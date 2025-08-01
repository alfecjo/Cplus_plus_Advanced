#include <set>
#include <iostream>

using namespace std;

template < class T > 
void print(T start, T end)
{
  for (; start != end; ++start)
  {
    std::cout << *start << " "; // imprime o valor apontado pelo iterador
  }
}

int main()
{
  int t[] = { 2, 10, 8, 4, 5, 5, 3, 10, 7, 2 };

  // cria um multiset com os valores do vetor (permite valores duplicados)
  multiset<int> s1(t, t + 10);

  // cria um set com os valores do multiset (não permite valores duplicados)
  set<int> s2(s1.begin(), s1.end());

  // Informações sobre o multiset
  cout << "Multiset:\n";
  cout << "Size: " << s1.size()          // Tamanho atual (quantidade de elementos)
       << " Max size: " << s1.max_size() // Tamanho máximo que pode ser armazenado
       << endl;
  print(s1.begin(), s1.end()); // Imprime todos os elementos (ordenados e com repetição)
  cout << endl;

  // Informações sobre o set
  cout << "Set:\n";
  cout << "Size: " << s2.size()          // Tamanho atual (apenas valores únicos)
       << " Max size: " << s2.max_size() // Tamanho máximo possível
       << endl;
  print(s2.begin(), s2.end()); // Imprime os valores únicos ordenados
  cout << endl;

  // apaga todos os elementos do multiset
  cout << "Deleting all elements from the multiset\n";
  s1.clear();

  // verifica se o multiset está vazio
  if (s1.empty())
  {
    cout << "Multiset is empty!\n";
  }
  else
  {
    print(s1.begin(), s1.end());
    cout << endl;
  }

  // Verifica se o set está vazio (não foi apagado)
  if (s2.empty())
  {
    cout << "Set is empty!\n";
  }
  else
  {
    print(s2.begin(), s2.end());
    cout << endl;
  }

  return 0;
}
