#include <stdio.h>
#include <string.h>
#include "aluno.h"

aluno criar_aluno(int id, char* nome, float engajamento, float desempenho){
   aluno a;
   a.id = id;
   strcpy(a.nome, nome);
   a.engajamento = engajamento;
   a.desempenho = desempenho;
   strcpy(a.categoria, "Indefinido");
   return a;
}

void mostrar_aluno(aluno atual){
    printf("id-> %d\n", atual.id);
    printf("nome-> %s\n", atual.nome);
    printf("engajamento %f\n", atual.engajamento);
    printf("desempenho %f\n", atual.desempenho);
}
