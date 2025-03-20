#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define HABILIDADE 5
#define NAVIO 3
#define AGUA 0

// Estrutura para armazenar o tabuleiro
int tabuleiro[TAMANHO][TAMANHO];

// Inicializa o tabuleiro com água
void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para desenhar uma habilidade em formato de cone
void desenharCone(int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            if (linha + i < TAMANHO && coluna + j >= 0 && coluna + j < TAMANHO)
                tabuleiro[linha + i][coluna + j] = HABILIDADE;
        }
    }
}

// Função para desenhar uma habilidade em formato de cruz
void desenharCruz(int linha, int coluna) {
    for (int i = -1; i <= 1; i++) {
        if (linha + i >= 0 && linha + i < TAMANHO)
            tabuleiro[linha + i][coluna] = HABILIDADE;
        if (coluna + i >= 0 && coluna + i < TAMANHO)
            tabuleiro[linha][coluna + i] = HABILIDADE;
    }
}

// Função para desenhar uma habilidade em formato de octaedro
void desenharOctaedro(int linha, int coluna) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1 + abs(i); j <= 1 - abs(i); j++) {
            if (linha + i >= 0 && linha + i < TAMANHO && coluna + j >= 0 && coluna + j < TAMANHO)
                tabuleiro[linha + i][coluna + j] = HABILIDADE;
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro() {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    inicializarTabuleiro();
    
    // Posicionar navios para teste
    tabuleiro[2][2] = NAVIO;
    tabuleiro[4][4] = NAVIO;
    tabuleiro[6][6] = NAVIO;
    
    // Aplicar habilidades
    desenharCone(1, 4);
    desenharCruz(4, 4);
    desenharOctaedro(6, 6);
    
    // Exibir tabuleiro com habilidades
    imprimirTabuleiro();
    
    return 0;
}
