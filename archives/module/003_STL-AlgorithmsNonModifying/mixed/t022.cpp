#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
  vector<int> v(mynumbers, mynumbers + 7); // Cria um vetor com os elementos do array
  vector<int>::iterator it;

  int m1[] = { 9, 0, 2 }; // Subsequência a ser procurada

  // Busca a subsequência m1 dentro do vetor v
  it = search(v.begin(), v.end(), m1, m1 + 3);  // LINE I

  if (it != v.end()) {
    cout << "found at position: " << it - v.begin() << endl;  // LINE II
  } else {
    cout << "subsequence not found" << endl;
  }

  return 0;
}
