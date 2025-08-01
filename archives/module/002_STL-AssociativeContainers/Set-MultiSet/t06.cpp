#include <iostream>
#include <set>  // Necessário para usar multiset

using namespace std;

int main()
{
	// Declara e inicializa dois multiset com inteiros (permitem valores duplicados)
	multiset<int> m1 = { 1, 5, 7, 8, 9, 4, 5 };
	multiset<int> m2 = { 2, 4, 6, 8, 8, 6, 2 };

	unsigned value;  // Variável para armazenar o valor a ser buscado
	cin >> value;    // lê esse valor digitado pelo usuário

	int count = 0;   // Contador de ocorrências

	// percorre todos os elementos do multiset m1
	for (auto x : m1)
	{
		if (x == value)  // Se o elemento for igual ao valor procurado
			count++;     // Incrementa o contador
	}

	// Percorre todos os elementos do multiset m2
	for (auto x : m2)
	{
		if (x == value)  // Mesmo procedimento acima
			count++;
	}

	// Exibe o número de vezes que o valor apareceu nos dois multisets
	cout << value << " found " << count << " times." << endl;

	return 0;
}
