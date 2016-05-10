/*
  Objetivo: calcular a quantidade mínima de trocas para deixar o vetor lido ordenado.
  O vetor tem uma particularidade: se o seu tamanho é N, ele terá única e exclusivamente
  elementos entre 1 e N, sem repetições.
*/

#include <stdio.h>
#define MAX 50

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(int argc, char **argv)
{
    int vetor[MAX], n, i, j, menor, menor_pos, num_trocas;
    num_trocas = 0;

    printf("Entre com a quantidade de elementos (< 50): ");
    scanf("%d", &n);

    for(i = 0; i < n; ++i)
    {
        printf("Entre com o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < n; ++i)
    {
        menor = vetor[i];
        menor_pos = i;
        for(j = i + 1; j < n; ++j)
            if(vetor[j] < menor)
            {
                menor = vetor[j];
                menor_pos = j;
            }

        if(menor_pos != i)
        {
            swap(&vetor[i], &vetor[menor_pos]);
            ++num_trocas;
        }
    }

    printf("O menor numero de trocas para ordenar o vetor em ordem crescente eh %d.\n", num_trocas);

    return 0;
}
