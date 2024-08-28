#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h" //inclui os Prot�tipos

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento j� existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 � o n� anterior a r na ordem e-r-d
    // no1 � o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}


void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

/// Funcoes dos exercicios desenvolvidas por mim e minha dupla

void emOrdem_Arvore(ArvBin *raiz){
    /// Verificando se a arvore existe
    if(raiz == NULL){
        return;

    }
    /// Recursao baseada na explicacao da aula do professor no youtube
    if(*raiz != NULL){
        emOrdem_Arvore(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);
        emOrdem_Arvore(&((*raiz)->dir));

    }

}

void posOrdem_Arvore(ArvBin *raiz){
    /// Verificando se a arvore existe
    if(raiz == NULL){
        return;

    }
    /// Recursao baseada na explicacao da aula do professor no youtube
    if(*raiz != NULL){
        emOrdem_Arvore(&((*raiz)->dir));
        emOrdem_Arvore(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);

    }

}

int TotalNO_Arvore(ArvBin *raiz){
    /// Variavel para contar toda vez que passar por um no
    int cont = 1;
    /// Verificando se a arvore existe
    if(raiz == NULL){
        return 0;

    } /// Recursao baseada na rechamada somente se o no existir
    if(*raiz != NULL){
        if((*raiz)->esq != NULL){
            cont += TotalNO_Arvore(&((*raiz)->esq));

        }
        if((*raiz)->dir != NULL){
            cont += TotalNO_Arvore(&((*raiz)->dir));

        }

    }
    return cont;
}


int Cons_Arvore(ArvBin *raiz, int valor){
    /// Verifica se a arvore existe e se tem conteudo
    if(raiz == NULL || *raiz == NULL){
        return 0;

    }
    /// Criando o n� para percorrer e achar o valor na arvore
    struct NO* consult = *raiz;
    /// Percorrendo a arvore e procurando o valor
    while(consult != NULL){
        if(valor > consult->info){
            consult = consult->dir;
        }
        else if(valor < consult->info){
            consult = consult->esq;
        }
        else{
            return 1;
        }

    }
    /// valor nao encontrado
    return 0;
}

