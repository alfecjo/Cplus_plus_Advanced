#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // map onde a chave é o nome da categoria (string)
    // e o valor é o número de produtos disponíveis (int)
    map<string, int> estoque;

    // inserindo elementos no map (categoria -> quantidade)
    estoque["Eletrônicos"] = 120;
    estoque["Roupas"] = 75;
    estoque["Livros"] = 40;
    estoque["Alimentos"] = 150;
    estoque["Móveis"] = 30;

    // tentamos encontrar uma categoria que *existe* no map
    string categoria_busca = "Livros";

    cout << "Buscando categoria: " << categoria_busca << endl;

    // com método find(), que retorna um iterador para o par (chave, valor)
    map<string, int>::iterator it = estoque.find(categoria_busca);

    // Verificamos se o iterador é diferente de end() => encontrado!
    if (it != estoque.end()) {
        cout << "Categoria encontrada: " << it->first 
             << " -> Quantidade: " << it->second << endl;
    } else {
        cout << "Categoria não encontrada: " << categoria_busca << endl;
    }

    cout << "\n--------------------------\n";

    // Agora procuramos uma categoria que NÃO existe
    categoria_busca = "Brinquedos";
    cout << "Buscando categoria: " << categoria_busca << endl;

    it = estoque.find(categoria_busca);

    if (it != estoque.end()) {
        cout << "Categoria encontrada: " << it->first 
             << " -> Quantidade: " << it->second << endl;
    } else {
        cout << "Categoria não encontrada: " << categoria_busca << endl;
    }

    cout << "\n--------------------------\n";

    // percorrendo o map completo (ordem alfabética das chaves)
    cout << "Estoque total por categoria:\n";
    for (const auto& par : estoque) {
        cout << "Categoria: " << par.first << " | Quantidade: " << par.second << endl;
    }

    return 0;
}
