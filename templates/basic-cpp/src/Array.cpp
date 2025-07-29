#include "Array.hpp"
#include <iostream>
#include <stdexcept>

Array::Array(unsigned size)
    : _array(nullptr), _size(size) {
    if (size > 0) {
        _array = new int[_size];
    }
}

Array::~Array() {
    delete[] _array;
}

void Array::add(int value) {
    int* tmp = new int[_size + 1];
    for (unsigned i = 0; i < _size; i++) {
        tmp[i] = _array[i];
    }
    tmp[_size] = value;
    delete[] _array;
    _array = tmp;
    _size++;
}

void Array::delItem(unsigned index) {
    if (index >= _size) return; // ignorar índice inválido

    if (_size == 1) {
        delete[] _array;
        _array = nullptr;
    } else {
        int* tmp = new int[_size - 1];
        for (unsigned i = 0, j = 0; i < _size; i++) {
            if (i == index) continue;
            tmp[j++] = _array[i];
        }
        delete[] _array;
        _array = tmp;
    }
    _size--;
}

unsigned int Array::getSize() const {
    return _size;
}

int& Array::operator[](unsigned index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _array[index];
}
