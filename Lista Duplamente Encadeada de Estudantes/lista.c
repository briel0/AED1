//////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementacao do TAD Lista circular duplamente encadeada para armazenar dados do TAD Estudante    //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estudante.h"
#include "lista.h"

struct lista {
    Estudante *aluno;
    struct no *prox;
    struct no *ant;
};

Lista* criaLista(){
    return NULL;
}

void destroiLista(Lista* l){
    for(Lista* i = l; i != NULL;){
        Lista* temp = i->ant;
        free(i);
        i = temp;
    }
}

void insere(Lista* l, Estudante* e){
    Lista* novo = malloc(sizeof(Lista));
    novo->aluno = e;
    novo->ant = l;
    novo->prox = NULL;
    l->prox = novo;
    l = novo;
}

void retira(Lista* l, const char nome){

}

void imprime(Lista* l){

}
