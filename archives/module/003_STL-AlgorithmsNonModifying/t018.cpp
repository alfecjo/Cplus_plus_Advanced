#include <iostream>
#include <vector>
#include <cmath>    // para std::abs

using namespace std;

// app inserido no contexto relacionado a análise de sinais com ruído (elétrica/telecomunicações, etc...)

/*
    Um sensor de temperatura, pressão, velocidade, etc., está enviando valores medidos 
    (que são os noisy_values) e você os compara com os valores esperados ou teóricos 
    (os original_values). O ruído pode vir de interferência eletromagnética, falhas nos
    componentes, distorção, etc.
    A ideia é detectar quando o erro entre o valor real e o valor medido ultrapassa um limite
    aceitável, que chamamos de limiar (threshold).

    Você tem um sistema que deve seguir uma trajetória, mas está desviando por algum motivo 
    (mecânico, eletrônico ou software). Comparar os valores ideais (original) com os obtidos
    (noisy) ajuda a entender até que ponto o sistema está estável ou desajustado.

    Sensores embarcados em robôs ou drones coletam dados em tempo real. Esses dados são afetados 
    por ruídos. Um algoritmo pode filtrar ou rejeitar dados com erro excessivo comparando com 
    valores esperados.

    nesse código:
    - Os valores originais são os dados ideais (sem ruído, teóricos).
    - Os valores com ruído são os dados reais medidos por algum sistema.
    - O programa busca detectar quando a diferença entre eles ultrapassa
      um limiar definido, o que pode indicar falhas, anomalias, ou necessidade
      de correção.
*/
int main() {
    vector<int> original_values =
        { 210, 314, 202, 110, 211, 302, 358, 229, 260, 411, 412, 311, 373, 483 };
    vector<int> noisy_values =
        { 211, 324, 203, 113, 227, 320, 340, 210, 239, 411, 412, 333, 371, 501 };

    // Verifica para thresholds de 15 a 21
    for (int threshold = 15; threshold <= 21; ++threshold) {
        for (size_t i = 0; i < original_values.size(); ++i) {
            int original = original_values[i];
            int noisy = noisy_values[i];
            if (abs(original - noisy) > threshold) {
                cout << "First difference greater than " << threshold
                     << " is found: " << original << " - " << noisy << endl;
                break;  // passa para o próximo threshold após encontrar a primeira diferença
            }
        }
    }

    return 0;
}
