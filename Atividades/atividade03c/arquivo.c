/* Atividade 03C - Comandos de Repeticao em C - Painel de Senhas
1) Por que do-while no menu? O do-while verifica a condicao so depois de
executar o bloco, entao o menu e exibido pelo menos uma vez. O while
poderia nunca exibir o menu se a condicao inicial fosse falsa.
2) Onde o continue evita contar senha invalida? Na opcao 1 (lote): se a
senha e negativa, soma em "ignoradas" e o continue salta o resto da
volta, entao ela nao entra em "atendidas" nem em "pares".
3) E se o break fosse omitido na busca prioritaria? Como o laco for(;;) nao
tem condicao de parada, ele repetiria para sempre: mesmo apos achar a
prioritaria (ou digitar 0) o programa pediria senhas e nao voltaria ao menu. */

#include <stdio.h>
 
int main(void)
{
    int opcao;
 
    do {
        printf("\n===== PAINEL DE SENHAS =====\n");
        printf("1 - Registrar senha\n");
        printf("2 - Simular chamadas\n");
        printf("3 - Grade de guiches\n");
        printf("4 - Buscar senha prioritaria\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
 
        switch (opcao) {
        case 1: {
            int senha;
            int atendidas = 0, ignoradas = 0, pares = 0;
 
            printf("Senha (0 para encerrar): ");
            scanf("%d", &senha);              
            while (senha != 0) {              
                if (senha < 0) {
                    ignoradas++;
                    printf("Senha: ");        
                    scanf("%d", &senha);     
                    continue;                 
                }
                atendidas++;
                if (senha % 2 == 0) {
                    pares++;
                }
                printf("Senha: ");
                scanf("%d", &senha);
            }
 
            printf("Atendidas : %d\n", atendidas);
            printf("Ignoradas : %d\n", ignoradas);
            printf("Pares : %d\n", pares);
            break;
        }
 
        case 2: {
            int inicio, fim, passo;
            int chamadas = 0;
 
            printf("Inicio: ");
            scanf("%d", &inicio);
            printf("Fim: ");
            scanf("%d", &fim);
            printf("Passo: ");
            scanf("%d", &passo);
 
            if (passo == 0) {
                printf("Passo invalido\n");   
            } else {
                for (int i = inicio; passo > 0 ? i <= fim : i >= fim; i += passo) {
                    if (chamadas == 0) {
                        printf("Chamadas:");
                    }
                    printf(" %d", i);
                    chamadas++;
                }
                if (chamadas == 0) {
                    printf("Nenhuma chamada\n");
                } else {
                    printf("\n");
                }
            }
            break;
        }
 
        case 3: {
            int g, s;
 
            printf("Guiches (1 a 4): ");
            scanf("%d", &g);
            printf("Senhas por guiche (1 a 5): ");
            scanf("%d", &s);
 
            if (g < 1 || g > 4 || s < 1 || s > 5) {
                printf("Grade invalida\n");
            } else {
                for (int guiche = 1; guiche <= g; guiche++) {       
                    printf("Guiche %d:", guiche);
                    for (int numero = 1; numero <= s; numero++) {   
                        printf(" %d", numero);
                    }
                    printf("\n");
                }
            }
            break;
        }
 
        case 4: {
            int senha;
            int lidas = 0;
 
            for (;;) {
                printf("Senha (0 para encerrar): ");
                scanf("%d", &senha);
 
                if (senha == 0) {                       
                    printf("Nao encontrada\n");
                    printf("Lidas : %d\n", lidas);
                    break;
                }
                if (senha > 0 && senha % 10 == 0) {
                    printf("Prioritaria : %d\n", senha);
                    printf("Lidas antes : %d\n", lidas);
                    break;
                }
                lidas++;                                
            }
            break;
        }
 
        case 0:
            break;
 
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 0);
 
    printf("\nPainel encerrado.\n");
    return 0;
}
 
