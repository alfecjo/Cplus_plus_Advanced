#include <vector>
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
    int tab[] = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v1(tab, tab + 10);
    vector<int> v2;

    while (!v1.empty())
    {
        int last = v1.back();
        v1.pop_back();
        v2.insert(v2.begin(), last); // ou v2.push_back(last);
    }

    print(v2.begin(), v2.end()) << ": " << v2.size() << endl;

    return 0;
}
