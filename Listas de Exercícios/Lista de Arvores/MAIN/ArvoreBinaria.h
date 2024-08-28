
typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
int remove_ArvBin(ArvBin *raiz, int valor);
struct NO* remove_atual(struct NO* atual);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
void preOrdem_ArvBin(ArvBin *raiz);

/// Funcoes dos exercicios desenvolvidas por mim e minha dupla
void emOrdem_Arvore(ArvBin *raiz);
void posOrdem_Arvore(ArvBin *raiz);
int TotalNO_Arvore(ArvBin *raiz);
int Cons_Arvore(ArvBin *raiz, int valor);
