#include <stdio.h>
#include <string.h>

#define MAX 30

enum StatusAluno { REPROVADO = 0, RECUPERACAO = 1, APROVADO = 2 };

struct Aluno {
    int matricula;
    char nome[41];
    float a1;
    float a2;
    enum StatusAluno status;
};

int main() {
    struct Aluno turma[MAX];
    int total = 0;

    char nomes_status[3][12] = {"Reprovado", "Recuperacao", "Aprovado"};

    int opcao, matricula, achou, tam;
    int qtd[3];
    float media, soma;
    char trecho[41];

    do {
        printf("\n===== CADASTRO DE TURMA (%d/%d alunos) =====\n", total, MAX);
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar por matricula\n");
        printf("4 - Buscar por trecho do nome\n");
        printf("5 - Estatisticas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:

                if (total >= MAX) {
                    printf("\nTurma cheia (maximo de %d alunos).\n", MAX);
                    break;
                }

                printf("\n--- Cadastrar aluno ---\n");
                printf("Matricula: ");
                scanf("%d", &matricula);
                while (getchar() != '\n');

                achou = 0;
                for (int i = 0; i < total; i++) {
                    if (turma[i].matricula == matricula) {
                        achou = 1;
                    }
                }
                if (achou) {
                    printf("Matricula ja cadastrada.\n");
                    break;
                }
                turma[total].matricula = matricula;

                printf("Nome: ");
                fgets(turma[total].nome, sizeof(turma[total].nome), stdin);
                tam = strlen(turma[total].nome);
                if (tam > 0 && turma[total].nome[tam - 1] == '\n') {
                    turma[total].nome[tam - 1] = '\0';
                } else {
               
                    while (getchar() != '\n');
                }

                do {
                    printf("A1 (0 a 10): ");
                    scanf("%f", &turma[total].a1);
                    while (getchar() != '\n');
                } while (turma[total].a1 < 0 || turma[total].a1 > 10);

                do {
                    printf("A2 (0 a 10): ");
                    scanf("%f", &turma[total].a2);
                    while (getchar() != '\n');
                } while (turma[total].a2 < 0 || turma[total].a2 > 10);

                media = 0.4f * turma[total].a1 + 0.6f * turma[total].a2;
                if (media >= 5) {
                    turma[total].status = APROVADO;
                } else if (media >= 3) {
                    turma[total].status = RECUPERACAO;
                } else {
                    turma[total].status = REPROVADO;
                }

                printf("Aluno cadastrado! Media %.2f - %s\n",
                       media, nomes_status[turma[total].status]);
                total++;
                break;

            case 2:
                printf("\n--- Lista de alunos ---\n");
                if (total == 0) {
                    printf("Nenhum aluno cadastrado.\n");
                    break;
                }
                printf("matricula | Nome | A1 | A2 | Media | Status\n");
                for (int i = 0; i < total; i++) {
                    media = 0.4f * turma[i].a1 + 0.6f * turma[i].a2;
                    printf("%d | %s | %.1f | %.1f | %.2f | %s\n",
                           turma[i].matricula, turma[i].nome,
                           turma[i].a1, turma[i].a2, media,
                           nomes_status[turma[i].status]);
                }
                break;

            case 3:
                printf("\n--- Buscar por matricula ---\n");
                printf("Matricula: ");
                scanf("%d", &matricula);
                while (getchar() != '\n');

                achou = 0;
                for (int i = 0; i < total; i++) {
                    if (turma[i].matricula == matricula) {
                        media = 0.4f * turma[i].a1 + 0.6f * turma[i].a2;
                        printf("%d | %s | %.1f | %.1f | %.2f | %s\n",
                               turma[i].matricula, turma[i].nome,
                               turma[i].a1, turma[i].a2, media,
                               nomes_status[turma[i].status]);
                        achou = 1;
                    }
                }
                if (!achou) {
                    printf("nao encontrado\n");
                }
                break;

            case 4:
                printf("\n--- Buscar por trecho do nome ---\n");
                printf("Trecho: ");
                fgets(trecho, sizeof(trecho), stdin);
                tam = strlen(trecho);
                if (tam > 0 && trecho[tam - 1] == '\n') {
                    trecho[tam - 1] = '\0';
                } else {
                    while (getchar() != '\n');
                }

                achou = 0;
                for (int i = 0; i < total; i++) {
                    if (strstr(turma[i].nome, trecho) != NULL) {
                        media = 0.4f * turma[i].a1 + 0.6f * turma[i].a2;
                        printf("%d | %s | %.1f | %.1f | %.2f | %s\n",
                               turma[i].matricula, turma[i].nome,
                               turma[i].a1, turma[i].a2, media,
                               nomes_status[turma[i].status]);
                        achou = 1;
                    }
                }
                if (!achou) {
                    printf("nao encontrado\n");
                }
                break;

            case 5:
                printf("\n--- Estatisticas ---\n");
                if (total == 0) {
                    printf("Nenhum aluno cadastrado.\n");
                    break;
                }

                qtd[REPROVADO] = 0;
                qtd[RECUPERACAO] = 0;
                qtd[APROVADO] = 0;
                soma = 0;
                for (int i = 0; i < total; i++) {
                    qtd[turma[i].status]++;
                    soma += 0.4f * turma[i].a1 + 0.6f * turma[i].a2;
                }

                printf("Aprovados:   %d\n", qtd[APROVADO]);
                printf("Recuperacao: %d\n", qtd[RECUPERACAO]);
                printf("Reprovados:  %d\n", qtd[REPROVADO]);
                printf("Media geral da turma: %.2f\n", soma / total);
                break;

            case 0:
                printf("\nEncerrando o programa.\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}