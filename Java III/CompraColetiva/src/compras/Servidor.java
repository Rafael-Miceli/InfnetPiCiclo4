package compras;

import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Servidor {
	
	List<Produto> listaProdutos;
	private int porta;
	private List<PrintStream> listaBroadcast; //tem que ter uma para cada produto ou colocar essa lista na classe Produto
	private ServerSocket server;

	//________________
	public Servidor(int porta) {		
		this.porta = porta;
		listaBroadcast = new ArrayList<>();
		listaProdutos = new ArrayList<>();
	}

	//________________
	//Retorna a lista de Produtos
	public List<Produto> getListaProdutos() {
		return listaProdutos;
	}

	//________________

	public void executarVendedor(){

		try
		{
			server = new ServerSocket(this.porta);
			System.out.println("Porta 10000 Aberta !");
			inserirProduto();

			//Fica esperando o cliente
			while(true){
				Socket socket = server.accept();

				System.out.println("Nova conexão com o cliente " +   
						socket.getInetAddress().getHostAddress()
						);

				//Para armazenar a saída dos clientes e mandar as atualizações do produto
				PrintStream ps = new PrintStream(socket.getOutputStream());
				listaBroadcast.add(ps);

				//Tratamento do recebimento de msg e distribuição
				//AQUI EU DELEGO PARA THREAD
				
				BroadcastThread broadcastThread = new BroadcastThread(socket , listaBroadcast , listaProdutos);
				new Thread(broadcastThread).start();
				
			}
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		}
		finally
		{
			try {
				server.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

	}

	//________________


	public void inserirProduto(){


		Scanner s = new Scanner(System.in);

		System.out.println("\nEntre com o total de produtos oferecidos : ");
		int op = s.nextInt();

		for(int i=1; i <= op; i++){

			Produto produto = new Produto(); // GC mata o anterior , compilador faz isso , entende que vai precisar de novas interações a cada for

			System.out.println("\nEntre com o nome do produto");	
			produto.setNome(s.next());
			System.out.println("\nEntre com a quantidade de produtos");	
			produto.setQuantidade(s.nextInt());

			listaProdutos.add(produto);

		}
		

	}


	//________________

	public static void main(String[] args) {

		Servidor vendedor = new Servidor(10000);
		vendedor.executarVendedor();

	}


}
