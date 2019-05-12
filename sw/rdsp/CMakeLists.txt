cmake_minimum_required(VERSION 3.5)

project(rdsp C CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3 REQUIRED NO_MODULE)
find_package(Matlab REQUIRED)
find_package(msgpack REQUIRED)

include(CheckIncludeFileCXX)
check_include_file_cxx(asio.hpp ASIO_FOUND)
if (NOT ASIO_FOUND)
  message(FATAL_ERROR "Could not find ASIO in the system\n")
endif()

add_subdirectory(src)
