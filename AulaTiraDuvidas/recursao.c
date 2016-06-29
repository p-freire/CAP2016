/*
   Objetivo: calcular o fatorial de um numero de formas recursivas e iterativa.
   
*/

#include <stdio.h>
#include <stdlib.h>

int fatorial_recursivo(int n)
{
	return n <= 1 ? 1 : n * fatorial_recursivo(n - 1);
}

int fatorial_iterativo(int *n)
{
	int mult = *n;
	while(--(*n))
		mult *= *n;
	return mult;
}

int main()
{
	int n;
	printf("Entre com o valor do fatorial que deseja saber: ");
	
	if(n < 0)
	{
		printf("Entre apenas com valores maiores ou iguais a zero!\n");
		return -1;
	}

	scanf("%d", &n);
	printf("[Recursivo] %d! = %d\n", n, fatorial_recursivo(n));
	printf("Valor de N antes = %d\n", n);
	printf("[Iterativo] %d! = %d\n", n, fatorial_iterativo(&n));
	printf("Valor de N depois = %d\n", n);


	return 0;
}
