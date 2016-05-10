/*
  Objetivo: ler um vetor de números inteiros e calcular: média, mediana, moda, maior valor e menor valor.
*/

#include <stdio.h>
#define MAX 100

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char **argv)
{
    int numeros[MAX], n, maior_elem, menor_elem, contador, moda, i, menor, j;
    double media = 0.0, mediana;

    printf("Entre com a quantidade de numeros que serao lidos: ");
    scanf("%d", &n);
    if(n > 0)
    {
        printf("Entre com o valor 1: ");
        scanf("%d", &numeros[0]);
        maior_elem = numeros[0];
        menor_elem = numeros[0];
        media += numeros[0];

        for(i = 1; i < n; ++i)
        {
            printf("Entre com o valor %d: ", i + 1);
            scanf("%d", &numeros[i]);
            if(numeros[i] > maior_elem)
                maior_elem = numeros[i];
            else if(numeros[i] < menor_elem)
                menor_elem = numeros[i];
            media += numeros[i];
        }
        media /= n;

        // ordenação usando selection sort
        for(i = 0; i < n; ++i)
        {
            menor = numeros[i];
            for(j = i + 1; j < n; ++j)
                if(numeros[j] > menor)
                    swap(&menor, &numeros[j]);
            numeros[i] = menor;
        }

        // se a quantidade de números for ímpar, a mediana é o elemento que separa o vetor em dois
        // se a quantidade de números for par, a mediana é a média dos números que separam o vetor em dois
        // o operador "&" é um AND lógico. Dessa forma, n & 1 faz um AND de n com 1
        // todo número binário terminado em 1 é ímpar, logo n & 1 retorna true se n for ímpar e par, caso contrário
        mediana = n & 1 ? numeros[n / 2] : (numeros[n / 2] + numeros[(n / 2) - 1]) / 2.0;

        // encontra a moda
        int aux, mais_frequente = 0;
        i = 0;
        while(i < n)
        {
            aux = numeros[i];
            contador = 1;
            j = i + 1;
            while(j < n && numeros[j] == aux)
            {
                ++contador;
                ++j;
            }

            if(contador > mais_frequente)
            {
                mais_frequente = contador;
                moda = numeros[i];
            }

            i = j;
        }

        printf("\nMedia = %.3lf\n", media);
        printf("Mediana = %.3lf\n", mediana);
        printf("Maior elemento = %d\n", maior_elem);
        printf("Menor elemento = %d\n", menor_elem);
        printf("Moda = %d\n", moda);



    }
    else
        printf("Nada a ser feito.\n");
    return 0;
}
