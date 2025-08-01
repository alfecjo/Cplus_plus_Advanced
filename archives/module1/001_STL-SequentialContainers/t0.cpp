#include <cstdint>
#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <algorithm>

/*
    Containers sequenciais (vector, deque, list) são fundamentais para armazenar dados em ordem.

     vector:
        - Armazenamento contíguo na memória (como array).
        - Acesso aleatório rápido.
        - Inserção/remoção rápida apenas no final.
        - Usado quando o tamanho pode crescer, mas o acesso por índice é importante.

     deque (double-ended queue):
        - Armazenamento não contíguo, mas com acesso aleatório.
        - Inserção/remoção eficiente nas duas extremidades.
        - Útil em buffers circulares ou filas de leitura UART em embarcados.

     list (doubly linked list):
        - Sem acesso aleatório — apenas iteração linear.
        - Inserção/remoção muito rápida em qualquer posição.
        - Útil quando há muitas alterações no meio da sequência.

     Em sistemas embarcados, esses containers aparecem juntos em cenários como:
        - Leitura contínua de dados (deque),
        - Pré-processamento (vector),
        - Rearranjo/filtragem (list),
        - E até ordenação com algoritmos da STL.
*/

int main() {
    // Simula um buffer de entrada UART
    std::deque<uint8_t> uartBuffer = { 0x02, 0x45, 0x23, 0x99, 0x10 };

    // Transferência dos dados do buffer para um vector para processamento rápido
    std::vector<uint8_t> dataVector(uartBuffer.begin(), uartBuffer.end());

    // Filtrar dados maiores que 0x20 para uma list para posterior análise
    std::list<uint8_t> filteredData;
    std::copy_if(dataVector.begin(), dataVector.end(), std::back_inserter(filteredData),
                 [](uint8_t val) { return val > 0x20; });

    // Saída para depuração
    std::cout << "Dados filtrados (> 0x20): ";
    for (auto val : filteredData) {
        std::cout << std::hex << static_cast<int>(val) << " ";
    }
    std::cout << std::endl;

    return 0;
}
