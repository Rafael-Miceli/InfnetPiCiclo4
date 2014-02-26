#include<stdio.h>
#include<string.h>


//Pilha de produtos bbllaa

typedef struct{
    char *nome_produto;
}tp_produto;

typedef struct{
    int topo;
    tp_produto vetor_produtos[5];
}tp_pilha;

//___________________________________
//Fila de clientes

typedef struct{
    char *nome_cliente;
    char *email;
}tp_cliente;

typedef struct tp_nofila{
    tp_cliente cliente;
    struct tp_no *ant;
    struct tp_no *prox;
}tp_nofila;

typedef struct {
	tp_no *inicio;
	tp_no *fim;
} tp_fila;

//___________________________________
//lista dos clientes sorteados

typedef struct tp_nolista{
    tp_produto produto;
    tp_cliente cliente;
	struct tp_no *ant;
	struct tp_no *prox;
} tp_nolista;

typedef struct {
	tp_no *inicio;
	tp_no *fim;
} tp_lista;




//___________________________________

/** Pilha de Produtos**/

void le_produto(char produto[20]){
    printf("Entre com um produto: ");
    scanf("%s",produto);
}


int pilha_esta_vazia(tp_pilha *pilha){

    //5 é o limite de produtos
	if (pilha->topo == 0)
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

void listar_pilha(tp_pilha *pilha){

    int i;
	if (!pilha_esta_vazia(pilha))
		for (i = pilha->topo-1; i >= 0; i--)
			printf ("%d\n",pilha->vetor_produtos[i]);
	else
        printf ("Pilha vazia\n");
}

void cadastrar_produtos(tp_pilha *pilha){

    tp_produto produto;


    produto.nome_produto = "computador";
    push(pilha, produto);

    produto.nome_produto = "Televisao";
    push(pilha, produto);

    produto.nome_produto = "Radio";
    push(pilha, produto);

    produto.nome_produto = "Xbox One";
    push(pilha, produto);

    produto.nome_produto = "Sofa";
    push(pilha, produto);

}


//___________________________________
//___________________________________


/** Fila de Clientes **/

/*
int vazia(tp_fila *fila){

    if(fila->inicio == NULL){
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



int main(){

    tp_pilha pilha;
    char op;

    pilha.topo = 0;

    cadastrar_produtos(&pilha);

	do {
        printf(" 1 - listar produtos da pilha\n");
        printf(" 2 - excluir produto da pilha\n");
        printf(" 0 - sair\n\n");
        fflush(stdin); scanf("%c", &op);
        switch (op) {
        case '1':
            listar_pilha(&pilha);
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

