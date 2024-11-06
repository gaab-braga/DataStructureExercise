#include <stdio.h>
#include "pilha.h"

void converter_para_base(Pilha* pilha, int numero, int base) {
    criar_pilha(pilha);

    // Empilha os restos das divisões sucessivas pelo valor da base
    while (numero > 0) {
        empilhar(pilha, numero % base);
        numero /= base;
    }
}

void imprimir_pilha(Pilha* pilha, int base) {
    // Desempilha e imprime os valores na ordem correta
    while (!pilha_vazia(pilha)) {
        int digito = desempilhar(pilha);
        
        if (base == 16 && digito >= 10) {
            printf("%c", 'A' + (digito - 10));  // Hexadecimal: A, B, C, etc.
        } else {
            printf("%d", digito);
        }
    }
    printf("\n");
}

int main() {
    int numero, opcao;
    Pilha pilha;

    printf("Digite um número decimal para converter: ");
    scanf("%d", &numero);

    printf("Escolha a base para conversão:\n");
    printf("1 - Decimal para Binário\n");
    printf("2 - Decimal para Octal\n");
    printf("3 - Decimal para Hexadecimal\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Binário: ");
            converter_para_base(&pilha, numero, 2);
            imprimir_pilha(&pilha, 2);
            break;
        case 2:
            printf("Octal: ");
            converter_para_base(&pilha, numero, 8);
            imprimir_pilha(&pilha, 8);
            break;
        case 3:
            printf("Hexadecimal: ");
            converter_para_base(&pilha, numero, 16);
            imprimir_pilha(&pilha, 16);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}
