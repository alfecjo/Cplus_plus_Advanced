#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Classe que representa um pacote com prioridade
class DataPacket
{
    int priority;

public:
    DataPacket(int p) : priority(p) {}

    int getPriority() const { return priority; }

    // Sobrecarga para permitir ordenação
    bool operator<(const DataPacket &other) const
    {
        return priority < other.priority;
    }
};

// Sobrecarga do operador << para imprimir DataPacket
ostream &operator<<(ostream &stream, const DataPacket &packet)
{
    stream << "P" << packet.getPriority();
    return stream;
}

// Função para imprimir usando for_each
void printPacket(DataPacket p)
{
    cout << p << " ";
}

int main()
{
    // Simulação de chegada de pacotes (fase 1 e fase 2)
    DataPacket incomingPackets[] = {DataPacket(5), DataPacket(2), DataPacket(9), DataPacket(1), DataPacket(4), DataPacket(3)};

    // Pré-processamento: ordenar fase 1 e fase 2 separadamente
    vector<DataPacket> queue(incomingPackets, incomingPackets + 6);

    // Suponha que os 3 primeiros são da fase 1, e os 3 últimos da fase 2
    sort(queue.begin(), queue.begin() + 3); // fase 1
    sort(queue.begin() + 3, queue.end());   // fase 2

    // Unir as duas fases em ordem de prioridade
    inplace_merge(queue.begin(), queue.begin() + 3, queue.end());

    // Mostrar fila final de pacotes para processamento
    cout << "Fila final dos pacotes ordenados por prioridade: ";
    for_each(queue.begin(), queue.end(), printPacket);
    cout << endl;

    return 0;
}
