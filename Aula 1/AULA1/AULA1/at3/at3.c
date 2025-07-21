#include <stdio.h>
#include <stdlib.h>


//VETOR ORDENADO BUBBLU SORT OSCILANTE

void OrdenaBubbleSortOsci(int *v, int n);


int main(){
    //vetor desordenado
    int i, vetorDesord[10] = {120, 150, 110, 130, 100, 160, 140, 190, 170, 180};

    //imprimindo o vetor desordenado
    printf("Vetor Desordenado:\n\n");
    for(i = 0; i < 10; i++){
        printf(" %d |", vetorDesord[i]);
    }

    printf("\nordenando por BubbleSort:");

    //ordenando o vetor com a funcao
    OrdenaBubbleSortOsci(vetorDesord, 10);

    printf("Vetor Ordenado:\n\n");
    for(i = 0; i < 10; i++){
        printf(" %d |", vetorDesord[i]);
    }



}

void OrdenaBubbleSortOsci(int *v, int n /*tamanho do vetor*/){
    int i, k, j, trocou, aux, inicio = 0, fim = n - 1; // trocou -> trocou? se n trocou ate o fim do for, o vetor esta ordenado
    do{
        trocou = 0;
        for(j = 0; j < n; j++){
            if(j % 2 == 0){//se par, colocar o maior no final
                for(i = 0; i < fim; i++){//percorre ate o final
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
                 fim--;//diminuir o final pois o final foi colocado
            }else{//se impar, colocar o menor no inicio

                    for(k = fim; k < 0; k--){//percorre do final ate o coeço
                        if(v[k] < v[k-1]){//B < A? O DA FRENTE É MENOR Q O DE TRAS? TROCA.
                            aux = v[k];//aux recebe o primeiro
                            v[k] = v[k-1];//o primeiro recebe o segundo
                            v[k-1] = aux;//o segundo rebe o aux que é o valor do primeiro
                        }
                    inicio++;//como o primeiro ja e o menor, n precisamos mais verificar ele
                  }
            }
            //cada vez que o for acaba o maior elem encontrado vai para o final, assim, n é preciso verificar ele
            //nas proximas vezes pois ja sabemos q ele é o maior, assim diminuimos o tamanho de ate aonde no vetor iremos percorrer


        }
    }while(trocou != 0);//enquando ele fizer trocas, repetir o processo ate o vetor ficar na ordem

}
