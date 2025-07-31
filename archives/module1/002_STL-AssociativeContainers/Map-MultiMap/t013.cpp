#include <map>
#include <iostream>
#include <functional>

using namespace std;

// função genérica para imprimir os pares (chave:valor) de um map
template <class T>
void print(T start, T end) {
  while (start != end) {
    std::cout << start->first << ":" << start->second << " ";
    start++;
  }
}

// Função genérica para preencher um map com valores a partir de um vetor
template <class T, class U>
void fillMap(map<T, T>& m, U start, U end) {
  for (; start != end; ++start) {
    m.insert(pair<T, T>(*start, *start)); // insere o par {chave, valor} onde chave = valor = *start
  }
}

int main() {
  int t[] = { 1, 10, 8, 4, 5, 6, 3, 9, 7, 2 };
  map<int, int> m1;

  fillMap(m1, t, t + 10); // preenche o map com os valores do vetor

  cout << "Tamanho do map após preenchimento: " << m1.size() << endl;
  print(m1.begin(), m1.end()); // imprime o conteúdo do map
  cout << endl << endl;

  cout << "Usando o operador [] para modificar o valor de uma chave existente:\n";
  m1[1] = 101; // altera o valor da chave 1 (kkk não de key-first). De 1 para 101 (de second)
  print(m1.begin(), m1.end());
  cout << endl << endl;

  cout << "Usando o operador [] para adicionar um novo elemento ao map:\n";
  m1[11] = 11; // insere novo par {11, 11}
  print(m1.begin(), m1.end());
  cout << endl << endl;

  cout << "Erro comum ao usar operator[] - acessar uma chave inexistente:\n";
  cout << "Tamanho antes de acessar chave inexistente 0: " << m1.size() << endl;

  // Mesmo sem existir a chave 0, essa linha cria um novo par {0, 0}
  if (m1[0] == 100) {
    cout << "Existe a chave 0 no map!\n";
  } else {
    cout << "A chave 0 não existia, mas foi criada com valor padrão (0)!\n";
  }

  cout << "Tamanho após acessar chave inexistente 0: " << m1.size() << endl;
  print(m1.begin(), m1.end());
  cout << endl << endl;

  cout << "Uso apropriado para verificar se uma chave existe no map:\n";
  cout << "Tamanho antes de acessar a chave inexistente 13: " << m1.size() << endl;

  // Aqui evitamos criar a chave usando find()
  if (m1.find(13) != m1.end()) {
    cout << "Existe a chave 13 no map!\n";
  } else {
    cout << "Não existe a chave 13 no map!\n";
  }

  cout << "Tamanho após tentativa de acesso à chave 13: " << m1.size() << endl;
  print(m1.begin(), m1.end());
  cout << endl << endl;

  return 0;
}
