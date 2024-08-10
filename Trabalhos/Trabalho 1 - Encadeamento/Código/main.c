#include <stdio.h>
#include <stdlib.h>
#include "arquivo_matriz.h"

int main(){

    int i = 0;
    Elem* info;
    Mat* matriz = criar_matriz(3, 3);

    for(int l = 0; l < 3; l++){
        for(int c = 0; c < 3; c++){
            i++;
            insere_matriz(matriz, l, c, i);
        }
    }

    printf("---------------------------------------------------------\n");
    printf("|!! Usando todas as funcoes desenvolvidas no trabalho !!|\n");
    printf("---------------------------------------------------------\n\n");
    imprime_matriz(matriz);

    info = consulta_posicao_matriz(matriz, 1, 2);
    printf("Resultado da consulta por posicao 1 e 2 : %i \n", info->valor);

    info = consulta_valor_matriz(matriz, 7);
    printf("\n\n>> Resultado da consulta por valor 7 :\n");
    printf("linha do elemento : %i\n", info->pos_lin);
    printf("coluna do elemento : %i\n", info->pos_col);

    imprimir_vizinhos(matriz, 1, 1);

    aumentar_matriz(matriz, 7, 6);

    insere_matriz(matriz, 6, 5, 12);

    imprime_matriz(matriz);

    info = consulta_valor_matriz(matriz, 12);
    printf(">> Resultado da consulta por valor 12 :\n");
    printf("linha do elemento : %i\n", info->pos_lin);
    printf("coluna do elemento : %i\n", info->pos_col);

    diminuir_matriz(matriz, 5, 5);

    insere_matriz(matriz, 2, 4, 131);
    insere_matriz(matriz, 3, 4, 76);

    imprimir_vizinhos(matriz, 3, 4);

    imprime_matriz(matriz);

    liberar_matriz(matriz);

    system("pause");
    system("cls");
    creditos();
    return 0;
}

