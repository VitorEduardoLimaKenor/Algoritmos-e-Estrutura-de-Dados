#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h"

int main(){
    struct aluno al, a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};

    /// Usando as funcoes que foram disponibilizadas pelo professor
    printf("!!! Lista Duplamente Encadeadas criada com funcoes disponibilizadas pelo professor !!!\n\n");
    Lista* li = cria_lista();
    printf("Tamanho: %d\n\n",tamanho_lista(li));

    int i;
    for(i=0; i < 4; i++)
        insere_lista_final(li,a[i]);

    imprime_lista(li);
    printf("\nTamanho: %d\n\n",tamanho_lista(li));
    system("pause");
    system("cls");

    /** Teste do exercicio numero 1 !!!

    printf("!!! Exercicio 1 !!!\n\n");
    /// matricula escolhida para ser removida foi a numero 1
    remove_aluno(li, 1);
    imprime_lista(li);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 2 !!!

    printf("!!! Exercicio 2 !!!\n\n");
    Lista* teste = cria_lista();
    for(i = 0; i < 4; i++){
        insere_lista_ordenada(teste, a[i]);
    }
    imprime_lista(teste);
    libera_lista(teste);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 3 !!!

    printf("!!! Exercicio 3 !!!\n\n");
    int qtd_nota = conta_lista_nota(li, 9);
    imprime_lista(li);
    printf("\n\n!!! A nota 9 como n1 foi repetida %i vezes na lista !!!\n\n", qtd_nota);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 4 !!!

    printf("!!! Exercicio 4 !!!\n\n");
    printf(">>> Lista Circular:\n\n");
    Lista* teste = cria_lista();

    insere_lista_circular_final(teste, a[0]);
    insere_lista_circular_inicio(teste, a[1]);
    insere_lista_circular_final(teste, a[2]);
    insere_lista_circular_inicio(teste, a[3]);

    remove_lista_circular_inicio(teste);
    remove_lista_circular_final(teste);

    imprime_lista_circular(teste);
    libera_lista_circular(teste);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 5 !!!

    printf("!!! Exercicio 5 !!!\n\n");
    Fila* fi = cria_Fila();
    enfileirar(fi, 12);
    enfileirar(fi, 17);
    enfileirar(fi, 29);
    enfileirar(fi, 34);
    desenfileirar(fi);
    imprime_Fila(fi);
    libera_Fila(fi);
    system("pause");
    system("cls");

    **/

    libera_lista(li);
    return 0;
}

