#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_MAX 4

typedef struct
{
	int *v, **m;
} matriz;

matriz soma(matriz m1, matriz m2, int l, int c)
{
	int i, j;
	matriz m3;
	
	m3.v = (int*)malloc(l * c * sizeof(int));
	m3.m = (int**)malloc(l * sizeof(int*));
	for(i = 0; i < l; ++i)
		m3.m[i] = &m3.v[i * c];

	for(i = 0; i < l; ++i)
		for(j = 0; j < c; ++j)
			m3.m[i][j] = m1.m[i][j] + m2.m[i][j];
	return m3;
}

void imprime(matriz mat, int l, int c)
{
	int i, j;
	for(i = 0; i < l; ++i)
	{
		for(j = 0; j < c; ++j)
			printf("%3d ", mat.m[i][j]);
		printf("\n");
	}
}

int main() 
{
	matriz m1, m2, m3;
	int i, j, l, c;

	printf("Linhas e colunas: ");
	scanf("%d %d", &l, &c);

	m1.v = (int*)malloc(l * c * sizeof(int));
	m1.m = (int**)malloc(l * sizeof(int*));
	for(i = 0; i < l; ++i)
		m1.m[i] = &m1.v[i * c];

	m2.v = (int*)malloc(l * c * sizeof(int));
	m2.m = (int**)malloc(l * sizeof(int*));
	for(i = 0; i < l; ++i)
		m2.m[i] = &m2.v[i * c];

	srand(time(NULL));
	
	for(i = 0; i < l; ++i)
		for (j = 0; j < c; ++j)
		{
			m1.m[i][j] = rand() % 10;
			m2.m[i][j] = rand() % 10;
		}
	
    m3 = soma(m1, m2, l, c);

    imprime(m1, l, c);
    printf("\n");
    imprime(m2, l, c);
    printf("\n");
    imprime(m3, l, c);

    free(m1.v);
    free(m1.m);

    free(m2.v);
    free(m2.m);

    free(m3.v);
    free(m3.m);

	return 0;
}