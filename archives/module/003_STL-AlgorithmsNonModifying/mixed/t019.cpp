#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

// Função personalizada usada para comparar elementos
bool identical(int a, int b)
{
    return b == a; // LINE I
}

int main()
{
    // Vetores de dados
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5, 6, 6, 9, 8, 2};
    int othernumbers[] = {3, 9, 0, 3, 1, 4, 3, 6, 6, 9, 8, 3};

    // Inicializa containers com os dados
    vector<int> v1(mynumbers, mynumbers + 12);
    deque<int> d1(othernumbers, othernumbers + 12);

    // LINE II + LINE III: Aplica mismatch com função de comparação personalizada
    pair<deque<int>::iterator, vector<int>::iterator> result;
    result = mismatch(d1.begin(), d1.end(), v1.begin(), identical);

    // Verifica se são idênticos
    if (result.first == d1.end() && result.second == v1.end())
        cout << "Identical" << endl;
    else
        cout << "Not identical" << endl;

    return 0;
}
