#ifndef AVL_H
#define AVL_H

#include "aluno.h"

typedef struct NoAVL{
    aluno al;
    struct NoAVL *esq;
    struct NoAVL *dir;
    int altura;
} noAVL;

noAVL* inserir_avl(noAVL* raiz, aluno atual);
noAVL* buscar_avl(noAVL* raiz, int id);
void exibir_avl_em_ordem(noAVL* raiz);
void liberar_avl(noAVL* raiz);
int altura(noAVL* no);
void contar_avl(noAVL* raiz, char* tipos[], int counts[], int qtde_tipos);

#endif
