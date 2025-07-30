#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };
  string words[] = { "three", "nine", "zero", "two", "one", "four", "five" };

  map<int, string> m;

  // inserção correta com insert ou operador []
  for (int i = 0; i < 7; i++) {
    // ou até: m[mynumbers[i]] = words[i];
    m.insert(pair<int, string>(mynumbers[i], words[i]));    
  }

  for (map<int, string>::iterator i = m.begin(); i != m.end(); i++) {
    cout << i->first << ": " << i->second << endl;
  }

  return 0;
}
