#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int consulta()
{
	 setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	 
	 //início criação de variáveis/strings
	char cpf [40];
	char conteudo[200];
	//fim criação de variáveis/strings
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf);
	
	FILE *file; //acessando arquivo
	file = fopen(cpf,"r"); //lendo arquivo
	
	if(file == NULL) //"se o arquivo for nulo"
	{
		printf("O arquivo não foi encontrado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s,", conteudo); //colando as informações do usuário
		printf("\n\n"); //pulando duas linhas
	}
	
	system("pause"); //pausa o sistema
	
}

int registro() //função reponsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável
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
	fprintf(file,","); //adiciona uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,sobrenome); //salva o sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,","); //adiciona uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,cargo); //salva o cargo
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema
	
}

int deletar() //função reponsável por deletar os usuários da base de dados do sistema
{
	char cpf[40]; //criação da string
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf); //deletando usuário
	
	FILE *file; //acessando arquivo
	file = fopen(cpf, "r"); //lendo o arquivo
	
	if(file == NULL) //"se o arquivo for nulo"
	{
		printf("O usuário não se encontra mais no sistema!.\n");
		system("pause"); //pausa o sistema
	}
	
	
}

int main ()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		printf("\t* Cadastro de usuários * \n\n"); //início do menu
	    printf("Escolha uma das opções abaixo:\n\n");
	    printf("\t1 - Consultar cadastro\n");
	    printf("\t2 - Adicionar usuário\n");
	    printf("\t3 - Excluir usuário\n\n");
	    printf("Opção: "); //final do menu
	
	    scanf("%d",  &opcao); //armazenando a escolha do usuário
	
	    system("cls"); //responsável por limpar a tela
	    
	    switch(opcao) //início da seleção do menu
	    {
	    	case 1:
	    	consulta(); //chamada de funções
	    	break; //pausa
	    	
	    	case 2:
	    	registro(); //chamada de funções
	 	    break; //pausa
	 	    
	 	    case 3:
	 	    deletar(); //chamada de funções
	        break; //pausa
	        
	        default: //"se for nulo"
	        printf("Esta opção não está disponível!\n");
	        system("pause"); //pausa sistema
	 	    break; //pausa
		} //fim da seleção do menu
    } 
}
