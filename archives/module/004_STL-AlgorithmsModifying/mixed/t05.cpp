#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// Função para imprimir elementos de um container usando iteradores
template <typename Iterator>
void print_range(Iterator start, Iterator end) {
    for (Iterator it = start; it != end; ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    // Array inicial com valores (podem ter repetidos)
    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5, 3, 2};

    // Criando um set com os valores do array
    // O set automaticamente ordena e elimina duplicatas
    set<int> s1(mynumbers, mynumbers + 9);

    cout << "Conteúdo do set (ordenado e sem duplicatas): ";
    print_range(s1.begin(), s1.end());  // Exibe: 0 1 2 3 4 5 9

    // Criar um vetor com os elementos do set em ordem reversa
    vector<int> v1(s1.rbegin(), s1.rend());

    cout << "Conteúdo do vetor (set invertido): ";
    print_range(v1.begin(), v1.end());  // Exibe: 9 5 4 3 2 1 0

    // Criar outro vetor baseado em v1 (cópia exata)
    vector<int> v2 = v1;

    cout << "Conteúdo do segundo vetor (cópia de v1): ";
    print_range(v2.begin(), v2.end());

    // Modificar v2 para que fique diferente
    // Exemplo: incrementar todos os valores em 10
    for (auto& x : v2) {
        x += 10;
    }

    cout << "v2 após adicionar 10 a cada elemento: ";
    print_range(v2.begin(), v2.end());  // Exibe valores incrementados

    // Agora vamos trocar os 3 primeiros elementos entre v1 e v2
    swap_ranges(v1.begin(), v1.begin() + 3, v2.begin());

    cout << "v1 após swap_ranges dos 3 primeiros elementos com v2: ";
    print_range(v1.begin(), v1.end());

    cout << "v2 após swap_ranges dos 3 primeiros elementos com v1: ";
    print_range(v2.begin(), v2.end());

    // Finalmente, imprimir o set novamente para mostrar que ele não foi alterado
    cout << "Set permanece intacto: ";
    print_range(s1.begin(), s1.end());

    return 0;
}
