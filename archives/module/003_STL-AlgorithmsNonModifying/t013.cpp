#include <iostream>
#include <vector>
#include <list>
#include <algorithm>  // para std::adjacent_find, std::for_each
#include <cctype>     // para std::tolower

using namespace std;

// Função genérica para imprimir qualquer tipo de dado
template <typename T>
void imprimir(const T &valor) {
    cout << valor << " ";
}

// Functor para comparar caracteres ignorando maiúsculas/minúsculas
struct CompararIgnorandoCase {
    bool operator()(const char &a, const char &b) {
        return tolower(a) == tolower(b);  // compara ignorando caixa
    }
};

int main() {
    // Vetor de caracteres (poderia ser uma frase, por exemplo)
    char caracteres[] = {'A', 'b', 'c', 'D', 'e', 'F', 'F', 'G', 'h', 'i', 'I', 'J'};

    // Cria uma lista a partir do array
    list<char> listaCaracteres(caracteres, caracteres + sizeof(caracteres) / sizeof(char));

    cout << "Conteúdo da lista de caracteres:\n";
    for_each(listaCaracteres.begin(), listaCaracteres.end(), imprimir<char>);
    cout << "\n\n";

    cout << "Buscando pares de caracteres iguais (ignorando maiúsculas/minúsculas)...\n";

    // Busca dois elementos adjacentes iguais (ignora diferença entre maiúsculas e minúsculas)
    auto encontrado = adjacent_find(listaCaracteres.begin(), listaCaracteres.end(), CompararIgnorandoCase());

    if (encontrado != listaCaracteres.end()) {
        cout << "Par encontrado: '" << *encontrado << "' na posição "
             << distance(listaCaracteres.begin(), encontrado) << endl;
    } else {
        cout << "Nenhum par adjacente de caracteres iguais foi encontrado.\n";
    }

    return 0;
}
