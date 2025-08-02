#include <iostream>
#include <algorithm> // Para for_each e transform
#include <vector>
#include <set>

using namespace std;

void printer(int i)
{
    cout << i << ", ";
}

int multiply(int a)
{
    return a * 2;
}

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

    // Criação de um vetor (vector) com os elementos do array
    vector<int> v1(mynumbers, mynumbers + 7);

    // Criação de um conjunto ordenado (set) a partir do mesmo array
    set<int> s1(mynumbers, mynumbers + 7); // remove duplicados e ordena

    /*
      Aplica a função multiply (dobra o valor) em cada elemento do set s1.
      Os resultados são armazenados nas posições correspondentes do vector v1.

      transform(origem_begin, origem_end, destino_begin, funcao)
    */
    transform(s1.begin(), s1.end(), v1.begin(), multiply); // LINE II

    // Imprime os elementos modificados do vetor v1
    for_each(v1.begin(), v1.end(), printer);

    return 0;
}
