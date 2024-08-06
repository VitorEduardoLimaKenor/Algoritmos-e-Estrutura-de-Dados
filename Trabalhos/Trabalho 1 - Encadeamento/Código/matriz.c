#include <stdio.h>
#include <stdlib.h>
#include "arquivo_matriz.h"

struct matriz{
    int num_lin;
    int num_col;
    struct elemento *mat;
};

/// Alocando a struct matriz e definindo o numero de linhas e colunas
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

void imprime_matriz(Mat* matriz){
    if(matriz == NULL || matriz->mat == NULL){
        return;
    }

    Elem* lin = matriz->mat;
    Elem* no;

    while(lin != NULL){
        no = lin;
        lin = lin->baixo;

        while(no != NULL){
            printf(" %d ", no->valor);
            no = no->direita;
        }
        printf("\n");
    }

}

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
                printf("Valor do viziho de cima: %i\n", no->cima->valor);
                printf("Valor do viziho de baixo: %i\n", no->baixo->valor);
                printf("Valor do viziho da esquerda: %i\n", no->esquerda->valor);
                printf("Valor do viziho da direita: %i\n", no->direita->valor);
            }

            no = no->direita;

        }

    }

}

int aumentar_matriz(Mat* matriz, int num_lin, int num_col){
    if(matriz == NULL || matriz->mat == NULL){
        return 0;
    }
    matriz->num_lin = num_lin;
    matriz->num_col = num_col;

    if(num_lin < matriz->num_lin){
        return 0;
    }

    if(num_col < matriz->num_col){
        return 0;
    }

    int num_add_lin = matriz->num_lin - num_lin;
    int num_add_col = matriz->num_col - num_col;


}

