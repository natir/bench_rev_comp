cmake_minimum_required(VERSION 2.8)

project(bench_rev_comp_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O2")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)

include_directories(inc)

file(
  GLOB_RECURSE
  src_files
  src/*rev*
  src/*comp*
  )

file(
  GLOB_RECURSE
  test_files
  test/*
  )

add_executable(
  bench
  src/main.cpp
  ${src_files}
  )

add_executable(
  bench_test
  ${test_files}
  ${src_files}
  )











