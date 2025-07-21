#include <stdio.h>
#include <stdlib.h>

//ORDENAÇÃO BUBBLE SORT - ORDENACAO POR TROCA DE ELEMENTOS VIZINHOS

//   0   1   2   3   4   5   6   7   8   9   - indice no vetor
//  120|150|110|130|100|160|140|190|170|180|

void OrdenaBubbleSort(int *v, int n);

int main(){
    //vetor para ser ordenado
    int i, vetorDesord[10] = {120, 150, 110, 130, 100, 160, 140, 190, 170, 180};

    //imprimindo o vetor desordenado
    printf("Vetor Desordenado:\n\n");
    for(i = 0; i < 10; i++){
        printf(" %d |", vetorDesord[i]);
    }

    printf("\nordenando por BubbleSort:");

    //ordenando o vetor com a funcao
    OrdenaBubbleSort(vetorDesord, 10);

    printf("Vetor Ordenado:\n\n");
    for(i = 0; i < 10; i++){
        printf(" %d |", vetorDesord[i]);
    }

}

void OrdenaBubbleSort(int *v, int n /*tamanho do vetor*/){
    int i, trocou, aux, fim = n - 1; // trocou -> trocou? se n trocou ate o fim do for, o vetor esta ordenado
    do{
        trocou = 0;
        for(i = 0; i < fim; i++){
            if(v[i] > v[i+1]){//A > B? se sim troca -> 150 > 110? sim -> 120|110|150
                aux = v[i];//auxiliar recebe o primeito valor
                v[i] = v[i+1];// o primeiro vcalor recebe o proximo
                v[i+1] = aux;// o segundo recebe o valor da aux
                trocou = i;//cont serve para ver em se esta fazendo trocas, se ele percorrer o vetor
                //e estiver na ordem, ou seja nenhum troca ocorrer, o cont = 0 ate o fim do for
                //e quando while for verificar sera falso, pois contiua == 0, saindo assim do
                //while e agora deixando o vetor ordenado
            }
        }
        fim--;//cada vez que o for acaba o maior elem encontrado vai para o final, assim, n é preciso verificar ele
        //nas proximas vezes pois ja sabemos q ele é o maior, assim diminuimos o tamanho de ate aonde no vetor iremos percorrer

    }while(trocou != 0);//enquando ele fizer trocas, repetir o processo ate o vetor ficar na ordem
}
