#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

int altura(noAVL* no){
    if(no == NULL){
        return 0;
    }
    return no->altura;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

noAVL* novo_no_avl(aluno atual){
    noAVL* no = malloc(sizeof(noAVL));
    if(no == NULL){
        printf("Erro na alocação de memória!\n");
        return NULL;
    }
    no->al = atual;
    no->esq = NULL;
    no->dir = NULL;
    no->altura = 1;
    return no;
}

noAVL *rotacao_direita(noAVL *y) {
    noAVL *x = y->esq;
    noAVL *T2 = x->dir;
    x->dir = y;
    y->esq = T2;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    return x;
}

noAVL *rotacao_esquerda(noAVL *x) {
    noAVL *y = x->dir;
    noAVL *T2 = y->esq;
    y->esq = x;
    x->dir = T2;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    return y;
}

int obter_balanceamento(noAVL *no){
    if(no == NULL){
        return 0;
    }
    return altura(no->esq) - altura(no->dir);
}

noAVL* inserir_avl(noAVL* no, aluno aluno) {
    if (no == NULL) {
        return novo_no_avl(aluno);
    }

    if (aluno.matricula < no->al.matricula)
        no->esq = inserir_avl(no->esq, aluno);
    else if (aluno.matricula > no->al.matricula)
        no->dir = inserir_avl(no->dir, aluno);
    else {
        no->al = aluno;
        return no;
    }

    no->altura = 1 + max(altura(no->esq), altura(no->dir));

    int balance = obter_balanceamento(no);

    if (balance > 1 && aluno.matricula < no->esq->al.matricula)
        return rotacao_direita(no);

    if (balance < -1 && aluno.matricula > no->dir->al.matricula)
        return rotacao_esquerda(no);

    if (balance > 1 && aluno.matricula > no->esq->al.matricula) {
        no->esq = rotacao_esquerda(no->esq);
        return rotacao_direita(no);
    }

    if (balance < -1 && aluno.matricula < no->dir->al.matricula) {
        no->dir = rotacao_direita(no->dir);
        return rotacao_esquerda(no);
    }

    return no;
}

noAVL* buscar_avl(noAVL* raiz, int id){
    if(raiz == NULL){
        return NULL;
    }
    if(id == raiz->al.matricula){
        return raiz;
    }
    else if(id < raiz->al.matricula){
        return buscar_avl(raiz->esq, id);
    }
    else{
        return buscar_avl(raiz->dir, id);
    }
}

void contar_avl(noAVL* raiz, char* tipos[], int counts[], int qtde_tipos){
    if(raiz == NULL){
        return;
    }

    contar_avl(raiz->esq, tipos, counts, qtde_tipos);

    for(int i = 0; i < qtde_tipos; i++){
        if(strcmp(raiz->al.categoria, tipos[i]) == 0){
            counts[i]++;
            break;
        }
    }
    contar_avl(raiz->dir, tipos, counts, qtde_tipos);
}

void exibir_avl_em_ordem(noAVL *raiz) {
    if (raiz != NULL) {
        exibir_avl_em_ordem(raiz->esq);
        mostrar_aluno(raiz->al);
        exibir_avl_em_ordem(raiz->dir);
    }
}

void liberar_avl(noAVL *raiz) {
    if (raiz != NULL) {
        liberar_avl(raiz->esq);
        liberar_avl(raiz->dir);
        free(raiz);
    }
}