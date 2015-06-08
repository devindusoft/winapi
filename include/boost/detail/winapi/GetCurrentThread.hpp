//  GetCurrentThread.hpp  --------------------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba
//  Copyright 2015 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_GETCURRENTTHREAD_HPP
#define BOOST_DETAIL_WINAPI_GETCURRENTTHREAD_HPP

#include <boost/detail/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( UNDER_CE ) && !defined( BOOST_USE_WINDOWS_H )
extern "C" {
BOOST_SYMBOL_IMPORT boost::detail::winapi::HANDLE_ WINAPI GetCurrentThread();
}
#endif

namespace boost {
namespace detail {
namespace winapi {
#if defined( UNDER_CE )
// Windows CE define GetCurrentThread as an inline function in kfuncs.h
BOOST_FORCEINLINE HANDLE_ GetCurrentThread() 
{
    return ::GetCurrentThread();
}
#else
using ::GetCurrentThread;
#endif
}
}
}

#endif // BOOST_DETAIL_WINAPI_GETCURRENTTHREAD_HPP
