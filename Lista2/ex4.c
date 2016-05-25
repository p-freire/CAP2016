#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int *vetorzao1, *vetorzao2, *vetorzao3, **matriz, **resultado, **tmp;
	int linhas, colunas, i, j, k, n;

    // As matrizes devem ser quadradas
	printf("Entre com o numero de linhas: ");
	scanf("%d", &linhas);
	colunas = linhas;

	printf("Entre com o expoente inteiro: ");
	scanf("%d", &n);

    // Aloca e verifica
	if((vetorzao1 = malloc(linhas * colunas * sizeof(int))) == NULL)
		return -1;

	if((vetorzao2 = malloc(linhas * colunas * sizeof(int))) == NULL)
		return -1;

	if((vetorzao3 = malloc(linhas * colunas * sizeof(int))) == NULL)
		return -1;

	if((matriz = malloc(linhas * sizeof(int*))) == NULL)
		return -1;

	if((resultado = malloc(linhas * sizeof(int*))) == NULL)
		return -1;

	if((tmp = malloc(linhas * sizeof(int*))) == NULL)
		return -1;

    // Enderecamento
	for(i = 0; i < linhas; ++i)
	{
		matriz[i] = &vetorzao1[i * colunas];
		resultado[i] = &vetorzao2[i * colunas];
		tmp[i] = &vetorzao3[i * colunas];
	}

    // Leitura da matriz
	for(i = 0; i < linhas; ++i)
		for(j = 0; j < colunas; ++j)
		{
			printf("Entre com o elemento [%d, %d]: ", i, j);
			scanf("%d", &matriz[i][j]);
			resultado[i][j] = matriz[i][j];
		}

    // Exponenciacao
	while(--n)
	{
		for(i = 0; i < linhas; ++i)
			for(j = 0; j < colunas; ++j)
				tmp[i][j] = 0;


		for(i = 0; i < linhas; ++i)
			for(j = 0; j < colunas; ++j)
				for(k = 0; k < linhas; ++k)
					tmp[i][j] += resultado[i][k] * matriz[k][j];

		for(i = 0; i < linhas; ++i)
			for(j = 0; j < colunas; ++j)
				resultado[i][j] = tmp[i][j];
	}

	printf("Matriz inicial\n");
	for(i = 0; i < linhas; ++i)
	{
		for(j = 0; j < colunas; ++j)
			printf("%d ", matriz[i][j]);
		printf("\n");
	}

	printf("\nMatriz final\n");
	for(i = 0; i < linhas; ++i)
	{
		for(j = 0; j < colunas; ++j)
			printf("%d ", resultado[i][j]);
		printf("\n");
	}

	free(vetorzao1);
	free(vetorzao2);
	free(vetorzao3);
	free(matriz);
	free(tmp);
	free(resultado);
	return 0;
}
