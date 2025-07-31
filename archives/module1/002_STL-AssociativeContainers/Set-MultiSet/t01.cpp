#include <set>          // fornece set e multiset
#include <iostream>     
#include <functional>   // Para uso de comparadores como greater

using namespace std;


template <class T>
void print(T start, T end)
{
    while (start != end)
    {
        std::cout << *start << " ";
        start++;
    }
}

int main()
{
    // Vetor com elementos inteiros (alguns repetidos)
    int t[] = {2, 10, 8, 4, 5, 5, 3, 10, 7, 2};

    // Criação de um multiset vazio
    // multiset permite elementos duplicados, ao contrário do set
    multiset<int> s1;

    // Criação de um multiset a partir de um intervalo de elementos (do vetor t)
    // Os elementos serão ordenados de forma crescente e duplicatas serão mantidas
    multiset<int> s2(t, t + 10);
    print(s2.begin(), s2.end());
    cout << " :s2" << endl;

    // construtor de cópia: cria s3 como uma cópia de s2
    multiset<int> s3(s2);
    print(s3.begin(), s3.end());
    cout << " :s3" << endl;

    // Criação de um multiset com ordenação decrescente (usando greater<int>)
    multiset<int, greater<int>> s4(t, t + 10);
    print(s4.begin(), s4.end());
    cout << " :s4" << endl;

    // Não é permitido: tentar criar um multiset<greater> a partir de outro com ordenação padrão
    // Isso falha porque os comparadores são diferentes, logo os tipos são incompatíveis
    // multiset<int, greater<int>> s5(s3);

    // Atribuição direta entre multisets do mesmo tipo é permitida
    multiset<int> s6;
    s6 = s3;
    print(s6.begin(), s6.end());
    cout << " :s6" << endl;

    // Não é permitido: atribuição entre multisets com tipos diferentes (comparadores distintos)
    // s6 = s4;

    return 0;
}
