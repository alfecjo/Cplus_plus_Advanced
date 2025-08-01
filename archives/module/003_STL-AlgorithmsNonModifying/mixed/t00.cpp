#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <set>
using namespace std;

void myprint(int i)
{
    cout << i << ", ";
}

int main()
{

    int mynumbers[] = {3, 9, 0, 2, 1, 4, 5};
    vector<int> v1(mynumbers, mynumbers + 7);
    set<int> s1(mynumbers, mynumbers + 7);
    deque<int> d1(mynumbers, mynumbers + 7);
    d1.pop_front();                          // Line II
    for_each(v1.begin(), v1.end(), myprint); // Line III
    for_each(s1.begin(), s1.end(), myprint);
    for_each(d1.begin(), d1.end(), myprint);
    cout << endl; // Print newline
    return 0;
}
