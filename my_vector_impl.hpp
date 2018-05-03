#include "my_vector.hpp"

template<class T>
my_vector<T>::my_vector() : elements(new T[1]) {}

template<class T>
my_vector<T>::my_vector(size_t sz) : elements(new T[1]){
    resize(sz);
}

template<class T>
my_vector<T>::my_vector(size_t sz, T init) : elements(new T[1]) {
    resize(sz);
    for (size_t i = 0; i < sze; i++) elements[i] = init;
}

template<class T>
my_vector<T>::my_vector(std::initializer_list<T> lst) : elements(new T[1]){
    resize(lst.size());
    int j = 0;
    for (auto i = lst.begin(); i != lst.end(); i++, j++) elements[j] = *i;
}

template<class T>
my_vector<T>::my_vector(const my_vector<T> &vect) : elements(new T[1]){
    auto n = new T[vect.capacity()];
    for (size_t i = 0; i < vect.size(); ++i) n[i] = vect[i];
    elements = n;
    sze = vect.size();
    capacty = vect.capacity();
}

template<class T>
my_vector<T>::my_vector(my_vector<T> &&vect) noexcept : sze(vect.size()), capacty(vect.capacity()),
                                                        elements(vect.elements) {
    vect.sze = 0;
    vect.capacty = 0;
    vect.elements = nullptr;
}

template<class T>
void my_vector<T>::assign(size_t count, const T &elem) {
    T *n = new T[count];
    for (size_t i = 0; i < count; ++i) n[i] = elem;
    delete[] elements;
    elements = n;
    sze = count;
    capacty = count;

}

template<class T>
my_vector<T>::~my_vector() {
    delete[] elements;
}

template<class T>
void my_vector<T>::reserve(size_t num) {
    if (num <= capacty) return;
    auto n = new T[num];
    for (int i = 0; i < sze; i++) n[i] = elements[i];
    delete[] elements;
    capacty = num;
    elements = n;
}

template<class T>
void my_vector<T>::resize(size_t num) {
    reserve(num);
    for (size_t i = sze; i < num; ++i) elements[i] = T();
    sze = num;
}

template<class T>
size_t my_vector<T>::capacity() const {
    return capacty;
}

template<class T>
size_t my_vector<T>::size() const {
    return sze;
}

template<class T>
bool my_vector<T>::empty() const {
    return sze == 0;
}

template<class T>
void my_vector<T>::shrink_to_fit() {
    if (sze == capacty) return;
    T *n = new T[sze];
    for (size_t i = 0; i < sze; ++i) n[i] = elements[i];
    delete[] elements;
    capacty = sze;
    elements = n;
}

template<class T>
void my_vector<T>::push_back(const T &num) {
    if (sze == capacty) {
        if (&num < elements || (&num > elements + sze)) {
            if (sze == capacty) reserve(capacty*2);
            elements[sze++] = T(num);
            return;
        }
    }
    elements[sze++] = num;
}

template<class T>
void my_vector<T>::pop_back() {
    if (sze == 0) return;
    --sze;
}

template<class T>
T &my_vector<T>::at(size_t ind) {
    if (ind >= sze) throw wrong_index(ind);
    return elements[ind];
}

template<class T>
const T& my_vector<T>::at(size_t ind) const {
    if (ind >= sze) throw wrong_index(ind);
    return elements[ind];
}

template<class T>
T &my_vector<T>::operator[](size_t ind) {
    return elements[ind];
}

template<class T>
const T& my_vector<T>::operator[](size_t ind) const {
    return elements[ind];
}

template<class T>
T &my_vector<T>::front() {
    return elements[0];
}

template<class T>
const T& my_vector<T>::front() const {
    return elements[0];
}

template<class T>
T &my_vector<T>::back() {
    return elements[sze - 1];
}

template<class T>
const T& my_vector<T>::back() const {
    return elements[sze - 1];
}

template<class T>
T *my_vector<T>::data() {
    return elements;
}

template<class T>
const T *my_vector<T>::data() const {
    return elements;
};

template<class T>
my_vector<T> &my_vector<T>::operator=(const my_vector<T> &vect) {
    auto n = new T[vect.size()];
    for (size_t i = 0; i < vect.size(); ++i) n[i] = vect.elements[i];
    sze = vect.size();
    capacty = vect.capacity();
    delete[] elements;
    elements = n;
    return *this;
}

template<class T>
my_vector<T> &my_vector<T>::operator=(my_vector<T> &&vect) noexcept {
    sze = vect.size();
    capacty = vect.capacity();
    delete[] elements;
    elements = vect.elements;
    vect.sze = 0;
    vect.capacty = 0;
    vect.elements = nullptr;
    return *this;
}

template<class T>
void my_vector<T>::clear() {
    sze = 0;
    capacty = 0;
    delete[] elements;
    elements = nullptr;
}

template<class T>
void my_vector<T>::swap(my_vector &other) {
    T *tmp_el = other.elements;
    size_t tmp_sz = other.sze;
    size_t tmp_cap = other.capacty;
    other.elements = elements;
    elements = tmp_el;
    other.sze = sze;
    sze = tmp_sz;
    other.capacty = capacty;
    capacty = tmp_cap;
}

