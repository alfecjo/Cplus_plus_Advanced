#include <iostream>   
#include <set>        
#include <vector>     

using namespace std;

int main() {    
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 7 };

    // vetor `v` com os 7 primeiros elementos do array (exclui o último '7')
    vector<int> v(mynumbers, mynumbers + 7);

    // cria um multiset `s1` a partir do vetor `v` 
    // multiset permite elementos duplicados e "armazena em ordem crescente automaticamente"...
    multiset<int> s1(v.begin(), v.end());

    // insere novamente todos os elementos do vetor `v` no multiset `s1`
    // duplica os valores que estavam originalmente no vetor
    s1.insert(v.begin(), v.end());  

    // cria um par de iteradores que apontam para o intervalo de valores iguais a 5
    // `equal_range(5)` e retorna:
    //   - primeiro: o iterador para o primeiro 5
    //   - segundo: o iterador logo após o último 5...
    pair<multiset<int>::iterator, multiset<int>::iterator> range;
    range = s1.equal_range(5);

    // imprime todos os valores iguais a 5 dentro do intervalo retornado
    while (range.first != range.second) {
        cout << *range.first << ", ";
        ++range.first;
    }

    return 0;
}
