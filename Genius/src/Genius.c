/****
 * 
 * T�tulo: Genius
 *
 * Autores: Ryann Carlos de Arruda Quintino
 *
 * Data da cria��o: 02/11/2019
 * �ltima modifica��o: 03/11/2019
 *
 * Descri��o: O software permite jogar uma ou mais partidas do jogo Genius.
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
		printf("Erro de aloca��o!");
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
		
			printf("[%d]Sequ�ncia = %d\n", i, sequencia[i]);
			Sleep(1300);
			system("cls");
		}
		
	}while(RespostaUsuario(u) == -1);
	
	printf("Deseja jogar outra partida? (1 - Sim / 2 - N�o)\n");
	scanf("%d", &resposta);
	system("cls");
	
	if(resposta == 1){
		free(sequencia);
		sequencia = (int *)malloc(alocacao * sizeof(int));
		
		if(sequencia == NULL){
			printf("Erro de aloca��o!");
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
 * Descri��o: Recebe a resposta do usu�rio e verifica se ele ganhou ou perdeu a partida.
 *
 * Par�metros: indices - inteiro que indica at� que �ndice o for deve ir.
 *
 * Valor de retorno: Inteiro que indica se o jogador ganhou ou perdeu a partida.
 *
 ****/
 
int RespostaUsuario(int indices){
	register int i;
	int resposta, confirmacao = 0;
	
	for(i = 0; i < indices; i++){
		printf("A sequ�ncia visualizada:\n");
		scanf("%d", &resposta);
		LimpaBuffer();
		system("cls");
		
		if(resposta == sequencia[i]){
			confirmacao++;
		}
	}
	
	if(confirmacao == indices){
		printf("Voc� ganhou essa partida! Prepare-se para a pr�xima.");
		Sleep(1500);
		system("cls");
		
		alocacao++;
		sequencia = (int *) realloc(sequencia, alocacao * sizeof(int));
		
		if(sequencia == NULL){
			printf("Erro de realoca��o!");
			Sleep(1500);
			system("cls");
			
			printf("O jogo ir� reiniciar, aguarde!");
			Sleep(1500);
			system("cls");
			main();
		}
		return -1;
	}
	
	else{
		printf("Voc� perdeu! Tente novamente.");
		Sleep(1500);
		system("cls");
		
		return -2;
	}
}

void LimpaBuffer(){
	char c;
	
	while(c = getchar() != '\n');
}
