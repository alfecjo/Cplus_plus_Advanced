#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>
#include <cctype>

using namespace std;

/*
Uso de search_n da STL para buscar sequências repetidas.
Uso de functor personalizado (Compare) para comparação case-insensitive.
Como usar vector, list e distance de forma prática.
Aplicação de conceitos C++ em problemas reais de engenharia, como
 monitoramento de sinais e análise de mensagens de status.
*/

// Função genérica para imprimir valores
template <class T>
void print(const T &value)
{
    cout << value << " ";
}

// Comparador case-insensitive para caracteres
struct CaseInsensitiveCompare
{
    bool operator()(const char &a, const char &b) const
    {
        return tolower(a) == tolower(b);
    }
};

int main()
{
    // Simulando amostras de um sinal digital capturado (por exemplo, níveis de potência em dBm)
    int sinal[] = {-65, -66, -70, -65, -65, -65, -90, -90, -90, -90, -70, -65, -66, -65};
    vector<int> amostras(sinal, sinal + sizeof(sinal) / sizeof(int));

    cout << "Amostras do sinal capturado:\n";
    for_each(amostras.begin(), amostras.end(), print<int>);
    cout << "\n\n";

    // Detectando perda de sinal (simulada com valor -90 repetido 4 vezes)
    cout << "Analisando perda de sinal (nível -90 dBm repetido 4 vezes):\n";
    auto found = search_n(amostras.begin(), amostras.end(), 4, -90);
    if (found != amostras.end())
    {
        cout << "Perda detectada na posição: " << distance(amostras.begin(), found) << endl;
    }
    else
    {
        cout << "Perda de sinal não detectada.\n";
    }
    cout << endl;

    // Detectando erro temporário (simulado com -65 repetido 3 vezes)
    cout << "Analisando erro temporário (nível -65 dBm repetido 3 vezes):\n";
    found = search_n(amostras.begin(), amostras.end(), 3, -65);
    if (found != amostras.end())
    {
        cout << "Erro detectado na posição: " << distance(amostras.begin(), found) << endl;
    }
    else
    {
        cout << "Erro temporário não detectado.\n";
    }
    cout << endl;

    // Simulando uma sequência de códigos de status de um sistema de enlace (A, B, C, etc.)
    char codigosStatus[] = {'a', 'B', 'A', 'a', 'A', 'C', 'D', 'a', 'b', 'c', 'A', 'f'};
    list<char> status(codigosStatus, codigosStatus + sizeof(codigosStatus) / sizeof(char));

    cout << "Códigos de status recebidos:\n";
    for_each(status.begin(), status.end(), print<char>);
    cout << "\n\n";

    // Análise case-sensitive
    cout << "Análise de sequência 'A A' (sensível a maiúsculas):\n";
    auto foundStatus = search_n(status.begin(), status.end(), 2, 'A');
    if (foundStatus != status.end())
    {
        cout << "Sequência encontrada na posição: " << distance(status.begin(), foundStatus) << endl;
    }
    else
    {
        cout << "Sequência 'A A' não encontrada.\n";
    }
    cout << endl;

    // Análise case-insensitive (importante em protocolos que ignoram case)
    cout << "Análise de sequência 'A A' (ignorando maiúsculas/minúsculas):\n";
    foundStatus = search_n(status.begin(), status.end(), 2, 'A', CaseInsensitiveCompare());
    if (foundStatus != status.end())
    {
        cout << "Sequência (sem considerar maiúsculas/minúsculas) encontrada na posição: "
             << distance(status.begin(), foundStatus) << endl;
    }
    else
    {
        cout << "Sequência 'A A' (case-insensitive) não encontrada.\n";
    }
    cout << endl;

    return 0;
}
