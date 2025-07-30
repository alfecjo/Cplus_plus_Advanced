#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string> 

using namespace std;

int main() {

  
  int mynumbers[] = { 3, 9, 0, 2, 1, 4, 5 };

  // um vector a partir do array
  vector<int> v(mynumbers, mynumbers + 7);

  // um multimap onde uma chave pode estar associada a várias strings
  multimap<int, string> m;

  // preenchendo o multimap
  for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
    stringstream s;
    s << *i << *i;  // gera uma string com o número repetido (ex: 3 vira "33")
    m.insert(pair<int, string>(*i, s.str()));  // insere no multimap
  }

  // por fim, aimpressão das chaves armazenadas no multimap
  for (multimap<int, string>::iterator i = m.begin(); i != m.end(); i++) {
    cout << i->first << ", "; // imprime apenas as chaves
  }

  cout << endl;  

  return 0;
}
