#include <stdio.h>

typedef struct
{
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;

} Carta;

int main()
{
    // ==== CADASTRO DE CARTAS ====
    Carta cartas[32];
    int i;

    for (i = 0; i < 32; i++)
    {
        // a cada 4 cidades pula pro próximo estado
        int estadoIndex = i / 4;
        // pega o resto da divisão, e começa no 0 e vai até o 3 de tipo, cidade 0,1,2,3
        int cidadeIndex = i % 4;
        // recebe a letra de tipo, estado A01,A02
        char estado = 'A' + estadoIndex;
        // recebe o numero da cidade
        int numeroCidade = cidadeIndex + 1;

        // gera o codigo da cidade
        sprintf(cartas[i].codigo, "%c%02d", estado, numeroCidade);

        printf("\nCadastro da carta %s\n", cartas[i].codigo);

        printf("População: ");
        scanf("%d", &cartas[i].populacao);

        printf("Aréa: ");
        scanf("%f", &cartas[i].area);

        if (cartas[i].area > 0)
        {
            cartas[i].densidade = cartas[i].populacao / cartas[i].area;
        }
        else
        {
            cartas[i].densidade = 0;
        }

        printf("PIB: ");
        scanf("%f", &cartas[i].pib);

        if (cartas[i].pib > 0 && cartas[i].populacao > 0)
        {
            cartas[i].pibPerCapita = cartas[i].pib / cartas[i].populacao;
        }
        else
        {
            cartas[i].pibPerCapita = 0;
        }
        printf("Números de Pontos Tuísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);
    }

    printf("-------------------\n cartas super trunfo \n--------------------");

    for (i = 0; i < 32; i++)

    {
        printf("Carta %s:\n", cartas[i].codigo);
        printf(" População: %d\n", cartas[i].populacao);
        printf("  Área: %.2f\n", cartas[i].area);
        printf("  Pontos Turísticos: %d\n", cartas[i].pontosTuristicos);
        printf("  PIB: %.2f\n", cartas[i].pib);
        printf("  Densidade Populacional: %.2f hab/km^2\n", cartas[i].densidade);
        printf("  PIB per Capita: %.2f\n", cartas[i].pibPerCapita);
        printf("--------------------------------------\n");
    }

    return 0;
}
