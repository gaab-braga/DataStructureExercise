#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

void criar_fila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void inserir_fila(Fila* fila, int valor) {
    NoFila* novo = (NoFila*) malloc(sizeof(NoFila));
    if (novo) {
        novo->valor = valor;
        novo->proximo = NULL;
        if (fila->fim) {
            fila->fim->proximo = novo;
        } else {
            fila->inicio = novo;
        }
        fila->fim = novo;
    } else {
        printf("Erro ao alocar memoria\n");
    }
}

int remover_fila(Fila* fila) {
    if (fila->inicio) {
        NoFila* temp = fila->inicio;
        int valor = temp->valor;
        fila->inicio = temp->proximo;
        if (!fila->inicio) {
            fila->fim = NULL;
        }
        free(temp);
        return valor;
    }
    printf("Fila vazia\n");
    return -1;
}

int fila_vazia(Fila* fila) {
    return fila->inicio == NULL;
}


