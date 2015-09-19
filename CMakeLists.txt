cmake_minimum_required(VERSION 3.2)

project(bench_rev_comp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O2")

include_directories(inc)

file(
  GLOB_RECURSE
  src_files
  src/*
  )

add_executable(
  bench_rev_comp
  ${src_files}
  )











