#include <iostream>
#include <set>
#include <vector>
#include <functional> // para greater<int>

using namespace std;

/*
Associative Containers – STL C++

Esses containers armazenam pares *chave-valor* ou apenas *chaves*, mantendo os dados
automaticamente ordenados por chave.
Utilizam estruturas internas como árvores balanceadas (geralmente Red-Black Tree -> n sei se Flamengo, S C do Recife, C A Paranaense ou Grêmio Esportivo Brasil, kkk)
para garantir desempenho log(n) em busca, inserção e remoção.

 set:
    - Armazena apenas *valores únicos* (sem repetições).
    - Os elementos são automaticamente ordenados.
    - Ideal para quando se precisa verificar rapidamente se um elemento existe.
    - Exemplo: armazenar um conjunto de IDs únicos.

 multiset:
    - Similar ao set, mas permite *valores repetidos*.
    - Também ordenado automaticamente.
    - Exemplo: contagem de ocorrências, como histogramas simples.

 map:
    - Armazena *pares chave-valor* com *chaves únicas*.
    - Acesso rápido ao valor por meio da chave (como um dicionário).
    - Exemplo: associar nomes a números, sensores a leituras, etc.

 multimap:
    - Semelhante ao map, mas permite *múltiplos valores* para a *mesma chave*.
    - Exemplo: log de eventos por código de erro (vários eventos para o mesmo código).

Situações em que aparecem juntos:
    - Pode-se usar um multimap para agrupar dados antes de um processamento que espera map ou set.
    - map/set são usados para indexação, verificação de unicidade, ou lookup eficiente.
    - multiset/multimap ajudam quando há duplicatas que precisam ser tratadas por agrupamento ou contagem.

Desempenho:
    - Todas as operações básicas (inserção, busca, remoção) são em O(log n).
    - Mantêm os dados ordenados conforme o operador < (padrão) ou um comparador customizado.

Diferente dos containers sequenciais (vector, deque, list), os associativos não possuem posição física clara
(você não acessa elementos por índice).

*/


int main ()
{
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };

    // container sequêncial
    // vector: permite acesso aleatório, redimensionável
    vector<int> v(mynumbers, mynumbers + 7);

    // container associativo
    // set: não permite duplicatas, ordena automaticamente os elementos
    set<int> set1(v.begin(), v.end());

    set<int, greater<int>> set2(v.begin(), v.end()); // ordenação decrescente

    for (set<int, greater<int>>::iterator i = set2.begin(); i != set2.end(); ++i)
        cout << *i << " ";

    //cout << endl;

    for (set<int>::iterator i = set1.begin(); i != set1.end(); ++i)
        cout << *i << ", ";

    cout << endl;

    return 0;
}
