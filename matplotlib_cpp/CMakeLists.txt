cmake_minimum_required(VERSION 3.14)
project(my_project)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-DWITHOUT_NUMPY)

find_package(PythonLibs 2.7)

add_executable(
  example1
  example1.cpp 
)
add_executable(
  example2
  example2.cpp 
)
add_executable(
  example3
  example3.cpp 
)
add_executable(
  example4
  example4.cpp 
)
#add_executable(
#  example5
#  example5.cpp 
#)

target_include_directories(example1 PRIVATE ${PYTHON_INCLUDE_DIRS} extern/matplotlib-cpp)
target_link_libraries(example1 ${PYTHON_LIBRARIES})
target_include_directories(example2 PRIVATE ${PYTHON_INCLUDE_DIRS} extern/matplotlib-cpp)
target_link_libraries(example2 ${PYTHON_LIBRARIES})
target_include_directories(example3 PRIVATE ${PYTHON_INCLUDE_DIRS} extern/matplotlib-cpp)
target_link_libraries(example3 ${PYTHON_LIBRARIES})
target_include_directories(example4 PRIVATE ${PYTHON_INCLUDE_DIRS} extern/matplotlib-cpp)
target_link_libraries(example4 ${PYTHON_LIBRARIES})
#target_include_directories(example5 PRIVATE ${PYTHON_INCLUDE_DIRS} extern/matplotlib-cpp)
#target_link_libraries(example5 ${PYTHON_LIBRARIES})

