#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
using namespace std;

struct myprinter {
    void operator () (int i) const {
        cout << i << ", ";
    }
};

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };

    vector<int> v1(mynumbers, mynumbers + 7);
    deque<int> d1(mynumbers, mynumbers + 7);
    set<int> s1(mynumbers, mynumbers + 7);

    d1.pop_front();  // Remove o primeiro elemento do deque (3)

    // Imprime os elementos do deque após remoção
    cout << "deque: ";
    for_each(d1.begin(), d1.end(), myprinter());

    cout << "\ndeque (again): ";
    for_each(d1.begin(), d1.end(), myprinter());  // Sem new!

    // Imprime os elementos do vetor original
    cout << "\nvector: ";
    for_each(v1.begin(), v1.end(), myprinter());

    // Só por curiosidade: imprimindo o set (opcional)
    cout << "\nset (ordenado, único): ";
    for_each(s1.begin(), s1.end(), myprinter());

    cout << endl;
    return 0;
}
