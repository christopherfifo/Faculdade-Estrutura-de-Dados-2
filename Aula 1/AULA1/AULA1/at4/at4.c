//atividade 4
//ordenacao por slection sort - busca o menor valor e coloca no inicio do vetor, n --
#include <stdio.h>
#include <stdlib.h>


void ordenaSelectionSort(int *v, int n);


int main(){
    //variaiveis
        int k, vetorDesord[10] = {120, 150, 110, 130, 100, 160, 140, 190, 170, 180};

    //imprimindo o vetor desordenado
    printf("Vetor desordenado:\n");
    for(k = 0; k < 10; k++){
        printf("| %d ", vetorDesord[k]);
    }

    //chamando a funcao para ordenar o vetor
    ordenaSelectionSort(vetorDesord, 10);

    //imprimindo o vetor ordenado
    printf("Vetor ordenado pela funcao SelectionSort:\n");
    for(k = 0; k < 10; k++){
        printf("| %d ", vetorDesord[k]);
    }
}

void ordenaSelectionSort(int *v, int n)/*vetor e tamanho do vetor*/{
    int i, j, menor, aux;
    for(i = 0; i < n; i++){/*seleciona o elemento em i*/
        menor = i;//menor elemento encontrado ate agora, no caso o primeiro
        for(j = i + 1; j < n; j++)/*comparando com os outros elementos do vetor*/{
            if(v[j] < v[menor]){
                    menor = j;//se aquele elemento for menor q o enconrandoo antes, ele passa a ser o menor
            }
        }//depois de percorrer tod o vetor e encontrar o menor elemento
        if(i != menor)/*se o meno num n fo o primeio elem, temos q colocar na 1 posicao so vetor*/{
            aux = v[i];
            v[i] = v[menor];//colocando o numero menor encontrado no inicio do vetor
            v[menor] = aux;
        }
    }
}
