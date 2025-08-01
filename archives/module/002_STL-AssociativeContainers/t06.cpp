#include <iostream>
#include <set>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
    vector<int> v(mynumbers, mynumbers + 7);

    // multiset com ordenação padrão (crescente)
    multiset<int> s1(v.begin(), v.end());

    // Insere novamente os elementos do vetor em s1 (aceita duplicatas)
    s1.insert(v.begin(), v.end());

    // multiset com ordenação decrescente (greater<int>)
    multiset<int, greater<int>> s2(v.begin(), v.end());

    // insere o número 9 em s2 (aceita duplicatas)
    s2.insert(9);

    // imprime elementos de s1 (crescente)
    for (multiset<int>::iterator i = s1.begin(); i != s1.end(); ++i)
        cout << *i << " - ";
    cout << endl;

    // Imprime elementos de s2 (decrescente)
    for (multiset<int, greater<int>>::iterator i = s2.begin(); i != s2.end(); ++i)
        cout << *i << ", ";
    cout << endl;

    return 0;
}
