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


//// Função para exibir os dados de uma carta
void exibirCarta(Carta c) {
    cout << "\n📇 Carta da Cidade: " << c.nomeCidade << " - " << c.estado << endl;
    cout << "Código: " << c.codigo << endl;
    cout << "População: " << c.populacao << " habitantes" << endl;
    cout << "Área: " << c.area << " km²" << endl;
    cout << "PIB: R$ " << c.pib << " bilhões" << endl;
    cout << "Pontos turísticos: " << c.pontosTuristicos << endl;
    cout << "---------------------------" << endl;
}

//// Função que compara dois valores e imprime quem venceu
void compararAtributo(string nomeAtributo, float valor1, float valor2, string nome1, string nome2) {
    cout << "\n🔍 Comparando: " << nomeAtributo << endl;

    if (valor1 > valor2) {
        cout << "🏆 " << nome1 << " venceu com maior " << nomeAtributo << "!" << endl;
    } else if (valor2 > valor1) {
        cout << "🏆 " << nome2 << " venceu com maior " << nomeAtributo << "!" << endl;
    } else {
        cout << "🤝 Empate no atributo " << nomeAtributo << "!" << endl;
    }
}

int main() {
    Carta carta1, carta2;

    cout << "=== Cadastro da Carta 1 ===" << endl;
    cout << "Digite o estado: ";
    getline(cin, carta1.estado);
    cout << "Digite o nome da cidade: ";
    getline(cin, carta1.nomeCidade);
    cout << "Digite o código da carta: ";
    cin >> carta1.codigo;
    cout << "Digite a população: ";
    cin >> carta1.populacao;
    cout << "Digite a área (km²): ";
    cin >> carta1.area;
    cout << "Digite o PIB (em bilhões): ";
    cin >> carta1.pib;
    cout << "Digite o número de pontos turísticos: ";
    cin >> carta1.pontosTuristicos;
    cin.ignore(); // limpar buffer

    cout << "\n=== Cadastro da Carta 2 ===" << endl;
    cout << "Digite o estado: ";
    getline(cin, carta2.estado);
    cout << "Digite o nome da cidade: ";
    getline(cin, carta2.nomeCidade);
    cout << "Digite o código da carta: ";
    cin >> carta2.codigo;
    cout << "Digite a população: ";
    cin >> carta2.populacao;
    cout << "Digite a área (km²): ";
    cin >> carta2.area;
    cout << "Digite o PIB (em bilhões): ";
    cin >> carta2.pib;
    cout << "Digite o número de pontos turísticos: ";
    cin >> carta2.pontosTuristicos;

    // Mostrar as cartas cadastradas
    cout << "\n=== Cartas Cadastradas ===" << endl;
    exibirCarta(carta1);
    exibirCarta(carta2);

     Menu de seleção
    int escolha;
    cout << "\n=== Escolha um atributo para comparar ===" << endl;
    cout << "1 - População" << endl;
    cout << "2 - Área" << endl;
    cout << "3 - PIB" << endl;
    cout << "4 - Pontos Turísticos" << endl;
    cout << "Digite a opção desejada: ";
    cin >> escolha;

    switch (escolha) {
        case 1:
            compararAtributo("População", carta1.populacao, carta2.populacao, carta1.nomeCidade, carta2.nomeCidade);
            break;
        case 2:
            compararAtributo("Área", carta1.area, carta2.area, carta1.nomeCidade, carta2.nomeCidade);
            break;
        case 3:
            compararAtributo("PIB", carta1.pib, carta2.pib, carta1.nomeCidade, carta2.nomeCidade);
            break;
        case 4:
            compararAtributo("Pontos Turísticos", carta1.pontosTuristicos, carta2.pontosTuristicos, carta1.nomeCidade, carta2.nomeCidade);
            break;
        default:
            cout << "❌ Opção inválida!" << endl;
    }

    return 0;
}
// Created by Giselle on 24/06/2025.
//
