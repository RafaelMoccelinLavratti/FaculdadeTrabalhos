#include <stdio.h>
#include <string.h>

// Definição da estrutura para armazenar os dados das cartas de cidades
typedef struct {
    char estado[3]; // Estado (Ex: SP, RJ, MG)
    char codigo[10]; // Código da carta
    char nome[50]; // Nome da cidade
    unsigned long int populacao; // População da cidade
    float area; // Área da cidade (km²)
    float pib; // PIB da cidade
    int pontos_turisticos; // Número de pontos turísticos
    float densidade_populacional; // Calculado como populacao / area
    float pib_per_capita; // Calculado como pib / populacao
    float super_poder; // Soma das propriedades ajustadas
} CartaCidade;

// Função para calcular os atributos derivados de uma carta
void calcularAtributos(CartaCidade *carta) {
    carta->densidade_populacional = carta->area > 0 ? (carta->populacao / carta->area) : 0;
    carta->pib_per_capita = carta->populacao > 0 ? (carta->pib / carta->populacao) : 0;
    
    // Super Poder: Soma de todas as propriedades ajustadas
    carta->super_poder = (float)carta->populacao + carta->area + carta->pib + carta->pontos_turisticos + (1 / (carta->densidade_populacional + 1));
}

// Função para coletar os dados de uma carta
void lerCarta(CartaCidade *carta) {
    printf("Digite o estado (ex: SP, RJ, MG): ");
    scanf("%2s", carta->estado);
    getchar();

    printf("Digite o código da carta: ");
    scanf("%9s", carta->codigo);
    getchar();
    
    printf("Digite o nome da cidade: ");
    fgets(carta->nome, 50, stdin);
    carta->nome[strcspn(carta->nome, "\n")] = 0;
    
    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);
    
    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB da cidade: ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    calcularAtributos(carta);
}

// Função para comparar dois atributos escolhidos pelo usuário
void compararAtributos(CartaCidade c1, CartaCidade c2, int atributo1, int atributo2) {
    float valor1_c1, valor2_c1, valor1_c2, valor2_c2;
    int vencedor1, vencedor2;

    float atributos[6] = {c1.populacao, c1.area, c1.pib, c1.pontos_turisticos, c1.densidade_populacional, c1.pib_per_capita};
    float atributos2[6] = {c2.populacao, c2.area, c2.pib, c2.pontos_turisticos, c2.densidade_populacional, c2.pib_per_capita};

    valor1_c1 = atributos[atributo1];
    valor2_c1 = atributos[atributo2];
    valor1_c2 = atributos2[atributo1];
    valor2_c2 = atributos2[atributo2];

    vencedor1 = (atributo1 == 4) ? (valor1_c1 < valor1_c2) : (valor1_c1 > valor1_c2);
    vencedor2 = (atributo2 == 4) ? (valor2_c1 < valor2_c2) : (valor2_c1 > valor2_c2);

    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;
    int vencedor_final = (soma_c1 > soma_c2) ? 1 : (soma_c1 < soma_c2 ? 2 : 0);

    printf("\nComparação entre %s e %s:\n", c1.nome, c2.nome);
    printf("%s: %.2f vs %.2f\n", (atributo1 == 4 ? "Densidade Populacional" : "Atributo 1"), valor1_c1, valor1_c2);
    printf("%s: %.2f vs %.2f\n", (atributo2 == 4 ? "Densidade Populacional" : "Atributo 2"), valor2_c1, valor2_c2);
    printf("Soma dos atributos: %.2f vs %.2f\n", soma_c1, soma_c2);
    printf("Resultado final: %s\n", (vencedor_final == 1 ? c1.nome : (vencedor_final == 2 ? c2.nome : "Empate!")));
}

int main() {
    CartaCidade carta1, carta2;
    
    printf("\n===== Cadastro da Carta 1 =====\n");
    lerCarta(&carta1);
    
    printf("\n===== Cadastro da Carta 2 =====\n");
    lerCarta(&carta2);
    
    int atributo1, atributo2;
    do {
        printf("\nEscolha o primeiro atributo (0: População, 1: Área, 2: PIB, 3: Pontos Turísticos, 4: Densidade Populacional, 5: PIB per capita): ");
        scanf("%d", &atributo1);
        printf("Escolha o segundo atributo: ");
        scanf("%d", &atributo2);
    } while (atributo1 == atributo2 || atributo1 < 0 || atributo1 > 5 || atributo2 < 0 || atributo2 > 5);
    
    compararAtributos(carta1, carta2, atributo1, atributo2);
    
    return 0;
}
