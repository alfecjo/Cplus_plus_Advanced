#include <iostream>
#include <set>
#include <list>

using namespace std;

int main()
{
  
  int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 5 };

  // usa apenas os 7 primeiros elementos do vetor (índices 0 a 6)
  list<int> v(mynumbers, mynumbers + 7); 

  // O multiset pode conter elementos duplicados e os armazena automaticamente ordenados
  multiset<int> s1(v.begin(), v.end());

  // Verifica se há exatamente UMA ocorrência do número 5 no multiset
  // count(5) retorna o número de vezes que 5 aparece
  if (s1.count(5) == 1)  
    s1.erase(5);  // remove todas as ocorrências de 5 (nesse caso, uma só)

  // imprime os elementos ordenados do multiset
  for (multiset<int>::iterator i = s1.begin(); i != s1.end(); i++)
    cout << *i << ", ";

  return 0;
}