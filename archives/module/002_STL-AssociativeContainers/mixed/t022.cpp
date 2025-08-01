#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
  string words[]   = { "three", "nine", "zero", "two", "one", "four", "five" };

  // um multimap, que pode conter chaves duplicadas
  multimap<int, string> m;

  // inserção dos pares chave-valor no multimap
  for (int i = 0; i < 7; i++) {
    m.insert(pair<int, string>(mynumbers[i], words[i]));
  }

  // busca a chave 0 no multimap e verifica se o valor associado é "zero"
  // Nota: multimap::find retorna o primeiro elemento com a chave especificada
  if (m.find(0)->second == "zero")  
    cout << "found expected -> ";      // imprime se encontrou "zero" (chave e valor associado!)

    // aqui atenção, mais, fica claro que se houver mais de um par com a chave 0,
    // essa verificação só testa o primeiro encontrado.

  // imprime todos os valores associados (em ordem de chave crescente)
  for (multimap<int, string>::iterator i = m.begin(); i != m.end(); ++i)
    cout << i->second << ", ";

  // Imprime o tamanho total do multimap (número total de elementos)
  cout << m.size();

  return 0;
}
