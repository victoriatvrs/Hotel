//menu

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
//prototipo das funcoes
void fcriarmapa();
void fmostrarmapa();
void freserva();
void fcheckin();
void fclear();
void fcheckout();
//void fcancela();
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
	fmostrarmapa();
	
	do{
		printf("\n1. Fazer reserva\n");
		printf("2. Fazer check-in\n");
		printf("3. Fazer check-out\n");
		printf("4. Cancelar reserva\n");
		printf("5. Modo administrador\n");
		
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
		//	case 4:
				//fcancreserva();
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
				
		//sobrescrevendo!!!!!
		if((mat[andar - 1][apto - 1] != 'O') && (mat[andar - 1][apto - 1] != 'R'))
		{
			printf("Digite seu CPF: ");
			scanf("%s", &hospede[andar][apto].cpf);
			fclear();
			printf("\n");
			mat[andar-1][apto-1] = 'R';
			fmostrarmapa();
		}
		else
		{
			printf("\nQuarto indisponivel!\n");
		}
		
		//FIX: CHECAGEM DE NUMERO INVALIDO
		printf("\nGostaria de fazer outra reserva?\n");
		printf("1 - Sim\n");
		printf("2 - Nao\n");
		scanf("%d", &repeat);
		fclear();
		
	}while(repeat == 1);
}

void fcheckin()
{
	int reserva, vazio;
	int andar, apto;
	char checagem[11]; //apenas para checar se o cpf bate com a reserva
	
	printf("Possui reserva?\n");
	printf("1 - Sim\n");
	printf("2 - Nao\n");
	scanf("%d", &reserva);
	fclear();
	if(reserva == 1)
	{
		printf("Digite o andar e apartamento: ");
		scanf("%d %d", &andar, &apto);
		fclear();
		
		printf("\n\nDigite seu cpf: ");
		gets(checagem);
		fclear();
		
		if(checagem == hospede[andar][apto].cpf)
		{
			printf("\nCheck-in confirmado! Prossiga com seus dados.");
			printf("\nNome: ");
			gets(hospede[andar][apto].nome);
			fclear();
			printf("\nTelefone: ");
			gets(hospede[andar][apto].tel);
			fclear();
			printf("\nEmail: ");
			gets(hospede[andar][apto].email);
			fclear();
			printf("\nEndereco: ");
			gets(hospede[andar][apto].endereco.ender);
			fclear();
			printf("\nMunicipio: ");
			gets(hospede[andar][apto].endereco.munic);
			fclear();
			printf("\nEstado: ");
			gets(hospede[andar][apto].endereco.estado);
			fclear();
			printf("\nCEP: ");
			gets(hospede[andar][apto].endereco.cep);
			fclear();
			
			mat[andar][apto] == 'O';
		}
		else
		{
			printf("\nCadastro invalido! O quarto esta reservado.\n");
			printf("Gostaria de fazer check-in em um quarto vazio?\n");
			printf("1 - Sim\n");
			printf("2 - Nao\n");
			scanf("%d", &vazio);
			fclear();
			
			if(vazio == 1)
			{
				printf("\nDigite o numero do andar e apartamento: ");
				scanf("%d %d", &andar, &apto);
				fclear();
				if(mat[andar][apto] == 'R')
				{
					printf("Quarto nao disponivel.");
				}
				else
				{
					mat[andar][apto] = 'O';
				}
			}
		}
	}
	
	else
	{
		printf("Digite o andar e apartamento: ");
		scanf("%d %d", &andar, &apto);
		fclear();
		printf("\nProssiga com seus dados.");
		printf("\nNome: ");
		gets(hospede[andar][apto].nome);
		fclear();
		printf("\nTelefone: ");
		gets(hospede[andar][apto].tel);
		fclear();
		printf("\nEmail: ");
		gets(hospede[andar][apto].email);
		fclear();
		printf("\nEndereco: ");
		gets(hospede[andar][apto].endereco.ender);
		fclear();
		printf("\nMunicipio: ");
		gets(hospede[andar][apto].endereco.munic);
		fclear();
		printf("\nEstado: ");
		gets(hospede[andar][apto].endereco.estado);
		fclear();
		printf("\nCEP: ");
		gets(hospede[andar][apto].endereco.cep);
		fclear();
		
		mat[andar][apto] == 'O';
	}
}


void fcheckout()
{
	int andar, apto;
	
	printf("Digite o andar e apartamento: ");
	scanf("%d %d", &andar, &apto);
	fclear();
	
	mat[andar][apto] = '.';
	printf("\n\nQuarto liberado!\n\n");
	fmostrarmapa();
}
