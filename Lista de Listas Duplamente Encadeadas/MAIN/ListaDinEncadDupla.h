//Arquivo ListaDinEncadDupla.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;
typedef struct fila Fila;

Lista* cria_lista();
Fila* cria_Fila();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
void libera_Fila(Fila* fi);
void imprime_Fila(Fila* fi);


/// Funcoes dos exercicios desenvolvidas por mim e minha dupla
int remove_aluno(Lista* li, int matricula);
int insere_lista_ordenada(Lista* li, struct aluno al);
int conta_lista_nota(Lista* li, int n1);
int insere_lista_circular_inicio(Lista* li, struct aluno al);
int insere_lista_circular_final(Lista* li, struct aluno al);
int remove_lista_circular_inicio(Lista* li);
int remove_lista_circular_final(Lista* li);
void imprime_lista_circular(Lista* li);
void libera_lista_circular(Lista* li);
int enfileirar(Fila* fi, int info);
int desenfileirar(Fila* fi);
