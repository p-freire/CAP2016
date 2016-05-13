/*
  Objetivo: ler dois vetores, V1 e V2, e criar um terceiro vetor V3, ordenado, com
  os valores de V1 e V2.
  É possível fazer isso jogando os valores de V1 e V2 em V3 e depois ordenando-o.
  No entanto, aqui ordenou-se V1 e V2 e depois V3 foi criado usando apenas V1 e V2,
  sem necessidade de ordenar V3.
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
	int i, j, pos_menor;

	for(i = 0; i < n; ++i)
	{
		pos_menor = i;
		for(j = i + 1; j < n; ++j)
			if(v[j] < v[pos_menor])
				pos_menor = j
		if(pos_menor != i)
			swap(&v[i], &v[pos_menor]);
	}
}

int main(int argc, char **argv)
{
	int v1[MAX], v2[MAX], v3[MAX+MAX], n1, n2, i, j, k;
		
	// dados do primeiro vetor
	printf("Entre com a quantidade de elementos do primeiro vetor: ");
	scanf("%d", &n1);

	for(i = 0; i < n1; ++i)
	{
		printf("Entre com o numero %d: ", i + 1);
		scanf("%d", &v1[i]);
	}
	selection_sort(&v1[0], n1);

	// dados do segundo vetor
	printf("Entre com a quantidade de elementos do segundo vetor: ");
	scanf("%d", &n2);

	for(i = 0; i < n2; ++i)
	{
		printf("Entre com o numero %d: ", i + 1);
		scanf("%d", &v2[i]);
	}
	selection_sort(&v2[0], n2);

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

	printf("O vetor V3 eh: \n");
	for(i = 0; i < k; ++i)
		printf("%d ", v3[i]);
	printf("\n");

	return 0;
}
