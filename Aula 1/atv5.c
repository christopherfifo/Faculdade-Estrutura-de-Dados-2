#include <stdio.h>
#include <stdlib.h>


void Ordena_insertionSort(int *v, int n){
    int i, j, aux;
    for(i = 1; i < n; i++){
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j-1]); j--){ 
            v[j] = v[j-1];
        }
        v[j] = aux;
    }
}

void imprimirVetor(int v[], int n){ 
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}
int main()
{
    int vetor[] = {120, 150, 110, 130, 100, 160, 140, 190, 180, 170};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor desordenado: \n");
    imprimirVetor(vetor, n);

    printf("\nOrdenando por InsertionSort: \n\n");
    Ordena_insertionSort(vetor, n);

    printf("Vetor ja ordenado por InsertionSort:\n");
    imprimirVetor(vetor, n);
    return 0;
}
