#include <stdio.h>
#include <stdlib.h>


void Ordena_selectionSort(int *v, int n){
    int i, j, menor, troca;
    for(i = 0; i < n -1; i++){
        menor = i;
        for(j = i + 1; j < n; j++){
            if(v[j] < v[menor]){ 
                menor = j;
            }
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];  
            v[menor] = troca;
        }
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

    printf("\nOrdenando por SelectionSort: \n\n");
    Ordena_selectionSort(vetor, n);

    printf("Vetor ja ordenado por SelectionSort:\n");
    imprimirVetor(vetor, n);
    return 0;
}
