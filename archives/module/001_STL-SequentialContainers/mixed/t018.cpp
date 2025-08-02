#include <vector>
#include <iostream>

using namespace std;

// Função template para imprimir elementos entre dois iteradores
template <typename T>
ostream& print(T start, T end) {
    for (; start != end; ++start) {
        cout << *start << " ";
    }
    return cout;
}

int main() {
    int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // v1 é inicializado com os elementos do array tab
    vector<int> v1(tab, tab + 10);

    // v2 começa vazio
    vector<int> v2;

    // Iterador para percorrer v1
    vector<int>::iterator it;
    for (it = v1.begin(); it != v1.end(); ++it) {
        //  usamos it diretamente com desreferência e iterador reverso
        v2.push_back(*(v1.end() - (it - v1.begin()) - 1));
    }

    // Imprime v2 em ordem reversa — o que reverte novamente a ordem original
    print(v2.rbegin(), v2.rend()) << endl;

    return 0;
}
