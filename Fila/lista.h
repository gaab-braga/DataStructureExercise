#ifndef LISTA_H
#define LISTA_H

typedef struct no_lista {
    int valor;
    struct no_lista* proximo;
} NoLista;

typedef struct lista {
    NoLista* inicio;
} Lista;

void criar_lista(Lista* lista);
void inserir_lista(Lista* lista, int valor);
int remover_lista(Lista* lista);
int lista_vazia(Lista* lista);

#endif // LISTA_H

