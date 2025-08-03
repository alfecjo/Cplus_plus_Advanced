#include <deque>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

// Classe que representa uma peça com um identificador
class Pocket
{
    int value;

public:
    Pocket(int value) : value(value) {}

    int getValue() const
    {
        return value;
    }

    // Define como comparar duas peças (por valor numérico)
    bool operator<(const Pocket &other) const
    {
        return value < other.value;
    }
};

// Permite imprimir a peça usando cout
ostream &operator<<(ostream &stream, const Pocket &pocket)
{
    stream << "Peça[" << pocket.getValue() << "]";
    return stream;
}

int main()
{
    // Estoque atual da fábrica (pode conter duplicatas ou estar desordenado)
    Pocket estoque[] = {3, 9, 0, 2, 1, 4, 5};

    // Peças requeridas para montar o "Produto X"
    Pocket produtoX_requisitos[] = {Pocket(3), Pocket(2), Pocket(4), Pocket(1)};

    // Deque e set para representar o estoque
    deque<Pocket> estoqueDeque(estoque, estoque + 7); // estrutura modificável
    set<Pocket> estoqueSet(estoque, estoque + 7);     // estrutura ordenada e única

    // Ordena o deque para usar includes corretamente
    sort(estoqueDeque.begin(), estoqueDeque.end());

    // Também ordena os requisitos (necessário para includes funcionar corretamente)
    sort(produtoX_requisitos, produtoX_requisitos + 4);

    // Verifica se todas as peças do Produto X estão no estoque (versão com deque)
    bool podeMontarComDeque = includes(
        estoqueDeque.begin(), estoqueDeque.end(),
        produtoX_requisitos, produtoX_requisitos + 4);

    // Verifica se todas as peças estão no set (mais eficiente, sem duplicatas)
    bool podeMontarComSet = includes(
        estoqueSet.begin(), estoqueSet.end(),
        produtoX_requisitos, produtoX_requisitos + 4);

    // Saída
    cout << "Pode montar Produto X com Deque? " << (podeMontarComDeque ? "Sim" : "Não") << endl;
    cout << "Pode montar Produto X com Set? " << (podeMontarComSet ? "Sim" : "Não") << endl;

    return 0;
}
