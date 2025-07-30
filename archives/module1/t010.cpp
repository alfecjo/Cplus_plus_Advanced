#include <iostream>     
#include <set>          // set e multiset.

using namespace std;    // evitar ter que escrever std:: na frente de cout, multiset, etc...

int main () {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 7 };

    // elementos: 3, 9, 0, 2, 1, 4, 5
    multiset <int> s1(mynumbers, mynumbers + 7);

    // insere o valor 6 na posição onde está o elemento com valor 3.
    // de dentro para fora... a função `find(3)` retorna um iterator para a primeira ocorrência de 3,
    // e `insert(iterator, value)` insere o valor *próximo a essa posição*, otimizando a operação.
    // lembrando que: multiset é um container ordenado — a posição fornecida é apenas uma **sugestão**.
    s1.insert(s1.find(3), 6);

    // percorre o multiset (que armazena os elementos em ordem crescente automaticamente)
    // e imprime os elementos separados por vírgula.
    for (multiset<int>::iterator i = s1.begin(); i != s1.end(); i++)
        cout << *i << ", ";

    return 0;
}
