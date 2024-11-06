struct aluno{
    int codigo;
    char nome[50];
    float ap1, ap2, ap3, ap4, np;
    float av;
};

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem; //onde for struct elemento trocar por "Elem"
typedef struct elemento* Lista; //onde for struct elemento* li trocar por "Lista* li"
typedef struct aluno Aluno; //onde for struct aluno trocar por "Aluno"

//func base
Lista* cria_lista();
void libera_lista(Lista* li);
int lista_vazia(Lista* li);
int tamanho_lista(Lista* li);
void imprime_lista(Lista* li);

//manipulação
int insere_lista_inicio(Lista* li, Aluno al); //al é um objeto que acessa as variáveis da struct aluno e diferencia os diferentes alunos
int insere_lista_final(Lista* li, Aluno al);
int remove_lista_inicio(Lista* li);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista_final(Lista* li);
int consulta_lista_(Lista* li, int codigo, Aluno al);



