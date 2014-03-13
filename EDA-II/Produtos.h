#define MaxProdutos 5

typedef struct{
    char *Nome;
} Produto;

typedef struct {
	int topo;
	Produto produtos[MaxProdutos];
} PilhaProdutos;

extern


// Métodos Pilha de Produtos

int PilhaProdutosVazia(PilhaProdutos *pilhaProdutos);
int PilhaProdutosCheia(PilhaProdutos *pilhaProdutos);
int PushProduto(PilhaProdutos *pilhaProdutos, char *produto);
void PopProduto(PilhaProdutos *pilhaProdutos);
void ListarProdutos(PilhaProdutos *pilhaProdutos);
void EmpilharProdutosModoPreguica();
