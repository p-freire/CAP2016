#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int n, i;
	scanf("%d", &n);
	int vetor[n];
	for(i = 0; i < n; ++i)
		vetor[i] = i + 1;
	for(i = 0; i < n; ++i)
		printf("%d ", vetor[i]);
	printf("\n");
	return 0;
}