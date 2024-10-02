#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

// Função que calcula a nota final com base nas notas fornecidas
float calcula_nota_final(struct aluno al) {
    return ((al.ap1 + al.ap2 + al.ap3 + al.ap4) / 4.0) * 0.4 + (al.np * 0.6);
}

// Função para criar a lista encadeada
Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL) {
        *li = NULL;
    }
    return li;
}

// Função para liberar a lista
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

// Função para inserir aluno de forma ordenada pela nota final (da maior para a menor)
int insere_lista_ordenado(Lista* li, struct aluno al) {
    if (li == NULL) return 0;
    
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    
    no->dados = al;
    no->dados.nota_final = calcula_nota_final(al);
    
    if ((*li) == NULL) { // Lista vazia, insere no início
        no->prox = NULL;
        *li = no;
        return 1;
    } else { // Inserção de forma ordenada
        Elem *ant = NULL, *atual = *li;
        while (atual != NULL && atual->dados.nota_final > no->dados.nota_final) {
            ant = atual;
            atual = atual->prox;
        }
        if (ant == NULL) { // Insere no início
            no->prox = *li;
            *li = no;
        } else { // Insere no meio ou final
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

// Função para imprimir a lista de alunos
void imprime_lista(Lista* li) {
    if (li == NULL) return;
    Elem* no = *li;
    while (no != NULL) {
        printf("Matricula: %d Nome: %s Nota Final: %.2f\n", no->dados.matricula, no->dados.nome, no->dados.nota_final);
        no = no->prox;
    }
}

// Função para contar a quantidade de alunos na lista
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

// Função para criar a lista das 10 melhores notas
Lista* cria_lista_melhores_notas(Lista* disciplina1, Lista* disciplina2) {
    Lista* melhores = cria_lista();

        // Contar quantos alunos existem nas duas disciplinas
    int total_alunos_disciplina1 = conta_alunos(disciplina1);
    int total_alunos_disciplina2 = conta_alunos(disciplina2);
    
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
        Elem *melhoresNo = *melhores;
        int count = 0;
        while (melhoresNo != NULL) {
            count++;
            melhoresNo = melhoresNo->prox;
        }
        if (count == 10) break; // Limite de 10
    }
    
    return melhores;
}

// Função para criar a lista das 10 piores notas
Lista* cria_lista_piores_notas(Lista* disciplina1, Lista* disciplina2) {
    Lista* piores = cria_lista();
    
    // Contar quantos alunos existem nas duas disciplinas
    int total_alunos_disciplina1 = conta_alunos(disciplina1);
    int total_alunos_disciplina2 = conta_alunos(disciplina2);

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
        Elem *pioresNo = *piores;
        int count = 0;
        while (pioresNo != NULL) {
            count++;
            pioresNo = pioresNo->prox;
        }
        if (count == 10) break; // Limite de 10
    }
    
    return piores;
}
