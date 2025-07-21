#include <stdio.h>

void exibirVetor(int *vetor, int n) {
    printf("Vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int buscaLinear(int *vetor, int n, int elem) {
    for (int i = 0; i < n; i++) {
        if (vetor[i] == elem) {
            return i;
        }
    }
    return -1;
}

int buscaOrdenada(int *vetor, int n, int elem) {
    for (int i = 0; i < n; i++) {
        if (vetor[i] == elem) {
            return i;
        } else if (vetor[i] > elem) {
            return -1;
        }
    }
    return -1;
}

int buscaBinaria(int *vetor, int n, int elem) {
    int inicio = 0, fim = n - 1, meio;

    while (inicio <= fim) {
        printf("inicio: %d  fim: %d\n", inicio, fim);

        meio = (inicio + fim) / 2;

        if (vetor[meio] == elem) {
            return meio;
        } else if (vetor[meio] < elem) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    int vetorDesordenado[] = {120, 150, 110, 130, 100, 160, 140, 190, 180, 170};
    int vetorOrdenado[] = {100, 110, 120, 130, 140, 150, 160, 170, 180, 190};
    int tamanhoDesordenado = sizeof(vetorDesordenado) / sizeof(vetorDesordenado[0]);
    int tamanhoOrdenado = sizeof(vetorOrdenado) / sizeof(vetorOrdenado[0]);
    int elemento, resultado;

    exibirVetor(vetorDesordenado, tamanhoDesordenado);
    printf("\nElemento a ser procurado por busca linear: ");
    if (scanf("%d", &elemento) == 1) {
        resultado = buscaLinear(vetorDesordenado, tamanhoDesordenado, elemento);
        printf("\nA posição do elemento no vetor é: %d\n\n", resultado);
    } else {
        printf("\nEntrada inválida.\n\n");
        return 1;
    }

    exibirVetor(vetorOrdenado, tamanhoOrdenado);
    printf("\nElemento a ser procurado por busca ordenada: ");
    if (scanf("%d", &elemento) == 1) {
        resultado = buscaOrdenada(vetorOrdenado, tamanhoOrdenado, elemento);
        printf("\nA posição do elemento no vetor é: %d\n\n", resultado);
    } else {
        printf("\nEntrada inválida.\n\n");
        return 1;
    }

    printf("\nElemento a ser procurado por busca binária: ");
    if (scanf("%d", &elemento) == 1) {
        resultado = buscaBinaria(vetorOrdenado, tamanhoOrdenado, elemento);
        printf("\nA posição do elemento no vetor é: %d\n", resultado);
    } else {
        printf("\nEntrada inválida.\n");
        return 1;
    }

    return 0;
}
