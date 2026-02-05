#include <stdio.h>

struct Carta
{
    char codigo[4];
    int populacao;
    float area;
    float pib;
    long int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

int main()
{
    struct Carta cartas[32];
    int indice = 0;

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
            scanf("%ld", &cartas[indice].pontosTuristicos);

            //incrementa o indice, garantindo que sempre que o for percorrer o codigo o indice aumente mais 1
            indice++;
        }
    }

    // SAIDA DOS DADOS CADASTRADOS DAS CARTAS

    printf("\n========== CARTAS CADASTRADAS ==========\n");

    for (int i = 0; i < 32; i++)
    {
        //caluculo da densidade populaciona e do PIB PER CAPITA
        cartas[i].densidadePopulacional = (float)cartas[i].populacao / cartas[i].area;
        cartas[i].pibPerCapita = cartas[i].pib / cartas[i].populacao;
        
        //exibição dos dados das cartas
        printf("\n========= Carta %s =========\n", cartas[i].codigo);
        printf("\n População: %d\n----------------------", cartas[i].populacao);
        printf("\n Área: %.2f\n----------------------", cartas[i].area);
        printf("\n PIB: %.2f\n----------------------", cartas[i].pib);
        printf("\n Pontos Turísticos: %ld\n----------------------", cartas[i].pontosTuristicos);
        printf("\nDensidade Populacional: %.2f\n----------------------", cartas[i].densidadePopulacional);
        printf("\nPIB PER CAPITA: %.2f\n----------------------", cartas[i].pibPerCapita);
    }

    return 0;
}
