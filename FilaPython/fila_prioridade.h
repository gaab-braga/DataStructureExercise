#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

typedef struct paciente {
    int idade;
    int id;
    struct paciente* proximo;
} Paciente;

typedef struct fila_prioridade {
    Paciente* inicio;
} FilaPrioridade;

void criar_fila(FilaPrioridade* fila);
void inserir_paciente(FilaPrioridade* fila, int idade, int id);
int remover_paciente(FilaPrioridade* fila);
int fila_vazia(FilaPrioridade* fila);

#endif // FILA_PRIORIDADE_H
