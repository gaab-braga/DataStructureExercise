#include <stdio.h>
#include "ListaEncadeada.h"

int main() {
    // Criação das listas para duas disciplinas
    Lista* disciplina1 = cria_lista();
    Lista* disciplina2 = cria_lista();

    // Inserção de alunos na disciplina 1 e 2
    struct aluno alunos_disciplina1[] = {
        {16350, "Joao", 5.0, 5.0, 5.5, 3.5, 4.5, 0.0},
        {17890, "Ricardo", 7.0, 8.0, 6.2, 4.3, 5.8, 0.0},
        {16350, "Bianca", 1.0, 1.1, 2.2, 2.7, 4.1, 0.0},
        {16350, "Jose", 1.0, 1.1, 2.5, 2.9, 3.1, 0.0},
        {11234, "Marcelo", 2.0, 7.0, 2.5, 2.9, 4.6, 0.0},
        {17890, "Carla", 7.0, 2.3, 2.4, 3.6, 4.3, 0.0},
        {17823, "Fabiano", 1.0, 1.7, 2.8, 3.0, 3.1, 0.0},
        {15212, "Ana", 8.0, 1.6, 2.9, 3.1, 3.5, 0.0},
        {15542, "Joaquim", 5.0, 8.6, 9.9, 8.1, 6.5, 0.0},
        {13452, "Gabriel", 8.0, 6.4, 9.5, 7.5, 5.7, 0.0}
    };

    struct aluno alunos_disciplina2[] = {
        {16340, "Fábio", 8.0, 9.0, 7.5, 5.5, 9.5, 0.0},
        {17390, "Rafael", 9.0, 8.0, 8.5, 7.5, 5.0, 0.0},
        {12350, "Luana", 8.0, 9.1, 8.2, 7.7, 6.5, 0.0},
        {15350, "Carlos", 5.0, 7.1, 8.5, 9.9, 8.1, 0.0},
        {12244, "Maria", 8.0, 7.0, 8.5, 9.9, 8.5, 0.0},
        {14560, "Luiza", 9.0, 6.5, 7.5, 8.5, 7.5, 0.0},
        {12523, "Roberto", 8.0, 7.7, 8.8, 8.0, 6.1, 0.0},
        {15514, "Tiago", 9.0, 8.0, 9.9, 8.1, 7.5, 0.0},
        {13542, "Humberto", 8.0, 6.0, 8.9, 7.1, 8.5, 0.0},
        {16432, "Samuel", 6.0, 6.0, 9.5, 8.5, 7.0, 0.0}
    };


    for (int i = 0; i < 10; i++) {
        insere_lista_ordenado(disciplina1, alunos_disciplina1[i]);
        insere_lista_ordenado(disciplina2, alunos_disciplina2[i]);
    }

    // Criar lista das 10 melhores notas
    Lista* melhores_notas = cria_lista_melhores_notas(disciplina1, disciplina2);
    printf("10 Melhores Notas:\n");
    imprime_lista(melhores_notas);

    // Criar lista das 10 piores notas
    Lista* piores_notas = cria_lista_piores_notas(disciplina1, disciplina2);
    printf("\n10 Piores Notas:\n");
    imprime_lista(piores_notas);

    // Liberação de memória
    libera_lista(disciplina1);
    libera_lista(disciplina2);
    libera_lista(melhores_notas);
    libera_lista(piores_notas);

    return 0;
}