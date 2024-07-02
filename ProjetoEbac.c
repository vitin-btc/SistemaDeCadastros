#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int consulta()
{
	 setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	 
	 //in�cio cria��o de vari�veis/strings
	char cpf [40];
	char conteudo[200];
	//fim cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	FILE *file; //acessando arquivo
	file = fopen(cpf,"r"); //lendo arquivo
	
	if(file == NULL) //"se o arquivo for nulo"
	{
		printf("O arquivo n�o foi encontrado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s,", conteudo); //colando as informa��es do usu�rio
		printf("\n\n"); //pulando duas linhas
	}
	
	system("pause"); //pausa o sistema
	
}

int registro() //fun��o repons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" significa atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,nome); //salva o nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,","); //adiciona uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,sobrenome); //salva o sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,","); //adiciona uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,cargo); //salva o cargo
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema
	
}

int deletar() //fun��o repons�vel por deletar os usu�rios da base de dados do sistema
{
	char cpf[40]; //cria��o da string
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //deletando usu�rio
	
	FILE *file; //acessando arquivo
	file = fopen(cpf, "r"); //lendo o arquivo
	
	if(file == NULL) //"se o arquivo for nulo"
	{
		printf("O usu�rio n�o se encontra mais no sistema!.\n");
		system("pause"); //pausa o sistema
	}
	
	
}

int main ()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		printf("\t* Cadastro de usu�rios * \n\n"); //in�cio do menu
	    printf("Escolha uma das op��es abaixo:\n\n");
	    printf("\t1 - Consultar cadastro\n");
	    printf("\t2 - Adicionar usu�rio\n");
	    printf("\t3 - Excluir usu�rio\n\n");
	    printf("Op��o: "); //final do menu
	
	    scanf("%d",  &opcao); //armazenando a escolha do usu�rio
	
	    system("cls"); //respons�vel por limpar a tela
	    
	    switch(opcao) //in�cio da sele��o do menu
	    {
	    	case 1:
	    	consulta(); //chamada de fun��es
	    	break; //pausa
	    	
	    	case 2:
	    	registro(); //chamada de fun��es
	 	    break; //pausa
	 	    
	 	    case 3:
	 	    deletar(); //chamada de fun��es
	        break; //pausa
	        
	        default: //"se for nulo"
	        printf("Esta op��o n�o est� dispon�vel!\n");
	        system("pause"); //pausa sistema
	 	    break; //pausa
		} //fim da sele��o do menu
    } 
}
