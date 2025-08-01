#include <set>
#include <iostream>
#include <functional>

using namespace std;

// função para imprimir os elementos entre dois iteradores
template <class T> 
void print(T start, T end)
{
  for (; start != end; ++start)
  {
    std::cout << *start << " ";
  }
}

// tipo auxiliar: o retorno de set.insert é um par (iterator, bool)
typedef pair<set<int>::iterator, bool> Pair;

// Função que verifica se a inserção teve sucesso
void check(const Pair &result)
{
  if (result.second == true)
  {
    cout << "A new value (" << *result.first << ") has been inserted" << endl;
  }
  else
  {
    cout << "Insertion failed, value " << *result.first << " already exists\n";
  }
}

int main()
{
  // Vetor inicial com alguns inteiros
  int t[] = {16, 10, 8, 40, 6, 15, 3, 9, 7, 2};

  // Cria um set com os elementos do vetor (valores duplicados são ignorados)
  set<int> s1(t, t + 10);

  cout << "The first version of insert:\n";
  print(s1.begin(), s1.end());  // Exibe os elementos do set
  cout << endl;

  // Primeira forma de inserção: insert(valor) — retorna um par
  Pair p = s1.insert(10);  // 10 já existe
  check(p);
  print(s1.begin(), s1.end());
  cout << endl;

  p = s1.insert(13);  // valor novo
  check(p);
  print(s1.begin(), s1.end());
  cout << endl << endl;

  cout << "The second version of insert:\n";
  // Segunda forma: insert(posição sugerida, valor)
  set<int>::iterator it1 = s1.insert(s1.find(10), 11); // 11 é novo, inserido após 10
  set<int>::iterator it2 = s1.insert(s1.find(11), 11); // valor repetido

  if (it1 == it2)
  {
    cout << "Second insertion was not successful\n";
  }

  print(s1.begin(), s1.end());
  cout << endl << endl;

  cout << "The third version of insert:\n";
  // Terceira forma: insert(intervalo)
  int t2[] = {4, 10, 15, 21, 0, 4}; 
  s1.insert(t2, t2 + 6); // Apenas valores não repetidos são inseridos
  print(s1.begin(), s1.end());
  cout << endl;

  return 0;
}
