#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h" //inclui os Protótipos

//Definição do tipo lista
struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct nodesc{
    int info;
    struct nodesc *prox;
    struct nodesc *ant;
};
typedef struct nodesc nods;

struct fila{
    struct nodesc *final;
    struct nodesc *inicio;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere início
        no->ant = NULL;
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    if(*li != NULL)//lista não vazia: apontar para o anterior!
        (*li)->ant = no;
    *li = no;
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    while(no->prox != NULL)
        no = no->prox;

    if(no->ant == NULL)//remover o primeiro e único
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
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

void libera_Fila(Fila* fi){
    if(fi != NULL){
        nods* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    nods* no = fi->inicio;
    while(no != NULL){
        printf("INFO: %d\n",no->info);
        printf("-------------------------------\n");
        no = no->prox;
    }
    printf("\n");
}

/// Funcoes dos exercicios desenvolvidas por mim e minha dupla

int remove_aluno(Lista* li, int matricula){
    /// Verifica se a lista existe e se tem conteudo
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    /// Criando um Elemento no para acessar as informacoes da lista
    Elem* no = *li;
    /// Verifica se a remocao sera feita no inicio
    if(no->dados.matricula == matricula && no->ant == NULL){
        (*li) = no->prox;
        /// Caso o elemento nao seja o unico na lista
        if(no->prox != NULL){
            no->prox->ant = NULL;
        }
        free(no);
        return 1;
    }
    /// Loop para percorrer a lista caso a remocao nao seja no inicio
    while(no != NULL){
        /// Verifica se a remocao sera feita no final
        if(no->dados.matricula == matricula && no->prox == NULL){
            no->ant->prox = NULL;
            free(no);
            return 1;
        }
        /// Remocao no meio da lista
        else if(no->dados.matricula == matricula){
            no->ant->prox = no->prox;
            no->prox->ant = no->ant;
            free(no);
            return 1;
        }
        else{
            no = no->prox;
        }
    }
    return 0;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    /// Verifica se a lista foi criada
    if(li == NULL){
        return 0;
    }
    /// Alocando dinamicamente o Elemento no que vai ser adicionado na lista
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    /// Passando as informacoes para esse no
    no->dados = al;
    /// Caso a lista esteja vazia, so inserir no inicio
    if((*li) == NULL){
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }
    else{
        /// Criando um ant e um atual para monitorar os no's para a insercao
        Elem *ant, *atual = *li;
        /// Percorrendo a lista para saber onde inserir o no
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        /// Se o atual estiver no inicio so inserir antes dele
        if(atual == *li){
            no->prox = (*li);
            no->ant = NULL;
            (*li)->ant = no;
            *li = no;
        }
        /// Caso contrario so arrumar as ligacoes para adicionar no meio ou no fim
        else{
            no->prox = atual;
            if(atual != NULL){
                atual->ant = no;
            }
            no->ant = ant;
            ant->prox = no;
        }
        return 1;
    }
}

int conta_lista_nota(Lista* li, int n1){
    /// Verifica se a lista existe e se tem conteudo
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    /// Criando uma variavel para armazenar o numero de repeticoes
    int repet = 0;
    /** Loop para passar o ponteiro por todos os no's e parar no ultimo,
        e contando quantos vezes a nota n1 se repete **/
    while((*li) != NULL){
        if((int)(*li)->dados.n1 == n1){
            repet++;
        }
        if((*li)->prox == NULL){
            break;
        }else{
            *li = (*li)->prox;
        }
    }
    /// Voltando o ponteiro para o inicio da lista
    while((*li)->ant != NULL){
        *li = (*li)->ant;
    }
    return repet;
}

int insere_lista_circular_inicio(Lista* li, struct aluno al){
    /// Verifica se a lista foi criada
    if(li == NULL){
        return 0;
    }
    /// Criando e alocando a variavel no que sera inserida na lista circular
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    /// Criando um aux para ajudar a fazer a conexao
    Elem* aux;
    /// Arrumando a conexao da lista circular
    no->dados = al;
    /// Caso for o primeiro elemento
    if(*li == NULL){
        no->ant = no;
        no->prox = no;
    }else{
        no->ant = (*li)->ant;
        no->prox = *li;
        (*li)->ant = no;
        /// Caso so tenha um elemento
        if((*li)->prox == (*li)){
            (*li)->prox = no;
        }
        else{ /// Caso tenha 2 ou mais elementos
            aux = *li;
            while(aux->prox != (*li)){
                 aux = aux->prox;
            }
            aux->prox = no;
        }
        *li = no;
    }
    *li = no;
    return 1;
}

int insere_lista_circular_final(Lista* li, struct aluno al){
    /// Verifica se a lista foi criada
    if(li == NULL){
        return 0;
    }
    /// Criando e alocando a variavel no que sera inserida na lista circular
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    /// Criando um aux para ajudar a fazer a conexao
    Elem* aux;
    /// Arrumando a conexao da lista circular
    no->dados = al;
    /// Caso for o primeiro elemento
    if(*li == NULL){
        no->ant = no;
        no->prox = no;
        *li = no;
    }else{ /// Caso tenha 2 ou mais elementos
        aux = *li;
        while(aux->prox != (*li)){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
        (*li)->ant = no;
        no->prox = *li;
    }
    return 1;
}

int remove_lista_circular_inicio(Lista* li){
    /// Verifica se a lista circular foi criada e se tem conteudo
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    /// Criando um no para acessar o elemento do topo e removelo
    Elem* topo = *li;
    /// Criando um no para acessar o ultimo elemento para arrumar a conexao
    Elem* fim = topo->ant;
    /// Arrumando as conexoes da lista circular
    if(topo != fim){
        *li = topo->prox;
        (*li)->ant = topo->ant;
        fim->prox = *li;
    }
    else{
        *li = NULL;
    }
    free(topo);
    return 1;
}

int remove_lista_circular_final(Lista* li){
    /// Verifica se a lista circular foi criada e se tem conteudo
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    /// Criando um no para acessar o ultimo elemento e removelo
    Elem* fim = (*li)->ant;
    /// Criando um auxiliar para realizar a remocao
    Elem* aux = fim;
    /// Arrumando as conexoes da lista circular
    if((*li) != fim){
        fim = fim->ant;
        fim->prox = aux->prox;
        (*li)->ant = fim;
    }
    else{
        *li = NULL;
    }
    free(aux);
    return 1;
}

void imprime_lista_circular(Lista* li){
    /// Verifica se a lista foi criada ou se tem conteudo
    if(li == NULL || (*li) == NULL){
        return;
    }
    /// Criando um no para acessar as informacoes da lista circular
    Elem* no = *li;
    /// Loop para percorrer a lista circular e apresentar as informacoes
    do{
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }while(no != (*li));
    printf("\n");
}

void libera_lista_circular(Lista* li){
    /// Verifica se a lista existe e se tem conteudo
    if(li != NULL && (*li) != NULL){
        /** Cria uma variavel no para acessar e remover as informacoes
            comecando pelo final da lista circular **/
        Elem* no = (*li)->ant;
        /// Criando um aux para a remocao;
        Elem* aux;
        /// Vai rodar até a lista estiver sido removida e faltar apenas o topo
        while(no != (*li)){
            aux = no;
            no = no->ant;
            free(aux);
        }
        /// Removendo o topo
        aux = no;
        free(aux);
        free(li);
    }
}

int enfileirar(Fila* fi, int info){
    /// Verifica se a fila foi criada
    if(fi == NULL){
        return 0;
    }
    /// Faz a alocao do no que sera colocado na fila
    nods *no = (nods*) malloc(sizeof(nods));
    if(no == NULL){
        return 0;
    }
    no->info = info;
    no->prox = NULL;
    /// Caso a fila esteja vazia define o inicio
    if(fi->final == NULL){
        fi->inicio = no;
        no->ant = NULL;
    }
    else{ /// Caso o inicio ja existe so redefinimos o final
        fi->final->prox = no;
        no->ant = fi->final;
    }
    fi->final = no;
    return 1;
}

int desenfileirar(Fila* fi){
    /// Verifica se a fila foi criada e se tem conteudo
    if(fi == NULL || fi->inicio == NULL){
        return 0;
    }
    nods *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    /// Caso a fila tenha ficado vazia define o final como inexistente
    if(fi->inicio == NULL){
        fi->final = NULL;
    }
    else{ /// Se hover mais elementos, apenas define o anterior do inicio como nulo
        fi->inicio->ant = NULL;
    }
    free(no);
    return 1;
}

