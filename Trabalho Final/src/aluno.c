#include <stdio.h>
#include <string.h>
#include "aluno.h"

aluno criar_aluno(){
    aluno novo;

    printf("Matrícula: ");
    scanf("%d", &novo.matricula);
    getchar();

    printf("Nome: ");
    fgets(novo.nome, TAM_NOME, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0;

    printf("Nota média das provas (0-100): ");
    scanf("%f", &novo.nota);

    printf("Aulas assistidas (Porcentagem): ");
    scanf("%f", &novo.aulas_assistidas);

    printf("Atividades concluídas (Porcentagem): ");
    scanf("%f", &novo.atividades_concluidas);

    return novo;
}

void mostrar_aluno(aluno atual){
    printf("Matrícula-> %d\n", atual.matricula);
    printf("Nome-> %s\n", atual.nome);
    printf("Média das provas-> %f\n", atual.nota);
    printf("Aulas assistidas-> %f\n", atual.aulas_assistidas);
    printf("Atividades concluídas-> %f\n", atual.atividades_concluidas);
    printf("Categoria-> %s\n", atual.categoria);
    printf("\n");
}
