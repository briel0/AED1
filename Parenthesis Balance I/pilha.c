#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct pilha {
    int elemento;
    struct pilha* anterior;
} Pilha;

Pilha* criar_pilha(){
    return NULL;
}   

int pilha_vazia(Pilha* p){
    return p == NULL;
}    

Pilha* push(Pilha* p, int valor){
    Pilha* novo = (Pilha*) malloc(sizeof(Pilha));

    if(novo == NULL){
        return p;
    }

    novo->elemento = valor;
    novo->anterior = p;

    return novo;

}

Pilha* pop(Pilha* p){
    if(pilha_vazia(p)){
        return NULL;
    }
    Pilha* anterior = p->anterior;
    free(p);
    return anterior;
}

int topo(Pilha* p){
    return p->elemento;
}

void liberar_pilha(Pilha* p){
    while(!pilha_vazia(p)){
        p = pop(p);
    }
}

