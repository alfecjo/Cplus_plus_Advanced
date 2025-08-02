#include <vector>        
#include <iostream>      
#include <functional>    // Contém utilitários como std::less (não usado neste exemplo)
#include <algorithm>     // Para funções como generate, for_each, random_shuffle

using namespace std;

// Functor que imprime os elementos do vetor
template <class T>
struct Out {
    ostream &out;

    Out(ostream &o) : out(o) {}  // construtor que recebe uma referência a um stream de saída

    void operator()(const T &val) {
        out << val << ", ";      // Imprime o valor seguido de vírgula e espaço
    }
};

// Functor gerador de sequência
struct Sequence {
    int start;

    Sequence(int start) : start(start) {}

    int operator()() {
        return start++ % 7;  // gera valores cíclicos entre 0 e 6
                             // Exemplo: se start = 10 → 10%7=3, depois 4, 5, 6, 0, 1, ...
    }
};

int main() {
    vector<int> v1(4);  

    // preenche o vetor em ordem reversa com valores da sequência
    // v1.rbegin() aponta para o último elemento, v1.rend() aponta antes do primeiro
    // Isso inverte a ordem em que os valores são preenchidos
    generate(v1.rbegin(), v1.rend(), Sequence(10));
    // Sequence gera: 10%7=3, 11%7=4, 12%7=5, 13%7=6
    // mas como é preenchido de trás para frente, v1 = [6, 5, 4, 3]

    // Tentativa de embaralhar os elementos, mas com erro
    random_shuffle(v1.begin(), v1.end());
    // Isso **não faz nada**. O intervalo [begin, begin) é vazio, logo nenhuma troca acontece.
    // Para embaralhar corretamente: use `random_shuffle(v1.begin(), v1.end());`
    // Obs: `random_shuffle` está **obsoleto em C++14** e **removido em C++17+**.
    // Em versões modernas, substitua por: `std::shuffle(...)` com um gerador aleatório.
    // warning: ‘void std::random_shuffle(_RAIter, _RAIter) [...]’ is deprecated: use 'std::shuffle' instead [-Wdeprecated-declarations]
    // Em C++17, o correto é usar `random_shuffle(v1.begin(), v1.end());`

    for_each(v1.begin(), v1.end(), Out<int>(cout));

    return 0;
}
