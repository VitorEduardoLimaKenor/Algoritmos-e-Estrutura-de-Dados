//Arquivo ListaDinEncad.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);

/// Funcoes dos exercicios desenvolvidas por mim e minha dupla
int consulta_matricula(Lista* li, int matricula, struct aluno *al);
int consulta_posicao(Lista* li, int posicao, struct aluno *al);
int remove_no(Lista* li, int mat);
int listas_iguais(Lista* L1, Lista* L2);
int insere_valor(Lista* li, struct aluno al, int posicao);
Lista* lista_vetor(float *vet, int tam);
void imprime_lista_vetor(Lista* li);
int remove_info(Lista* li, int num_mat);
Lista* concatenar_listas(Lista* L1, Lista* L2);
int remove_repetidos(Lista* li);
Lista* fusao_ordenada(Lista* L1, Lista* L2);
int Troca_posicao(Lista* li, int matricula);
