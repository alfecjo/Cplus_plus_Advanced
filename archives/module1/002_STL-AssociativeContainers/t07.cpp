#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main ()
{
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };

    // cria um set (sem duplicatas e ordenado) com os elementos do array
    set<int> s1(mynumbers, mynumbers + 7);

    // cria um multiset (permite duplicatas) com os mesmos elementos de s1
    multiset<int> s2(s1.begin(), s1.end());

    // insere novamente os elementos de s1, agora duplicando-os em s2
    s2.insert(s1.begin(), s1.end());

    // remove os elementos no intervalo [1, 4), ou seja, 1, 2 e 3
    s2.erase(s2.lower_bound(1), s2.upper_bound(4)); // LINE I

    // imprime todos os elementos de s2
    for (multiset<int>::iterator i = s2.begin(); i != s2.end(); i++)
    {
        cout << *i << ", ";        
    }

    return 0;
}
