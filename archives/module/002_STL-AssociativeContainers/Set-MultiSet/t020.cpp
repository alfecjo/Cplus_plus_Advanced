#include <iostream>
#include <set>

using namespace std;

template <typename Iterator>
void print_range(Iterator start, Iterator end) {
    for (; start != end; ++start) {
        cout << *start << " ";
    }
    cout << endl;
}

int main() {
    multiset<double> valuesA = { 1.1, 2.3, 2.7, 2.9, 3.5 };
    multiset<double> valuesB = { 2.5, 2.7, 3.14, 3.5, 3.5, 4.5 };

    double start_value, stop_value;

    // Solicita ao usuário que insira os limites inferior e superior do intervalo
    cout << "Digite o valor inicial do intervalo: ";
    cin >> start_value;
    cout << "Digite o valor final do intervalo: ";
    cin >> stop_value;

    // Encontra os iteradores que delimitam o intervalo [start_value, stop_value)
    auto it_start_A = valuesA.lower_bound(start_value); // primeiro elemento >= start_value
    auto it_end_A = valuesA.upper_bound(stop_value);    // primeiro elemento > stop_value
    auto it_start_B = valuesB.lower_bound(start_value);
    auto it_end_B = valuesB.upper_bound(stop_value);

    // Imprime os elementos dentro do intervalo definido para cada multiset
    cout << "\nElementos em valuesA dentro do intervalo [" << start_value << ", " << stop_value << "):\n";
    print_range(it_start_A, it_end_A);

    cout << "\nElementos em valuesB dentro do intervalo [" << start_value << ", " << stop_value << "):\n";
    print_range(it_start_B, it_end_B);

    return 0;
}
