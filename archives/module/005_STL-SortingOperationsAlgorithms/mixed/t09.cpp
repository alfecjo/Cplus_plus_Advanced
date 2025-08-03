#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Enlace {
    string nome;
    double ber; // Bit Error Rate

public:
    Enlace(string nome, double ber) : nome(nome), ber(ber) {}

    double getBER() const {
        return ber;
    }

    string getNome() const {
        return nome;
    }

    // sobrecarga para comparação (ordenação do menor BER para o maior)
    bool operator<(const Enlace& outro) const {
        return ber < outro.ber;
    }
};

// Impressão customizada com cout <<
ostream& operator<<(ostream& os, const Enlace& e) {
    os << "Enlace: " << e.getNome() << " | BER: " << e.getBER();
    return os;
}

// Função para imprimir cada elemento
void imprimir(Enlace e) {
    cout << e << endl;
}

int main() {
    vector<Enlace> enlaces = {
        Enlace("Enlace A", 1.5e-5),
        Enlace("Enlace B", 2.3e-6),
        Enlace("Enlace C", 9.1e-6),
        Enlace("Enlace D", 4.7e-5),
        Enlace("Enlace E", 7.8e-7)
    };

    // Ordenar do melhor para o pior (menor BER para maior BER)
    sort(enlaces.begin(), enlaces.end()); // usa operator<

    cout << "Enlaces ordenados por qualidade (menor BER para maior):\n";
    for_each(enlaces.begin(), enlaces.end(), imprimir);

    return 0;
}
