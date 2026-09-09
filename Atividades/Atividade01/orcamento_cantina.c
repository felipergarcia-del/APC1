#include <stdio.h>

const float café = 4.00, refeições = 12.50;

int main(void) {
    
    int quatidade_café, quantidade_refeições;
    float saldo;
    
    printf("Quanto de saldo voce tem?");
    scanf("%f", &saldo);
    printf("Seu saldo é de R$%.2f\n", saldo);

    printf("Quantos vezes durante a semana voce tomou café?");
    scanf("%d", &quatidade_café);
    printf("Quantos reifeções durante a semana voce tomou?");
    scanf("%d", &quantidade_refeições);

// Os calculos sao basicos, qtd vezes preco, soma dos dois 
// gastos e o saldo daquele momento menos o gasto total

    float gasto_refeições = quantidade_refeições * refeições;
    float gasto_café = quatidade_café * café;
    float gasto_total = gasto_café + gasto_refeições;
    saldo = saldo - gasto_total;
    

    printf("Voce gastou R$%.2f com refeições\n", gasto_refeições);
    printf("Voce gastou R$%.2f com cafés\n", gasto_café);
    printf("Voce gastou no total R$%.2f com refeições e cafés\n", gasto_total);
    printf("Voce tem de saldo restante R$%.2f\n", saldo);


    return 0;
}