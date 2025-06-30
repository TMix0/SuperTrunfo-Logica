#include <stdio.h>

int main() {
    // Variáveis para o primeiro estado
    char estado1[20], codigo1[5], cidade1[20];
    int populacao1, pontosTuristicos1;
    float area1, pib1;
    
    // Variáveis para o segundo estado
    char estado2[20], codigo2[5], cidade2[20];
    int populacao2, pontosTuristicos2;
    float area2, pib2;
    
    // Variáveis calculadas
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;
    
    // Variáveis para a comparação
    int atributo1, atributo2;
    float valor1_1, valor1_2, valor2_1, valor2_2;
    float soma1, soma2;
    
    // Entrada dos dados do primeiro estado
    printf("=== CADASTRO PRIMEIRO ESTADO ===\n");
    printf("Nome do estado: ");
    scanf(" %[^\n]", estado1);
    printf("Codigo (2 letras): ");
    scanf(" %4s", codigo1);
    printf("Cidade capital: ");
    scanf(" %[^\n]", cidade1);
    printf("Populacao: ");
    scanf("%d", &populacao1);
    printf("Area (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhoes R$): ");
    scanf("%f", &pib1);
    printf("Pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);
    
    // Entrada dos dados do segundo estado
    printf("\n=== CADASTRO SEGUNDO ESTADO ===\n");
    printf("Nome do estado: ");
    scanf(" %[^\n]", estado2);
    printf("Codigo (2 letras): ");
    scanf(" %4s", codigo2);
    printf("Cidade capital: ");
    scanf(" %[^\n]", cidade2);
    printf("Populacao: ");
    scanf("%d", &populacao2);
    printf("Area (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhoes R$): ");
    scanf("%f", &pib2);
    printf("Pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);
    
    // Cálculos
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;
    
    // Menu de atributos
    printf("\n=== COMPARACAO ===\n");
    
    // Primeiro atributo
    printf("\nEscolha o PRIMEIRO atributo:\n");
    printf("1-Area | 2-Populacao | 3-PIB\n");
    printf("4-Pontos Turisticos | 5-Densidade | 6-PIB per capita\n");
    printf("Opcao: ");
    scanf("%d", &atributo1);
    
    // Validar primeiro atributo
    while(atributo1 < 1 || atributo1 > 6) {
        printf("Opcao invalida! Digite novamente: ");
        scanf("%d", &atributo1);
    }
    
    // Segundo atributo (diferente do primeiro)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    
    // Mostrar apenas opções disponíveis
    if(atributo1 != 1) printf("1-Area\n");
    if(atributo1 != 2) printf("2-Populacao\n");
    if(atributo1 != 3) printf("3-PIB\n");
    if(atributo1 != 4) printf("4-Pontos Turisticos\n");
    if(atributo1 != 5) printf("5-Densidade\n");
    if(atributo1 != 6) printf("6-PIB per capita\n");
    
    printf("Opcao: ");
    scanf("%d", &atributo2);
    
    // Validar segundo atributo
    while(atributo2 == atributo1 || atributo2 < 1 || atributo2 > 6) {
        printf("Opcao invalida! Digite novamente: ");
        scanf("%d", &atributo2);
    }
    
    // Determinar valores dos atributos para cada estado
    // Atributo 1
    switch(atributo1) {
        case 1:
            valor1_1 = area1;
            valor1_2 = area2;
            break;
        case 2:
            valor1_1 = populacao1;
            valor1_2 = populacao2;
            break;
        case 3:
            valor1_1 = pib1;
            valor1_2 = pib2;
            break;
        case 4:
            valor1_1 = pontosTuristicos1;
            valor1_2 = pontosTuristicos2;
            break;
        case 5:
            valor1_1 = densidade1;
            valor1_2 = densidade2;
            break;
        case 6:
            valor1_1 = pibPerCapita1;
            valor1_2 = pibPerCapita2;
            break;
    }
    
    // Atributo 2
    switch(atributo2) {
        case 1:
            valor2_1 = area1;
            valor2_2 = area2;
            break;
        case 2:
            valor2_1 = populacao1;
            valor2_2 = populacao2;
            break;
        case 3:
            valor2_1 = pib1;
            valor2_2 = pib2;
            break;
        case 4:
            valor2_1 = pontosTuristicos1;
            valor2_2 = pontosTuristicos2;
            break;
        case 5:
            valor2_1 = densidade1;
            valor2_2 = densidade2;
            break;
        case 6:
            valor2_1 = pibPerCapita1;
            valor2_2 = pibPerCapita2;
            break;
    }
    
    // Exibir comparação
    printf("\n=== RESULTADOS ===\n");
    
    // Comparar primeiro atributo
    printf("\nPRIMEIRO ATRIBUTO: ");
    switch(atributo1) {
        case 1: printf("AREA\n"); break;
        case 2: printf("POPULACAO\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("PONTOS TURISTICOS\n"); break;
        case 5: printf("DENSIDADE\n"); break;
        case 6: printf("PIB PER CAPITA\n"); break;
    }
    
    printf("%s: ", estado1);
    if(atributo1 == 2 || atributo1 == 4) printf("%.0f\n", valor1_1);
    else printf("%.2f\n", valor1_1);
    
    printf("%s: ", estado2);
    if(atributo1 == 2 || atributo1 == 4) printf("%.0f\n", valor1_2);
    else printf("%.2f\n", valor1_2);
    
    // Verificar vencedor do primeiro atributo
    if(atributo1 == 5) { // Densidade (menor vence)
        if(valor1_1 < valor1_2) printf("%s venceu!\n", estado1);
        else if(valor1_1 > valor1_2) printf("%s venceu!\n", estado2);
        else printf("Empate!\n");
    } else { // Demais atributos (maior vence)
        if(valor1_1 > valor1_2) printf("%s venceu!\n", estado1);
        else if(valor1_1 < valor1_2) printf("%s venceu!\n", estado2);
        else printf("Empate!\n");
    }
    
    // Comparar segundo atributo
    printf("\nSEGUNDO ATRIBUTO: ");
    switch(atributo2) {
        case 1: printf("AREA\n"); break;
        case 2: printf("POPULACAO\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("PONTOS TURISTICOS\n"); break;
        case 5: printf("DENSIDADE\n"); break;
        case 6: printf("PIB PER CAPITA\n"); break;
    }
    
    printf("%s: ", estado1);
    if(atributo2 == 2 || atributo2 == 4) printf("%.0f\n", valor2_1);
    else printf("%.2f\n", valor2_1);
    
    printf("%s: ", estado2);
    if(atributo2 == 2 || atributo2 == 4) printf("%.0f\n", valor2_2);
    else printf("%.2f\n", valor2_2);
    
    // Verificar vencedor do segundo atributo
    if(atributo2 == 5) { // Densidade (menor vence)
        if(valor2_1 < valor2_2) printf("%s venceu!\n", estado1);
        else if(valor2_1 > valor2_2) printf("%s venceu!\n", estado2);
        else printf("Empate!\n");
    } else { // Demais atributos (maior vence)
        if(valor2_1 > valor2_2) printf("%s venceu!\n", estado1);
        else if(valor2_1 < valor2_2) printf("%s venceu!\n", estado2);
        else printf("Empate!\n");
    }
    
    // Calcular soma (ajustando densidade)
    soma1 = (atributo1 == 5 ? -valor1_1 : valor1_1) + (atributo2 == 5 ? -valor2_1 : valor2_1);
    soma2 = (atributo1 == 5 ? -valor1_2 : valor1_2) + (atributo2 == 5 ? -valor2_2 : valor2_2);
    
    // Resultado final
    printf("\n=== RESULTADO FINAL ===\n");
    printf("Soma %s: %.2f\n", estado1, soma1);
    printf("Soma %s: %.2f\n", estado2, soma2);
    
    if(soma1 > soma2) printf("\n%s VENCEU O JOGO!\n", estado1);
    else if(soma1 < soma2) printf("\n%s VENCEU O JOGO!\n", estado2);
    else printf("\nEMPATE!\n");
    
    return 0;
}