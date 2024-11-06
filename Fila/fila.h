#ifndef FILA_H
#define FILA_H

typedef struct no_fila {
    int valor;
    struct no_fila* proximo;
} NoFila;

typedef struct fila {
    NoFila* inicio;
    NoFila* fim;
} Fila;

void criar_fila(Fila* fila);
void inserir_fila(Fila* fila, int valor);
int remover_fila(Fila* fila);
int fila_vazia(Fila* fila);

#endif // FILA_H
