#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h" //inclui os Protótipos

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
    libera_NO(*raiz);//libera cada nó
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
                return 0;//elemento já existe
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
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
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
    /// Criando o nó para percorrer e achar o valor na arvore
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

int CalcNO_folha(ArvBin *raiz){
    /// Variavel para contar toda vez que passar por um no
    int cont = 0;
    /// Verificando se a arvore existe
    if(raiz == NULL){
        return 0;

    } /** Recursao baseada na rechamada somente se o no existir.
          E se nao tiver filhos o contador sera incrementado **/
    if(*raiz != NULL){
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            cont++;

        }
        if((*raiz)->esq != NULL){
            cont += CalcNO_folha(&((*raiz)->esq));

        }
        if((*raiz)->dir != NULL){
            cont += CalcNO_folha(&((*raiz)->dir));

        }

    }

    return cont;
}

void imprime_hierarquia(ArvBin *raiz){
    /// Verificando se a arvore existe
    if(raiz == NULL){
        return;

    }
    /// Recursao que passa pela arvore e notifica infos sobre o NO
    if(*raiz != NULL){
        printf("------------------\n");
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            printf("Folha: %i \n",(*raiz)->info);
        }
        else{
            printf("Pai: %i \n",(*raiz)->info);
            if((*raiz)->esq != NULL){
                printf("Filho da Esquerda: %i \n",((*raiz)->esq)->info);
            }
            if((*raiz)->dir != NULL){
                printf("Filho da Direita: %i \n",((*raiz)->dir)->info);
            }

        }
        printf("------------------\n");
        imprime_hierarquia(&((*raiz)->esq));
        imprime_hierarquia(&((*raiz)->dir));
    }

}

int qtdValor_aproximado_Arvore(ArvBin *raiz, int valor){
    /// Verifica se a arvore existe e se tem conteudo
    if(raiz == NULL || *raiz == NULL){
        return 0;

    }
    /// Variavel para contar valores aproximados ou exatos
    int cont = 0;
    /// Criando o nó para percorrer e achar valores parecidos na arvore
    struct NO* consult = *raiz;
    /// Percorrendo a arvore e procurando os valores
    while(consult != NULL){
        if(valor > consult->info && (valor - 10) <  consult->info){
            cont++;
        }
        if(valor < consult->info && (valor + 10) >  consult->info){
            cont++;
        }

        if(valor > consult->info){
            consult = consult->dir;
        }
        else if(valor < consult->info){
            consult = consult->esq;
        }
        else{
            printf("\n !!! Esse valor foi encontrado na Arvore !!! \n");
            return cont;
        }

    }

    return cont;
}

void imprimeDecre_folhas(ArvBin *raiz){
    /// Verificando se a arvore existe
    if(raiz == NULL){
        return;

    } /// Percorrendo a matriz indo para o lado com maior valor, e printando os NO folha
    if(*raiz != NULL){
        imprimeDecre_folhas(&((*raiz)->dir));
        imprimeDecre_folhas(&((*raiz)->esq));
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            printf("%d\n",(*raiz)->info);
        }
    }

}

int QtdNOarvores_iguais(ArvBin *raiz1, ArvBin *raiz2){
    /// Variavel para contar toda vez que passar por um no
    int cont = 1;
    /// Verificando se as arvores existem
    if(raiz1 == NULL || raiz2 == NULL){
        return 0;

    }
    /// Recursao baseada na rechamada somente se o no existir e se tiverem o mesmo valor
    if(*raiz1 != NULL && *raiz2 != NULL){
        if((*raiz1)->esq != NULL && (*raiz2)->esq != NULL){
            if((*raiz1)->info == (*raiz2)->info){
                cont += QtdNOarvores_iguais(&((*raiz1)->esq), &((*raiz2)->esq));

            }
        }
        if((*raiz1)->dir != NULL && (*raiz2)->dir != NULL){
            if((*raiz1)->info == (*raiz2)->info){
                cont += QtdNOarvores_iguais(&((*raiz1)->dir), &((*raiz2)->dir));

            }

        }

    }
    /// Voltara a quantidade de NO's totais das arvores se forem iguais
    return cont;
}

int eliminaPares(ArvBin *raiz){
    /// Verificando se a arvore existe
    if(raiz == NULL){
        return 0;

    }
    /// Percorrendo a Arvore e indentificando os elementos pares;
    if(*raiz != NULL){
        if((*raiz)->esq != NULL){
            eliminaPares(&((*raiz)->esq));
        }
        if((*raiz)->dir != NULL){
            eliminaPares(&((*raiz)->dir));
        }
        if((*raiz)->info % 2 == 0){
            remove_ArvBin(raiz, (*raiz)->info);
        }

    }

    return 1;
}

