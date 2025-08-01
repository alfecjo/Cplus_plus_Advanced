#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Função que imprime todas as posições em que o valor aparece,
 * e a quantas vezes ele foi encontrado até aquele ponto.
 */
void print_found(vector<int> values, int value)
{
	int count = 0;
	for (int i = 0; i < values.size(); ++i)
	{
		if (values[i] == value)
		{
			count++;
			cout << value << " found " << count << " times at: " << i << endl;
		}
	}
}

int main()
{
	vector<int> values =
		{ 11, 11, 21, 21, 30, 11, 11, 11, 17, 21, 21, 21, 11, 11, 11, 11 };
	print_found(values, 11);
	print_found(values, 21);
	return 0;
}
