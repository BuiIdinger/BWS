cmake_minimum_required(VERSION 3.10)

project(bws)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bws
  bws.cpp
  log.cpp
  fileArchitecture.cpp
  timeFunctions.cpp
)
