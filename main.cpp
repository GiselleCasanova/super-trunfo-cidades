#include <iostream>
#include <string>
using namespace std;

struct Carta {
    string estado;
    string nomeCidade;
    int codigo;
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

void exibirCarta(Carta c) {
    cout << "\n📇 Carta da Cidade: " << c.nomeCidade << " - " << c.estado << endl;
    cout << "Código: " << c.codigo << endl;
    cout << "População: " << c.populacao << endl;
    cout << "Área: " << c.area << " km²" << endl;
    cout << "PIB: R$ " << c.pib << " bilhões" << endl;
    cout << "Pontos Turísticos: " << c.pontosTuristicos << endl;
}

Carta cadastrarCarta() {
    Carta c;
    cout << "Digite o estado: ";
    getline(cin, c.estado);
    cout << "Digite o nome da cidade: ";
    getline(cin, c.nomeCidade);
    cout << "Digite o código da carta: ";
    cin >> c.codigo;
    cout << "Digite a população: ";
    cin >> c.populacao;
    cout << "Digite a área em km²: ";
    cin >> c.area;
    cout << "Digite o PIB (em bilhões): ";
    cin >> c.pib;
    cout << "Digite o número de pontos turísticos: ";
    cin >> c.pontosTuristicos;
    cin.ignore(); // limpar o buffer do enter
    return c;
}

void compararPorPopulacao(Carta c1, Carta c2) {
    cout << "\n🔎 Comparando por população...\n";
    if (c1.populacao > c2.populacao)
        cout << "🏆 " << c1.nomeCidade << " venceu com maior população!\n";
    else if (c2.populacao > c1.populacao)
        cout << "🏆 " << c2.nomeCidade << " venceu com maior população!\n";
    else
        cout << "🤝 Empate! Ambas as cidades têm a mesma população.\n";
}

int main() {
    cout << "=== Cadastro da Carta 1 ===\n";
    Carta carta1 = cadastrarCarta();
    cout << "\n=== Cadastro da Carta 2 ===\n";
    Carta carta2 = cadastrarCarta();

    cout << "\n--- Carta 1 ---";
    exibirCarta(carta1);
    cout << "\n--- Carta 2 ---";
    exibirCarta(carta2);

    compararPorPopulacao(carta1, carta2);

    return 0;
}
