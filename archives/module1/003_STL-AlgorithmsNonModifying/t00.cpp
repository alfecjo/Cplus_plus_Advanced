#include <iostream>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

/*
Algorithms Non-Modifying – STL C++

Esses algoritmos percorrem os elementos de uma coleção (geralmente usando iteradores),
mas **não alteram** os dados originais. Como o nome diz: *não modificam* — só olham, contam, procuram e analisam.

São ideais para buscas, verificações, comparações e medições dentro de ranges, mantendo a coleção intacta
(como um fiscal de obra: observa tudo, mas não pega na enxada 😅).

Principais exemplos:

    - all_of(begin, end, pred):
        Verifica se *todos* os elementos satisfazem uma condição.
        Exemplo: todos os números são pares?

    - any_of(begin, end, pred):
        Verifica se *ao menos um* elemento satisfaz a condição.
        Exemplo: há algum número negativo?

    - none_of(begin, end, pred):
        Verifica se *nenhum* elemento satisfaz a condição.
        Exemplo: todos os nomes estão vazios?

    - for_each(begin, end, func):
        Aplica uma função a cada elemento (sem modificar a coleção em si).
        Exemplo: imprimir cada valor, somar em uma variável externa etc.

    - find(begin, end, value):
        Procura por um elemento com valor exato.
        Retorna iterador para o primeiro encontrado, ou end se não achar.

    - find_if(begin, end, pred):
        Parecido com `find`, mas usa uma função condicional (predicate).
        Exemplo: achar o primeiro número primo.

    - find_if_not(begin, end, pred):
        Oposto do `find_if`: acha o primeiro que *não* satisfaz a condição.

    - count(begin, end, value):
        Conta quantas vezes um valor aparece no range.

    - count_if(begin, end, pred):
        Conta quantos elementos satisfazem a condição.

    - mismatch(range1, range2):
        Compara dois ranges, retorna o primeiro par de elementos que diferem.

    - equal(range1, range2):
        Verifica se dois ranges têm os *mesmos elementos* na mesma ordem.

    - search(range1, range2):
        Procura se o `range2` aparece como subsequência dentro do `range1`.

    - adjacent_find(begin, end):
        Procura por dois elementos consecutivos com o *mesmo valor*.

Aplicações:
    - Muito úteis para validação de dados, análise, filtragem e inspeção sem afetar o estado da coleção.
    - Base para lógica de negócio que depende de *comportamento observado*, sem efeitos colaterais.

Observações:
    - Não alteram os dados, mas podem gerar *efeitos colaterais* (ex.: `for_each` com `cout`, logs, etc).
    - Geralmente exigem que os iteradores sejam ao menos `InputIterator`.

Dica ninja:
    Use com lambdas para manter o código elegante e expressivo, evitando funções auxiliares separadas
    (a menos que queira impressionar alguém com abstração pura 😎).

*/

void print(const int& value)
{
    cout << value << " ";
}

// Functor (objeto função) que imprime um valor - também precisa ser const para uso com set
struct Print
{
    void operator()(const int& value) const
    {
        cout << value << " ";
    }
};

int main()
{
    int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Cria uma lista (container sequencial) com os valores do array
    list<int> l1(t, t + 10);

    cout << "Print all elements of the list - using function\n";
    // Usa o algoritmo for_each para percorrer todos os elementos da lista
    for_each(l1.begin(), l1.end(), print);
    cout << endl << endl;

    cout << "Print all elements of the list - using function object\n";
    // Usa o algoritmo for_each com um functor (objeto função)
    for_each(l1.begin(), l1.end(), Print());
    cout << endl << endl;

    // Agora o mesmo com um container associativo: set
    // Lembrando que o set não permite modificar seus elementos durante a iteração
    set<int> s1(t, t + 10);

    // Usa o algoritmo for_each para percorrer todos os elementos do set
    cout << "Print all elements of the set - using function\n";
    for_each(s1.begin(), s1.end(), print);
    cout << endl << endl;

    // Usa o algoritmo for_each com um functor (objeto função) para o set
    cout << "Print all elements of the set - using function object\n";
    for_each(s1.begin(), s1.end(), Print());
    cout << endl << endl;

    return 0;
}
