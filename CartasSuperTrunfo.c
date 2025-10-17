#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para system("cls") ou system("clear")

/*
 ============================================================================
 Desafio: Super Trunfo - A Batalha Final (Nível Avançado)
 Linguagem: C
 Objetivo: Permitir que o jogador escolha dois atributos para comparar,
           utilizando menus dinâmicos (switch), tratando exceções e
           determinando o vencedor da rodada com base em um sistema de pontos.
 ============================================================================
*/

// Documentação: Estrutura para armazenar os dados de uma carta de país.
// Usamos 'long long int' para população para garantir que números grandes caibam.
// Usamos 'double' para maior precisão em valores decimais.
struct CartaSuperTrunfo {
    char pais[50];
    char codigo[5];
    long long int populacao;
    double area; // em km²
    double pib;  // em trilhões de USD
    double idh;  // Índice de Desenvolvimento Humano
    double densidadeDemografica; // Atributo calculado
};

// Protótipo da função para limpar a tela (melhora a usabilidade)
void limparTela();

int main() {
    // Declaração e inicialização das duas cartas para a batalha
    struct CartaSuperTrunfo carta1, carta2;

    // --- CADASTRO DA CARTA 1: BRASIL ---
    strcpy(carta1.pais, "Brasil");
    strcpy(carta1.codigo, "C1");
    carta1.populacao = 215300000;
    carta1.area = 8516000;
    carta1.pib = 1.609;
    carta1.idh = 0.759;

    // --- CADASTRO DA CARTA 2: JAPÃO ---
    strcpy(carta2.pais, "Japao");
    strcpy(carta2.codigo, "D2");
    carta2.populacao = 125700000;
    carta2.area = 377975;
    carta2.pib = 4.941;
    carta2.idh = 0.919;

    // --- CÁLCULO DE ATRIBUTOS DERIVADOS ---
    carta1.densidadeDemografica = carta1.populacao / carta1.area;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    // Usabilidade: Exibe os dados das cartas antes do início da rodada
    printf("====================================================\n");
    printf("        SUPER TRUNFO - DESAFIO FINAL\n");
    printf("====================================================\n\n");
    printf("Carta 1: %s\n", carta1.pais);
    printf("  Populacao: %lld\n", carta1.populacao);
    printf("  Area: %.0f km2\n", carta1.area);
    printf("  PIB: %.3f trilhoes USD\n", carta1.pib);
    printf("  IDH: %.3f\n", carta1.idh);
    printf("  Densidade Demografica: %.2f hab/km2\n\n", carta1.densidadeDemografica);

    printf("Carta 2: %s\n", carta2.pais);
    printf("  Populacao: %lld\n", carta2.populacao);
    printf("  Area: %.0f km2\n", carta2.area);
    printf("  PIB: %.3f trilhoes USD\n", carta2.pib);
    printf("  IDH: %.3f\n", carta2.idh);
    printf("  Densidade Demografica: %.2f hab/km2\n\n", carta2.densidadeDemografica);

    printf("Pressione Enter para iniciar a batalha...");
    getchar(); // Pausa o programa esperando a tecla Enter
    limparTela();

    // Variáveis para armazenar as escolhas do jogador e os valores comparados
    int escolha1 = 0, escolha2 = 0;
    char nomeAtributo1[30], nomeAtributo2[30];
    double valorCarta1_attr1, valorCarta2_attr1;
    double valorCarta1_attr2, valorCarta2_attr2;

    // --- MENU 1: ESCOLHA DO PRIMEIRO ATRIBUTO ---
    do {
        printf("====================================================\n");
        printf("          RODADA 1: Escolha o PRIMEIRO atributo\n");
        printf("====================================================\n");
        printf("1 - Populacao\n");
        printf("2 - Area (km2)\n");
        printf("3 - PIB (Trilhoes USD)\n");
        printf("4 - IDH\n");
        printf("5 - Densidade Demografica (menor vence)\n");
        printf("Sua escolha: ");
        scanf("%d", &escolha1);

        // Manutenibilidade: O 'switch' organiza a lógica de seleção de forma limpa.
        switch (escolha1) {
            case 1:
                strcpy(nomeAtributo1, "Populacao");
                valorCarta1_attr1 = (double)carta1.populacao; // Cast para double
                valorCarta2_attr1 = (double)carta2.populacao;
                break;
            case 2:
                strcpy(nomeAtributo1, "Area");
                valorCarta1_attr1 = carta1.area;
                valorCarta2_attr1 = carta2.area;
                break;
            case 3:
                strcpy(nomeAtributo1, "PIB");
                valorCarta1_attr1 = carta1.pib;
                valorCarta2_attr1 = carta2.pib;
                break;
            case 4:
                strcpy(nomeAtributo1, "IDH");
                valorCarta1_attr1 = carta1.idh;
                valorCarta2_attr1 = carta2.idh;
                break;
            case 5:
                strcpy(nomeAtributo1, "Densidade Demografica");
                valorCarta1_attr1 = carta1.densidadeDemografica;
                valorCarta2_attr1 = carta2.densidadeDemografica;
                break;
            // Confiabilidade: 'default' trata entradas inválidas.
            default:
                limparTela();
                printf("Opcao invalida! Por favor, escolha um numero entre 1 e 5.\n\n");
                escolha1 = 0; // Reseta a escolha para manter o loop
        }
    } while (escolha1 == 0);

    limparTela();

    // --- MENU 2: ESCOLHA DO SEGUNDO ATRIBUTO (DINÂMICO) ---
    do {
        printf("====================================================\n");
        printf("          RODADA 2: Escolha o SEGUNDO atributo\n");
        printf("====================================================\n");
        printf("Primeiro atributo escolhido: %s\n\n", nomeAtributo1);

        // Menus Dinâmicos: O 'if' impede que a opção já escolhida apareça.
        if (escolha1 != 1) printf("1 - Populacao\n");
        if (escolha1 != 2) printf("2 - Area (km2)\n");
        if (escolha1 != 3) printf("3 - PIB (Trilhoes USD)\n");
        if (escolha1 != 4) printf("4 - IDH\n");
        if (escolha1 != 5) printf("5 - Densidade Demografica (menor vence)\n");
        printf("Sua escolha: ");
        scanf("%d", &escolha2);

        // Confiabilidade: Garante que o jogador não escolha o mesmo atributo duas vezes.
        if (escolha2 == escolha1) {
            limparTela();
            printf("Erro! Voce nao pode escolher o mesmo atributo duas vezes.\n\n");
            escolha2 = 0; // Força a repetição do loop
        } else {
            switch (escolha2) {
                case 1:
                    strcpy(nomeAtributo2, "Populacao");
                    valorCarta1_attr2 = (double)carta1.populacao;
                    valorCarta2_attr2 = (double)carta2.populacao;
                    break;
                case 2:
                    strcpy(nomeAtributo2, "Area");
                    valorCarta1_attr2 = carta1.area;
                    valorCarta2_attr2 = carta2.area;
                    break;
                case 3:
                    strcpy(nomeAtributo2, "PIB");
                    valorCarta1_attr2 = carta1.pib;
                    valorCarta2_attr2 = carta2.pib;
                    break;
                case 4:
                    strcpy(nomeAtributo2, "IDH");
                    valorCarta1_attr2 = carta1.idh;
                    valorCarta2_attr2 = carta2.idh;
                    break;
                case 5:
                    strcpy(nomeAtributo2, "Densidade Demografica");
                    valorCarta1_attr2 = carta1.densidadeDemografica;
                    valorCarta2_attr2 = carta2.densidadeDemografica;
                    break;
                default:
                    limparTela();
                    printf("Opcao invalida! Por favor, escolha um dos atributos disponiveis.\n\n");
                    escolha2 = 0; // Reseta a escolha
            }
        }
    } while (escolha2 == 0);

    limparTela();

    // --- LÓGICA DE COMPARAÇÃO E RESULTADO ---
    int pontosCarta1 = 0;
    int pontosCarta2 = 0;

    // Comparação do Atributo 1
    if (escolha1 == 5) { // Regra especial para Densidade (menor vence)
        pontosCarta1 += (valorCarta1_attr1 < valorCarta2_attr1) ? 1 : 0;
        pontosCarta2 += (valorCarta2_attr1 < valorCarta1_attr1) ? 1 : 0;
    } else { // Regra geral (maior vence)
        // Operador Ternário: Forma concisa de um if-else para atribuir o ponto.
        pontosCarta1 += (valorCarta1_attr1 > valorCarta2_attr1) ? 1 : 0;
        pontosCarta2 += (valorCarta2_attr1 > valorCarta1_attr1) ? 1 : 0;
    }

    // Comparação do Atributo 2
    if (escolha2 == 5) { // Regra especial para Densidade
        pontosCarta1 += (valorCarta1_attr2 < valorCarta2_attr2) ? 1 : 0;
        pontosCarta2 += (valorCarta2_attr2 < valorCarta1_attr2) ? 1 : 0;
    } else { // Regra geral
        pontosCarta1 += (valorCarta1_attr2 > valorCarta2_attr2) ? 1 : 0;
        pontosCarta2 += (valorCarta2_attr2 > valorCarta1_attr2) ? 1 : 0;
    }
    
    // Usabilidade: A exibição do resultado é clara e detalhada.
    printf("====================================================\n");
    printf("                      RESULTADO\n");
    printf("====================================================\n\n");
    printf("           | %-20s | %-20s\n", carta1.pais, carta2.pais);
    printf("----------------------------------------------------\n");
    printf("Atributo 1: %-10s | %-20.2f | %-20.2f\n", nomeAtributo1, valorCarta1_attr1, valorCarta2_attr1);
    printf("Atributo 2: %-10s | %-20.2f | %-20.2f\n", nomeAtributo2, valorCarta1_attr2, valorCarta2_attr2);
    printf("----------------------------------------------------\n");
    printf("PONTUACAO FINAL      | %-20d | %-20d\n", pontosCarta1, pontosCarta2);
    printf("----------------------------------------------------\n\n");

    // Lógica final para determinar o vencedor da rodada
    if (pontosCarta1 > pontosCarta2) {
        printf("VENCEDOR DA RODADA: %s!\n", carta1.pais);
    } else if (pontosCarta2 > pontosCarta1) {
        printf("VENCEDOR DA RODADA: %s!\n", carta2.pais);
    } else {
        printf("RESULTADO DA RODADA: EMPATE!\n");
    }

    printf("\n====================================================\n");

    return 0;
}

// Função auxiliar para limpar a tela do console.
// Funciona tanto em Windows (cls) quanto em Linux/Mac (clear).
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}