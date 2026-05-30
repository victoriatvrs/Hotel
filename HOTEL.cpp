//ATV4
//mapa geral - 20 andares e 14 aptos
//fazer reserva
//fazer check in a partir de reserva
//fazer check in sem reserva - nunca em um ja reservado
//fazer check out
//cancelar uma reserva

//ATV5
//taxa de ocupacao
//taxa de reservas
//cadastrar info do hospede (cpf, nome, endereco, telefone e email)
//verificar as infos do hospede no apto

//reserva + dados
//bater check in e reserva

//ATV6
//apresentacao do projeto
//entrega da versao final
//relatorio/documentacao para leigos

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

//prototipo das funcoes
void fcriarmapa();
void fmostrarmapa();
void freserva();
void fcheckin();
void fclear();
void fcheckout();
void fcancreserva();
void fclear();

//variaveis globais
char mat[20][14];
int i, j;

typedef struct stendereco{
	char ender[40];
	char munic[20];
	char estado[3];
	char cep[10];
}stendereco;

typedef struct stdados{
	char cpf[11];
	char nome[50];
	struct stendereco endereco;
	char tel[15];
	char email[30]; 
}stdados;

struct stdados hospede[20][14];

int main()
{
	int op;
	
	fcriarmapa(); //tem que ser no main pra nao resetar
	
	do{
		system("cls");
		fmostrarmapa();
	
		printf("\n[1] Fazer reserva\n");
		printf("[2] Fazer check-in\n");
		printf("[3] Fazer check-out\n");
		printf("[4] Cancelar reserva\n");
		printf("[5] Modo administrador\n");

		printf("-----------------------\n");
		printf("Digite uma opcao: ");
		scanf("%d", &op);
		fclear();
		
		switch(op){
			case 1:
				freserva();
				break;
			case 2:
				fcheckin();
				break;
			case 3:
				fcheckout();
				break;
			case 4:
				fcancreserva();
				break;
		//	case 5:
				// modo de administrador p taxas e verificar info do cliente
		}
	}while(1);
}

void fclear()
{
	char car;
	while ((car = fgetc(stdin)) != EOF && car != '\n'){}
}

void fcriarmapa()
{
	// preencher matriz com '.'
    for(i = 19; i >= 0; i--)
    {
		for(j = 0; j < 14; j++)
		{
			mat[i][j] = '.';
		}
	}		
}

void fmostrarmapa()
{
	printf("     ");
	
	//printa coluna/apto
	for(j = 0; j < 14; j++)
	{
 		printf("%2d ", j+1);
	}
	
	printf("\n");
	
	//printa linha/andar 
	for(i = 19; i >= 0; i--)
	{
		printf("  %2d ", i+1);
		for(j = 0; j < 14; j++)
		{
			printf(" %c ", mat[i][j]);
    	}	
		printf("\n");
    }
}

void freserva()
{
	int andar, apto;
	int repeat;
	
	do{
		system("cls");		
		fmostrarmapa();

		// pedir coordenadas
		printf("\nDigite o numero do andar e apartamento: ");
		scanf("%d %d", &andar, &apto);
		fclear();
		
		// validar limites
		if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
		{
			printf("Coordenada invalida!\n");
			break;
		}
				
		if((mat[andar - 1][apto - 1] != 'O') && (mat[andar - 1][apto - 1] != 'R'))
		{
			printf("Digite seu CPF: ");
			scanf("%s", &hospede[andar-1][apto-1].cpf);
			fclear();
			printf("\n");
			mat[andar-1][apto-1] = 'R';
			system("cls");
			fmostrarmapa();
		}
		else
		{
			printf("\nQuarto indisponivel!\n");
		}
		
		printf("\nGostaria de fazer outra reserva?\n");
		printf("[1] Sim\n");
		printf("[2] Nao\n");
		printf("---------------------------------\n");
		printf("Digite uma opcao: ");
		scanf("%d", &repeat);
		if(repeat != 1 && repeat != 2)
		{
			printf("\nNumero invalido!");
			break;
		}
		fclear();
		
	}while(repeat == 1);
}

