#include <vector>
#include <iostream>

using namespace std;

// Função para imprimir elementos de um intervalo
template <typename T>
ostream& print(const T& start, const T& end)
{
    for (T it = start; it != end; ++it)
    {
        cout << *it << " ";
    }
    return cout;
}

int main()
{
    int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> v1(tab, tab + 10);  // Cria o vetor com os elementos do array
    vector<int> v2;                 // Vetor auxiliar que receberá os valores invertidos

    // Enquanto v1 não estiver vazio, pegue o último elemento e insira no início de v2
    while (!v1.empty())
    {
        int last = v1.back();       // Pega o último elemento
        v1.pop_back();              // Remove o último elemento
        v2.insert(v2.begin(), last); // Insere no início de v2
    }

    // Imprime v2 na ordem invertida (ou seja, mesma ordem original do array)
    print(v2.rbegin(), v2.rend()) << ": " << v2.size() << endl;

    return 0;
}
