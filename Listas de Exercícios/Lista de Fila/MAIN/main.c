#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"

int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};

    /// Usando as funcoes que foram disponibilizadas pelo professor
    printf("!!! Fila criada com funcoes disponibilizadas pelo professor !!!\n\n");
    Fila* fi = cria_Fila();
    printf("Tamanho: %d\n\n",tamanho_Fila(fi));

    for(int i=0; i < 4; i++)
        insere_Fila(fi,a[i]);

    imprime_Fila(fi);
    printf("\nTamanho: %d\n\n\n\n",tamanho_Fila(fi));
    system("pause");
    system("cls");

    /** Teste do exercicio numero 1 !!!

    printf("!!! Exercicio 1 !!!\n\n");
    Fila* f2 = cria_Fila();
    separa(fi, f2, 4); /// Numero de matricula para separação foi 4
    printf("!!!! FILA 1 !!!!!\n\n");
    imprime_Fila(fi);
    printf("\n\n!!!!! FILA 2 !!!!!\n\n");
    imprime_Fila(f2);
    system("pause");
    system("cls");
    libera_Fila(f2);

    **/

    /** Teste do exercicio numero 2 !!!

    printf("!!! Exercicio 2 !!!\n\n\n");
    printf("|-------- Fila de Filas ---------|\n");
    Fila* f2 = cria_Fila();
    Fila* f3 = cria_Fila();
    insere_Fila_na_Fila(f2, fi);
    insere_Fila_na_Fila(f2, f3);
    insere_Fila_na_Fila(f2, fi);
    imprime_Fila_de_filas(f2);
    libera_Fila(f2);
    libera_Fila(f3);

    printf("\n\n\n|-------- Fila de Pilhas ---------|\n");
    Fila* fi_p = cria_Fila();
    Pilha* pi1 = cria_Pilha();
    Pilha* pi2 = cria_Pilha();
    for(int i = 0; i < 4; i++)
        insere_Pilha(pi1, a[i]);
    insere_Pilha_na_Fila(fi_p, pi1);
    insere_Pilha_na_Fila(fi_p, pi2);
    insere_Pilha_na_Fila(fi_p, pi1);
    imprime_Fila_de_Pilhas(fi_p);
    libera_Fila(fi_p);
    libera_Pilha(pi1);
    libera_Pilha(pi2);

    printf("\n\n\n|-------- Pilha de Filas ---------|\n");
    Pilha* pi_f = cria_Pilha();
    Fila* f4 = cria_Fila();
    insere_Fila_na_Pilha(pi_f, fi);
    insere_Fila_na_Pilha(pi_f, f4);
    imprime_Pilha_de_Filas(pi_f);
    libera_Fila(f4);
    libera_Pilha(pi_f);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 3 !!!

    printf("!!! Exercicio 3 !!!\n\n\n");
    printf("!!! Fila original !!! \n\n");
    imprime_Fila(fi);
    printf("\n!!! Fila invertida !!! \n\n");
    inverte_fila_com_pilha(fi);
    imprime_Fila(fi);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 4 !!!

    printf("!!! Exercicio 4 !!!\n\n\n");
    Fila* fi_circular = cria_Fila();
    printf("!!! Fila circular !!!\n\n");
    FilaCircular(fi_circular, a[3]);
    FilaCircular(fi_circular, a[1]);
    FilaCircular(fi_circular, a[2]);
    imprime_fila_circular(fi_circular);

    **/

    /** Teste do exercicio numero 5 !!!

    printf("!!! Exercicio 5 !!!\n\n\n");
    aeroporto();

    **/

    /** Teste do exercicio numero 6 !!!

    printf("!!! Exercicio 6 !!!\n\n\n");
    Fila* f1 = cria_Fila();
    insere_Fila(f1, a[1]);
    insere_Fila(f1, a[0]);
    insere_Fila(f1, a[2]);
    Fila* f2 = cria_Fila();
    insere_Fila(f2, a[1]);
    insere_Fila(f2, a[3]);
    insere_Fila(f2, a[3]);
    Fila* f3 = cria_Fila();
    preenche_fila(f1, f2, f3);
    printf("!!! Fila numero 1 em ordem crescente de acordo com a matricula !!!\n\n");
    imprime_Fila(f1);
    printf("\n\n!!! Fila numero 2 em ordem crescente de acordo com a matricula !!!\n\n");
    imprime_Fila(f2);
    printf("\n\n!!! Juncao das filas em ordem crescente de acordo com a matricula !!!\n\n");
    imprime_Fila(f3);
    libera_Fila(f1);
    libera_Fila(f2);
    libera_Fila(f3);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 7 !!!

    printf("!!! Exercicio 7 !!!\n\n\n");
    printf("!!! Fila sem estar invertida !!!\n\n");
    imprime_Fila(fi);
    inverte_fila(fi);
    printf("\n\n!!! Fila invertida !!!\n\n");
    imprime_Fila(fi);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 8 !!!

    printf("!!! Exercicio 8 !!!\n\n\n");
    menu();

    **/

    libera_Fila(fi);
    return 0;
}

