#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    int t[] = { 3, 5, 1, 4, 2 };
    
    // Cria um vector com os elementos do array t
    vector<int> v(t, t + 5);
    
    // Cria uma priority_queue (max-heap) inicializada com os elementos do vector v
    // O construtor que recebe iteradores monta a heap automaticamente
    priority_queue<int> q(v.begin(), v.end());
    
    // Imprime o elemento do topo da fila de prioridade (maior elemento)
    cout << q.top() << " ";  // Deve imprimir 5, que é o maior dos elementos iniciais
    
    // Insere o elemento 0 na fila de prioridade
    q.push(0);
    
    // Imprime novamente o topo da fila (deve continuar sendo 5)
    cout << q.top() << endl;
    
    return 0;
}
