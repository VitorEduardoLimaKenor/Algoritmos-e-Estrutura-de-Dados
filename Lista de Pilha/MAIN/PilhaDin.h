//Arquivo PilhaDin.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int consulta_topo_Pilha(Pilha* pi, struct aluno *al);
int insere_Pilha(Pilha* pi, struct aluno al);
int remove_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int Pilha_cheia(Pilha* pi);
void imprime_Pilha(Pilha* pi);

/// Funcoes dos exercicios desenvolvidas por mim e minha dupla
void pop2(Pilha* pi);
void push2(Pilha* pi, struct aluno al1, struct aluno al2);
void popN(Pilha* pi, int n);
Pilha *pilha_copia(Pilha* pi);
void info_pilha(Pilha* pi);
void calculadora(Pilha* pi);
void checa_texto(Pilha* pi);
void par_impar(Pilha* pi);
void verifica_repetidos(Pilha *pi);
void conversao(int num);
void menu();
