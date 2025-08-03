#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/* Função auxiliar para imprimir cada elemento */
void printer(int i)
{
    cout << i << ", ";
}

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

    vector<int> v1(mynumbers, mynumbers + 7);

    // Substituindo bind1st(less_equal<int>(), 4) por lambda
    int counter = count_if(v1.begin(), v1.end(), [](int x)
                           { return x <= 4; }); // conta quantos elementos são <= 4

    v1.push_back(counter); // adiciona o contador ao final do vetor

    // Imprime o vetor de trás pra frente
    for_each(v1.rbegin(), v1.rend(), printer);

    return 0;
}
