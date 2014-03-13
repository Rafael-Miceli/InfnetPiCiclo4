#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Produtos.h"

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
        pilhaProdutos->produtos[pilhaProdutos->topo].Nome = NULL;
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
        printf ("\nPilha vazia\n");
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

    printf("\n\n Pilha De Produtos Completa\n\n");
}
