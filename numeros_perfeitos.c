/*
 Objetivo: Dado um limite superior, encontrar os números perfeitos até aquele limite.

 Números perfeitos são aqueles cuja soma de seus divisores é o próprio número.
 Por exemplo: 6 = 3 + 2 + 1. Ou seja, o número 6 é perfeito.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void encontra_numeros_perfeitos(int limite)
{
    int i, j, soma, raiz;
    for(i = 2; i <= limite; ++i)
    {
        soma = 1;
        if(i % 2 == 0) // números perfeitos são, por definição, apenas pares
        {
            // para achar os divisores, eu preciso ir apenas até a raiz do número.
            // Explicação -> https://stackoverflow.com/questions/5811151/why-do-we-check-upto-the-square-root-of-a-prime-number-to-determine-if-it-is-pri
            raiz = (int)sqrt(i);
            j = 2;
            while(soma <= i && j <= raiz)
            {
                if(i % j == 0 && j * j != i)
                    soma += j + (i / j); // soma as duas contrapartes
                else if(i % j == 0 && j * j == i) // pro caso do número possuir raiz inteira e não somar o mesmo numero duas vezes
                    soma += j;
                ++j;
            }
        }
        if(soma == i)
            printf("O numero %d eh perfeito\n", soma);
    }
}

int main(int argc, char **argv)
{
    int limite;
    printf("Entre com o limite: ");
    scanf("%d", &limite);
    encontra_numeros_perfeitos(limite);
    return 0;
}
