/****
 * 
 * Título: Jogo da Velha
 *
 * Autores: Ryann Carlos de Arruda Quintino
 *
 * Data da criação: 26/10/2019
 * Última modificação: 27/10/2019
 *
 * Descrição: O software permite jogar uma partida de jogo da velha com um oponente.
 *
 ****/

#include <stdio.h>
#include <locale.h>
#include <windows.h>

extern void InicializaMatriz();
extern void tabuleiro();
extern int jogadores(int opcao, char jogador);
extern void tabuleiro();
extern int vencedor();

int j = 0;
char matriz[9];

int main(){
	int opcao = 0, retorno = 0;
	int escolha = 0;
	
	setlocale(LC_ALL, "Portuguese"); 	/*Define o idioma de saída*/
	
	printf("REGRAS DO JOGO:\n\n");
	printf("1) Escolha sua opção de jogada de 0 a 8, correspondendo respectivamente a cada espaço do jogo, da esquerda para direita\nde cima para baixo.\n\n\n");
	printf("Pressione qualquer tecla para continuar...");
	getchar();
	system("cls");
	
	InicializaMatriz();
	tabuleiro();
	
	while(j != -1){

		do{

			printf("\n(Jogador 1) Digite o número do quadrante que deseja marcar:\n");
			scanf("%d", &opcao);
			system("cls");
			retorno = jogadores(opcao, 'X');
		
			if(retorno == 1){
				printf("Jogador 1 é o vencedor!");

				printf("\n\nDeseja jogar outra partida? (1 - Sim / 2 - Não)\n");
				scanf("%d", &escolha);
				
				if(escolha == 1){
					return main();
				}
				
				else{
					return 0;
				}
			}
		
			else if(retorno == 4){
				printf("Velha!");

				printf("\n\nDeseja jogar outra partida? (1 - Sim / 2 - Não)\n");
				scanf("%d", &escolha);
				
				if(escolha == 1){
					return main();
				}
				
				else{
					return 0;
				}
			}
			
			else if(retorno == -1){
				printf("Opção Inválida! Tente novamente.");
				
				Sleep(1000);
				system("cls");
				
				tabuleiro();
			}
			
		}while(retorno == -1);

		do{

			printf("\n(Jogador 2) Digite o número do quadrante que deseja marcar:\n");
			scanf("%d", &opcao);
			system("cls");
			retorno = jogadores(opcao, 'O');

			if(retorno == 2){
				printf("Jogador 2 é o vencedor!");

				printf("\nDeseja jogar outra partida?\n");
				scanf("%d", &escolha);
				
				if(escolha == 1){
					return main();
				}
				
				else{
					return 0;
				}
			}
		
			else if(retorno == 4){
				printf("Velha!");
				
				printf("\nDeseja jogar outra partida?\n");
				scanf("%d", &escolha);
				
				if(escolha == 1){
					return main();
				}
				
				else{
					return 0;
				}
				
			}
			
			else if(retorno == -1){
				printf("Opção Inválida! Tente novamente.");

				Sleep(1000);
				system("cls");
				
				tabuleiro();
			}
		
		}while(retorno == -1);
		
	}
	
	return 0;
}

/****
 * Descrição: Inicializa a matriz que irá armazenar as escolhas do usuário.
 *
****/
void InicializaMatriz(){
	register int p;
	
	for(p = 0; p < 9; p++){
		matriz[p] = '\0';
	}
}

/****
 * Descrição: Armazena a escolha do jogador e verifica se a opção escolhida é válida.
 *
 * Parâmetros: opcao - inteiro que corresponde a escolha de cada jogador.
 * 			   jogador - caracter que indica qual jogador que realizou a jogada.
 *
 * Valor de retorno: Inteiro que corresponde ao retorno da função "vencedor()";indicando se existe ou não alguma vencedor.
 *
 ****/
int jogadores(int opcao, char jogador){
	
	if (jogador == 'X'){
		
		if(matriz[opcao] != '\0' || opcao < 0 || opcao > 9){
			return -1;
		}
		
		matriz[opcao] = jogador;
		tabuleiro();
		return vencedor();
	}
	
	else if(jogador == 'O'){
		
		if(matriz[opcao] != '\0' || opcao < 0 || opcao > 9){
			return -1;
		}
		
		matriz[opcao] = jogador;
		tabuleiro();
		return vencedor();
	}
}

void tabuleiro(){
	
	printf(" %c  | %c   | %c \n", matriz[0], matriz[1], matriz[2]);
	printf("____|_____|_____\n");
	printf(" %c  | %c   | %c  \n", matriz[3], matriz[4], matriz[5]);
	printf("____|_____|_____\n");
	printf(" %c  | %c   | %c  \n", matriz[6], matriz[7], matriz[8]);
	printf("    |     |     \n");
}

/****
 * Descrição: Verifica se existe algum vencedor ou de aconteceu "velha".
 *
 * Parâmetros: nenhum.
 *
 * Valor de retorno: Inteiro que corresponde a existencia de vencedor ou de velha.
 *
 ****/
int vencedor(){
	register int i = 0;
	int elementos = 0;
	
	for(i = 0; i < 6; i += 3){
		
		if(matriz[i] == matriz[i + 1] && matriz[i + 1] == matriz[i + 2]){
			
			if(matriz[i] == 'X'){
		
				return 1;
			}
			
			else if(matriz[i] == 'O'){
		
				return 2;
			}
		}
	}
	
	for(i = 0; i < 3; i++){

		if(matriz[i] == matriz[i + 3] && matriz[i + 3] == matriz[i + 6]){
			
			if(matriz[i] == 'X'){
		
				return 1;
			}
			
			else if(matriz[i] == 'O'){
		
				return 2;
			}
		}
	}
		
	if(matriz[0] == matriz[4] && matriz[4] == matriz[8] || matriz[2] == matriz[4] && matriz[4] == matriz[6]){
			
		if(matriz[4] == 'X'){
		
			return 1;
		}
			
		else if(matriz[4] == 'O'){
		
			return 2;
		}
	}
	
	for(i = 0; i < 9; i++){
		
		if(matriz[i] != '\0'){
			
			elementos++;
			
			if(elementos == 9){
				
				return 4;
			}
		}
	}
}
