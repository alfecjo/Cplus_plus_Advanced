#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

void printer(int i) {
    cout << i << " ";
}

int main() {
    vector<int> signals = { -5, 3, -2, 7, 0, -9, 4, -1, 6 };

    // Separando negativos e positivos
    vector<int> negatives, positives;

    for (int num : signals) {
        if (num < 0) negatives.push_back(num);
        else positives.push_back(num);
    }

    // ordena negativos em ordem crescente
    sort(negatives.begin(), negatives.end());

    // Ordena positivos em ordem decrescente
    sort(positives.begin(), positives.end(), greater<int>());

    // Combina os dois vetores
    vector<int> result;
    result.insert(result.end(), negatives.begin(), negatives.end());
    result.insert(result.end(), positives.begin(), positives.end());

    // imprime resultado
    cout << "Vetor final ordenado por sinal:" << endl;
    for_each(result.begin(), result.end(), printer);

    cout << endl;
    return 0;
}
