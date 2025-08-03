#include <vector>
#include <iostream>
#include <algorithm>
#include <functional> // greater<int>()

using namespace std;

int main()
{
    // Pontuação dos canais baseada em métricas técnicas (quanto maior, melhor)
    int channel_priorities[] = {75, 92, 60, 85, 70, 90, 66};

    // Criamos um vetor com os dados
    vector<int> channels(channel_priorities, channel_priorities + 7);

    // Ordenamos os canais da maior para a menor prioridade
    sort(channels.begin(), channels.end(), greater<int>()); // LINE I

    cout << "Canais ordenados por prioridade (alta -> baixa): ";
    for (int c : channels)
    {
        cout << c << " ";
    }
    cout << endl;

    // Encontramos o canal com menor prioridade (para possível desligamento automático)
    int min_priority = *min_element(channels.begin(), channels.end()); // LINE II

    cout << "Canal com menor prioridade (candidato a desligamento): " << min_priority << endl;

    return 0;
}