int arvoresSimilares(ArvBin *raiz1, ArvBin *raiz2){
    /// Verifica se ambas existem
    if(raiz1 == NULL && raiz2 == NULL){
        return 0;

    }
    /// Verificando se uma das arvores existem
    if(raiz1 == NULL || raiz2 == NULL){
        return 0;

    }

    ///  Passo recursivo
    if(*raiz1 == NULL || *raiz2 == NULL){
        arvoresSimilares(&((*raiz1)->esq), &((*raiz2)->esq));
        arvoresSimilares(&((*raiz1)->dir), &((*raiz2)->dir));

    }
    /// Verifica se pelo menos um dos filhos esquerdos é NULL
    if((*raiz1)->esq == NULL || (*raiz2)->esq == NULL){
        return 0;

    }
    /// Verifica se ambos os filhos esquerdos são NULL
    if((*raiz1)->esq == NULL && (*raiz2)->esq == NULL){
        return 1;

    }
    /// Verifica se pelo menos um dos filhos direitos é NULL
    if((*raiz1)->dir == NULL || (*raiz2)->dir == NULL){
        return 0;

    }
    /// Verifica se ambos os filhos direitos são NULL
    if((*raiz1)->dir == NULL && (*raiz2)->dir == NULL){
        return 1;

    }

    return 0;
}

void preOrdemLetras_ArvBin(ArvBin *raiz){
    /// Verifica se a Arvore existe
    if(raiz == NULL)
        return;
    /// Printa as informacoes como letras ao inves de inteiros
    if(*raiz != NULL){
        printf("%c\n",(*raiz)->info);
        preOrdemLetras_ArvBin(&((*raiz)->esq));
        preOrdemLetras_ArvBin(&((*raiz)->dir));
    }
}

void preOrdemOperacao_ArvBin(ArvBin *raiz){
    /// Verifica se a Arvore existe
    if(raiz == NULL)
        return;
    /// Printa a operacao da arvore
    if(*raiz != NULL){
        if((*raiz)->info == 45 || (*raiz)->info == 36){
            printf("+\n");
        }
        if((*raiz)->info == 46){
            printf("5\n");
        }
        if((*raiz)->info == 32){
            printf("*\n");
        }
        if((*raiz)->info == 24){
            printf("-\n");
        }
        if((*raiz)->info == 17){
            printf("6\n");
        }
        if((*raiz)->info == 26){
            printf("3\n");
        }
        if((*raiz)->info == 38){
            printf("1\n");
        }
        if((*raiz)->info == 33){
            printf("4\n");
        }
        preOrdemOperacao_ArvBin(&((*raiz)->esq));
        preOrdemOperacao_ArvBin(&((*raiz)->dir));
    }
}

void posOrdemOperacao_ArvBin(ArvBin *raiz){
    /// Verifica se a Arvore existe
    if(raiz == NULL)
        return;
    /// Printa a operacao da arvore
    if(*raiz != NULL){
        posOrdemOperacao_ArvBin(&((*raiz)->dir));
        posOrdemOperacao_ArvBin(&((*raiz)->esq));
        if((*raiz)->info == 45 || (*raiz)->info == 36){
            printf("+\n");
        }
        if((*raiz)->info == 46){
            printf("5\n");
        }
        if((*raiz)->info == 32){
            printf("*\n");
        }
        if((*raiz)->info == 24){
            printf("-\n");
        }
        if((*raiz)->info == 17){
            printf("6\n");
        }
        if((*raiz)->info == 26){
            printf("3\n");
        }
        if((*raiz)->info == 38){
            printf("1\n");
        }
        if((*raiz)->info == 33){
            printf("4\n");
        }
    }
}

void emOrdemOperacao_ArvBin(ArvBin *raiz){
    /// Verifica se a Arvore existe
    if(raiz == NULL)
        return;
    /// Printa a operacao da arvore
    if(*raiz != NULL){
        emOrdemOperacao_ArvBin(&((*raiz)->esq));
        if((*raiz)->info == 45 || (*raiz)->info == 36){
            printf("+\n");
        }
        if((*raiz)->info == 46){
            printf("5\n");
        }
        if((*raiz)->info == 32){
            printf("*\n");
        }
        if((*raiz)->info == 24){
            printf("-\n");
        }
        if((*raiz)->info == 17){
            printf("6\n");
        }
        if((*raiz)->info == 26){
            printf("3\n");
        }
        if((*raiz)->info == 38){
            printf("1\n");
        }
        if((*raiz)->info == 33){
            printf("4\n");
        }
        emOrdemOperacao_ArvBin(&((*raiz)->dir));
    }
}

int result(ArvBin* raiz) {
    /// Verifica se a Arvore existe
    if (raiz == NULL){
        return 0;

    }

    /// Se o nó for um operando retorne seu valor
    if ((*raiz)->esq == NULL && (*raiz)->dir == NULL){
        return (*raiz)->info;

    }

    /// Calcula o valor da esquerda
    int valor_esq = result(&((*raiz)->esq));

    /// Calcula o valor da direita
    int valor_dir = result(&((*raiz)->dir));

    /// Realiza a operação
    switch ((*raiz)->info) {
        case 45:
            return valor_esq + valor_dir;
        case 36:
            return valor_esq + valor_dir;
        case 32:
            return valor_esq * valor_dir;
        case 24:
            return valor_esq - valor_dir;
        default:
            return 0;

    }

}

