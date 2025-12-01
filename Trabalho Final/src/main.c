#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avl.h"
#include "aluno.h"
#include "decision_tree.h"
#include "actions.h"

void clear(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
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