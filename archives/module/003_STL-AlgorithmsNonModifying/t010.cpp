#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>     // para tolower
#include <iterator>

using namespace std;

// Função genérica para imprimir valores (template)
template <class T>
void print(const T& value) {
    cout << value << " ";
}

// Functor para comparação case-insensitive de caracteres
struct CompareCaseInsensitive {
    bool operator()(const char& a, const char& b) const {
        return tolower(a) == tolower(b);
    }
};

int main() {
    // ------------------------
    // Vetor de inteiros
    // ------------------------

    int t[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 2};
    vector<int> v1(t, t + 18);

    cout << "Conteúdo de v1 (inteiros):\n";
    for_each(v1.begin(), v1.end(), print<int>);
    cout << "\n\n";

    int pattern1[] = {2, 3};

    cout << "Procurando qualquer ocorrência de 2 ou 3 em v1:\n";
    auto it = find_first_of(v1.begin(), v1.end(), pattern1, pattern1 + 2);

    if (it != v1.end()) {
        // Primeira ocorrência encontrada
        cout << "Encontrado: " << *it << " na posição: " << distance(v1.begin(), it) << endl;

        // Continua procurando pelas próximas ocorrências
        cout << "Procurando outras ocorrências de 2 ou 3:\n";
        ++it; // pular o encontrado
        while ((it = find_first_of(it, v1.end(), pattern1, pattern1 + 2)) != v1.end()) {
            cout << "Encontrado: " << *it << " na posição: " << distance(v1.begin(), it) << endl;
            ++it;
        }
    } else {
        cout << "Nenhum valor 2 ou 3 encontrado.\n";
    }

    cout << "\n";

    // ------------------------
    // Vetor de caracteres
    // ------------------------

    char chars[] = {'a','b','c','d','A','b','D','A','b','C','a','f'};
    vector<char> v2(chars, chars + 12);

    cout << "Conteúdo de v2 (caracteres):\n";
    for_each(v2.begin(), v2.end(), print<char>);
    cout << "\n\n";

    char pattern2[] = {'a', 'b'};

    // Comparação com case-insensitive
    cout << "Procurando 'a' ou 'b' (ignorar maiúsculas/minúsculas):\n";
    auto it2 = find_first_of(v2.begin(), v2.end(), pattern2, pattern2 + 2, CompareCaseInsensitive());

    if (it2 != v2.end()) {
        cout << "Encontrado: " << *it2 << " na posição: " << distance(v2.begin(), it2) << endl;

        cout << "Procurando outras ocorrências de 'a' ou 'b' (sem distinguir maiúsculas/minúsculas):\n";
        ++it2;
        while ((it2 = find_first_of(it2, v2.end(), pattern2, pattern2 + 2, CompareCaseInsensitive())) != v2.end()) {
            cout << "Encontrado: " << *it2 << " na posição: " << distance(v2.begin(), it2) << endl;
            ++it2;
        }
    } else {
        cout << "Nenhuma ocorrência encontrada com case-insensitive.\n";
    }

    cout << "\n";

    // Comparação case-sensitive (padrão)
    cout << "Procurando 'a' ou 'b' (case-sensitive):\n";
    it2 = find_first_of(v2.begin(), v2.end(), pattern2, pattern2 + 2);

    if (it2 != v2.end()) {
        cout << "Encontrado: " << *it2 << " na posição: " << distance(v2.begin(), it2) << endl;

        cout << "Procurando outras ocorrências (case-sensitive):\n";
        ++it2;
        while ((it2 = find_first_of(it2, v2.end(), pattern2, pattern2 + 2)) != v2.end()) {
            cout << "Encontrado: " << *it2 << " na posição: " << distance(v2.begin(), it2) << endl;
            ++it2;
        }
    } else {
        cout << "Nenhuma ocorrência encontrada com case-sensitive.\n";
    }

    return 0;
}
