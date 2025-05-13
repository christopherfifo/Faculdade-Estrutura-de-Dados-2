#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"
int main()
{
    int x;
    ArvBin *raiz;

    raiz = cria_arvBin();

    printf("\t\t\tArvore Binaria de Busca\n\n");

    x = insere_arvBin(raiz, 150);
    if(x){
        printf("\tElemento inserido na arvore com sucesso. \n");
    }else{
        printf("\tERRO: elemento nao inserido na arvore. \n");
    }

    x = insere_arvBin(raiz, 110);
    if(x){
        printf("\tElemento inserido na arvore com sucesso. \n");
    }else{
        printf("\tERRO: elemento nao inserido na arvore. \n");
    }

    x = insere_arvBin(raiz, 100);
    if(x){
        printf("\tElemento inserido na arvore com sucesso. \n");
    }else{
        printf("\tERRO: elemento nao inserido na arvore. \n");
    }

    x = insere_arvBin(raiz, 130);
    if(x){
        printf("\tElemento inserido na arvore com sucesso. \n");
    }else{
        printf("\tERRO: elemento nao inserido na arvore. \n");
    }

    x = insere_arvBin(raiz, 120);
    if(x){
        printf("\tElemento inserido na arvore com sucesso. \n");
    }else{
        printf("\tERRO: elemento nao inserido na arvore. \n");
    }

    x = insere_arvBin(raiz, 140);
    if(x){
        printf("\tElemento inserido na arvore com sucesso. \n");
    }else{
        printf("\tERRO: elemento nao inserido na arvore. \n");
    }

    x = insere_arvBin(raiz, 160);
    if(x){
        printf("\tElemento inserido na arvore com sucesso. \n");
    }else{
        printf("\tERRO: elemento nao inserido na arvore. \n");
    }

    printf("\n");

    if(vazia_arvBin(raiz)){
        printf("\tA arvore esta vazia.\n");
    }else{
        printf("\tA arvore possui elementos.\n");
    }
    printf("\n");

    x = altura_arvBin(raiz);
    printf("\tAltura da arvore: %d\n\n", x);

    x = totalNO_arvBin(raiz);
    printf("\tTotal de nos na arvore: %d\n", x);

    printf("\n\tVisitando em pre-Ordem: \n");
    preOrdem_arvBin(raiz);
    printf("\n");

    printf("\n\tVisitando em-Ordem: \n");
    emOrdem_arvBin(raiz);
    printf("\n");

    printf("\n\tVisitando em pos-Ordem: \n");
    posOderm_arvBin(raiz);
    printf("\n");

    x = remove_arvBin(raiz, 100);

    printf("\n\tVisitando em pos-Ordem apos a remocao: \n");
    posOderm_arvBin(raiz);
    printf("\n");

    printf("\tBusca na Arvore Binaria: \n");
    if(consulta_arvBin(raiz, 140)){
        printf("\tConsulta realizada com sucesso!");
    }else{
        printf("\tElemento nao encontrado...");
    }

    printf("\n");

    liberar_arvBin(raiz);
}
