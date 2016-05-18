#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int *vetor, **matriz;
	int n_linhas, n_colunas, i, j;
	srand(time(NULL));

	printf("Entre com a quantidade de linhas e colunas: ");
	scanf("%d %d", &n_linhas, &n_colunas);

	vetor = malloc(n_linhas * n_colunas * sizeof(int));

	if(vetor == NULL)
		return -1;

	matriz = malloc(n_linhas * sizeof(int*));

	if(matriz == NULL)
		return -1;

	for(i = 0; i < n_linhas; ++i)
		matriz[i] = &vetor[i * n_colunas];

    for(i = 0; i < n_linhas; ++i)
        for(j = 0; j < n_colunas; ++j)
            matriz[i][j] = rand() % 100;

    for(i = 0; i < n_linhas; ++i)
    {
        for(j = 0; j < n_colunas; ++j)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }

	free(vetor);
	free(matriz);
	return 0;
}
