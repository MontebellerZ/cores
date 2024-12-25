/* 
	---------------------------------------------------------------
	O �ndice do Programa se encontra ao fim do mesmo afim de evitar
	que cada nova linha no �ndice altere a localiza��o dos itens.
	---------------------------------------------------------------
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>




//Testa se o sistema que est� rodando o programa � o Windows
#if defined(_WIN32) || defined(_WIN64)
	#define OS_Windows
#endif

//Utiliza a fun��o para a limpar a tela de acordo com o sistema que o programa est� rodando
void clear(){
	#ifdef OS_Windows
		system("cls"); //Caso Windows
	#else
		system("clear"); //Caso Unix
	#endif
}

//Personaliza o texto
/*
Type:
	0: none
	1: bold
	2: underline
	
Background:
	0: none
	1: regular
	
Intense:
	0: none
	1: intense text
	2: intense background
	3: intense both
	
t_color e b_color:
	"" (regular)
	"black"
	"red"
	"green"
	"yellow"
	"blue"
	"purple"
	"cyan"
	"white"
*/
void style(int intense, char t_color[], char b_color[], char text[]){
	int n_t_cor, n_b_cor;
	
	//Muda a cor do texto
	if(t_color!=""){
		if(t_color=="black"){
			n_t_cor=30;
		}
		else if(t_color=="red"){
			n_t_cor=31;
		}
		else if(t_color=="green"){
			n_t_cor=32;
		}
		else if(t_color=="yellow"){
			n_t_cor=33;
		}
		else if(t_color=="blue"){
			n_t_cor=34;
		}
		else if(t_color=="purple"){
			n_t_cor=35;
		}
		else if(t_color=="cyan"){
			n_t_cor=36;
		}
		else if(t_color=="white"){
			n_t_cor=37;
		}
		else{
			n_t_cor=0;
		}
	}
		
	//Muda a cor do fundo
	if(b_color!=""){
		if(b_color=="black"){
			n_b_cor=40;
		}
		else if(b_color=="red"){
			n_b_cor=41;
		}
		else if(b_color=="green"){
			n_b_cor=42;
		}
		else if(b_color=="yellow"){
			n_b_cor=43;
		}
		else if(b_color=="blue"){
			n_b_cor=44;
		}
		else if(b_color=="purple"){
			n_b_cor=45;
		}
		else if(b_color=="cyan"){
			n_b_cor=46;
		}
		else if(b_color=="white"){
			n_b_cor=47;
		}
		else{
			n_b_cor=0;
		}
	}
		
	//Muda a intensidade
	if(t_color!=""){
		if(intense==1||intense==3){
			n_t_cor+=60;
		}
	}
	if(b_color!=""){
		if(intense==2||intense==3){
			n_b_cor+=60;
		}
	}
	
	//Escreve o resultado
	printf("\033[%i;%im%s\033[0m", n_b_cor, n_t_cor, text);
}

int main(){
	//Declara��o de vari�veis
	int i;
	char nome[50], frase[200]="Bem vindo, ";
	
	clear();
	
	//L� a inser��o do nome do usu�rio
	printf("Insira seu nome (sem acentuacao): ");
	scanf("%[^\n]%*c", nome); //Recebe o valor at� que se pule uma linha (Enter)
	
	//Transforma a primeira letra de cada palavra em mai�scula.
	for(i=0; nome[i]!='\0'; i++){
		if(i==0 && nome[i]>='a' && nome[i]<='z'){ //Testa se o primeiro caractere � uma letra min�scula
			nome[i]=nome[i]-32; //Transforma para mai�scula
		}
		else if(nome[i]>='A' && nome[i]<='Z'){ //Testa se cada um dos caracteres seguintes � letra mai�scula
			nome[i]=nome[i]+32; //Transforma para min�scula
		}
		else if(nome[i]==' '){ //Testa se o caractere � um espa�o em branco
			i++;
			if(nome[i]>='a' && nome[i]<='z'){ //Testa se o primeiro caractere � uma letra min�scula
				nome[i]=nome[i]-32; //Transforma para mai�scula
			}
		}
	}
	
	clear();
	
	//Apresenta��o
	strcat(frase, nome);
	style(2,"black","red",frase);
	
	getch();
	
	return 0;
}
