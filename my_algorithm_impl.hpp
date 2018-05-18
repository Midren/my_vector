#ifndef MY_VECTOR_MY_ALGORITHM_IMPL_HPP
#define MY_VECTOR_MY_ALGORITHM_IMPL_HPP

#include "my_algorithm.hpp"

template <typename T, typename F>
auto reduce(T beg, T end, F f) {
    decltype(f(*beg, *beg)) res = *beg;
    T snd = ++beg;
    while(snd != end) {
        res = f(res, *snd);
        ++snd;
    }
    return res;
};
#endif //MY_VECTOR_MY_ALGORITHM_IMPL_HPP
