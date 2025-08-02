#include <iostream>
#include <vector>
#include <algorithm> // Algoritmos STL
#include <numeric>   // std::iota

using namespace std;

/*
    Algorithms Modifying (Algoritmos Modificadores)

    Esses algoritmos fazem parte da biblioteca padrão do C++ (STL - Standard Template Library)
    e são usados para modificar o conteúdo das coleções (como vector, list, deque, etc.).

    Os algoritmos modificadores **alteram diretamente os dados** nas coleções, diferentemente
    dos algoritmos de busca, por exemplo, que apenas inspecionam os dados.

    Exemplos de Algorithms Modifying:
    ---------------------------------
    - std::copy: copia elementos de uma coleção para outra.
    - std::fill: preenche a coleção com um valor.
    - std::generate: preenche com valores gerados por uma função.
    - std::replace: substitui valores por outro valor.
    - std::remove: "remove" elementos (na verdade, reordena e deixa lixo no final).
    - std::transform: aplica uma função a cada elemento.
    - std::rotate: rotaciona os elementos da coleção.
    - std::partition / std::stable_partition: separa elementos por uma condição.
    - std::reverse: inverte a ordem dos elementos.

    Nota: alguns algoritmos como `remove` ou `unique` **não alteram o tamanho do container**,
    e por isso, muitas vezes devem ser usados junto com `.erase()` para efetivar a modificação.
*/

template <typename T>
void print_vector(const vector<T>& v, const string& label) {
    cout << label << ": ";
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << "\n";
}

int main() {
    // Simulando notas dos alunos
    vector<int> notas(10);

    // Preenche com valores sequenciais a partir de 5 (i.e., 5,6,7,...)
    iota(notas.begin(), notas.end(), 5);
    print_vector(notas, "Notas originais");

    // Aplicar uma bonificação de 2 pontos usando transform
    vector<int> bonificadas(notas.size());
    transform(notas.begin(), notas.end(), bonificadas.begin(),
              [](int nota) { return nota + 2; });
    print_vector(bonificadas, "Notas bonificadas (+2)");

    // Substituir todas as notas 10 por 100 (para destacar, por exemplo)
    replace(bonificadas.begin(), bonificadas.end(), 10, 100);
    print_vector(bonificadas, "Notas após replace (10 -> 100)");

    // Remover todas as notas acima de 12 (limite arbitrário)
    auto it = remove_if(bonificadas.begin(), bonificadas.end(),
                        [](int nota) { return nota > 12; });
    bonificadas.erase(it, bonificadas.end());
    print_vector(bonificadas, "Notas após remoção (>12)");

    // Preencher com 8 os três primeiros valores
    fill_n(bonificadas.begin(), min<size_t>(3, bonificadas.size()), 8);
    print_vector(bonificadas, "Notas após fill_n (3 primeiros = 8)");

    // Criar uma cópia rotacionada das notas
    vector<int> rotacionadas = bonificadas;
    rotate(rotacionadas.begin(), rotacionadas.begin() + 1, rotacionadas.end());
    print_vector(rotacionadas, "Notas após rotate");

    // Criar uma cópia reversa
    vector<int> invertidas(bonificadas.rbegin(), bonificadas.rend());
    print_vector(invertidas, "Notas invertidas (reverse copy)");

    return 0;
}
