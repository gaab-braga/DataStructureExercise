#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila_prioridade.h"

#define NUM_INSERCOES 100  // Número de inserções para a simulação
#define NUM_REMOCOES 40    // Número de remoções para a simulação

void simular_operacoes(FilaPrioridade* fila_coracao, FilaPrioridade* fila_cornea, FilaPrioridade* fila_medula) {
    clock_t inicio, fim;
    double tempo_insercao = 0, tempo_remocao = 0;

    // Simulação de inserções aleatórias com prioridade (por idade)
    for (int i = 0; i < NUM_INSERCOES; i++) {
        int idade = rand() % 71 + 20; // Idade aleatória entre 20 e 90
        int tipo_fila = rand() % 3;    // Seleciona aleatoriamente entre as filas

        inicio = clock();
        if (tipo_fila == 0) {
            inserir_paciente(fila_coracao, idade, i); // Fila de Coração
        } else if (tipo_fila == 1) {
            inserir_paciente(fila_cornea, idade, i);  // Fila de Córnea
        } else {
            inserir_paciente(fila_medula, idade, i);  // Fila de Medula
        }
        fim = clock();
        tempo_insercao += (double)(fim - inicio) / CLOCKS_PER_SEC;
    }

    // Simulação de remoções aleatórias
    for (int i = 0; i < NUM_REMOCOES; i++) {
        int tipo_fila = rand() % 3; // Seleciona aleatoriamente entre as filas

        inicio = clock();
        if (tipo_fila == 0) {
            remover_paciente(fila_coracao); // Remover da Fila de Coração
        } else if (tipo_fila == 1) {
            remover_paciente(fila_cornea);  // Remover da Fila de Córnea
        } else {
            remover_paciente(fila_medula);  // Remover da Fila de Medula
        }
        fim = clock();
        tempo_remocao += (double)(fim - inicio) / CLOCKS_PER_SEC;
    }

    // Exibir resultados dos tempos médios
    printf("Tempo médio de inserção na Fila com Prioridade: %.10f segundos\n", tempo_insercao / NUM_INSERCOES);
    printf("Tempo médio de remoção na Fila com Prioridade: %.10f segundos\n", tempo_remocao / NUM_REMOCOES);
}

int main() {
    srand(time(NULL)); // Semente para geração de números aleatórios

    // Inicializar filas para cada tipo de transplante
    FilaPrioridade fila_coracao, fila_cornea, fila_medula;
    criar_fila(&fila_coracao);
    criar_fila(&fila_cornea);
    criar_fila(&fila_medula);

    // Realizar a simulação de operações na fila com prioridade
    simular_operacoes(&fila_coracao, &fila_cornea, &fila_medula);

    return 0;
}
