/*
  Objetivo: dados dois vetores, V1 e V2, criar um terceiro vetor V3
  tal que V3 é a união de V1 com V2.
  Lembrando que união não pode conter elementos repetidos.
*/

#include <stdio.h>
#define MAX 100

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void selection_sort(int *v, int n)
{
	int i, j, menor;

	for(i = 0; i < n; ++i)
	{
		menor = v[i];
		for(j = i + 1; j < n; ++j)
			if(v[j] < menor)
				swap(&v[j], &menor);
		v[i] = menor;
	}
}

int remove_repeticoes(int *v, int n)
{
	int i = 0, novo_tam = 0, j;
	while(i < n)
	{
		v[novo_tam++] = v[i];
		j = i + 1;
		while(j < n && v[j] == v[i])
			++j;
		i = j;
	}

	return novo_tam;
}

int main(int argc, char **argv)
{
	int v1[MAX], v2[MAX], v3[MAX], n1, n2, i, j, k;
		
	// dados do primeiro vetor
	printf("Entre com a quantidade de elementos do primeiro vetor: ");
	scanf("%d", &n1);

	for(i = 0; i < n1; ++i)
	{
		printf("Entre com o numero %d: ", i + 1);
		scanf("%d", &v1[i]);
	}
	selection_sort(&v1[0], n1);
	n1 = remove_repeticoes(&v1[0], n1);

	// dados do segundo vetor
	printf("Entre com a quantidade de elementos do segundo vetor: ");
	scanf("%d", &n2);

	for(i = 0; i < n2; ++i)
	{
		printf("Entre com o numero %d: ", i + 1);
		scanf("%d", &v2[i]);
	}
	selection_sort(&v2[0], n2);
	n2 = remove_repeticoes(&v2[0], n2);

	i = 0;
	j = 0;
	k = 0;

	// junta os dois vetores ordenados em um terceiro vetor também ordenado
	while(k < n1 + n2)
	{
		if(i < n1 && j < n2) // ainda há elementos nos dois vetores
		{
			if(v1[i] < v2[j])
				v3[k] = v1[i++];
			else
				v3[k] = v2[j++];
		}
		else if(i < n1) // só há elementos no primeiro vetor
			v3[k] = v1[i++];
		else // só há elementos no segundo vetor
			v3[k] = v2[j++];
		++k;
	}

	k = remove_repeticoes(&v3[0], k);
	printf("O vetor V3 eh: \n");
	for(i = 0; i < k; ++i)
		printf("%d ", v3[i]);
	printf("\n");

	return 0;
}