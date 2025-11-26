#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decisao.h"

noDecisao* criar_no_decisao(char* atributo, float limiar){
    noDecisao* no = malloc(sizeof(noDecisao));
    strcpy(no->atributo, atributo);
    no->limiar = limiar;
    no->esq = NULL;
    no->dir = NULL;
    strcpy(no->resultado, "");
    no->folha = 0;
    return no;
}

noDecisao* criar_no_folha(char* resultado){
    noDecisao* no = malloc(sizeof(noDecisao));
    strcpy(no->atributo, "");
    no->limiar = 0;
    no->esq = NULL;
    no->dir = NULL;
    strcpy(no->resultado, resultado);
    no->folha = 1;
    return no;
}

noDecisao* criar_arvore_decisao(){
    noDecisao* raiz = criar_no_decisao("engajamento", 50.0);

    raiz->esq = criar_no_decisao("desempenho", 50.0);
    raiz->esq->esq = criar_no_folha("Risco de Evasão"); //Engaj < 50 && Desemp < 50
    raiz->esq->dir = criar_no_folha("Aluno Passivo"); //Engaj < 50 && Desemp >= 50

    raiz->dir = criar_no_decisao("desempenho", 60.0);
    raiz->dir->esq = criar_no_folha("Precisa de Reforço"); //Engaj >= 50 && Desemp < 60
    raiz->dir->dir = criar_no_folha("Aluno Destaque"); //Engaj >= 50 && Desemp >= 60

    return raiz;
}

void classificar_aluno(noDecisao* no, aluno* a){
    if(no->folha){
        strcpy(a->categoria, no->resultado);
        return;
    }

    float valor_comp = 0;
    
    if(strcmp(no->atributo, "engajamento") == 0){
        valor_comp = a->engajamento;
    }
    else if(strcmp(no->atributo, "desempenho") == 0){
        valor_comp = a->desempenho;
    }
    
    if(valor_comp < no->limiar){
        classificar_aluno(no->esq, a);
    }
    else{
        classificar_aluno(no->dir, a);
    }
}

void liberar_arvore_decisao(noDecisao* no){
    if(no == NULL){
        return;
    }
    liberar_arvore_decisao(no->esq);
    liberar_arvore_decisao(no->dir);
    free(no);
}
