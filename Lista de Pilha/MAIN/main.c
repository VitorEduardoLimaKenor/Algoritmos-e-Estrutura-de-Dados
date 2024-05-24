#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDin.h"

int main(){
    struct aluno a[4] = {{4,"Andre",9.5,7.8,8.5},
                         {2,"Ricardo",7.5,8.7,6.8},
                         {3,"Bianca",9.7,6.7,8.4},
                         {1,"ana",5.7,6.1,7.4}};

    /// Usando as funcoes que foram disponibilizadas pelo professor
    printf("!!! Pilha criada com funcoes disponibilizadas pelo professor !!!\n\n");
    Pilha *pi = cria_Pilha();
    insere_Pilha(pi, a[0]);
    insere_Pilha(pi, a[1]);
    insere_Pilha(pi, a[2]);
    insere_Pilha(pi, a[3]);
    imprime_Pilha(pi);
    system("pause");
    system("cls");

    /** Teste do exercicio numero 1 !!!

    printf("!!! Exercicio 1 !!!\n\n");
    pop2(pi);
    printf("Removendo dois elementos de uma vez !!!\n\n");
    imprime_Pilha(pi);
    system("pause");
    system("cls");
    printf("!!! Exercicio 1 !!!\n\n");
    printf("Adicionando dois elementos de uma vez !!!\n\n");
    push2(pi, a[2], a[3]);
    imprime_Pilha(pi);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 2 !!!

    int n; /// Variavel para o exercicio 2
    printf("!!! Exercicio 2 !!!\n\n");
    printf("Quantos Elementos deseja remover: ");
    scanf("%i", &n);
    popN(pi, n);
    printf("\n");
    printf("!!! Pilha pos remocao !!!\n\n");
    imprime_Pilha(pi);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 3 !!!

    printf("!!! Exercicio 3 !!!\n\n");
    Pilha* pi_cop = pilha_copia(pi);
    printf("!!! Pilha original !!!\n\n");
    imprime_Pilha(pi);
    printf("\n\n\n");
    printf("!!! Pilha copia !!!\n\n");
    imprime_Pilha(pi_cop);
    libera_Pilha(pi_cop);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 4 !!!

    printf("!!! Exercicio 4 !!!\n\n");
    printf("!!! Maior, Menor e a media aritmetica das notas presente na pilha !!!\n\n");
    info_pilha(pi);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 5 !!!

    printf("!!! Exercicio 5 !!!\n\n");
    calculadora(pi);

    **/

    /** Teste do exercicio numero 6 !!!

    printf("!!! Exercicio 6 !!!\n\n");
    checa_texto(pi);

    **/

    /** Teste do exercicio numero 7 !!!

    printf("!!! Exercicio 7 !!!\n\n");
    par_impar(pi);

    **/

    /** Teste do exercicio numero 8 !!!

    printf("!!! Exercicio 8 !!!\n\n");
    verifica_repetidos(pi);

    **/

    /** Teste do exercicio numero 9 !!!

    menu();

    **/

    libera_Pilha(pi);
    return 0;
}
