#include <stdio.h>

int main() {
    // ======= Torre: Move 5 casas para a direita (usando FOR) =======
    printf("=== Movimento da TORRE (5 casas para a direita) ===\n");

    for (int i = 1; i <= 5; i++) {
        printf("Direita (%d)\n", i); // Mostra a direção e o número da casa
    }

    // ======= Bispo: Move 5 casas na diagonal superior direita (usando WHILE) =======
    printf("\n=== Movimento do BISPO (5 casas na diagonal: cima e direita) ===\n");

    int j = 1;
    while (j <= 5) {
        printf("Cima Direita (%d)\n", j);
        j++;
    }

    // ======= Rainha: Move 8 casas para a esquerda (usando DO-WHILE) =======
    printf("\n=== Movimento da RAINHA (8 casas para a esquerda) ===\n");

    int k = 1;
    do {
        printf("Esquerda (%d)\n", k);
        k++;
    } while (k <= 8);

    return 0;
}
