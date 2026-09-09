/* Questao 3 -> O problema do scanf("%s") são os nomes compostos pois possuem a presença de 
espaços e ele para de ler quando encontra um espaço vazio (" "), por exemplo "Felipe Ribeiro" 
ele só retorna "Felipe", no programa evita esse problema utilizando fgets(), que permite ler 
strings sem parar quando encontra um espaço, então no mesmo exemplo anterior ele vai retornar
de volta toda a string "Felipe Ribeiro". */

#include <stdio.h>

int main(void) {
    char nome_pessoa[50], nome_produto[50], categoria;
    int codigo_produto, qtd_produto;
    float preco_produto, total;

    printf("Qual o seu nome: ");
    fgets(nome_pessoa, sizeof(nome_pessoa), stdin);

    printf("Nome do produto: ");
    fgets(nome_produto, sizeof(nome_produto), stdin);

    printf("Categoria (A/B/C): ");
    scanf("%c", &categoria);
    while (getchar() != '\n');

    printf("Codigo do produto: ");
    scanf("%d", &codigo_produto);
    while (getchar() != '\n');

    printf("Quantidade: ");
    scanf("%d", &qtd_produto);
    while (getchar() != '\n');

    printf("Preco unitario: ");
    scanf("%f", &preco_produto);
    while (getchar() != '\n');

    total = qtd_produto * preco_produto;

    printf("\n========================================\n");
    printf("I           RECIBO DE COMPRA           I\n");
    printf("========================================\n");
    printf("%-10s: %s", "Cliente", nome_pessoa);
    printf("%-10s: %s", "Produto", nome_produto);
    printf("%-10s: %d\n", "Codigo", codigo_produto);
    printf("%-10s: %c\n", "Categoria", categoria);
    printf("%-10s: %d\n", "Qtd", qtd_produto);
    printf("%-10s: R$ %.2f\n", "Unitario", preco_produto);
    printf("%-10s: R$ %.2f\n", "Total", total);
    printf("========================================\n");

    return 0;
}