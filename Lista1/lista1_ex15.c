/*
  Objetivo: dados dois vetores, V1 e V2, criar um terceiro vetor V3 
  tal que V3 é a interseção de V1 com V2.
  Lembrando que não há repetições na interseção.
*/

#include <stdio.h>
#define MAX 100
#define MENOR(a, b) (a) < (b) ? (a) : (b)

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
	int v1[MAX], v2[MAX], v3[MAX], n1, n2, i, j, k, maior_vetor, menor_vetor;
		
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

	//maior_vetor = MAIOR(n1, n2);
	menor_vetor = MENOR(n1, n2);

	i = 0;
	j = 0;
	k = 0;

	if(menor_vetor == n1)
	{
		while(i < n1)
		{
			if(v1[i] == v2[j])
			{
				v3[k++] = v1[i];
				++i;
				++j;
			}
			else if(v1[i] < v2[j])
				++i;
			else
				++j;
		}
	}
	else
	{
		while(j < n2)
		{
			if(v2[j] == v1[i])
			{
				v3[k++] = v2[j];
				++i;
				++j;
			}
			else if(v2[j] < v1[i])
				++j;
			else
				++i;
		}
	}

	if(k == 0)
		printf("O vetor V3 eh vazio.\n");
	else
	{
		printf("O vetor V3 eh: \n");
		for(i = 0; i < k; ++i)
			printf("%d ", v3[i]);
		printf("\n");
	}

	return 0;
}
