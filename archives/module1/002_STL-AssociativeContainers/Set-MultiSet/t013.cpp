#include <set>
#include <string>
#include <iostream>

using namespace std;

template <class T>
void print(T start, T end)
{
    for (; start != end; ++start)
    {
        cout << *start << " ";
    }
    cout << endl;
}

int main()
{
    // Vetores de strings, com elementos duplicados
    string t1[] = {"aaa", "bbb", "ccc", "aaa"}; // "aaa" aparece duas vezes
    string t2[] = {"xxx", "yyy", "zzz", "xxx"}; // "xxx" aparece duas vezes

    // Criação de multiset com todos os elementos dos vetores
    multiset<string> s1(t1, t1 + 4); // insere 4 elementos
    multiset<string> s2(t2, t2 + 4); // insere 4 elementos

    // Mostra o conteúdo de s1 e s2
    cout << "Conteúdo inicial de s1: ";
    print(s1.begin(), s1.end());

    cout << "Conteúdo inicial de s2: ";
    print(s2.begin(), s2.end());

    // Contando quantas vezes "aaa" aparece em s1
    cout << "\nQuantidade de vezes que 'aaa' aparece em s1: " << s1.count("aaa") << endl;

    // Inserindo mais uma ocorrência de "bbb" em s1
    s1.insert("bbb");
    cout << "Após inserir mais uma 'bbb' em s1: ";
    print(s1.begin(), s1.end());
    cout << "Agora 'bbb' aparece " << s1.count("bbb") << " vezes em s1.\n";

    // Removendo todas as ocorrências de "aaa"
    cout << "\nRemovendo todas as ocorrências de 'aaa' em s1:\n";
    s1.erase("aaa");
    print(s1.begin(), s1.end());

    // Troca o conteúdo de s1 com s2
    cout << "\nTrocando s1 com s2 usando swap...\n";
    s1.swap(s2);

    // Mostra os conjuntos após a troca
    cout << "s1 (após swap): ";
    print(s1.begin(), s1.end());

    cout << "s2 (após swap): ";
    print(s2.begin(), s2.end());

    // Troca novamente para restaurar
    s2.swap(s1);

    cout << "\nConjuntos após nova troca:\n";
    cout << "s1: ";
    print(s1.begin(), s1.end());

    cout << "s2: ";
    print(s2.begin(), s2.end());

    // Limpando todos os elementos de s1
    s1.clear();
    cout << "\nApós limpar s1, tamanho = " << s1.size() << endl;

    return 0;
}
