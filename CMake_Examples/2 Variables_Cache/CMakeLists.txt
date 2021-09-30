cmake_minimum_required(VERSION 3.7...3.21)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(MyProject VERSION 1.0 DESCRIPTION "Very nice project" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

option(BuildTypeSet "Make Shift Global Variable" OFF)
if(BuildTypeSet)
  set(CMAKE_BUILD_TYPE "Release" CACHE INTERNAL "")
endif()

add_library(calclib STATIC src/calclib.cpp include/calclib.hpp)
target_include_directories(calclib PUBLIC include)
target_compile_features(calclib PUBLIC cxx_std_11)

add_executable(calc apps/calc.cpp)
target_link_libraries(calc PUBLIC calclib)