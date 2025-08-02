#include <vector>
#include <iostream>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

// Functor genérico que imprime os elementos com separação por vírgula
template <class T>
struct Out {
    ostream &out;
    Out(ostream &o) : out(o) {}
    void operator()(const T &val) {
        out << val << ", ";
    }
};

// Functor gerador de sequência periódica simulando leitura de dados
struct Sequence {
    int start;
    Sequence(int start) : start(start) {}
    int operator()() {
        return start++ % 7; // simula um sinal cíclico de sensor com ruído modular
    }
};

int main() {
    // Simula coleta de 3 amostras de um sinal periódico ruidoso
    vector<int> v1(3);
    generate(v1.begin(), v1.end(), Sequence(10)); // Preenche com: 10%7, 11%7, 12%7 → 3, 4, 5

    // set ordena automaticamente, aqui é usado para representar um filtro tipo "filtro de medianas"
    set<int> s1(v1.rbegin(), v1.rend()); // Constrói o conjunto com base na ordem reversa de v1

    // deque simula um buffer circular que preserva a ordem de processamento dos dados
    deque<int> d1(s1.rbegin(), s1.rend()); // Constrói deque com ordem reversa do set (que já é ordenado)

    // Invertemos v1 e d1 para simular operações de pré-processamento (por ex. reordenação)
    reverse(v1.begin(), v1.end());        // Reverte a ordem das amostras em v1
    reverse(d1.begin(), d1.end());        // Reverte a ordem das amostras no buffer d1

    // Impressão dos dados processados de cada estrutura
    for_each(s1.begin(), s1.end(), Out<int>(cout)); // set é naturalmente ordenado e sem duplicatas
    cout << endl;

    for_each(v1.begin(), v1.end(), Out<int>(cout)); // mostra a sequência de entrada invertida
    cout << endl;

    for_each(d1.begin(), d1.end(), Out<int>(cout)); // mostra dados reordenados no buffer
    cout << endl;

    return 0;
}
