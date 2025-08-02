#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Função que imprime um valor seguido de vírgula e espaço
void print(int v)
{
  cout << v << ", ";
}

// Functor que gera uma sequência crescente, começando em 'start'
struct Sequence
{
  int start;

  // Construtor que inicializa o valor inicial da sequência
  Sequence(int start) : start(start) {}

  // Operador função que retorna o valor atual e incrementa para o próximo
  int operator()()
  {
    return start++;  // Retorna o valor e depois incrementa (pós-incremento)
  }
};

// Predicado que retorna true se o valor for par (divisível por 2)
bool predicate(int v)
{
  return v % 2 == 0;
}

int main()
{
  // Cria um vetor de inteiros com 7 posições (inicialmente com valores indefinidos)
  vector<int> v1(7);

  // Preenche as 7 posições do vetor v1 usando o functor Sequence
  // A cada chamada, Sequence retorna um número crescente (1, 2, 3, ..., 7)
  generate_n(v1.begin(), 7, Sequence(1));    // LINE I

  // Remove todos os elementos pares do vetor v1
  // Na prática, o remove_if reorganiza os elementos, colocando os que NÃO satisfazem o predicado
  // no início do vetor e retorna um iterador para a nova "fronteira" do vetor
  auto new_end = remove_if(v1.begin(), v1.end(), predicate);    // LINE II

  // Imprime os elementos válidos do vetor, do início até a nova fronteira (new_end)
  // Os elementos após new_end não são removidos fisicamente, mas devem ser ignorados
  for_each(v1.begin(), new_end, print);

  cout << endl;

  return 0;
}
