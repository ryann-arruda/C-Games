/****
 * 
 * T�tulo: Jogo da Forca
 *
 * Autores: Ryann Carlos de Arruda Quintino
 *
 * Data da cria��o: 28/10/2019
 * �ltima modifica��o: 30/10/2019
 *
 * Descri��o: O software permite jogar uma ou mais partidas do jogo da forca .
 *
 ****/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <ctype.h>

extern void InterfaceJogadores();
extern void PalavraChave();
extern void Inicializa();
extern void InicializaPontuacao();
extern int ArmazenaLetra(char letra, int jogador);
extern int VerificaLetras(char letra);
extern void VerificaResposta(char letra, int jogador);
extern int VerificaTamPalavra();
extern int VerificaRespostaGeral(char *RespostaGeral, int jogador);
extern void LimpaBuffer();

char LetrasArmazenadas[27], armazena[175];
int VidasJogadores[3] = {6, 6, 6};
char Resposta[175];
int pontuacao[3];

int main(){
	char letra, RespostaGeral[175];
	int partidas = 0, retorno = 0;
	
	setlocale(LC_ALL, "Portuguese"); /*Define o idioma de sa�da*/
	
	InicializaPontuacao();
	
	while(partidas != 5){
		
		PalavraChave();
		Inicializa();
		
		InterfaceJogadores();
		
		if(partidas != 4){

			printf("Digite a nova palavra no arquivo e pressione qualquer tecla para continuar para a pr�xima partida!");
			getchar();
			Sleep(1800);
			system("cls");
		}
		
		partidas++;
	}
	
	printf("\tPONTUA��O\n");
	printf("Jogador 1 = %d\n", pontuacao[0]);
	printf("Jogador 2 = %d\n", pontuacao[1]);
	printf("Jogador 3 = %d", pontuacao[2]);
		
	return 0;
}

/****
 *
 * Descri��o: Exibe as letras da palavra secreta, quantas vidas (tentativas) o jogador ainda possui e permite o usu�rio selecionar sua op��o de letra ou a palavra completa.
 *
 * Par�metros: Nenhum.
 *
 * Valor de retorno: Nenhum.
 *
 ****/

