#include <iostream>
#include <vector>
#include <algorithm> // std::unique
#include <iterator>  // std::ostream_iterator

using namespace std;

int main() {
    // sinal com valores repetidos consecutivamente (ex: ruído estático)
    vector<int> signal = {1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 5, 5, 6};

    cout << " Sinal original:\n";
    copy(signal.begin(), signal.end(), ostream_iterator<int>(cout, " "));
    cout << "\n\n";

    // unique reordena os elementos, removendo duplicatas consecutivas
    auto new_end = unique(signal.begin(), signal.end());

    // Apaga os elementos redundantes do vetor
    signal.erase(new_end, signal.end());

    cout << "Sinal após std::unique (removendo duplicatas consecutivas):\n";
    copy(signal.begin(), signal.end(), ostream_iterator<int>(cout, " "));
    cout << "\n\n";

    return 0;
}
