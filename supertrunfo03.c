#include <stdio.h>

int main() {
    // ======= Declaração de variáveis =======
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2; // em bilhões
    int pontos1, pontos2;

    float densidade1, densidade2;
    float per_capita1, per_capita2;
    float poder1, poder2;

    // ======= Entrada - Carta 1 =======
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Código (ex: A01): ");
    scanf(" %3s", codigo1);

    printf("Cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Pontos turísticos: ");
    scanf("%d", &pontos1);

    // ======= Cálculos - Carta 1 =======
    densidade1 = populacao1 / area1;
    per_capita1 = (pib1 * 1000000000) / populacao1;
    poder1 = (float)populacao1 + area1 + (pib1 * 1000000000) + pontos1 + per_capita1 + (1 / densidade1);

    // ======= Entrada - Carta 2 =======
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Código (ex: B02): ");
    scanf(" %3s", codigo2);

    printf("Cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Pontos turísticos: ");
    scanf("%d", &pontos2);

    // ======= Cálculos - Carta 2 =======
    densidade2 = populacao2 / area2;
    per_capita2 = (pib2 * 1000000000) / populacao2;
    poder2 = (float)populacao2 + area2 + (pib2 * 1000000000) + pontos2 + per_capita2 + (1 / densidade2);

    // ======= Comparações =======
    int v_populacao     = populacao1 > populacao2;
    int v_area          = area1 > area2;
    int v_pib           = pib1 > pib2;
    int v_pontos        = pontos1 > pontos2;
    int v_densidade     = densidade1 < densidade2; // quanto menor, melhor
    int v_per_capita    = per_capita1 > per_capita2;
    int v_poder         = poder1 > poder2;

    // ======= Saída =======
    printf("\n\n=== COMPARAÇÃO DE CARTAS ===\n");
    printf("População: Carta 1 venceu (%d)\n", v_populacao);
    printf("Área: Carta 1 venceu (%d)\n", v_area);
    printf("PIB: Carta 1 venceu (%d)\n", v_pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", v_pontos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", v_densidade);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", v_per_capita);
    printf("Super Poder: Carta 1 venceu (%d)\n", v_poder);

    return 0;
}
