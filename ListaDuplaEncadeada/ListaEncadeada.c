#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

float calcula_nota_final(struct aluno al) {
    return ((al.ap1 + al.ap2 + al.ap3 + al.ap4) / 4.0) * 0.4 + (al.np * 0.6);
}

// Criação da lista duplamente encadeada
Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL) {
        *li = NULL;
    }
    return li;
}

// Liberação da lista duplamente encadeada
void libera_lista(Lista* li) {
    if (li != NULL) {
        Elem* no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

// Inserção ordenada em lista duplamente encadeada
int insere_lista_ordenado(Lista* li, struct aluno al) {
    if (li == NULL) return 0;
    
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    
    no->dados = al;
    no->dados.nota_final = calcula_nota_final(al);
    
    if ((*li) == NULL) {  // Lista vazia
        no->prox = NULL;
        no->ant = NULL;   // Não há anterior
        *li = no;
        return 1;
    } else {
        Elem *atual = *li;
        while (atual != NULL && atual->dados.nota_final > no->dados.nota_final) {
            atual = atual->prox;
        }
        if (atual == *li) {  // Inserção no início
            no->ant = NULL;
            no->prox = *li;
            (*li)->ant = no;
            *li = no;
        } else {
            no->prox = atual;
            no->ant = atual->ant;
            if (atual != NULL) {
                atual->ant->prox = no;
                atual->ant = no;
            } else {  // Inserção no final
                no->ant->prox = no;
            }
        }
        return 1;
    }
}

// Impressão da lista duplamente encadeada
void imprime_lista(Lista* li) {
    if (li == NULL) return;
    Elem* no = *li;
    while (no != NULL) {
        printf("Matricula: %d Nome: %s Nota Final: %.2f\n", no->dados.matricula, no->dados.nome, no->dados.nota_final);
        no = no->prox;
    }
}

int conta_alunos(Lista* li) {
    if (li == NULL) return 0;
    int count = 0;
    Elem* no = *li;
    while (no != NULL) {
        count++;
        no = no->prox;
    }
    return count;
}

Lista* cria_lista_melhores_notas(Lista* disciplina1, Lista* disciplina2) {
    Lista* melhores = cria_lista();
    Elem *no1 = *disciplina1, *no2 = *disciplina2;

    while ((no1 != NULL || no2 != NULL)) {
        struct aluno al;
        if (no1 != NULL && (no2 == NULL || no1->dados.nota_final > no2->dados.nota_final)) {
            al = no1->dados;
            no1 = no1->prox;
        } else {
            al = no2->dados;
            no2 = no2->prox;
        }
        insere_lista_ordenado(melhores, al);
        if (conta_alunos(melhores) == 10) break;
    }
    return melhores;
}

Lista* cria_lista_piores_notas(Lista* disciplina1, Lista* disciplina2) {
    Lista* piores = cria_lista();
    Elem *no1 = *disciplina1, *no2 = *disciplina2;

    while ((no1 != NULL || no2 != NULL)) {
        struct aluno al;
        if (no1 != NULL && (no2 == NULL || no1->dados.nota_final < no2->dados.nota_final)) {
            al = no1->dados;
            no1 = no1->prox;
        } else {
            al = no2->dados;
            no2 = no2->prox;
        }
        insere_lista_ordenado(piores, al);
        if (conta_alunos(piores) == 10) break;
    }
    return piores;
}
