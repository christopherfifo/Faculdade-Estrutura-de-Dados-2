#include <stdio.h>
#include <stdlib.h>

int buscaLinear(int *vetor, int n, int elem);
int buscaOrdenada(int *vetor, int n, int elem);
int buscaBinaria(int *vetor, int n, int elem);

int main(){

    int vetorOrdenado[10] ={100,110,120,130,140,150,160,170,180,190};
    int vetorDesordenado[10] = {140, 180, 100, 160, 170, 120, 150, 190, 130, 110};
    int n = 10;
    int elem;

    printf("/n Digite o elemento que voce quer achar: ");
    scanf("%d", &elem);

    system("pause");
    return 0;
}

int buscaLinear(int *vetor, int n, int elem){
    int i;
    for(i = 0; i < n; i++){
        if(elem == vetor[i]){
            return i;
        }
    }
    return -1;
}

int buscaOrdenada(int *vetor, int n, int elem){
    int i;
    for(i = 0; 1 < n; i++){{
        if(elem == vetor[i]){
            return i;
        }else{
            if(elem < vetor[i]){
                return -1;
            }
        }
    }
    return -1;
}

int buscaBinaria(int *vetor, int n, int elem){
    int i, inicio, meio, fim;
    inicio = 0;
    fim = n - 1;

    while(inicio <= fim){
        meio = (inicio + fim)/2;
        if(elem < vetor[meio]){
            fim = meio - 1; // busca na metade esquerda
        } else {
            if(elem > vetor[meio]){
                inicio = meio + 1; // busca na metade direita
            } else{
                return meio;
            }
        }
    }
    return -1;//elemento não encontrado
}
