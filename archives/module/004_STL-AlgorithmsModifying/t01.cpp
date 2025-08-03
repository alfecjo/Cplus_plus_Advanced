#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

template <class T>
void print(const T& value) {
    cout << value << " ";
}

int main() {
    int data[] = {1,2,3,4,5,6,7,8,9,10};
    size_t size = sizeof(data) / sizeof(data[0]);

    // COPY ----------
    cout << "=== std::copy ===\n";

    vector<int> source1(data, data + size); // vetor de origem
    deque<int> target1(size);               // deque destino

    cout << "Source: ";
    for_each(source1.begin(), source1.end(), print<int>);
    cout << "\nTarget before copy: ";
    for_each(target1.begin(), target1.end(), print<int>);
    cout << "\n";

    // Copiando os elementos da origem para o destino
    copy(source1.begin(), source1.end(), target1.begin());

    cout << "Target after copy: ";
    for_each(target1.begin(), target1.end(), print<int>);
    cout << "\n\n";

    // COPY_BACKWARD ----------
    cout << "=== std::copy_backward ===\n";

    vector<int> source2(data, data + size);
    deque<int> target2(size);

    cout << "Source: ";
    for_each(source2.begin(), source2.end(), print<int>);
    cout << "\nTarget before copy_backward: ";
    for_each(target2.begin(), target2.end(), print<int>);
    cout << "\n";

    // copiando os elementos da origem para o destino de trás para frente
    copy_backward(source2.begin(), source2.end(), target2.end());

    cout << "Target after copy_backward: ";
    for_each(target2.begin(), target2.end(), print<int>);
    cout << "\n";

    return 0;
}
