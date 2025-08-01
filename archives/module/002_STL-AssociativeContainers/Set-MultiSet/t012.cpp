#include <set>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

template <class T>
void print(T start, T end)
{
    for (; start != end; ++start)
    {
        std::cout << *start << " "; // imprime o valor apontado pelo iterador
    }
}

int main()
{
    // vetores de strings
    string t1[] = {"aaa", "bbb", "ccc"};
    string t2[] = {"xxx", "yyy", "zzz"};

    // Cria (set) com os elementos dos vetores
    set<string> s1(t1, t1 + 3);
    set<string> s2(t2, t2 + 3);

    cout << "s1: ";
    print(s1.begin(), s1.end());
    cout << endl;

    cout << "s2: ";
    print(s2.begin(), s2.end());
    cout << endl;

    // Troca o conteúdo de s1 com s2
    cout << "swap:\n";
    s1.swap(s2);

    // Imprime novamente os conjuntos após a troca
    cout << "s1: ";
    print(s1.begin(), s1.end());
    cout << endl;
    cout << "s2: ";
    print(s2.begin(), s2.end());
    cout << endl;

    // troca novamente os conjuntos
    cout << "swap:\n";
    s2.swap(s1);

    // imprime os conjuntos após a segunda troca
    cout << "S1: ";
    print(s1.begin(), s1.end());
    cout << endl;
    cout << "S2: ";
    print(s2.begin(), s2.end());
    cout << endl;

    return 0; 
}
