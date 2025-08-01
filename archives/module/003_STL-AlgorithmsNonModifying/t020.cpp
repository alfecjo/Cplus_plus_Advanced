#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * ▌ Moving Average (Média Móvel):
 * Uma técnica comum para suavizar dados ruidosos. Seria aplicada fazendo a média
 * de uma janela de N amostras consecutivas. Ex: (x[i-1] + x[i] + x[i+1]) / 3
 *
 * ▌ Filtro de Kalman:
 * Muito usado em engenharia e sistemas embarcados (por exemplo, em sensores de movimento),
 * esse filtro estima o verdadeiro valor de uma variável, mesmo com medições imprecisas.
 * Baseia-se em modelos estatísticos de previsão e correção iterativa.
 *
 * ▌ Filtro Passa-Baixa:
 * Deixa passar frequências **baixas** e atenua as altas (ex: ruído).
 * Aplicável quando se quer manter o "comportamento geral" e descartar variações bruscas.
 *
 * ▌ Filtro Passa-Alta:
 * Faz o oposto: atenua sinais estáveis e destaca variações rápidas.
 * Pode ser usado para detectar mudanças bruscas.
 *
 * ▌ Detecção de valores fora do intervalo:
 * A "distância" que calculamos (|original - ruidoso|) pode ser usada
 * para identificar **outliers** — valores muito distantes, que podem indicar falhas ou ruído forte.
 */


int main()
{
    vector<int> original_values =
        {210, 314, 202, 110, 211, 302, 358, 229, 260, 411, 412, 311, 373, 483};
    vector<int> noisy_values =
        {211, 324, 203, 113, 227, 320, 340, 210, 239, 411, 412, 333, 371, 501};

    /** 
     * Aqui fazemos a comparação entre os valores originais e os ruidosos,
     * calculando a distância absoluta entre eles.
     * Essa diferença pode ser vista como o "erro" de medição.
     */
    
    cout << fixed << setprecision(1);
    cout << "Index | Original | Noisy | Distance\n";
    cout << "-------------------------------\n";

    for (size_t i = 0; i < original_values.size(); ++i) {
        int diff = abs(original_values[i] - noisy_values[i]);
        cout << setw(5) << i 
             << " | " << setw(8) << original_values[i]
             << " | " << setw(5) << noisy_values[i]
             << " | " << setw(8) << diff << '\n';
    }

    return 0;
}

// isso sim é engenharia de software! kkk
