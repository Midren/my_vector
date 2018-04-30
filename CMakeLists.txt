cmake_minimum_required(VERSION 3.10)
project(my_vector)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_vector my_vector.h test_my_vector.cpp)
TARGET_LINK_LIBRARIES(my_vector -lgtest)
