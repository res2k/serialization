/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// multi_shared2.cpp: library simply using extended_type_info_typeid

// (C) Copyright 2018 Alexander Grund
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_SERIALIZATION_SOURCE

#include <boost/serialization/extended_type_info_typeid.hpp>

BOOST_SYMBOL_EXPORT int g(){
  // Use a different(!) type
  return 0 != boost::serialization::extended_type_info_typeid<float>::get_const_instance().get_key();
}

