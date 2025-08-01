#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Vetor tipo double
    vector<double> valores = 
        { 2.1, 3.14, 2.2, 1.1, 2.11, 3.2, 3.6, 2.5, 2.6, 4.11, 4.12, 3.11, 3.73, 4.83 };
    
    double valor_inicial, valor_final;

    // intervalo a ser considerado
    cout << "Digite o valor inicial do intervalo: ";
    cin >> valor_inicial;

    cout << "Digite o valor final do intervalo: ";
    cin >> valor_final;

    // quantos elementos estão dentro do intervalo [valor_inicial, valor_final]
    int quantidade = count_if(valores.begin(), valores.end(), 
                              [&](double x) {
                                  return x >= valor_inicial && x <= valor_final;
                              });

    cout << quantidade << " elemento(s) estao dentro do intervalo fornecido." << endl;

    return 0;
}
