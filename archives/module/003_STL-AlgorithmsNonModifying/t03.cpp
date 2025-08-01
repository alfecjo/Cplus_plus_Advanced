#include <iostream>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

// para imprimir elementos..
// OBS: 'int &' porque 'list' permite modificar os elementos
// se for usar com 'set', o correto é 'const int &', pois os elementos de 'set' não podem ser modificados
void print(int & value) {
    cout << value << " ";
}

// Functor (objeto-função), que é uma struct com operator()
// Permite ser tratado como uma função, mas também pode manter estado interno, se necessário
// Também deve usar 'const int &' para funcionar com 'set', de novo, porque 'set' não permite modificar seus elementos
struct Print {
    void operator()(int & value) {
        cout << value << " ";
    }
};

int main() {
    int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> l1(t, t + 10);

    // -----------------------------
    // USO DE FUNÇÃO COMUM COM for_each
    // -----------------------------
    cout << "Imprimir todos os elementos da lista - usando função\n";
    for_each(l1.begin(), l1.end(), print); // chama a função 'print' para cada elemento
    cout << endl << endl;

    // -----------------------------
    // USO DE FUNCTOR (OBJETO-FUNÇÃO) COM for_each
    // -----------------------------
    cout << "Imprimir todos os elementos da lista - usando objeto-função (functor)\n";
    for_each(l1.begin(), l1.end(), Print()); // Cria uma instância de Print e aplica como função
    cout << endl << endl;

    // ATENÇÃO: em containers como 'set', os elementos não podem ser modificados
    // Portanto, devemos passar os valores como 'const int &' na função ou functor
    // Descomente a seguir para testar com 'set'

    /*
    // Criando um conjunto (set<int>) com os mesmos elementos
    set<int> s1(t, t + 10);

    // Agora usamos versão da função com argumento 'const int &'
    // Isso é necessário porque 'set' não permite modificar seus elementos
    auto printSet = [](const int & value) {
        cout << value << " ";
    };

    struct PrintSet {
        void operator()(const int & value) {
            cout << value << " ";
        }
    };

    cout << "Imprimir todos os elementos do set - usando função (lambda)\n";
    for_each(s1.begin(), s1.end(), printSet); 
    cout << endl << endl;

    cout << "Imprimir todos os elementos do set - usando objeto-função\n";
    for_each(s1.begin(), s1.end(), PrintSet());
    cout << endl << endl;
    */

    return 0;
}
