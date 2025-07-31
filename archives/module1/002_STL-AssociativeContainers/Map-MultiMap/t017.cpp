#include <map>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

template <class T>
void print(T start, T end) {
  while (start != end) {
    cout << start->first << ":" << start->second << " ";
    start++;
  }
  cout << endl;
}

// Preenche o multimap com pares {valor, valor}
template <class T, class U>
void fillMap(multimap<T, T>& m, U start, U end) {
  for (; start != end; ++start) {
    m.insert(pair<T, T>(*start, *start)); // multimap permite chaves duplicadas
  }
}

int main() {
  string t1[] = { "aaa", "bbb", "ccc", "aaa" };
  string t2[] = { "xxx", "yyy", "zzz", "yyy" };

  // Criação dos multimaps
  multimap<string, string> m1;
  multimap<string, string> m2;

  fillMap(m1, t1, t1 + 4);
  fillMap(m2, t2, t2 + 4);

  cout << "Conteúdo inicial:\n";
  cout << "m1: ";
  print(m1.begin(), m1.end());
  cout << "m2: ";
  print(m2.begin(), m2.end());

  // Troca os multimaps
  cout << "\nSwap m1 <-> m2:\n";
  m1.swap(m2);

  cout << "Após troca:\n";
  cout << "m1: ";
  print(m1.begin(), m1.end());
  cout << "m2: ";
  print(m2.begin(), m2.end());

  // Segunda troca (volta ao estado original)
  cout << "\nSwap m2 <-> m1:\n";
  m2.swap(m1);

  cout << "Após segunda troca:\n";
  cout << "m1: ";
  print(m1.begin(), m1.end());
  cout << "m2: ";
  print(m2.begin(), m2.end());

  // Demonstrando acesso a todas as entradas com chave duplicada
  cout << "\nValores com a chave 'aaa' no m1:\n";
  auto range = m1.equal_range("aaa");
  for (auto it = range.first; it != range.second; ++it) {
    cout << it->first << " -> " << it->second << endl;
  }

  return 0;
}
