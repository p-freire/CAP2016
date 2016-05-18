#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int **matriz, n_linhas, n_colunas, i, j;
	printf("Entre com a quantidade de linhas e colunas: ");
	scanf("%d %d", &n_linhas, &n_colunas);
	srand(time(NULL));

	matriz = malloc(n_linhas * sizeof(int*));

	if(matriz == NULL)
		return -1;

	for(i = 0; i < n_linhas; ++i)
	{
		matriz[i] = malloc(n_colunas * sizeof(int));
		if(matriz[i] == NULL)
			return -1;
	}

    for(i = 0; i < n_linhas; ++i)
        for(j = 0; j < n_colunas; ++j)
            matriz[i][j] = rand() % 100;

	printf("Matriz:\n");
	for(i = 0; i < n_linhas; ++i)
    {
        for(j = 0; j < n_colunas; ++j)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }

	for(i = 0; i < n_linhas; ++i)
		free(matriz[i]);

	free(matriz);
	return 0;
}
