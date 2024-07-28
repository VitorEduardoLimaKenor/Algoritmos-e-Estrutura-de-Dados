#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDin.h" //inclui os Protótipos

//Definição do tipo Pilha
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_cheia(Pilha* pi){
    return 0;
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

/// Funcoes dos exercicios desenvolvidas por mim e minha dupla

void pop2(Pilha* pi){
    /// Verificando se a pilha foi criada
    if(pi == NULL){
        return;
    }
    /// Verificando se existe algum elemento na pilha
    if((*pi) == NULL){
        return;
    }
    /** Faço um ponteiro temporário para pegar o elemento do topo,
        depois passo o topo para o próximo elemento, e removo o antigo topo **/
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    /// Verifico se o novo topo é um elemento
    if((*pi) == NULL){
        return;
    }
    /// Repitindo o passo de remoção anterior
    no = *pi;
    *pi = no->prox;
    free(no);
}

void push2(Pilha* pi, struct aluno al1, struct aluno al2){
    /// Verificando se a pilha foi criada
    if(pi == NULL){
        return;
    }
    /// Criando um no e alocando ele na memória
    Elem* no1;
    no1 = (Elem*) malloc(sizeof(Elem));
    /// Verifico se meu no foi criado
    if(no1 == NULL){
        return;
    }
    /** Atribuo os dados ao meu no,
        Faço ele apontar para o meu antigo no se existir,
        Torno esse no meu novo topo **/
    no1->dados = al1;
    no1->prox = (*pi);
    *pi = no1;

    /// Repito o processo anterior para meu novo no
    Elem* no2;
    no2 = (Elem*) malloc(sizeof(Elem));

    if(no2 == NULL){
        return;
    }

    no2->dados = al2;
    no2->prox = (*pi);
    *pi = no2;
}

void popN(Pilha* pi, int n){
    /// Verificando se a pilha foi criada
    if(pi == NULL){
        return;
    }
    /** Tudo dentro do laço de repetição para executar
        a remoção o número de vezes requisitado **/
    while(n > 0){
        /// Verificando se existe algum elemento na pilha
        if((*pi) == NULL){
            return;
        }
        /** Faço um ponteiro temporário para pegar o elemento do topo,
        depois passo o topo para o próximo elemento, e removo o antigo topo **/
        Elem *no = *pi;
        *pi = no->prox;
        free(no);
        /// Controlando o número de repetições
        n--;
    }
}

Pilha *pilha_copia(Pilha* pi){
    /// Verificando se a pilha tem algum elemento
    if((*pi) == NULL){
        return NULL;
    }
    /** Criando um no para pegar as informações da Pilha original
        e outro para salvar essas informações na pilha temporária,
        e posteriormente na copia **/
    Elem* no = *pi;
    Elem* no_cop;
    /// Iniciando a pilha temporária que será o inverso da original
    Elem* pi_temp = NULL;
    /** Inicializando a pilha cópia que será o inverso da temorária,
        logo é uma cópia da original **/
    Pilha* pi_cop = (Pilha*) malloc(sizeof(Pilha));
    if(pi_cop != NULL){
        *pi_cop = NULL;
    }
    /// Criando váriavel para excluir a pilha temporária após o uso
    Elem* delet_no;
    /// Copiando os dados da pilha original para a temporária
    while(no != NULL){
        no_cop = (Elem*) malloc(sizeof(Elem));
        if(no_cop == NULL){
            return NULL;
        }
        no_cop->dados = no->dados;
        no_cop->prox = pi_temp;
        pi_temp = no_cop;

        no = no->prox;
    }
    /** Copiando os dados da pilha temporária para a cópia,
        e excluindo a pilha temporária **/
    while(pi_temp != NULL){
        no_cop = (Elem*) malloc(sizeof(Elem));
        if(no_cop == NULL){
            return NULL;
        }
        no_cop->dados = pi_temp->dados;
        no_cop->prox = (*pi_cop);
        *pi_cop = no_cop;

        delet_no = pi_temp;
        pi_temp = pi_temp->prox;
        free(delet_no);
    }

    return pi_cop;
}

void info_pilha(Pilha* pi){
    /// Verifica se a pilha existe
    if(pi == NULL){
        return;
    }
    /// Criando um no para percorrer os elementos da pilha
    Elem* no = *pi;
    /// Criando ponteiros para marcarem o maior e o menor valor
    float *maior, *menor;
    /// Criando a variavel para descobrir a media
    float media = 0;
    /// Percorrendo a pilha
    while(no != NULL){
        /// Checando a maior nota do aluno
            maior = &no->dados.n1;
            if(*maior < no->dados.n2){
                maior = &no->dados.n2;
            }
            if(*maior < no->dados.n3){
                maior = &no->dados.n3;
            }
        /// Checando a menor nota do aluno
            menor = &no->dados.n1;
            if(*menor > no->dados.n2){
                menor = &no->dados.n2;
            }
            if(*menor > no->dados.n3){
                menor = &no->dados.n3;
            }
        /// Calculando a media do aluno
        media = (no->dados.n1 + no->dados.n2 + no->dados.n3) / 3;
        /// Apresentando as informacoes
        printf("Maior nota do(a) %s: %.2f \n", no->dados.nome, *maior);
        printf("Menor nota do(a) %s: %.2f \n", no->dados.nome, *menor);
        printf("Media aritmetica do(a) %s: %.2f \n", no->dados.nome, media);
        printf("\n\n");
        /// Passando para o proximo no
        no = no->prox;
    }

    return;
}


void calculadora(Pilha* pi){
    /// Verificando se a pilha existe
    if(pi == NULL){
        return;
    }
    /// Criando um no para pegarmos as informacoes da pilha
    Elem* no = *pi;
    /// Criando variaveis para informar qual operacao sera feita
    int operacao1, operacao2;
    /// Criando uma variavel para guardar o numero resultante da operacao
    float resultado;
    /// Percorrendo a pilha
    while(no != NULL){
        /** Apresentando para o usuario os numeros coletados na struct
            e as operacoes que podem ser feitas **/
        printf("( %.2f (?) %.2f ) (?) %.2f = Resultado \n\n", no->dados.n1, no->dados.n2, no->dados.n3);
        printf("1 - (+) \n");
        printf("2 - (-) \n");
        printf("3 - (*) \n");
        printf("4 - (/) \n\n");

        /// Pedindo a primeira operacao para o usuario
        do{
            printf(">>> Primeira operacao: ");
            scanf("%i", &operacao1);
        }while(operacao1 < 1 || operacao1 > 4);
        /// Calculando o resultado com a operacao escolhida
        if(operacao1 == 1){
            resultado = no->dados.n1 + no->dados.n2;
        }
        else if(operacao1 == 2){
            resultado = no->dados.n1 - no->dados.n2;
        }
        else if(operacao1 == 3){
            resultado = no->dados.n1 * no->dados.n2;
        }
        else if(operacao1 == 4){
            resultado = no->dados.n1 / no->dados.n2;
        }
        /// Pedindo a Segunda operacao para o usuario
        do{
            printf(">>> Segunda operacao: ");
            scanf("%i", &operacao2);
        }while(operacao2 < 1 || operacao2 > 4);
        /// Calculando o resultado com a operacao escolhida
        if(operacao2 == 1){
            resultado += no->dados.n3;
        }
        else if(operacao2 == 2){
            resultado -= no->dados.n3;
        }
        else if(operacao2 == 3){
            resultado *= no->dados.n3;
        }
        else if(operacao2 == 4){
            resultado /= no->dados.n3;
        }
        /// Apresentando o resultado das operacoes
        printf("\nResultado = %.2f", resultado);
        printf("\n\n");
        system("pause");
        system("cls");
        /// Passando para o proximo no
        no = no->prox;
    }

    return;
}

void checa_texto(Pilha* pi){
    /// Verifica se a pilha existe
    if(pi == NULL){
        return;
    }
    /// Criando um no para pegar as informacoes da pilha
    Elem* no = *pi;
    /// Variavel para saber o tamanho do texto
    int tamanho;
    /// Variavel para servir de indice
    int i;
    /// Variavel para guardar o texto inverso
    char *texto_inverso;
    /// Percorrendo a pilha
    while(no != NULL){
        /// Verificando o tamanho do texto
        tamanho = strlen(no->dados.nome);
        /// Alocando o texto_inverso de acordo com o tamanho
        texto_inverso = malloc(tamanho * sizeof(char));
        /// Percorrendo o texto original de tras para frente
        for(i = 0; tamanho >= 0; i++, tamanho--){
            texto_inverso[i] = no->dados.nome[tamanho - 1];
        }
        /// Apresentando as informacoes
        printf("Texto inverso: %s \n", texto_inverso);
        if(strcmp(texto_inverso, no->dados.nome) == 0){
            printf("^^^ Esse texto e palindromo ^^^\n\n");
        }else{
            printf("^^^ Esse texto nao e palindromo ^^^\n\n");
        }
        /// Passando para o proximo no
        no = no->prox;
    }
    return;
}

void par_impar(Pilha* pi){
    /// Verificando se a pilha existe
    if(pi == NULL){
        return;
    }
    /// Criando um no para pegar as informações da pilha
    Elem* no = *pi;
    /// Criando uma váriavel para saber a quantidade de pares
    int qtd_par = 0;
    /// Criando uma váriavel para saber a quantidade de impares
    int qtd_impar = 0;
    /// Percorrendo a pilha
    while(no != NULL){
        if(no->dados.matricula % 2 == 0){
            qtd_par++;
        }
        else{
            qtd_impar++;
        }
        /// Passando para o proximo no
        no = no->prox;
    }
    /// Apresentando as informacoes
        printf("Quantidade de numeros pares na matricula: %i \n", qtd_par);
        printf("Quantidade de numeros impares na matricula: %i\n\n", qtd_impar);

    return;
}

void verifica_repetidos(Pilha *pi){
    /// Verifica se a Pilha existe
    if(pi == NULL || *pi == NULL){
        return;
    }
    /// Criando uma variavel para o tamanho da pilha
    int tam = tamanho_Pilha(pi) / 2;
    /// Criando os ponteiros para percorrer a pilha
    Elem* no1 = *pi;
    Elem* no2 = *pi;
    /// Deslocar no2 para a segunda metade da pilha
    for(int i = 0; i < tam; i++){
        no2 = no2->prox;
    }
    /// Verifica elementos repetidos
    while(no1 != NULL && no2 != NULL){
        if(no1->dados.matricula == no2->dados.matricula){
            /// Apresentando o resultado
            printf("existem elementos repetidos!!!\n\n");
            return;
        }
        no1 = no1->prox;
        no2 = no2->prox;
    }
    /// Apresentando o resultado
    printf("Nao foram encontrados elementos repetidos!!!\n\n");
    return;
}

/// Funcao para converter um inteiro em decimal
void conversao(int num){
    if(num == 0){
        return;
    }
    else{
        printf("%i", num % 2);
        return conversao(num / 2);
    }
}

void menu(){
    /// Variavel para criacao da pilha
    Pilha *pi = NULL;
    /// Variavel de saida do loop
    int sair = 0;
    /// Variavel de opcao do menu
    int opcao;
    /// Variavel para mostrar topo pilha
    struct aluno b;
    /// Variavel para inserir elemento
    struct aluno a = {2,"Andre",9.5,7.8,8.5};
    /// Variavel para guardar numero usado na conversao
    int num;
    /// Loop do menu
    while(sair == 0){
        do{
            system("cls");
            printf("1-Inicializa pilha.\n");
            printf("2-Verifica se a pilha e vazia.\n");
            printf("3-Verifica se a pilha e cheia.\n");
            printf("4-Empilha o elemento na pilha.\n");
            printf("5-Desempilha elemento da pilha.\n");
            printf("6-Le topo de um pilha.\n");
            printf("7-Converte um numero decimal em binario.\n");
            printf("8-Sair.\n\n");
            printf(">>> Escolha uma opcao: ");
            scanf("%i", &opcao);
        }while(opcao < 1 || opcao > 8);
        /// Criando uma condicao para cada escolha
        if(opcao == 1){
            pi = cria_Pilha();
            printf("\nPilha criada com sucesso\n");
        }
        else if(opcao == 2){
            if(pi == NULL){
                printf("\nPilha nao existe \n");
            }
            else{
                if(Pilha_vazia(pi) == 0){
                    printf("\nPilha não esta vazia\n");
                }
                else{
                    printf("\nPilha esta vazia\n");
                }
            }
        }
        else if(opcao == 3){
            if(pi == NULL){
                printf("\nPilha nao existe \n");
            }
            else{
                if(Pilha_vazia(pi) == 0){
                    printf("\nPilha esta cheia \n");
                }
                else{
                    printf("\nPilha nao esta cheia \n");
                }
            }
        }
        else if(opcao == 4){
            if(pi == NULL){
                printf("\nPilha nao existe \n");
            }
            else{
                insere_Pilha(pi, a);
                printf("\nElemento inserido na pilha \n");
            }
        }
        else if(opcao == 5){
            if(pi == NULL){
                printf("\nPilha nao existe \n");
            }
            else if(*pi == NULL){
                printf("\nPilha esta vazia\n");
            }
            else{
                remove_Pilha(pi);
                printf("\nElemento removido da pilha \n");
            }
        }
        else if(opcao == 6){
            if(pi == NULL){
                printf("\nPilha nao existe \n");
            }
            else if(*pi == NULL){
                printf("\nPilha esta vazia\n");
            }
            else{
                consulta_topo_Pilha(pi, &b);
                printf("Matricula: %d\n", b.matricula);
                printf("Nome: %s\n", b.nome);
                printf("Notas: %f %f %f\n", b.n1, b.n2, b.n3);
                printf("-------------------------------\n");
            }
        }
        else if(opcao == 7){
            printf("Digite um numero inteiro para conversao: ");
            scanf("%i", &num);
            printf("Numero convertido em binario: ");
            conversao(num);
            printf("\n");
        }
        else{
            if(pi == NULL){
                libera_Pilha(pi);
            }
            sair++;
        }
        system("pause");
        system("cls");
    }
    return;
}
