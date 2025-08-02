#include <list>
#include <iostream>

int main() {
    std::list<int> mylist = {1, 2, 3, 4, 5};

    std::cout << "Antes do clear, tamanho: " << mylist.size() << std::endl;

    mylist.clear();  // remove todos os elementos

    std::cout << "Depois do clear, tamanho: " << mylist.size() << std::endl;

    return 0;
}
