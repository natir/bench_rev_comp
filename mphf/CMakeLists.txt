cmake_minimum_required(VERSION 2.8)

project(bench_rev_comp_cpp)

if(NOT ${KMER})
    set(KMER 4)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O2 -DKMER=${KMER}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)

include_directories(inc)

file(
  GLOB_RECURSE
  src_files
  src/*rev*
  src/*comp*
  )

add_custom_command(
    OUTPUT  inc/mphf_kmer.hpp
    COMMAND ${CMAKE_SOURCE_DIR}/script/generate_gperf_file.py ${KMER} ${CMAKE_SOURCE_DIR}/inc/mphf_kmer.hpp
    )

add_executable(
  bench
  src/main.cpp
  ${src_files}
  inc/mphf_kmer.hpp
  )

