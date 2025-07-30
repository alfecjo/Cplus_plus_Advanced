#include <deque>
#include <iostream>

using namespace std;

template <typename T>
ostream& print(const T& start, const T& end)
{
    T tmp = start;
    for (; tmp != end; ++tmp)
    {
        cout << *tmp << " ";
    }
    return cout;
}

int main()
{
    int tab[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    deque<int> d1(tab, tab + 10);
    deque<int> d2;

    while (!d1.empty())
    {
        // Pega o último elemento de d1 e insere na frente de d2
        d2.push_front(d1.back());  // LINE I

        // Remove o primeiro elemento de d1 (o da frente)
        d1.pop_front();            // LINE II
    }

    // Imprime todos os elementos de d2 e mostra seu tamanho
    print(d2.begin(), d2.end()) << ": " << d2.size() << endl;

    return 0;
}
