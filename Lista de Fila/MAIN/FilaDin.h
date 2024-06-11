//Arquivo FilaDin.h
struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct fila Fila;
typedef struct elemento* Pilha;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);
Pilha* cria_Pilha();
int insere_Pilha(Pilha* pi, struct aluno al);
void libera_Pilha(Pilha* pi);

/// Struct criada para exercicio 5
struct aviao{
    int qtd_passageiros;
    char empresa[30];
    char destino[30];
};
/// Funcoes dos exercicios desenvolvidas por mim e minha dupla
int separa(Fila* f1, Fila* f2, int n);
int insere_Fila_na_Fila(Fila* fi, Fila* fi_interna);
void imprime_Fila_de_filas(Fila* fi);
int insere_Pilha_na_Fila(Fila* fi, Pilha* pi);
void imprime_Fila_de_Pilhas(Fila* fi);
int insere_Fila_na_Pilha(Pilha* pi, Fila* fi);
void imprime_Pilha_de_Filas(Pilha* pi);
void preenche_fila(Fila* f1, Fila* f2, Fila* f3);
void inverte_fila(Fila* fi);
void fura_fila(Fila* fi, struct aluno al);
void menu();
void consulta_avioes(Fila* fi, struct aviao *av);
int insere_aviao_na_Fila(Fila* fi, struct aviao av);
void listar_avioes(Fila* fi);
void aeroporto();
void inverte_fila_com_pilha(Fila* fi);
void FilaCircular(Fila* fi, struct aluno al);
void imprime_fila_circular(Fila* fi);
