#ifndef DECISAO_H
#define DECISAO_H

#include "aluno.h"

#define TAM_ATRIBUTO 20
#define TAM_RESULTADO 50

typedef struct NoDecisao{
    char atributo[TAM_ATRIBUTO];
    float limiar;
    struct NoDecisao* esq;
    struct NoDecisao* dir;
    char resultado[TAM_RESULTADO];
    int folha;
} noDecisao;

noDecisao* criar_arvore_decisao();

void classificar_aluno(noDecisao* raiz, aluno* a);

void liberar_arvore_decisao(noDecisao* no);

#endif
