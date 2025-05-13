#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

void exibirMensagemInsercao(int resultado);
void exibirVisita(const char *tipo, void (*func)(ArvBin *), ArvBin *raiz);
void exibirBusca(ArvBin *raiz, int valor);

int main() {
    int x;
    ArvBin *raiz = cria_arvBin();

    printf("\n");
    printf("\t=====================================\n");
    printf("\t||       Arvore Binaria de Busca    ||\n");
    printf("\t=====================================\n\n");

    int elementos[] = {150, 110, 100, 130, 120, 140, 160};
    for (int i = 0; i < 7; i++) {
        x = insere_arvBin(raiz, elementos[i]);
        exibirMensagemInsercao(x);
    }

    printf("\n");

    if (vazia_arvBin(raiz)) {
        printf("\tA arvore esta vazia.\n");
    } else {
        printf("\tA arvore possui elementos.\n");
    }
    printf("\n");

    printf("\tAltura da arvore: %d\n\n", altura_arvBin(raiz));
    printf("\tTotal de nos na arvore: %d\n", totalNO_arvBin(raiz));

    exibirVisita("pre-Ordem", preOrdem_arvBin, raiz);
    exibirVisita("em-Ordem", emOrdem_arvBin, raiz);
    exibirVisita("pos-Ordem", posOderm_arvBin, raiz);

    x = remove_arvBin(raiz, 100);
    exibirVisita("pos-Ordem apos a remocao", posOderm_arvBin, raiz);

    exibirBusca(raiz, 140);

    liberar_arvBin(raiz);

    return 0;
}

void exibirMensagemInsercao(int resultado) {
    if (resultado) {
        printf("\tElemento inserido na arvore com sucesso.\n");
    } else {
        printf("\tERRO: elemento nao inserido na arvore.\n");
    }
}


void exibirVisita(const char *tipo, void (*func)(ArvBin *), ArvBin *raiz) {
    printf("\n\tVisitando em %s:\n", tipo);
    func(raiz);
    printf("\n");
}

void exibirBusca(ArvBin *raiz, int valor) {
    printf("\tBusca na Arvore Binaria:\n");
    if (consulta_arvBin(raiz, valor)) {
        printf("\tConsulta realizada com sucesso!\n");
    } else {
        printf("\tElemento nao encontrado...\n");
    }
    printf("\n");
}