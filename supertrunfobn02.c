#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

#define AGUA 0
#define NAVIO 3

// Inicializa o tabuleiro com zeros (água)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Verifica se a posição está livre para o navio (sem sobreposição)
int areaLivre(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        switch (direcao) {
            case 'H':
                if (tabuleiro[linha][coluna + i] != AGUA) return 0;
                break;
            case 'V':
                if (tabuleiro[linha + i][coluna] != AGUA) return 0;
                break;
            case 'D': // Diagonal principal (↘)
                if (tabuleiro[linha + i][coluna + i] != AGUA) return 0;
                break;
            case 'I': // Diagonal inversa (↙)
                if (tabuleiro[linha + i][coluna - i] != AGUA) return 0;
                break;
        }
    }
    return 1;
}

// Posiciona o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        switch (direcao) {
            case 'H':
                tabuleiro[linha][coluna + i] = NAVIO;
                break;
            case 'V':
                tabuleiro[linha + i][coluna] = NAVIO;
                break;
            case 'D': // Diagonal principal (↘)
                tabuleiro[linha + i][coluna + i] = NAVIO;
                break;
            case 'I': // Diagonal inversa (↙)
                tabuleiro[linha + i][coluna - i] = NAVIO;
                break;
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Definições de navios (linha, coluna, direção)
    int linha1 = 1, coluna1 = 2;     // horizontal
    int linha2 = 5, coluna2 = 5;     // vertical
    int linha3 = 0, coluna3 = 0;     // diagonal principal (↘)
    int linha4 = 0, coluna4 = 9;     // diagonal inversa (↙)

    // Validações e posicionamentos
    if (coluna1 + TAM_NAVIO <= TAM_TABULEIRO && areaLivre(tabuleiro, linha1, coluna1, 'H'))
        posicionarNavio(tabuleiro, linha1, coluna1, 'H');
    else printf("Erro ao posicionar navio 1\n");

    if (linha2 + TAM_NAVIO <= TAM_TABULEIRO && areaLivre(tabuleiro, linha2, coluna2, 'V'))
        posicionarNavio(tabuleiro, linha2, coluna2, 'V');
    else printf("Erro ao posicionar navio 2\n");

    if (linha3 + TAM_NAVIO <= TAM_TABULEIRO && coluna3 + TAM_NAVIO <= TAM_TABULEIRO && areaLivre(tabuleiro, linha3, coluna3, 'D'))
        posicionarNavio(tabuleiro, linha3, coluna3, 'D');
    else printf("Erro ao posicionar navio 3 (diagonal principal)\n");

    if (linha4 + TAM_NAVIO <= TAM_TABULEIRO && coluna4 - (TAM_NAVIO - 1) >= 0 && areaLivre(tabuleiro, linha4, coluna4, 'I'))
        posicionarNavio(tabuleiro, linha4, coluna4, 'I');
    else printf("Erro ao posicionar navio 4 (diagonal inversa)\n");

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
