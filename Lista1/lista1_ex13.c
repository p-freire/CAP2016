/*
  Objetivo: dado um valor N, 1 <= N <= 20, calcular e armazenar num
  vetor os N primeiros elementos da sequência de Fibonacci.
*/

#include <stdio.h>
#define MAX 20

int main(int argc, char **argv)
{
	int fibonacci[MAX], n, i;
	fibonacci[0] = 1;
	fibonacci[1] = 1;

	printf("Entre com o valor de 1 <= N <= 20: ");
	scanf("%d", &n);

	if(n < 1 || n > 20)
	{
		printf("Valor invalido!\n");
	}	
	else
	{
		for(i = 2; i < n; ++i)
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

		if(n == 1)
			printf("O primeiro elemento da sequencia de Fibonacci eh %d.\n", fibonacci[0]);
		else
		{
			printf("Os %d primeiros elementos da sequencia de Fibonacci sao: \n", n);
			for(i = 0; i < n; ++i)
				printf("%d ", fibonacci[i]);
			printf("\n");
		}
	}
	

	return 0;
}