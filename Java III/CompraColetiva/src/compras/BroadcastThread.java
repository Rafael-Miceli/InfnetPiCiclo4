package compras;

import java.io.PrintStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

//Para enviar as atualiza��es do Produto

public class BroadcastThread implements Runnable {


	private List<PrintStream> listaBroadcast;
	private List<Produto> listaProdutos;
	private Socket conexaoLeitura;

	public BroadcastThread (Socket conexaoLeitura, List<PrintStream> listaBroadcast, List<Produto> listaProdutos){

		this.conexaoLeitura = conexaoLeitura;
		this.listaBroadcast = listaBroadcast;
		this.listaProdutos = listaProdutos;
	}


	@Override
	public void run() {
		
		// 1 - Recebe o produto escolhido pelo cliente 
		// Mais complexo, pois a partir dessa escolha , vai ser aberta a pagina desse produto para o cliente 
		// e ele vai ficar vendo a atualiza��o da quantidade de produtos
		// e tamb�m vai poder comprar o produto
		
		
		// 2 - Manda a lista dos nomes dos Produtos para todos os clientes
		for(PrintStream ps : listaBroadcast){
		   for(Produto p :listaProdutos){
			   ps.println("Nome : " + p.getNome()); //Não coloquei a quantidade de produtos , pois o cliente só vai vê-la quando abrir a página do produto 
		   }
		}
	}

}
