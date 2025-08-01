#include <set>
#include <iostream>
#include <functional> // opcional neste caso, útil para ordenação personalizada
#include <iterator>   // Para std::distance

using namespace std;

template <class T>
void print(T start, T end)
{
    for (; start != end; ++start)
    {
        cout << *start << " ";
    }
}

int main()
{
    int t[] = {16, 10, 8, 40, 6, 15, 3, 9, 7, 2};

    // Os elementos serão automaticamente ordenados
    multiset<int> s1(t, t + 10);

    print(s1.begin(), s1.end());
    cout << endl;

    // --- Primeira forma de inserção (simples) ---
    cout << "Primeira forma de insert:\n";
    multiset<int>::iterator it1 = s1.insert(13); // Insere 13
    print(s1.begin(), s1.end());
    cout << endl;
    cout << "Posição onde 13 foi inserido: " << distance(s1.begin(), it1) << endl
         << endl;

    // Insere 13 novamente (duplicados são permitidos em multiset)
    multiset<int>::iterator it2 = s1.insert(13);
    print(s1.begin(), s1.end());
    cout << endl;
    // lembrando que o multiset é ordenado, então o segundo 13 será colocado após o primeiro
    cout << "Posição do segundo 13: " << distance(s1.begin(), it2) << endl
         << endl;

    // --- Segunda forma de inserção (com dica de posição) ---
    cout << "Segunda forma de insert (com dica de posição):\n";

    // Tenta inserir 11 antes da posição onde está o 10.
    // Apesar da dica, o `multiset` mantém a ordenação automática,
    // então o 11 será inserido na posição correta segundo a ordem,
    // ou seja, entre 10 e 13. A dica não foi exata, mas a inserção ocorre corretamente.
    it1 = s1.insert(s1.find(10), 11);

    // Tenta inserir 11 antes da posição onde está o primeiro 11 (inserido acima).
    // Como o multiset permite elementos duplicados, um novo 11 será inserido,
    // também em ordem apropriada. Como a dica de posição é próxima do local correto,
    // a inserção pode ser mais eficiente.
    it2 = s1.insert(s1.find(11), 11);

    // A sobrecarga insert(pos, value) aceita uma dica de posição para otimizar a inserção.
    // Se 'pos' estiver próximo da posição correta (segundo a ordenação), a busca interna pode ser evitada,
    // tornando a inserção mais eficiente (potencialmente O(1) em vez de O(log n)).
    // Porém, se a dica estiver errada ou muito distante, o multiset ignora a dica
    // e realiza a busca completa, mantendo a ordenação automaticamente. Isso significa otimização...
    // multiset é implementado como uma árvore binária balanceada (geralmente uma Red-Black Tree) e
    // está associada a vetores associativos, permitindo inserções, buscas e remoções eficientes.
    // daí 'Associative Containers' (Containers Associativos).

    // Verifica se os dois iteradores apontam para o mesmo elemento
    if (it1 == it2)
    {
        cout << "A segunda inserção de 11 não teve efeito (mas isso não ocorre com multiset, pois permite duplicados)\n";
    }

    print(s1.begin(), s1.end());
    cout << endl
         << endl;

    // --- Terceira forma de inserção (intervalo) ---
    cout << "Terceira forma de insert (intervalo):\n";
    int t2[] = {4, 10, 15, 21, 0};
    // Insere todos os elementos do vetor t2 no multiset
    s1.insert(t2, t2 + 5);
    print(s1.begin(), s1.end());
    cout << endl;

    return 0;
}