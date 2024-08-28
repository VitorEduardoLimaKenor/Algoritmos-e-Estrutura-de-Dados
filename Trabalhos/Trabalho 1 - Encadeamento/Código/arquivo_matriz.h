#ifndef ARQUIVO_MATRIZ_H_INCLUDED
#define ARQUIVO_MATRIZ_H_INCLUDED

struct elemento{
    int valor;
    int pos_lin;
    int pos_col;
    struct elemento *direita;
    struct elemento *esquerda;
    struct elemento *cima;
    struct elemento *baixo;
};
typedef struct elemento Elem;

typedef struct matriz Mat;

/// funcoes requisitadas
Mat* criar_matriz(int num_lin, int num_col);
int liberar_matriz(Mat* matriz);
int insere_matriz(Mat* matriz, int pos_lin, int pos_col, int valor);
Elem* consulta_posicao_matriz(Mat* matriz, int pos_lin, int pos_col);
Elem* consulta_valor_matriz(Mat* matriz, int valor);
void imprimir_vizinhos(Mat* matriz, int pos_lin, int pos_col);

/// funcoes adicionais
void imprime_matriz(Mat* matriz);
int aumentar_matriz(Mat* matriz, int num_lin, int num_col);
int diminuir_matriz(Mat* matriz, int num_lin, int num_col);
void menu();

#endif // ARQUIVO_MATRIZ_H_INCLUDED
