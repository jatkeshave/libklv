cmake_minimum_required(VERSION 3.17)

project(
  libklv
  VERSION ${CMAKE_PROJECT_VERSION}
  DESCRIPTION "libklv sources"
  LANGUAGES CXX
)

set(LIBKLV_TYPE "IGNORE")
set(
  LIBKLV_PRIVATE_SRC
  src/ber/berencoder.cpp
  src/ber/beridentifier.cpp
)
set(
  LIBKLV_PUBLIC_SRC
  include/libklv/ber/berencoder.h
  include/libklv/ber/beridentifier.h
  include/libklv/common/globals.h
  include/libklv/common/cowhelper.h
)
set(
  LIBKLV_PUBLIC_DEF
)
set(
  LIBKLV_PRIVATE_DEF
  LIBKLV_BUILD_LIB=1
)

if(LIBKLV_BUILD_SHARED)
  set(LIBKLV_TYPE SHARED)
  list(APPEND LIBKLV_PUBLIC_DEF LIBKLV_SHARED=1)
else()
  set(LIBKLV_TYPE STATIC)
  list(APPEND LIBKLV_PUBLIC_DEF LIBKLV_STATIC=1)
endif()

add_library(libklv ${LIBKLV_TYPE})
target_sources(libklv PRIVATE ${LIBKLV_PRIVATE_SRC} PRIVATE ${LIBKLV_PUBLIC_SRC})
target_include_directories(
  libklv
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
)
target_compile_features(
  libklv
  PUBLIC
  cxx_std_17
)
target_compile_definitions(libklv PRIVATE ${LIBKLV_PRIVATE_DEF} PUBLIC ${LIBKLV_PUBLIC_DEF})
target_compile_options(
  libklv
  PRIVATE
  $<$<AND:$<CXX_COMPILER_ID:MSVC>,$<CONFIG:Debug>>:/WX /Wall>
)
