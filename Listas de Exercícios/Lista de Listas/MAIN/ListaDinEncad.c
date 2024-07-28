#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os Protótipos

//Definição do tipo lista
struct elemento{
    struct aluno dados;
    float vet;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elemento* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere início
        *li = no;
    }else{
        Elemento *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento* no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere início
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elemento *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere início
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elemento *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//não encontrado
        return 0;

    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elemento* no = *li;
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
    Elemento* no = *li;
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

int consulta_matricula(Lista* li, int matricula, struct aluno *al){
    /// Verifica se a lista existe e se tem conteudo
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    /// Criando um no para acessar as informacoes da lista
    Elemento* no = *li;
    /// Percorrendo a lista ate achar a matricula desejada ou chegar a NULL
    while(no != NULL && no->dados.matricula != matricula){
        no = no->prox;
    }
    /// Matricula nao encontrada
    if(no == NULL){
        return 0;
    }
    else{ /// Matricula encontrada
        *al = no->dados;
        return 1;
    }
}

int consulta_posicao(Lista* li, int posicao, struct aluno *al){
    /// Verifica se a lista existe e se tem conteudo
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    /// Criando um no para acessar as informacoes da lista
    Elemento* no = *li;
    /// Criando um contador para saber quantas posicoes andar na lista
    int qtd = 0;
    /// Percorrendo a lista ate chegar a posicao escolhida
    while(no != NULL && qtd != posicao){
        qtd++;
        no = no->prox;
    }
    /// Verifica se encontrou a posicao escolhida
    if (no == NULL) {
        return 0;
    }
    /// Pegando as informacoes do no encontrado
    *al = no->dados;
    return 1;
}

int remove_no(Lista* li, int mat){
    /// Verifica se a lista existe e se tem conteudo
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    /// Criando um no que ira ficar um passo atras
    Elemento* ant = *li;
    /// Criando um no que ficara a frente
    Elemento* no = ant->prox;
    /// Verifica se o no inicial e o que esta sendo procurado
    if(ant->dados.matricula == mat){
        *li = no;
        free(ant);
        return 1;
    }
    else{
        /// Caso de parada
        if(no->dados.matricula == mat){
            ant->prox = no->prox;
            free(no);
            return 1;
        }else{ /// recursao
            ant = ant->prox;
            return remove_no(&ant, mat);
        }
    }
}

int listas_iguais(Lista* L1, Lista* L2){
    /// Verifica se as listas tem o mesmo tamanho
    if(tamanho_lista(L1) != tamanho_lista(L2)){
        return 0;
    }
    /// Criando no's para fazer as comparações
    Elemento* n1 = *L1;
    Elemento* n2 = *L2;
    /// caso de parada
    if(n1 == NULL && n2 == NULL){
        return 1;
    }else{ /// recursao
        /// verifica se tem as mesmas infos
        if(n1->dados.matricula != n2->dados.matricula){
            return 0;
        }
        n1 = n1->prox;
        n2 = n2->prox;
        return listas_iguais(&n1, &n2);
    }
}

int insere_valor(Lista* li, struct aluno al, int posicao){
    /// Verifica se a lista existe e se tem conteudo
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    /// Verifica se a posicao escolhida existe na lista
    if(tamanho_lista(li) < posicao || posicao < 0){
        return 0;
    }
    /// Alocando o no que sera inserido na lista
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    /// Criando um no para percorrer a lista se necessario
    Elemento* no_li = *li;
    /// Criando um no para servir de aux na conexao da lista
    Elemento* aux;
    /// Caso a posicao escolhida seja a primeira
    if(posicao == 0){
        no->prox = (*li);
        *li = no;
        return 1;
    }else{
        /// loop para chegar na posicao escolhida
        for(int i = 0; i < posicao - 1; i++){
            no_li = no_li->prox;
        }
        /// fazendo a insercao do no e arumando a conexao da lista
        aux = no_li->prox;
        no_li->prox = no;
        no->prox = aux;
        return 1;
    }
}

Lista* lista_vetor(float *vet, int tam){
    /// Criando uma lista
    Lista* li = cria_lista();
    /// Criando no que ira passar o vetor para a lista
    Elemento *no;
    /// Colocando as infos do vetor na lista em ordem igual ao vetor
    for(int i = 0; i < tam; i++){
        no = (Elemento*) malloc(sizeof(Elemento));
        if(no == NULL){
            return 0;
        }
        no->vet = vet[i];
        no->prox = NULL;
        if(i == 0){/// lista vazia: insere início
            *li = no;
        }else{
            Elemento *aux;
            aux = *li;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = no;
        }
    }
    return li;
}

void imprime_lista_vetor(Lista* li){
    /// Verifica se a lista existe e se tem conteudo
    if(li == NULL || (*li) == NULL){
        return;
    }
    /// Criando um no para acessar as informacoes da lista
    Elemento* no = *li;
    /// Percorrendo a lista
    while(no != NULL){
        printf("%.1f  ", no->vet);
        no = no->prox;
    }
}

int remove_info(Lista* li, int num_mat){
    /// Verifica se a lista existe e se tem conteudo
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    /// Verifica se o numero da matricula é positivo e esta registrado
    if(num_mat <= 0 || num_mat > 4){
        return 0;
    }
    /// Criando um no que ira ficar um passo atras
    Elemento* ant = *li;
    /// Criando um no que ficara a frente
    Elemento* no = ant->prox;
    /// Criando um auxiliar para remocao
    Elemento* aux;
    /// Verifica se o no inicial esta sendo procurado
    if(ant->dados.matricula == num_mat){
        no = no->prox;
        aux = ant;
        ant = ant->prox;
        free(aux);
        *li = ant;
    }
    /** Percorrendo a lista e tirando os no's de acordo com a matricula
        e concertando a conexao da lista **/
    while(no != NULL){
        if(no->dados.matricula == num_mat){
            aux = no;
            no = no->prox;
            ant->prox = no;
            free(aux);
        }else{
            no = no->prox;
            ant = ant->prox;
        }
    }
    return 1;
}

Lista* concatenar_listas(Lista* L1, Lista* L2){
    /// Verifica se a lista 1 existe e se tem conteudo
    if(L1 == NULL || (*L1) == NULL){
        return NULL;
    }
    /// Verifica se a lista 2 existe e se tem conteudo
    if(L2 == NULL || (*L2) == NULL){
        return NULL;
    }
    /// Criando um no para acessar as informacoes da lista 1
    Elemento* n1 = *L1;
    /** Percorrendo a lista 1 e interligando o final dela com o
        inicio da lista 2 **/
    while(n1 != NULL){
        if(n1->prox == NULL){
            n1->prox = (*L2);
            break;
        }
        n1 = n1->prox;
    }
    /// Criando uma lista que recebera a uniao dessas listas
    Lista* L3 = cria_lista();
    *L3 = *L1;
    /// Liberando a L1 e a L2
    *L1 = NULL;
    *L2 = NULL;
    libera_lista(L1);
    libera_lista(L2);

    return L3;
}

int remove_repetidos(Lista* li){
    /// Verifica se a lista existe e se tem conteudo
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    /// Criando um no que ira ficar comparando
    Elemento* comp = *li;
    /// Criando um no que ficara um passo atras arrumando a conexao da lista
    Elemento* ant = *li;
    /// Criando um no que ficara a frente para comparar
    Elemento* no = ant->prox;
    /// Criando um auxiliar para fazer remocao
    Elemento* aux;
    /// Caso de parada
    if(comp == NULL){
        return 1;
    }else{ /// recursao
        while(no != NULL){
            if(no->dados.matricula == comp->dados.matricula){
                ant->prox = no->prox;
                aux = no;
                no = no->prox;
                free(aux);
            }else{
                ant = ant->prox;
                no = no->prox;
            }
        }
        comp = comp->prox;
        return remove_repetidos(&comp);
    }
}

Lista* fusao_ordenada(Lista* L1, Lista* L2){
    /// Verifica se a lista 1 existe e se tem conteudo
    if(L1 == NULL || (*L1) == NULL){
        return NULL;
    }
    /// Verifica se a lista 2 existe e se tem conteudo
    if(L2 == NULL || (*L2) == NULL){
        return NULL;
    }
    /// Criando um no para acessar as informacoes da lista 1
    Elemento* n1 = *L1;
    /// Criando um no que ira monitorar o elemento da frente na lista 1
    Elemento* n1_prox = n1->prox;
    /// Criando um no para acessar as informacoes da lista 2
    Elemento* n2 = *L2;
    /// Criando um ant para mudar o prox do no anterior na lista 2
    Elemento* ant_n2 = NULL;
    /** Percorrendo cada no da lista 2 e fazendo a comparacao com os no's da lista 1.
        Para conseguir colocar o no em seu devido lugar seguindo a ordenacao. **/
    while(n2 != NULL){
        if(n1_prox == NULL){
            if(n2->prox == NULL){
                if(n1 == *L1){
                    *L1 = *L2;
                }
                n2->prox = n1;
                break;
            }
            else if(n1->dados.matricula >= n2->dados.matricula && n1->dados.matricula <= n2->prox->dados.matricula){
                if(n1 == *L1){
                    *L1 = *L2;
                }
                n1->prox = n2->prox;
                n2->prox = n1;
                break;
            }
            else{
                n2 = n2->prox;
            }
        }
        else if(n2->dados.matricula >= n1->dados.matricula && n2->dados.matricula <= n1_prox->dados.matricula){
            n1->prox = n2;
            ant_n2 = n2;
            n2 = n2->prox;
            ant_n2->prox = n1_prox;
            n1 = n1->prox;
        }
        else{
            n1 = n1->prox;
            n1_prox = n1_prox->prox;
        }
    }
    /// Criando uma lista que recebera a fusao ordenada dessas listas
    Lista* L3 = cria_lista();
    *L3 = *L1;
    /// Liberando a L1 e a L2
    *L1 = NULL;
    *L2 = NULL;
    libera_lista(L1);
    libera_lista(L2);

    return L3;
}

int Troca_posicao(Lista* li, int matricula){
    /// Verifica se a lista existe e se tem conteudo
    if(li == NULL || (*li) == NULL){
        return 0;
    }
    /// Criando um no para acessar as informacoes da lista
    Elemento* no = *li;
    /// Criando um prox para poder realizar a troca dos apontadores
    Elemento* prox =  no->prox;
    /// Se a troca for no inicio
    if(no->dados.matricula == matricula){
        no->prox = prox->prox;
        prox->prox = no;
        *li = prox;
        return 1;
    }
    /// Loop para percorrer a lista
    while(prox != NULL){
        if(prox->dados.matricula == matricula){
            /// Se nao existir um elemento na frente a troca nao sera realizada
            if(prox->prox == NULL){
                return 0;
            }
            no->prox = prox->prox;
            prox->prox = (no->prox)->prox;
            (no->prox)->prox = prox;
            return 1;
        }
        else{
            no = no->prox;
            prox = prox->prox;
        }
    }
    return 0;
}
