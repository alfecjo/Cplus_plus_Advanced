#include <iostream>
#include <deque>
#include <algorithm>  // std::find
#include <iterator>   // std::distance

using namespace std;

int main() {
    int t[] = {10, 2, 4, 3, 5, 6, 10, 8, 9, 10};

    // Cria um deque com os valores do array
    deque<int> d1(t, t + 10);

    cout << "Procurando pelo primeiro valor 10 no container:\n";
    // std::find retorna um iterador para o primeiro elemento igual ao procurado.
    // ou seja, procura pela primeira ocorrência do valor 10
    auto found = find(d1.begin(), d1.end(), 10);

    if (found != d1.end()) {
        // std::distance calcula a posição do elemento a partir do início do container
        // Mostra a posição do primeiro 10 encontrado
        cout << "Valor 10 encontrado na posição: "
             << distance(d1.begin(), found) << endl;

        cout << "\nBuscando todas as ocorrências restantes do valor 10:\n";

        ++found; // Pula o primeiro encontrado

        // Continua procurando por outros valores 10
        while ((found = find(found, d1.end(), 10)) != d1.end()) {
            cout << "Outro valor 10 encontrado na posição: "
                 << distance(d1.begin(), found) << endl;
            ++found;
        }
    } else {
        cout << "Valor 10 não encontrado.\n";
    }

    return 0;
}
