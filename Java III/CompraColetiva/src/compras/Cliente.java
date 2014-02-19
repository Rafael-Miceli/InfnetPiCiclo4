package compras;

import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

import sun.awt.windows.ThemeReader;

public class Cliente {
	
	private Socket socket = null;
	private String host;
	private int porta;
	
	
	public Cliente(String host, int porta) {
		this.host = host;
		this.porta = porta;
	}

	
	//____________
	
	public void executarMenu(){
		
		boolean run = true; //Para executar o menu
		Scanner scanner = new Scanner(System.in);
		
		try 
		{
			socket = new Socket(this.host, this.porta);
			
			//Para quando eu abrir a página de um produto 
			//Ou para quando eu efetuar compra ou fechar a página do produto
			PrintStream ps = new PrintStream(socket.getOutputStream()); 
			
			while(run){
				
				// 1 - Lista os produtos
				RecebeMsgThread recebeMsg = new RecebeMsgThread(socket);
				new Thread(recebeMsg).start();
				
	            
				// 2 - Escolhe o produto
				System.out.println("\nEntre com o nome do produto");
				String strOpcao = scanner.nextLine();
				
				
				
				
				// 3 - Abre a página do produto 
				/*O cliente ira escolher um produto da lista de produtos e irá abrir a sua página
				Ele vai poder ou comprar o produto e vai receber as atualizações
				Ou ele vai fechar a pagina e vai deixar de receber as atualizações da quantidade do produto*/
				
				
				// 4 - Compra o Produto
				
				// 5 - Fecha a pagina do Produto
				
				
				// 6 - Sai do Menu
				if(strOpcao.equals("exit")){
					run = false;
				}
			}
		}
		catch (IOException e) 
		{
			e.printStackTrace();
		}
		finally
		{
			try {
				socket.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
	
		
		
		
	}
	
	public static void main(String[] args) {
		
		Cliente cliente = new Cliente("127.0.0.1", 10000);
		cliente.executarMenu();
	}
}
