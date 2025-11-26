//////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementacao do TAD Lista simplesmente encadeada para armazenar dados do TAD Estudante    //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estudante.h"
#include "lista.h"

struct lista{
    Estudante* aluno;
    struct lista* prox;
};

Lista* criaLista(){
    return NULL;
}

// Insere um estudante no início da lista
Lista* insere(Lista* l, Estudante* e){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (!novo) return l;  // Retorna a lista original se falhar
    
    novo->aluno = e;
    novo->prox = l;
    return novo;  // Retorna o novo primeiro nó
}

// Remove um estudante pelo nome
Lista* retira(Lista *l, const char *nome) {
    if (!l) {
      printf("Lista vazia\n");
      return NULL;
    }

    Lista *atual = l, *anterior = NULL;

    while (atual) {
        if (strcmp(getNome(atual->aluno), nome) == 0) {
            if (!anterior) {
                Lista *novo_inicio = atual->prox; // Atualiza o primeiro nó
                destroiEstudante(atual->aluno);
                free(atual);
                return novo_inicio;
            } else {
                anterior->prox = atual->prox;
                destroiEstudante(atual->aluno);
                free(atual);
                return l; // Retorna o início original
            }
        }
        anterior = atual;
        atual = atual->prox;
    }
    return l; // Retorna o início original se não encontrar o nome
}


// Destroi a lista, liberando memória
void destroiLista(Lista *l) {
    Lista *atual = l;
    while (atual) {
        Lista *temp = atual;
        atual = atual->prox;
        destroiEstudante(temp->aluno);
        free(temp);
    }
}

//---------------------Novas funções----------------

// Imprime a lista de estudantes
void imprime(Lista* l) {

    if(l == NULL){
        return;
    }

    imprime(l->prox);

    imprimeEstudante(l->aluno);

}

// Implementar função de busca um estudante pelo nome, retorna o ponteiro para o nó, se encontrado e, NULL, caso contrário
Lista* busca(Lista *l, char* nome){
    
    Lista* atual = l;

    while(atual != NULL){
        if(strcmp(getNome(atual->aluno), nome) == 0){
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

// Implementar função de retorna o comprimento da lista
int tamanho(Lista *l){
    int tam = 0;
    Lista* atual = l;
    while(atual != NULL){
        tam++;
        atual = atual->prox;
    }
    return tam;
}

