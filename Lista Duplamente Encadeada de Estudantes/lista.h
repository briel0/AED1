//////////////////////////////////
// Interface do TAD Lista       //
//////////////////////////////////

#include "estudante.h"


// Estrutura da lista
typedef struct lista Lista;

// Funcao para criar uma lista
Lista* criaLista();

// Funcao para destruir a lista
void destroiLista(Lista *l);

// Funcao para inserir um estudante na lista
void insere(Lista *l, Estudante *e);

// Funcao para remover um estudante da lista por nome
void retira(Lista *l, const char *nome);

// Funcao para imprimir a lista de estudantes
void imprime(Lista *l);
