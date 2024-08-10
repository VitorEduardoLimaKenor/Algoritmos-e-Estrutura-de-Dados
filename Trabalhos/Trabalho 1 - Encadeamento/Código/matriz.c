#include <stdio.h>
#include <stdlib.h>
#include "arquivo_matriz.h"

struct matriz{
    int num_lin;
    int num_col;
    struct elemento *mat;
};

/** Aloca e inicializa uma matriz com o número especificado de linhas e colunas.
    Retorna um ponteiro para uma estrutura Mat na posicao L0 e C0, que representa a matriz criada.
    Caso haja falha na alocação de memória, retorna NULL.   **/
Mat* criar_matriz(int num_lin, int num_col){

    Mat* matriz = (Mat*) malloc(sizeof(Mat));
    if(matriz == NULL){
        return NULL;
    }else{
        matriz->num_lin = num_lin;
        matriz->num_col = num_col;
    }

    int cont_lin = 0;
    Elem* no;
    Elem* aux;
    Elem* lin_ant = NULL;
    Elem* lin = NULL;

    while(cont_lin < num_lin){
        aux = NULL;

        for(int i = 0; i < num_col; i++){
            no = malloc(sizeof(Elem));
            if(no == NULL){
                return NULL;
            }

            no->cima = NULL;
            no->baixo = NULL;
            no->esquerda = aux;
            no->direita = NULL;
            no->pos_lin = cont_lin;
            no->pos_col = i;
            no->valor = 0;

            if(aux != NULL){
                aux->direita = no;
            }

            if(i == 0 && cont_lin == 0){
                matriz->mat = no;
            }

            if(i == 0){
                lin = no;
            }

            if(lin_ant != NULL){
                lin_ant->baixo = no;
                no->cima = lin_ant;
                lin_ant = lin_ant->direita;
            }

            aux = no;
        }

        cont_lin++;
        if(lin != NULL){
            lin_ant = lin;
        }

    }

    aux = NULL;
    lin = NULL;
    lin_ant = NULL;

    return matriz;
};

/** A função percorre a matriz, liberando os nós,
    em seguida, libera o ponteiro da estrutura da matriz. **/
int liberar_matriz(Mat* matriz){
    if(matriz == NULL || matriz->mat == NULL){
        return 0;
    }

    Elem* no;
    Elem* aux;

    while(matriz->mat != NULL){
        no = matriz->mat;
        matriz->mat = matriz->mat->baixo;

        while(no != NULL){
            aux = no;
            no = no->direita;
            free(aux);
        }

    }

    free(matriz);
    return 1;
}

/// A função percorre a matriz e atualiza o valor no nó correspondente à posição fornecida.
int insere_matriz(Mat* matriz, int pos_lin, int pos_col, int valor){
    if(matriz == NULL || matriz->mat == NULL){
        return 0;
    }

    Elem* lin = matriz->mat;
    Elem* no;

    while(lin != NULL){
        no = lin;
        lin = lin->baixo;

        while(no != NULL){

            if(no->pos_lin == pos_lin && no->pos_col == pos_col){
                no->valor = valor;
                return 1;
            }

            no = no->direita;

        }

    }

    return 0;
}

/** Retorna um ponteiro para o nó na posição especificada, ou NULL se a
    matriz for NULL ou a posição não for encontrada. **/
Elem* consulta_posicao_matriz(Mat* matriz, int pos_lin, int pos_col){
    if(matriz == NULL || matriz->mat == NULL){
        return NULL;
    }

    Elem* lin = matriz->mat;
    Elem* no;

    while(lin != NULL){
        no = lin;
        lin = lin->baixo;

        while(no != NULL){

            if(no->pos_lin == pos_lin && no->pos_col == pos_col){
                return no;
            }

            no = no->direita;

        }

    }

    return NULL;
}

/** Retorna um ponteiro para o nó que contém o valor especificado, ou NULL se a
    matriz for NULL ou o valor não for encontrado. **/
Elem* consulta_valor_matriz(Mat* matriz, int valor){
    if(matriz == NULL || matriz->mat == NULL){
        return NULL;
    }

    Elem* lin = matriz->mat;
    Elem* no;

    while(lin != NULL){
        no = lin;
        lin = lin->baixo;

        while(no != NULL){

            if(no->valor == valor){
                return no;
            }

            no = no->direita;

        }

    }

    return NULL;
}

/** A função percorre a matriz e, ao encontrar o elemento na posição fornecida, imprime
    os valores dos nós vizinhos (acima, abaixo, esquerda e direita). Se um vizinho não existir,
    imprime "NULL" para essa direção. **/
void imprimir_vizinhos(Mat* matriz, int pos_lin, int pos_col){
    if(matriz == NULL || matriz->mat == NULL){
        return;
    }

    Elem* lin = matriz->mat;
    Elem* no;

    while(lin != NULL){
        no = lin;
        lin = lin->baixo;

        while(no != NULL){

             if(no->pos_lin == pos_lin && no->pos_col == pos_col){
                printf("\n\n>> Vizinhos do elemento da posicao %i e %i com valor %i :\n", pos_lin,
                                                                                          pos_col,
                                                                                          no->valor);
                if(no->cima != NULL)
                    printf("Valor do viziho de cima: %i\n", no->cima->valor);
                else
                    printf("Valor do viziho de cima: NULL\n");
                if(no->baixo != NULL)
                    printf("Valor do viziho de baixo: %i\n", no->baixo->valor);
                else
                    printf("Valor do viziho de baixo: NULL\n");
                if(no->esquerda != NULL)
                    printf("Valor do viziho da esquerda: %i\n", no->esquerda->valor);
                else
                    printf("Valor do viziho da esquerda: NULL\n");
                if(no->direita != NULL)
                    printf("Valor do viziho da direita: %i\n\n", no->direita->valor);
                else
                    printf("Valor do viziho da direita: NULL\n\n");

            }

            no = no->direita;

        }

    }
    printf("\n");
}

