#include <map>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

template <class T>
void print(T start, T end)
{
    while (start != end)
    {
        cout << start->first << ":" << start->second << " ";
        start++;
    }
    cout << endl;
}

// Preenche o map com pares {valor, valor} onde chave e valor são iguais
// trata-se apenas de um artifício para simplificar o exemplo
template <class T, class U>
void fillMap(map<T, T> &m, U start, U end)
{
    for (; start != end; ++start)
    {
        m.insert(pair<T, T>(*start, *start)); // Ex: {"aaa", "aaa"}
    }
}

int main()
{
    string t1[] = {"aaa", "bbb", "ccc"};
    string t2[] = {"xxx", "yyy", "zzz"};
    
    map<string, string> m1;
    map<string, string> m2;

    fillMap(m1, t1, t1 + 3);
    fillMap(m2, t2, t2 + 3);

    cout << "Conteúdo inicial:\n";
    cout << "m1: ";
    print(m1.begin(), m1.end());
    cout << "m2: ";
    print(m2.begin(), m2.end());

    // Troca os conteúdos dos maps
    cout << "\nSwap m1 <-> m2:\n";
    m1.swap(m2);

    cout << "Após troca:\n";
    cout << "m1: ";
    print(m1.begin(), m1.end());
    cout << "m2: ";
    print(m2.begin(), m2.end());

    // Realiza nova troca (volta ao estado anterior)
    cout << "\nSwap m2 <-> m1:\n";
    m2.swap(m1);

    cout << "Após segunda troca:\n";
    cout << "m1: ";
    print(m1.begin(), m1.end());
    cout << "m2: ";
    print(m2.begin(), m2.end());

    // Acessando valor diretamente por chave
    cout << "\nAcessando valor pela chave 'bbb' no m1:\n";
    if (m1.find("bbb") != m1.end())
    {
        cout << "bbb -> " << m1["bbb"] << endl;
    }
    else
    {
        cout << "Chave 'bbb' não encontrada.\n";
    }

    return 0;
}
