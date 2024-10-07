#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

// Estrutura do aluno
struct aluno {
    int matricula;
    char nome[30];
    float ap1, ap2, ap3, ap4, np, av;
    float nota_final;
};

// Estrutura do nó da lista
struct elemento {
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

typedef struct elemento* Lista;

// Funções para manipulação da lista encadeada
Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_ordenado(Lista* li, struct aluno al);
void imprime_lista(Lista* li);
int conta_alunos(Lista* li);

// Funções para melhores e piores notas
Lista* cria_lista_melhores_notas(Lista* disciplina1, Lista* disciplina2);
Lista* cria_lista_piores_notas(Lista* disciplina1, Lista* disciplina2);

#endif
