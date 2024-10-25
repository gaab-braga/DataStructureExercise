#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura para representar um paciente na fila
typedef struct no {
    int id;  // ID do paciente
    struct no* prox;  // Próximo paciente na fila
} No;

// Estrutura para representar a fila
typedef struct fila {
    No* inicio;  // Início da fila
    No* fim;     // Fim da fila
    int tamanho; // Tamanho da fila
} Fila;

// Função para inicializar uma fila
void inicializar_fila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

// Função para enfileirar um paciente
void enfileirar(Fila* fila, int id) {
    No* novo = (No*)malloc(sizeof(No));
    novo->id = id;
    novo->prox = NULL;

    if (fila->fim != NULL) {
        fila->fim->prox = novo;
    }
    fila->fim = novo;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
    }

    fila->tamanho++;
}

// Função para desenfileirar um paciente
int desenfileirar(Fila* fila) {
    if (fila->inicio == NULL) {
        return -1;  // Fila vazia
    }

    No* temp = fila->inicio;
    int id = temp->id;

    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(temp);
    fila->tamanho--;
    return id;
}

// Função para verificar se a fila está vazia
int fila_vazia(Fila* fila) {
    return fila->tamanho == 0;
}

// Função para escolher uma fila aleatória
int escolher_fila_aleatoria() {
    return rand() % 3;  // Retorna 0, 1 ou 2
}

// Função para exibir o conteúdo de uma fila
void imprimir_fila(Fila* fila, const char* tipo) {
    printf("Fila de %s: ", tipo);
    No* atual = fila->inicio;
    while (atual != NULL) {
        printf("%d ", atual->id);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));  // Inicializar a semente do gerador de números aleatórios

    // Criar filas para os três tipos de transplante
    Fila fila_coracao, fila_cornea, fila_medula;
    inicializar_fila(&fila_coracao);
    inicializar_fila(&fila_cornea);
    inicializar_fila(&fila_medula);

    // Simular 100 inserções aleatórias
    for (int i = 0; i < 100; i++) {
        int fila_escolhida = escolher_fila_aleatoria();
        int id_paciente = i + 1;  // IDs de 1 a 100

        switch (fila_escolhida) {
            case 0:
                enfileirar(&fila_coracao, id_paciente);
                break;
            case 1:
                enfileirar(&fila_cornea, id_paciente);
                break;
            case 2:
                enfileirar(&fila_medula, id_paciente);
                break;
        }
    }

    // Simular 40 remoções aleatórias
    for (int i = 0; i < 40; i++) {
        int fila_escolhida = escolher_fila_aleatoria();

        switch (fila_escolhida) {
            case 0:
                if (!fila_vazia(&fila_coracao)) {
                    desenfileirar(&fila_coracao);
                }
                break;
            case 1:
                if (!fila_vazia(&fila_cornea)) {
                    desenfileirar(&fila_cornea);
                }
                break;
            case 2:
                if (!fila_vazia(&fila_medula)) {
                    desenfileirar(&fila_medula);
                }
                break;
        }
    }

    // Exibir o estado final das filas
    imprimir_fila(&fila_coracao, "CORAÇÃO");
    imprimir_fila(&fila_cornea, "CÓRNEA");
    imprimir_fila(&fila_medula, "MEDULA");

    return 0;
}
