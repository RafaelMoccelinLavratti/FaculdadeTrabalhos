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
    // Densidade populacional invertida para efeito de comparação (quanto menor, melhor)
    carta->super_poder = (float)carta->populacao + carta->area + carta->pib + carta->pontos_turisticos + (1 / (carta->densidade_populacional + 1));
}

// Função para coletar os dados de uma carta
void lerCarta(CartaCidade *carta) {
    printf("Digite o estado (ex: SP, RJ, MG): ");
    scanf("%2s", carta->estado);
    getchar(); // Consumir nova linha

    printf("Digite o código da carta: ");
    scanf("%9s", carta->codigo);
    getchar(); // Consumir nova linha
    
    printf("Digite o nome da cidade: ");
    fgets(carta->nome, 50, stdin);
    carta->nome[strcspn(carta->nome, "\n")] = 0; // Remover quebra de linha
    
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

// Função para comparar e exibir os resultados das propriedades
void compararCartas(CartaCidade c1, CartaCidade c2) {
    printf("\n=== Comparação das Cartas ===\n");
    printf("%s vs %s\n\n", c1.nome, c2.nome);

    printf("População: %lu vs %lu -> Vencedor: %d\n", c1.populacao, c2.populacao, c1.populacao > c2.populacao);
    printf("Área (km²): %.2f vs %.2f -> Vencedor: %d\n", c1.area, c2.area, c1.area > c2.area);
    printf("PIB: %.2f vs %.2f -> Vencedor: %d\n", c1.pib, c2.pib, c1.pib > c2.pib);
    printf("Pontos turísticos: %d vs %d -> Vencedor: %d\n", c1.pontos_turisticos, c2.pontos_turisticos, c1.pontos_turisticos > c2.pontos_turisticos);
    printf("Densidade Populacional: %.2f vs %.2f -> Vencedor: %d\n", c1.densidade_populacional, c2.densidade_populacional, c1.densidade_populacional < c2.densidade_populacional);
    printf("PIB per capita: %.2f vs %.2f -> Vencedor: %d\n", c1.pib_per_capita, c2.pib_per_capita, c1.pib_per_capita > c2.pib_per_capita);
    printf("Super Poder: %.2f vs %.2f -> Vencedor: %d\n", c1.super_poder, c2.super_poder, c1.super_poder > c2.super_poder);
}

int main() {
    CartaCidade carta1, carta2;
    
    printf("\n===== Cadastro da Carta 1 =====\n");
    lerCarta(&carta1);
    
    printf("\n===== Cadastro da Carta 2 =====\n");
    lerCarta(&carta2);
    
    compararCartas(carta1, carta2);
    
    return 0;
}
