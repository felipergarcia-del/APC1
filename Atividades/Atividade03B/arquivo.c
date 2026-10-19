#include <stdio.h>

int main() {
    int codigo, dia, guiche = 0;
    char prioridade;

    char servico[50];
    char categoria[50];
    char prazo[30];
    char status[20];
    char nomePrioridade[20];
    char nomeDia[30];
    char expediente[20];

    float taxa_base = 0.0;
    float acrescimo = 0.0;
    float taxa_final;

    printf("Digite o codigo do servico: ");
    scanf("%d", &codigo);

    printf("Digite a prioridade (U/u, N/n ou B/b): ");
    scanf(" %c", &prioridade);

    printf("Digite o dia da semana (1 a 7): ");
    scanf("%d", &dia);

    
    switch (codigo) {
        case 1:
            sprintf(servico, "Historico escolar");
            /* fall-through */
        case 2:
            switch (codigo) {
                case 2:
                    sprintf(servico, "Declaracao de matricula");
                    break;
                default:
                    break;
            }
        case 3:
            switch (codigo) {
                case 3:
                    sprintf(servico, "Declaracao de vinculo");
                    break;
                default:
                    break;
            }
            sprintf(categoria, "Documento simples");
            sprintf(prazo, "2 dias uteis");
            taxa_base = 15.0;
            sprintf(status, "ACEITO");
            break;

        case 4:
            sprintf(servico, "Trancamento");
            /* fall-through */
        case 5:
            switch (codigo) {
                case 5:
                    sprintf(servico, "Cancelamento");
                    break;
                default:
                    break;
            }
            sprintf(categoria, "Interrupcao de vinculo");
            sprintf(prazo, "10 dias uteis");
            taxa_base = 0.0;
            sprintf(status, "ACEITO");
            break;

        case 6:
            sprintf(servico, "Colacao de grau");
            sprintf(categoria, "Ato solene");
            sprintf(prazo, "15 dias uteis");
            taxa_base = 80.0;
            sprintf(status, "ACEITO");
            break;

        default:
            sprintf(servico, "Codigo invalido");
            sprintf(categoria, "---");
            sprintf(prazo, "0");
            taxa_base = 0.0;
            sprintf(status, "RECUSADO");
            break;
    }


    switch (prioridade) {
        case 'U':
        case 'u':
            sprintf(nomePrioridade, "Urgente");
            guiche = 1;
            acrescimo = 10.0;
            break;

        case 'N':
        case 'n':
            sprintf(nomePrioridade, "Normal");
            guiche = 2;
            acrescimo = 0.0;
            break;

        case 'B':
        case 'b':
            sprintf(nomePrioridade, "Balcao");
            guiche = 3;
            acrescimo = 0.0;
            break;

        default:
            sprintf(nomePrioridade, "Invalida");
            guiche = 0;
            acrescimo = 0.0;
            break;
    }

    switch (dia) {
        case 1:
            sprintf(nomeDia, "Domingo");
            break;
        case 2:
            sprintf(nomeDia, "Segunda-feira");
            break;
        case 3:
            sprintf(nomeDia, "Terca-feira");
            break;
        case 4:
            sprintf(nomeDia, "Quarta-feira");
            break;
        case 5:
            sprintf(nomeDia, "Quinta-feira");
            break;
        case 6:
            sprintf(nomeDia, "Sexta-feira");
            break;
        case 7:
            sprintf(nomeDia, "Sabado");
            break;
        default:
            sprintf(nomeDia, "Dia invalido");
            break;
    }

    switch (dia) {
        case 2:
        case 3:
        case 4:
        case 5:
            sprintf(expediente, "Pleno");
            break;

        case 6:
            sprintf(expediente, "Reduzido");
            break;

        case 1:
            /* fall-through */
        case 7:
            sprintf(expediente, "Fechado");
            break;

        default:
            sprintf(expediente, "Dia invalido");
            break;
    }

    taxa_final = taxa_base + acrescimo;


    printf("\n========================================\n");
    printf("TRIAGEM DE PROTOCOLO ACADEMICO\n");
    printf("========================================\n");
    printf("Servico : %s\n", servico);
    printf("Categoria : %s\n", categoria);
    printf("Prazo : %s\n", prazo);
    printf("Taxa base : R$ %.2f\n", taxa_base);
    printf("Prioridade : %s\n", nomePrioridade);
    printf("Guiche : %d\n", guiche);
    printf("Acrescimo : R$ %.2f\n", acrescimo);
    printf("Dia : %s\n", nomeDia);
    printf("Expediente : %s\n", expediente);
    printf("-----------------------------------------------------------------------\n");
    printf("Taxa final : R$ %.2f\n", taxa_final);
    printf("Status do servico : %s\n", status);
    printf("========================================\n");

    return 0;
}