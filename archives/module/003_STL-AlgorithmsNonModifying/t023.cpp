#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <list>
#include <cctype> // para tolower

using namespace std;

// Função genérica para imprimir elementos
template <class T>
void print(const T& value) {
    cout << value << " ";
}

// Comparador para comparação case-insensitive (útil em sinais codificados por letras, por exemplo)
struct CompareCaseInsensitive {
    bool operator()(const char& a, const char& b) {
        return tolower(a) == tolower(b);
    }
};

int main() {
    // Simulando uma sequência de amostras inteiras (poderiam representar amostras de um sensor)
    int signal_samples[] = { 1, 2, 3, 4, 1, 1, 1, 2, 3, 3, 5, 6, 7, 7, 7, 2, 3, 4 };
    vector<int> signal(signal_samples, signal_samples + 18);

    cout << "Sequência de amostras:\n";
    for_each(signal.begin(), signal.end(), print<int>);
    cout << "\n\n";

    // Verificando se há uma sequência de 3 repetições de 7 (pico constante)
    cout << "🔍 Procurando padrão de 3 amostras consecutivas com valor 7:\n";
    auto it = search_n(signal.begin(), signal.end(), 3, 7);
    if (it != signal.end()) {
        cout << "Padrão 7 7 7 encontrado na posição: "
             << distance(signal.begin(), it) << "\n";
    } else {
        cout << "Padrão 7 7 7 não encontrado\n";
    }
    cout << "\n";

    // Procurando padrão 2 2 (ruído ou interferência duplicada)
    cout << "🔍 Procurando padrão de 2 amostras consecutivas com valor 2:\n";
    it = search_n(signal.begin(), signal.end(), 2, 2);
    if (it != signal.end()) {
        cout << "Padrão 2 2 encontrado na posição: "
             << distance(signal.begin(), it) << "\n";
    } else {
        cout << "Padrão 2 2 não encontrado\n";
    }
    cout << "\n";

    // Agora uma sequência de caracteres simulando um canal com símbolos (A, B, C...)
    char symbol_stream[] = { 'a', 'b', 'a', 'A', 'A', 'b', 'D', 'A', 'b', 'C', 'a', 'f' };
    list<char> signal_letters(symbol_stream, symbol_stream + 12);

    cout << "🔍 Procurando símbolo 'A' duas vezes seguidas (sensível a maiúsculas):\n";
    auto lit = search_n(signal_letters.begin(), signal_letters.end(), 2, 'A');
    if (lit != signal_letters.end()) {
        cout << "Padrão 'A A' encontrado na posição: "
             << distance(signal_letters.begin(), lit) << "\n";
    } else {
        cout << "Padrão 'A A' não encontrado\n";
    }
    cout << "\n";

    cout << "🔍 Procurando símbolo 'A' duas vezes seguidas (ignorando maiúsculas/minúsculas):\n";
    lit = search_n(signal_letters.begin(), signal_letters.end(), 2, 'A', CompareCaseInsensitive());
    if (lit != signal_letters.end()) {
        cout << "Padrão 'A A' (case-insensitive) encontrado na posição: "
             << distance(signal_letters.begin(), lit) << "\n";
    } else {
        cout << "Padrão 'A A' (case-insensitive) não encontrado\n";
    }

    return 0;
}
