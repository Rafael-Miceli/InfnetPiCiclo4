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

extern FilaDeClientes _filaDeClientes;

// Métodos Fila de Clientes

int FilaDeClienteVazia(FilaDeClientes filaDeClientes);
ListaDeClientes* AdicionarNaFila();
void EnfileirarCliente(FilaDeClientes *filaDeClientes, Cliente cliente);
void InserirClientesModoPreguica();
void DesenfileirarCliente(FilaDeClientes *filaDeClientes);
void ListarClientes(FilaDeClientes filaDeClientes, ListaDeClientes *listaDeClientes);
