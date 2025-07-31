#include <set>          
#include <iostream>     
#include <functional>   // contém o comparador 'greater'

using namespace std;

// função genérica para imprimir elementos de um intervalo [start, end)
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
    
    int t[] = {1, 10, 8, 4, 6, 5, 3, 9, 7, 2};

    // conjunto vazio de inteiros (não é usado nesse exemplo)
    set<int> s1;

    // criação de um conjunto s2 com os elementos do vetor t
    // Os elementos são automaticamente ordenados em ordem crescente
    set<int> s2(t, t + 10);
    print(s2.begin(), s2.end());
    cout << " :s2" << endl;

    // construtor de cópia: s3 é cópia de s2
    set<int> s3(s2);
    print(s3.begin(), s3.end());
    cout << " :s3" << endl;

    // Criação de um conjunto s4 com os elementos de t, mas usando comparador 'greater'
    // Isso faz com que os elementos fiquem em ordem decrescente
    set<int, greater<int>> s4(t, t + 10);
    print(s4.begin(), s4.end());
    cout << " :s4" << endl;

    // Não é permitido:
    // set<int, greater<int>> s5(s3);
    // Isso resultaria em erro de compilação, pois os tipos são diferentes:
    // s3 é set<int> (ordem crescente) e s5 seria set<int, greater<int>> (ordem decrescente)

    /* 
       set<int> e set<int, greater<int>> são tipos diferentes porque o comparador 
       (menos<int> ou greater<int>) faz parte do tipo. 
       Para criar um conjunto com ordenação diferente a partir de outro, 
       use o construtor por intervalo, como foi feito em s4.
    */

    // Atribuição direta de conjuntos do mesmo tipo é permitida
    set<int> s6;
    s6 = s3; // OK: ambos são do tipo set<int>
    print(s6.begin(), s6.end());
    cout << " :s6" << endl;
    
    // Não é permitido:
    // s6 = s4;
    // Erro, pois s4 é set<int, greater<int>> e s6 é set<int>

    return 0;
}
