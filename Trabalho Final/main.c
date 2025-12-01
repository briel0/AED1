#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avl.h"
#include "aluno.h"
#include "decision_tree.h"

void clear(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}


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
        aluno al = temp->al;
        printf("\nDados atuais:\n");
        mostrar_aluno(al);    

        printf("\nNovos dados:\n");
        printf("Nova nota (0-100): ");
        scanf("%f", &al.nota);

        printf("Novas aulas assistidas (0-100): ");
        scanf("%f", &al.aulas_assistidas);

        printf("Novas atividades concluídas (0-100): ");
        scanf("%f", &al.atividades_concluidas);

        classificar_aluno(decision, &al);

        printf("Dados atualizados! Nova categoria: %s\n", al.categoria);
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

void aguardar_enter() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

int main() {
    noAVL *avl = NULL;

    noDecisao* decision = criar_arvore_decisao();

    int opcao;

    printf("=== SISTEMA DE CLASSIFICAÇÃO DE ALUNOS ===\n");
    printf("Integração: Árvore AVL + Árvore de Decisão\n");

    do {
        printf("\n=== PLATAFORMA DE CURSOS ONLINE ===\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Buscar aluno\n");
        printf("3. Atualizar dados do aluno\n");
        printf("4. Listar todos os alunos\n");
        printf("5. Estatísticas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                printf("\n--- CADASTRO DE ALUNO ---\n");
                cadastrar_aluno(&avl, decision);
                aguardar_enter();
                break;
            case 2:
                buscar_aluno(avl);
                aguardar_enter();
                break;
            case 3:
                atualizar_aluno(avl, decision);
                aguardar_enter();
                break;
            case 4:
                printf("\n--- LISTA DE ALUNOS ---\n");
                exibir_avl_em_ordem(avl);
                aguardar_enter();
                break;
            case 5:
                contar_categorias(avl);
                aguardar_enter();
                break;
            case 0:
                printf("Encerrando sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
                aguardar_enter();
        }
        clear();
    } while(opcao != 0);

    liberar_avl(avl);
    liberar_arvore_decisao(decision);

    return 0;
}
