#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Funcao principal para testes
int main() {
    Lista *lista = criaLista();

    lista = insere(lista, criaEstudante("Alice", 20, 8.5));
    lista = insere(lista, criaEstudante("Bob", 22, 7.8));
    lista = insere(lista, criaEstudante("Carlos", 19, 9.2));
    imprime(lista);
    
    if (busca(lista, "Bob") != NULL)
        printf("Nome existe na lista\n");
    else printf("Nome não existe na lista\n");


    lista = retira(lista, "Bob");
    imprime(lista);
    
    if (busca(lista, "Bob") != NULL)
        printf("Nome existe na lista\n");
    else printf("Nome não existe na lista\n");

    printf("Há %d elemento(s) na lista\n", tamanho(lista));
    lista = retira(lista, "Alice");
    imprime(lista);

    lista = retira(lista, "Carlos");
    imprime(lista);

    lista = retira(lista, "Daniel");
    imprime(lista);

    destroiLista(lista);

    return 0;
