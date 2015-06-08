//  error_handling.hpp  --------------------------------------------------------------//

//  Copyright 2010 Vicente J. Botet Escriba
//  Copyright 2015 Andrey Semashev

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt


#ifndef BOOST_DETAIL_WINAPI_ERROR_HANDLING_HPP
#define BOOST_DETAIL_WINAPI_ERROR_HANDLING_HPP

#include <stdarg.h>
#include <boost/detail/winapi/basic_types.hpp>
#include <boost/detail/winapi/GetLastError.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
#if !defined( BOOST_NO_ANSI_APIS )
BOOST_SYMBOL_IMPORT boost::detail::winapi::DWORD_ WINAPI
FormatMessageA(
    boost::detail::winapi::DWORD_ dwFlags,
    boost::detail::winapi::LPCVOID_ lpSource,
    boost::detail::winapi::DWORD_ dwMessageId,
    boost::detail::winapi::DWORD_ dwLanguageId,
    boost::detail::winapi::LPSTR_ lpBuffer,
    boost::detail::winapi::DWORD_ nSize,
    va_list *Arguments);
#endif

BOOST_SYMBOL_IMPORT boost::detail::winapi::DWORD_ WINAPI
FormatMessageW(
    boost::detail::winapi::DWORD_ dwFlags,
    boost::detail::winapi::LPCVOID_ lpSource,
    boost::detail::winapi::DWORD_ dwMessageId,
    boost::detail::winapi::DWORD_ dwLanguageId,
    boost::detail::winapi::LPWSTR_ lpBuffer,
    boost::detail::winapi::DWORD_ nSize,
    va_list *Arguments);
}
#endif

namespace boost {
namespace detail {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

#if !defined( BOOST_NO_ANSI_APIS )
using ::FormatMessageA;
#endif
using ::FormatMessageW;

const DWORD_ FORMAT_MESSAGE_ALLOCATE_BUFFER_= FORMAT_MESSAGE_ALLOCATE_BUFFER;
const DWORD_ FORMAT_MESSAGE_IGNORE_INSERTS_=  FORMAT_MESSAGE_IGNORE_INSERTS;
const DWORD_ FORMAT_MESSAGE_FROM_STRING_=     FORMAT_MESSAGE_FROM_STRING;
const DWORD_ FORMAT_MESSAGE_FROM_HMODULE_=    FORMAT_MESSAGE_FROM_HMODULE;
const DWORD_ FORMAT_MESSAGE_FROM_SYSTEM_=     FORMAT_MESSAGE_FROM_SYSTEM;
const DWORD_ FORMAT_MESSAGE_ARGUMENT_ARRAY_=  FORMAT_MESSAGE_ARGUMENT_ARRAY;
const DWORD_ FORMAT_MESSAGE_MAX_WIDTH_MASK_=  FORMAT_MESSAGE_MAX_WIDTH_MASK;

const WORD_ LANG_NEUTRAL_=                  LANG_NEUTRAL;
const WORD_ LANG_INVARIANT_=                LANG_INVARIANT;

const WORD_ SUBLANG_DEFAULT_=               SUBLANG_DEFAULT;    // user default

BOOST_FORCEINLINE WORD_ MAKELANGID_(WORD_ p, WORD_ s)
{
    return MAKELANGID(p,s);
}

#else

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE DWORD_ FormatMessageA(
    DWORD_ dwFlags,
    LPCVOID_ lpSource,
    DWORD_ dwMessageId,
    DWORD_ dwLanguageId,
    LPSTR_ lpBuffer,
    DWORD_ nSize,
    va_list *Arguments)
{
    return ::FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments);
}
#endif

BOOST_FORCEINLINE DWORD_ FormatMessageW(
    DWORD_ dwFlags,
    LPCVOID_ lpSource,
    DWORD_ dwMessageId,
    DWORD_ dwLanguageId,
    LPWSTR_ lpBuffer,
    DWORD_ nSize,
    va_list *Arguments)
{
    return ::FormatMessageW(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments);
}

const DWORD_ FORMAT_MESSAGE_ALLOCATE_BUFFER_= 0x00000100;
const DWORD_ FORMAT_MESSAGE_IGNORE_INSERTS_=  0x00000200;
const DWORD_ FORMAT_MESSAGE_FROM_STRING_=     0x00000400;
const DWORD_ FORMAT_MESSAGE_FROM_HMODULE_=    0x00000800;
const DWORD_ FORMAT_MESSAGE_FROM_SYSTEM_=     0x00001000;
const DWORD_ FORMAT_MESSAGE_ARGUMENT_ARRAY_=  0x00002000;
const DWORD_ FORMAT_MESSAGE_MAX_WIDTH_MASK_=  0x000000FF;

const WORD_ LANG_NEUTRAL_=                  0x00;
const WORD_ LANG_INVARIANT_=                0x7f;

const WORD_ SUBLANG_DEFAULT_=               0x01;    // user default

BOOST_FORCEINLINE WORD_ MAKELANGID_(WORD_ p, WORD_ s)
{
    return ((((WORD_)(s)) << 10) | (WORD_)(p));
}
#endif

#if !defined( BOOST_NO_ANSI_APIS )
BOOST_FORCEINLINE DWORD_ format_message(
    DWORD_ dwFlags,
    LPCVOID_ lpSource,
    DWORD_ dwMessageId,
    DWORD_ dwLanguageId,
    LPSTR_ lpBuffer,
    DWORD_ nSize,
    va_list *Arguments)
{
    return ::FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments);
}
#endif

BOOST_FORCEINLINE DWORD_ format_message(
    DWORD_ dwFlags,
    LPCVOID_ lpSource,
    DWORD_ dwMessageId,
    DWORD_ dwLanguageId,
    LPWSTR_ lpBuffer,
    DWORD_ nSize,
    va_list *Arguments)
{
    return ::FormatMessageW(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments);
}

}
}
}

#endif // BOOST_DETAIL_WINAPI_ERROR_HANDLING_HPP
