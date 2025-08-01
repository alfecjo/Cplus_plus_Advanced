#include <iostream>
#include <vector>

using namespace std;

/**
 * 
 * Imagine que temos uma série temporal de amostras (como ruído, pulsos ou níveis de sinal) 
 * e queremos detectar ocorrências repetidas de certos valores discretos — como se estivéssemos
 * detectando eventos específicos no sinal digital (por exemplo, picos de interferência, 
 * níveis de tensão repetidos, etc).
 * 
 * Essa função é útil em sistemas de monitoramento, onde queremos identificar padrões
 * ou anomalias em um fluxo de dados contínuo, como em sistemas de telecomunicações, 
 * sensores industriais, ou até mesmo em análise de sinais digitais.
 * 
 * @brief Detecta e imprime a ocorrência de eventos discretos repetidos
 * em uma série de amostras. Cada evento pode representar um nível de sinal,
 * uma interferência, ou até mesmo um padrão específico em um sistema de medição.
 * 
 * @param samples Vetor com a série de amostras coletadas do sinal.
 * @param event_value Valor discreto representando o evento de interesse (ex: pulso lógico 11 ou 21).
 */

void detect_signal_events(const vector<int>& samples, int event_value)
{
    int occurrence = 0;

    for (int i = 0; i < samples.size(); ++i)
    {
        if (samples[i] == event_value)
        {
            occurrence++;
            // Simula a detecção de um evento no tempo i, como se fosse um instante em milissegundos
            cout << "Evento (" << event_value << ") detectado pela " 
                 << occurrence << "ª vez na amostra " << i << endl;
        }
    }
}

int main()
{
    // Simulação de um sinal digital com ruído e eventos repetidos
    vector<int> signal_samples = {
        11, 11, 21, 21, 30, 11, 11, 11, 17, 21, 21, 21, 11, 11, 11, 11
    };

    // detecção de eventos do tipo 11 (ex: interferência tipo A)
    detect_signal_events(signal_samples, 11);

    // Detecção de eventos do tipo 21 (ex: interferência tipo B)
    detect_signal_events(signal_samples, 21);

    cout << "Análise completa dos eventos no sinal digital - and so on...\n";

    return 0;
}
