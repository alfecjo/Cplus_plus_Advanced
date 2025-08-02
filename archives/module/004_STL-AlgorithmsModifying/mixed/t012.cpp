#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void printer(int i)
{
    cout << i << ", ";
}

// Predicado que retorna verdadeiro para valores maiores que 3
bool classifier(int v)
{
    return v - 3 > 0; // equivalente a: return v > 3;
}

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

    vector<int> v1(mynumbers, mynumbers + 7);

    // Cria um conjunto (set) com os valores do array (valores únicos e ordenados)
    set<int> s1(mynumbers, mynumbers + 7);

    // Substitui todos os valores de v1 que satisfazem o predicado classifier (v > 3) por 7
    replace_if(v1.begin(), v1.end(), classifier, 7); 

    // Imprime todos os valores do vetor v1 após a substituição
    for_each(v1.begin(), v1.end(), printer); 

    return 0;
}
