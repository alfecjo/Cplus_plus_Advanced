#include <set>          
#include <iostream>     // Entrada e saída padrão
#include <functional>   // Para usar comparadores como greater<int>

using namespace std;

// Função genérica para imprimir um intervalo [start, end)
template <class T> 
void print(T start, T end)
{
  for (; start != end; ++start)
  {
    std::cout << *start << " ";
  }
}

int main()
{
  // Vetor de inteiros com valores não ordenados
  int t[] = { 1, 10, 8, 4, 6, 5, 3, 9, 7, 2 };

  // Criação de um multiset com os valores do vetor
  // multiset permite elementos duplicados e os ordena (ordem crescente por padrão)
  multiset<int> s1(t, t + 10);

  // Criação de outro multiset, mas com ordenação decrescente (greater<int>)
  multiset<int, greater<int>> s2(s1.begin(), s1.end());

  cout << "Standard iterator:\n";

  // Iterador padrão: percorre os elementos do início ao fim, respeitando a ordenação do container
  multiset<int>::iterator it1 = s1.begin();
  for (; it1 != s1.end(); ++it1)
  {
    cout << *it1 << " ";
  }
  cout << endl;

  // Iteração padrão no multiset com ordenação decrescente
  it1 = s2.begin();
  for (; it1 != s2.end(); ++it1)
  {
    cout << *it1 << " ";
  }
  cout << endl;

  cout << "Reverse iterators:\n";

  // Iteradores reversos percorrem o container de trás para frente
  print(s1.rbegin(), s1.rend());
  cout << endl;
  print(s2.rbegin(), s2.rend());
  cout << endl;

  cout << "Const iterators:\n";

  // Iteradores constantes garantem somente leitura dos elementos
  print(s1.cbegin(), s1.cend());
  cout << endl;
  print(s2.cbegin(), s2.cend());
  cout << endl;

  cout << "Const iterators - reverse:\n";

  // Iteradores constantes reversos (do fim para o início, sem possibilidade de alteração)
  print(s1.crbegin(), s1.crend());
  cout << endl;
  print(s2.crbegin(), s2.crend());
  cout << endl;

  /***********************************************************/
  // Observação importante:
  // em std::set e std::multiset, **todos os iteradores são considerados constantes**
  // isso acontece porque modificar diretamente um elemento violaria a ordenação interna da estrutura

  // Mesmo que se use um "iterator" em vez de "const_iterator", não é possível alterar os valores:
  multiset<int>::const_iterator cit1 = s1.begin();  // Iterador constante
  it1 = s1.cbegin();                                // Também constante
  it1 = s1.begin();                                 // Ainda assim, não pode alterar

  // A linha abaixo causaria erro de compilação, pois não se pode modificar elementos diretamente:
  // *it1 = 100;

  return 0;
}
