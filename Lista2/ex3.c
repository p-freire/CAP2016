#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int *vetorzao1, *vetorzao2, *vetorzao3, **matriz1, **matriz2, **matriz3;
	int linhas1, colunas1, linhas2, colunas2, i, j, k;
	srand(time(NULL));
	
	printf("Entre com as dimensoes da primeira matriz separadas por espaco: ");
	scanf("%d %d", &linhas1, &colunas1);

	printf("Entre com as dimensoes da segunda matriz separadas por espaco: ");
	scanf("%d %d", &linhas2, &colunas2);

	if(colunas1 != linhas2)
	{
		printf("Impossivel fazer multiplicao com essas dimensoes de matrizes!\n");
		return -1;
	}


	// Alocacoes e verificacoes
	if((vetorzao1 = malloc(linhas1 * colunas1 * sizeof(int))) == NULL)
		return -1;

	if((matriz1 = malloc(linhas1 * sizeof(int*))) == NULL)
		return -1;

	if((vetorzao2 = malloc(linhas2 * colunas2 * sizeof(int))) == NULL)
		return -1;

	if((matriz2 = malloc(linhas2 * sizeof(int*))) == NULL)
		return -1;

	if((vetorzao3 = malloc(linhas1 * colunas2 * sizeof(int))) == NULL)
		return -1;

	if((matriz3 = malloc(linhas1 * sizeof(int*))) == NULL)
		return -1;	


	// Enderecamento
	for(i = 0; i < linhas1; ++i)
		matriz1[i] = &vetorzao1[i * colunas1];

	for(i = 0; i < linhas2; ++i)
		matriz2[i] = &vetorzao2[i * colunas2];

	for(i = 0; i < linhas1; ++i)
		matriz3[i] = &vetorzao3[i * colunas2];


	// Inicializacao dos valores
	for(i = 0; i < linhas1; ++i)
		for(j = 0; j < colunas1; ++j)
			matriz1[i][j] = rand() % 10;
	
	for(i = 0; i < linhas2; ++i)
		for(j = 0; j < colunas2; ++j)
			matriz2[i][j] = rand() % 10;
	
	for(i = 0; i < linhas1; ++i)
		for(j = 0; j < colunas2; ++j)
			matriz3[i][j] = 0;
	

	// Multiplicacao
	for(i = 0; i < linhas1; ++i)
	{
		for(j = 0; j < colunas2; ++j)
		{
			for(k = 0; k < linhas2; ++k)
				matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
				//*(*(matriz3 + i) + j) += (*(*(matriz1 + i) + k)) * (*(*(matriz2 + k) + j));
		}
	}
	
	printf("Matriz 1\n");
	for(i = 0; i < linhas1; ++i)
	{
		for(j = 0; j < colunas1; ++j)
			printf("%d ", matriz1[i][j]);
		printf("\n");
	}
	printf("\n");

	printf("Matriz 2\n");
	for(i = 0; i < linhas2; ++i)
	{
		for(j = 0; j < colunas2; ++j)
			printf("%d ", matriz2[i][j]);
		printf("\n");
	}
	printf("\n");

	printf("Resultado da multiplicao\n");
	for(i = 0; i < linhas1; ++i)
	{
		for(j = 0; j < colunas2; ++j)
			printf("%d ", matriz3[i][j]);
		printf("\n");
	}
	printf("\n");

	free(vetorzao1);
	free(vetorzao2);
	free(vetorzao3);
	free(matriz1);
	free(matriz2);
	free(matriz3);
			
	return 0;
}