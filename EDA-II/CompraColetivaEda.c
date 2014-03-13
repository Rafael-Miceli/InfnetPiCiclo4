/*NOMES :

RICARDO MENDES

ALEX  BAURUEL

ALEXANDRO  BENTO

FABIO NASCIMENTO

RAFAEL MICELI
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Produtos.c"
#include "Clientes.c"
#include "EntregaDePromocoes.c"


//================ Variaveis Globais ================//

PilhaProdutos _pilhaProdutos;

FilaDeClientes _filaDeClientes;

ListaDeClientesPromocionados _listaDeClientesPromocionados;


//Menus

void ImprimirMenuPrincipal();
void ImprimirMenuPromocoesProdutos();
void ImprimirMenuClientes();


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
            EntregarPromocoesAClientes(&_filaDeClientes, &_pilhaProdutos, &_listaDeClientesPromocionados);
            ListarClientesPromocionados(_listaDeClientesPromocionados, _listaDeClientesPromocionados.fim);
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
        printf("4 - Cadastro Preguicoso (Mais 5 clientes para voce que esta com preguica)\n");
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
            InserirClientesModoPreguica();
            break;
        case 5:
            printf("\nVoltando");
            break;
        default:
            printf("\nOpcao invalida");
        }

    } while(opcao != 5);

}

