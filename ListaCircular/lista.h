#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    int valor;
    struct no* proximo;
} No;

typedef struct lista {
    No* inicio;
    No* fim;
    int tamanho;
} Lista;

// Funções de manipulação da lista
void criar_lista(Lista* lista);
void inserir_no_inicio(Lista* lista, int num);
void inserir_no_fim(Lista* lista, int num);
void inserir_ordenado(Lista* lista, int num);
No* remover(Lista* lista, int num);
No* buscar(Lista* lista, int num);
void imprimir(Lista* lista);

#endif // LISTA_H
