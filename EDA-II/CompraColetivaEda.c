#include <stdio.h>
#include <string.h>

#define MaxProdutos 5

typedef struct{
    char *Nome;
} Produto;

typedef struct {
	int topo;
	Produto produtos[MaxProdutos];
} PilhaProdutos;

typedef struct{
    char *Nome;
    char *Email;
} Cliente;

struct FilaDeClientes
{
    Cliente cliente;
    struct FilaDeClientes *referencia_no;
} *primeiro_no=NULL, *ultimo_no=NULL;


//Menus

void ImprimirMenuPrincipal();
void ImprimirMenuPromocoesProdutos();
void ImprimirMenuClientes();


// Métodos Pilha de Produtos

int PilhaProdutosVazia(PilhaProdutos *pilhaProdutos);
int PilhaProdutosCheia(PilhaProdutos *pilhaProdutos);
int PushProduto(PilhaProdutos *pilhaProdutos, char *produto);
void PopProduto(PilhaProdutos *pilhaProdutos);
void ListarProdutos(PilhaProdutos *pilhaProdutos);
void EmpilharProdutosModoPreguica();


//Entregar Promocoes a Clientes
void EntregarPromocoesAClientes();

main(){

    printf("Bem vindo ao programa de PI de EDA\n\n");

    ImprimirMenuPrincipal();
}

//======================================================================================================
//Menus

void ImprimirMenuPrincipal(){
    int opcao = 9;

    do{
        printf("\n==============  Menu Principal  ===============\n");
        printf("Escolha uma das opcoes abaixo\n");

        printf("1 - Tela de Promocoes Produtos\n");
        printf("2 - Tela de Clientes\n");
        printf("3 - Entregar promocoes de produtos a clientes\n");
        printf("4 - Sair\n");

        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            ImprimirMenuPromocoesProdutos();
            break;
        case 2:
            ImprimirMenuClientes();
            break;
        case 3:
            EntregarPromocoesAClientes();
            break;
        case 4:
            printf("\nFim da aplicacao");
            break;
        default:
            printf("\nOpcao invalida");
        }

    } while(opcao != 4);

}

void ImprimirMenuPromocoesProdutos(){
    int opcao = 9;

    do{

        printf("\n=============  Tela de Promocoes Produtos  ================\n");
        printf("Escolha uma das opcoes abaixo\n");

        printf("1 - Empilhar Produto em Promocao na Pilha\n");
        printf("2 - Push de Produto em Promocao do topo da Pilha\n");
        printf("3 - Listar Pilha de Produtos em Promocao\n");
        printf("4 - Cadastro Preguicoso (Completa a pilha para voce que esta com preguica)\n");
        printf("5 - Voltar Menu Principal");

        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            //ImprimirMenuPromocoesProdutos();
            break;
        case 2:
            //ImprimirMenuClientes();
            break;
        case 3:
            //EntregarPromocoesAClientes();
            break;
        case 4:
            //printf("\nFim da aplicacao");
            break;
        case 5:
            printf("\nVoltando");
            break;
        default:
            printf("\nOpcao invalida");
        }

    } while(opcao != 5);

}

void ImprimirMenuClientes(){
    int opcao = 9;

    do{

        printf("\n=============  Tela de Clientes  ================\n");
        printf("Escolha uma das opcoes abaixo\n");

        printf("1 - Enfileirar Cliente na Fila\n");
        printf("2 - Remover Cliente do fim da Fila\n");
        printf("3 - Listar Fila de Clientes\n");
        printf("4 - Cadastro Preguicoso (Completa a fila com 30 clientes para voce que esta com preguica)\n");
        printf("5 - Voltar Menu Principal");

        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            //ImprimirMenuPromocoesProdutos();
            break;
        case 2:
            //ImprimirMenuClientes();
            break;
        case 3:
            //EntregarPromocoesAClientes();
            break;
        case 4:
            //printf("\nFim da aplicacao");
            break;
        case 5:
            printf("\nVoltando");
            break;
        default:
            printf("\nOpcao invalida");
        }

    } while(opcao != 5);

}


//======================================================================================================
//Entregar Promocoes a Clientes
void EntregarPromocoesAClientes(){
}


//======================================================================================================
// Métodos Pilha de Produtos

int PilhaProdutosVazia(PilhaProdutos *pilhaProdutos){
	if (pilhaProdutos->topo <= 0)
		return 1;
	else
        return 0;
}

int PilhaProdutosCheia(PilhaProdutos *pilhaProdutos){
	if (pilhaProdutos->topo >= MaxProdutos)
		return 1;
	else
        return 0;
}

int PushProduto(PilhaProdutos *pilhaProdutos, char *produto){
	if (!PilhaProdutosCheia(pilhaProdutos)) {
		pilhaProdutos->produtos[pilhaProdutos->topo++].Nome = strdup(produto);
		return 1;
	}
	else {
		printf("Erro: pilha cheia\n");
		return 0;
	}
}

void PopProduto(PilhaProdutos *pilhaProdutos){
	if (!PilhaProdutosVazia(pilhaProdutos)){
		pilhaProdutos->produtos[--pilhaProdutos->topo];
	}
	else{
		printf("Erro: pilha vazia\n");
	}
}

void ListarProdutos(PilhaProdutos *pilhaProdutos){
	int i;
	if (!PilhaProdutosVazia(pilhaProdutos))
		for (i = pilhaProdutos->topo-1; i >= 0; i--)
			printf ("%s\n",pilhaProdutos->produtos[i].Nome);
	else
        printf ("Pilha vazia\n");
}
