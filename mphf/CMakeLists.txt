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

add_custom_command(
    OUTPUT  inc/mphf_4mer.hpp
    COMMAND ${CMAKE_SOURCE_DIR}/script/generate_gperf_file.py 4 ${CMAKE_SOURCE_DIR}/inc/mphf_4mer.hpp
    )

add_executable(
  bench
  src/main.cpp
  ${src_files}
  inc/mphf_4mer.hpp
  )

