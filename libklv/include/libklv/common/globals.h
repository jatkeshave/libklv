// Copyright (c) 2023. Keshav Jat
#ifndef LIBKLV_GLOBALS_H
#define LIBKLV_GLOBALS_H

#define DECL_EXPORT __declspec(dllexport)
#define DECL_IMPORT __declspec(dllimport)

#if defined(_MSC_VER) && (defined(LIBKLV_SHARED) || !defined(LIBKLV_STATIC))
  #if defined(LIBKLV_BUILD_LIB)
    #define LIBKLV_EXPORT DECL_EXPORT
  #else
    #define LIBKLV_EXPORT DECL_IMPORT
  #endif
#else
  #define LIBKLV_EXPORT
#endif

#endif // LIBKLV_GLOBALS_H
