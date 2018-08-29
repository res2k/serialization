/////////1/////////2/////////3/////////4/////////5/////////6/////////7/////////8
// visibility.hpp

// (C) Copyright 2002 Robert Ramey - http://www.rrsd.com . 
// (C) Copyright 2018 Frank Richter
// Use, modification and distribution is subject to the Boost Software
// License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for updates, documentation, and revision history.

#ifndef BOOST_ARCHIVE_DETAIL_VISIBILITY_HPP
#define BOOST_ARCHIVE_DETAIL_VISIBILITY_HPP

#include <boost/config.hpp>

#if (defined(BOOST_GCC_VERSION) && (BOOST_GCC_VERSION >= 40000) && !defined(BOOST_HAS_DECLSPEC))
#  define BOOST_SERIALIZATION_HAVE_PRAGMA_VISIBILITY
#  define BOOST_SERIALIZATION_PRIVATE       __attribute__((visibility("hidden")))
#  define BOOST_SERIALIZATION_VISIBLE       __attribute__((visibility("default")))
#elif (defined(BOOST_CLANG) && !defined(_WIN32) && !defined(__WIN32__) && !defined(WIN32))
#  define BOOST_SERIALIZATION_HAVE_PRAGMA_VISIBILITY
#  define BOOST_SERIALIZATION_PRIVATE       __attribute__((__visibility__("hidden")))
#  define BOOST_SERIALIZATION_VISIBLE       __attribute__((__visibility__("default")))
#endif

#ifndef BOOST_SERIALIZATION_PRIVATE
#  define BOOST_SERIALIZATION_PRIVATE
#endif

#endif // BOOST_ARCHIVE_DETAIL_VISIBILITY_HPP
