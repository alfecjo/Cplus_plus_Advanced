#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void print(const int &value)
{
    cout << value << " ";
}

int main()
{
    // Vetor com valores repetidos
    int t[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 2};
    vector<int> v1(t, t + 18);

    // Exibe o conteúdo do vetor
    for_each(v1.begin(), v1.end(), print);
    cout << endl
         << endl;

    // Subsequência que queremos encontrar
    int ts[] = {2, 3};

    cout << "Procurando a sequência 2, 3 a partir do início:\n";
    auto found = search(v1.begin(), v1.end(), ts, ts + 2);

    if (found != v1.end())
    {
        cout << "Sequência encontrada na posição: " << distance(v1.begin(), found) << endl;
    }
    else
    {
        cout << "Sequência não encontrada\n";
    }

    cout << endl
         << "Procurando a sequência 2, 3 a partir do fim:\n";
    found = find_end(v1.begin(), v1.end(), ts, ts + 2);

    if (found != v1.end())
    {
        cout << "Última ocorrência encontrada na posição: " << distance(v1.begin(), found) << endl;
    }
    else
    {
        cout << "Sequência não encontrada\n";
    }

    return 0;
}
