#include <iostream>
#include <vector>
#include <algorithm> // std::transform, std::copy, etc.
#include <numeric>   // std::accumulate
#include <random>    // geração de dados simulados
#include <iomanip>   // std::setprecision

using namespace std;

/*
    processamento de sinais com Algorithms Modifying


    aqui simulo um sinal ruidoso (como de um sensor físico),
    e aplicamos um filtro passa-baixa simples — a média móvel.

    Objetivo:
    Mostrar o uso de algoritmos como:
    - std::generate: para gerar o sinal original com ruído.
    - std::transform: para aplicar o filtro.
    - std::copy: para copiar os dados.
    - std::fill: para preencher zonas com zeros.
*/

const int TAMANHO_SINAL = 20;
const int JANELA_MOVEL = 5;

// Gerador de sinal com ruído
double gerarSinal() {
    static default_random_engine engine;
    static normal_distribution<double> dist(10.0, 2.0); // média 10, desvio padrão 2
    return dist(engine);
}

// Função para aplicar média móvel (filtro passa-baixa)
vector<double> aplicarMediaMovel(const vector<double>& sinal, int janela) {
    vector<double> resultado(sinal.size(), 0.0);

    // percorre o vetor e aplica média dos N últimos valores
    transform(sinal.begin(), sinal.end(), resultado.begin(), 
        [&sinal, janela](double, size_t i = 0) mutable {
            int inicio = max(0, static_cast<int>(i) - janela + 1);
            double soma = accumulate(sinal.begin() + inicio, sinal.begin() + i + 1, 0.0);
            i++;
            return soma / min(janela, static_cast<int>(i));
        });

    return resultado;
}

int main() {
    vector<double> sinal(TAMANHO_SINAL);

    // para gerar valores simulados com ruído
    generate(sinal.begin(), sinal.end(), gerarSinal);

    // Aplicar média móvel (filtro passa-baixa)
    vector<double> sinalFiltrado = aplicarMediaMovel(sinal, JANELA_MOVEL);

    // Mostrar sinal original e filtrado
    cout << fixed << setprecision(2);
    cout << "Sinal original : ";
    for (auto v : sinal) cout << v << "  ";
    cout << "\n";

    cout << "Sinal filtrado : ";
    for (auto v : sinalFiltrado) cout << v << "  ";
    cout << "\n";

    return 0;
}
