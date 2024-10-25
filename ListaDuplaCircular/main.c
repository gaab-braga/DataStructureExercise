#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Função para criar a lista
void criar_lista(Lista* lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

// Função para inserir um nó no fim da lista
void inserir_no_fim(Lista* lista, int num) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = num;
    novo->prox = NULL;
    novo->ant = lista->fim;

    if (lista->fim != NULL) {
        lista->fim->prox = novo;
    }
    lista->fim = novo;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    }

    lista->tamanho++;
}

// Função para imprimir a lista
void imprimir(Lista* lista) {
    No* aux = lista->inicio;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

// Função principal para testar
int main() {
    Lista lista;
    criar_lista(&lista);

    // Inserindo números 10, 20, 30, 40, 50 na lista
    inserir_no_fim(&lista, 10);
    inserir_no_fim(&lista, 20);
    inserir_no_fim(&lista, 30);
    inserir_no_fim(&lista, 40);
    inserir_no_fim(&lista, 50);

    printf("Lista original: ");
    imprimir(&lista);

    // Solicitando que o usuário escolha um número para trocar
    int num;
    printf("Digite o número que deseja trocar: ");
    scanf("%d", &num);

    // Testando a troca consecutiva com o número escolhido
    printf("Trocando o %d (se estiver na lista):\n", num);
    trocar_consecutivo(&lista, num);
    imprimir(&lista);

    return 0;
}
