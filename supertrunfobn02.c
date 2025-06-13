#include <stdio.h>

#define TAM 10       // Tamanho do tabuleiro
#define NAVIO 3       // Valor que representa um navio
#define AGUA 0        // Valor que representa água
#define TAM_NAVIO 3   // Tamanho fixo dos navios

// ======================== FUNÇÕES AUXILIARES ======================== //

// Exibe o tabuleiro completo
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Valida se um navio está dentro dos limites
int dentroDosLimites(int linha, int coluna, char direcao) {
    if (direcao == 'H') return (coluna + TAM_NAVIO <= TAM);
    if (direcao == 'V') return (linha + TAM_NAVIO <= TAM);
    if (direcao == 'D') return (linha + TAM_NAVIO <= TAM && coluna + TAM_NAVIO <= TAM); // Diagonal ↘
    if (direcao == 'E') return (linha + TAM_NAVIO <= TAM && coluna - (TAM_NAVIO - 1) >= 0); // Diagonal ↙
    return 0;
}

// Verifica se a área está livre
int areaLivre(int tabuleiro[TAM][TAM], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha, c = coluna;
        if (direcao == 'H') c += i;
        else if (direcao == 'V') l += i;
        else if (direcao == 'D') { l += i; c += i; }
        else if (direcao == 'E') { l += i; c -= i; }

        if (tabuleiro[l][c] != AGUA) return 0;
    }
    return 1;
}

// Posiciona o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (direcao == 'H') tabuleiro[linha][coluna + i] = NAVIO;
        else if (direcao == 'V') tabuleiro[linha + i][coluna] = NAVIO;
        else if (direcao == 'D') tabuleiro[linha + i][coluna + i] = NAVIO;
        else if (direcao == 'E') tabuleiro[linha + i][coluna - i] = NAVIO;
    }
}
