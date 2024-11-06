#include "fila_prioridade.h"
#include <stdlib.h>
#include <stdio.h>

void criar_fila(FilaPrioridade* fila) {
    fila->inicio = NULL;
}

void inserir_paciente(FilaPrioridade* fila, int idade, int id) {
    Paciente* novo = (Paciente*) malloc(sizeof(Paciente));
    if (novo) {
        novo->idade = idade;
        novo->id = id;
        novo->proximo = NULL;

        if (!fila->inicio || fila->inicio->idade < idade) {
            // Inserir no início se a fila está vazia ou se o paciente é mais velho
            novo->proximo = fila->inicio;
            fila->inicio = novo;
        } else {
            // Procurar o lugar correto baseado na prioridade de idade
            Paciente* atual = fila->inicio;
            while (atual->proximo && atual->proximo->idade >= idade) {
                atual = atual->proximo;
            }
            novo->proximo = atual->proximo;
            atual->proximo = novo;
        }
    } else {
        printf("Erro ao alocar memoria\n");
    }
}

int remover_paciente(FilaPrioridade* fila) {
    if (fila->inicio) {
        Paciente* temp = fila->inicio;
        int id = temp->id;
        fila->inicio = temp->proximo;
        free(temp);
        return id;
    }
    printf("Fila vazia\n");
    return -1;
}

int fila_vazia(FilaPrioridade* fila) {
    return fila->inicio == NULL;
}
