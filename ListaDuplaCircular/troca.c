#include <stddef.h>
#include "lista.h"

void trocar_consecutivo(Lista* lista, int num) {
    // Verificar se a lista está vazia ou contém um único elemento
    if (lista->inicio == NULL || lista->inicio->prox == NULL) {
        return;
    }

    No* atual = lista->inicio;

    // Percorrer a lista em busca do nó que contém o valor `num`
    while (atual != NULL) {
        if (atual->valor == num) {
            // Verificar se o nó atual é o último da lista
            if (atual == lista->fim) {
                No* primeiro = lista->inicio;  // Primeiro nó

                // Se o nó atual (último) e o primeiro nó são diferentes, trocamos
                if (primeiro != lista->fim) {
                    No* penultimo = lista->fim->ant;  // Penúltimo nó

                    // Atualizar ponteiros do penúltimo nó e o primeiro nó
                    lista->fim = primeiro;  // O novo último será o antigo primeiro
                    lista->inicio = atual;  // O novo primeiro será o antigo último

                    penultimo->prox = primeiro;  // O penúltimo agora aponta para o antigo primeiro
                    primeiro->ant = penultimo;   // Ajusta o ponteiro anterior do antigo primeiro

                    // Ajustar ponteiros entre o último e o primeiro nó
                    No* temp_prox = atual->prox;
                    atual->prox = primeiro->prox;
                    primeiro->prox = temp_prox;

                    No* temp_ant = atual->ant;
                    atual->ant = primeiro->ant;
                    primeiro->ant = temp_ant;

                    if (lista->fim->prox) {
                        lista->fim->prox->ant = lista->fim; // Ajustar o ponteiro do próximo nó do antigo último
                    }
                    return;  // Troca realizada, pode sair
                }
            }

            // Troca normal entre elementos consecutivos (não último e primeiro)
            if (atual->prox != NULL) {
                No* prox = atual->prox; // Próximo nó a ser trocado

                // Ajustar ponteiros para realizar a troca
                if (atual->ant != NULL) {
                    atual->ant->prox = prox;
                } else {
                    lista->inicio = prox; // Atualizando o início da lista se `atual` for o primeiro nó
                }

                if (prox->prox != NULL) {
                    prox->prox->ant = atual;
                } else {
                    lista->fim = atual; // Atualizando o fim da lista se `prox` for o último nó
                }

                // Realizar a troca de ponteiros entre os dois nós
                atual->prox = prox->prox;
                prox->ant = atual->ant;
                prox->prox = atual;
                atual->ant = prox;

                return; // Troca feita, podemos sair
            }
        }

        atual = atual->prox;
    }
}
