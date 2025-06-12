#include <stdio.h>

int main() {
    // ======= Declaração das variáveis das duas cartas =======
    char estado1[3], estado2[3];
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos1, pontos2;

    float densidade1, densidade2;
    float per_capita1, per_capita2;

    // ======= Entrada dos dados da Carta 1 =======
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (ex: SP): ");
    scanf(" %2s", estado1);
    printf("Código: ");
    scanf(" %3s", codigo1);
    printf("Cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("População: ");
    scanf("%d", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontos1);

    // ======= Entrada dos dados da Carta 2 =======
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (ex: RJ): ");
    scanf(" %2s", estado2);
    printf("Código: ");
    scanf(" %3s", codigo2);
    printf("Cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontos2);

    // ======= Cálculo da Densidade e PIB per Capita =======
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    per_capita1 = (pib1 * 1000000000) / populacao1;
    per_capita2 = (pib2 * 1000000000) / populacao2;

    // ======= Exibir os dados calculados =======
    printf("\n--- Carta 1 ---\n");
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", per_capita1);

    printf("\n--- Carta 2 ---\n");
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", per_capita2);

    // ======= Comparação de um atributo específico =======
    // Atributo escolhido: População

    printf("\n=== COMPARAÇÃO DE CARTAS (Atributo: População) ===\n");
    printf("Carta 1 - %s (%s): %d habitantes\n", cidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %d habitantes\n", cidade2, estado2, populacao2);

    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
