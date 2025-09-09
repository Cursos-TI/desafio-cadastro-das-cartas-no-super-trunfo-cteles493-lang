#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

  #include <stdio.h>

int main() {
    // --- Variáveis para a Carta 1 ---
    char estadoCarta1;
    char codigoCarta1[5]; 
    char nomeCidade1[50];
    int populacaoCarta1;
    float areaCarta1;
    float pibCarta1;
    int pontosTuristicos1;

    // --- Variáveis para a Carta 2 ---
    char estadoCarta2;
    char codigoCarta2[5];
    char nomeCidade2[50];
    int populacaoCarta2;
    float areaCarta2;
    float pibCarta2;
    int pontosTuristicos2;

    // =================================================================
    // CADASTRO DA CARTA 1
    // =================================================================
    printf("--- CADASTRO DA CARTA 1 ---\n");
    printf("Digite o Estado (uma letra de 'A' a 'H'): ");
    
    scanf(" %c", &estadoCarta1);

    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf("%s", codigoCarta1);

    printf("Digite o Nome da Cidade: ");
    
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a Populacao da cidade: ");
    scanf("%d", &populacaoCarta1);

    printf("Digite a Area (em km2): ");
    scanf("%f", &areaCarta1);

    printf("Digite o PIB da cidade (em bilhoes): ");
    scanf("%f", &pibCarta1);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);
    printf("\n"); 

    // =================================================================
    // CADASTRO DA CARTA 2
    // =================================================================
    printf("--- CADASTRO DA CARTA 2 ---\n");
    printf("Digite o Estado (uma letra de 'A' a 'H'): ");
    scanf(" %c", &estadoCarta2);

    printf("Digite o Codigo da Carta (ex: B02): ");
    scanf("%s", codigoCarta2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a Populacao da cidade: ");
    scanf("%d", &populacaoCarta2);

    printf("Digite a Area (em km2): ");
    scanf("%f", &areaCarta2);

    printf("Digite o PIB da cidade (em bilhoes): ");
    scanf("%f", &pibCarta2);

    printf("Digite o Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);
    printf("\n"); 

    // =================================================================
    // CARTAS CADASTRADAS
    // =================================================================
    printf("----------------------------------------\n");
    printf("    CARTAS CADASTRADAS NO SISTEMA\n");
    printf("----------------------------------------\n\n");

    
    printf("CARTA 1:\n");
    printf("Estado: %c\n", estadoCarta1);
    printf("Codigo: %s\n", codigoCarta1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacaoCarta1);
    
    printf("Area: %.2f km2\n", areaCarta1);
    printf("PIB: %.2f bilhoes de reais\n", pibCarta1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("\n"); // Linha em branco para separar as cartas

    printf("CARTA 2:\n");
    printf("Estado: %c\n", estadoCarta2);
    printf("Codigo: %s\n", codigoCarta2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacaoCarta2);
    printf("Area: %.2f km2\n", areaCarta2);
    printf("PIB: %.2f bilhoes de reais\n", pibCarta2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);

    return 0; 
}