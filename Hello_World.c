#include <stdio.h>  //Biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Blibioteca de aloca��es de texto por regi�o 
#include <string.h> //Blibioteca respons�vel por cuidar das string

int resgistro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Reeponsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
	system("pause");	

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
		system("pause");
		return; // return; // Adicionado o return para evitar continuar a execu��o do c�digo
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");


}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
		
}



int main()
	{
		setlocale(LC_ALL, "Portuguese");
	int opcao=0; //Definindo as vari�veis	
	int laco=1;	
	char login[30]="b";
	char senhadigitada[20]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("\nLogin de administrador !\nDigite  seu login: \n\n");
	scanf("%s" ,login);
	printf("\n\nLogin de administrador !\nDigite a sua senha: \n\n");
	scanf("%s", senhadigitada);
	
	if(strcmp(login, "admin1") == 0) //usei o comando strcmp que � diferente do curso por conta dos limites do array (li sobre em uma corre��o do meu codigo)
	{
 
		comparacao = strcmp(senhadigitada, "admin");
		
		if (comparacao == 0)
		
		{
	
			system ("cls");
			for (laco = 1; laco != 0; )
			{
			
				system("cls");		
		
				setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem 
	
				printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
				printf("Escolha a op��o desejada do menu:\n\n");
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n\n"); 
				printf("\t4 - sair do sistema\n\n");
				printf("Op��o: "); //Fim do menu 

				scanf("%d", &opcao); //Armazenando a escolha do Usu�rio
	
					system("cls");
		
				switch(opcao)
				{
					case 1:
					resgistro();
					break;
					
					case 2:
					consulta();
					break;
			
					case 3:
					deletar();
					break;
				
					case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;
				
					default:
					printf("Essa op��o n�o est� disponivel!\n");
					system("pause");
					break;
			
				} //fim da sele��o
			}
 	
		}
			else
				printf("Senha incorreta");
				
	}
		else
				printf("login incorreto");					
}
