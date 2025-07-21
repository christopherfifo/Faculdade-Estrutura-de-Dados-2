//atividade 1

#include <stdio.h>
#include <stdlib.h>

//programa de busca
//linear - acessa TODOS os itens do vetor buscando tal elemento
//ordenada - busca ate onde ele poderia estar (ex: se 8 n esta entre 7 e 10, ele n esta mais para frenmte no vetor, pois o veto esta ordenado)
//busca binaria - ividir para conquistar

//vetor desordenado para ser utilizado na busca linera
//   0   1   2   3   4   5   6   7   8   9   - indice no vetor
//  120|150|110|130|100|160|140|190|170|180|

int buscaLinear(int *vetor, int n, int elem);

int buscaOrdenada(int *vetor, int n, int elem);

int buscaBinaria (int *vetor, int n, int elem);


int main(){
    int x; //variavel par exibir os sucessor e erros
    int busca; //variavel para o numero que deseja ser buscado
    int vetorDesord[10] = {120, 150, 110, 130, 100, 160, 140, 190, 170, 180};
    int vetorOrd[10]    = {100, 110, 120, 130, 140, 150, 160, 170, 180, 190};

    printf("\n\n\t\tBUSCA LINEAR\n\n");
    printf(" Vetor desordenado para busca linear\n");
    printf("     0   1   2   3   4   5   6   7   8   9 - indice correspondente\n\n");
    printf("    120|150|110|130|100|160|140|190|170|180|\n\n\n");

    printf("Que numero deseja buscar pela busca linear?  ");
    scanf(" %d", &busca);
    //printf("busca = %d", busca);//teste para ver se o scanf funcionou

    //busca linear com o vetor desordenado
    x = buscaLinear(vetorDesord, 10, busca);
    if(x >= 0){
        printf("O elemento %d esta no indice %d.\n\n", busca, x);
    }else{
        printf("O elemento %d digitado não foi encontrado.\n\n", busca);
        }

        //BUSCA ORDENADA

    printf("\n\n\t\tBUSCA ORDENADA\n\n");
    printf(" Vetor ordenado\n");
    printf("     0   1   2   3   4   5   6   7   8   9 - indice correspondente\n\n");
    printf("    100|110|120|130|140|150|160|170|180|190|\n\n\n");

    printf("Que numero deseja buscar pela busca ordenada?  ");
    scanf(" %d", &busca);

    x = buscaOrdenada(vetorOrd, 10, busca);
    if(x >= 0){
        printf("O elemento %d esta no indice %d.\n\n", busca, x);
    }else{
        printf("O elemento %d digitado nao foi encontrado.\n\n", busca);
        }

    //BUSCA BINARIA
        printf("\n\n\t\tBUSCA BINARIA\n\n");
    printf(" Vetor ordenado\n");
    printf("     0   1   2   3   4   5   6   7   8   9 - indice correspondente\n\n");
    printf("    100|110|120|130|140|150|160|170|180|190|\n\n\n");

    printf("Que numero deseja buscar pela busca binaria?  ");
    scanf(" %d", &busca);

    x = buscaBinaria(vetorOrd, 10, busca);
    if(x >= 0){
        printf("O elemento %d esta no indice %d.\n\n", busca, x);
    }else{
        printf("O elemento %d digitado nao foi encontrado.\n\n", busca);
        }


}


int buscaLinear(int *vetor, int n, int elem){
    int i;
    for(i = 0; i < n; i++){
        if(elem == vetor[i])/*se o elemento de indice i for oq eu busco*/{
            return i;//retorno o indice dele no vetor que é onde ele esta localizado
        }
    }//caso eu rode o for ate o final(nao encontre o elem no vetor)
    return -1;//retornar -1 pois significa erro, ou o elemento nao esta no vetor/ nao existe
}

int buscaOrdenada(int *vetor, int n, int elem){
    int i; //para rodar o for
    for(i = 0; i < n; i++){
        if(elem == vetor[i]){/*o elemento que eu procuro é igual ao vetor no indice de i?*/
            return i;//se sim, retorne o indice/ sua posicao
        }else{
            if(elem < vetor[i]){/*o elem que eu busc é menor que o num do veto na pos i?*/
            //depois de comparar se o elemento na pos do i é o mesmo q busco, caso n seja
            // ele verifica se ele é menor, pois se for, ele n pode estar mais para frente,
            // pois o vetor esta ordenado.
            //caso o numero n seja igual mas seja maior, ele continua a rodar o for.
            return -1;//elemento n existe no vetor

            }
        }
    }
}

//dividir para conquistar
int buscaBinaria (int *vetor, int n, int elem){
    int inicio, meio, fim; //usadas para defifir a parte que sera analisada (tamanho)
    inicio = 0;//vai comecar no primeiro item do vetor
    fim = n-1;//final do vetor

    while(inicio <= fim){/*enquanto o intervalo ainda exixtir*/

        meio = (inicio + fim)/2;//se impar = parte menor ex: 9 :2 = 4 pois meio é int, so pega a parte inteira
        //vai redefinir o meio toda vez q o while rodar
        printf("inicio = %d \t meio = %d \t fim = %d \n",inicio, meio, fim);


        if(elem < vetor[meio]){//vendo se o numero buscado esta na primeira metade do vetor
            fim = meio - 1; //busca na metade esquerda. n pega o meio pois o if verifica se ele for menor q isso
            //ent, ou ele é exatamento um antes do meio ou outros menores
        }else{//o elem é maior ou igual ao meio
            if(elem > vetor[meio]){//busca na metade direita
                inicio = meio +1;//se elimina a primeira parte do vetor, ate o meio, que sabemos q ele é maior
            }else{//caso ele n seja nem maior nem menor ele é exatamente o meio
                return meio;
            }
        }
    }
    //caso ele n se enciaxe em nenhum dos ifs ele vai sair do while e retornar 1-
    return -1; //elemento n encontrado
}
