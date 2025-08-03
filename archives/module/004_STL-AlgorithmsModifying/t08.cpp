#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Simular, de forma simplificada, o que acontece em um canal de comunicação com codificação de canal,
ou seja, adicionar redundância aos dados antes da transmissão para proteger contra ruídos e interferências.
Em redes móveis (como 4G/5G), isso acontece o tempo todo.

[Bits de Entrada] → [Codificação por Redundância] → [Canal com Ruído] → [Decodificação com Correção de Erros]

bits podem representar:
 - Dados de voz digitalizada (voz codificada)
 - Dados de vídeo
 - Pacotes IP
 - Qualquer informação transmitida

*/

// codifica cada bit com repetição 3x
// Conceito Real: Isso é uma forma simples de Forward Error Correction (FEC).
// Em sistemas reais, usa-se Turbo Codes, LDPC, mas a ideia de adicionar redundância é a mesma!
vector<int> encode(const vector<int> &bits)
{
    vector<int> encoded;
    for (int bit : bits)
    {
        encoded.push_back(bit);
        encoded.push_back(bit);
        encoded.push_back(bit);
    }
    return encoded;
}

// Simula ruído no canal (altera bits com probabilidade p_error)
vector<int> transmit(const vector<int> &encoded, double p_error)
{
    vector<int> noisy = encoded;
    for (int &bit : noisy)
    {
        if ((rand() % 100) < (p_error * 100))
        {
            bit = 1 - bit; // inverte bit
        }
    }
    return noisy;
}

// decodifica usando decisão por maioria (3 bits)
vector<int> decode(const vector<int> &noisy)
{
    vector<int> decoded;
    for (size_t i = 0; i < noisy.size(); i += 3)
    {
        int sum = noisy[i] + noisy[i + 1] + noisy[i + 2];
        // pensa no que dá para fazer com ternário...
        decoded.push_back(sum >= 2 ? 1 : 0);
    }
    return decoded;
}

// exibe vetor de bits
void printBits(const string &label, const vector<int> &bits)
{
    cout << label << ": ";
    for (int b : bits)
        cout << b;
    cout << endl;
}

int main()
{
    srand(time(0));

    // Exemplo de bits de voz codificada
    vector<int> original_bits = {1, 0, 1, 1, 0, 0, 1, 0}; // exemplo simples

    /* Etapas do sistema
        Cada bit tem 20% de chance de ser invertido — 
        simulando interferência, desvanecimento, ou ruído térmico.

        Paralelo Teórico: Em sistemas reais, isso é feito com técnicas de modulação robustas,
        como QPSK, OFDM, etc., que mitigam erros de transmissão.
        
        Paralelo Real: Na vida real, isso representa perdas por:
        Interferência eletromagnética
        Desvanecimento (fading) em canais móveis
        Ruído de quantização (ADC)
        Ruído de fundo (thermal noise)
        Ruído de fase (jitter)
        Ruído de impulso (spikes)
        Ruído de intermodulação (cross-talk)
        Ruído de banda lateral (sideband noise)
        Ruído de banda larga (broadband noise)
        Ruído de banda estreita (narrowband noise)
        Ruído de banda passante (bandpass noise)
        Ruído de banda rejeitada (bandstop noise)
        .
        .
        .
        Colisões (no ar, com outros sinais)
        and so on...


    */

    vector<int> encoded = encode(original_bits);
    vector<int> noisy = transmit(encoded, 0.2); // 20% de erro
    vector<int> decoded = decode(noisy);

    // Resultados
    printBits("Original   ", original_bits);
    printBits("Codificado ", encoded);
    printBits("Com ruído  ", noisy);
    printBits("Decodificado", decoded);

    // Verifica quantos bits foram recuperados corretamente
    int erros = 0;
    for (size_t i = 0; i < original_bits.size(); ++i)
    {
        if (original_bits[i] != decoded[i])
            ++erros;
    }
    cout << "\nErros após decodificação: " << erros << " de " << original_bits.size() << " bits." << endl;

    return 0;
}
