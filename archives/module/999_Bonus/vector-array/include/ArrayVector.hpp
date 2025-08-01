#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <vector>

class Array {
    std::vector<int> _array;

public:
    Array(unsigned size = 0);

    void add(int value);
    void delItem(unsigned index);

    unsigned int getSize() const;
    int& operator[](unsigned index);
};

#endif
