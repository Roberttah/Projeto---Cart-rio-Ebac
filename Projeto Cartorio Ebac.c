#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca para aloca��es de espa�os
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include <string.h>// biblioteca dos strings

int registrar() {
	
	char arquivo [40];//definindo as variav�is 
	char nome [20];
	char sobrenome [20];
	char cpf [11]; 
	char cargo [20];
	
	FILE *file; // Cria o arquivo no banco de dados 
	
	printf("Digite seu CPF para cadastro:"); //**Adicionar conferimento de cpf e limitar a quantidade de numeros escritos, adcionar o caractere "-"
	scanf("%s", cpf);
	
		strcpy(arquivo, cpf); // Copia os valores das strings
	
	
		file = fopen(arquivo, "w"); //"w" usado para iniciar a escrita dentro do arquivo
		fprintf(file, "\nCPF:");
		fprintf(file, cpf);
		fclose(file);
	
		file = fopen(arquivo, "a"); // "a" usado para atualizar informa��es dentro do arquivo criado utilizando o "w"
		fprintf(file, "\nNOME:");
		fclose(file);
	
	printf("Digite seu nome para cadastro:");
	scanf("%s", nome);
	
		file = fopen(arquivo, "a");
		fprintf(file, nome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file, " ");
		fclose(file);
	
	printf("Digite seu sobrenome para cadastro:");
	scanf("%s", sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file, "\nCARGO:");
		fclose(file);
	
	
	printf("Digite seu cargo para cadastro:"); //**Adicionar somente duas escolhas para o usuario, "professsor" ou "aluno"
	scanf("%s", cargo);
	
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fprintf(file, "\n\n");
		fclose(file);
	
	system("pause");
	
}

int consultar() {

	char cpf [11];
	char conteudo [200];

	setlocale(LC_ALL, "Portuguese");

		printf("Digite o CPF para consulta:");
		scanf("%s", cpf);

	FILE *file;
	file = fopen (cpf,"r");
	

	if (file == NULL)
{
		printf("Usu�rio n�o localizado.\n");
		system ("pause");
		return 0;
		
}
	
	printf("Essas s�o as informa��es do usu�rio cadastrado:\n");
			
	while (fgets(conteudo, 200, file)!= NULL)
{
		
		printf("%s", conteudo);
}

	fclose(file);
	system("pause");
}

int deletar() {

	char cpf[40];
	
	printf("Digite o cpf do aluno a ser deletado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	fclose(file);
	
	if (file == NULL) 
{
		printf("O CPF informado n�o foi encontrado no sistema!\n");
}
	
	else 
{
		(remove(cpf)==0);
		printf("Usu�rio deletado com sucesso!\n");
}
	
	system ("pause");	
}

int main () {
	int opcao =0;//variaveis definidas
	int repetir=1;

	for(repetir=1; repetir=1;) // Faz com que o menu sempre se repita ao chegar no final do programa
{

		system("cls");


		setlocale(LC_ALL, "Portuguese");//Linguagem utilizada

		printf( "\t##Cart�rio da EBAC## \n\n");//inicio do menu
		printf("Escolha a op��o desejada: \n\n");
		printf("\t1 Registrar nomes \n" );
		printf("\t2 Consultar nomes \n");
		printf("\t3 Deletar nomes \n \n");
		printf("Digite a op��o desejada:");//fim do menu

		scanf("%d", &opcao);//armazena a escolha do usuario

		system("cls");//"limpa" a tela apos a escolha do usu�rio

		switch(opcao) 
{
			case 1:
				registrar();
				break;// Encerra a opc�o do switch case

			case 2:
				consultar();
				break;

			case 3:
				deletar();
				break;

			default:// Utilizado para op��es que n�o tenham sido mapeadas
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;
		}

	}
}



