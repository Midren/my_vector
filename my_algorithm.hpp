#ifndef MY_VECTOR_MY_ALGORITHM_HPP
#define MY_VECTOR_MY_ALGORITHM_HPP

template <typename T, typename F>
auto reduce(T* beg, T* end, F);

#include "my_algorithm_impl.hpp"
#endif //MY_VECTOR_MY_ALGORITHM_HPP
