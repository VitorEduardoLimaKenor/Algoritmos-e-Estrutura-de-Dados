#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h" //inclui os Protótipos
//Definição do tipo Fila
struct elemento{
    struct aluno dados;
    struct aviao decolagem;
    Fila* filas;
    Pilha* pilhas;
    struct elemento *prox;
};
typedef struct elemento Elem;
//Definição do Nó Descritor da Fila
struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
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

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
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

/// Funcoes dos exercicios desenvolvidas por mim e minha dupla

int separa(Fila* f1, Fila* f2, int n){
    /// Verifica se a fila existe
    if(f1 == NULL){
        return 0;
    }
    /// Verifica se a fila esta vazia
    if(f1->inicio == NULL){
        return 0;
    }
    /// Criando um no para percorrer a fila
    Elem *no = f1->inicio;
    /// Percorrendo a fila ate chegar na matricula desejada
    while(no != NULL){
        /// Verificando onde esta a matricula informada
        if(no->dados.matricula == n){
            /// Iniciando a fila 2 no proximo nó
            /// Terminando ela no final da primeria fila
            f2->inicio = no->prox;
            f2->final = f1->final;

            /// Desconectando as filas
            /// Definindo o final da primeira fila na ocorrencia
            no->prox = NULL;
            f1->final = no;
        }
        no = no->prox;
    }

    return 1;
}

int insere_Fila_na_Fila(Fila* fi, Fila* fi_interna){
    /// Verifica se a fila existe
    if(fi == NULL){
        return 0;
    }
    /// Criando um no para colocar as informacoes
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    /// Inserindo a fila informada no nó
    no->filas = fi_interna;
    no->prox = NULL;
    /// Verifica se a fila esta vazia
    /// Se estiver esse no sera seu inicio
    /// Se não, so continuamos interligando os nós apartir do final
    if(fi->final == NULL){
        fi->inicio = no;
    }
    else{
        fi->final->prox = no;
    }
    /// Definindo o novo final da fila
    fi->final = no;
    fi->qtd++;
    return 1;
}

void imprime_Fila_de_filas(Fila* fi){
    /// Verifica se a fila existe
    if(fi == NULL){
       return;
    }
    /// Variavel para ser contador
    int i = 1;
    /// Criando um no para pegar as informacoes do no
    Elem* no = fi->inicio;
    while(no != NULL){
        /// Apresentando as informações
        printf("___ Fila de numero %i da Fila ___\n", i);
        printf("Endereco do inicio dela: %p\n", no->filas->inicio);
        printf("Endereco do final dela: %p\n", no->filas->final);
        printf("-------------------------------\n");
        i++;
        no = no->prox;
    }
}

int insere_Pilha_na_Fila(Fila* fi, Pilha* pi){
    /// Verifica se a fila existe
    if(fi == NULL){
        return 0;
    }
    /// Criando um no para colocar as informacoes
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    /// Inserindo a fila informada no nó
    no->pilhas = pi;
    no->prox = NULL;
    /// Verifica se a fila esta vazia
    /// Se estiver esse no sera seu inicio
    /// Se não, so continuamos interligando os nós apartir do final
    if(fi->final == NULL){
        fi->inicio = no;
    }
    else{
        fi->final->prox = no;
    }
    /// Definindo o novo final da fila
    fi->final = no;
    fi->qtd++;
    return 1;
}

void imprime_Fila_de_Pilhas(Fila* fi){
    /// Verifica se a fila existe
    if(fi == NULL){
       return;
    }
    /// Variavel para ser contador
    int i = 1;
    /// Criando um no para pegar as informacoes do no
    Elem* no = fi->inicio;
    while(no != NULL){
        /// Apresentando as informações
        printf("___ Pilha de numero %i da Fila ___\n", i);
        printf("Endereco do topo da pilha: %p\n", *no->pilhas);
        printf("-------------------------------\n");
        i++;
        no = no->prox;
    }
}

