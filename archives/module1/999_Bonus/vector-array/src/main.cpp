#include "Array.hpp"
#include <iostream>

int main() {
    Array arr;

    arr.add(10);
    arr.add(20);
    arr.add(30);

    std::cout << "Array after adding 3 elements:\n";
    for (unsigned i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    arr.delItem(1);

    std::cout << "Array after deleting index 1:\n";
    for (unsigned i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
