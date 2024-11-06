#ifndef PILHA_H
#define PILHA_H

typedef struct no {
    int valor;
    struct no* proximo;
} No;

typedef struct pilha {
    No* topo;
} Pilha;

void criar_pilha(Pilha* pilha);
void empilhar(Pilha* pilha, int valor);
int desempilhar(Pilha* pilha);
int pilha_vazia(Pilha* pilha);

#endif // PILHA_H
