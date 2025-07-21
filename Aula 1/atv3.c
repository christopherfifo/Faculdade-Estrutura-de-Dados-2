#include <stdio.h>

void bubbleSortOscilante(int arr[], int n) {
    int trocou = 1;
    int inicio = 0, fim = n - 1;

    while (trocou) {
        trocou = 0;

        for (int i = inicio; i < fim; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                trocou = 1;
            }
        }

        if (!trocou) break;

        trocou = 0;
        fim--;

        for (int i = fim - 1; i >= inicio; i--) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                trocou = 1;
            }
        }
        inicio++;
    }
}

void imprimirVetor(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {120, 150, 110, 130, 100, 160, 140, 190, 180, 170};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("\nVetor desordenado: \n");
    imprimirVetor(vetor, n);

    printf("\nOrdenando por metodo bubbleSort Oscilante - CocktailSort:\n");
    bubbleSortOscilante(vetor, n);

    printf("\nVetor ja ordenado: \n");
    imprimirVetor(vetor, n);

    return 0;
}
