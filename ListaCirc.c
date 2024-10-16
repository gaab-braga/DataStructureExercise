#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaCirc.h"

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista)); //aloca memória de forma dinamica, do tamanho da lista
    if(li != NULL)
        *li = NULL;
    return li;
}
void libera_lista(Lista* li){
    if(li != NULL && *li != NULL) //verifica se a lista e seus elementos são válidos
    {
        Elem* aux, *no = *li; //ponteiros auxiliares para percorrer a lista
        do{
            aux = no; //armazena o elemento atual
            no = no->prox; // avança para o próximo elemento 
            free(aux); //libera o elemento atual
        } while(no != *li); //continua até retornar ao início da lista
        free(li); //libera a lista
    } //n pode usar apenas free(li) para evitar vazamento de memória
}
int lista_vazia(Lista* li){
    return(li == NULL || *li == NULL);
}
float calcular_nota(struct aluno al){
    float media_parcial = (al.ap1 + al.ap2 + al.ap3 + al.ap4) / 4;
    return (media_parcial * 0.4) + (al.np * 0.6); //retorna o valor da média final (o al.np acessa o aluno e sua nota da prova dentro da struct aluno)
} 

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL) return 0; 
    
    Elem* no = (Elem*) malloc(sizeof(Elem)); //aloca memória para um novo elemento
    if(no == NULL) return 0;
    no->dados = al; //copia os dados do aluno para o novo elemento
    no->dados.av = calcular_nota(al);//calcula a nota final e armazena dentro da subcategoria av dentro do objeto al na struct aluno
    if(*li ==  NULL){
        *li = no; //caso a lista esteja vazia, define o elemento adicionado como o primeiro da lista
        no->prox = no; //define o próximo como ele mesmo para a circularidade
    }
    else{
        Elem *ant = NULL, *atual = *li; //ponteiros que vão percorrer a lista
        do{
            if(no->dados.av > atual->dados.av) break; //encontra a posição correta com base na nota final
            ant = atual; //mantém o elemento anterior
            atual = atual->prox; //avança para o proximo elemento
        } while(atual != *li); //continua até percorrer 
        if (ant == NULL){ //se a inserção for no início da lista
            Elem* ult = *li; //encontra o último elemento da lista
            while (ult->prox != *li)
                ult = ult->prox;
            no->prox = *li; //insere o novo elemento no início
            ult->prox = no; //o último elemento aponta para o novo primeiro
            *li = no; //atualiza o inicio da lista
        }
        else{
            ant->prox = no; //o anerior aponta para o novo
            no->prox = atual;
        }
    }
    return 1;
}
void imprime_lista(Lista* li) {
    if (lista_vazia(li)) {  // Verifica se a lista está vazia
        printf("Lista vazia.\n");
        return;
    }

    Elem* no = *li;  //ponteiro para percorrer a lista
    do {
        //imprime os dados do aluno
        printf("Código: %d\n", no->dados.codigo);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %.2f, %.2f, %.2f, %.2f\n", 
               no->dados.ap1, no->dados.ap2, no->dados.ap3, no->dados.ap4);
        printf("Nota Prova: %.2f\n", no->dados.np);
        printf("Nota Final: %.2f\n", no->dados.av);  //imprime a nota final
        printf("-------------------------\n");
        no = no->prox;  //avança para o próximo elemento
    } while (no != *li);  //continua até retornar ao início da lista

// do...while (faça depois confira)

}
int remove_lista_inicio(Lista* li){ //remove o primeiro elemento
    if(lista_vazia(li)) return 0;

    Elem* no = *li; //ponteiro para o primeiro elemento
    if(no->prox == *li){ //caso haja apenas um elemento
        free(no); //libera o unico elemento
        *li = NULL; //atribui o valor da lista como nulo
    }else{
        Elem* ult = *li; //aponta pro ultimo elemento
        while (ult->prox != *li){
            ult = ult->prox;
            ult->prox = no->prox; //último elemento aponta pro novo primeiro elemento
            *li = no->prox; //atualiza o ponteiro do início
            free(no); //libera o primeiro elemento (remove)
        }
    }
    return 1; //deu boa
}
int remove_lista_final(Lista *li){ //remove o último elemento 
    if(lista_vazia(li)) return 0;

    Elem* ant = NULL, *no = *li; //ponteiros que percorrem a lista
    if(no->prox == *li){ //apenas um elemento
        free(no);
        *li = NULL;
    } else{
        while (no->prox != *li){ //percorre a lista até o último elemento
            ant = no; //mantém o anterior
            no = no->prox; //avança pro próximo
        }
        ant->prox = *li; //anterior passa a ser o último
        free(no); //libera o nó (ultimo elemento)
    }
    return 1; //deu boa
}
