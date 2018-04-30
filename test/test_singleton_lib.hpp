/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// (C) Copyright 2018 Alexander Grund
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_SERIALIZATION_TEST_SINGLETON_LIB_HPP
#define BOOST_SERIALIZATION_TEST_SINGLETON_LIB_HPP

#if defined(BOOST_ALL_DYN_LINK) || defined(BOOST_SERIALIZATION_DYN_LINK)
    #if defined(SINGLETON_LIB_IMPORT)
        #define SINGLETON_LIB_DLL_DECL BOOST_SYMBOL_IMPORT
        #pragma message ("singleton_lib imported")
    #elif defined(SINGLETON_LIB_EXPORT)
        #define SINGLETON_LIB_DLL_DECL BOOST_SYMBOL_EXPORT
        #pragma message ("singleton_lib exported")
    #endif
#else
    #define SINGLETON_LIB_DLL_DECL
    #pragma message ("singleton_lib static")
#endif

// Simple method that should return 0
SINGLETON_LIB_DLL_DECL int singleton_lib_query();

#endif // BOOST_SERIALIZATION_TEST_SINGLETON_LIB_HPP
