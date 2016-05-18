#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void selection_sort(int *ptr, int n)
{
	int i, j, pos_menor;
	for(i = 0; i < n; ++i)
	{
		pos_menor = i;
		for(j = i + 1; j < n; ++j)
			if(ptr[j] < ptr[pos_menor])
				pos_menor = j;
		if(pos_menor != i)
			troca((ptr + i), (ptr + pos_menor));//troca(&ptr[i], &ptr[pos_menor]);
	}
}

int main()
{
	int n, i, *vetor;
	srand(time(NULL));
	printf("Entre com o tamanho do vetor: ");
	scanf("%d", &n);

	vetor = malloc(n * sizeof(int));

	if(vetor == NULL)
		return -1;

	for(i = 0; i < n; ++i)
		vetor[i] = rand() % 100;

	for(i = 0; i < n; ++i)
		printf("%d ", vetor[i]); //*(vetor + i)

	selection_sort(vetor, n);

	printf("\n");
	for(i = 0; i < n; ++i)
		printf("%d ", vetor[i]); //*(vetor + i)
	printf("\n");

	free(vetor);
	return 0;
}
