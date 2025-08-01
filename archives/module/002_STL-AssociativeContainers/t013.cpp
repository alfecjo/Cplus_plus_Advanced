#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 8 };

    vector<int> v(mynumbers, mynumbers + 7);

    map<int, string> m;

    // preenche o map com pares {número, "valor como string"}
    for (int i = 0; i < v.size(); i++) {
        // stringstream para transformar int em string
        stringstream ss;
        ss << "valor_" << v[i];
        m[v[i]] = ss.str();  // insere no map
    }

    // itera sobre o map e imprime os pares chave:valor
    for (map<int, string>::iterator i = m.begin(); i != m.end(); i++) {
        cout << i->first << ": " << i->second << ", ";
    }

    cout << endl;
    return 0;
}
