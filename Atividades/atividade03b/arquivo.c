/*
O fall-through consciente foi vantajoso nos cases de prioridade U/u, N/n e B/b,
pois permite que letras maiusculas e minusculas compartilhem o mesmo bloco.
No expediente, os dias 2 a 5 compartilham a classificacao de horario pleno.
O switch organiza opcoes por valores especificos de uma variavel.
Ele nao substitui o if-else-if na classificacao por faixas de renda.
Isso ocorre porque o switch compara valores especificos, nao intervalos.
Com if-else-if, e possivel testar condicoes como renda maior ou menor que um limite.
Assim, cada estrutura atende melhor a diferentes tipos de classificacao.
*/

#include <stdio.h>
#include <string.h>

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

    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("| Código | Serviço                 | Categoria               | Prazo       | Taxa base | Status     |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("| 1      | Histórico escolar       | Documento simples       | 02 dias úteis | R$ 15,00  | ACEITO   |\n");
    printf("| 2      | Declaração de matrícula | Documento simples       | 02 dias úteis | R$ 15,00  | ACEITO   |\n");
    printf("| 3      | Declaração de vínculo   | Documento simples       | 02 dias úteis | R$ 15,00  | ACEITO   |\n");
    printf("| 4      | Trancamento             | Interrupção de vínculo  | 10 dias úteis | R$ 0,00   | ACEITO   |\n");
    printf("| 5      | Cancelamento            | Interrupção de vínculo  | 10 dias úteis | R$ 0,00   | ACEITO   |\n");
    printf("| 6      | Colação de grau         | Ato solene              | 15 dias úteis | R$ 80,00  | ACEITO   |\n");
    printf("| outro  | Código inválido         | —                       | 0             | R$ 0,00   | RECUSADO |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    printf("Digite o codigo do servico: ");
    scanf("%d", &codigo);

    printf("U/u -> URGENTE\n");
    printf("N/n -> NORMAL\n");
    printf("B/b -> BALCAO\n");
    printf("Digite a prioridade: ");
    scanf(" %c", &prioridade);

    printf(" / 1-Domingo 2-Segunda 3-Terca 4-Quarta / \n ");
    printf("/ 5-Quinta 6-Sexta 7-Sabado            / \n ");
    printf("Digite o dia da semana (1 a 7): ");
    scanf("%d", &dia);

    switch (codigo) {
        case 1:
            strcpy(servico, "Historico escolar");
            /* fall-through */
        case 2:
            /* fall-through */
        case 3:
            if (codigo == 2) {
                strcpy(servico, "Declaracao de matricula");
            }
            if (codigo == 3) {
                strcpy(servico, "Declaracao de vinculo");
            }
            strcpy(categoria, "Documento simples");
            strcpy(prazo, "2 dias uteis");
            taxa_base = 15.0;
            strcpy(status, "ACEITO");
            break;

        case 4:
            strcpy(servico, "Trancamento");
            /* fall-through */
        case 5:
            if (codigo == 5) {
                strcpy(servico, "Cancelamento");
            }
            strcpy(categoria, "Interrupcao de vinculo");
            strcpy(prazo, "10 dias uteis");
            taxa_base = 0.0;
            strcpy(status, "ACEITO");
            break;

        case 6:
            strcpy(servico, "Colacao de grau");
            strcpy(categoria, "Ato solene");
            strcpy(prazo, "15 dias uteis");
            taxa_base = 80.0;
            strcpy(status, "ACEITO");
            break;

        default:
            strcpy(servico, "Codigo invalido");
            strcpy(categoria, "---");
            strcpy(prazo, "0");
            taxa_base = 0.0;
            strcpy(status, "RECUSADO");
            break;
    }

    switch (prioridade) {
        case 'U':
            /* fall-through */
        case 'u':
            strcpy(nomePrioridade, "Urgente");
            guiche = 1;
            acrescimo = 10.0;
            break;

        case 'N':
            /* fall-through */
        case 'n':
            strcpy(nomePrioridade, "Normal");
            guiche = 2;
            acrescimo = 0.0;
            break;

        case 'B':
            /* fall-through */
        case 'b':
            strcpy(nomePrioridade, "Balcao");
            guiche = 3;
            acrescimo = 0.0;
            break;

        default:
            strcpy(nomePrioridade, "Invalida");
            guiche = 0;
            acrescimo = 0.0;
            break;
    }

    switch (dia) {
        case 1:
            strcpy(nomeDia, "Domingo");
            break;
        case 2:
            strcpy(nomeDia, "Segunda-feira");
            break;
        case 3:
            strcpy(nomeDia, "Terca-feira");
            break;
        case 4:
            strcpy(nomeDia, "Quarta-feira");
            break;
        case 5:
            strcpy(nomeDia, "Quinta-feira");
            break;
        case 6:
            strcpy(nomeDia, "Sexta-feira");
            break;
        case 7:
            strcpy(nomeDia, "Sabado");
            break;
        default:
            strcpy(nomeDia, "Dia invalido");
            break;
    }

    switch (dia) {
        case 2:
            /* fall-through */
        case 3:
            /* fall-through */
        case 4:
            /* fall-through */
        case 5:
            strcpy(expediente, "Pleno");
            break;

        case 6:
            strcpy(expediente, "Reduzido");
            break;

        case 1:
            /* fall-through */
        case 7:
            strcpy(expediente, "Fechado");
            break;

        default:
            strcpy(expediente, "Dia invalido");
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