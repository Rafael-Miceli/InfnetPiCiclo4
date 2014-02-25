#include<stdio.h>
#include<string.h>


typedef struct{
    char nome_produto[20];
}tp_produto;

typedef struct{
    char nome_cliente[20];
    char email[20];
}tp_cliente;

//Pilha

typedef struct{
    int topo;
    tp_produto vetor_produtos[5];
}tp_pilha;

//Filas

typedef struct tp_no{
    tp_produto produto;
    struct tp_no *ant;
    struct tp_no *prox;
}tp_no;



void le_produto(char produto[20]){
    printf("Entre com um produto: ");
    scanf("%s",produto);
}


int pilha_esta_vazia(tp_pilha *pilha){

    //5 é o limite de produtos
	if (pilha->topo == 5)
		return 1;
	else
        return 0;
}

int pilha_esta_cheia(tp_pilha *pilha){
	if (pilha->topo == 5)
		return 1;
	else
        return 0;
}

/*
int vazia(tp_pilha *pilha){

    if(pilha->topo == NULL){
        return 1;
    }
    else{
        return 0;
    }
}*/

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

void push(tp_pilha *pilha, tp_produto produto){

    if (!pilha_esta_cheia(pilha)) {
		pilha->vetor_produtos[pilha->topo++] = produto;
		return 1;
	}
	else {
		printf("Erro: pilha cheia\n");
		return 0;
	}
}

void pop(tp_pilha *pilha){

    if (!pilha_esta_vazia(pilha)){
		return pilha->vetor_produtos[--pilha->topo];
	}
	else{
		printf("Erro: pilha vazia\n");
		return 0;
	}
}

void listar_pilha(tp_pilha *pilha, tp_no *pos){

    int i;
	if (!pilha_esta_vazia(pilha))
		for (i = pilha->topo-1; i >= 0; i--)
			printf ("%d\n",pilha->vetor_produtos[i]);
	else
        printf ("Pilha vazia\n");
}

void criar_produtos(tp_pilha *pilha){

    int i;

    tp_produto produto;

    for(i = 0; i < 5; i++){
       le_produto(produto.nome_produto);
       push(&pilha, produto);
    }
}


int main(){

    tp_pilha pilha = {NULL};
    tp_produto produto;
    char op;


    criar_produtos(&pilha);
	do {
        printf(" 1 - listar produtos da pilha\n");
        printf(" 2 - excluir produto da pilha\n");
        printf(" 0 - sair\n\n");
        fflush(stdin); scanf("%c", &op);
        switch (op) {
        case '1':
            listar_pilha(&pilha, pilha.topo);
            break;
        case '2':
            pop(&pilha);
            break;
        case '0':
            printf("Fim do programa");
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (op != '0');
}

