#include <stdio.h>
#include <stdlib.h>
#include "rubroNegra.h"

void exibirMensagemInsercao(int resultado);
void exibirVisita(const char *tipo, void (*func)(arvoreLLRB *), arvoreLLRB *raiz);
void exibirBusca(arvoreLLRB *raiz, int valor);

int main() {
    int x;
    arvoreLLRB *raiz = cria_arvoreLLRB();

    printf("\n");
    printf("\t=====================================\n");
    printf("\t||       Arvore Rubro Negra   ||\n");
    printf("\t=====================================\n\n");

    int elementos[] = {150, 110, 100, 130, 120, 140, 160};
    for (int i = 0; i < 7; i++) {
        x = insere_arvoreLLRB(raiz, elementos[i]);
        exibirMensagemInsercao(x);
    }

    printf("\n");

    if (vazia_arvoreLLRB(raiz)) {
        printf("\tA arvore esta vazia.\n");
    } else {
        printf("\tA arvore possui elementos.\n");
    }
    printf("\n");

    printf("\tAltura da arvore: %d\n\n", altura_arvoreLLRB(raiz));
    printf("\tTotal de nos na arvore: %d\n", totalNO_arvoreLLRB(raiz));

    exibirVisita("pre-Ordem", preOrdem_arvoreLLRB, raiz);
    exibirVisita("em-Ordem", emOrdem_arvoreLLRB, raiz);
    exibirVisita("pos-Ordem", posOderm_arvoreLLRB, raiz);

    x = remove_arvoreLLRB(raiz, 100);
    exibirVisita("pos-Ordem apos a remocao", posOderm_arvoreLLRB, raiz);

    exibirBusca(raiz, 140);

    liberar_arvoreLLRB(raiz);

    return 0;
}

void exibirMensagemInsercao(int resultado) {
    if (resultado) {
        printf("\tElemento inserido na arvore com sucesso.\n");
    } else {
        printf("\tERRO: elemento nao inserido na arvore.\n");
    }
}


void exibirVisita(const char *tipo, void (*func)(arvoreLLRB *), arvoreLLRB *raiz) {
    printf("\n\tVisitando em %s:\n", tipo);
    func(raiz);
    printf("\n");
}

void exibirBusca(arvoreLLRB *raiz, int valor) {
    printf("\tBusca na Arvore Binaria:\n");
    if (consulta_arvoreLLRB(raiz, valor)) {
        printf("\tConsulta realizada com sucesso!\n");
    } else {
        printf("\tElemento nao encontrado...\n");
    }
    printf("\n");
}