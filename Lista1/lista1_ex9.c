/*
  Objetivo: dado um vetor, imprimir o segundo maior valor. Em situações do tipo
  [3, 3, 2, 2, 1], o programa deve retornar o valor 2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // caso queira usar o rand()
#define TAM_MAX 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char **argv)
{
    int vetor[TAM_MAX], n, i, j, maior;
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);

    for(i = 0; i < n; ++i)
    {
        printf("Entre com o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // ordenação usando selection sort
    for(i = 0; i < n; ++i)
    {
        maior = vetor[i];
        for(j = i + 1; j < n; ++j)
        {
            if(vetor[j] > maior)
                swap(&maior, &vetor[j]);
        }
        vetor[i] = maior;
    }

    i = 0;
    while(i + 1 < n && vetor[i] == vetor[i + 1])
        ++i;

    printf("\nO segundo maior valor eh: ");
    if(i == n - 1)
        printf("%d\n", vetor[i]);
    else
        printf("%d\n", vetor[i + 1]);

    return 0;
}
