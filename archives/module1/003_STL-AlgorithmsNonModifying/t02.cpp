#include <iostream>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

// Função para verificar se o número é ímpar
bool odd(const int& value) {
    return value % 2 != 0;
}

// Functor para verificar se o número é par
struct Even {
    bool operator()(const int& value) {
        return value % 2 == 0;
    }
};

int main() {
    int t[] = {10, 2, 4, 3, 5, 6, 7, 8, 9, 1};
    
    // deque permite inserções e remoções eficientes nas duas extremidades
    // vector pode ser usado, mas deque é mais adequado para este exemplo
    deque<int> d1(t, t + 10);

    cout << "Procurando o primeiro elemento ímpar no deque:\n";
    auto found = find_if(d1.begin(), d1.end(), odd);
    if (found != d1.end()) {
        cout << "Encontrado: " << *found << endl;
    } else {
        cout << "Nenhum elemento ímpar encontrado\n";
    }

    cout << "\nProcurando o primeiro elemento par no deque:\n";
    found = find_if(d1.begin(), d1.end(), Even());
    if (found != d1.end()) {
        cout << "Encontrado: " << *found << endl;
    } else {
        cout << "Nenhum elemento par encontrado\n";
    }

    // Agora com um set (ordenado e sem elementos repetidos)
    set<int> s1(t, t + 10);

    cout << "\nProcurando o primeiro elemento ímpar no set:\n";
    auto founds = find_if(s1.begin(), s1.end(), odd);
    if (founds != s1.end()) {
        cout << "Encontrado: " << *founds << endl;
    } else {
        cout << "Nenhum elemento ímpar encontrado\n";
    }

    cout << "\nProcurando o primeiro elemento par no set:\n";
    founds = find_if(s1.begin(), s1.end(), Even());
    if (founds != s1.end()) {
        cout << "Encontrado: " << *founds << endl;
    } else {
        cout << "Nenhum elemento par encontrado\n";
    }

    return 0;
}
