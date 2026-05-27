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

//variaveis globais
char mat[20][14];
int i, j;
struct stdados{
	//matriz 20x14 p guardar dados
};

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
		
		switch(op){
			case 1:
				freserva();
		//	case 2:
				//fcheckin();
		//	case 3:
				//fcheckout();
		//	case 4:
				//cancreserva();
		//	case 5:
				// modo de administrador p taxas e verificar info do cliente
		}
	}while((op > 5)  || (op > 1));
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
		
		// validar limites
		if(andar < 1 || andar > 20 || apto < 1 || apto > 14)
		{
			printf("Coordenada invalida!\n");
			break;
		}
	
		mat[andar-1][apto-1] = 'R';
		fmostrarmapa();
		
		//FIX: CHECAGEM DE NUMERO INVALIDO
		printf("\nGostaria de fazer outra reserva?\n");
		printf("1 - Sim\n");
		printf("2 - Nao\n");
		scanf("%d", &repeat);
		
	}while(repeat == 1);
}

void fcheckin()
{
	int reserva;
	printf("Possui reserva?\n");
	printf("1 - Sim\n");
	printf("2 - Nao\n");
	scanf("%d", &reserva);
	if(reserva == 1)
	{
		printf("Digite seus dados: ");
	}
}
