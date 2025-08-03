#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

using namespace std;

// Função geradora de bits aleatórios (0 ou 1)
int generate_bit() {
    return rand() % 2;
}

// Função geradora de padrão alternado (0,1,0,1,...)
class AlternatingBit {
    bool current = false;
public:
    int operator()() {
        current = !current;
        return current;
    }
};

// Função auxiliar para exibir o vetor
template<typename T>
void print_vector(const vector<T>& v, const string& label) {
    cout << label << ": ";
    for (const auto& val : v)
        cout << val << " ";
    cout << endl;
}

int main() {
    srand(time(0)); // Inicializa gerador de números aleatórios

    //  fill: preencher buffer com 0 (simula buffer limpo)
    vector<int> buffer(10);
    fill(buffer.begin(), buffer.end(), 0);
    print_vector(buffer, "Buffer inicializado com zeros");

    // fill_n: preencher os primeiros N elementos com 1 (simulando envio de sinal de sincronismo)
    fill_n(buffer.begin(), 5, 1);
    print_vector(buffer, "Buffer com sincronismo (1s nos primeiros 5 bits)");

    // generate: preencher com bits aleatórios (simula dados binários reais)
    generate(buffer.begin(), buffer.end(), generate_bit);
    print_vector(buffer, "Buffer com bits aleatórios");

    //  generate_n: preencher os N primeiros bits com padrão alternado (0,1,0,1,...)
    AlternatingBit altGen;
    generate_n(buffer.begin(), 8, altGen);
    print_vector(buffer, "Buffer com padrão alternado nos primeiros 8 bits");

    return 0;
}
