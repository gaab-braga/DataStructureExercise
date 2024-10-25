#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void criar_lista(Lista* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

void inserir_no_inicio(Lista* lista, int num) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo) {
        novo->valor = num;
        novo->prox = lista->inicio;
        lista->inicio = novo;
        if (lista->tamanho == 0)
            lista->fim = novo;
        lista->fim->prox = lista->inicio;
        lista->tamanho++;
    } else {
        printf("Erro ao alocar memoria");
    }
}

void inserir_no_fim(Lista* lista, int num) {
    No* novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = num;
        if (lista->inicio == NULL) {
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->prox = lista->inicio;
        } else {
            lista->fim->prox = novo;
            lista->fim = novo;
            novo->prox = lista->inicio;
        }
        lista->tamanho++;
    } else {
        printf("Erro ao alocar memoria");
    }
}

void inserir_ordenado(Lista* lista, int num) {
    No* novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = num;
        if (lista->inicio == NULL || novo->valor < lista->inicio->valor) {
            inserir_no_inicio(lista, num);
        } else {
            No* aux = lista->inicio;
            while (aux->prox != lista->inicio && novo->valor > aux->prox->valor)
                aux = aux->prox;
            if (aux->prox == lista->inicio) {
                inserir_no_fim(lista, num);
            } else {
                novo->prox = aux->prox;
                aux->prox = novo;
                lista->tamanho++;
            }
        }
    } else {
        printf("Erro ao alocar memoria");
    }
}

No* remover(Lista* lista, int num) {
    No* aux, *remover = NULL;
    if (lista->inicio) {
        if (lista->inicio == lista->fim && lista->inicio->valor == num) {
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tamanho--;
        } else if (lista->inicio->valor == num) {
            remover = lista->inicio;
            lista->inicio = lista->inicio->prox;
            lista->fim->prox = lista->inicio;
            lista->tamanho--;
        } else {
            aux = lista->inicio;
            while (aux->prox != lista->inicio && aux->prox->valor != num)
                aux = aux->prox;
            if (aux->prox->valor == num) {
                if (lista->fim == aux->prox) {
                    remover = aux->prox;
                    aux->prox = remover->prox;
                    lista->fim = aux;
                } else {
                    remover = aux->prox;
                    aux->prox = remover->prox;
                }
                lista->tamanho--;
            }
        }
    }
    return remover;
}

No* buscar(Lista* lista, int num) {
    No* aux = lista->inicio;
    if (aux) {
        do {
            if (aux->valor == num)
                return aux;
            aux = aux->prox;
        } while (aux != lista->inicio);
    }
    return NULL;
}

void imprimir(Lista* lista) {
    No* no = lista->inicio;
    printf("\n\tLista tam %d", lista->tamanho);
    if (no) {
        do {
            printf("%d ", no->valor);
            no = no->prox;
        } while (no != lista->inicio);
        printf("\nInicio: %d\n", no->valor);
    }
    printf("\n");
}
