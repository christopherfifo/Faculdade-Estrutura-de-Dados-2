#include <stdio.h>
#include <stdlib.h>


void Ordena_bubbleSort(int *v, int n){ 
    int i, continua, aux, fim = n;
    do{
        continua = 0;
        for(i = 0; i < fim - 1; i++){
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);
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

    printf("\nOrdenando por BubbleSort: \n\n");
    Ordena_bubbleSort(vetor, n);

    printf("Vetor ja ordenado por BubbleSort:\n");
    imprimirVetor(vetor, n);
    return 0;
}
