#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

#define MAX 100

struct lista {
    int qtd;
    struct aluno *dados;
};

// Função para criar a lista com alocação dinâmica
Lista* cria_lista() {
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL) {
        li->qtd = 0;
        li->dados = (struct aluno*) malloc(MAX * sizeof(struct aluno));
        if (li->dados == NULL) {
            free(li);
            return NULL;
        }
    }
    return li;
}

void libera_lista(Lista* li) {
    if (li != NULL) {
        free(li->dados);
        free(li);
    }
}

int tamanho_lista(Lista* li) {
    if (li == NULL)
        return -1;
    return li->qtd;
}

int lista_cheia(Lista* li) {
    if (li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li) {
    if (li == NULL)
        return -1;
    return (li->qtd == 0);
}

void imprime_lista(Lista* li) {
    if (li == NULL || li->qtd == 0) {
        printf("Lista vazia!\n");
        return;
    }

    for (int i = 0; i < li->qtd; i++) {
        printf("Matricula: %d\n", li->dados[i].matricula);
        printf("Nome: %s\n", li->dados[i].nome);
        printf("Notas: %d, %d, %d, %d, NP: %d\n",
            li->dados[i].n1, li->dados[i].n2, li->dados[i].n3, li->dados[i].n4, li->dados[i].np);
        printf("Nota Final: %.2f\n", calcula_nota_final(li->dados[i]));
        printf("-----------------------------\n");
    }
}

int insere_lista_final(Lista* li, struct aluno al) {
    if (li == NULL || lista_cheia(li))
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}
