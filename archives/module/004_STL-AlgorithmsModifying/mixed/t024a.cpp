#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <random> // para std::shuffle e geradores aleatórios

using namespace std;

template <class T>
struct Out
{
    ostream &out;

    Out(ostream &o) : out(o) {}

    void operator()(const T &val)
    {
        out << val << ", ";
    }
};

struct Sequence
{
    int start;

    Sequence(int start) : start(start) {}

    int operator()()
    {
        return start++ % 7;
    }
};

int main()
{
    vector<int> v1(4);

    generate(v1.rbegin(), v1.rend(), Sequence(10));

    // Criar gerador aleatório
    random_device rd;
    mt19937 g(rd());

    // Usar shuffle com gerador para embaralhar
    shuffle(v1.begin(), v1.end(), g);

    for_each(v1.begin(), v1.end(), Out<int>(cout));

    return 0;
}