void InterfaceJogadores(){
	char letra, RespostaGeral[175];
	int retorno = 0;

		do{
			
			if(VidasJogadores[0] != 0){

				do{
					printf("Palavra secreta: %s\n\n", Resposta);
					printf("LETRAS USADAS: %s\n\n", LetrasArmazenadas);
					printf("***VIDAS DO JOGADOR 1: %d***\n\n", VidasJogadores[0]);
					printf("(Jogador 1)Digite sua escolha de letra:\n");
					scanf("%c", &letra);
					LimpaBuffer();
					system("cls");
				
				}while(ArmazenaLetra(letra, 0) == -1);
			}
			
			if(VerificaTamPalavra() <= 3){
				
				do{
					
					printf("Palavra secreta: %s\n\n", Resposta);
					
					printf("(Jogador 2)Digite a palavra secreta:\n");
					scanf("%[^\n]s", RespostaGeral);
					LimpaBuffer();
					system("cls");
					
					if(VerificaRespostaGeral(RespostaGeral, 1) == -2){
						retorno = -2;
						break;
					}

					printf("Palavra secreta: %s\n\n", Resposta);
					
					printf("(Jogador 3)Digite a palavra secreta:\n");
					scanf("%[^\n]s", RespostaGeral);
					LimpaBuffer();
					system("cls");
					
					if(VerificaRespostaGeral(RespostaGeral, 2) == -2){
						retorno = -2;
						break;
					}

					printf("Palavra secreta: %s\n\n", Resposta);
					
					printf("(Jogador 1)Digite a palavra secreta:\n");
					scanf("%[^\n]s", RespostaGeral);
					LimpaBuffer();
					system("cls");
					
					if(VerificaRespostaGeral(RespostaGeral, 0) == -2){
						retorno = -2;
						break;
					}
					
				}while(1);
				
				if(retorno == -2){
					retorno = 0;
					break;
				}
			}

			if(VidasJogadores[1] != 0){

				do{
					printf("Palavra secreta: %s\n\n", Resposta);
					printf("LETRAS USADAS: %s\n\n", LetrasArmazenadas);
					printf("***VIDAS DO JOGADOR 2: %d***\n\n", VidasJogadores[1]);
					printf("(Jogador 2)Digite sua escolha de letra:\n");
					scanf("%c", &letra);
					LimpaBuffer();
					system("cls");
				
				}while(ArmazenaLetra(letra, 1) == -1);
			}
			
			if(VerificaTamPalavra() <= 3){
				
				do{

					printf("Palavra secreta: %s\n\n", Resposta);
					
					printf("(Jogador 3)Digite a palavra secreta:\n");
					scanf("%[^\n]s", RespostaGeral);
					LimpaBuffer();
					system("cls");
					
					if(VerificaRespostaGeral(RespostaGeral, 2) == -2){
						retorno = -2;
						break;
					}
					
					printf("Palavra secreta: %s\n\n", Resposta);
					
					printf("(Jogador 1)Digite a palavra secreta:\n");
					scanf("%[^\n]s", RespostaGeral);
					LimpaBuffer();
					system("cls");
					
					if(VerificaRespostaGeral(RespostaGeral, 0) == -2){
						retorno = -2;
						break;
					}

					printf("Palavra secreta: %s\n\n", Resposta);
					
					printf("(Jogador 2)Digite a palavra secreta:\n");
					scanf("%[^\n]s", RespostaGeral);
					LimpaBuffer();
					system("cls");
					
					if(VerificaRespostaGeral(RespostaGeral, 1) == -2){
						retorno = -2;
						break;
					}
					
				}while(1);
				
				if(retorno == -2){
					retorno = 0;
					break;
				}
			}

			if(VidasJogadores[2] != 0){

				do{
					printf("Palavra secreta: %s\n\n", Resposta);
					printf("LETRAS USADAS: %s\n\n", LetrasArmazenadas);
					printf("***VIDAS DO JOGADOR 3: %d***\n\n", VidasJogadores[2]);
					printf("(Jogador 3)Digite sua escolha de letra:\n");
					scanf("%c", &letra);
					LimpaBuffer();
					system("cls");
				
				}while(ArmazenaLetra(letra, 2) == -1);
			}
			
			if(VerificaTamPalavra() <= 3){
				
				do{
					
					printf("Palavra secreta: %s\n\n", Resposta);
					
					printf("(Jogador 1)Digite a palavra secreta:\n");
					scanf("%[^\n]s", RespostaGeral);
					LimpaBuffer();
					system("cls");
					
					if(VerificaRespostaGeral(RespostaGeral, 0) == -2){
						retorno = -2;
						break;
					}

					printf("Palavra secreta: %s\n\n", Resposta);
					
					printf("(Jogador 2)Digite a palavra secreta:\n");
					scanf("%[^\n]s", RespostaGeral);
					LimpaBuffer();
					system("cls");
					
					if(VerificaRespostaGeral(RespostaGeral, 1) == -2){
						retorno = -2;
						break;
					}

					printf("(Jogador 3)Digite a palavra secreta:\n");
					scanf("%[^\n]s", RespostaGeral);
					LimpaBuffer();
					system("cls");
					
					if(VerificaRespostaGeral(RespostaGeral, 2) == -2){
						retorno = -2;
						break;
					}
					
				}while(1);
				
				if(retorno == -2){
					retorno = 0;
					break;
				}
			}
			
			if(VidasJogadores[0] == 0 && VidasJogadores[1] == 0 && VidasJogadores[2] == 0){
				printf("EMPATE!\n\n");
				printf("A palavra secreta era: %s", armazena);
				Sleep(1500);
				system("cls");
				break;
			}
			
		}while(1);
}

/****
 * Descri��o: Pega a palavra chave do jogo.
 *
 * Par�metros: Nenhum.
 *
 * Valor de retorno: Nenhum.
 *
 ****/

void PalavraChave(){
	FILE *Palavra;
	
	Palavra = fopen("PalavraChave.txt", "r");
	
	if(Palavra == NULL){
		printf("N�o foi poss�vel encontrar a palavra secreta! Tente novamente.");
		main();
	}
	
	while(fgets(armazena, 175, Palavra) != NULL);
	
	fclose(Palavra);
}

void Inicializa(){
	register int i;
	
	for(i = 0; i < 127; i++){
		
		Resposta[i] = '\0';
	}
	
	for(i = 0; i < strlen(armazena); i++){
		
		Resposta[i] = '_';
	}
	
	for(i = 0; i < 27; i++){
		
		LetrasArmazenadas[i] = '\0';
	}
}

