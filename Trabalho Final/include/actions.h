#ifndef ACTIONS_H
#define ACTIONS_H

#include "aluno.h"
#include "decision_tree.h"
#include "avl.h"

void cadastrar_aluno(noAVL** avl, noDecisao* no);
void buscar_aluno(noAVL* avl);
void atualizar_aluno(noAVL* avl, noDecisao* decision);
void contar_categorias(noAVL* avl);

#endif



