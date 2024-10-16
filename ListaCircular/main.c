#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    int opcao, valor;
    Lista lista;
    No* removido;

    criar_lista(&lista);

    do {
        printf("\n\t0 - Sair\n\t1 - Inserir no Inicio\n\t2 - Inserir no Fim\n\t3 - Inserir Ordenado\n\t4 - Remover\n\t5 - Imprimir\n\t6 - Buscar\n ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                inserir_no_inicio(&lista, valor);
                break;
            case 2:
                printf("Valor: ");
                scanf("%d", &valor);
                inserir_no_fim(&lista, valor);
                break;
            case 3:
                printf("Valor: ");
                scanf("%d", &valor);
                inserir_ordenado(&lista, valor);
                break;
            case 4:
                printf("Valor: ");
                scanf("%d", &valor);
                removido = remover(&lista, valor);
                if (removido) {
                    printf("Removido: %d\n", removido->valor);
                    free(removido);
                } else {
                    printf("Valor nao encontrado\n");
                }
                break;
            case 5:
                imprimir(&lista);
                break;
            case 6:
                printf("Digite um valor a ser buscado: ");
                scanf("%d", &valor);
                removido = buscar(&lista, valor);
                if (removido) {
                    printf("Valor encontrado: %d\n", removido->valor);
                } else {
                    printf("Valor nao encontrado\n");
                }
                break;
            default:
                if (opcao != 0) {
                    printf("Opcao invalida\n");
                }
        }
    } while (opcao != 0);

    return 0;
}
