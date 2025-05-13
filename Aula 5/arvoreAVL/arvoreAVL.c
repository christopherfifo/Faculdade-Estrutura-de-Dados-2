#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

typedef struct NO{
    int info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

arvAVL *cria_arvAVL(){
    arvAVL *raiz = (arvAVL*) malloc(sizeof(arvAVL));
    if (raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

int vazia_arvAVL(arvAVL *raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

int altura_arvAVL(arvAVL *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = altura_arvAVL(&((*raiz)->esq));
    int alt_dir = altura_arvAVL(&((*raiz)->dir));
    if(alt_esq > alt_dir){
        return(alt_esq + 1);
    }else{
        return(alt_dir + 1);
    }
}

// int insere_arvAVL(arvAVL *raiz, int valor){
//     if(raiz == NULL){
//         return 0;
//     }
//     struct NO *novo;
//     novo = (struct NO*) malloc(sizeof(struct NO));
//     if(novo == NULL){
//         return 0;
//     }
//     novo->info = valor;
//     novo->dir = NULL;
//     novo->esq = NULL;
//     if(*raiz == NULL){
//         *raiz = novo;
//     }else{
//         struct NO *atual = *raiz;
//         struct NO *ant = NULL;
//         while(atual != NULL){
//             ant = atual;
//             if(valor == atual->info){
//                 free(novo);
//                 return 0;
//             }
//             if(valor > atual->info){
//                 atual = atual->dir;
//             }else{
//                 atual = atual->esq;
//             }
//         }
//         if(valor > ant->info){
//             ant->dir = novo;
//         }else{
//             ant->esq = novo;
//         }
//     }
//     return 1;
// }

int totalNO_arvAVL(arvAVL *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = totalNO_arvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_arvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}


void preOrdem_arvAVL(arvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("\t%d\n", (*raiz)->info);
        preOrdem_arvAVL(&((*raiz)->esq));
        preOrdem_arvAVL(&((*raiz)->dir));
    }
}


void emOrdem_arvAVL(arvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdem_arvAVL(&((*raiz)->esq));
        printf("\t%d\n", (*raiz)->info);
        emOrdem_arvAVL(&((*raiz)->dir));
    }
}

// struct NO *remove_atual(struct NO *atual){
//     struct NO *no1, *no2;
//     if(atual->esq == NULL){
//         no2 = atual->dir;
//         free(atual);
//         return no2;
//     }
//     no1 = atual;
//     no2 = atual->esq;
//     while(no2->dir != NULL){
//         no1 = no2;
//         no2 = no2->dir;
//     }
//     if(no1 != atual){
//         no1->dir = no2->esq;
//         no2->esq = atual->esq;
//     }
//     no2->dir = atual->dir;
//     free(atual);
//     return no2;
// }


void posOderm_arvAVL(arvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOderm_arvAVL(&((*raiz)->esq));
        posOderm_arvAVL(&((*raiz)->dir));
        printf("\t%d\n", (*raiz)->info);
    }
}


// int remove_arvAVL(arvAVL *raiz, int valor){
//     if(raiz == NULL){
//         return 0;
//     }
//     struct NO *ant = NULL;
//     struct NO *atual = *raiz;
//     while(atual != NULL){
//         if(valor == atual->info){
//             if(atual == *raiz){
//                 *raiz = remove_atual(atual);
//         }else{
//             if(ant->dir == atual){
//                 ant->dir = remove_atual(atual);
//             }else{
//                 ant->esq = remove_atual(atual);
//             }
//         }
//         return 1;
//     }
//     ant = atual;
//     if(valor > atual->info){
//         atual = atual->dir;
//     }else{
//         atual = atual->esq;
//     }
// }
// }


int consulta_arvAVL(arvAVL *raiz, int valor){
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


void liberar_arvAVL(arvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    libera_NO(*raiz);
    free(raiz);
}
