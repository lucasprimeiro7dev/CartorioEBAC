#include <stdio.h>  //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //função responsavel por cadastrar os usuarios no sistema
{
	//inicio da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//final da criação de variaveis/string
	
	printf("digite o cpf a ser cadastrado"); //coletando informação usuario
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy (arquivo, cpf); //responsavel por copiar os valores dos string
	
	FILE *file; // cria o arquivo
	file = fopen (arquivo, "w");// cria o arquivo e o "w" significa escrever
	fprintf (file,cpf);// salva o valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen (arquivo, "a");//cria arquivo
	fprintf(file,",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("digite o nome a ser cadastrado: ");//coletando informações do usuario
	scanf("%s", nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf (file,nome);//salva o valor da variavel
	fclose (file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf (file,",");//salva o valor da variavel
	fclose (file);//fecha o arquivo
	
	printf("digite o sobrenome a ser cadastrado: ");//coletando informações do usuario
	scanf("%s",sobrenome);//%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf (file,sobrenome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf (file,",");//salva o valor da variavel
	fclose (file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informações do usuario
	scanf ("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	system("pause");//
	
	 
}
int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf ("\nEssas são as informações do usuario: ");
		printf ("%s", conteudo);
		printf("\n\n");
		
	}

    system("pause");
	
}

int deletar()
{
    char cpf[40]; 
    
    printf("digite o CPF do usuario a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf ("O usuario não se encontra no sistema!.\n");
    	system ("pause");
	}
 
}

int main()
	{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
    	
        system ("cls"); //responsavel por limpar a tela
    	
	    setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
        printf ("### cartorio da EBAC ###\n\n"); //inicio do menu
        printf("Escolha a opcao desejada do menu:\n\n");
        printf("\t1 - registrar nome\n");
        printf("\t2 - consultar nomes\n");
        printf ("\t3 - deletar nomes\n"); 
	    printf("opção: ");//fim do menu
   
        scanf("%d", &opcao); //armazenando a escolha do usuario
    
        system ("cls"); //responsavel por limpar a tela
        
        switch (opcao) //inicio da sessão do menu
        {
          case 1:
          registro();//chamada das funções
          break;
         
          case 2:
          consulta();
          break;
        
          case 3:
          deletar();
          break;
            
          default:
          printf("essa opcao não está disponivel!\n");
    	  system ("pause");
    	  break;
        }//fim da sessão	
		
		}
		
    
       
}
