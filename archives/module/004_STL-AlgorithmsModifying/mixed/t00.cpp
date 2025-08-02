#include <iostream>
#include <vector>
#include <algorithm> // para os algoritmos

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 3, 3, 6, 7};

    // std::replace: substitui todos os 3 por 99
    replace(v.begin(), v.end(), 3, 99);
    cout << "After replace 3 by 99: ";
    for (int n : v) cout << n << " ";
    cout << "\n";

    // std::remove: remove todos os 99 (na verdade, move-os para o final)
    auto it = remove(v.begin(), v.end(), 99);
    cout << "After remove 99 (logical removal): ";
    for (int n : v) cout << n << " ";
    cout << "\n";

    // erase-remove idiom: efetivamente remove os elementos fisicamente
    v.erase(it, v.end());
    cout << "After erase-remove idiom: ";
    for (int n : v) cout << n << " ";
    cout << "\n";

    // std::reverse: inverte a ordem dos elementos
    reverse(v.begin(), v.end());
    cout << "After reverse: ";
    for (int n : v) cout << n << " ";
    cout << "\n";

    // std::transform: eleva ao quadrado cada elemento
    vector<int> v2(v.size());
    transform(v.begin(), v.end(), v2.begin(),
              [](int x) { return x * x; });
    cout << "After transform (square): ";
    for (int n : v2) cout << n << " ";
    cout << "\n";

    return 0;
}
