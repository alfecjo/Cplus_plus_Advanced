#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Part
{
    int id;

public:
    Part() : id(0) {} // construtor padrão necessário para vector<Part>(N)
    Part(int id) : id(id) {}

    int getId() const { return id; }

    bool operator<(const Part &other) const
    {
        return id < other.id;
    }

    bool operator<(const int &other) const
    {
        return id < other;
    }

    operator int() const
    {
        return id;
    }
};

ostream &operator<<(ostream &stream, const Part &part)
{
    stream << part.getId();
    return stream;
}

void printPart(const Part &part)
{
    cout << part << ", ";
}

int main()
{
    Part parts1[] = {3, 9, 0, 2};
    int part_ids2[] = {6, 1, 4, 2};

    sort(begin(parts1), end(parts1));       // ordena os objetos Part
    sort(begin(part_ids2), end(part_ids2)); // ordena os ints

    vector<Part> diff(4); // espaço suficiente para a diferença

    auto it = set_difference(
        begin(parts1), end(parts1),
        begin(part_ids2), end(part_ids2),
        diff.begin());

    // remove elementos extras não preenchidos
    diff.resize(it - diff.begin());

    for_each(diff.begin(), diff.end(), printPart);
    cout << endl;

    return 0;
}
