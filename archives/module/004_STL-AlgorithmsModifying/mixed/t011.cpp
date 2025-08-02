#include <iostream>
#include <algorithm>    // Para for_each, replace_if
#include <vector>   
#include <set>          // Para std::set (não é usado diretamente neste exemplo)

using namespace std;

// Função para imprimir cada elemento
void printer(int i) {
    cout << i << ", ";
}

// Função que classifica se o valor deve ser substituído
// Critério: retorna true se o número for maior que 3
bool classifier(int v) {
    return v - 3 > 0;  // equivalente a: return v > 3;
}

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };

    vector<int> v1(mynumbers, mynumbers + 7);

    set<int> s1(mynumbers, mynumbers + 7);

    // Substitui todos os elementos de v1 que satisfazem o predicado "classifier"
    // ou seja, todos os valores > 3 serão substituídos por 7
    replace_if(v1.begin(), v1.end(), classifier, 7);

    // Imprime os valores do vetor atualizado
    for_each(v1.begin(), v1.end(), printer);

    return 0;
}