#include <iostream>
#include <vector>
#include <cmath> // para std::abs

using namespace std;

int main() {
    /**
     * Valores originais sem ruído.
     * Representam a saída ideal de um sistema (ex: temperatura ideal, posição exata, etc).
     */
    vector<double> original_values = {2.0, 3.0, 2.2, 1.0, 2.1, 3.1, 3.5, 2.4, 2.5, 4.0, 4.1, 3.0, 3.7, 4.8};

    /**
     * Valores com ruído (medidos na prática).
     * Normalmente obtidos por sensores que estão sujeitos a interferências.
     * O ruído pode ser aleatório (ruído branco) ou sistêmico (desvio constante).
     */
    vector<double> noisy_values   = {2.24, 3.14, 2.2, 1.1, 2.11, 3.2, 3.6, 2.5, 2.6, 4.11, 4.12, 3.11, 3.73, 4.83};

    /**
     * Threshold = limiar de erro aceitável.
     * Se a diferença entre o valor medido e o ideal for maior que esse limite, consideramos como "erro excessivo".
     */
    double threshold = 0.2;

    /**
     * Variável para contar quantos valores medidos estão "fora do limite aceitável".
     */
    int count = 0;

    /**
     * Percorre os valores comparando a diferença entre o valor real e o ruidoso.
     * std::abs calcula o valor absoluto da diferença.
     */
    for (size_t i = 0; i < original_values.size(); ++i) {
        if (abs(original_values[i] - noisy_values[i]) > threshold) {
            count++;
        }
    }

    /**
     * Saída: quantos valores estão fora do padrão esperado (considerando o threshold).
     */
    cout << count << " valores estão fora do limite aceitável de ruído." << endl;

    return 0;
}
