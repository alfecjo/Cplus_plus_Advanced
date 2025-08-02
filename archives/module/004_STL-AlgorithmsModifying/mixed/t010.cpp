#include <iostream>     
#include <algorithm>    // Para usar std::replace e std::for_each
#include <vector>       
#include <set>          

using namespace std;


void printer(int i) {
    cout << i << ", ";
}

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };

    
    vector<int> v1(mynumbers, mynumbers + 7);

    // Inicializa um set s1 com os mesmos valores (elimina duplicatas e ordena automaticamente)
    set<int> s1(mynumbers, mynumbers + 7);

    // substitui todas as ocorrências do valor 9 por 3 dentro de v1
    // Ou seja, percorre v1 do começo ao fim, procurando 9 e trocando por 3
    replace(v1.begin(), v1.end(), 9, 3);

    // Imprime os elementos do vector v1 após a substituição
    for_each(v1.begin(), v1.end(), printer);

    return 0;
}
