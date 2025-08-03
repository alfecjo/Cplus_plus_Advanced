#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main() {
    vector<int> signal = { -3, 5, -1, 7, -6, 2, -4, 8, -2, 6 };

    cout << "Sinal original:\n";
    for (int v : signal) cout << v << " ";
    cout << "\n\n";

    random_device rd;
    mt19937 gen(rd());

    shuffle(signal.begin(), signal.end(), gen);  // std::shuffle (pré-C++20)

    cout << "Sinal embaralhado:\n";
    for (int v : signal) cout << v << " ";
    cout << "\n";
}
