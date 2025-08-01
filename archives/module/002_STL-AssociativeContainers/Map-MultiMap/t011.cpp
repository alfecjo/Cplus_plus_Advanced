#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename It>
void print(It start, It end) {
    for (; start != end; ++start) {
        cout << "[" << start->first << " => " << start->second << "] ";
    }
    cout << endl;
}

int main() {
    //com map (chaves únicas)
    map<int, string> m1;
    m1[10] = "apple";
    m1[20] = "banana";
    m1[30] = "cherry";

    cout << "Using map:\n";
    auto range1 = m1.equal_range(10);  // retorna um par de iteradores para chave 10
    print(range1.first, range1.second);  // deve imprimir apenas "10 => apple"

    auto range2 = m1.equal_range(15);  // chave inexistente
    print(range2.first, range2.second);  // nada será impresso

    // com multimap (chaves duplicadas)
    multimap<int, string> m2;
    m2.insert({10, "apple"});
    m2.insert({10, "apricot"});
    m2.insert({20, "banana"});
    m2.insert({10, "avocado"});
    m2.insert({30, "cherry"});

    cout << "\nUsing multimap:\n";
    auto range3 = m2.equal_range(10);  // retorna todos os pares com chave 10
    print(range3.first, range3.second);  // imprime todas as ocorrências da chave 10

    auto range4 = m2.equal_range(15);  // chave inexistente
    print(range4.first, range4.second);  // nada será impresso

    return 0;
}
