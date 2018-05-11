#ifndef MY_VECTOR_MY_VECTOR_ITERATOR_IMPL_HPP
#define MY_VECTOR_MY_VECTOR_ITERATOR_IMPL_HPP

#include "my_vector_iterator.hpp"

template<class T>
my_vector_iterator<T>::my_vector_iterator(T *ptr) : p(ptr) {};

template<class T>
my_vector_iterator<T>::my_vector_iterator(const my_vector_iterator &mvi) : p(mvi.p) {};

template<class T>
my_vector_iterator<T> &my_vector_iterator<T>::operator++() {
    ++p;
    return *this;
}

template<class T>
const my_vector_iterator<T> my_vector_iterator<T>::operator++(int) {
    T *tmp = p;
    ++p;
    return my_vector_iterator(tmp);
}

template<class T>
my_vector_iterator<T> &my_vector_iterator<T>::operator--() {
    --p;
    return *this;
}

template<class T>
const my_vector_iterator<T> my_vector_iterator<T>::operator--(int) {
    T *tmp = p;
    --p;
    return my_vector_iterator(tmp);
}

template<class T>
const bool my_vector_iterator<T>::operator==(const my_vector_iterator &rhs) const {
    return p == rhs.p;
}

template<class T>
const bool my_vector_iterator<T>::operator!=(const my_vector_iterator &rhs) const {
    return p != rhs.p;
}

template<class T>
T &my_vector_iterator<T>::operator*() {
    return *p;
}

template<class T>
my_vector_iterator<T> &my_vector_iterator<T>::operator+=(size_t i) {
    p += i;
    return *this;
}

template<class T>
my_vector_iterator<T> &my_vector_iterator<T>::operator-=(size_t i) {
    p -= i;
    return *this;
}

template<class T>
my_vector_iterator<T> my_vector_iterator<T>::operator+(size_t i) const {
    return my_vector_iterator(p) += i;
}

template<class T>
my_vector_iterator<T> my_vector_iterator<T>::operator-(size_t i) const {
    return my_vector_iterator(p) -= i;
}

template<class T>
size_t my_vector_iterator<T>::operator-(const my_vector_iterator &rhs) const {
    return p - rhs.p;
}

template<class T>
const bool my_vector_iterator<T>::operator<(const my_vector_iterator &rhs) const {
    return p < rhs.p;
}

template<class T>
const bool my_vector_iterator<T>::operator<=(const my_vector_iterator &rhs) const {
    return p <= rhs.p;
}

template<class T>
const bool my_vector_iterator<T>::operator>(const my_vector_iterator &rhs) const {
    return p > rhs.p;
}

template<class T>
const bool my_vector_iterator<T>::operator>=(const my_vector_iterator<T>& rhs) const{
    return p >= rhs.p;
}

template<class T>
T &my_vector_iterator<T>::operator[](size_t i) {
    return p[i];
}

#endif //MY_VECTOR_MY_VECTOR_ITERATOR_IMPL_HPP
