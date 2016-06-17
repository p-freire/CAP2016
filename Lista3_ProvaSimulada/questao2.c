/*
    Objetivo: fazer a exponenciacao da matriz {{1, 1}, {1, 0}} de forma
    a calcular o n-esimo elemento da sequencia de Fibonacci.
    Note que nesse caso nao eh necessario fazer alocacao dinamica, pois
    os limites da matriz sao definidos a priori.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fib[2][2] = {{1, 1}, {1, 0}}, resultado[2][2] = {{1, 1}, {1, 0}}, temp[2][2] = {{0, 0}, {0, 0}};
    int i, j, k, n, aux;

    printf("Entre com o valor de N: ");
    scanf("%d", &n);
    if(n < 1)
    {
        printf("Por favor, entre com valores maiores ou iguais a 1.\n");
        return -1;
    }

    aux = n;
    --aux; // decremento feito porque a matriz resultado já tem o valor para n = 1

    // exponenciacao da matriz
    while(aux)
    {
        memset(temp, 0, sizeof(temp)); // zera os valores da matriz
        for(i = 0; i < 2; ++i)
            for(j = 0; j < 2; ++j)
                for(k = 0; k < 2; ++k)
                    temp[i][j] += resultado[i][k] * fib[k][j];

        // passa a mutiplicacao pra matriz resultado
        for(i = 0; i < 2; ++i)
            for(j = 0; j < 2; ++j)
                resultado[i][j] = temp[i][j];
        --aux;
    }

    printf("O elemento %d da sequencia de Fibonacci eh: %d\n", n, resultado[0][1]);
    return 0;
}
