#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    int valor;
    struct no* prox; // Próximo nó na lista
    struct no* ant;  // Nó anterior na lista
} No;

typedef struct lista {
    No* inicio; // Aponta para o primeiro nó
    No* fim;    // Aponta para o último nó (adicionando este membro)
    int tamanho; // Armazena o tamanho da lista
} Lista;

// Funções de manipulação da lista
void criar_lista(Lista* lista);
void inserir_no_inicio(Lista* lista, int num);
void inserir_no_fim(Lista* lista, int num);
void inserir_ordenado(Lista* lista, int num);
No* remover(Lista* lista, int num);
No* buscar(Lista* lista, int num);
void imprimir(Lista* lista);
void trocar_consecutivo(Lista* lista, int num);

#endif // LISTA_H
