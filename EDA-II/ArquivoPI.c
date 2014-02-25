#include<stdio.h>
#include<string.h>


typedef struct{
    char nome_produto[20];
}tp_produto;



typedef struct{
    tp_no *topo;
}tp_pilha;

typedef struct tp_no{
    tp_produto produto;
    struct tp_no *ant;
    struct tp_no *prox;
}tp_no;



void le_produto(char produto[20]){
    printf("Entre com um produto: ");
    scanf("%s",produto);
}

int vazia(tp_pilha *pilha){

    if(pilha->topo == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

tp_no* criano(){

   tp_no *no;

   no = (tp_no*) malloc(sizeof(tp_no));

   if(no == NULL){
       printf("Erro: Criacao do no\n");
       return NULL;
   }
   else{
       return no;
   }
}

void inserir(tp_pilha *pilha, tp_produto produto){

    if(vazia(pilha)){
        pilha->topo = criano();
        pilha->topo->produto = produto;
        pilha->topo->ant = NULL;
        pilha->topo->prox = NULL;
    }
    else{
        pilha->topo->prox = criano();
        pilha->topo->prox->ant = pilha->topo;
        pilha->topo = pilha->topo->prox;
        pilha->topo->produto = produto;
        pilha->topo->prox = NULL;
    }
}

void excluir(tp_pilha *pilha){

    if(!vazia(pilha)){
       if(pilha->topo->ant == NULL){
           free(pilha->topo);
           pilha->topo = NULL;
       }
       else{
           pilha->topo = pilha->topo->ant;
           free(pilha->topo->prox);
           pilha->topo->prox = NULL;
       }
    }
    else{
        printf("Erro: Pilha vazia\n");
    }
}

void listar(tp_pilha *pilha, tp_no *pos){

    if(vazia(pilha)){
      printf("Erro: Pilha vazia\n");
      return;
    }
    else{
        while(pos != NULL){
            puts(pos->produto.nome_produto);
            pos = pos->ant;
        }
    }
}


int main(){

    tp_pilha pilha = {NULL};
    tp_produto produto;
    char op;
    int qtd_produtos , i;

	do {
        printf("\n 1 - inserir produto\n");
        printf(" 2 - listar produtos da pilha\n");
        printf(" 3 - excluir produto da pilha\n");
        printf(" 0 - sair\n\n");
        fflush(stdin); scanf("%c", &op);
        switch (op) {
        case '1':
            le_produto(produto.nome_produto);
            inserir(&pilha, produto);
            break;
        case '2':
            listar(&pilha, pilha.topo);
            break;
        case '3':
            excluir(&pilha);
            break;
        case '0':
            printf("Fim do programa");
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (op != '0');
}

