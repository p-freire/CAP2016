#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, *vetor;
	printf("Entre com o tamanho do vetor: ");
	scanf("%d", &n);
	vetor = malloc(n * sizeof(int));
	if(vetor == NULL)
		return -1;
	for(i = 0; i < n; ++i)
		vetor[i] = i + 1; //*(vetor + i) = i + 1
	for(i = 0; i < n; ++i)
		printf("%d ", vetor[i]); //*(vetor + i)
	printf("\n");

	free(vetor);
	return 0;
}
