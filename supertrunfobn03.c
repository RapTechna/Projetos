#include <stdio.h>
#include <stdlib.h>

#define TAM_TAB 10
#define TAM_HAB 5

// Tabuleiro principal
int tabuleiro[TAM_TAB][TAM_TAB];

// Matrizes das habilidades
int cone[TAM_HAB][TAM_HAB];
int cruz[TAM_HAB][TAM_HAB];
int octaedro[TAM_HAB][TAM_HAB];

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro() {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Simulação de navios (valor 3)
void posicionarNavios() {
    // Horizontal
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;
    tabuleiro[1][4] = 3;

    // Vertical
    tabuleiro[3][6] = 3;
    tabuleiro[4][6] = 3;
    tabuleiro[5][6] = 3;

    // Diagonal principal
    tabuleiro[6][0] = 3;
    tabuleiro[7][1] = 3;
    tabuleiro[8][2] = 3;

    // Diagonal secundária
    tabuleiro[6][9] = 3;
    tabuleiro[7][8] = 3;
    tabuleiro[8][7] = 3;
}

// Gera cone (expandindo para baixo)
void gerarCone(int m[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i))
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

// Gera cruz (linha e coluna centrais)
void gerarCruz(int m[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

// Gera octaedro (losango)
void gerarOctaedro(int m[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2)
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
}

// Aplica uma matriz de habilidade sobre o tabuleiro
void aplicarHabilidade(int m[TAM_HAB][TAM_HAB], int centroLinha, int centroColuna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = centroLinha - TAM_HAB / 2 + i;
            int coluna = centroColuna - TAM_HAB / 2 + j;

            // Validação de limite
            if (linha >= 0 && linha < TAM_TAB && coluna >= 0 && coluna < TAM_TAB) {
                if (m[i][j] == 1 && tabuleiro[linha][coluna] != 3) {
                    tabuleiro[linha][coluna] = 5; // Marca área afetada
                }
            }
        }
    }
}

// Exibe o tabuleiro no console
void exibirTabuleiro() {
    printf("=== TABULEIRO ===\n\n");
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    inicializarTabuleiro();
    posicionarNavios();

    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    aplicarHabilidade(cone, 2, 5);      // Aplica cone no centro superior
    aplicarHabilidade(cruz, 5, 5);      // Aplica cruz no meio do tabuleiro
    aplicarHabilidade(octaedro, 7, 3);  // Aplica octaedro na parte inferior esquerda

    exibirTabuleiro();

    return 0;
}
