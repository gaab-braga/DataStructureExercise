#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

float calcula_nota_final(struct aluno al);

int main() {
 struct aluno {
 int matricula;
 char nome[30];
 float ap1,ap2,ap3,ap4,np,av;
};

struct aluno estrutura_de_dados[10] = {{16350,"Joao",5.0,5.0,5.5,3.5,4.5,0.0},
 {17890,"Ricardo",7.0,8.0,6.2,4.3,5.8,0.0},
 {16350,"Bianca",1.0,1.1,2.2,2.7,4.1,0.0},
 {16350,"Jose",1.0,1.1,2.5,2.9,3.1,0.0},
 {11234,"Marcelo",2.0,7.0,2.5,2.9,4.6,0.0},
{17890,"Carla",7.0,2.3,2.4,3.6,4.3,0.0},
{17823,"Fabiano",1.0,1.7,2.8,3.0,3.1,0.0},
{15212,"Ana",8.0,1.6,2.9,3.1,3.5,0.0},
 {15542,"Joaquim",5.0,8.6,9.9,8.1,6.5,0.0},
 {13452,"Gabriel",8.0,6.4,9.5,7.5,5.7,0.0}};

struct aluno fabrica_de_projetos2[10] = {{16340,"Fábio",8.0,9.0,7.5,5.5,9.5,0.0},
 {17390,"Rafael",9.0,8.0,8.5,7.5,5.0,0.0},
 {12350,"Luana",8.0,9.1,8.2,7.7,6.5,0.0},
 {15350,"Carlos",5.0,7.1,8.5,9.9,8.1,0.0},
 {12244,"Maria",8.0,7.0,8.5,9.9,8.5,0.0},
 {14560,"Luiza",9.0,6.5,7.5,8.5,7.5,0.0},
 {12523,"Roberto",8.0,7.7,8.8,8.0,6.1,0.0},
 {15514,"Tiago",9.0,8.0,9.9,8.1,7.5,0.0},
 {13542,"Humberto",8.0,6.0,8.9,7.1,8.5,0.0},
 {16432,"Samuel",6.0,6.0,9.5,8.5,7.0,0.0}};

    Lista *li;
    li = cria_lista();

    // Inserção de alunos
    // for (int i = 0; i < 5; i++) {
    //    insere_lista_final(li, a[i]);
    // }

    // Impressão da lista
    imprime_lista(li);

    // Liberação da memória
    libera_lista(li);

    return 0;
}

// Função que calcula a nota final com base nas notas fornecidas
float calcula_nota_final(struct aluno al) {
    float media = ((al.n1 + al.n2 + al.n3 + al.n4) / 0.4)*0.4 + (al.np)*0.6;
    return media;
}
