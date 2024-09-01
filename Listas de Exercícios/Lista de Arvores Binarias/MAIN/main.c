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

    printf("\naltura: %d\n\n",altura_ArvBin(raiz));
    system("pause");
    system("cls");


    /** Teste do exercicio numero 1 !!!

    printf("!!! Exercicio 1 !!!\n\n");
    printf("Quantidade de NO folha na Arvore: %i\n", CalcNO_folha(raiz));
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 2 !!!

    printf("!!! Exercicio 2 !!!\n\n");
    imprime_hierarquia(raiz);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 3 !!!

    int num;
    printf("!!! Exercicio 3 !!!\n\n");
    printf("Digite um valor: ");
    scanf("%i", &num);
    printf("Quantidade de valores aproximados a esse na Arvore: %i\n", qtdValor_aproximado_Arvore(raiz, num));
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 4 !!!

    printf("!!! Exercicio 4 !!!\n\n");
    imprimeDecre_folhas(raiz);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 5 !!!

    printf("!!! Exercicio 5 !!!\n\n");
    ArvBin* raiz2 = cria_ArvBin();

    for(i=0; i < N; i++)
        insere_ArvBin(raiz2,dados[i]);

    remove_ArvBin(raiz2,50);

    if(QtdNOarvores_iguais(raiz, raiz2) == TotalNO_Arvore(raiz)){
        printf("!!! As Arvores sao iguais !!!\n");
    }else{
        printf("!!! As Arvores nao sao iguais !!!\n");
    }
    libera_ArvBin(raiz2);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 6 !!!

    printf("!!! Exercicio 6 !!!\n\n");
    printf("-----ANTES-----\n");
    preOrdem_ArvBin(raiz);
    printf("-----------------\n");
    eliminaPares(raiz);
    printf("-----Depois-----\n");
    preOrdem_ArvBin(raiz);
    printf("-----------------\n");
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 7 !!!

    printf("!!! Exercicio 7 !!!\n\n");
    ArvBin* raiz2 = cria_ArvBin();

    for(i=0; i < N; i++)
        insere_ArvBin(raiz2,dados[i]);

    if(arvoresSimilares(raiz, raiz2)){
        printf("!!! As Arvores sao Similares !!!\n");
    }
    else{
        printf("!!! As Arvores nao sao Similares !!!\n");
    }
    libera_ArvBin(raiz2);
    system("pause");
    system("cls");

    **/


    /** Teste do exercicio numero 8!!!

    printf("!!! Exercicio 8 !!!\n\n");
    int C = 14;
    int letras[14] = {77, 70, 83, 68, 74, 80, 85, 65, 69, 72, 81, 84, 87, 75};

    ArvBin* teste = cria_ArvBin();
    for(int i=0; i < C; i++)
        insere_ArvBin(teste,letras[i]);

    preOrdemLetras_ArvBin(teste);
    system("pause");
    system("cls");

    libera_ArvBin(teste);

    **/

    /** Teste do exercicio numero 9 !!!

    printf("!!! Exercicio 9 !!!\n\n");
    int D = 9;
    /// 45 = +, 46 = 5, 32 = *, 36 = +, 24 = -, 17 = 6, 26 = 3, 33 = 4, 38 = 1.
    int operacao[9] = {45, 46, 32, 36, 24, 17, 26, 33, 38};
    ArvBin* teste = cria_ArvBin();

    for(int i=0; i < D; i++)
        insere_ArvBin(teste,operacao[i]);

    printf("-----PreOrdem-----\n");
    preOrdemOperacao_ArvBin(teste);
    printf("-----------------\n");
    printf("-----PosOrdem-----\n");
    posOrdemOperacao_ArvBin(teste);
    printf("-----------------\n");
    printf("-----EmOrdem-----\n");
    emOrdemOperacao_ArvBin(teste);
    printf("-----------------\n");

    printf("\nResultado da Operacao: %i\n", CalcNO_folha(teste));

    libera_ArvBin(teste);
    system("pause");
    system("cls");

    **/

    libera_ArvBin(raiz);
    return 0;

}

