#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Template para impressão de elementos no ostream
template <class T>
struct Out
{
  ostream &out;

  Out(ostream &o) : out(o) {}

  void operator()(const T &val)
  {
    out << val << ", ";
  }
};

// Functor que gera uma sequência com valores baseados em 3 * (start++ % 2)
struct Sequence
{
  int start;

  Sequence(int start) : start(start) {}

  int operator()()
  {
    return 3 * (start++ % 2);    // LINE I: gera alternadamente 0 e 3 (porque start++ % 2 alterna 0 e 1)
  }
};

int main()
{
  vector<int> v1(7);

  generate(v1.begin(), v1.end(), Sequence(10));    // LINE II: gera a sequência usando Sequence(10)

  unique(v1.begin(), v1.end()); // Remove elementos repetidos consecutivos (mas não altera o tamanho do vetor!)

  for_each(v1.begin(), v1.end(), Out<int>(cout)); // Imprime os elementos

  return 0;
}
