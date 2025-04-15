#include "hashTable.h"
#include <ctype.h>

struct hash {
    int qtd;
    int TABLE_SIZE;
    Aluno** itens;
};

Hash* criaHash(int TABLE_SIZE) {
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if (ha != NULL) {
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (Aluno**) malloc((size_t)TABLE_SIZE * sizeof(Aluno*));

        if (ha->itens == NULL) {
            free(ha);
            return NULL;
        }

        ha->qtd = 0;
        for (int i = 0; i < ha->TABLE_SIZE; i++) {
            ha->itens[i] = NULL;
        }
    }
    return ha;
}

void liberaHash(Hash* ha) {
    if (ha != NULL) {
        for (int i = 0; i < ha->TABLE_SIZE; i++) {
            if (ha->itens[i] != NULL) {
                free(ha->itens[i]);
            }
        }
        free(ha->itens);
        free(ha);
    }
}

int chaveDivisao(int chave, int TABLE_SIZE) {
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_semTraColisao(Hash* ha, Aluno al) {
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE) {
        return 0;
    }

    int pos = chaveDivisao(al.matricula, ha->TABLE_SIZE);

    if (ha->itens[pos] != NULL) {
        return 0;
    }

    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo == NULL) {
        return 0;
    }

    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

int buscaHash_semTratColisao(Hash* ha, int mat, Aluno* al) {
    if (ha == NULL) {
        return 0;
    }

    int pos = chaveDivisao(mat, ha->TABLE_SIZE);

    if (ha->itens[pos] == NULL) {
        return 0;
    }

    *al = *(ha->itens[pos]);
    return 1;
}

int sondagemLinear(int pos, int i, int TABLE_SIZE) {
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_TratColisao(Hash* ha, Aluno al) {
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE) {
        return 0;
    }

    int pos = chaveDivisao(al.matricula, ha->TABLE_SIZE);

    for (int i = 0; i < ha->TABLE_SIZE; i++) {
        int newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);

        if (ha->itens[newPos] == NULL) {
            Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
            if (novo == NULL) {
                return 0;
            }

            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}

int buscaHash_TratColisao(Hash* ha, int mat, Aluno* al) {
    if (ha == NULL) {
        return 0;
    }

    int pos = chaveDivisao(mat, ha->TABLE_SIZE);

    for (int i = 0; i < ha->TABLE_SIZE; i++) {
        int newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);

        if (ha->itens[newPos] == NULL) {
            return 0;
        }

        if (ha->itens[newPos]->matricula == mat) {
            *al = *(ha->itens[newPos]);
            return 1;
        }
    }
    return 0;
}

void imprimeAluno(Aluno* al) {
    if (al == NULL) {
        printf("Aluno nao encontrado.\n");
        return;
    }

    printf("Matricula: %d\n", al->matricula);
    printf("Nome: %s\n", al->nome);
    printf("Notas: %.2f, %.2f, %.2f\n", al->n1, al->n2, al->n3);
    printf("----------------------\n");
}


void menuOperacoes(Hash* ha, int comColisao) {
    int opcao;
    int continuar;

    do {
        printf("\n----- MENU DE OPERACOES -----\n");
        printf("[1] Inserir aluno\n");
        printf("[2] Buscar aluno\n");
        printf("[3] Exibir tabela hash\n");
        printf("[0] Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Aluno a;
                printf("\n--- Insercao de Aluno ---\n");
                printf("Matricula: ");
                scanf("%d", &a.matricula);
                limpaBuffer();

                printf("Nome: ");
                fgets(a.nome, STRING_SIZE, stdin);
                a.nome[strcspn(a.nome, "\n")] = '\0';

                printf("Notas (n1 n2 n3): ");
                scanf("%f %f %f", &a.n1, &a.n2, &a.n3);

                int resultado;
                if (comColisao) {
                    resultado = insereHash_TratColisao(ha, a);
                } else {
                    resultado = insereHash_semTraColisao(ha, a);
                }

                if (resultado) {
                    printf("\nAluno inserido com sucesso!\n");
                } else {
                    printf("\nErro ao inserir aluno. Tabela pode estar cheia.\n");
                }
                break;
            }

            case 2: {
                int matricula;
                printf("\n--- Busca de Aluno ---\n");
                printf("Matricula: ");
                scanf("%d", &matricula);

                Aluno encontrado;
                int resultado;
                if (comColisao) {
                    resultado = buscaHash_TratColisao(ha, matricula, &encontrado);
                } else {
                    resultado = buscaHash_semTratColisao(ha, matricula, &encontrado);
                }

                if (resultado) {
                    printf("\nAluno encontrado:\n");
                    imprimeAluno(&encontrado);
                } else {
                    printf("\nAluno nao encontrado.\n");
                }
                break;
            }

            case 3: {
                printf("\n--- Exibindo Tabela Hash ---\n");
                exibeTabelaHash(ha);
                break;
            }

            case 0:
                printf("\nRetornando ao menu principal...\n");
                break;

            default:
                printf("\nopcao invalida!\n");
        }

        if (opcao != 0) {
            printf("\nDeseja realizar outra operacao? [1] Sim [2] Nao: ");
            scanf("%d", &continuar);

            if (continuar != 1){
                opcao = 0;
                printf("\nRetornando ao menu principal...\n");
            }
        }
    } while (opcao != 0);
}

void limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibeTabelaHash(Hash* ha) {
    if (ha == NULL) {
        printf("Tabela hash nao existe.\n");
        return;
    }

    printf("\n----- TABELA HASH -----\n");
    for (int i = 0; i < ha->TABLE_SIZE; i++) {
        if (ha->itens[i] != NULL) {
            printf("Posicao %d:\n", i);
            imprimeAluno(ha->itens[i]);
            printf("\n"); 
        } else {
            printf("Posicao %d: Vazia\n\n", i);
        }
    }
}