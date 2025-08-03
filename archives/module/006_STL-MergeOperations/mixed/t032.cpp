#include <vector>

#include <iostream>

#include <algorithm>

#include <string>

using namespace std;

void
printer (string i)
{

  cout << i << ", ";

}

int
main ()
{

  string myvalues[] =
    { "yyy","Yyy","yYy","yyY","ZZZ","zZZ","ZzZ","ZZz"};

  vector < string > v1 (myvalues, myvalues + 8);

  sort (v1.begin (), v1.end ());    //LINE I

  remove (v1.begin (), v1.end (), "yyy");    //LINE II

  for_each (v1.begin (), v1.end (), printer);

  return 0;

}

