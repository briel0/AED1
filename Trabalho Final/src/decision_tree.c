#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decision_tree.h"

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

    if(no == NULL){
        printf("A alocação de memória falhou!\n");
        return NULL;
    }

    strcpy(no->atributo, "");
    no->limiar = 0;
    no->esq = NULL;
    no->dir = NULL;
    strcpy(no->resultado, resultado);
    no->folha = 1;
    return no;
}

noDecisao* criar_arvore_decisao(){
    // Raiz: primeiro critério → NOTA
    noDecisao* raiz = criar_no_decisao("nota", 70.0);

    // ----------- RAMO ESQUERDO (nota < 70) -----------
    raiz->esq = criar_no_decisao("aulas", 70.0);

    // aulas < 70 → verificar atividades
    raiz->esq->esq = criar_no_decisao("atividades", 70.0);
    raiz->esq->esq->esq = criar_no_folha("Desinteressado");  // aulas < 70 && atividades < 70
    raiz->esq->esq->dir = criar_no_folha("Com Dificuldade"); // aulas < 70 && atividades >= 70

    // aulas >= 70 → também Com Dificuldade (pela lógica do if)
    raiz->esq->dir = criar_no_folha("Com Dificuldade");

    // ----------- RAMO DIREITO (nota >= 70) -----------
    raiz->dir = criar_no_decisao("aulas", 70.0);

    // aulas < 70 → verificar atividades
    raiz->dir->esq = criar_no_decisao("atividades", 70.0);
    raiz->dir->esq->esq = criar_no_folha("Autodidata"); // atu < 70
    raiz->dir->esq->dir = criar_no_folha("Prático");    // atu >= 70

    // aulas >= 70 → verificar atividades
    raiz->dir->dir = criar_no_decisao("atividades", 70.0);
    raiz->dir->dir->esq = criar_no_folha("Teórico");
    raiz->dir->dir->dir = criar_no_folha("Exemplar");

    return raiz;
}


void classificar_aluno(noDecisao* no, aluno* a){
    if(no->folha){
        strcpy(a->categoria, no->resultado);
        return;
    }

    float valor_comp = 0;
    
    if(strcmp(no->atributo, "nota") == 0){
        valor_comp = a->nota;
    }
    else if(strcmp(no->atributo, "aulas") == 0){
        valor_comp = a->aulas_assistidas;
    }
    else if(strcmp(no->atributo, "atividades") == 0){
        valor_comp = a->atividades_concluidas;
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
