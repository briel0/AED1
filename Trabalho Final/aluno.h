#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define TAM_CATEGORIA 50

typedef struct Aluno{
   int id;
   char nome[TAM_NOME];
   float engajamento;
   float desempenho;
   char categoria[TAM_CATEGORIA];
} aluno;

aluno criar_aluno(int id, char* nome, float engajemento, float desempenho);

void mostrar_aluno(aluno atual);

#endif
