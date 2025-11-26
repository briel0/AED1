#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
 
/*Protótipo da função */
int parenthesis_balance (char* s){
    
    int tam = strlen(s);

    Pilha* stack = criar_pilha();

    for(int i = 0; i < tam - 1; i++){
        if(s[i] == '('){
            stack = push(stack, 1);
        }
        else if(s[i] == ')'){
            if(pilha_vazia(stack)){
                return 0;
            }
            stack = pop(stack);
        }
    }
    return pilha_vazia(stack);
}  

int main() {

    char* exp = NULL;
    size_t tam = 0;

    ssize_t lidos = getline(&exp, &tam, stdin);

    if(parenthesis_balance(exp)){
        printf("correct\n");
    }
    else{
        printf("incorrect\n");
    }

    return 0;
}