int insere_Fila_na_Pilha(Pilha* pi, Fila* fi){
    /// Verifica se a pilha existe
    if(pi == NULL){
        return 0;
    }
    /// Cria um no para colocar as informacoes
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    /// Colocando as filas na pilha
    no->filas = fi;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

void imprime_Pilha_de_Filas(Pilha* pi){
    /// Verifica se a pilha existe
    if(pi == NULL){
       return;
    }
    /// Variavel para dizer o topo da pilha
    int i = 0;
    /// Criando um no para pegar as informacoes do no
    Elem* no = *pi;
    while(no != NULL){
        /// Apresentando as informações
        if(i == 0){
            printf("________Topo da Pilha_______\n");
            i++;
        }
        printf("Endereco do inicio dela: %p\n", no->filas->inicio);
        printf("Endereco do final dela: %p\n", no->filas->final);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

void preenche_fila(Fila* f1, Fila* f2, Fila* f3){
    /// Verifica se a Fila 1 existe e se tem algum conteudo
    if(f1 == NULL){
        return;
    }
    if(f1->inicio == NULL){
        return;
    }
    /// Verifica se a Fila 2 existe e se tem algum conteudo
    if(f2 == NULL){
        return;
    }
    if(f2->inicio == NULL){
        return;
    }
    /// Criando no para pegar as informacoes da fila
    Elem* no_f1 = f1->inicio;
    Elem* no_f2 = f2->inicio;
    /// Criando um no aonde vamos inserir as informacoes
    Elem* no_f3;
    /// Variavel criada para saber quantos elementos terao em f3
    int tam_filas = f1->qtd + f2->qtd;
    /// Comparando f1 e f2 para saber a ordem dos elementos
    while(tam_filas != 0){
        if(no_f2 == NULL || no_f1->dados.matricula >= no_f2->dados.matricula){
            /// Alocando o no que vai para a f3
            no_f3 = (Elem*) malloc(sizeof(Elem));
            if(no_f3 == NULL){
                return;
            }
            /// Metodo padrao de insercao na fila
            no_f3->dados = no_f1->dados;
            no_f3->prox = NULL;
            if(f3->final == NULL)
                f3->inicio = no_f3;
            else
                f3->final->prox = no_f3;
            f3->final = no_f3;
            f3->qtd++;
            /// Avanca o no f1 que ja foi inserido
            no_f1 = no_f1->prox;
        }
        else if(no_f1 == NULL || no_f2->dados.matricula >= no_f1->dados.matricula){
            /// Alocando o no que vai para a f3
            no_f3 = (Elem*) malloc(sizeof(Elem));
            if(no_f3 == NULL){
                return;
            }
            /// Metodo padrao de insercao na fila
            no_f3->dados = no_f2->dados;
            no_f3->prox = NULL;
            if(f3->final == NULL)
                f3->inicio = no_f3;
            else
                f3->final->prox = no_f3;
            f3->final = no_f3;
            f3->qtd++;
            /// Avanca o no f2 que ja foi inserido
            no_f2 = no_f2->prox;
        }
        /// Controlando as repeticoes
        tam_filas--;
    }
    return;
}

void inverte_fila(Fila* fi){
    /// Verifica se a fila existe e se tem conteudo
    if(fi == NULL){
        return;
    }
    if(fi->inicio == NULL){
        return;
    }
    /// Criando auxiliares para poder fazer a inversao
    Elem* aux1 = fi->inicio;
    Elem* aux2 = fi->inicio->prox;
    Elem* aux3 = aux2;
    /// Fazendo a inversao dos ponteiros
    fi->inicio = fi->final;
    fi->final = aux1;
    fi->final->prox = NULL;
    /// Fazendo a inversao dos elementos
    while(aux3 != NULL){
        aux3 = aux3->prox;
        aux2->prox = aux1;
        aux1 = aux2;
        aux2 = aux3;
    }

    return;
}

void fura_fila(Fila* fi, struct aluno al){
    /// Verifica se a fila existe e se tem conteudo
    if(fi == NULL){
        return;
    }
    if(fi->inicio == NULL){
        return;
    }
    /// Criando um no para furar a fila
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
          return;
    }
    /// fazendo a troca do antigo inicio para o novo inicio
    no->dados = al;
    no->prox = fi->inicio;
    fi->inicio = no;
    fi->qtd++;

    return;
}

void menu(){
    /// Variavel para criacao da pilha
    Fila* fi = NULL;
    /// Variavel de saida do loop
    int sair = 0;
    /// Variavel de opcao do menu
    int opcao;
    /// Variavel para inserir elemento
   struct aluno a[2] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8}};
    /// Variavel para ler primeiro da fila
    struct aluno b;
    /// Variavel para saber tamanho de uma pilha qualquer
    int qtd_fila;
    /// Loop do menu
    while(sair == 0){
        do{
            system("cls");
            printf("1-Inicializa Fila.\n");
            printf("2-Verifica se a Fila esta vazia.\n");
            printf("3-Verifica se a Fila esta cheia.\n");
            printf("4-Enfileira o elemento na Fila.\n");
            printf("5-Desenfileira elemento da Fila.\n");
            printf("6-Le o numero no inicio da fila.\n");
            printf("7-Testar qual Fila possui mais elementos.\n");
            printf("8-Furar a fila.\n");
            printf("9-Sair.\n\n");
            printf(">>> Escolha uma opcao: ");
            scanf("%i", &opcao);
        }while(opcao < 1 || opcao > 9);
        /// Criando uma condicao para cada escolha
        if(opcao == 1){
            fi = cria_Fila();
            if(fi->inicio == NULL){
                printf("\nFila inicializada com sucesso\n\n");
            }
        }
        else if(opcao == 2){
            if(fi == NULL){
                printf("\nFila nao foi inicializada\n\n");
            }
            else{
                if(fi->inicio == NULL){
                    printf("\nFila esta vazia\n\n");
                }
                else{
                    printf("\nFila nao esta vazia\n\n");
                }
            }
        }
        else if(opcao == 3){
            if(fi == NULL){
                printf("\nFila  nao foi inicializada\n\n");
            }
            else{
                if(fi->inicio != NULL){
                    printf("\nFila esta cheia\n\n");
                }
                else{
                    printf("\nFila nao esta cheia\n\n");
                }
            }
        }
        else if(opcao == 4){
            if(fi == NULL){
                printf("\nFila nao foi inicializada\n\n");
            }
            else{
                insere_Fila(fi, a[0]);
                printf("\nElemento inserido com sucesso\n\n");
            }
        }
        else if(opcao == 5){
            if(fi == NULL){
                printf("\nFila nao foi inicializada\n\n");
            }
            else{
                if(fi->inicio == NULL){
                    printf("\nFila esta vazia\n\n");
                }
                else{
                    remove_Fila(fi);
                    printf("\nElemento desenfileirado com sucesso\n\n");
                }
            }
        }
        else if(opcao == 6){
            if(fi == NULL){
                printf("\nFila nao foi inicializada\n\n");
            }
            else{
                if(fi->inicio == NULL){
                    printf("\nFila esta vazia\n\n");
                }
                else{
                    consulta_Fila(fi, &b);
                    printf("\nMatricula: %d\n", b.matricula);
                    printf("Nome: %s\n", b.nome);
                    printf("Notas: %f %f %f\n", b.n1, b.n2, b.n3);
                }
            }
        }
        else if(opcao == 7){
            printf("\nDe uma quantidade para uma fila qualquer: ");
            scanf("%i", &qtd_fila);
            if(fi == NULL || qtd_fila > fi->qtd){
                printf("\nEssa fila qualquer e maior que a sua\n");
            }
            else{
                printf("\nSua fila e maior que essa fila qualquer\n");
            }
        }
        else if(opcao == 8){
            if(fi == NULL){
                printf("\nFila nao foi inicializada\n\n");
            }
            else{
                if(fi->inicio == NULL){
                    printf("\nFila esta vazia\n\n");
                }
                else{
                    fura_fila(fi, a[1]);
                    printf("\nElemento furou a fila com sucesso\n\n");
                }
            }
        }
        else{
            libera_Fila(fi);
            sair++;
        }
        system("pause");
        system("cls");
    }
    return;
}

