struct aluno {
    int matricula;
    char nome[30];
    int n1, n2, n3, n4, np;
};

typedef struct lista Lista;
Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
