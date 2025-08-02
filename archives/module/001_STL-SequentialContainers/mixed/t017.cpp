#include <stack>
#include <deque>
#include <iostream>

using namespace std;

int main()
{
  int t[] = { 1, 5, 3, 4, 2 };
  deque<int> d(t, t + 5);
  stack<int, deque<int>> s(d); // <- especificar o tipo do container
  cout << s.top() << " ";
  d.push_front(6);             // não afeta a pilha s
  cout << s.top() << endl;     // ainda imprime 2
  return 0;
}
