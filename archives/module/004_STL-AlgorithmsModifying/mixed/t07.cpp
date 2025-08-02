#include <iostream>
#include <algorithm> // Para usar algoritmos STL como transform, for_each
#include <vector>
#include <set> // Container do tipo conjunto (valores únicos ordenados)

using namespace std;

void printer(int i)
{
    cout << i << ", ";
}

int multiply(int a)
{
    return a * 2; // LINE I
}

int main()
{
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};

    vector<int> v1(mynumbers, mynumbers + 7);


    // O set elimina automaticamente duplicatas (se houvesse) e mantém os valores ordenados
    set<int> s1(mynumbers, mynumbers + 7);

    // Aplica a função multiply a cada elemento do set s1, e armazena o resultado no vetor v1
    // transform(source_begin, source_end, destination_begin, function)
    transform(s1.begin(), s1.end(), v1.begin(), multiply); // LINE II

    for_each(s1.begin(), s1.end(), printer);

    return 0;
}
