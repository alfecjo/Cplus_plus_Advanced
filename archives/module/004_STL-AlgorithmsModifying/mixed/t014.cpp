#include <iostream>     // Necessário para a função cout
#include <algorithm>    // Necessário para os algoritmos fill, fill_n e for_each
#include <vector>       // Necessário para usar o container vector
#include <set>          // Incluído, mas não utilizado neste exemplo

using namespace std;

// Função que imprime um número seguido de vírgula
void printer(int i) {
    cout << i << ", ";
}

int main() {
    // Cria um vetor v1 com 7 elementos, todos inicialmente com valor 1
    vector<int> v1(7, 1);  // v1 = {1, 1, 1, 1, 1, 1, 1}

    // Preenche do 4º até o penúltimo elemento com o valor 8
    // fill(início, fim, valor) -> preenche do início até (mas sem incluir) fim
    fill(v1.begin() + 3, v1.end() - 1, 8);  
    // Agora v1 = {1, 1, 1, 8, 8, 1, 1}

    // Preenche 5 elementos, a partir da posição 4 (índice 4), com valor 7
    // fill_n(início, quantidade, valor)
    fill_n(v1.begin() + 4, 5, 7);
    // Vai tentar preencher 5 elementos a partir do índice 4: sobrescrevendo até além do vetor
    // Isso é um erro de **comportamento indefinido**, pois ultrapassa o fim do vetor!
    // Resultado imprevisível — em sistemas permissivos, ele sobrescreve apenas o que for possível

    // Imprime todos os elementos do vetor
    for_each(v1.begin(), v1.end(), printer);
    // Saída esperada (em compiladores permissivos): 1, 1, 1, 8, 7, 7, 7,

    return 0;
}
