#include "pilha.h"
#include <stdlib.h>

void criar_pilha(Pilha* pilha) {
    pilha->topo = NULL;
}

void empilhar(Pilha* pilha, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo) {
        novo->valor = valor;
        novo->proximo = pilha->topo;
        pilha->topo = novo;
    }
}

int desempilhar(Pilha* pilha) {
    if (pilha->topo) {
        No* temp = pilha->topo;
        int valor = temp->valor;
        pilha->topo = temp->proximo;
        free(temp);
        return valor;
    }
    return -1;  // Indica que a pilha está vazia
}

int pilha_vazia(Pilha* pilha) {
    return pilha->topo == NULL;
}
