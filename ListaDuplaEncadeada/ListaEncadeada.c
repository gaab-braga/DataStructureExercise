#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"


float calcula_nota_final(struct aluno al) {
    // 40% da média das avaliações parciais + 60% da nota da prova final (NP)
    return ((al.ap1 + al.ap2 + al.ap3 + al.ap4) / 4.0) * 0.4 + (al.np * 0.6);
}


Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));  // Aloca espaço para o ponteiro da lista
    if (li != NULL) {
        *li = NULL;  // Inicializa a lista como vazia (ponteiro NULL)
    }
    return li;
}

void libera_lista(Lista* li) {
    if (li != NULL) {
        Elem* no;  // Variável auxiliar para percorrer a lista
        while ((*li) != NULL) {
            no = *li;  // Pega o primeiro nó
            *li = (*li)->prox;  // Avança para o próximo nó
            free(no);  // Libera o nó atual
        }
        free(li);  // Libera o ponteiro da lista
    }
}

// Insere um aluno na lista de forma ordenada (maior nota para menor)
int insere_lista_ordenado(Lista* li, struct aluno al) {
    if (li == NULL) return 0;  // Verifica se a lista existe
    
    Elem *no = (Elem*) malloc(sizeof(Elem));  // Cria um novo nó
    if (no == NULL) return 0;  // Verifica se o nó foi alocado corretamente
    
    no->dados = al;  // Copia os dados do aluno para o nó
    no->dados.nota_final = calcula_nota_final(al);  // Calcula a nota final do aluno

    if ((*li) == NULL) {  // Se a lista está vazia, insere o nó como o primeiro
        no->prox = NULL;   // Não há próximo
        no->ant = NULL;    // Não há anterior
        *li = no;          // Atualiza a lista para apontar para o novo nó
        return 1;
    } else {  // Caso contrário, insere ordenadamente pela nota final
        Elem *atual = *li;
        // Procura a posição correta para inserir o aluno (ordem decrescente)
        while (atual != NULL && atual->dados.nota_final > no->dados.nota_final) {
            atual = atual->prox;
        }

        // Insere no início da lista
        if (atual == *li) {
            no->ant = NULL;  // Não há anterior
            no->prox = *li;  // O próximo será o antigo primeiro nó
            (*li)->ant = no;  // Atualiza o anterior do antigo primeiro nó
            *li = no;  // O novo nó se torna o primeiro da lista

        } else {  // Insere no meio ou no final da lista
            no->prox = atual;  // O próximo do novo nó será o nó atual
            no->ant = atual->ant;  // O anterior será o anterior do nó atual
            
            if (atual != NULL) {  // Se não for o final da lista
                atual->ant->prox = no;  // Atualiza o ponteiro do nó anterior
                atual->ant = no;  // Atualiza o anterior do nó atual
            } else {  // Se for inserção no final
                no->ant->prox = no;  // O novo nó é o próximo do antigo último nó
            }
        }
        return 1;
    }
}

// Função para imprimir os alunos da lista (exibe matrícula, nome e nota final)
void imprime_lista(Lista* li) {
    if (li == NULL) return;  // Verifica se a lista existe
    Elem* no = *li;  // Ponteiro auxiliar para percorrer a lista
    while (no != NULL) {
        printf("Matricula: %d Nome: %s Nota Final: %.2f\n", no->dados.matricula, no->dados.nome, no->dados.nota_final);
        no = no->prox;  // Avança para o próximo nó
    }
}


int conta_alunos(Lista* li) {
    if (li == NULL) return 0;  // Verifica se a lista existe
    int count = 0;  // Contador
    Elem* no = *li;  // Ponteiro auxiliar para percorrer a lista
    while (no != NULL) {
        count++;  // Incrementa o contador para cada nó
        no = no->prox;  // Avança para o próximo nó
    }
    return count;  // Retorna a quantidade de alunos
}


Lista* cria_lista_melhores_notas(Lista* disciplina1, Lista* disciplina2) {
    Lista* melhores = cria_lista();  // Cria uma nova lista para armazenar as melhores notas
    Elem *no1 = *disciplina1, *no2 = *disciplina2;  // Ponteiros para percorrer as duas listas

    // Enquanto houver elementos em uma das listas
    while ((no1 != NULL || no2 != NULL)) {
        struct aluno al;
        // Seleciona o aluno com a maior nota final entre as duas listas
        if (no1 != NULL && (no2 == NULL || no1->dados.nota_final > no2->dados.nota_final)) {
            al = no1->dados;
            no1 = no1->prox;
        } else {
            al = no2->dados;
            no2 = no2->prox;
        }
        // Insere o aluno na nova lista de melhores
        insere_lista_ordenado(melhores, al);
        // Para quando atingir 10 alunos
        if (conta_alunos(melhores) == 10) break;
    }
    return melhores;
}


Lista* cria_lista_piores_notas(Lista* disciplina1, Lista* disciplina2) {
    Lista* piores = cria_lista();  // Cria uma nova lista para armazenar as piores notas
    Elem *no1 = *disciplina1, *no2 = *disciplina2;  // Ponteiros para percorrer as duas listas

    // Enquanto houver elementos em uma das listas
    while ((no1 != NULL || no2 != NULL)) {
        struct aluno al;
        // Seleciona o aluno com a menor nota final entre as duas listas
        if (no1 != NULL && (no2 == NULL || no1->dados.nota_final < no2->dados.nota_final)) {
            al = no1->dados;
            no1 = no1->prox;
        } else {
            al = no2->dados;
            no2 = no2->prox;
        }
        // Insere o aluno na nova lista de piores
        insere_lista_ordenado(piores, al);
        // Para quando atingir 10 alunos
        if (conta_alunos(piores) == 10) break;
    }
    return piores;
}

// Função que concatena duas listas, mantendo-as ordenadas por nota final (da maior para a menor)
Lista* concatena_listas(Lista* disciplina1, Lista* disciplina2) {
    Lista* concatenada = cria_lista();  // Cria uma nova lista para armazenar a concatenação

    Elem* no1 = *disciplina1; // Ponteiro para percorrer a primeira lista
    Elem* no2 = *disciplina2; // Agora para a segunda lista

    // Insere todos os elementos da primeira lista na lista concatenada
    while (no1 != NULL) {
        insere_lista_ordenado(concatenada, no1->dados);
        no1 = no1->prox;
    }

    // Insere todos os elementos da segunda lista na lista concatenada
    while (no2 != NULL) {
        insere_lista_ordenado(concatenada, no2->dados);
        no2 = no2->prox;
    }

    return concatenada;  
}

void inverte_lista(Lista* li) {
    if (li == NULL || *li == NULL) return;

    Elem* atual = *li;
    Elem* temp = NULL;

    // Percorre a lista invertendo os ponteiros
    while (atual != NULL) {
        temp = atual->ant; // Salva o nó anterior para não perder a referência
        atual->ant = atual->prox; // Inverte o ponteiro anterior
        atual->prox = temp; // Inverte o ponteiro próximo
        atual = atual->ant;  // Move-se para o "próximo", que agora é o anterior
    }

    // Ajusta o novo primeiro nó da lista
    if (temp != NULL) {
        *li = temp->ant;  // O último nó se torna o primeiro
    }
}
