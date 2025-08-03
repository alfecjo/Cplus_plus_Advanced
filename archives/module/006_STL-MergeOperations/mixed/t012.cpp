#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Função para imprimir os nomes (IDs) das disciplinas
void imprimir(int id)
{
    cout << "Disciplina " << id << "\n";
}

int main()
{
    // Disciplinas do Aluno A (IDs hipotéticos)
    int alunoA[] = {101, 204, 303, 150};

    // Disciplinas do Aluno B
    int alunoB[] = {150, 101, 400, 500};

    // Ordenação dos vetores para poder usar set_intersection
    sort(alunoA, alunoA + 4);
    sort(alunoB, alunoB + 4);

    // Vetor para armazenar disciplinas em comum
    vector<int> disciplinas_comuns(4); // tamanho suficiente (min dos dois conjuntos)

    // Calcula a interseção (disciplinas cursadas por ambos)
    auto it = set_intersection(
        alunoA, alunoA + 4,
        alunoB, alunoB + 4,
        disciplinas_comuns.begin());

    // Redimensiona vetor para conter apenas elementos válidos
    disciplinas_comuns.resize(it - disciplinas_comuns.begin());

    // Imprime disciplinas em comum
    cout << "Disciplinas em comum entre os dois alunos:\n";
    for_each(disciplinas_comuns.begin(), disciplinas_comuns.end(), imprimir);

    return 0;
}
