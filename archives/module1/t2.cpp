#include <vector>
#include <iostream>
using namespace std;

int main ()
{
    vector<int> v1(4, 3);
    v1.push_back(4);
    
    // for(vector<int>::iterator i = v1.rbegin(); i != v1.rend(); ++i)
    // precisa usar reverse_iterator, que é o tipo retornado por rbegin() e rend()
    // o iterator normal não funciona aqui
    // o reverse_iterator itera do final para o começo
    // e o iterator normal itera do começo para o final
    // então, se você usar iterator, ele não vai funcionar como esperado
    // o reverse_iterator é necessário para percorrer o vetor de trás para frente
    // e o iterator normal é necessário para percorrer o vetor de frente para trás
    for (vector<int>::reverse_iterator i = v1.rbegin(); i != v1.rend(); ++i)
    {
        cout << *i << " ";
    }
    cout<< endl;
    return 0;
}

