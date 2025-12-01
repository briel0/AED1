#include "actions.h"

void cadastrar_aluno(noAVL** avl, noDecisao* no){
    aluno novo = criar_aluno();
    classificar_aluno(no, &novo);

    *avl = inserir_avl(*avl, novo);

    printf("\nAluno cadastrado com sucesso!\n");
    printf("Categoria atribuída: %s\n", novo.categoria);
}

void buscar_aluno(noAVL *avl) {
    int matricula;
    printf("\n--- BUSCAR ALUNO ---\n");
    printf("Matrícula: ");
    scanf("%d", &matricula);

    noAVL* temp = buscar_avl(avl, matricula);
    if(temp != NULL){
        aluno al = temp->al;
        mostrar_aluno(al);    
    }
    else {
        printf("Aluno não encontrado!\n");
    }
}

void atualizar_aluno(noAVL* avl, noDecisao* decision){
    int matricula;
    printf("\n--- ATUALIZAR ALUNO ---\n");
    printf("Matrícula: ");
    scanf("%d", &matricula);

    noAVL* temp = buscar_avl(avl, matricula);
    if(temp != NULL){
        aluno* al = &temp->al;
        printf("\nDados atuais:\n");
        mostrar_aluno(*al);    

        printf("\nNovos dados:\n");
        printf("Nova nota (0-100): ");
        scanf("%f", &al->nota);

        printf("Novas aulas assistidas (0-100): ");
        scanf("%f", &al->aulas_assistidas);

        printf("Novas atividades concluídas (0-100): ");
        scanf("%f", &al->atividades_concluidas);

        classificar_aluno(decision, al);

        printf("Dados atualizados! Nova categoria: %s\n", al->categoria);
    }
    else {
        printf("Aluno não encontrado!\n");
    }
}

void contar_categorias(noAVL* avl){
    char* tipos[] = {"Desinteressado", "Com Dificuldade", "Autodidata", "Prático", "Teórico", "Exemplar"};
    int counts[6] = {};
    
    contar_avl(avl, tipos, counts, 6);

    for(int i = 0; i < 6; i++){
        printf("Há %d alunos da categoria %s\n", counts[i], tipos[i]);
    }

}