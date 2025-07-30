#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main ()
{
  int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };

  // inicializa um vector com os valores do array
  vector<int> v(mynumbers, mynumbers+7);

  // Cria um set com os elementos do vector (remove duplicatas e ordena)
  set<int> s (v.begin(), v.end());

  // Tenta inserir os mesmos elementos do vector no set (sem efeito, pois set não permite duplicatas)
  s.insert (v.begin(), v.end());

  // Adiciona 5 no final do vector (não afeta o set automaticamente),
  // pois é uma estrutura de dados separada.
  // Isso é apenas para mostrar que o vector pode ser modificado independentemente do set
  // só pra firmar: não existe vínculo ou sincronização automática entre containers.
  v.push_back(5);

  // Insere o valor 8 no set
  s.insert(8);

  // equal_range retorna um par de iteradores: [first, second)
  // que correspondem ao intervalo dos elementos equivalentes a 5 no set
  pair<set<int>::iterator, set<int>::iterator> range;
  range = s.equal_range(5);

  // Imprime o valor apontado pelo primeiro iterador e o valor do segundo iterador
  // Note que o segundo iterador aponta para o elemento logo após o intervalo
  cout << *range.first << ", " << *range.second << endl;

  return 0;
}
