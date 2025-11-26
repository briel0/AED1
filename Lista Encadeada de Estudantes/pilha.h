typedef struct pilha Pilha;
Pilha* criar_pilha();          // Cria pilha vazia
int pilha_vazia(Pilha *p);     // Retorna 1 se vazia
void push(Pilha *p, int valor);// Empilha novo valor
int pop(Pilha *p);             // Desempilha e retorna
int topo(Pilha *p);            // Consulta topo
void liberar_pilha(Pilha *p);  // Libera memória
