/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// test_multi_shared_lib.cpp: test that implementation of extented_type_info
//		works when using multiple shared libraries

// (C) Copyright 2018 Alexander Grund
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/serialization/config.hpp>

BOOST_SYMBOL_IMPORT int f();
BOOST_SYMBOL_IMPORT int g();

int main(int argc, char**){
  if(f() && g())
  	return 0;
}

