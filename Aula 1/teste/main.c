#include <stdio.h>
#include <locale.h>

int buscaBinaria(int *vetor, int n, int elem) {
    int inicio = 0;
    int fim = n - 1;
    int meio;

    setlocale(LC_ALL, "");

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        printf("inicio: %d, fim: %d, meio: %d, vetor[meio]: %d\n",
               inicio, fim, meio, vetor[meio]);

        if (elem < vetor[meio]) {
            printf("-> %d é menor que %d, procurando na metade esquerda\n\n", elem, vetor[meio]);
            fim = meio - 1;
        } else if (elem > vetor[meio]) {
            printf("-> %d é maior que %d, procurando na metade direita\n\n", elem, vetor[meio]);
            inicio = meio + 1;
        } else {
            printf("Elemento encontrado na posição %d\n", meio);
            return meio;
        }
    }

    printf("Elemento %d não encontrado.\n", elem);
    return -1;
}

int main() {
    int vetor[] = {10, 20, 30, 40, 50};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int elementoProcurado = 35;

    buscaBinaria(vetor, n, elementoProcurado);

    return 0;
}
