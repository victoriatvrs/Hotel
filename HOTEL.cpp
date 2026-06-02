//HSV-Ativ04 
//30/05/2026
//Hellen Araujo da Silva
//Samira Soares Carvalho 
//Victoria Spina Tavares
/*Um hotel possui 20 andares com 14 apartamentos por andar.
Conforme os hospedes v�o chegando, eles escolhem o apartamento desejado. 
Se estiver livre, o apartamento � alocado e o hospede faz o registro. 
Ao deixar o hotel, o hospede faz o check-out e libera o apartamento. 
O gerente tamb�m precisa saber quais apartamentos est�o livres e a taxa de ocupa��o do hotel.
*/

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

//prototipo das funcoes
void fcriarmapa();
void fmostrarmapa();
void freserva();
void fcheckin();
void fcheckout();
void fcancreserva();
void fclear();

//variaveis globais

//dados residenciais do hospede
typedef struct stendereco{
	char ender[40];
	char munic[20];
	char estado[3];
	char cep[10];
}stendereco;

//dados gerais do hospede
typedef struct stdados{
	char cpf[12];
	char nome[50];
	struct stendereco endereco;
	char tel[15];
	char email[30]; 
}stdados;

typedef struct sthotel{
	char status;
	struct stdados hospede;
}sthotel;

