#ifndef MY_VECTOR_MY_VECTOR_ITERATOR_HPP
#define MY_VECTOR_MY_VECTOR_ITERATOR_HPP

#include <iterator>

template <class T>
class my_vector_iterator {
public:
    typedef T value_type;
    typedef std::random_access_iterator_tag iterator_category;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T* &reference;

    my_vector_iterator() = default;

    explicit my_vector_iterator<T>(T* ptr);

    my_vector_iterator(const my_vector_iterator<T>& mvi);

    my_vector_iterator<T> &operator++();

    const my_vector_iterator<T> operator++(int);

    my_vector_iterator<T> &operator--();

    const my_vector_iterator<T> operator--(int);

    const bool operator==(const my_vector_iterator& rhs) const;

    const bool operator!=(const my_vector_iterator& rhs) const;

    T& operator*();

    my_vector_iterator<T>& operator+=(size_t i);

    my_vector_iterator<T>& operator-=(size_t i);

    my_vector_iterator<T> operator+(size_t i) const;

    my_vector_iterator<T> operator-(size_t i) const;

    size_t operator-(const my_vector_iterator<T>& rhs) const;

    const bool operator<(const my_vector_iterator<T>& rhs) const;

    const bool operator<=(const my_vector_iterator<T>& rhs) const;

    const bool operator>(const my_vector_iterator<T>& rhs) const;

    const bool operator>=(const my_vector_iterator<T>& rhs) const;

    T& operator[](size_t i);

private:
    T* p;
};

#include "my_vector_iterator_impl.hpp"
#endif //MY_VECTOR_MY_VECTOR_ITERATOR_HPP
