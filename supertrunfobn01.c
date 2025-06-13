#include <stdio.h>

// Tamanho do tabuleiro e dos navios
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Valor representativo
#define AGUA 0
#define NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para verificar se o navio está dentro dos limites
int validarLimites(int inicioLinha, int inicioColuna, char direcao) {
    if (direcao == 'H') {
        return (inicioColuna + TAM_NAVIO <= TAM_TABULEIRO);
    } else if (direcao == 'V') {
        return (inicioLinha + TAM_NAVIO <= TAM_TABULEIRO);
    }
    return 0;
}

// Função para verificar se a área está livre (sem sobreposição)
int areaLivre(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (direcao == 'H') {
            if (tabuleiro[linha][coluna + i] != AGUA)
                return 0;
        } else if (direcao == 'V') {
            if (tabuleiro[linha + i][coluna] != AGUA)
                return 0;
        }
    }
    return 1;
}

// Função para posicionar um navio
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (direcao == 'H') {
            tabuleiro[linha][coluna + i] = NAVIO;
        } else if (direcao == 'V') {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

int main() {
    // Inicializa o tabuleiro com água
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Coordenadas iniciais definidas no código
    int linhaNavio1 = 2, colunaNavio1 = 3; // horizontal
    int linhaNavio2 = 5, colunaNavio2 = 5; // vertical

    // Validar e posicionar primeiro navio (horizontal)
    if (validarLimites(linhaNavio1, colunaNavio1, 'H') && areaLivre(tabuleiro, linhaNavio1, colunaNavio1, 'H')) {
        posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, 'H');
    } else {
        printf("Erro: não foi possível posicionar o navio 1\n");
    }

    // Validar e posicionar segundo navio (vertical)
    if (validarLimites(linhaNavio2, colunaNavio2, 'V') && areaLivre(tabuleiro, linhaNavio2, colunaNavio2, 'V')) {
        posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, 'V');
    } else {
        printf("Erro: não foi possível posicionar o navio 2\n");
    }

    // Exibir o tabuleiro completo
    exibirTabuleiro(tabuleiro);

    return 0;
}
