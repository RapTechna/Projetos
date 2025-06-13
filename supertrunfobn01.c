#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para exibir o tabuleiro na tela
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n=== TABULEIRO ===\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declaração da matriz do tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicialização do tabuleiro com 0 (água)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Coordenadas iniciais fixas dos navios
    int linhaNavioH = 2;  // Navio horizontal começa na linha 2
    int colunaNavioH = 4; // e coluna 4

    int linhaNavioV = 5;  // Navio vertical começa na linha 5
    int colunaNavioV = 1; // e coluna 1

    // Posicionando NAVIO HORIZONTAL (tamanho 3)
    if (colunaNavioH + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaNavioH][colunaNavioH + i] = VALOR_NAVIO;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 1;
    }

    // Posicionando NAVIO VERTICAL (tamanho 3)
    int sobreposicao = 0;

    if (linhaNavioV + TAM_NAVIO <= TAM_TABULEIRO) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            // Verifica se já existe um navio na posição
            if (tabuleiro[linhaNavioV + i][colunaNavioV] == VALOR_NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (sobreposicao) {
            printf("Erro: navios não podem se sobrepor!\n");
            return 1;
        } else {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaNavioV + i][colunaNavioV] = VALOR_NAVIO;
            }
        }

    } else {
        printf("Erro: navio vertical fora dos limites!\n");
        return 1;
    }

    // Exibe o tabuleiro após o posicionamento dos navios
    exibirTabuleiro(tabuleiro);

    return 0;
}
