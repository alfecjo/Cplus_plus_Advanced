#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>
void print(const T& value) {
    cout << value << " ";
}

int main() {
    // Swap simples de variáveis ----------
    int a = 10, b = 100;
    cout << "=== std::swap (valores simples) ===\n";
    cout << "Antes da troca:\n";
    cout << "a = " << a << ", b = " << b << "\n";

    swap(a, b); // Troca os valores de a e b

    cout << "Depois da troca:\n";
    cout << "a = " << a << ", b = " << b << "\n\n";

    // iter_swap: troca de elementos via iteradores ----------
    int t[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v(t, t + 10);

    cout << "=== std::iter_swap (primeiro e último elementos) ===\n";
    cout << "Antes da troca:\n";
    for_each(v.begin(), v.end(), print<int>);
    cout << "\n";

    iter_swap(v.begin(), prev(v.end())); // Troca o primeiro com o último

    cout << "Depois da troca:\n";
    for_each(v.begin(), v.end(), print<int>);
    cout << "\n\n";

    // swap_ranges: troca de intervalos ----------
    vector<int> v2(t, t + 10);

    cout << "=== std::swap_ranges (metade da lista com a outra metade) ===\n";
    cout << "Antes da troca:\n";
    for_each(v2.begin(), v2.end(), print<int>);
    cout << "\n";

    // Troca primeira metade com a segunda metade
    swap_ranges(v2.begin(), v2.begin() + v2.size() / 2, v2.begin() + v2.size() / 2);

    cout << "Depois da troca:\n";
    for_each(v2.begin(), v2.end(), print<int>);
    cout << "\n";

    return 0;
}
