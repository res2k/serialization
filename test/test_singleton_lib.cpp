/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// test_singleton_lib.cpp: simple library using singletons to test usage in shared libraries

// (C) Copyright 2018 Alexander Grund
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/serialization/export.hpp>

#define SINGLETON_LIB_EXPORT
#include "test_singleton_lib.hpp"

#include "test_singleton.hpp"

int singleton_lib_query() {
    return boost::serialization::singleton<plainSingleton>::get_const_instance().i - inheritedSingleton::get_const_instance().i;
}

