#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Funcao principal para testes
int main() {
    Lista *lista = criaLista();

    insere(lista, criaEstudante("Alice", 20, 8.5));
    insere(lista, criaEstudante("Bob", 22, 7.8));
    insere(lista, criaEstudante("Carlos", 19, 9.2));
    imprime(lista);

    retira(lista, "Bob");
    imprime(lista);

    retira(lista, "Alice");
    imprime(lista);

    retira(lista, "Carlos");
    imprime(lista);

    retira(lista, "Daniel");
    imprime(lista);

    destroiLista(lista);

    return 0;
}
