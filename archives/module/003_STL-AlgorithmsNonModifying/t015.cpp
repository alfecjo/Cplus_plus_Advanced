#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <list>

using namespace std;

template <class T>
void print(const T & value) 
{
    cout << value << " ";
}

// Functor (objeto função) que compara caracteres ignorando maiúsculas/minúsculas
struct Find
{
    char value;

    // Construtor: converte o caractere passado para maiúsculo
    Find(const char & v) : value(toupper(v)) {}

    // Sobrecarga do operador () que compara ignorando o caso
    bool operator()(const char & v)
    {
        return toupper(v) == value;
    }
};

int main()
{

    int t[] = {1, 2, 3, 4, 5, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 1};
    vector<int> v1(t, t + 19);

    cout << "Elementos do vetor:\n";
    for_each(v1.begin(), v1.end(), print<int>);
    cout << endl << endl;

    // Contagem de quantas vezes o número 2 aparece
    cout << "Contando o valor 2:\n";
    unsigned number = count(v1.begin(), v1.end(), 2);
    cout << "Número de vezes que (2) aparece: " << number << endl << endl;

    // Contagem de quantas vezes o número 2 aparece
    cout << "Contando o valor 1:\n";
    number = count(v1.begin(), v1.end(), 1);
    cout << "Número de vezes que (1) aparece: " << number << endl << endl;

        // Contagem do valor 10 (que não está presente)
    cout << "Contando o valor 10:\n";
    number = count(v1.begin(), v1.end(), 10);
    cout << "Número de vezes que (10) aparece: " << number << endl << endl;

    // Lista de caracteres com letras maiúsculas e minúsculas misturadas
    char ts[] = {'a','b', 'c', 'a', 'A', 'b','D', 'A', 'b', 'C', 'a', 'f'};
    list<char> l1(ts, ts + 12);

    // Contagem de 'a' ignorando maiúsculas/minúsculas
    cout << "Contando 'a' (ignorando maiúsculas/minúsculas):\n";
    number = count_if(l1.begin(), l1.end(), Find('a'));
    cout << "Número de vezes que ('a') aparece: " << number << endl << endl;

    // Contagem de 'a' considerando diferenciação entre maiúsculas e minúsculas
    cout << "Contando 'a' (diferenciando maiúsculas/minúsculas):\n";
    number = count(l1.begin(), l1.end(), 'a');
    cout << "Número de vezes que ('a') aparece: " << number << endl;

    return 0;
}
