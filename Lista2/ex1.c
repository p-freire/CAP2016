#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *vetor, *primos, lim, numPrimos, i, j;
	
	numPrimos = 0;
	printf("Entre com o limite superior: ");
	scanf("%d", &lim);

	++lim;
	// Aloca um vetor de tamanho de lim + 1
	vetor = malloc(lim * sizeof(int));

	if(vetor == NULL)
		return -1;

	for(i = 0; i < lim; ++i)
		vetor[i] = i;

	// Faz o crivo de Eratostenes
	for(i = 2; i < lim; ++i)
	{
		if(vetor[i] != -1)
		{
			++numPrimos;
			for(j = vetor[i] << 1; j < lim; j += vetor[i])
				vetor[j] = -1;
		}
	}

	// Aloca o vetor de primos
	primos = malloc(numPrimos * sizeof(int));

	if(primos == NULL)
		return -1;

	// Copia os primos pro vetor
	j = 0;
	for(i = 2; i < lim; ++i)
		if(vetor[i] != -1)
		{
			primos[j] = vetor[i];
			++j;
		}

	printf("Numero de primos ate %d: %d\n", lim - 1, numPrimos);
	for(i = 0; i < numPrimos; ++i)
		printf("%d\n", primos[i]);

	free(vetor);
	free(primos);

	return 0;
}