/*
   Objetivo: fazer a soma de duas matrizes usando apenas ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void somaMatrizes(int **a, int **b, int **c, int n, int m)
{
	int i, j;z
	for(i = 0; i < n; ++i)
		for(j = 0; j < m; ++j)
			c[i][j] = a[i][j] + b[i][j];
}

void imprimeMatriz(int **mat, int n, int m)
{
	int i, j;
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < m; ++j)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

int main()
{
	int *v1, *v2, *v3, **m1, **m2, **m3;
	int n, m, i, j;
	printf("Entre com o numero de linhas e colunas: ");
	scanf("%d %d", &n, &m);

	if((v1 = (int*)malloc(n * m * sizeof(int))) == NULL)
		return -1;

	if((v2 = (int*)malloc(n * m * sizeof(int))) == NULL)
		return -1;

	if((v3 = (int*)malloc(n * m * sizeof(int))) == NULL)
		return -1;

	if((m1 = (int**)malloc(n * sizeof(int*))) == NULL)
		return -1;

	if((m2 = (int**)malloc(n * sizeof(int*))) == NULL)
		return -1;

	if((m3 = (int**)malloc(n * sizeof(int*))) == NULL)
		return -1;

	for(i = 0; i < n; ++i)
	{
		m1[i] = &v1[i * n];
		m2[i] = &v2[i * n];
		m3[i] = &v3[i * n];
	}

	for(i = 0; i < n; ++i)
		for(j = 0; j < m; ++j)
		{
			m1[i][j] = rand() % 100;
			m2[i][j] = rand() % 100;
			m3[i][j] = 0;
		}

	somaMatrizes(m1, m2, m3, n, m);
	
	printf("Matriz 1\n");
	imprimeMatriz(m1, n, m);
	
	printf("\nMatriz 2\n");
	imprimeMatriz(m2, n, m);
	
	printf("\nMatriz 3\n");
	imprimeMatriz(m3, n, m);

	free(v1);
	free(v2);
	free(v3);
	free(m1);
	free(m2);
	free(m3);
	return 0;
}
