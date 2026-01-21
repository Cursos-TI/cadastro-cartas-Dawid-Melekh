#include <stdio.h>

typedef struct
{
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

int main()
{
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

        printf("PIB: ");
        scanf("%f", &cartas[i].pib);

        printf("Números de Pontos Tuísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);
    }

    return 0;
}
