/* Ao declarar char nome[50], uma das 50 posições é reservada para o terminador
'\0', que marca o fim da string em C. Por isso sobram 49 caracteres úteis.
Em int M[3][4], o primeiro índice representa a linha (0 a 2) e o segundo
representa a coluna (0 a 3). A linguagem C guarda a matriz na memória em
ordem de linha: os 4 elementos da linha 0 ficam lado a lado, seguidos pelos
da linha 1 e depois pelos da linha 2, totalizando 12 posições contíguas.
O elemento M[i][j] está no deslocamento i * 4 + j.
 */

#include <stdio.h>
#include <string.h>

#define TAM_NOME  50
#define LINHAS  3
#define COLUNAS  4

int main() {
    
    int NUM_ALUNOS;
    printf("Quantos alunos estudam na academia? -> ");
    scanf("%d", &NUM_ALUNOS);
    
    int opcao;
    char alunos[NUM_ALUNOS][TAM_NOME];
    float notas_finais[NUM_ALUNOS];
    float boletim[LINHAS][COLUNAS];
    float notas[NUM_ALUNOS];
    float soma, media, maior;
    int acima, indice;

    do {
        printf("\n===== SISTEMA DE GESTAO ACADEMICA =====\n");
        printf("1 - Cadastrar Lista de Alunos\n");
        printf("2 - Estatisticas de Desempenho\n");
        printf("3 - Matriz de Notas da Turma \n");
        printf("4 - Consultar Aluno em Destaque\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                printf("\n--- Cadastro de Alunos ---\n");
                for (int i = 0; i < NUM_ALUNOS; i++) {
                    printf("Nome do aluno %d: ", i + 1);
                    fgets(alunos[i], sizeof(alunos[i]), stdin);
                    alunos[i][strcspn(alunos[i], "\n")] = '\0';
                }

                printf("\nAlunos cadastrados:\n");
                for (int i = 0; i < NUM_ALUNOS; i++) {
                    printf("%d. %s\n", i + 1, alunos[i]);
                }
                break;

            case 2:
                printf("\n--- Estatisticas de Desempenho ---\n");
                for (int i = 0; i < NUM_ALUNOS; i++) {
                    printf("Nota final do aluno %d: ", i + 1);
                    scanf("%f", &notas_finais[i]);
                    while (getchar() != '\n');
                }

                soma = 0;
                for (int i = 0; i < NUM_ALUNOS; i++) {
                    soma += notas_finais[i];
                }
                media = soma / NUM_ALUNOS;

                acima = 0;
                for (int i = 0; i < NUM_ALUNOS; i++) {
                    if (notas_finais[i] >= media) {
                        acima++;
                    }
                }

                printf("\nMedia geral da turma: %.2f\n", media);
                printf("Aluno destaque >= media: %d\n", acima);
                break;

            case 3:
                printf("\n--- Matriz de Notas da Turma ---\n");
                for (int i = 0; i < LINHAS; i++) {
                    for (int j = 0; j < COLUNAS; j++) {
                        printf("Aluno %d - Bimestre %d: ", i + 1, j + 1);
                        scanf("%f", &boletim[i][j]);
                        while (getchar() != '\n');
                    }
                }

                printf("\n            Bim1   Bim2   Bim3   Bim4   | Media\n");
                for (int i = 0; i < LINHAS; i++) {
                    soma = 0;
                    printf("Aluno %d  ", i + 1);
                    for (int j = 0; j < COLUNAS; j++) {
                        printf("%6.2f ", boletim[i][j]);
                        soma += boletim[i][j];
                    }
                    printf("| %6.2f\n", soma / COLUNAS);
                }
                break;

            case 4:
                printf("\n--- Aluno em Destaque ---\n");
                for (int i = 0; i < NUM_ALUNOS; i++) {
                    printf("Nota do aluno %d: ", i + 1);
                    scanf("%f", &notas[i]);
                    while (getchar() != '\n');
                }

                maior = notas[0];
                indice = 0;
                for (int i = 1; i < NUM_ALUNOS; i++) {
                    if (notas[i] > maior) {
                        maior = notas[i];
                        indice = i;
                    }
                }

                printf("\nMaior nota da turma: %.2f\n", maior);
                printf("Posicao (indice) no vetor: %d (aluno %d)\n", indice, indice + 1);
                break;

            case 0:
                printf("\nEncerrando o sistema.\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}