/** A função percorre a matriz e imprime os valores de cada elemento, organizados em linhas
    e colunas conforme especificado. Se a matriz for NULL, a função não faz nada. **/
void imprime_matriz(Mat* matriz){
    if(matriz == NULL || matriz->mat == NULL){
        return;
    }

    Elem* lin = matriz->mat;
    Elem* no;

    printf(">> Matriz[%i][%i]: \n", matriz->num_lin, matriz->num_col);
    while(lin != NULL){
        no = lin;
        lin = lin->baixo;

        while(no != NULL){
            printf(" %d ", no->valor);
            no = no->direita;
        }
        printf("\n");
    }
    printf("\n\n");

}

/** A função verifica se o novo tamanho é maior que o tamanho atual e, se for, aloca novos nós
    para expandir a matriz horizontal e verticalmente, conectando-os aos nós existentes. **/
int aumentar_matriz(Mat* matriz, int num_lin, int num_col){
    if(matriz == NULL || matriz->mat == NULL){
        return 0;
    }

    if(num_lin < matriz->num_lin){
        return 0;
    }

    if(num_col < matriz->num_col){
        return 0;
    }

    int num_add_lin = num_lin - matriz->num_lin;
    int num_add_col = num_col - matriz->num_col;
    int num = 0;
    Elem* lin = matriz->mat;
    Elem* aux1;
    Elem* aux2;
    Elem* no;

    while(lin != NULL){
        aux1 = lin;

        while(aux1->direita != NULL){
            aux1 = aux1->direita;
        }

        for(int i = 0; i < num_add_col; i++){
            no = malloc(sizeof(Elem));
            if(no == NULL){
                return 0;
            }
            if(aux1->pos_lin == 0){
                no->cima = NULL;
            }
            else{
                no->cima = aux1->cima->direita;
                aux1->cima->direita->baixo = no;
            }
            no->baixo = NULL;
            no->esquerda = aux1;
            aux1->direita = no;
            no->direita = NULL;
            no->pos_lin = aux1->pos_lin;
            no->pos_col = aux1->pos_col + 1;
            no->valor = 0;
            aux1 = no;
        }

        if(lin->baixo == NULL && num < num_add_lin){
            no = malloc(sizeof(Elem));
            if(no == NULL){
                return 0;
            }
            lin->baixo = no;
            no->cima = lin;
            no->baixo = NULL;
            no->esquerda = NULL;
            no->direita = NULL;
            no->pos_lin = lin->pos_lin + 1;
            no->pos_col = 0;
            no->valor = 0;
            aux2 = no;

            for(int i = 1; i < matriz->num_lin; i++){
                no = malloc(sizeof(Elem));
                if(no == NULL){
                    return 0;
                }

                no->cima = aux2->cima->direita;
                aux2->cima->direita->baixo = no;
                no->baixo = NULL;
                no->esquerda = aux2;
                aux2->direita = no;
                no->direita = NULL;
                no->pos_lin = aux2->pos_lin;
                no->pos_col = aux2->pos_col + 1;
                no->valor = 0;
                aux2 = no;
            }

            num++;
            lin = lin->baixo;
        }else{
            lin = lin->baixo;
        }

    }

    matriz->num_lin = num_lin;
    matriz->num_col = num_col;
    return 1;
}

/** A função percorre a matriz e remove nós das colunas e linhas que excedem o novo tamanho. Libera a memória
    dos nós removidos e atualiza o ponteiro para o próximo nó conforme necessário. **/
int diminuir_matriz(Mat* matriz, int num_lin, int num_col){
    if(matriz == NULL || matriz->mat == NULL){
        return 0;
    }
    if(num_lin > matriz->num_lin){
        return 0;
    }
    if(num_col > matriz->num_col){
        return 0;
    }

    Elem* lin = matriz->mat;
    Elem* aux1;
    Elem* aux2;

    while(lin != NULL){
        aux1 = lin;

        while(aux1 != NULL && aux1->pos_col < num_col){
            aux1 = aux1->direita;
        }
        while(aux1 != NULL){
            aux1->esquerda->direita = NULL;
            aux2 = aux1;
            aux1 = aux1->direita;
            free(aux2);
        }

        if(lin->baixo->pos_lin > num_lin - 1){
            aux1 = lin->baixo;

            while(lin != NULL){
                lin->baixo = NULL;
                lin = lin->direita;
            }

            lin = aux1;
            while(lin != NULL){
                aux1 = lin;
                lin = lin->baixo;
                while(aux1 != NULL){
                    aux2 = aux1;
                    aux1 = aux1->direita;
                    free(aux2);
                }
            }
        }
        else{
            lin = lin->baixo;
        }
    }

    matriz->num_lin = num_lin;
    matriz->num_col = num_col;
    return 1;
}

/// Exibindo meu nome e o da minha dupla, fomos os criadores das funcoes acima
void creditos(){
    printf("---------------------------------------------------------\n");
    printf("|!!                      AUTORES                      !!|\n");
    printf("---------------------------------------------------------\n");
    printf("|                VITOR EDUARDO DE LIMA KENOR            |\n");
    printf("|                MAYARA RODRIGUES PEREIRA               |\n");
    printf("---------------------------------------------------------\n\n");
}

