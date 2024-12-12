#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 2
#define NUM_CIDADES 2

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Cidade;

void cadastrarCartas(Cidade cartas[NUM_ESTADOS][NUM_CIDADES], char estados[NUM_ESTADOS]) {
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            // Gerar código da cidade
            snprintf(cartas[i][j].codigo, sizeof(cartas[i][j].codigo), "%c%02d", estados[i], j + 1);

            // Solicitar informações ao usuário
            printf("\nCadastrando a cidade %s:\n", cartas[i][j].codigo);
            printf("Digite a populacao: ");
            scanf("%d", &cartas[i][j].populacao);

            printf("Digite a area (em km^2): ");
            scanf("%f", &cartas[i][j].area);

            printf("Digite o PIB (em bilhoes): ");
            scanf("%f", &cartas[i][j].pib);

            printf("Digite o numero de pontos turisticos: ");
            scanf("%d", &cartas[i][j].pontos_turisticos);
        }
    }
}

void compararCartas(Cidade carta1, Cidade carta2, char criterio) {
    printf("\nComparando cartas %s e %s pelo criterio '%c':\n", carta1.codigo, carta2.codigo, criterio);

    if (criterio == 'P') { // Comparação por população
        if (carta1.populacao > carta2.populacao)
            printf("Vencedora: %s (População: %d)\n", carta1.codigo, carta1.populacao);
        else
            printf("Vencedora: %s (População: %d)\n", carta2.codigo, carta2.populacao);
    } else if (criterio == 'A') { // Comparação por área
        if (carta1.area > carta2.area)
            printf("Vencedora: %s (Área: %.2f km^2)\n", carta1.codigo, carta1.area);
        else
            printf("Vencedora: %s (Área: %.2f km^2)\n", carta2.codigo, carta2.area);
    } else if (criterio == 'I') { // Comparação por PIB
        if (carta1.pib > carta2.pib)
            printf("Vencedora: %s (PIB: %.2f bilhões)\n", carta1.codigo, carta1.pib);
        else
            printf("Vencedora: %s (PIB: %.2f bilhões)\n", carta2.codigo, carta2.pib);
    } else if (criterio == 'D') { // Comparação por densidade populacional
        float dens1 = carta1.populacao / carta1.area;
        float dens2 = carta2.populacao / carta2.area;

        if (dens1 < dens2)
            printf("Vencedora: %s (Densidade: %.2f hab/km^2)\n", carta1.codigo, dens1);
        else
            printf("Vencedora: %s (Densidade: %.2f hab/km^2)\n", carta2.codigo, dens2);
    } else {
        printf("Criterio invalido!\n");
    }
}

int main() {
    Cidade cartas[NUM_ESTADOS][NUM_CIDADES];
    char estados[NUM_ESTADOS] = {'A', 'B'}; // Exemplo de estados: 'A' e 'B'

    // Cadastro das cartas
    cadastrarCartas(cartas, estados);

    // Comparação de duas cartas (exemplo: A1 e B1)
    compararCartas(cartas[0][0], cartas[1][0], 'P'); // Comparação por população
    compararCartas(cartas[0][0], cartas[1][0], 'D'); // Comparação por densidade populacional

    return 0;
}
