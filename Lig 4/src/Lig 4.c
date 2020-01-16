/****
 * 
 * Título: Lig4.
 *
 * Autores: Ryann Carlos de Arruda Quintino
 *
 * Data da criação: 06/11/2019
 * Última modificação: 08/11/2019
 *
 * Descrição: O software permite jogar uma partida do Lig4.
 *
 ****/

#include <stdio.h>
#include <string.h>
#include <locale.h>

extern void Inicializa();
extern void ImprimeTabuleiro();
extern int Jogadas(int coluna, char jogador);
extern int Vencedor();

char tabuleiro [6][7];

int main(){
	int coluna = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	Inicializa();
	
	do{

		do{
			ImprimeTabuleiro();
			printf("\n(Jogador 1)Escolha a coluna que deseja jogar (0 - 5):\n");
			scanf("%d", &coluna);
			system("cls");
		
		}while(Jogadas(coluna, 'X') == -1);
		
		if(Vencedor() == -2){
			break;
		}

		do{
			system("cls");
			ImprimeTabuleiro();	
			printf("\n(Jogador 2)Escolha a coluna que deseja jogar (0 - 6):\n");
			scanf("%d", &coluna);
			system("cls");
		
		}while(Jogadas(coluna, 'O') == -1);
		
		if(Vencedor() == -2){
			break;
		}
	
	}while(1);
	
	return 0;
}

void Inicializa(){
	int i, j;
	
	for(i = 0; i < 6; i++){
		
		for(j = 0; j < 7; j++){
			
			tabuleiro[i][j] = '\0';
		}
	}
}

