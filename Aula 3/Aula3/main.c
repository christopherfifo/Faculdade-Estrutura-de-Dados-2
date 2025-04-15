#include "hashTable.h"
#include <ctype.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "C");
    int tamanho;
    printf("TAMANHO DA TABELA HASH (recomendado numero primo): ");
    scanf("%d", &tamanho);

    Hash* ha = criaHash(tamanho);
    if (ha == NULL) {
        printf("Erro ao criar tabela hash!\n");
        return 1;
    }

    int modo;
    do {
        printf("\n----- MENU PRINCIPAL -----\n");
        printf("[1] Modo sem tratamento de colisoes\n");
        printf("[2] Modo com tratamento de colisoes\n");
        printf("[0] Sair\n");
        printf("Escolha o modo de operacao: ");
        scanf("%d", &modo);

        switch (modo) {
            case 1:
                printf("\n--- MODO SEM TRATAMENTO DE COLISOES ---\n");
                menuOperacoes(ha, 0);
                break;

            case 2:
                printf("\n--- MODO COM TRATAMENTO DE COLISOES ---\n");
                menuOperacoes(ha, 1);
                break;

            case 0:
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nopcao invalida!\n");
        }
    } while (modo != 0);

    liberaHash(ha);
    return 0;
}