/// Mudei um pouco a original para adaptar a insercao de outra struct que no caso e aviao
int insere_aviao_na_Fila(Fila* fi, struct aviao av){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->decolagem = av;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

void listar_avioes(Fila* fi){
    /// Verifica se a fila existe
    if(fi == NULL){
        return;
    }
    /// Criando um no para pegar as informacoes
    Elem* no = fi->inicio;
    /// Apresentando as informacoes da lista
    while(no != NULL){
        printf("Quantidade de passageiros: %i\n", no->decolagem.qtd_passageiros);
        printf("Nome da Empresa: %s\n", no->decolagem.empresa);
        printf("Destino do aviao: %s\n", no->decolagem.destino);
        printf("-------------------------------\n");
        no = no->prox;
    }

    return;
}

/// Igual a consulta_fila, so foi adaptada para a struct aviao
void consulta_avioes(Fila* fi, struct aviao *av){
   if(fi == NULL)
        return;
    if(fi->inicio == NULL)//fila vazia
        return;
    *av = fi->inicio->decolagem;
    return;
}

void aeroporto(){
    /// Variavel para saber a escolha do usuario
    int opcao;
    /// Struct com informacao dos avioes
    struct aviao av[4] = {{20,"Azul","EUA"},
                         {15,"Gol","Russia"},
                         {35,"Tam","Brasil"},
                         {30,"Avianca","Japao"}};
    /// Iniciando uma fila e adicionando informacoes
    Fila* fi = cria_Fila();
    for(int i = 0; i < 4; i++){
        insere_aviao_na_Fila(fi, av[i]);
    }
    /// Variavel para escolha de aviao
    int escolha;
    /// Variavel para consulta de aviao
    struct aviao p;
    /// Variavel para sair do loop
    int sair = 0;
    /// Loop
    while(sair == 0){
        do{
            system("cls");
            printf("1-Numero de avioes aguardando na fila de decolagem.\n");
            printf("2-Autorizar a decolagem do primeiro aviao da fila.\n");
            printf("3-Adicionar um aviao a fila de espera.\n");
            printf("4-Listar todos os avioes na fila de espera.\n");
            printf("5-Listar as caracteristicas do primeiro aviao da fila.\n");
            printf("6-Sair.\n\n");
            printf(">>> Escolha uma opcao: ");
            scanf("%i", &opcao);
            printf("\n\n");
        }while(opcao < 1 || opcao > 6);
        /// Criando uma condicao para cada escolha
        if(opcao == 1){
            printf("Existem no momento _%i_ avioes aguardando na fila de decolagem\n\n", fi->qtd);
        }
        else if(opcao == 2){
            if(fi->inicio == NULL){
                printf("Nao tem aviao na fila de decolagem\n\n");
            }
            else{
                remove_Fila(fi);
                printf("A decolagem foi autorizada, aviao tirado da fila de espera\n\n");
            }
        }
        else if(opcao == 3){
            do{
                system("cls");
                printf("Qual dos nossos avioes voce deseja adicionar?\n");
                printf("1-Azul.\n");
                printf("2-Gol.\n");
                printf("3-Tam.\n");
                printf("4-Avianca.\n\n");
                printf(">>>> ");
                scanf("%i", &escolha);
            }while(escolha < 1 || escolha > 4);
            if(escolha == 1){
                insere_aviao_na_Fila(fi, av[0]);
            }
            else if(escolha == 2){
                insere_aviao_na_Fila(fi, av[1]);
            }
            else if(escolha == 3){
                insere_aviao_na_Fila(fi, av[2]);
            }
            else{
                insere_aviao_na_Fila(fi, av[3]);
            }
            printf("\nAviao adicionado com sucesso\n\n");
        }
        else if(opcao == 4){
            if(fi->inicio == NULL){
                printf("Nao tem aviao na fila de decolagem\n\n");
            }
            else{
                listar_avioes(fi);
            }
        }
        else if(opcao == 5){
            if(fi->inicio == NULL){
                printf("Nao tem aviao na fila de decolagem\n\n");
            }
            else{
                printf("!!!Primeiro aviao na fila de decolagem!!!\n\n");
                consulta_avioes(fi, &p);
                printf("Quantidade de passageiros: %i\n", p.qtd_passageiros);
                printf("Nome da Empresa: %s\n", p.empresa);
                printf("Destino do aviao: %s\n\n", p.destino);
            }
        }
        else{
            libera_Fila(fi);
            sair++;
        }
        system("pause");
        system("cls");
    }

    return;
}

void inverte_fila_com_pilha(Fila* fi){
    /// Verifica se a fila existe e se tem conteudo
    if(fi == NULL){
        return;
    }
    if(fi->inicio == NULL){
        return;
    }
    /// Criando uma pilha para colocar as informações
    Pilha* pi = cria_Pilha();
    if(pi == NULL){
        return;
    }
    /// Loop para percorrer a fila e criar a pilha com as informacoes
    while(fi->inicio != NULL){
        insere_Pilha(pi, fi->inicio->dados);
        fi->inicio = fi->inicio->prox;
    }
    /// Redefinindo o final da fila
    fi->final = NULL;
    /// Loop que retorna as informacoes da pilha para a fila
    while((*pi) != NULL){
        insere_Fila(fi, (*pi)->dados);
        *pi = (*pi)->prox;
    }

    return;
}

void FilaCircular(Fila* fi, struct aluno al){
    /// Verifica se a fila existe
    if(fi == NULL){
        return;
    }
    /// Criando um no para colocar as informacoes
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
          return;
    }
    /// furando a fila e interligando o final para se tornar circular
    no->dados = al;
    /// Se a fila estiver vazia, o novo nó é o início e o final
    if (fi->inicio == NULL) {
        no->prox = no;
        fi->inicio = no;
        fi->final = no;
    }/// Se a fila não estiver vazia, insere o novo nó no início
    else {
        no->prox = fi->inicio;
        fi->inicio = no;
        fi->final->prox = no;
    }

    return;
}

void imprime_fila_circular(Fila* fi){
    /// Verifica se a fila existe
    if(fi == NULL){
        return;
    }
    /// Criando um no para pegar as informacoes
    Elem* no = fi->inicio;
    /// Percorrendo a Fila circular
    do{
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;

    }while(no != fi->inicio);

    return;
}

