#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define TAM_CATEGORIA 50

typedef struct{
   int matricula;
   char nome[TAM_NOME];
   float nota;
   float aulas_assistidas;
   float atividades_concluidas;
   char categoria[TAM_CATEGORIA];
} aluno;

aluno criar_aluno();

void mostrar_aluno(aluno atual);

#endif