void ImprimeTabuleiro(){
	
	printf("  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2], tabuleiro[0][3], tabuleiro[0][4], tabuleiro[0][5], tabuleiro[0][6]);
	printf("______|______|______|______|______|______|______|\n");
	printf("  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2], tabuleiro[1][3], tabuleiro[1][4], tabuleiro[1][5], tabuleiro[1][6]);
	printf("______|______|______|______|______|______|______|\n");
	printf("  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2], tabuleiro[2][3], tabuleiro[2][4], tabuleiro[2][5], tabuleiro[2][6]);
	printf("______|______|______|______|______|______|______|\n");
	printf("  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |\n", tabuleiro[3][0], tabuleiro[3][1], tabuleiro[3][2], tabuleiro[3][3], tabuleiro[3][4], tabuleiro[3][5], tabuleiro[3][6]);
	printf("______|______|______|______|______|______|______|\n");
	printf("  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |\n", tabuleiro[4][0], tabuleiro[4][1], tabuleiro[4][2], tabuleiro[4][3], tabuleiro[4][4], tabuleiro[4][5], tabuleiro[4][6]);
	printf("______|______|______|______|______|______|______|\n");
	printf("  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |  %c   |\n", tabuleiro[5][0], tabuleiro[5][1], tabuleiro[5][2], tabuleiro[5][3], tabuleiro[5][4], tabuleiro[5][5], tabuleiro[5][6]);
	printf("      |      |      |      |      |      |      |\n");
}

/****
 * 
 * Descrição: Verifica se a resposta fornecida pelo jogador é válida, caso seja, armazena sua resposta no respectivo espaço.
 *
 * Parâmetros: coluna - inteiro que indica a resposta do usuário.
 * 			   jogador - identificação de qual jogador realizou a jogada.
 *
 * Valor de retorno: Inteiro que indica se o joagdor realizou uma jogada inválida.
 *
 ****/
int Jogadas(int coluna, char jogador){
	int linha, contador = 0;
	
	if(coluna < 0 || coluna > 6){
		printf("Digite uma coluna válida!");
		Sleep(1500);
		system("cls");
		
		return -1;
	}
	
	for(linha = 5; linha >= 0; linha--){
		
		if(tabuleiro[linha][coluna] == '\0'){
			
			tabuleiro[linha][coluna] = jogador;
			break;
		}
		
		else{
			contador++;
		}
	}
	
	if(contador == 6){
		
		printf("Coluna já preenchida; insira uma coluna válida.");
		Sleep(1500);
		system("cls");
		
		return -1;
	}
}

/****
 * 
 * Descrição: Verifica se existe algum vencedor durante a partida.
 *
 * Parâmetros: Nenhum.
 *
 * Valor de retorno: Inteiro que indica se houve algum vencedor ou não.
 *
 ****/
int Vencedor(){
	int i, j;
	int contador = 0;
	
	for(j = 0; j < 7; j++){
		
		for(i = 0; i < 3; i++){
			
			if(tabuleiro[i][j] == tabuleiro[i + 1][j] && tabuleiro[i + 1][j] == tabuleiro[i + 2][j] && tabuleiro[i + 2][j] == tabuleiro[i + 3][j] && tabuleiro[i + 3][j] == 'X'){
				ImprimeTabuleiro();
				printf("\n\nJogador 1 é o vencedor!");
				
				return -2;
			}
			
			else if(tabuleiro[i][j] == tabuleiro[i + 1][j] && tabuleiro[i + 1][j] == tabuleiro[i + 2][j] && tabuleiro[i + 2][j] == tabuleiro[i + 3][j] && tabuleiro[i + 3][j] == 'O'){
				ImprimeTabuleiro();
				printf("\n\nJogador 2 é o vencedor!");
				
				return -2;
			}
		}
	}
	
	for(i = 0; i < 6; i++){
		
		for(j = 0; j < 4; j++){
			
			if(tabuleiro[i][j] == tabuleiro[i][j + 1] && tabuleiro[i][j + 1] == tabuleiro[i][j + 2] && tabuleiro[i][j + 2] == tabuleiro[i][j + 3] && tabuleiro[i][j] == 'X'){

				ImprimeTabuleiro();
				printf("\n\nJogador 1 é o vencedor!");
				
				return -2;
			}

			else if(tabuleiro[i][j] == tabuleiro[i][j + 1] && tabuleiro[i][j + 1] == tabuleiro[i][j + 2] && tabuleiro[i][j + 2] == tabuleiro[i][j + 3] && tabuleiro[i][j] == 'O'){

				ImprimeTabuleiro();
				printf("\n\nJogador 2 é o vencedor!");
				
				return -2;
			}
		}
	}
	
	for(i = 0; i < 3; i++){
		
		for(j = 3; j > -1; j--){
			
			if(tabuleiro[i][j] == tabuleiro[i + 1][j + 1] && tabuleiro[i + 1][j + 1] == tabuleiro[i + 2][j + 2] && tabuleiro[i + 2][j + 2] == tabuleiro[i + 3][j + 3] && tabuleiro[i][j] == 'X'){
				
				ImprimeTabuleiro();
				printf("\n\nJogador 1 é o vencedor!");
				
				return -2;
			}

			else if(tabuleiro[i][j] == tabuleiro[i + 1][j + 1] && tabuleiro[i + 1][j + 1] == tabuleiro[i + 2][j + 2] && tabuleiro[i + 2][j + 2] == tabuleiro[i + 3][j + 3] && tabuleiro[i][j] == 'O'){
				
				ImprimeTabuleiro();
				printf("\n\nJogador 2 é o vencedor!");
				
				return -2;
			}
		}
	}
	
	for(i = 5; i > 2; i--){
		
		for(j = 3; j > -1; j--){

			if(tabuleiro[i][j] == tabuleiro[i - 1][j + 1] && tabuleiro[i - 1][j + 1] == tabuleiro[i - 2][j + 2] && tabuleiro[i - 2][j + 2] == tabuleiro[i - 3][j + 3] && tabuleiro[i][j] == 'X'){
				
				ImprimeTabuleiro();
				printf("\n\nJogador 1 é o vencedor!");
				
				return -2;
			}

			if(tabuleiro[i][j] == tabuleiro[i - 1][j + 1] && tabuleiro[i - 1][j + 1] == tabuleiro[i - 2][j + 2] && tabuleiro[i - 2][j + 2] == tabuleiro[i - 3][j + 3] && tabuleiro[i][j] == 'O'){
				
				ImprimeTabuleiro();
				printf("\n\nJogador 2 é o vencedor!");
				
				return -2;
			}
			
		}
	}
	
	for(j = 0; j < 7; j++){
		
		for(i = 0; i < 6; i++){
			
			if(tabuleiro[i][j] != '\0'){
				
				contador++;
			}
		}
		
		if(contador == 42){
			printf("\n\nEMPATE!");
			
			return -2;
		}
	}
}
