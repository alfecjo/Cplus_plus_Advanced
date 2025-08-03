#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

template <class T>
void print(const T& value) {
    cout << value << " ";
}

// Functor para gerar números da série Fibonacci
struct FibonacciGenerator {
    int current;
    int next;

    // Inicializa os dois primeiros números da série Fibonacci
    FibonacciGenerator() : current(0), next(1) {}

    // gera o próximo número da série a cada chamada
    int operator()() {
        int ret = current;
        int new_next = current + next;
        current = next;
        next = new_next;
        return ret;
    }
};

int main() {
    deque<int> d1(10);

    cout << "Source collection - valores default:\n";
    cout << "d1: "; for_each(d1.begin(), d1.end(), print<int>); cout << "\n\n";

    cout << "Fill: Preenchendo a coleção inteira com valor 1\n";
    fill(d1.begin(), d1.end(), 1);
    cout << "d1: "; for_each(d1.begin(), d1.end(), print<int>); cout << "\n";

    cout << "Fill_n: Preenchendo metade da coleção com valor 10\n";
    fill_n(d1.begin(), d1.size() / 2, 10);
    cout << "d1: "; for_each(d1.begin(), d1.end(), print<int>); cout << "\n\n";

    cout << "Generate: Preenchendo toda a coleção com números da série Fibonacci\n";
    generate(d1.begin(), d1.end(), FibonacciGenerator());
    cout << "d1: "; for_each(d1.begin(), d1.end(), print<int>); cout << "\n";

    cout << "Generate_n: Preenchendo os primeiros 10 elementos com Fibonacci (reinicia a sequência)\n";
    generate_n(d1.begin(), 10, FibonacciGenerator());
    cout << "d1: "; for_each(d1.begin(), d1.end(), print<int>); cout << "\n\n";

    return 0;
}
