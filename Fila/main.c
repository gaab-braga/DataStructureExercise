#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"
#include "lista.h"

#define NUM_INSERCOES 100
#define NUM_REMOCOES 40

void simular_operacoes() {
    // Criação de filas e listas para cada tipo de transplante
    Fila fila_coracao, fila_cornea, fila_medula;
    Lista lista_coracao, lista_cornea, lista_medula;

    criar_fila(&fila_coracao);
    criar_fila(&fila_cornea);
    criar_fila(&fila_medula);

    criar_lista(&lista_coracao);
    criar_lista(&lista_cornea);
    criar_lista(&lista_medula);

    clock_t inicio, fim;
    double tempo_fila_insercao = 0, tempo_lista_insercao = 0;
    double tempo_fila_remocao = 0, tempo_lista_remocao = 0;

    int valor, estrutura;

    // Simulação de inserções aleatórias
    for (int i = 0; i < NUM_INSERCOES; i++) {
        valor = rand() % 1000;
        estrutura = rand() % 2;

        if (estrutura == 0) { // Fila
            inicio = clock();
            inserir_fila(&fila_coracao, valor); // Fila de coração como exemplo
            fim = clock();
            tempo_fila_insercao += (double)(fim - inicio) / CLOCKS_PER_SEC;
        } else { // Lista
            inicio = clock();
            inserir_lista(&lista_coracao, valor); // Lista de coração como exemplo
            fim = clock();
            tempo_lista_insercao += (double)(fim - inicio) / CLOCKS_PER_SEC;
        }
    }

    // Simulação de remoções aleatórias
    for (int i = 0; i < NUM_REMOCOES; i++) {
        estrutura = rand() % 2;

        if (estrutura == 0) { // Fila
            inicio = clock();
            remover_fila(&fila_coracao); // Fila de coração como exemplo
            fim = clock();
            tempo_fila_remocao += (double)(fim - inicio) / CLOCKS_PER_SEC;
        } else { // Lista
            inicio = clock();
            remover_lista(&lista_coracao); // Lista de coração como exemplo
            fim = clock();
            tempo_lista_remocao += (double)(fim - inicio) / CLOCKS_PER_SEC;
        }
    }

    // Cálculo dos tempos médios
    double media_fila_insercao = tempo_fila_insercao / NUM_INSERCOES;
    double media_lista_insercao = tempo_lista_insercao / NUM_INSERCOES;
    double media_fila_remocao = tempo_fila_remocao / NUM_REMOCOES;
    double media_lista_remocao = tempo_lista_remocao / NUM_REMOCOES;

    printf("Tempo médio de inserção na FILA: %.10f segundos\n", media_fila_insercao);
    printf("Tempo médio de inserção na LISTA: %.10f segundos\n", media_lista_insercao);
    printf("Tempo médio de remoção na FILA: %.10f segundos\n", media_fila_remocao);
    printf("Tempo médio de remoção na LISTA: %.10f segundos\n", media_lista_remocao);
}

int main() {
    srand(time(NULL));
    simular_operacoes();
    return 0;
}

