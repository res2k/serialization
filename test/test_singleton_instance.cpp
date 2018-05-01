/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// test_singleton.cpp

// (C) Copyright 2018 Robert Ramey - http://www.rrsd.com . 
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// should pass compilation and execution

#include <iostream>
#include <boost/serialization/singleton.hpp>
#include <boost/array.hpp>
#include <stdexcept>

#include "test_tools.hpp"

// Can't use BOOST_CHECK because destructors are called after program exit
#define STRINGIZE(x) STRINGIZE_SIMPLE(x)
#define STRINGIZE_SIMPLE(x) #x
#define THROW_ON_FALSE(cond) if(!(cond)) throw std::runtime_error(__FILE__ "(" STRINGIZE(__LINE__) ") Assertion failed: " #cond)

struct plainSingleton;
struct inheritedSingleton;

// Enum to designate the state of the singletonized instances
enum ConstructionState{CS_UNINIT, CS_INIT, CS_DESTROYED};

// We need another singleton to check for the destruction of the singletons at program exit
// We don't need all the magic for shared library anti-optimization and can keep it very simple
struct controller{
    static controller& getInstance(){
        static controller instance;
        return instance;
    }
    boost::array<ConstructionState, 2> states;
private:
    controller() {
        states[0] = states[1] = CS_UNINIT;
    }
    ~controller();
};

// Just to not duplicate the checks and sets
template<size_t T_num>
struct baseClass{
    baseClass(): i(42) {
        // access controller singleton. Therefore controller will be constructed before this
        BOOST_CHECK(controller::getInstance().states[T_num] == CS_UNINIT);
        controller::getInstance().states[T_num] = CS_INIT;
    }
    ~baseClass() {
        // Because controller is constructed before this, it will be destructed AFTER this. Hence controller is still valid
        THROW_ON_FALSE(controller::getInstance().states[T_num] == CS_INIT);
        controller::getInstance().states[T_num] = CS_DESTROYED;
    }
    // Volatile to prevent compiler optimization from removing this
    volatile int i;
};

struct plainSingleton: baseClass<0>
{};

struct inheritedSingleton: baseClass<1>, boost::serialization::singleton<inheritedSingleton>
{};

// Define after the classes:

controller::~controller() {
    // If this fails, the singletons were not freed and memory is leaked
    for(size_t i=0; i<states.size(); i++)
        THROW_ON_FALSE(states[i] == CS_DESTROYED);
    // If this fails, then the destroyed flag is not set and one may use a deleted instance if relying on this flag
    THROW_ON_FALSE(boost::serialization::singleton<plainSingleton>::is_destroyed());
    THROW_ON_FALSE(boost::serialization::singleton<inheritedSingleton>::is_destroyed());
    THROW_ON_FALSE(inheritedSingleton::is_destroyed());
}

int
test_main( int /* argc */, char* /* argv */[] )
{
    // Check if the singletons are alive and use them
    BOOST_CHECK(!boost::serialization::singleton<plainSingleton>::is_destroyed());
    BOOST_CHECK(!inheritedSingleton::is_destroyed());

    BOOST_CHECK(boost::serialization::singleton<plainSingleton>::get_const_instance().i == 42);
    BOOST_CHECK(inheritedSingleton::get_const_instance().i == 42);
    return EXIT_SUCCESS;
}

