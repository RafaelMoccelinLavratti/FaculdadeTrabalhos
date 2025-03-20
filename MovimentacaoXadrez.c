#include <stdio.h>

// Função recursiva para movimentação da Torre
void moverTorre(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Função recursiva para movimentação do Bispo
void moverBispo(int casas, int x, int y) {
    if (casas == 0) return;
    printf("Diagonal Direita Cima\n");
    moverBispo(casas - 1, x + 1, y + 1);
}

// Função recursiva para movimentação da Rainha
void moverRainha(int casas) {
    if (casas == 0) return;
    printf("Diagonal Esquerda Baixo\n");
    moverRainha(casas - 1);
}

// Função para movimentação do Cavalo com loops aninhados
void moverCavalo(int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if ((i == 2 && j == 1) || (i == 1 && j == 2)) {
                printf("Movimento Cavalo: (%d, %d)\n", i, j);
                continue;
            }
        }
    }
}

int main() {
    printf("Movimento da Torre:\n");
    moverTorre(3);
    
    printf("\nMovimento do Bispo:\n");
    moverBispo(3, 0, 0);
    
    printf("\nMovimento da Rainha:\n");
    moverRainha(3);
    
    printf("\nMovimento do Cavalo:\n");
    moverCavalo(3, 3);
    
    return 0;
}
