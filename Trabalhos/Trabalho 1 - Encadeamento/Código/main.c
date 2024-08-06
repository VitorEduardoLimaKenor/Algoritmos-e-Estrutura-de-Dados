#include <stdio.h>
#include <stdlib.h>
#include "arquivo_matriz.h"

int main(){

    int i = 0;
    Elem* info;
    Mat* matriz = criar_matriz(3, 3);

    printf(">> Matriz: \n");
    for(int l = 0; l < 3; l++){
        for(int c = 0; c < 3; c++){
            i++;
            insere_matriz(matriz, l, c, i);
        }
    }

    imprime_matriz(matriz);

    printf("\n");
    info = consulta_posicao_matriz(matriz, 1, 2);
    printf("\nResultado da consulta por posicao 1 e 2 : %i \n", info->valor);

    info = consulta_valor_matriz(matriz, 7);
    printf("\n\n>> Resultado da consulta por valor 7 :\n");
    printf("linha do elemento : %i\n", info->pos_lin);
    printf("coluna do elemento : %i\n", info->pos_col);

    imprimir_vizinhos(matriz, 1, 1);

    liberar_matriz(matriz);

    return 0;
}
