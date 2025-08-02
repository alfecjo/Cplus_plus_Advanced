#include <deque>
#include <iostream>

int main() {
    std::deque<int> d;

    if (d.empty()) {
        std::cout << "Deque está vazio.\n";
    } else {
        std::cout << "Deque tem elementos.\n";
    }

    d.push_back(10);

    if (!d.empty()) {
        std::cout << "Agora o deque tem elementos.\n";
    }

    return 0;
}
