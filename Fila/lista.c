#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void criar_lista(Lista* lista) {
    lista->inicio = NULL;
}

void inserir_lista(Lista* lista, int valor) {
    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
    if (novo) {
        novo->valor = valor;
        novo->proximo = NULL;

        if (!lista->inicio) {
            lista->inicio = novo;
        } else {
            NoLista* aux = lista->inicio;
            while (aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    } else {
        printf("Erro ao alocar memoria\n");
    }
}

int remover_lista(Lista* lista) {
    if (lista->inicio) {
        NoLista* temp = lista->inicio;
        int valor = temp->valor;
        lista->inicio = temp->proximo;
        free(temp);
        return valor;
    }
    printf("Lista vazia\n");
    return -1;
}

int lista_vazia(Lista* lista) {
    return lista->inicio == NULL;
}

