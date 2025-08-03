#include <iostream>
#include <vector>
#include <utility>   // std::pair
#include <algorithm> // std::transform, std::replace_if
#include <iterator>  // std::back_inserter

using namespace std;

// Função auxiliar para imprimir pares (representando símbolos QPSK)
void printSymbol(const pair<int, int> &sym)
{
    cout << "(" << sym.first << "," << sym.second << ") ";
}

// Estrutura para mapear 2 bits em símbolo QPSK
struct QPSKMapper
{
    pair<int, int> operator()(const pair<int, int> &bits)
    {
        if (bits == make_pair(0, 0))
            return {1, 1};
        if (bits == make_pair(0, 1))
            return {-1, 1};
        if (bits == make_pair(1, 1))
            return {-1, -1};
        if (bits == make_pair(1, 0))
            return {1, -1};
        return {0, 0}; // fallback
    }
};

// Predicado para identificar símbolo nulo (0,0)
struct IsNullSymbol
{
    bool operator()(const pair<int, int> &sym)
    {
        return sym == make_pair(0, 0);
    }
};

int main()
{
    vector<int> bits = {0, 1, 1, 0, 0, 0, 1, 1}; // 8 bits => 4 símbolos

    // agrupando em pares de bits
    vector<pair<int, int>> bit_pairs;
    for (size_t i = 0; i < bits.size(); i += 2)
    {
        bit_pairs.emplace_back(bits[i], bits[i + 1]);
    }

    // mapeando os pares para símbolos QPSK
    vector<pair<int, int>> qpsk_symbols;
    transform(bit_pairs.begin(), bit_pairs.end(),
              back_inserter(qpsk_symbols), QPSKMapper());

    cout << "Símbolos QPSK mapeados:\n";
    for_each(qpsk_symbols.begin(), qpsk_symbols.end(), printSymbol);
    cout << endl
         << endl;

    // substituindo símbolos inválidos (0,0) por símbolo de erro (-9,-9)
    replace_if(qpsk_symbols.begin(), qpsk_symbols.end(),
               IsNullSymbol(), make_pair(-9, -9));

    cout << "Após replace_if (substituindo símbolos nulos):\n";
    for_each(qpsk_symbols.begin(), qpsk_symbols.end(), printSymbol);
    cout << endl;

    return 0;
}
