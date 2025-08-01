#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <cctype>  // para tolower

using namespace std;

// usada com for_each
template<class T>
void print(const T & value) {
    cout << value << " ";
}

// Functor para comparação insensível a maiúsculas/minúsculas
struct Compare {
    bool operator()(const char &f, const char &s) {
        return tolower(f) == tolower(s);
    }
};

int main() {
    int t1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int t2[] = {1, 2, 4, 6, 7, 3, 5, 9, 10, 8};

    vector<int> v1(t1, t1 + 10);
    list<int> l1(t2, t2 + 10);

    cout << "v1: ";
    for_each(v1.begin(), v1.end(), print<int>);
    cout << endl;

    cout << "l1: ";
    for_each(l1.begin(), l1.end(), print<int>);
    cout << endl;

    // mismatch retorna o primeiro par de elementos diferentes entre duas sequências
    auto p1 = mismatch(v1.begin(), v1.end(), l1.begin());

    if (p1.first == v1.end() && p1.second == l1.end()) {
        cout << "As coleções v1 e l1 são iguais!\n";
    } else {
        cout << "As coleções v1 e l1 são DIFERENTES!\n";
        cout << "Diferença na posição: " << distance(v1.begin(), p1.first) << endl;
        cout << "Elementos diferentes - v1: " << *(p1.first) << " | l1: " << *(p1.second) << endl;
    }

    cout << endl;

    // comparação de caracteres (sensível e insensível a maiúsculas) ----------
    char t3[] = {'a','b','C','d','e','F','g','h','i','J'};
    char t4[] = {'a','b','C','D','E','F','g','h','i','j'};

    vector<char> v2(t3, t3 + 10);
    list<char> l2(t4, t4 + 10);

    cout << "v2: ";
    for_each(v2.begin(), v2.end(), print<char>);
    cout << endl;

    cout << "l2: ";
    for_each(l2.begin(), l2.end(), print<char>);
    cout << endl;

    // Comparação sensível a maiúsculas/minúsculas
    cout << "Comparação SENSÍVEL a maiúsculas/minúsculas:\n";
    auto p2 = mismatch(v2.begin(), v2.end(), l2.begin());

    if (p2.first == v2.end() && p2.second == l2.end()) {
        cout << "As coleções v2 e l2 são iguais!\n";
    } else {
        cout << "As coleções v2 e l2 são DIFERENTES!\n";
        cout << "Diferença na posição: " << distance(v2.begin(), p2.first) << endl;
        cout << "Elementos diferentes - v2: " << *(p2.first) << " | l2: " << *(p2.second) << endl;
    }

    cout << endl;

    // Comparação insensível a maiúsculas/minúsculas (usando Compare)
    cout << "Comparação INSENSÍVEL a maiúsculas/minúsculas:\n";
    p2 = mismatch(v2.begin(), v2.end(), l2.begin(), Compare());

    if (p2.first == v2.end() && p2.second == l2.end()) {
        cout << "As coleções v2 e l2 são iguais!\n";
    } else {
        cout << "As coleções v2 e l2 são DIFERENTES!\n";
        cout << "Diferença na posição: " << distance(v2.begin(), p2.first) << endl;
        cout << "Elementos diferentes - v2: " << *(p2.first) << " | l2: " << *(p2.second) << endl;
    }

    return 0;
}
