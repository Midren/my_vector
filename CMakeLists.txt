cmake_minimum_required(VERSION 3.10)
project(my_vector)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_vector my_vector.hpp my_vector_impl.hpp test_my_vector.cpp my_vector_iterator.hpp my_vector_iterator_impl.hpp my_algorithm.hpp my_algorithm_impl.hpp)
TARGET_LINK_LIBRARIES(my_vector -lgtest)
