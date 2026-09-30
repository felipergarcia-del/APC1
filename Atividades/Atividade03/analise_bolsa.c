/*Eu montei meu código com algumas coisas a mais que o senhor não requisitou e coloquei até mais fotos de teste para mostrar para você.
Em relação à pergunta que o senhor fez, eu acabei usando o operador ternário uma vez para o sistema de aprovação, porque foi um jeito que
eu pensei para resolver ele. Não usei em nenhum outro lugar, mesmo vendo que tem alguns lugares em que seria possível, mas eu acho mais fácil
a leitura do código quando ela está aninhada.*/

#include <stdio.h>

int main(){

    char nome_aluno[50], status_pontualidade, faixa_social;
    int idade_aluno, status_bolsa;
    float media_academica, renda_familiar, desconto_base, bonus_pontual, desconto_total;

    // NOME DO ALUNO
    printf("Qual é seu nome? ");
    fgets(nome_aluno, sizeof(nome_aluno), stdin);

    // IDADE DO ALUNO JUNTO COM A CONFIRMAÇÃO DE IDADE SUPERIOR A 16
    printf("Qual a sua idade? ");
    scanf("%d", &idade_aluno);

    if (idade_aluno < 16){
        printf("Idade nao permitida, sistema encerrado.");
        return 0;
    } 

    // RENDA FAMILIAR JUNTO COM A CONFIRMAÇÃO DE UMA RENDA SUPERIOR A 0 E A FAIXA SOCIAL
    printf("Qual a sua renda familiar mensal? ");
    scanf("%f", &renda_familiar);

    if (renda_familiar <= 0){
        printf("Renda mensal é insuficiente, sistema encerrado.");
        return 0;
    } else if (renda_familiar <= 2000){
        faixa_social = 'A';
    } else if (renda_familiar <= 5000){
        faixa_social = 'B';
    } else {
        faixa_social = 'C';
    }

    // MEDIA ACADEMICA
    printf("Qual a sua media academica? 0-10 ");
    scanf("%f", &media_academica);
    while (getchar() != '\n');
    
        if (media_academica < 0){
        printf("A media está errada, está fora da pontuacao possivel.\nSistema encerrado.");
        return 0;
    } else if (media_academica > 10){
        printf("A media está errada, está fora da pontuacao possivel.\nSistema encerrado.");
        return 0;
    } 

    // STATUS PONTUALIDADE E BONUS
    printf("Sua pontualidade no pagamento esta em dia? ('S'-> sim) ou ('N'-> nao) ");
    scanf("%c", &status_pontualidade);
    
    if (status_pontualidade == 'S'){
        bonus_pontual = 0.05;
    } else {
        bonus_pontual = 0;
    }
    
    // DESCONTO BASE
    if (faixa_social == 'A') {
        if (media_academica >= 8.5){
            desconto_base = 0.5;
        } else { 
            desconto_base = 0.3;
        }
    } else if (faixa_social == 'B'){
        if (media_academica >= 9){
            desconto_base = 0.25;
        } else { 
            desconto_base = 0.1;
        }
    } else if (faixa_social == 'C'){
        if (media_academica >= 9.5){
            desconto_base = 0.1;
        } else { 
            desconto_base = 0;
        }
    }
    
    // CALCULAR DESCONTO TOTAL
    desconto_total = (desconto_base + bonus_pontual)*100;
    
    // STATUS DA BOLSA
    if (media_academica >= 6){
        status_bolsa = 1;
        desconto_base = desconto_base*100;
        bonus_pontual = bonus_pontual*100;
    } else {
        status_bolsa = 0;
        desconto_base = 0;
        bonus_pontual = 0;
        desconto_total = 0;
    }

    // PRINT FINAL
    printf("========================================\n");
    printf("    SISTEMA DE AVALIACAO DE DESCONTO\n");
    printf("========================================\n");
    printf("Aluno         : %s\n", nome_aluno);
    printf("Faixa Social  : Faixa %c\n", faixa_social);
    printf("Media         : %.1f\n", media_academica);
    printf("Desconto Base : %.2f%%\n", desconto_base);
    printf("Bonus Pontual : %.2f%%\n", bonus_pontual);
    printf("----------------------------------------\n");
    printf("Desconto Total: %.2f%%\n", desconto_total);
    printf("Status        : %s\n", status_bolsa == 1? "APROVADO" : "REPROVADO");
    printf("========================================\n");




    return 0;
}
