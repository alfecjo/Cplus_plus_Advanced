#include <set>
#include <iostream>
#include <functional>
// #include <utility> // para std::pair, contudo,  set já inclui <utility> automaticamente

using namespace std;

template <class T>
void print(T start, T end)
{
    for (; start != end; ++start)
    {
        std::cout << *start << " ";
    }
}

/* o método insert() da std::set retorna justamente esse pair
   pair<iterator, bool>

   iterator: aponta para o local onde o valor foi inserido (ou já estava).
   bool: indica se a inserção foi bem-sucedida (true) ou falhou porque o elemento já existia (false).

   pair<iterator_para_set_int, verdadeiro_ou_falso>
   typedef pair<set<int>::iterator, bool> Pair;

   função global, verifica se a inserção foi bem-sucedida
 */

typedef pair<set<int>::iterator, bool> Pair;

void check(const Pair &result)
{
    if (result.second == true)
    {
        cout << "A new value (" << *result.first << ") has been inserted" << endl;
    }
    else
    {
        cout << "Insertion failed, value " << *result.first << " already exists" << endl;
    }
}

int main()
{
    int t[] = {16, 10, 8, 40, 6, 15, 3, 9, 7, 2};
    set<int> s1(t, t + 10); // cria um set com os valores do array (sem duplicatas)

    cout << "First version of insert:" << endl;
    print(s1.begin(), s1.end());
    cout << endl;

    // Inserção com retorno de par indicando sucesso ou falha
    Pair p = s1.insert(10); // 10 já existe
    check(p);
    print(s1.begin(), s1.end());
    cout << endl;

    p = s1.insert(13); // novo valor ok!
    check(p);
    print(s1.begin(), s1.end());
    cout << endl
         << endl;

    cout << "Second version of insert:" << endl;

    // Inserção com dica de posição (otimização, mas sem garantia de inserção)
    set<int>::iterator it1 = s1.insert(s1.find(10), 11);
    set<int>::iterator it2 = s1.insert(s1.find(11), 11); // 11 já existe
    if (it1 == it2)
    {
        cout << "Second insertion was not successful" << endl;
    }
    print(s1.begin(), s1.end());
    cout << endl
         << endl;

    cout << "Third version of insert:" << endl;
    int t2[] = {4, 10, 15, 21, 0};
    s1.insert(t2, t2 + 5); // insere um intervalo de valores (novos e repetidos) com os repetidos sendo descartados
    print(s1.begin(), s1.end());
    cout << endl;

    return 0;
}
