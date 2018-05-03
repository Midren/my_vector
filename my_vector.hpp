#ifndef MY_VECTOR_MY_VECTOR_H
#define MY_VECTOR_MY_VECTOR_H
#include <iostream>
class wrong_index : public std::exception {
public:
    wrong_index(int i) : ind(i) {}
private:
    int ind;
};

template <class T>
class my_vector {
public:
    my_vector();

    explicit my_vector(size_t sz);

    my_vector(size_t sz, T init);

    my_vector(std::initializer_list<T> lst);

    my_vector(const my_vector& vect);

    my_vector(my_vector&& vect) noexcept;

    void assign(size_t count, const T& elem);

    ~my_vector();

    void reserve(size_t num);

    void resize(size_t num);

    size_t capacity() const;

    size_t size() const;

    bool empty() const;

    void shrink_to_fit();

    void push_back(const T& num);

    void pop_back();

    T& at(size_t ind);

    const T& at(size_t ind) const;

    T& operator[](size_t ind);

    const T& operator[](size_t ind) const;

    T& front();

    const T& front() const;

    T& back();

    const T& back() const;

    T* data();

    const T* data() const;

    my_vector& operator=(const my_vector& vect);

    my_vector& operator=(my_vector&& vect) noexcept;

    void clear();

    void swap(my_vector& other);

private:
    size_t sze = 0;
    size_t capacty = 1;
    T* elements = nullptr;
};

#include "my_vector_impl.hpp"
#endif //MY_VECTOR_MY_VECTOR_H
