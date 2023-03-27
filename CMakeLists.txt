cmake_minimum_required(VERSION 3.17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMake")

include(libklvFunctions)

option_string(LIBKLV_VERSION "libklv version" "0.0.1")
option(LIBKLV_ENABLE_EXAMPLES "Enable example for libklv" ON)
option(LIBKLV_BUILD_SHARED "Build shared library" ON)

project(
  "libklv monorepo"
  VERSION ${LIBKLV_VERSION}
  DESCRIPTION "C++ library for KLV encoding"
  HOMEPAGE_URL "https://github.com/jatkeshave/libklv"
  LANGUAGES CXX
)

if(MSVC)
#  add_compile_options($<$<CONFIG:Debug>:/WX /Wall>)
elseif()
  message(FATAL_ERROR "Only MSVC compiler is supported at the moment.")
endif()


add_subdirectory(libklv)

if (LIBKLV_ENABLE_EXAMPLES)
  add_subdirectory(examples)
endif()

