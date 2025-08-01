#include <iostream>
#include <list>
#include <algorithm> // std::adjacent_find, std::for_each

using namespace std;

// Função genérica para imprimir qualquer tipo de dado
template <typename T>
void print(const T &valor) {
    cout << valor << " ";
}

int main() {
    // Vetor de caracteres (pode conter letras maiúsculas e minúsculas)
    char caracteres[] = {'A', 'B', 'C', 'D', 'E', 'F', 'F', 'g', 'h', 'i', 'j', 'j'};

    // Cria uma lista a partir do vetor
    list<char> listaCaracteres(caracteres, caracteres + sizeof(caracteres) / sizeof(char));

    cout << "Conteúdo da lista de caracteres:\n";
    for_each(listaCaracteres.begin(), listaCaracteres.end(), print<char>);
    cout << "\n\n";

    cout << "Buscando pares de caracteres exatamente iguais (case-sensitive)...\n";

    // Busca dois elementos adjacentes exatamente iguais (mesma caixa)
    auto encontrado = adjacent_find(listaCaracteres.begin(), listaCaracteres.end());

    if (encontrado != listaCaracteres.end()) {
        cout << "Par encontrado: '" << *encontrado << "' na posição "
             << distance(listaCaracteres.begin(), encontrado) << endl;
    } else {
        cout << "Nenhum par adjacente exatamente igual foi encontrado.\n";
    }

    return 0;
}
