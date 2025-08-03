#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;


template <class T>
void print(const T &value) {
    cout << value << " ";
}

// Função utilitária para imprimir uma coleção com um título
template <typename Container>
void print_collection(const Container &c, const string &label) {
    cout << label;
    for_each(c.begin(), c.end(), print<typename Container::value_type>);
    cout << "\n";
}

int main() {
    // Lista original com 10 elementos
    list<int> l1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    cout << "=== Exemplo: std::rotate com list<int> ===\n\n";

    print_collection(l1, "Coleção original:\n");

    // ROTACIONANDO PARA TRAZER O 3 PARA O TOPO
    {
        cout << "\nRotacionando para trazer o 3 para o topo:\n";
        auto it = l1.begin();
        advance(it, 2); // move o iterador para o 3º elemento (índice 2 = elemento 3)
        rotate(l1.begin(), it, l1.end());
        print_collection(l1, "Após rotate (3 no topo):\n");
    }

    // ROTACIONANDO PARA TRAZER O 7 PARA O TOPO
    {
        cout << "\nRotacionando para trazer o 7 para o topo:\n";
        auto it = l1.begin();
        advance(it, 4); // move o iterador para o 5º elemento (que agora é o 7)
        rotate(l1.begin(), it, l1.end());
        print_collection(l1, "Após rotate (7 no topo):\n");
    }

    return 0;
}