void InicializaPontuacao(){
	int i;
	
	for(i = 0; i < 3; i++){
		
		pontuacao[i] = 0;
	}
}

/****
 * 
 * Descri��o: Armazena as letras selecionadas pelo usu�rio.
 *
 * Par�metros: letra - caracter que passa a letra a ser armazenada.
 *			   jogador - inteiro que passa a identifica��o do jogador.
 *
 * Valor de retorno: Inteiro que indica se a letra j� foi armazenada n�o permitindo que o usu�rio a jogue.
 *
 ****/

int ArmazenaLetra(char letra, int jogador){
	int i = 0;
	
	if(VerificaLetras(letra) == -1){
		printf("Essa letra j� usada! Digite uma letra diferente.");
		Sleep(1500);
		system("cls");
		
		return -1;
	}
	
	do{

		if(LetrasArmazenadas[i] == '\0'){
			
			LetrasArmazenadas[i] =  letra;
			VerificaResposta(letra, jogador);
			break;
		}
	
		i++;
		
	}while(i < 27);
	
}

/****
 *
 * Descri��o: Verifica se a letra j� foi armazenada.
 *
 * Par�metro: letra - caracter que indica a letra a ser armazenada.
 *
 * Valor de retorno: Inteiro que indica se a letra j� foi armazenada.
 *
 ****/

int VerificaLetras(char letra){
	register int i = 0;
	
	do{
		
		if(LetrasArmazenadas[i] == letra){
			return -1;
		}
	
		i++;
		
	}while(i < 27);
}

/****
 *
 * Descri��o: Verifica se a letra que o usu�rio passou corresponde a alguma letra da palavra oculta.
 *
 * P�rametros: letra - caracter que representa a letra passada pelo usu�rio.
 * 			   jogador - inteiro que identifica qual jogador fez a jogada.
 *
 * Valor de retorno: Nenhum.
 *
 ****/

void VerificaResposta(char letra, int jogador){
	register int i = 0;
	int contador = 0;
	
	while(armazena[i] != '\0'){
		
		if(armazena[i] == letra || armazena[i] == toupper(letra) || armazena[i] == tolower(letra)){
			
			Resposta[i] = armazena[i];
		}
		
		else{
			contador++;
		}
		
		i++;
	}
	
	if(contador == strlen(armazena)){
		
		VidasJogadores[jogador] -= 1;
	}
	
}

/****
 * 
 * Descri��o: Verifica o tamanho da palavra oculta e inicializa uma string com "_" representando os espa�os de cada letra da palavra secreta.
 *
 * Par�metros: Nenhum.
 *
 * Valor de retorno: Retorna um inteiro que indica quantas letras ainda faltam para que a palavra fique completa.
 *
 ****/

int VerificaTamPalavra(){
	int i = 0, contador = 0;
	
	while(i < strlen(armazena)){
		
		if(Resposta[i] == '_'){
			contador++;
		}
		
		i++;
	}
	
	return contador;
}

/****
 *
 * Descri��o: Verica a palavra fornecida pelo usu�rio (palavra completa) se corresponde a palavra oculta.
 *
 * Par�metros: RespostaGeral - String que representa a resposta do usu�rio.
 * 			   jogador - inteiro que identifica qual jogador realizou a jogada.
 *
 * Valor de retorno: Inteiro que indica se algum dos jogadores ganhou a partida.
 *
 ****/

int VerificaRespostaGeral(char *RespostaGeral, int jogador){
	int pontos = 60;
	
	if(jogador == 0){
		
		if(!stricmp(RespostaGeral, armazena)){
			
			printf("Jogador 1 � o vencedor!");
			pontuacao[jogador] += pontos;
			Sleep(1000);
			system("cls");
			return -2;
		}
	}
	
	else if(jogador == 1){
		
		if(!stricmp(RespostaGeral, armazena)){
			
			printf("Jogador 2 � o vencedor!");
			pontuacao[jogador] += pontos;
			Sleep(1000);
			system("cls");
			return -2;
		}
	}

	else if(jogador == 2){
		
		if(!stricmp(RespostaGeral, armazena)){
			
			printf("Jogador 3 � o vencedor!");
			pontuacao[jogador] += pontos;
			Sleep(1000);
			system("cls");
			return -2;
		}
	}
}

void LimpaBuffer(){
	char c;
	
	while(c = getchar() != '\n');
}
