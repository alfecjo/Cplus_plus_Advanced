#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

void printer(int i) {
    cout << i << ", ";
}

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };

    deque<int> d1(mynumbers, mynumbers + 7);

    d1.push_back(6);  // Adiciona novo valor ao buffer

    sort(d1.begin(), d1.end());  //  ordena corretamente: {0,1,2,3,4,5,6,9}

    deque<int>::iterator it = upper_bound(d1.begin(), d1.end(), 3); // valores > 3

    for_each(it, d1.end(), printer);  // imprime: 4, 5, 6, 9,

    return 0;
}
