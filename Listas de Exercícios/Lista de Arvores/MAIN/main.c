#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    /// Usando as funcoes que foram disponibilizadas pelo professor
    printf("!!! Arvore criada com funcoes disponibilizadas pelo professor !!!\n\n");
    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);

    printf("-----------------\n");
    preOrdem_ArvBin(raiz);
    printf("-----------------\n");


    if(remove_ArvBin(raiz,50)){
        printf("\n!removido! \n\n");
        printf("-----------------\n");
        preOrdem_ArvBin(raiz);
        printf("-----------------\n");
    }else{
        printf("NAO removido\n");
    }

    printf("\naltura: %d\n",altura_ArvBin(raiz));
    system("pause");
    system("cls");

    /** Teste do exercicio numero 2 !!!

    printf("!!! Exercicio 2 !!!\n\n");
    printf("\n---EM_ORDEM---\n");
    emOrdem_Arvore(raiz);
    printf("--------------\n");
    printf("\n---POS_ORDEM---\n");
    posOrdem_Arvore(raiz);
    printf("---------------\n");
    system("pause");
    system("cls");

    **/


    /** Teste do exercicio numero 3 !!!

    printf("!!! Exercicio 3 !!!\n\n");
    printf("\n>>> Total de no's na arvore: %i\n", TotalNO_Arvore(raiz));
    system("pause");
    system("cls");

    **/


    /** Teste do exercicio numero 4 !!!

    int num;

    printf("!!! Exercicio 4 !!!\n\n");
    printf("\nQual valor deseja procurar na Arvore: ");
    scanf("%i", &num);

    if(Cons_Arvore(raiz, num) == 1){
        printf("\n>>> O Valor [%i] foi encontrado dentro da arvore\n\n", num);
    }
    else{
        printf("\n>>> O Valor [%i] não foi encontrado dentro da arvore\n\n", num);
    }
    system("pause");
    system("cls");

    **/

    libera_ArvBin(raiz);
    return 0;
}

