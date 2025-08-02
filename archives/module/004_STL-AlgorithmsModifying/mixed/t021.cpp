#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>  // para reverse

using namespace std;

int main() {
    
    // Vector - sequência linear mutável
    
    vector<int> v = {1, 2, 3, 4, 5};

    cout << "Original vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    reverse(v.begin(), v.end());  // inverte os elementos do vetor

    cout << "Reversed vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;


    
    // DEQUE — sequência linear mutável (como vector)
    deque<int> d = {10, 20, 30, 40, 50};

    cout << "\nOriginal deque: ";
    for (int x : d) cout << x << " ";
    cout << endl;

    reverse(d.begin(), d.end());  // também funciona

    cout << "Reversed deque: ";
    for (int x : d) cout << x << " ";
    cout << endl;
    
    // SET — estrutura ordenada automaticamente (não mutável por posição)
    
    set<int> s = {100, 50, 300, 200};

    cout << "\nOriginal set (ordenado automaticamente): ";
    for (int x : s) cout << x << " ";
    cout << endl;

    // Não podemos usar reverse(s.begin(), s.end()) diretamente
    //     Isso daria erro de compilação porque os iteradores de set são constantes
    //     e a estrutura mantém a ordenação automática (não faz sentido inverter).

    //  mas podemos iterar em ordem reversa usando rbegin() e rend()
    cout << "Iterating set in reverse order (com rbegin/rend): ";
    for (auto it = s.rbegin(); it != s.rend(); ++it)
        cout << *it << " ";
    cout << endl;

    // Ou podemos copiar os elementos do set para um vector, e inverter lá
    vector<int> v_from_set(s.begin(), s.end());
    reverse(v_from_set.begin(), v_from_set.end());

    cout << "Set values copied to vector and reversed: ";
    for (int x : v_from_set) cout << x << " ";
    cout << endl;

    return 0;
}
