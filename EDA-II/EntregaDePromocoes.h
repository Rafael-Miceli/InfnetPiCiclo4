typedef struct NoDeClientesPromocionados{
    char NomeCliente[100];
    char EmailCliente[100];
    char NomeProduto[100];
    struct NoDeClientesPromocionados *referencia_prox;
    struct NoDeClientesPromocionados *referencia_ant;
} NoDeClientesPromocionados;

typedef struct{
    NoDeClientesPromocionados *inicio;
    NoDeClientesPromocionados *fim;
} ListaDeClientesPromocionados;


extern ListaDeClientesPromocionados _listaDeClientesPromocionados;


//Entregar Promocoes a Clientes
void EntregarPromocoesAClientes();
NoDeClientesPromocionados* AdicionarNoNaLista();
void ListarClientesPromocionados(ListaDeClientesPromocionados listaDeClientesPromocionados, NoDeClientesPromocionados *noDeClientesPromocionados);
int ListaDeClientesPromocionaddoVazia(ListaDeClientesPromocionados listaDeClientesPromocionados);