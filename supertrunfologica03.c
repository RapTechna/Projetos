#include <stdio.h>
#include <string.h>

// Função auxiliar para imprimir o nome de um atributo
const char* nome_atributo(int opcao) {
    switch(opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Atributo Inválido";
    }
}

// Função para impedir que o jogador selecione o mesmo atributo duas vezes
void exibir_menu_filtrado(int excluido) {
    printf("Escolha um atributo para comparação:\n");
    for (int i = 1; i <= 5; i++) {
        if (i != excluido) {
            printf("%d - %s\n", i, nome_atributo(i));
        }
    }
}

int main() {
    // ======== Dados das cartas (pré-definidos) ========
    char pais1[30] = "Brasil", pais2[30] = "Argentina";
    int populacao1 = 213000000, populacao2 = 45100000;
    float area1 = 8515767.0, area2 = 2780400.0;
    float pib1 = 1.9, pib2 = 0.49; // PIB em trilhões USD
    int pontos1 = 70, pontos2 = 40;
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    int atributo1, atributo2;

    // ======== Escolha dos Atributos ========
    printf("====== SUPER TRUNFO - COMPARAÇÃO DE 2 ATRIBUTOS ======\n\n");

    // Primeiro atributo
    printf("Escolha o primeiro atributo:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    printf("Digite o número do primeiro atributo: ");
    scanf("%d", &atributo1);

    // Validação do primeiro atributo
    if (atributo1 < 1 || atributo1 > 5) {
        printf("Atributo inválido. Encerrando o programa.\n");
        return 1;
    }

    // Segundo atributo (exclui o primeiro do menu)
    printf("\nAgora escolha o segundo atributo (diferente do primeiro):\n");
    exibir_menu_filtrado(atributo1);
    printf("Digite o número do segundo atributo: ");
    scanf("%d", &atributo2);

    // Validação do segundo atributo
    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Atributo inválido ou repetido. Encerrando o programa.\n");
        return 1;
    }

    // ======== Lógica de Comparação ========
    float valor1_c1, valor2_c1, valor1_c2, valor2_c2;
    float soma1 = 0, soma2 = 0;

    // Função auxiliar para obter o valor correspondente de cada atributo
    for (int i = 1; i <= 2; i++) {
        int atual = (i == 1) ? atributo1 : atributo2;
        float v1 = 0, v2 = 0;

        switch (atual) {
            case 1: v1 = populacao1; v2 = populacao2; break;
            case 2: v1 = area1; v2 = area2; break;
            case 3: v1 = pib1; v2 = pib2; break;
            case 4: v1 = pontos1; v2 = pontos2; break;
            case 5: v1 = densidade1; v2 = densidade2; break;
            default: break;
        }

        // Exibição dos valores
        printf("\n--- Comparação: %s ---\n", nome_atributo(atual));
        printf("%s: %.2f\n", pais1, v1);
        printf("%s: %.2f\n", pais2, v2);

        // Regras de comparação
        int vitoria = 0;
        if (atual == 5) { // menor vence
            vitoria = (v1 < v2) ? 1 : (v2 < v1 ? 2 : 0);
        } else {
            vitoria = (v1 > v2) ? 1 : (v2 > v1 ? 2 : 0);
        }

        // Soma parcial
        soma1 += v1;
        soma2 += v2;

        // Resultado por atributo
        printf("Resultado: ");
        vitoria == 0 ? printf("Empate!\n") :
        vitoria == 1 ? printf("%s venceu neste atributo!\n", pais1) :
                       printf("%s venceu neste atributo!\n", pais2);

        // Armazena valores para soma final
        if (i == 1) { valor1_c1 = v1; valor1_c2 = v2; }
        else        { valor2_c1 = v1; valor2_c2 = v2; }
    }

    // ======== Resultado Final ========
    printf("\n====== RESULTADO FINAL ======\n");
    printf("%s - Soma dos atributos: %.2f (%.2f + %.2f)\n", pais1, soma1, valor1_c1, valor2_c1);
    printf("%s - Soma dos atributos: %.2f (%.2f + %.2f)\n", pais2, soma2, valor1_c2, valor2_c2);

    if (soma1 > soma2) {
        printf("Vencedor da rodada: %s!\n", pais1);
    } else if (soma2 > soma1) {
        printf("Vencedor da rodada: %s!\n", pais2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
