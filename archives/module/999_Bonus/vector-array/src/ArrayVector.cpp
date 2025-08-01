#include "Array.hpp"
#include <stdexcept>

Array::Array(unsigned size)
    : _array(size) {}

void Array::add(int value) {
    _array.push_back(value);
}

void Array::delItem(unsigned index) {
    if (index >= _array.size()) return;
    _array.erase(_array.begin() + index);
}

unsigned int Array::getSize() const {
    return static_cast<unsigned int>(_array.size());
}

int& Array::operator[](unsigned index) {
    if (index >= _array.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return _array[index];
}
