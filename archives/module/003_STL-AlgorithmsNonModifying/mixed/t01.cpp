#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
using namespace std;

struct myprinter {
    void operator()(int i) {
        cout << i << ", ";
    }
};

int main() {
    int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
    vector<int> v1(mynumbers, mynumbers + 7);
    deque<int> d1(mynumbers, mynumbers + 7);
    set<int> s1(mynumbers, mynumbers + 7);

    //a função pop_back() da std::vector não aceita argumentos
    v1.pop_back();  // remove apenas o último elemento (5)

    for_each(s1.begin(), s1.end(), myprinter());       // Line II
    for_each(d1.begin(), d1.end(), myprinter());       // Line III
    for_each(v1.begin(), v1.end(), myprinter());       // Line IV

    cout << endl; // Print newline
    cout << "Size of vector v1: " << v1.size() << endl; // Print size of vector
    cout << "Size of deque d1: " << d1.size() << endl; // Print size of deque
    cout << "Size of set s1: " << s1.size() << endl; // Print size of set
    
    return 0;
}
