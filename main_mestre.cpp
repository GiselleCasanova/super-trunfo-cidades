#include <iostream>
#include <string>
using namespace std;

// Estrutura da carta com os atributos da cidade
struct Carta {
    string estado;
    string nomeCidade;
    int codigo;
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Função para exibir os dados de uma carta
void exibirCarta(const Carta& c) {
    cout << "\n📇 Carta da Cidade: " << c.nomeCidade << " - " << c.estado << endl;
    cout << "Código: " << c.codigo << endl;
    cout << "População: " << c.populacao << " habitantes" << endl;
    cout << "Área: " << c.area << " km²" << endl;
    cout << "PIB: R$ " << c.pib << " bilhões" << endl;
    cout << "Pontos turísticos: " << c.pontosTuristicos << endl;
    cout << "---------------------------" << endl;
}

// Função para comparar um único atributo e retornar 1 se carta1 vence, 2 se carta2 vence, 0 empate
int compararAtributo(const string& nomeAtributo, float valor1, float valor2, bool menorVence = false) {
    if (menorVence) {
        if (valor1 < valor2) return 1;
        else if (valor2 < valor1) return 2;
    } else {
        if (valor1 > valor2) return 1;
        else if (valor2 > valor1) return 2;
    }
    return 0; // empate
}

int main() {
    Carta carta1, carta2;

    // Cadastro da Carta 1
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

    // Cadastro da Carta 2
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

    // Menu para escolha de dois atributos
    int escolha1, escolha2;
    cout << "\n=== Escolha o primeiro atributo para comparar ===" << endl;
    cout << "1 - População" << endl;
    cout << "2 - Área" << endl;
    cout << "3 - PIB" << endl;
    cout << "4 - Pontos Turísticos" << endl;
    cout << "Digite a opção desejada: ";
    cin >> escolha1;

    cout << "\n=== Escolha o segundo atributo para comparar ===" << endl;
    cout << "1 - População" << endl;
    cout << "2 - Área" << endl;
    cout << "3 - PIB" << endl;
    cout << "4 - Pontos Turísticos" << endl;
    cout << "Digite a opção desejada: ";
    cin >> escolha2;

    // Função lambda para obter nome do atributo por código
    auto nomeAtributo = [](int opc) -> string {
        switch (opc) {
            case 1: return "População";
            case 2: return "Área";
            case 3: return "PIB";
            case 4: return "Pontos Turísticos";
            default: return "Desconhecido";
        }
    };

    // Função lambda para pegar valor do atributo
    auto valorAtributo = [&](const Carta& c, int opc) -> float {
        switch (opc) {
            case 1: return c.populacao;
            case 2: return c.area;
            case 3: return c.pib;
            case 4: return c.pontosTuristicos;
            default: return 0;
        }
    };

    // Considerar que para densidade populacional o menor vence
    // Aqui vamos assumir que "Área" é atributo onde menor valor vence, só como exemplo.
    // Se quiser fazer densidade populacional mesmo, precisaria calcular população/área.
    auto menorVence = [&](int opc) -> bool {
        // Por enquanto, nenhum atributo é "menor vence" - ajustar aqui se quiser
        return false;
    };

    // Comparar os dois atributos individualmente
    int resultado1 = compararAtributo(nomeAtributo(escolha1), valorAtributo(carta1, escolha1), valorAtributo(carta2, escolha1), menorVence(escolha1));
    int resultado2 = compararAtributo(nomeAtributo(escolha2), valorAtributo(carta1, escolha2), valorAtributo(carta2, escolha2), menorVence(escolha2));

    // Mostrar resultados detalhados
    cout << "\n=== Resultados da Comparação ===" << endl;

    // Função lambda para imprimir vencedor de cada atributo
    auto imprimirResultado = [&](int res, int opc) {
        string nomeAttr = nomeAtributo(opc);
        if (res == 1)
            cout << "🏆 Carta 1 (" << carta1.nomeCidade << ") venceu no atributo " << nomeAttr << "!" << endl;
        else if (res == 2)
            cout << "🏆 Carta 2 (" << carta2.nomeCidade << ") venceu no atributo " << nomeAttr << "!" << endl;
        else
            cout << "🤝 Empate no atributo " << nomeAttr << "!" << endl;
    };

    imprimirResultado(resultado1, escolha1);
    imprimirResultado(resultado2, escolha2);

    // Lógica final para decidir vencedor geral
    int vencedorFinal;
    if (resultado1 == resultado2) {
        if (resultado1 == 0) {
            cout << "\n🤝 Resultado geral: Empate total!" << endl;
            vencedorFinal = 0;
        } else {
            cout << "\n🏆 Resultado geral: Ambas as cartas empataram nos dois atributos!" << endl;
            vencedorFinal = 0;
        }
    } else {
        // Se um venceu nos dois, ele vence geral. Se cada uma venceu um, empate.
        if (resultado1 == resultado2)
            vencedorFinal = resultado1;
        else if (resultado1 != 0 && resultado2 == 0)
            vencedorFinal = resultado1;
        else if (resultado2 != 0 && resultado1 == 0)
            vencedorFinal = resultado2;
        else
            vencedorFinal = 0;
    }

    if (vencedorFinal == 1)
        cout << "\n🎉 A carta 1 (" << carta1.nomeCidade << ") é a vencedora geral!" << endl;
    else if (vencedorFinal == 2)
        cout << "\n🎉 A carta 2 (" << carta2.nomeCidade << ") é a vencedora geral!" << endl;
    else if (vencedorFinal == 0)
        cout << "\n🤝 O jogo terminou em empate geral!" << endl;

    return 0;
}

// Created by Giselle on 24/06/2025.
//
