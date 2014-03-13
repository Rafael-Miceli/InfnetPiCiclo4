#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "EntregaDePromocoes.h"

ListaDeClientesPromocionados _listaDeClientesPromocionados = {NULL, NULL};


//Entregar Promocoes a Clientes
void EntregarPromocoesAClientes(FilaDeClientes *filaDeClientes, PilhaProdutos *pilhaProdutos, ListaDeClientesPromocionados *listaDeClientesPromocionados){
    ListaDeClientes *clienteAtual;
    int produto = pilhaProdutos->topo;


    if (!FilaDeClienteVazia(*filaDeClientes) && !PilhaProdutosVazia(pilhaProdutos))
    {
        clienteAtual = filaDeClientes->inicio;
    }
    else
    {
        printf("Sem produtos ou Clientes\n");
        return;
    }

    do
    {
        if (produto == 0)
        {
            printf("\n\nPromocoes de Produtos esgotadas.\n\n");
            break;
        }

        if (ListaDeClientesPromocionaddoVazia(*listaDeClientesPromocionados)) {
            listaDeClientesPromocionados->inicio = listaDeClientesPromocionados->fim = AdicionarNoNaLista();
            strcpy(listaDeClientesPromocionados->inicio->NomeCliente, clienteAtual->cliente.Nome);
            strcpy(listaDeClientesPromocionados->inicio->EmailCliente , clienteAtual->cliente.Email);
            strcpy(listaDeClientesPromocionados->inicio->NomeProduto , pilhaProdutos->produtos[--produto].Nome);
            listaDeClientesPromocionados->inicio->referencia_ant = NULL;
            listaDeClientesPromocionados->inicio->referencia_prox = NULL;
            DesenfileirarCliente(filaDeClientes);
            PopProduto(pilhaProdutos);
        }
        else{
            listaDeClientesPromocionados->fim->referencia_prox = AdicionarNoNaLista();
            listaDeClientesPromocionados->fim->referencia_prox->referencia_ant = listaDeClientesPromocionados->fim;
            listaDeClientesPromocionados->fim = listaDeClientesPromocionados->fim->referencia_prox;
            strcpy(listaDeClientesPromocionados->fim->NomeCliente , clienteAtual->cliente.Nome);
            strcpy(listaDeClientesPromocionados->fim->EmailCliente , clienteAtual->cliente.Email);
            strcpy(listaDeClientesPromocionados->fim->NomeProduto , pilhaProdutos->produtos[--produto].Nome);
            listaDeClientesPromocionados->fim->referencia_prox = NULL;
            DesenfileirarCliente(filaDeClientes);
            PopProduto(pilhaProdutos);
        }

        clienteAtual = clienteAtual->referencia_prox;
    } while(clienteAtual != NULL);
}

void ListarClientesPromocionados(ListaDeClientesPromocionados listaDeClientesPromocionados, NoDeClientesPromocionados *noDeClientesPromocionados){
    if (ListaDeClientesPromocionaddoVazia(listaDeClientesPromocionados)) {
        printf("Lista de Clientes Promocionados vazia\n");
        return;
    }

    printf("\n== == == Cliente Promocionado == == ==\n");
    printf("%s\n", noDeClientesPromocionados->NomeCliente);
    printf("%s\n", noDeClientesPromocionados->EmailCliente);
    printf("%s\n", noDeClientesPromocionados->NomeProduto);
    printf("== == == Cliente Promocionado == == ==\n");

    if (noDeClientesPromocionados->referencia_ant != NULL)
        ListarClientesPromocionados(listaDeClientesPromocionados, noDeClientesPromocionados->referencia_ant);
}

NoDeClientesPromocionados* AdicionarNoNaLista(){
    NoDeClientesPromocionados *no;

    no = (NoDeClientesPromocionados*)malloc(sizeof(struct NoDeClientesPromocionados));
    if (no == NULL) {
        printf("Erro: criacao do no\n");
        return NULL;
    }
	else
        return no;
}

int ListaDeClientesPromocionaddoVazia(ListaDeClientesPromocionados listaDeClientesPromocionados){
    if (listaDeClientesPromocionados.inicio == NULL)
        return 1;
    else
        return 0;
}