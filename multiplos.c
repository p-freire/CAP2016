/*
 Objetivo: ler um intervalo (dois valores), dois números A e B e
 imprimir todos os números do intervalo que são múltiplos ao
 mesmo tempo de A e B.
 Feito usando o cálculo do MMC entre A e B.

 Ainda faltam verificações nos inputs do usuário.
*/

#include <stdio.h>

// Calcula o MMC de dois números
int mmc(int a, int b)
{
	int contador, minimo;
	contador = 2;
	minimo = 1;

	while(a != 1 || b != 1)
	{
		if((a % contador == 0 && b % contador == 0)
			|| (a % contador == 0)
			|| (b % contador == 0))
		{
			minimo *= contador;
			a = a % contador == 0 ? a / contador : a; // atualiza o valor de A caso ele seja divisível pelo contador
			b = b % contador == 0 ? b / contador : b; // atualiza o valor de B caso ele seja divisível pelo contador
		}
		else
			++contador; // só incrementa quando não houver divisão inteira em nenhum caso
	}
	return minimo; // retorna o mínimo múltiplo comum encontrado
}

int main(int argc, char **argv)
{
	int i, intervalo_a, intervalo_b, multiplo_a, multiplo_b, incremento;
	
	printf("Entre com o intervalo: ");
	scanf("%d %d", &intervalo_a, &intervalo_b);
	
	// Verificação para garantir que intervalo_a seja o limite inferior
	// e intervalo_b seja o limite superior
	if(intervalo_a > intervalo_b)
	{
		int temp = intervalo_a;
		intervalo_a = intervalo_b;
		intervalo_b = temp;
	}
	
	printf("Entre com os multiplos desejados: ");
	scanf("%d %d", &multiplo_a, &multiplo_b);

	incremento = mmc(multiplo_a, multiplo_b); // encontra o MMC que vai servir de incremento
	
	// Acha o menor valor dentro do intervalo que atende os critérios de multiplicidade
	i = 0;
	while(i < intervalo_a)
		i += incremento;
	//for(i = 0; i < intervalo_a; i += incremento); // outra forma equivalente de fazer a mesma coisa acima
	
	// Imprime o resto dos números usando um incremento simples
	while(i <= intervalo_b)
	{
		printf("%d \n", i);
		i += incremento;
	}

	return 0;
}