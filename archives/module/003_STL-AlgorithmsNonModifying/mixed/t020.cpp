#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
  int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5, 6, 6, 9, 8, 2 };
  
  vector<int> v1(mynumbers, mynumbers + 12);
  set<int> s1(mynumbers, mynumbers + 12); // remove duplicatas automaticamente

  v1.push_back(10); // adiciona um elemento extra para ter tamanho maior que o set

  // LINE I – retorna o primeiro par de elementos diferentes
  auto resultSet = mismatch(s1.begin(), s1.end(), v1.begin());

  // LINE II
  if (resultSet.first != s1.end() && resultSet.second != v1.end()) {
    cout << *resultSet.first << ", " << *resultSet.second << endl;
  } else {
    cout << "All matched." << endl;
  }

  return 0;
}
