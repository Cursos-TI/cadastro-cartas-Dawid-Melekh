
// Inclusão das bibliotecas padrão de entrada/saída e manipulação de strings
#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do jogo
struct Carta
{
    char codigo[4];              // Código identificador da carta (ex: A01)
    long long int populacao;     // População da cidade/estado
    float area;                  // Área da cidade/estado
    float pib;                   // PIB da cidade/estado
    long int pontosTuristicos;   // Pontos turísticos
    float densidadePopulacional; // Densidade populacional
    float pibPerCapita;          // PIB per capita
    double superPoder;           // Valor do super poder da carta
};

int main()
{
    // Vetor para armazenar até 32 cartas
    struct Carta cartas[32];
    int indice = 0; // Índice para controle do vetor de cartas

    // Loop para cadastrar as cartas (8 estados x 4 cidades = 32 cartas)
    for (char estado = 'A'; estado <= 'H'; estado++)
    {
        for (int cidade = 1; cidade <= 4; cidade++)
        {

            // Cria o código da carta, ex: A01, B03, etc.
            sprintf(cartas[indice].codigo, "%c%02d", estado, cidade);

            printf("\n========== CADASTRO DA CARTA %s ==========\n", cartas[indice].codigo);

            // Recebe do usuário a quantidade da população
            printf("\nPopulação: ");
            while (scanf("%lld", &cartas[indice].populacao) != 1 || cartas[indice].populacao <= 0)
            {
                printf("Valor inválido! Digite novamente: ");
                while (getchar() != '\n')
                    ; // Limpa o buffer
            }

            // Recebe do usuário o tamanho da área
            printf("Área: ");
            while (scanf("%f", &cartas[indice].area) != 1 || cartas[indice].area <= 0)
            {
                printf("Valor inválido! Digite novamente: ");
                while (getchar() != '\n')
                    ;
            }

            // Recebe do usuário o PIB
            printf("PIB: ");
            while (scanf("%f", &cartas[indice].pib) != 1 || cartas[indice].pib <= 0)
            {
                printf("Valor inválido! Digite novamente: ");
                while (getchar() != '\n')
                    ;
            }

            // Recebe do usuário a quantidade de pontos turísticos
            printf("Pontos Turísticos: ");
            while (scanf("%ld", &cartas[indice].pontosTuristicos) != 1 || cartas[indice].pontosTuristicos <= 0)
            {
                printf("Valor inválido! Digite novamente: ");
                while (getchar() != '\n')
                    ;
            }

            // Verifica se a população não é 0 para evitar divisão por zero
            if (cartas[indice].populacao > 0)
            {
                // Se a população for maior que 0, faz o cálculo do PIB per capita
                cartas[indice].pibPerCapita = cartas[indice].pib / cartas[indice].populacao;
            }
            else
            {
                // Se a população for menor ou igual a 0, PIB per capita recebe 0
                cartas[indice].pibPerCapita = 0;
            }

            // Calcula a densidade populacional se a área for maior que 0
            if (cartas[indice].area > 0)
            {
                cartas[indice].densidadePopulacional = cartas[indice].populacao / cartas[indice].area;
            }
            else
            {
                cartas[indice].densidadePopulacional = 0;
            }

            // Cálculo do super poder da carta
            cartas[indice].superPoder =
                cartas[indice].populacao +
                cartas[indice].pib +
                cartas[indice].pontosTuristicos -
                cartas[indice].densidadePopulacional;

            indice++; // Avança para a próxima carta
        }
    }

    // Exibe os dados cadastrados das cartas
    printf("\n========== CARTAS CADASTRADAS ==========\n");

    for (int i = 0; i < indice; i++)
    {
        // Exibe os dados da carta
        printf("\n========= Carta %s =========\n", cartas[i].codigo);
        printf("\n População: %lld\n----------------------", cartas[i].populacao);
        printf("\n Área: %.2f\n----------------------", cartas[i].area);
        printf("\n PIB: %.2f\n----------------------", cartas[i].pib);
        printf("\n Pontos Turísticos: %ld\n----------------------", cartas[i].pontosTuristicos);
        printf("\nDensidade Populacional: %.2f\n----------------------", cartas[i].densidadePopulacional);
        printf("\nPIB PER CAPITA: %.2f\n----------------------", cartas[i].pibPerCapita);
        printf("\n Poder da Carta: %.2lf\n", cartas[i].superPoder);
    }

    // Variáveis para armazenar os códigos das cartas escolhidas pelo usuário
    char carta1[4], carta2[4];
    int cartaEscolhida1 = -1, cartaEscolhida2 = -1;

    // Solicita ao usuário que escolha duas cartas para a batalha
    printf("Escolha a primeira carta (ex: A01): ");
    scanf("%3s", carta1);
    printf("Escolha a segunda carta (ex: B02): ");
    scanf("%3s", carta2);

    // Procura os índices das cartas escolhidas
    for (int i = 0; i < indice; i++)
    {
        if (strcmp(cartas[i].codigo, carta1) == 0)
        {
            cartaEscolhida1 = i;
        }

        if (strcmp(cartas[i].codigo, carta2) == 0)
        {
            cartaEscolhida2 = i;
        }
    }

    // Verifica se as cartas escolhidas são válidas
    if (cartaEscolhida1 == -1 || cartaEscolhida2 == -1)
    {
        printf("Carta inválida!\n");
        return 0;
    }

    // Cria variáveis para facilitar a comparação entre as cartas escolhidas
    struct Carta c1 = cartas[cartaEscolhida1];
    struct Carta c2 = cartas[cartaEscolhida2];

    /* ================== COMPARAÇÕES ================== */
    printf("\n========== BATALHA DAS CARTAS ==========\n");
    printf("Carta %s  VS  Carta %s\n", c1.codigo, c2.codigo);

    // Contadores de vitórias
    int pontos1 = 0, pontos2 = 0;

    // Densidade Populacional: MENOR vence
    printf("\n--- Densidade Populacional (MENOR VENCE) ---\n");
    printf("%s: %.2f  |  %s: %.2f\n", c1.codigo, c1.densidadePopulacional, c2.codigo, c2.densidadePopulacional);
    if (c1.densidadePopulacional < c2.densidadePopulacional)
    {
        printf("Vencedora: %s (+1 ponto)\n", c1.codigo);
        pontos1++;
    }
    else if (c2.densidadePopulacional < c1.densidadePopulacional)
    {
        printf("Vencedora: %s (+1 ponto)\n", c2.codigo);
        pontos2++;
    }
    else
        printf("Empate!\n");

    // População: MAIOR vence
    printf("\n--- População (MAIOR VENCE) ---\n");
    printf("%s: %lld  |  %s: %lld\n", c1.codigo, c1.populacao, c2.codigo, c2.populacao);
    if (c1.populacao > c2.populacao)
    {
        printf("Vencedora: %s (+1 ponto)\n", c1.codigo);
        pontos1++;
    }
    else if (c2.populacao > c1.populacao)
    {
        printf("Vencedora: %s (+1 ponto)\n", c2.codigo);
        pontos2++;
    }
    else
        printf("Empate!\n");

    // Área: MAIOR vence
    printf("\n--- Área (MAIOR VENCE) ---\n");
    printf("%s: %.2f  |  %s: %.2f\n", c1.codigo, c1.area, c2.codigo, c2.area);
    if (c1.area > c2.area)
    {
        printf("Vencedora: %s (+1 ponto)\n", c1.codigo);
        pontos1++;
        printf("precione qualquer tecla para continuar");
        scanf("");
    }
    else if (c2.area > c1.area)
    {
        printf("Vencedora: %s (+1 ponto)\n", c2.codigo);
        pontos2++;
        printf("precione qualquer tecla para continuar");
        scanf("");
    }
    else
        printf("Empate!\n");

    // PIB: MAIOR vence
    printf("\n--- PIB (MAIOR VENCE) ---\n");
    printf("%s: %.2f  |  %s: %.2f\n", c1.codigo, c1.pib, c2.codigo, c2.pib);
    if (c1.pib > c2.pib)
    {
        printf("Vencedora: %s (+1 ponto)\n", c1.codigo);
        pontos1++;
        printf("precione qualquer tecla para continuar");
        scanf("");
    }
    else if (c2.pib > c1.pib)
    {
        printf("Vencedora: %s (+1 ponto)\n", c2.codigo);
        pontos2++;
        printf("precione qualquer tecla para continuar");
        scanf("");
    }
    else
        printf("Empate!\n");

    // Pontos Turísticos: MAIOR vence
    printf("\n--- Pontos Turísticos (MAIOR VENCE) ---\n");
    printf("%s: %ld  |  %s: %ld\n", c1.codigo, c1.pontosTuristicos, c2.codigo, c2.pontosTuristicos);
    if (c1.pontosTuristicos > c2.pontosTuristicos)
    {
        printf("Vencedora: %s (+1 ponto)\n", c1.codigo);
        pontos1++;
        printf("precione qualquer tecla para continuar");
        scanf("");
    }
    else if (c2.pontosTuristicos > c1.pontosTuristicos)
    {
        printf("Vencedora: %s (+1 ponto)\n", c2.codigo);
        pontos2++;
        printf("precione qualquer tecla para continuar");
        scanf("");
    }
    else
        printf("Empate!\n");

    // PIB per Capita: MAIOR vence
    printf("\n--- PIB per Capita (MAIOR VENCE) ---\n");
    printf("%s: %.2f  |  %s: %.2f\n", c1.codigo, c1.pibPerCapita, c2.codigo, c2.pibPerCapita);
    if (c1.pibPerCapita > c2.pibPerCapita)
    {
        printf("Vencedora: %s (+1 ponto)\n", c1.codigo);
        pontos1++;
        printf("precione qualquer tecla para continuar");
        scanf("");
    }
    else if (c2.pibPerCapita > c1.pibPerCapita)
    {
        printf("Vencedora: %s (+1 ponto)\n", c2.codigo);
        pontos2++;
        printf("precione qualquer tecla para continuar");
        scanf("");
    }
    else
        printf("Empate!\n");

    // Super Poder: MAIOR vence
    printf("\n--- Super Poder (MAIOR VENCE) ---\n");
    printf("%s: %.2lf  |  %s: %.2lf\n", c1.codigo, c1.superPoder, c2.codigo, c2.superPoder);
    if (c1.superPoder > c2.superPoder)
    {
        printf("Vencedora: %s (+1 ponto)\n", c1.codigo);
        pontos1++;
        printf("precione qualquer tecla para continuar");
        scanf("");
    }
    else if (c2.superPoder > c1.superPoder)
    {
        printf("Vencedora: %s (+1 ponto)\n", c2.codigo);
        pontos2++;
        printf("precione qualquer tecla para continuar");
        scanf("");
    }
    else
        printf("Empate!\n");

    // Resultado final
    printf("\n========== RESULTADO FINAL ==========\n");
    printf("Carta %s: %d pontos\n", c1.codigo, pontos1);
    printf("Carta %s: %d pontos\n", c2.codigo, pontos2);
    printf("\n");

    if (pontos1 > pontos2)
        printf("A CARTA VENCEDORA E: %s com %d pontos!\n", c1.codigo, pontos1);
    else if (pontos2 > pontos1)
        printf("A CARTA VENCEDORA E: %s com %d pontos!\n", c2.codigo, pontos2);
    else
        printf("EMPATE! Ambas as cartas ficaram com %d pontos!\n", pontos1);

    return 0;
}