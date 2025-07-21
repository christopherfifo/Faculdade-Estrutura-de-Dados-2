//atividade 5 - ordenacao por insertion sort

#include <stdio.h>
#include <stdlib.h>

void ordenaInsertionSort(int *v, int n);

int main(){
    //variaiveis
        int k, vetorDesord[10] = {120, 150, 110, 130, 100, 160, 140, 190, 170, 180};

    //imprimindo o vetor desordenado
    printf("Vetor desordenado:\n");
    for(k = 0; k < 10; k++){
        printf("| %d ", vetorDesord[k]);
    }

    //chamando a funcao para ordenar o vetor
    ordenaInsertionSort(vetorDesord, 10);

    //imprimindo o vetor ordenado
    printf("Vetor ordenado pela funcao SelectionSort:\n");
    for(k = 0; k < 10; k++){
        printf("| %d ", vetorDesord[k]);
    }

}

void ordenaInsertionSort(int *v, int n)//vetor e numeo de elementos no vetor
{
    int i, j, aux;
    for(i = 1; i < n; i++){
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j-1]); j--){
            v[j] = v[j-1];
        }
        v[j] = aux;
    }
}
