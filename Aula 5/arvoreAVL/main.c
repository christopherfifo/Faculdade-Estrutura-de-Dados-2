#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

void exibirMensagemInsercao(int resultado);
void exibirVisita(const char *tipo, void (*func)(arvAVL *), arvAVL *raiz);
void exibirBusca(arvAVL *raiz, int valor);

int main() {
    int x;
    int valor;
    arvAVL *raiz = cria_arvAVL();

    printf("\n");
    printf("\t=====================================\n");
    printf("\t||       Arvore AVL de Busca    ||\n");
    printf("\t=====================================\n\n");

    int elementos[] = {160, 150, 100, 110, 130, 140, 120, 170, 180, 190, 200, 200};
    for (int i = 0; i < 12; i++) {
        x = insere_arvAVL(raiz, elementos[i]);
        exibirMensagemInsercao(x);
    }

    printf("\n");

    if (vazia_arvAVL(raiz)) {
        printf("\tA arvore esta vazia.\n");
    } else {
        printf("\tA arvore possui elementos.\n");
    }
    printf("\n");

    printf("\tAltura da arvore: %d\n\n", altura_arvAVL(raiz));
    printf("\tTotal de nos na arvore: %d\n", totalNO_arvAVL(raiz));

    exibirVisita("pre-Ordem", preOrdem_arvAVL, raiz);
    exibirVisita("em-Ordem", emOrdem_arvAVL, raiz);
    exibirVisita("pos-Ordem", posOderm_arvAVL, raiz);

    printf("\tDigite o valor que deseja remover: ");
    scanf("%d", &valor);

    x = remove_arvAVL(raiz, valor);
    
    if (x) {
        printf("\tElemento removido com sucesso.\n");
    } else {
        printf("\tElemento nao encontrado na arvore.\n");
    }

    exibirVisita("pos-Ordem apos a remocao", posOderm_arvAVL, raiz);

    exibirBusca(raiz, 140);

    liberar_arvAVL(raiz);

    return 0;
}

void exibirMensagemInsercao(int resultado) {
    if (resultado) {
        printf("\tElemento inserido na arvore com sucesso.\n");
    } else {
        printf("\tERRO: elemento nao inserido na arvore.\n");
    }
}


void exibirVisita(const char *tipo, void (*func)(arvAVL *), arvAVL *raiz) {
    printf("\n\tVisitando em %s:\n", tipo);
    func(raiz);
    printf("\n");
}

void exibirBusca(arvAVL *raiz, int valor) {
    printf("\tBusca na Arvore Binaria:\n");
    if (consulta_arvAVL(raiz, valor)) {
        printf("\tConsulta realizada com sucesso!\n");
    } else {
        printf("\tElemento nao encontrado...\n");
    }
    printf("\n");
}
