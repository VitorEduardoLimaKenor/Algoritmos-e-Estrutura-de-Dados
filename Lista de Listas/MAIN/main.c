#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

int main(){
    struct aluno al, a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}};

    /// Usando as funcoes que foram disponibilizadas pelo professor
    printf("!!! Fila criada com funcoes disponibilizadas pelo professor !!!\n\n");
    Lista* li = cria_lista();
    printf("Tamanho: %d\n\n",tamanho_lista(li));

    int i;
    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);

    imprime_lista(li);
    printf("\nTamanho: %d\n\n",tamanho_lista(li));
    system("pause");
    system("cls");

    /** Teste do exercicio numero 1 !!!

    printf("!!! Exercicio 1 !!!\n\n");
    printf("A) Procurando um aluno pela matricula:\n\n");
    consulta_matricula(li, 3, &al); /// Matricula escolhida foi a 3
    printf("Matricula: %d\n", al.matricula);
    printf("Nome: %s\n", al.nome);
    printf("Notas: %f %f %f\n\n", al.n1, al.n2, al.n3);

    printf("B) Procurando um aluno pela sua posicao na lista:\n\n");
    consulta_posicao(li, 3, &al); /// Posicao escolhida foi a 3
    printf("Matricula: %d\n", al.matricula);
    printf("Nome: %s\n", al.nome);
    printf("Notas: %f %f %f\n\n", al.n1, al.n2, al.n3);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 2 !!!

    printf("!!! Exercicio 2 !!!\n\n");
    printf("1 - Removendo um no a partir do seu valor armazenado de matricula: \n\n");
    remove_no(li, 3); /// Matricula escolhida foi a 3
    imprime_lista(li);

    printf("\n\n2 - Verifica se duas listas encadeadas sao iguais:\n\n");
    Lista* L1 = cria_lista();
    Lista* L2 = cria_lista();
    for(i=0; i < 4; i++){
        insere_lista_ordenada(L1,a[i]);
        insere_lista_ordenada(L2,a[i]);
    }
    if(listas_iguais(L1, L2) == 1){
        printf("!!!Sao iguais!!!\n\n");
    }else{
        printf("!!!Nao sao iguais!!!\n\n");
    }
    libera_lista(L1);
    libera_lista(L2);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 3 !!!

    printf("!!! Exercicio 3 !!!\n\n");
    insere_valor(li, a[2], 3); /// sera inserido um valor na posicao 4
    imprime_lista(li);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 4 !!!

    printf("!!! Exercicio 4 !!!\n\n");
    float vet[4] = {5.5, 8, 9.1, 25};
    Lista* li_vet = lista_vetor(vet, 4);
    printf("Vetor dentro da lista: ");
    imprime_lista_vetor(li_vet);
    printf("\n\n");
    libera_lista(li_vet);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 5 !!!

    printf("!!! Exercicio 5 !!!\n\n");
    printf(">>> Antes da remocao de alunos com a matricula 3:\n\n");
    insere_lista_final(li, a[3]);
    insere_lista_inicio(li, a[3]);
    imprime_lista(li);
    printf("\n\n>>> Depois da remocao de alunos com a matricula 3:\n\n");
    remove_info(li, 3);
    imprime_lista(li);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 6 !!!

    printf("!!! Exercicio 6 !!!\n\n");
    Lista* l1 = cria_lista();
    Lista* l2 = cria_lista();
    for(i=0; i < 3; i++){
     insere_lista_ordenada(l1,a[i]);
     insere_lista_ordenada(l2,a[i]);
    }
    Lista* li_uniao = concatenar_listas(l1, l2);
    imprime_lista(li_uniao);
    libera_lista(li_uniao);
    system("pause");
    system("cls");

    **/

    /** Teste do exercicio numero 7 !!!

    printf("!!! Exercicio 7 !!!\n\n");
    printf("\n\n>>> Lista sem a remocao dos repetidos:\n\n");
    Lista* l2 = cria_lista();
    insere_lista_inicio(l2, a[0]);
    insere_lista_inicio(l2, a[1]);
    insere_lista_inicio(l2, a[1]);
    insere_lista_inicio(l2, a[2]);
    insere_lista_inicio(l2, a[0]);
    insere_lista_inicio(l2, a[3]);
    imprime_lista(l2);
    printf("\n\n>>> Lista com a remocao dos repetidos:\n\n");
    remove_repetidos(l2);
    imprime_lista(l2);

    **/

    /** Teste do exercicio numero 8 !!!

    printf("!!! Exercicio 8 !!!\n\n");
    Lista* l1 = cria_lista();
    Lista* l2 = cria_lista();
    for(i=0; i < 4; i++){
        insere_lista_ordenada(l1,a[i]);
        insere_lista_ordenada(l2,a[i]);
    }
    Lista* li_fusao_ordenada = fusao_ordenada(l1, l2);
    imprime_lista(li_fusao_ordenada);
    libera_lista(li_fusao_ordenada);

    **/

    /** Teste do exercicio numero 9 !!!

    printf("!!! Exercicio 9 !!!\n\n");
    /// Celula com o numero de matricula 4 sera movido
    Troca_posicao(li, 2);
    imprime_lista(li);

    **/

    libera_lista(li);
    return 0;
}
