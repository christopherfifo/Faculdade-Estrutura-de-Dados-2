#ifndef HASHTABLE_H
#define HASHTABLE_H

struct aluno {
    int matricula;
    char nome[31];
    float n1, n2, n3;
};

typedef struct hash Hash;

Hash* criaHash(int tamanho);
void liberaHash(Hash* ha);
int valorString(char* str);
int insereHash_semColisao(Hash* ha, struct aluno al);
int buscaHash_semColisao(Hash* ha, int mat, struct aluno* al);
int insereHash_enderecoAberto(Hash* ha, struct aluno al);
int buscaHash_enderecoAberto(Hash* ha, int mat, struct aluno* al);
void menuOperacoes(Hash* ha, int comTratamentoColisao);
void exibeTabelaHash(Hash* ha);
void imprimeAluno(struct aluno* al);
void limpaHash(Hash* ha);

#endif
