#include <set>
#include <string>
#include <iostream>
#include <functional> // Para std::greater

using namespace std;

template <class T>
void print(T start, T end)
{
    for (; start != end; ++start)
    {
        std::cout << *start << " ";
    }
    cout << endl;
}

int main()
{
    int t[] = {2, 10, 8, 4, 5, 5, 3, 10, 7, 2};

    // set com ordenação decrescente e sem elementos duplicados
    set<int, greater<int>> s1(t, t + 10);

    // multiset com ordenação decrescente e permite duplicatas
    multiset<int, greater<int>> s2(t, t + 10);

    cout << "S1: ";
    print(s1.begin(), s1.end());

    // Exibe os elementos do multiset
    cout << "S2: ";
    print(s2.begin(), s2.end());

    // Conta quantas vezes o número 2 aparece em cada contêiner
    cout << "How many '2' there are?" << endl;
    cout << "S1: " << s1.count(2) << endl; // Sempre será no máximo 1, pois set não permite duplicatas
    cout << "S2: " << s2.count(2) << endl; // Pode ser mais de 1, pois multiset permite duplicatas

    // Verifica se o número 1 está presente no set
    if (s1.count(1) > 0)
    {
        cout << "There is '1' in the set\n";
    }
    else
    {
        cout << "There is no '1' in the set\n";
    }

    return 0;
}
