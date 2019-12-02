/****
 * 
 * Título: Genius
 *
 * Autores: Ryann Carlos de Arruda Quintino
 *
 * Data da criação: 02/11/2019
 * Última modificação: 03/11/2019
 *
 * Descrição: O software permite jogar uma ou mais partidas do jogo Genius.
 *
 ****/
 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>

extern int RespostaUsuario(int indices);
extern void LimpaBuffer();

int *sequencia, alocacao = 3;

int main(){
	int u = 0, k = 0, resposta = 0;
	register int i;
	
	setlocale(LC_ALL, "Portuguese");
	
	sequencia = (int *)malloc(sizeof(int));
	
	if(sequencia == NULL){
		printf("Erro de alocação!");
		Sleep(1500);
		system("cls");
		main();
	}
	
	do{
		
		u++;
		
		if(u % 2 == 0){
			k++;
		}
		
		else{
			k += 1;
		}

		for(i = 0; i < u; i++){
		
			sequencia[i] = (rand() % (2 + k));
		
			printf("[%d]Sequência = %d\n", i, sequencia[i]);
			Sleep(1300);
			system("cls");
		}
		
	}while(RespostaUsuario(u) == -1);
	
	printf("Deseja jogar outra partida? (1 - Sim / 2 - Não)\n");
	scanf("%d", &resposta);
	system("cls");
	
	if(resposta == 1){
		free(sequencia);
		sequencia = (int *)malloc(alocacao * sizeof(int));
		
		if(sequencia == NULL){
			printf("Erro de alocação!");
			Sleep(1500);
			system("cls");
			main();
		}
		
		resposta = 0;
		main();
	}
	
	else{
		free(sequencia);
	}
	
	return 0;
}

/****
 *
 * Descrição: Recebe a resposta do usuário e verifica se ele ganhou ou perdeu a partida.
 *
 * Parâmetros: indices - inteiro que indica até que índice o for deve ir.
 *
 * Valor de retorno: Inteiro que indica se o jogador ganhou ou perdeu a partida.
 *
 ****/
 
int RespostaUsuario(int indices){
	register int i;
	int resposta, confirmacao = 0;
	
	for(i = 0; i < indices; i++){
		printf("A sequência visualizada:\n");
		scanf("%d", &resposta);
		LimpaBuffer();
		system("cls");
		
		if(resposta == sequencia[i]){
			confirmacao++;
		}
	}
	
	if(confirmacao == indices){
		printf("Você ganhou essa partida! Prepare-se para a próxima.");
		Sleep(1500);
		system("cls");
		
		alocacao++;
		sequencia = (int *) realloc(sequencia, alocacao * sizeof(int));
		
		if(sequencia == NULL){
			printf("Erro de realocação!");
			Sleep(1500);
			system("cls");
			
			printf("O jogo irá reiniciar, aguarde!");
			Sleep(1500);
			system("cls");
			main();
		}
		return -1;
	}
	
	else{
		printf("Você perdeu! Tente novamente.");
		Sleep(1500);
		system("cls");
		
		return -2;
	}
}

void LimpaBuffer(){
	char c;
	
	while(c = getchar() != '\n');
}
