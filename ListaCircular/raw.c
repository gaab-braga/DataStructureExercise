#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* proximo;
}No;

typedef struct lista{
    No* inicio;
    No* fim;
    int tamanho;
}Lista;

void criar_lista(Lista* lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

// procedimento para inserir no inicio 
void inserir_no_inicio(Lista* lista, int num)
{
    No* novo = (No*) malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        if(lista->tamanho == NULL)
            lista->fim = novo;
    
        lista->fim->proximo = lista->inicio;
        lista->tamanho++;
    }
    else
        printf("Erro ao alocar memoria");
    
    }

// procedimento para inserir no fim
void inserir_no_fim(Lista* lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;

        // é o primeiro?
        if(lista->inicio == NULL){
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
        }
        else
        {
            lista->fim->proximo = novo;
            lista->fim = novo;
            novo->proximo = lista->inicio;
        }
        lista->tamanho++;
    }
    else
        printf("Erro ao alocar memoria");
}

void inserir_ordenado(Lista* lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;

        // lista vazia
        if(lista->inicio == NULL){
            inserir_no_inicio(lista, num);
        }
        else if(novo->valor < lista->inicio->valor)
        {
            inserir_no_inicio(lista, num);
        }
        else
        {
            aux = lista->inicio;

            // percorre a lista
            while(aux->proximo != lista->inicio && novo->valor > aux->proximo->valor)
            aux = aux->proximo;
            if(aux->proximo == lista->inicio)
                inserir_no_fim(lista, num);
            else{
                novo->proximo = aux->proximo;
                aux->proximo = novo;
                lista->tamanho++;
                }
            }
        }
        else
            printf("Erro ao alocar memoria");
    }

// função remover um nó
No* remover(Lista* lista, int num){
    No *aux, *remover = NULL;

    if(lista->inicio)
    {
        if(lista->inicio == lista->fim && lista->inicio->valor == num)
        {
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tamanho--;
        }
        else if(lista->inicio->valor == num)
        {
            remover = lista->inicio;
            lista->inicio = lista->inicio->proximo;
            lista->fim->proximo = lista->inicio;
            lista->tamanho--;
        }
        else
        {
            aux = lista->inicio;
            while(aux->proximo != lista->inicio && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo->valor == num)
            {
                if(lista->fim == aux->proximo)
                    {
                        remover = aux->proximo;
                        aux->proximo = remover->proximo;
                        lista->fim = aux;
                    }
                else
                {
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                }
                lista->tamanho--;
            }
        }
    }
    return remover;
}

// função para buscar valor
No* buscar(Lista* lista, int num){
    No *aux = lista->inicio;

    if(aux)
    {
        do{
            if(aux->valor == num)
                return aux;
            aux = aux->proximo;
        }while(aux != lista->inicio);
    }
    return NULL;
}

// procedimento para imprimir a lista circular
void imprimir(Lista* lista){
    No *no = lista->inicio;
    printf("\n\tLista tam %d", lista->tamanho);

    if(no)
    {
        do{
            printf("%d ", no->valor);
            no = no->proximo;
        }while(no != lista->inicio);
        printf("\nInicio: %d\n", no->valor);
    }
    printf("\n");
}

int main()
{
    int opcao, valor, anterior;
    //No *lista == NULL
    Lista lista;
    No *removido;

    criar_lista(&lista);
    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - inserirF\n\t3 - Inserir Ordenado\n\t4 - Remover\n\t5 - Imprimir\n\t6 - Buscar\n ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1 : printf("Valor: ");
                     scanf("%d", &valor);
                     inserir_no_inicio(&lista, valor);
                     break;
            case 2 : printf("Valor: ");
                        scanf("%d", &valor);
                        inserir_no_fim(&lista, valor);
                        break;
            case 3 : printf("Valor: ");
                        scanf("%d", &valor);
                        inserir_ordenado(&lista, valor);
                        break;
            case 4 : printf("Valor: ");
                        scanf("%d", &valor);
                        removido = remover(&lista, valor);
                        if(removido)
                        {
                            printf("Removido: %d\n", removido->valor);
                        free(removido);
                        }
                        else
                            printf("Valor nao encontrado\n");
                        break;
            case 5 : imprimir(&lista);
                        break;
            case 6 : printf("Digite um Valor a ser buscado: ");
                        scanf("%d", &valor);
                        removido = buscar(&lista, valor);
                        if(removido)
                            printf("Valor encontrado: %d\n", removido->valor);
                        else
                            printf("Valor nao encontrado\n");
                        break;
            default: printf("Opcao invalida\n");
            
            }

        }while(opcao != 0);

    return 0;
}