struct sthotel mat[20][14];
int i, j;

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
			mat[i][j].status = '.';
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
			printf(" %c ", mat[i][j].status);
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
			printf("\nCoordenada invalida!\n\n");
			system("pause");
			break;
		}
				
		if((mat[andar-1][apto-1].status != 'O') && (mat[andar-1][apto-1].status != 'R'))
		{
			printf("Digite seu CPF: ");
			scanf("%s", mat[andar-1][apto-1].hospede.cpf);
			fclear();
			printf("\n");
			mat[andar-1][apto-1].status = 'R';
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
	char checagem[12]; //apenas para checar se o cpf bate com a reserva
	
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
		
		// validar limites
		if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
		{
			printf("\nCoordenada invalida!\n\n");
			system("pause");
			return;
		}
		
		printf("\nDigite seu cpf: ");
		scanf("%11s", checagem);
		fclear();
		
		if(strcmp(checagem, mat[andar-1][apto-1].hospede.cpf) == 0) //checa se o cpf bate com o da reserva
		{
			printf("-----------------------------------------------");
			printf("\nCheck-in confirmado! Prossiga com seus dados.\n");
			
			printf("\nNome: ");
			scanf("%s", mat[andar-1][apto-1].hospede.nome);
			fclear();
			
			printf("\nTelefone: ");
			scanf("%s", mat[andar-1][apto-1].hospede.tel);
			fclear();
			
			printf("\nEmail: ");
			scanf("%s", mat[andar-1][apto-1].hospede.email);
			fclear();
			
			printf("\nEndereco: ");
			scanf("%s", mat[andar-1][apto-1].hospede.endereco.ender);
			fclear();
			
			printf("\nMunicipio: ");
			scanf("%s", mat[andar-1][apto-1].hospede.endereco.munic);
			fclear();
			
			printf("\nEstado: ");
			scanf("%s", mat[andar-1][apto-1].hospede.endereco.estado);
			fclear();
			
			printf("\nCEP: ");
			scanf("%s", mat[andar-1][apto-1].hospede.endereco.cep);
			fclear();
			
			mat[andar-1][apto-1].status = 'O'; //confirma o check in
		}
		else //cpf nao bate com o da reserva
		{
			printf("\nCadastro invalido!\n");
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
				
				// validar limites
				if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
				{
					printf("\nCoordenada invalida!\n\n");
					system("pause");
					return;
				}
		
				if(mat[andar-1][apto-1].status == 'R') //se o quarto estiver reservado ele para
				{
					printf("\nQuarto nao disponivel.\n");
					printf("----------------------\n\n");
					system("pause");
				}
				else //se o quarto nao estiver reservado, prossegue
				{
					printf("\nProssiga com seus dados.");
					printf("\n-------------------------");
					
					printf("\nNome: ");
					scanf("%s", mat[andar-1][apto-1].hospede.nome);
					fclear();
					
					printf("\nCPF: ");
					scanf("%s", mat[andar-1][apto-1].hospede.cpf);
					fclear();
					
					printf("\nTelefone: ");
					scanf("%s", mat[andar-1][apto-1].hospede.tel);
					fclear();
					
					printf("\nEmail: ");
					scanf("%s", mat[andar-1][apto-1].hospede.email);
					fclear();
					
					printf("\nEndereco: ");
					scanf("%s", mat[andar-1][apto-1].hospede.endereco.ender);
					fclear();
				
					printf("\nMunicipio: ");
					scanf("%s", mat[andar-1][apto-1].hospede.endereco.munic);
					fclear();
					
					printf("\nEstado: ");
					scanf("%s", mat[andar-1][apto-1].hospede.endereco.estado);
					fclear();
				
					printf("\nCEP: ");
					scanf("%s", mat[andar-1][apto-1].hospede.endereco.cep);
					fclear();
					
					mat[andar-1][apto-1].status = 'O'; //ocupa o quarto vazio
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
		
		// validar limites
		if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
		{
			printf("\nCoordenada invalida!\n\n");
			system("pause");
			return;
		}
		
		if(mat[andar-1][apto-1].status == 'R' || mat[andar-1][apto-1].status == 'O')
		{
			printf("\nImpossivel fazer check-in em um quarto reservado ou ocupado!\n");
			printf("------------------------------------------------------------\n");
			system("pause");
		}
		else
		{
			printf("----------------------------------");
			printf("\nProssiga com seus dados.\n");
			
			printf("\nNome: ");
			scanf("%s", mat[andar-1][apto-1].hospede.nome);
			fclear();
			
			printf("\nCPF: ");
			scanf("%s", mat[andar-1][apto-1].hospede.cpf);
			fclear();
			
			printf("\nTelefone: ");
			scanf("%s", mat[andar-1][apto-1].hospede.tel);
			fclear();
			
			printf("\nEmail: ");
			scanf("%s", mat[andar-1][apto-1].hospede.email);
			fclear();
			
			printf("\nEndereco: ");
			scanf("%s", mat[andar-1][apto-1].hospede.endereco.ender);
			fclear();
			
			printf("\nMunicipio: ");
			scanf("%s", mat[andar-1][apto-1].hospede.endereco.munic);
			fclear();
			
			printf("\nEstado: ");
			scanf("%s", mat[andar-1][apto-1].hospede.endereco.estado);
			fclear();
			
			printf("\nCEP: ");
			scanf("%s", mat[andar-1][apto-1].hospede.endereco.cep);
			fclear();
			
			mat[andar-1][apto-1].status = 'O';
		}
	}
}

void fcheckout()
{
	int andar, apto;
	char checagem[12];
	
	system("cls");
	fmostrarmapa();
	printf("\nDigite o andar e apartamento: ");
	scanf("%d %d", &andar, &apto);
	fclear();
	
	// validar limites
	if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
	{
		printf("\nCoordenada invalida!\n\n");
		system("pause");
		return;
	}
	
	if(mat[andar-1][apto-1].status == 'O')
		{
			printf("Digite seu CPF para confirmar: ");
			scanf(" %11s", checagem);
			printf("\n");
		
			if(strcmp(checagem, mat[andar-1][apto-1].hospede.cpf) == 0)
			{
				fclear();
				system("cls");
				mat[andar-1][apto-1].status = '.';
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
	char checagem[12];
	
		// pedir coordenadas
		printf("\nDigite o numero do andar e apartamento: ");
		scanf("%d %d", &andar, &apto);
		fclear();
		
		// validar limites
		if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
		{
			printf("Coordenada invalida!\n");
			system("pause");
			return;
		}
		
		if(mat[andar-1][apto-1].status == 'R')
		{
			printf("Digite seu CPF para confirmar: ");
			scanf(" %11s", checagem);
			fclear();
			printf("\n");
		
			if(strcmp(checagem, mat[andar-1][apto-1].hospede.cpf) == 0)
			{
				system("cls");
				fmostrarmapa();
				printf("\nReserva cancelada.\n\n");
				mat[andar-1][apto-1].status = '.';
				system("pause");
			}
			else
			{
				system("cls");
				printf("\nNao foi possivel cancelar. Verifique o CPF.\n");
				system("pause");
			}
		}
		else
		{
			system("cls");
			fmostrarmapa();
			printf("\nO quarto nao esta reservado!\n\n");
			system("pause");
		}
}