void fcheckin()
{
	int reserva, vazio;
	int andar, apto;
	char checagem[11]; //apenas para checar se o cpf bate com a reserva
	
	system("cls");
	fmostrarmapa();
	printf("\nPossui reserva?\n");
	printf("[1] Sim\n");
	printf("[2] Nao\n");
	printf("------------------\n");
	printf("Digite uma opcao: ");
	scanf("%d", &reserva);
	fclear();
	
	if(reserva == 1) //check in em quarto reservado
	{
		system("cls");
		fmostrarmapa();
		printf("\nDigite o andar e apartamento: ");
		scanf("%d %d", &andar, &apto);
		fclear();
		
		printf("\nDigite seu cpf: ");
		scanf("%11s", &checagem);
		fclear();
		
		if(strcmp(checagem, hospede[andar - 1][apto - 1].cpf) == 0)
		{
			printf("-----------------------------------------------");
			printf("\nCheck-in confirmado! Prossiga com seus dados.\n");
			
			printf("\nNome: ");
			scanf("%s", &hospede[andar - 1][apto - 1].nome);
			fclear();
			
			printf("\nTelefone: ");
			scanf("%s", &hospede[andar - 1][apto - 1].tel);
			fclear();
			
			printf("\nEmail: ");
			scanf("%s", &hospede[andar - 1][apto - 1].email);
			fclear();
			
			printf("\nEndereco: ");
			scanf("%s", &hospede[andar - 1][apto - 1].endereco.ender);
			fclear();
			
			printf("\nMunicipio: ");
			scanf("%s", &hospede[andar - 1][apto - 1].endereco.munic);
			fclear();
			
			printf("\nEstado: ");
			scanf("%s", &hospede[andar - 1][apto - 1].endereco.estado);
			fclear();
			
			printf("\nCEP: ");
			scanf("%s", &hospede[andar - 1][apto - 1].endereco.cep);
			fclear();
			
			mat[andar - 1][apto - 1] = 'O';
		}
		else //falha no check in em quarto reservado
		{
			printf("\nCadastro invalido! O quarto esta reservado.\n");
			printf("------------------------------------------------\n");
			printf("Gostaria de fazer check-in em um quarto vazio?\n");
			printf("[1] Sim\n");
			printf("[2] Nao\n");
			printf("-------------------\n");
			printf("Digite uma opcao: ");
			scanf("%d", &vazio);
			fclear();
			
			if(vazio == 1) //check in em quarto vazio
			{
				system("cls");
				fmostrarmapa();
				printf("\nDigite o numero do andar e apartamento: ");
				scanf("%d %d", &andar, &apto);
				fclear();
				if(mat[andar-1][apto-1] == 'R') //falha no check in em quarto reservado
				{
					printf("\nQuarto nao disponivel.\n");
					printf("----------------------\n\n");
					system("pause");
				}
				else //quarto nao reservado
				{
					printf("\nProssiga com seus dados.");
					printf("\n-------------------------");
					
					printf("\nNome: ");
					scanf("%s", &hospede[andar - 1][apto - 1].nome);
					fclear();
					
					printf("\nTelefone: ");
					scanf("%s", &hospede[andar - 1][apto - 1].tel);
					fclear();
					
					printf("\nEmail: ");
					scanf("%s", &hospede[andar - 1][apto - 1].email);
					fclear();
					
					printf("\nEndereco: ");
					scanf("%s", &hospede[andar - 1][apto - 1].endereco.ender);
					fclear();
				
					printf("\nMunicipio: ");
					scanf("%s", &hospede[andar - 1][apto - 1].endereco.munic);
					fclear();
					
					printf("\nEstado: ");
					scanf("%s", &hospede[andar - 1][apto - 1].endereco.estado);
					fclear();
				
					printf("\nCEP: ");
					scanf("%s", &hospede[andar - 1][apto - 1].endereco.cep);
					fclear();
					
					mat[andar-1][apto-1] = 'O';
					fmostrarmapa();
				}
			}
		}
	}
	else //check in em quarto nao reservado
	{
		system("cls");
		fmostrarmapa();
		printf("\nDigite o andar e apartamento: ");
		scanf("%d %d", &andar, &apto);
		fclear();
		
		printf("----------------------------------");
		printf("\nProssiga com seus dados.\n");
		
		printf("\nNome: ");
		scanf("%s", &hospede[andar-1][apto-1].nome);
		fclear();
		
		printf("\nCPF: ");
		scanf("%s", &hospede[andar-1][apto-1].cpf);
		fclear();
		
		printf("\nTelefone: ");
		scanf("%s", &hospede[andar-1][apto-1].tel);
		fclear();
		
		printf("\nEmail: ");
		scanf("%s", &hospede[andar-1][apto-1].email);
		fclear();
		
		printf("\nEndereco: ");
		scanf("%s", &hospede[andar-1][apto-1].endereco.ender);
		fclear();
		
		printf("\nMunicipio: ");
		scanf("%s", &hospede[andar-1][apto-1].endereco.munic);
		fclear();
		
		printf("\nEstado: ");
		scanf("%s", &hospede[andar-1][apto-1].endereco.estado);
		fclear();
		
		printf("\nCEP: ");
		scanf("%s", &hospede[andar-1][apto-1].endereco.cep);
		fclear();
		
		mat[andar-1][apto-1] = 'O';
	}
}

void fcheckout()
{
	int andar, apto;
	char checagem[11];
	
	system("cls");
	fmostrarmapa();
	printf("\nDigite o andar e apartamento: ");
	scanf("%d %d", &andar, &apto);
	fclear();
	
	if(mat[andar - 1][apto - 1] == 'O')
		{
			printf("Digite seu CPF para confirmar: ");
			scanf(" %11s", &checagem);
			printf("\n");
		
			if(strcmp(checagem, hospede[andar - 1][apto - 1].cpf) == 0)
			{
				fclear();
				system("cls");
				mat[andar-1][apto-1] = '.';
				fmostrarmapa();
				printf("\nQuarto liberado!\n");
				printf("----------------\n");
				system("pause");
			}
			else
			{
				printf("Nao foi possivel completar. Verifique o CPF.\n");
				printf("--------------------------------------------\n");
				system("pause");
			}
	}
	else
	{
		printf("\nO quarto nao esta ocupado. Verifique a digitacao.\n");
		printf("-------------------------------------------------\n");
		system("pause");
		
	}
}

void fcancreserva()
{
	int andar, apto;
	char checagem[11];
	
		// pedir coordenadas
		printf("\nDigite o numero do andar e apartamento: ");
		scanf("%d %d", &andar, &apto);
		fclear();
		
		// validar limites
		if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
		{
			printf("Coordenada invalida!\n");
		}
		
		if(mat[andar - 1][apto - 1] == 'R')
		{
			printf("Digite seu CPF para confirmar: ");
			scanf("%11s", &checagem);
			fclear();
			printf("\n");
		
			if(strcmp(checagem, hospede[andar - 1][apto - 1].cpf) == 0)
			{
				//ENTER????
				fclear();
				printf("\nReserva cancelada. \n");
				mat[andar-1][apto-1] = '.';
				fmostrarmapa();
			}
			else
			{
				printf("\nNao foi possivel cancelar. Verifique o CPF.\n");
			}
		}
}
