#include <iostream>
#include <vector>
#include <algorithm> // std::unique_copy
#include <iterator>  // std::back_inserter

using namespace std;

int main() {
    // imagine que esse seja um buffer circular de sensor
    vector<int> raw_signal = {1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 5, 5};

    cout << "Sinal bruto:\n";
    copy(raw_signal.begin(), raw_signal.end(), ostream_iterator<int>(cout, " "));
    cout << "\n\n";

    // Vetor destino: só as transições únicas
    vector<int> transitions;

    // unique_copy copia apenas os primeiros valores distintos consecutivos
    unique_copy(raw_signal.begin(), raw_signal.end(), back_inserter(transitions));

    cout << "Transições detectadas com std::unique_copy:\n";
    copy(transitions.begin(), transitions.end(), ostream_iterator<int>(cout, " "));
    cout << "\n\n";

    return 0;
}
