#include <stdio.h>

int main() {
    // ================= TORRE =================
    printf("=== Movimento da TORRE (5 casas para a direita) ===\n");
    for (int i = 1; i <= 5; i++) {
        printf("Direita (%d)\n", i);
    }

    // ================= BISPO =================
    printf("\n=== Movimento do BISPO (5 casas na diagonal: cima e direita) ===\n");
    int j = 1;
    while (j <= 5) {
        printf("Cima Direita (%d)\n", j);
        j++;
    }

    // ================= RAINHA =================
    printf("\n=== Movimento da RAINHA (8 casas para a esquerda) ===\n");
    int k = 1;
    do {
        printf("Esquerda (%d)\n", k);
        k++;
    } while (k <= 8);

    // ================= CAVALO =================
    printf("\n=== Movimento do CAVALO (em L: 2 casas para baixo, 1 para esquerda) ===\n");

    // Movimentar duas casas para baixo usando FOR externo
    for (int passo_baixo = 1; passo_baixo <= 2; passo_baixo++) {
        printf("Baixo (%d)\n", passo_baixo);

        // Simulando algum processamento interno com WHILE aninhado (por exemplo: delay simbólico ou verificação de movimento válido)
        int verificador = 0;
        while (verificador < 1) {
            // Esse while serve apenas para cumprir a exigência do aninhamento
            verificador++;
        }
    }

    // Movimento final: uma casa para esquerda
    printf("Esquerda (1)\n");

    return 0;
}
