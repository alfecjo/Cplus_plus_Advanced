#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

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

struct Sequence
{
  int start;
  Sequence(int start) : start(start) {}

  int operator()()
  {
    return 3 * (start++ % 2); // Gera alternadamente 0 e 3 (porque start % 2 alterna 0 e 1)
  }
};

int main()
{
  vector<int> v1(7);

  generate(v1.begin(), v1.end(), Sequence(10)); // Preenche v1 com valores 0, 3, 0, 3, ...

  // unique retorna o novo fim lógico do vetor após remover elementos consecutivos repetidos
  auto new_end = unique(v1.begin(), v1.end());

  // Apaga efetivamente os elementos repetidos movidos para o fim
  v1.erase(new_end, v1.end());

  // Imprime os elementos únicos restantes
  for_each(v1.begin(), v1.end(), Out<int>(cout));

  return 0;
}
