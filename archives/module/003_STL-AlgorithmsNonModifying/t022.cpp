#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <cmath> // Para fabs (valor absoluto em float)

using namespace std;

template <class T>
void print(const T &value)
{
    cout << value << " ";
}

/**
 * Operador para comparação sem diferenciar maiúsculas e minúsculas
 */
struct Compare
{
    bool operator()(const char &f, const char &s)
    {
        return tolower(f) == tolower(s);
    }
};

/**
 * Filtro passa-baixa do tipo média móvel simples
 * Simula uma atenuação de ruído de alta frequência
 */
vector<double> moving_average_filter(const vector<double> &input, int window_size)
{
    vector<double> output(input.size(), 0.0);
    int half = window_size / 2;

    for (size_t i = 0; i < input.size(); ++i)
    {
        double sum = 0.0;
        int count = 0;

        for (int j = -half; j <= half; ++j)
        {
            if (i + j >= 0 && i + j < input.size())
            {
                sum += input[i + j];
                ++count;
            }
        }

        output[i] = sum / count;
    }

    return output;
}

int main()
{
    /**
     * Simulação de dois sinais amostrados com 10 amostras cada
     * v1 = sinal original
     * l1 = sinal com perturbações (ex: ruído aditivo)
     */
    double t1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double t2[] = {1.1, 2.2, 3.1, 4.0, 5.5, 5.9, 7.2, 8.3, 8.9, 10.1}; // sinal ruidoso

    vector<double> v1(t1, t1 + 10);
    vector<double> l1(t2, t2 + 10);

    cout << "Sinal original (v1): ";
    for_each(v1.begin(), v1.end(), print<double>);
    cout << "\nSinal com ruído (l1): ";
    for_each(l1.begin(), l1.end(), print<double>);
    cout << "\n\n";

    /**
     * Verifica diferença ponto a ponto (com tolerância)
     */
    cout << "Comparação ponto-a-ponto (tolerância 0.2):\n";
    bool equal_with_tolerance = true;
    for (size_t i = 0; i < v1.size(); ++i)
    {
        if (fabs(v1[i] - l1[i]) > 0.2)
        {
            equal_with_tolerance = false;
            cout << "Diferença significativa na posição " << i
                 << ": " << v1[i] << " vs " << l1[i] << endl;
        }
    }
    if (equal_with_tolerance)
        cout << "Sinais considerados equivalentes dentro da tolerância.\n";
    else
        cout << "Sinais diferentes acima da tolerância.\n";

    cout << "\nAplicando filtro passa-baixa (média móvel de 3 amostras)...\n";
    vector<double> l1_filtered = moving_average_filter(l1, 3);

    cout << "Sinal filtrado (l1): ";
    for_each(l1_filtered.begin(), l1_filtered.end(), print<double>);
    cout << "\n";

    /**
     * Simulação com símbolos (ex: transmissor digital)
     */
    char t3[] = {'a', 'b', 'C', 'd', 'e', 'F', 'g', 'h', 'i', 'J'};
    char t4[] = {'A', 'B', 'c', 'D', 'E', 'f', 'G', 'H', 'I', 'j'}; // recebido com variação

    vector<char> v2(t3, t3 + 10);
    list<char> l2(t4, t4 + 10);

    cout << "\nSímbolos transmitidos: ";
    for_each(v2.begin(), v2.end(), print<char>);
    cout << "\nSímbolos recebidos:   ";
    for_each(l2.begin(), l2.end(), print<char>);
    cout << "\n";

    cout << "Comparação sensível a maiúsculas:\n";
    if (equal(v2.begin(), v2.end(), l2.begin()))
    {
        cout << "Símbolos idênticos!\n";
    }
    else
    {
        cout << "Diferença entre símbolos (case-sensitive)\n";
    }

    cout << "Comparação insensível a maiúsculas:\n";
    if (equal(v2.begin(), v2.end(), l2.begin(), Compare()))
    {
        cout << "Símbolos equivalentes ignorando o caso!\n";
    }
    else
    {
        cout << "Diferenças detectadas mesmo ignorando o caso\n";
    }

    return 0;
}

/*
Sinal digital com ruído: simulado com pequenos desvios no vetor l1.
Filtro passa-baixa: reduz ruído usando média móvel, que suaviza variações rápidas.
Comparação ponto a ponto com tolerância: usada em engenharia para aceitar pequenas
 diferenças por ruído ou variações de hardware.
Símbolos transmitidos/recebidos: simulando sistemas de comunicação digital (como UART, RF, etc.).
Case-sensitive vs. insensitive: pode representar modulação ou codificações diferentes.
*/