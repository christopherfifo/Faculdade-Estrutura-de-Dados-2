#include <stdio.h>
#include <stdlib.h>
#include "rubroNegra.h"

#define RED 1
#define BLACK 0

typedef struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
    int cor;
};

arvoreLLRB *cria_arvoreLLRB(){
    arvoreLLRB *raiz = (arvoreLLRB*) malloc(sizeof(arvoreLLRB));
    if (raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

int vazia_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

int altura_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = altura_arvoreLLRB(&((*raiz)->esq));
    int alt_dir = altura_arvoreLLRB(&((*raiz)->dir));
    if(alt_esq > alt_dir){
        return(alt_esq + 1);
    }else{
        return(alt_dir + 1);
    }
}

int insere_arvoreLLRB(arvoreLLRB *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO *novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL){
        return 0;
    }
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL){
        *raiz = novo;
    }else{
        struct NO *atual = *raiz;
        struct NO *ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;
            }
            if(valor > atual->info){
                atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
        if(valor > ant->info){
            ant->dir = novo;
        }else{
            ant->esq = novo;
        }
    }
    return 1;
}

int totalNO_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = totalNO_arvoreLLRB(&((*raiz)->esq));
    int alt_dir = totalNO_arvoreLLRB(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}


void preOrdem_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("\t%d\n", (*raiz)->info);
        preOrdem_arvoreLLRB(&((*raiz)->esq));
        preOrdem_arvoreLLRB(&((*raiz)->dir));
    }
}


void emOrdem_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdem_arvoreLLRB(&((*raiz)->esq));
        printf("\t%d\n", (*raiz)->info);
        emOrdem_arvoreLLRB(&((*raiz)->dir));
    }
}

struct NO *remove_atual(struct NO *atual){
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
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}


void posOderm_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOderm_arvoreLLRB(&((*raiz)->esq));
        posOderm_arvoreLLRB(&((*raiz)->dir));
        printf("\t%d\n", (*raiz)->info);
    }
}


int remove_arvoreLLRB(arvoreLLRB *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO *ant = NULL;
    struct NO *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz){
                *raiz = remove_atual(atual);
        }else{
            if(ant->dir == atual){
                ant->dir = remove_atual(atual);
            }else{
                ant->esq = remove_atual(atual);
            }
        }
        return 1;
    }
    ant = atual;
    if(valor > atual->info){
        atual = atual->dir;
    }else{
        atual = atual->esq;
    }
}
}


int consulta_arvoreLLRB(arvoreLLRB *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}

void libera_NO(struct NO *no){
    if(no == NULL){
        return;
    }
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}


void liberar_arvoreLLRB(arvoreLLRB *raiz){
    if(raiz == NULL){
        return;
    }
    libera_NO(*raiz);
    free(raiz);
}


int cor(struct NO *H){
    if(H == NULL){
        return BLACK;
    }
    return H->cor;
}

void trocaCor(struct NO *H){
    H->cor = !H->cor;
    if(H->esq != NULL){
        H->esq->cor = !H->esq->cor;
    }
    if(H->dir != NULL){
        H->dir->cor = !H->dir->cor;
    }
}

struct NO *rotacionaEsquerda(struct NO *A){
    struct NO *B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO *rotacionaDireita(struct NO *A){
    struct NO *B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct NO *move2EsqRed(struct NO *H){
    trocaCor(H);
    if(cor(H->dir->esq) == RED){
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    return H;
}

struct NO *move2DirRed(struct NO *H){
    trocaCor(H);
    if(cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    return H;
}

struct NO *balancear(struct NO *H){
    if(cor(H->dir) == RED){
        H = rotacionaEsquerda(H);
    }
    if(H->esq != NULL && cor(H->dir) == RED && cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
    }
    if(cor(H->esq) == RED && cor(H->dir) == RED){
        trocaCor(H);
    }
    return H;
}