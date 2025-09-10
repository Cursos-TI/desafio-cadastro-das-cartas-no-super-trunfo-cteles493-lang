#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

  #include <stdio.h>

int main() {
    // --- Variáveis para a Carta 1 ---
    char estado1;
    char codigoCarta1[5];
    char nomeCidade1[50];
    // REQUISITO: População agora é unsigned long int para acomodar números maiores
    unsigned long int populacao1;
    float area1;
    float pib1; // PIB em bilhões de reais
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    float superPoder1; // Novo atributo

    // --- Variáveis para a Carta 2 ---
    char estado2;
    char codigoCarta2[5];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;

    // --- Variáveis para armazenar o resultado das comparações ---
    // 1 significa que a Carta 1 venceu, 0 que a Carta 2 venceu.
    int vitoriaPopulacao;
    int vitoriaArea;
    int vitoriaPIB;
    int vitoriaPontosTuristicos;
    int vitoriaDensidade;
    int vitoriaPIBPerCapita;
    int vitoriaSuperPoder;

    // --- Leitura dos Dados da Carta 1 ---
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%s", codigoCarta1);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("Digite a Populacao: ");
    // REQUISITO: Usar %lu para ler unsigned long int
    scanf("%lu", &populacao1);
    printf("Digite a Area (em km2): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhoes de R$): ");
    scanf("%f", &pib1);
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // --- Leitura dos Dados da Carta 2 ---
    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o Codigo da Carta (ex: B02): ");
    scanf("%s", codigoCarta2);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("Digite a Populacao: ");
    scanf("%lu", &populacao2);
    printf("Digite a Area (em km2): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhoes de R$): ");
    scanf("%f", &pib2);
    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- Cálculos para a Carta 1 ---
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;
    // REQUISITO: Cálculo do Super Poder. Convertemos os inteiros para float para a soma.
    superPoder1 = (float)populacao1 + area1 + (pib1 * 1000000000) + (float)pontosTuristicos1 + pibPerCapita1 + (1.0 / densidadePopulacional1);

    // --- Cálculos para a Carta 2 ---
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;
    superPoder2 = (float)populacao2 + area2 + (pib2 * 1000000000) + (float)pontosTuristicos2 + pibPerCapita2 + (1.0 / densidadePopulacional2);

    // --- Comparação das Cartas (Batalha) ---
    // Para a maioria, o maior valor vence (Carta 1 > Carta 2 resulta em 1)
    vitoriaPopulacao = populacao1 > populacao2;
    vitoriaArea = area1 > area2;
    vitoriaPIB = pib1 > pib2;
    vitoriaPontosTuristicos = pontosTuristicos1 > pontosTuristicos2;
    vitoriaPIBPerCapita = pibPerCapita1 > pibPerCapita2;
    vitoriaSuperPoder = superPoder1 > superPoder2;
    // REQUISITO: Para densidade, o MENOR valor vence (Carta 1 < Carta 2 resulta em 1)
    vitoriaDensidade = densidadePopulacional1 < densidadePopulacional2;

    // --- Exibição dos Resultados da Batalha ---
    printf("\n\n---------------------------------------\n");
    printf("      RESULTADO DA BATALHA\n");
    printf("---------------------------------------\n");
    // Usamos um operador ternário para decidir qual número de carta (1 ou 2) imprimir
    printf("Populacao: Carta %d venceu (%d)\n", (vitoriaPopulacao ? 1 : 2), vitoriaPopulacao);
    printf("Area: Carta %d venceu (%d)\n", (vitoriaArea ? 1 : 2), vitoriaArea);
    printf("PIB: Carta %d venceu (%d)\n", (vitoriaPIB ? 1 : 2), vitoriaPIB);
    printf("Pontos Turisticos: Carta %d venceu (%d)\n", (vitoriaPontosTuristicos ? 1 : 2), vitoriaPontosTuristicos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", (vitoriaDensidade ? 1 : 2), vitoriaDensidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", (vitoriaPIBPerCapita ? 1 : 2), vitoriaPIBPerCapita);
    printf("Super Poder: Carta %d venceu (%d)\n", (vitoriaSuperPoder ? 1 : 2), vitoriaSuperPoder);

    return 0;
}