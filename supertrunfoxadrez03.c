#include <stdio.h>

#define MOV_TORRE 5
#define MOV_BISPO 5
#define MOV_RAINHA 8

// ---------- FUNÇÕES RECURSIVAS ----------

// TORRE: movimento para a direita
void moverTorre(int passo) {
    if (passo > 0) {
        printf("Direita (%d)\n", passo);
        moverTorre(passo - 1);
    }
}

// BISPO: recursividade + loops aninhados
void moverBispoRec(int passo) {
    if (passo > 0) {
        printf("Cima Direita (%d)\n", passo);
        moverBispoRec(passo - 1);
    }
}

void moverBispoComLoops(int casas) {
    for (int i = 1; i <= casas; i++) {           
        for (int j = 1; j <= 1; j++) {             
            printf("Cima Direita (%d)\n", i);
        }
    }
}

// RAINHA: movimento para a esquerda
void moverRainha(int passo) {
    if (passo > 0) {
        printf("Esquerda (%d)\n", passo);
        moverRainha(passo - 1);
    }
}

// ---------- FUNÇÃO COM LOOPS ANINHADOS ----------

// CAVALO: 2 casas cima + 1 direita
void moverCavalo() {
    printf("=== Movimento do CAVALO (em L: 2 casas para cima, 1 para direita) ===\n");

    int cima = 0;
    int direita = 0;

    for (int i = 0; i < 3; i++) {
        if (i < 2) {
            
            cima++;
            if (cima == 1 || cima == 2) {
                printf("Cima (%d)\n", cima);
            }
        } else {
            
            while (direita < 1) {
                direita++;
                if (direita == 1) {
                    printf("Direita (%d)\n", direita);
                    break;
                }
            }
        }

        
        if (cima < 0 || direita < 0) {
            continue;
        }
    }
}

int main() {
    // ================= TORRE =================
    printf("=== Movimento da TORRE (5 casas para a direita) ===\n");
    moverTorre(MOV_TORRE);

    // ================= BISPO (Recursividade) =================
    printf("\n=== Movimento do BISPO (5 casas na diagonal - recursividade) ===\n");
    moverBispoRec(MOV_BISPO);

    // ================= BISPO (Loops Aninhados) =================
    printf("\n=== Movimento do BISPO (loops aninhados) ===\n");
    moverBispoComLoops(MOV_BISPO);

    // ================= RAINHA =================
    printf("\n=== Movimento da RAINHA (8 casas para a esquerda) ===\n");
    moverRainha(MOV_RAINHA);

    // ================= CAVALO =================
    printf("\n");
    moverCavalo();

    return 0;
}
