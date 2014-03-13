#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Clientes.h"


FilaDeClientes _filaDeClientes = {NULL, NULL};;

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

void InserirClientesModoPreguica(){

    Cliente cliente01;
    strcpy(cliente01.Nome,"cliente1");
    strcpy(cliente01.Email,"cliente01@email.com");
    EnfileirarCliente(&_filaDeClientes, cliente01);

    Cliente cliente02;
    strcpy(cliente02.Nome,"cliente2");
    strcpy(cliente02.Email,"cliente02@email.com");
    EnfileirarCliente(&_filaDeClientes, cliente02);

    Cliente cliente03;
    strcpy(cliente03.Nome,"cliente3");
    strcpy(cliente03.Email,"cliente03@email.com");
    EnfileirarCliente(&_filaDeClientes, cliente03);

    Cliente cliente04;
    strcpy(cliente04.Nome,"cliente4");
    strcpy(cliente04.Email,"cliente04@email.com");
    EnfileirarCliente(&_filaDeClientes, cliente04);

    Cliente cliente05;
    strcpy(cliente05.Nome,"cliente5");
    strcpy(cliente05.Email,"cliente05@email.com");
    EnfileirarCliente(&_filaDeClientes, cliente05);

    printf("\n\n5 clientes inseridos com sucesso\n\n");
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
        printf("\nFila de Clientes vazia\n");
        return;
    }

    printf("== == == Cliente == == ==\n");
    printf("%s\n", listaDeClientes->cliente.Nome);
    printf("%s\n", listaDeClientes->cliente.Email);
    printf("== == == Cliente == == ==\n");

    if (listaDeClientes->referencia_ant != NULL)
        ListarClientes(filaDeClientes, listaDeClientes->referencia_ant);

}
