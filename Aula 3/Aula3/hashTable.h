#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 31

typedef struct aluno {
    int matricula;
    char nome[STRING_SIZE];
    float n1, n2, n3;
} Aluno;

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);

int insereHash_semTraColisao(Hash* ha, Aluno al);
int buscaHash_semTratColisao(Hash* ha, int mat, Aluno* al);

int insereHash_TratColisao(Hash* ha, Aluno al);
int buscaHash_TratColisao(Hash* ha, int mat, Aluno* al);

void imprimeAluno(Aluno* al);

void menuOperacoes(Hash* ha, int comColisao);
void limpaBuffer();

void exibeTabelaHash(Hash* ha);

#endif
