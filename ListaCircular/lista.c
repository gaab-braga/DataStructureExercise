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
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        if (lista->tamanho == 0)
            lista->fim = novo;
        lista->fim->proximo = lista->inicio;
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
            lista->fim->proximo = lista->inicio;
        } else {
            lista->fim->proximo = novo;
            lista->fim = novo;
            novo->proximo = lista->inicio;
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
            while (aux->proximo != lista->inicio && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            if (aux->proximo == lista->inicio) {
                inserir_no_fim(lista, num);
            } else {
                novo->proximo = aux->proximo;
                aux->proximo = novo;
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
            lista->inicio = lista->inicio->proximo;
            lista->fim->proximo = lista->inicio;
            lista->tamanho--;
        } else {
            aux = lista->inicio;
            while (aux->proximo != lista->inicio && aux->proximo->valor != num)
                aux = aux->proximo;
            if (aux->proximo->valor == num) {
                if (lista->fim == aux->proximo) {
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                    lista->fim = aux;
                } else {
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
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
            aux = aux->proximo;
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
            no = no->proximo;
        } while (no != lista->inicio);
        printf("\nInicio: %d\n", no->valor);
    }
    printf("\n");
}
