//HSV-*****************
//22/06/2026
//Hellen Araujo da Silva
//Samira Soares Carvalho 
//Victoria Spina Tavares
/*Um hotel possui 20 andares com 14 apartamentos por andar.
Conforme os hospedes vao chegando, eles escolhem o apartamento desejado. 
Se estiver livre, o apartamento e alocado e o hospede faz o registro. 
Ao deixar o hotel, o hospede faz o check-out e libera o apartamento. 
O gerente tamb�m precisa saber quais apartamentos est�o livres e a taxa de ocupacao do hotel.
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
void faltreserva();
void fadmin();
void fclear();

//variaveis globais

//dados residenciais do hospede
typedef struct stendereco{
	char ender[40];
	char munic[20];
	char estado[20];
	char cep[15];
}stendereco;

//dados gerais do hospede
typedef struct stdados{
	char cpf[20];
	char nome[50];
	struct stendereco endereco;
	char tel[20];
	char email[40]; 
}stdados;

typedef struct sthotel{
	char status;
	struct stdados hospede;
}sthotel;

struct sthotel mat[20][14];
int i, j;
int ocupados = 0, reservados = 0;

int main()
{
	int op;
	
	fcriarmapa(); //main pra evitar reset
	
	do{
		system("cls");
		fmostrarmapa();
	
		printf("\n| MENU\n");
		printf("\n[1] Fazer reserva\n");
		printf("[2] Fazer check-in\n");
		printf("[3] Fazer check-out\n");
		printf("[4] Alterar reserva\n");
		printf("[5] Modo administrador (situacao do apartamento, taxas de reserva e ocupacao)\n");
		printf("[0] Sair\n");

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
				faltreserva();
				break;
			case 5:
				fadmin();
				break;
			case 0:
				break;
		}
	}while(op != 0);
}

void fclear() //limpar o buffer do teclado
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
		printf("\n| RESERVA\n");

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
			
		//checa se nao esta ocupado ou reservado	
		if((mat[andar-1][apto-1].status != 'O') && (mat[andar-1][apto-1].status != 'R'))
		{
			printf("Digite seu CPF: ");
			scanf("%s", mat[andar-1][apto-1].hospede.cpf);
			fclear();
			printf("\n");
			mat[andar-1][apto-1].status = 'R';
			system("cls");
			fmostrarmapa();
			printf("\n| RESERVA\n");
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
	char checagem[20]; //apenas para checar se o cpf bate com a reserva
	
	system("cls");
	fmostrarmapa();
	printf("\n| CHECK-IN\n");
	printf("\nPossui reserva?\n");
	printf("[1] Sim\n");
	printf("[2] Nao\n");
	printf("------------------\n");
	printf("Digite uma opcao: ");
	scanf("%d", &reserva);
	fclear();
	
	//check in em quarto reservado
	if(reserva == 1) 
	{
		system("cls");
		fmostrarmapa();
		printf("\n| CHECK-IN\n");
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
		scanf("%19s", checagem);
		fclear();
		
		//checa se o cpf bate com o da reserva
		if(strcmp(checagem, mat[andar-1][apto-1].hospede.cpf) == 0 && mat[andar-1][apto-1].status != 'O')
		{
			printf("-----------------------------------------------");
			printf("\nCheck-in confirmado! Prossiga com seus dados.\n");
			
			printf("\nNome: ");
			fgets(mat[andar-1][apto-1].hospede.nome, 50, stdin);
			mat[andar-1][apto-1].hospede.nome[strcspn(mat[andar-1][apto-1].hospede.nome, "\n")] = '\0';
			
			printf("\nTelefone: ");
			fgets(mat[andar-1][apto-1].hospede.tel, 20, stdin);
			mat[andar-1][apto-1].hospede.tel[strcspn(mat[andar-1][apto-1].hospede.tel, "\n")] = '\0';
					
			printf("\nEmail: ");
			scanf("%s", mat[andar-1][apto-1].hospede.email);
			fclear();
			
			printf("\nEndereco: ");
			fgets(mat[andar-1][apto-1].hospede.endereco.ender, 40, stdin);
			mat[andar-1][apto-1].hospede.endereco.ender[strcspn(mat[andar-1][apto-1].hospede.endereco.ender, "\n")] = '\0';
			
			printf("\nMunicipio: ");
			fgets(mat[andar-1][apto-1].hospede.endereco.munic, 20, stdin);
			mat[andar-1][apto-1].hospede.endereco.munic[strcspn(mat[andar-1][apto-1].hospede.endereco.munic, "\n")] = '\0';
			
			printf("\nEstado: ");
			fgets(mat[andar-1][apto-1].hospede.endereco.estado, 20, stdin);
			mat[andar-1][apto-1].hospede.endereco.estado[strcspn(mat[andar-1][apto-1].hospede.endereco.estado, "\n")] = '\0';
			
			printf("\nCEP: ");
			scanf("%s", mat[andar-1][apto-1].hospede.endereco.cep);
			fclear();
			
			mat[andar-1][apto-1].status = 'O'; //confirma o check in
		}
		else //cpf nao bate com o da reserva
		{
			printf("\nCadastro invalido!\n");
			printf("------------------------------------------------\n");
			printf("Gostaria de fazer check-in em outro apartamento?\n");
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
				printf("\n| CHECK-IN\n");
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
		
				if(mat[andar-1][apto-1].status == 'R') //quarto reservado
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
					fgets(mat[andar-1][apto-1].hospede.nome, 50, stdin);
					mat[andar-1][apto-1].hospede.nome[strcspn(mat[andar-1][apto-1].hospede.nome, "\n")] = '\0';
					
					printf("\nCPF: ");
					scanf("%s", mat[andar-1][apto-1].hospede.cpf);
					fclear();
					
					printf("\nTelefone: ");
					fgets(mat[andar-1][apto-1].hospede.tel, 20, stdin);
					mat[andar-1][apto-1].hospede.tel[strcspn(mat[andar-1][apto-1].hospede.tel, "\n")] = '\0';
					
					printf("\nEmail: ");
					scanf("%s", mat[andar-1][apto-1].hospede.email);
					fclear();
					
					printf("\nEndereco: ");
					fgets(mat[andar-1][apto-1].hospede.endereco.ender, 40, stdin);
					mat[andar-1][apto-1].hospede.endereco.ender[strcspn(mat[andar-1][apto-1].hospede.endereco.ender, "\n")] = '\0';
				
					printf("\nMunicipio: ");
					fgets(mat[andar-1][apto-1].hospede.endereco.munic, 20, stdin);
					mat[andar-1][apto-1].hospede.endereco.munic[strcspn(mat[andar-1][apto-1].hospede.endereco.munic, "\n")] = '\0';
					
					printf("\nEstado: ");
					fgets(mat[andar-1][apto-1].hospede.endereco.estado, 20, stdin);
					mat[andar-1][apto-1].hospede.endereco.estado[strcspn(mat[andar-1][apto-1].hospede.endereco.estado, "\n")] = '\0';
				
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
		printf("\n| CHECK-IN\n");
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
		
		// nega check in em quarto reservado ou ocupado
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
			fgets(mat[andar-1][apto-1].hospede.nome, 50, stdin);
			mat[andar-1][apto-1].hospede.nome[strcspn(mat[andar-1][apto-1].hospede.nome, "\n")] = '\0';
			
			printf("\nCPF: ");
			scanf("%s", mat[andar-1][apto-1].hospede.cpf);
			fclear();
			
			printf("\nTelefone: ");
			fgets(mat[andar-1][apto-1].hospede.tel, 20, stdin);
			mat[andar-1][apto-1].hospede.tel[strcspn(mat[andar-1][apto-1].hospede.tel, "\n")] = '\0';
			
			printf("\nEmail: ");
			scanf("%s", mat[andar-1][apto-1].hospede.email);
			fclear();
			
			printf("\nEndereco: ");
			fgets(mat[andar-1][apto-1].hospede.endereco.ender, 40, stdin);
			mat[andar-1][apto-1].hospede.endereco.ender[strcspn(mat[andar-1][apto-1].hospede.endereco.ender, "\n")] = '\0';
			
			printf("\nMunicipio: ");
			fgets(mat[andar-1][apto-1].hospede.endereco.munic, 20, stdin);
			mat[andar-1][apto-1].hospede.endereco.munic[strcspn(mat[andar-1][apto-1].hospede.endereco.munic, "\n")] = '\0';
			
			printf("\nEstado: ");
			fgets(mat[andar-1][apto-1].hospede.endereco.estado, 20, stdin);
			mat[andar-1][apto-1].hospede.endereco.estado[strcspn(mat[andar-1][apto-1].hospede.endereco.estado, "\n")] = '\0';
			
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
	char checagem[20];
	
	system("cls");
	fmostrarmapa();
	printf("\n| CHECK-OUT\n");
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
	
	// so executa com quarto ocupado
	if(mat[andar-1][apto-1].status == 'O')
		{
			printf("Digite seu CPF para confirmar: ");
			scanf(" %19s", checagem);
			printf("\n");
		
			if(strcmp(checagem, mat[andar-1][apto-1].hospede.cpf) == 0)
			{
				fclear();
				system("cls");
				mat[andar-1][apto-1].status = '.';
				fmostrarmapa();
				printf("\n| CHECK-OUT\n");
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

void faltreserva()
{
	int andar, apto, andar2, apto2;
	char checagem[20];
	int op;
	
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
		
		//so executa com quarto reservado
		if(mat[andar-1][apto-1].status == 'R')
		{
			printf("Digite seu CPF para confirmar: ");
			scanf(" %19s", checagem);
			fclear();
			printf("\n");
		
			if(strcmp(checagem, mat[andar-1][apto-1].hospede.cpf) == 0)
			{
				system("cls");
				fmostrarmapa();
				printf("\n| ALTERAR RESERVA\n");
				printf("\nSelecione uma opcao:\n");
				printf("[1] Cancelar\n");
				printf("[2] Alterar\n\n");
				scanf("%d", &op);
				if(op == 1){
						printf("\nReserva cancelada.\n\n");
						mat[andar-1][apto-1].status = '.';
				}
				else{
						printf("\nDigite o novo numero do andar e apartamento: ");
						scanf("%d %d", &andar2, &apto2);
						if(mat[andar2-1][apto2-1].status == '.')
						{
							printf("\nMudanca de reserva confirmada.\n\n");
							mat[andar-1][apto-1].status = '.';
							mat[andar2-1][apto2-1].status = 'R';
							strcpy(mat[andar2-1][apto2-1].hospede.cpf, mat[andar-1][apto-1].hospede.cpf);
						}
						else
						{
							printf("\nQuarto ja reservado ou ocupado!\n\n");
						}
		 	}
				system("pause");
			}
			else
			{
				system("cls");
				fmostrarmapa();
				printf("\n| ALTERAR RESERVA\n");
				printf("\nNao foi possivel alterar. Verifique o CPF.\n");
				system("pause");
			}
		}
		else
		{
			system("cls");
			fmostrarmapa();
			printf("\n| ALTERAR RESERVA\n");
			printf("\nO quarto nao esta reservado!\n\n");
			system("pause");
		}
}

void fadmin()
{
	int andar, apto;
	int op2; 
	float taxaO, taxaR;
	
	do{
		system("cls");
		printf("\n| MODO ADMINISTRADOR\n");
		printf("\n[1] Taxa de ocupacao\n");
		printf("[2] Taxa de reserva\n");
		printf("[3] Situacao do apartamento\n");
		printf("[4] Limpar o sistema\n");
		printf("[5] Retornar ao menu\n");

		printf("-----------------------\n");
		printf("Digite uma opcao: ");
		scanf("%d", &op2);
		printf("\n");
		fclear();
		
		switch(op2){
			case 1:
				//taxa de ocupacao
				ocupados = 0;
				
				//conta os quartos ocupados
				for(i = 0; i < 20; i++)
				{
				    for(j = 0; j < 14; j++)
				    {
				        if(mat[i][j].status == 'O')
				        {
    				        ocupados++;
        				}
    				}
				}
				
				taxaO = (ocupados*100.0)/280;
				printf("\nA taxa de ocupacao atual do hotel e de %.2f%%\n\n", taxaO);
				system("pause");
				break;
				
			case 2:
				 //taxa de reserva
				 reservados = 0;
				 
				 //conta os quartos reservados
				 for(i = 0; i < 20; i++)
				 {
				 	for(j = 0; j < 14; j++)
				 	{
				 		if(mat[i][j].status == 'R')
				 		{
				 			reservados++;
				 		}
				 	}
				 }
				 
				 taxaR = (reservados*100.0)/280;
				 printf("\nA taxa de reservas atual do hotel e de %.2f%%\n\n", taxaR);
				 system("pause");
				 break;
				
			case 3:
				//situacao do apto
				printf("Digite o andar e o apartamento: ");
				scanf("%d %d", &andar, &apto);
				printf("\n");
				
				
				if(mat[andar-1][apto-1].status == 'O')
				{
					printf("Quarto ocupado. Informacoes do hospede:");
				
					printf("\n\nNome: %s", mat[andar-1][apto-1].hospede.nome);
					printf("\nCPF: %s", mat[andar-1][apto-1].hospede.cpf);
					printf("\nTelefone: %s", mat[andar-1][apto-1].hospede.tel);
					printf("\nEmail: %s", mat[andar-1][apto-1].hospede.email);
					printf("\nEndereco: %s", mat[andar-1][apto-1].hospede.endereco.ender);
					printf("\nMunicipio: %s", mat[andar-1][apto-1].hospede.endereco.munic);
					printf("\nEstado: %s", mat[andar-1][apto-1].hospede.endereco.estado);
					printf("\nCEP: %s\n", mat[andar-1][apto-1].hospede.endereco.cep);
					printf("-----------------------------------------\n");
					system("pause");
				}
				if(mat[andar-1][apto-1].status == 'R')
				{
					printf("Quarto reservado. Informacoes do hospede:");
					
					printf("\n\nCPF: %s\n", mat[andar-1][apto-1].hospede.cpf);
					printf("-------------------------------------------\n");
					system("pause");
				}
				if(mat[andar-1][apto-1].status == '.')
				{
					printf("O quarto nao esta reservado ou ocupado.\n");
					printf("----------------------------------------\n");
					system("pause");
				}
				break;
				
			case 4:
				//zera todos os dados da matriz na mem�ria 
				memset(mat, 0, sizeof(mat));
				
				fcriarmapa();
				
				printf("Sistema resetado com sucesso!\n");
				printf("----------------------------------------\n");
				system("pause");
				
				return;
				break;
				
			case 5:
				return;
				break;
		}

	}while(op2 != 5);
}
