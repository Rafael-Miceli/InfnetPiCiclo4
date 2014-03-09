#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxProdutos 5

typedef struct{
    char *Nome;
} Produto;

typedef struct {
	int topo;
	Produto produtos[MaxProdutos];
} PilhaProdutos;

PilhaProdutos _pilhaProdutos;

typedef struct{
    char Nome[100];
    char Email[100];
} Cliente;

typedef struct ListaDeClientes{
    Cliente cliente;
    struct ListaDeClientes *referencia_prox;
    struct ListaDeClientes *referencia_ant;
} ListaDeClientes;

typedef struct{
    ListaDeClientes *inicio;
    ListaDeClientes *fim;
} FilaDeClientes;

FilaDeClientes _filaDeClientes = {NULL, NULL};


typedef struct NoDeClientesPromocionados{
    char *NomeCliente;
    char *EmailCliente;
    char *NomeProduto;
    struct NoDeClientesPromocionados *referencia_prox;
    struct NoDeClientesPromocionados *referencia_ant;
} NoDeClientesPromocionados;

typedef struct{
    NoDeClientesPromocionados *inicio;
    NoDeClientesPromocionados *fim;
} ListaDeClientesPromocionados;

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


// Métodos Fila de Clientes

int FilaDeClienteVazia(FilaDeClientes filaDeClientes);
ListaDeClientes* AdicionarNaFila();
void EnfileirarCliente(FilaDeClientes *filaDeClientes, Cliente cliente);
void DesenfileirarCliente(FilaDeClientes *filaDeClientes);
void ListarClientes(FilaDeClientes filaDeClientes, ListaDeClientes *listaDeClientes);

//Entregar Promocoes a Clientes
void EntregarPromocoesAClientes();

main(){

    _pilhaProdutos.topo = 0;

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
    char nomeProduto[100];

    do{

        printf("\n=============  Tela de Promocoes Produtos  ================\n");
        printf("Escolha uma das opcoes abaixo\n");

        printf("1 - Empilhar Produto em Promocao na Pilha\n");
        printf("2 - Pop de Produto em Promocao do topo da Pilha\n");
        printf("3 - Listar Pilha de Produtos em Promocao\n");
        printf("4 - Cadastro Preguicoso (Completa a pilha para voce que esta com preguica)\n");
        printf("5 - Voltar Menu Principal\n");

        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite o nome do produto em promocao: ");
            scanf("%s", nomeProduto);
            PushProduto(&_pilhaProdutos, nomeProduto);
            break;
        case 2:
            PopProduto(&_pilhaProdutos);
            break;
        case 3:
            ListarProdutos(&_pilhaProdutos);
            break;
        case 4:
            EmpilharProdutosModoPreguica(&_pilhaProdutos);
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
    char nomeCliente[100];
    char emailCliente[100];
    Cliente cliente;

    do{

        printf("\n=============  Tela de Clientes  ================\n");
        printf("Escolha uma das opcoes abaixo\n");

        printf("1 - Enfileirar Cliente na Fila\n");
        printf("2 - Remover Cliente do fim da Fila\n");
        printf("3 - Listar Fila de Clientes\n");
        printf("4 - Cadastro Preguicoso (Mais 30 clientes para voce que esta com preguica)\n");
        printf("5 - Voltar Menu Principal\n");

        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite o nome do cliente: ");
            scanf("%s", cliente.Nome);
            printf("Digite o email do cliente: ");
            scanf("%s", cliente.Email);

            EnfileirarCliente(&_filaDeClientes, cliente);
            break;
        case 2:
            DesenfileirarCliente(&_filaDeClientes);
            break;
        case 3:
            ListarClientes(_filaDeClientes, _filaDeClientes.fim);
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
    {
        printf("========= Produtos em Promocao =========\n");

		for (i = pilhaProdutos->topo-1; i >= 0; i--)
			printf ("%s\n",pilhaProdutos->produtos[i].Nome);

        printf("========= Produtos em Promocao =========\n");
    }
	else
        printf ("Pilha vazia\n");
}

void EmpilharProdutosModoPreguica(PilhaProdutos *pilhaProdutos){
    int prodCount = 49;
    char produtoNome[100] = "Produto ";

    if(PilhaProdutosCheia(pilhaProdutos))
    {
        printf("Erro: pilha cheia\n");
        return;
    }

    while(!PilhaProdutosCheia(pilhaProdutos)) {
         produtoNome[8] = prodCount;
	 	 pilhaProdutos->produtos[pilhaProdutos->topo++].Nome = strdup(produtoNome);
	 	 prodCount++;
    }
}

// Métodos fila de Cliente


int FilaDeClienteVazia(FilaDeClientes filaDeClientes) {

    if (filaDeClientes.inicio == NULL)
        return 1;
    else
        return 0;
}

ListaDeClientes* AdicionarNaFila(){
    ListaDeClientes *no;

    no = (ListaDeClientes*)malloc(sizeof(struct ListaDeClientes));
    if (no == NULL) {
        printf("Erro: criacao do no\n");
        return NULL;
    }
	else
        return no;
}

void EnfileirarCliente(FilaDeClientes *filaDeClientes, Cliente cliente) {



    if (FilaDeClienteVazia(*filaDeClientes)) {
        filaDeClientes->inicio = filaDeClientes->fim = AdicionarNaFila();
        filaDeClientes->inicio->cliente = cliente;
        filaDeClientes->inicio->referencia_ant = NULL;
        filaDeClientes->inicio->referencia_prox = NULL;
    }
    else {
        filaDeClientes->fim->referencia_prox = AdicionarNaFila();
        filaDeClientes->fim->referencia_prox->referencia_ant = filaDeClientes->fim;
        filaDeClientes->fim = filaDeClientes->fim->referencia_prox;
        filaDeClientes->fim->cliente = cliente;
        filaDeClientes->fim->referencia_prox = NULL;
    }
}

void DesenfileirarCliente(FilaDeClientes *filaDeClientes) {

    if (!FilaDeClienteVazia(*filaDeClientes)) {
        if (filaDeClientes->inicio == filaDeClientes->fim) {
            free(filaDeClientes->fim);
            filaDeClientes->inicio = filaDeClientes->fim = NULL;
        }
        else {
            filaDeClientes->inicio = filaDeClientes->inicio->referencia_prox;
            free(filaDeClientes->inicio->referencia_ant);
            filaDeClientes->inicio->referencia_ant= NULL;
        }
    }
    else
        printf("Erro: Fila de Clientes vazia\n");
}

void ListarClientes(FilaDeClientes filaDeClientes, ListaDeClientes *listaDeClientes) {

    if (FilaDeClienteVazia(filaDeClientes)) {
        printf("Fila de Clientes vazia\n");
        return;
    }

    printf("== == == Cliente == == ==\n");
    printf("%s\n", listaDeClientes->cliente.Nome);
    printf("%s\n", listaDeClientes->cliente.Email);
    printf("== == == Cliente == == ==\n");

    if (listaDeClientes->referencia_ant != NULL)
        ListarClientes(filaDeClientes, listaDeClientes->referencia_ant);

}
