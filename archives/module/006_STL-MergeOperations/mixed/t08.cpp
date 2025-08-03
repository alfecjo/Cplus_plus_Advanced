#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Função auxiliar para imprimir os elementos de um vetor
void imprimir(int id)
{
    cout << id << ", ";
}

int main()
{
    // IDs de clientes da base antiga
    int base_antiga[] = {102, 208, 101, 150};

    // IDs de clientes da base nova
    int base_nova[] = {150, 300, 102, 400};

    // Vetores para armazenar os dados
    vector<int> uniao_ids(10); // tamanho suficiente para armazenar a união

    // Ordena as duas listas (pré-requisito para usar set_union)
    sort(base_antiga, base_antiga + 4);
    sort(base_nova, base_nova + 4);

    // Aplica a união dos conjuntos, eliminando duplicatas
    auto fim = set_union(base_antiga, base_antiga + 4,
                         base_nova, base_nova + 4,
                         uniao_ids.begin());

    // Ajusta o tamanho do vetor resultante com base na união real
    uniao_ids.resize(fim - uniao_ids.begin());

    // Imprime os IDs únicos e ordenados
    cout << "IDs de clientes únicos combinados:\n";
    for_each(uniao_ids.begin(), uniao_ids.end(), imprimir);
    cout << endl;

    return 0;
}
