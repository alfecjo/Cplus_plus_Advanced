#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array {
    int* _array;
    unsigned int _size;

public:
    Array(unsigned size = 0);
    ~Array();

    void add(int value);
    void delItem(unsigned index);

    unsigned int getSize() const;
    int& operator[](unsigned index);
};

#endif
