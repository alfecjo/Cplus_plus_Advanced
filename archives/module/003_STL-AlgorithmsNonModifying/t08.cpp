#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>    // para tolower
#include <iterator>

using namespace std;

void print(const char & value) 
{
    cout << value << " ";
}

// Função de comparação sem considerar maiúsculas/minúsculas
bool compare(const char &f, const char &s)
{
    return tolower(f) == tolower(s);
}

int main()
{
    char t[] = {'a','b', 'c', 'd', 'A', 'b','D', 'A', 'b', 'C', 'a', 'f'};
    vector<char> v1(t, t + 12);

    for_each(v1.begin(), v1.end(), print); 
    cout << endl << endl;

    char ts[] = {'b','c'};

    cout << "Procurando a sequência 'b','c' (sem diferenciar maiúsculas/minúsculas):\n";
    auto found = search(v1.begin(), v1.end(), ts, ts + 2, compare);

    if (found != v1.end()) {
        cout << "Sequência encontrada na posição: " << distance(v1.begin(), found) << endl;
    } else {
        cout << "Sequência não encontrada\n";
    }

    cout << endl << "Procurando a última ocorrência da sequência (sem diferenciar case):\n";
    found = find_end(v1.begin(), v1.end(), ts, ts + 2, compare);

    if (found != v1.end()) {
        cout << "Última ocorrência na posição: " << distance(v1.begin(), found) << endl;
    } else {
        cout << "Sequência não encontrada\n";
    }

    cout << endl << "Procurando com comparação **sensível a maiúsculas/minúsculas**:\n";
    found = find_end(v1.begin(), v1.end(), ts, ts + 2);

    if (found != v1.end()) {
        cout << "Encontrada na posição: " << distance(v1.begin(), found) << endl;
    } else {
        cout << "Não encontrada\n";
    }

    return 0;
}
