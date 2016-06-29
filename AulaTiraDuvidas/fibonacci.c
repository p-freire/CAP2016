/*
   Objetivo: calcular o n-esimo elemento da sequencia de Fibonacci E armazear os elementos da
   sequencia ate N e exibi-los depois.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib_recursivo(int n, int *vetor)
{
	if(n == 0)
	{
		vetor[0] = 1;
		return 1;
	}
	else if(n == 1)
	{
		vetor[1] = 1;
		vetor[0] = 1;
		return 1;
	}
	else
	{
		vetor[n] = fib_recursivo(n - 1, vetor) + fib_recursivo(n - 2, vetor);
		return vetor[n];
	}
}

int fib_iterativo(int n, int *vetor)
{
	vetor[0] = 1;
	if(n >= 1)
	{
		vetor[1] = 1;
		if(n > 1)
		{
			int i = 2;
			while(i <= n)
			{
				vetor[i] = vetor[i - 1] + vetor[i - 2];
				++i;
			}
		}
	}

	return vetor[n];
}

int main()
{
	int *v, n, i;
	printf("Entre com o tamanho da sequencia: ");
	scanf("%d", &n);

	if((v = (int*)malloc(n * sizeof(int))) == NULL)
		return -1;

	memset(v, 0, n * sizeof(int)); // zera o vetor

	printf("Sequencia inicial: \n");
	for(i = 0; i < n; ++i)
		printf("%d ", v[i]);
	printf("\n");

	printf("[RECURSIVO] Fib(%d) = %d\n", n, fib_recursivo(n - 1, v));

	printf("Sequencia final: \n");
	for(i = 0; i < n; ++i)
		printf("%d ", v[i]);
	printf("\n");

	memset(v, 0, n * sizeof(int)); // zera o vetor

	printf("\nZerando a sequencia novamente: \n");
	for(i = 0; i < n; ++i)
		printf("%d ", v[i]);
	printf("\n");

	printf("[ITERATIVO] Fib(%d) = %d\n", n, fib_iterativo(n - 1, v));

	printf("Sequencia final: \n");
	for(i = 0; i < n; ++i)
		printf("%d ", v[i]);
	printf("\n");

	free(v);

	return 0;
}
