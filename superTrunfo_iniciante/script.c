#include <stdio.h>

struct Carta
{
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

int main()
{
    struct Carta cartas[32];
    int indice = 0;

    //percorre cada estado para por as letras de "A a "H"
    for (char estado = 'A'; estado <= 'H'; estado++)
    {
        for (int cidade = 1; cidade <= 4; cidade++)
        {
            // cria o código da carta ex (A01)
            sprintf(cartas[indice].codigo, "%c%02d", estado, cidade);

            printf("\n========== CADASTRO DA CARTA %s ==========\n", cartas[indice].codigo);

            // recebe do usúario a quantidade da população
            printf("\nPopulação: ");
            scanf("%d", &cartas[indice].populacao);

            // recebe do usúario o tamanho da área
            printf("Área: ");
            scanf("%f", &cartas[indice].area);

            printf("PIB: ");
            scanf("%f", &cartas[indice].pib);

            printf("Pontos Turísticos: ");
            scanf("%d", &cartas[indice].pontosTuristicos);

            indice++;
        }
    }

    // SAIDA DOS DADOS CADASTRADOS DAS CARTAS

    printf("\n========== CARTAS CADASTRADAS ==========\n");

    //mostras as 32 cartas cadastradas
    for (int i = 0; i < 32; i++)
    {
        printf("\n========= Carta %s =========\n", cartas[i].codigo);
        printf("\n População: %d\n----------------------", cartas[i].populacao);
        printf("\n Área: %.2f\n----------------------", cartas[i].area);
        printf("\n PIB: %.2f\n----------------------", cartas[i].pib);
        printf("\n Pontos Turísticos: %d\n----------------------", cartas[i].pontosTuristicos);
    }

    return 0;
}
