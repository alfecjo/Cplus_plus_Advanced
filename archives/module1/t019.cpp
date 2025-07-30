#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int mynumbers[] = { 3, 9, 3, 2, 1, 4, 5 };

    // Cria um vetor com os valores de mynumbers
    vector<int> v(mynumbers, mynumbers + 7);

    map<int, string> m;

    // Preenche o mapa com os valores do vetor
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
        stringstream s;
        s << *i; // Converte o inteiro para string
        m[*i] = s.str();  // Substitui qualquer valor anterior com mesma chave
    }

    // Tenta encontrar todos os pares com chave igual a 3
    pair<map<int, string>::iterator, map<int, string>::iterator> range;
    range = m.equal_range(3);

    map<int, string>::iterator it = range.first;

    for (; it != range.second; ++it) {
        cout << it->first << ", ";
    }

    cout << endl;
    return 0;
}
