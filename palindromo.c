/*
 Objetivo: verificar se um dado número é ou não é palíndromo.

 Para fazer essa verificação, basta calcular o reverso do número
 e verificar se o reverso é igual ao número em questão.
*/

#include <stdio.h>
#include <stdlib.h>

int calcula_potencia(int potencia)
{
    int i, base;
    base = 1;
    if(potencia == 0)
        return 1;
    else
    {
        for(i = 0; i < potencia; ++i)
            base *= 10;
        return base;
    }
}

int main(int argc, char **argv)
{
    int n, tam, soma, aux, mult, divisor, i;
    printf("Entre com o numero: ");
    scanf("%d", &n);

    tam = 0;
    soma  = 0;
    aux = n;

    // verifica a maior base do número
    // Exemplos: 0 - 9, base = 0 (unidade)
    //           10 - 99, base = 1 (dezena)
    //           100 - 999, base = 2 (centena)
    while(aux / 10 > 0)
    {
        ++tam;
        aux = aux / 10;
    }

    aux = n;
    // calcula o reverso do número
    for(i = 0; i <= tam; ++i)
    {
        mult = calcula_potencia(i);
        divisor = calcula_potencia(tam - i);
        soma += (aux / divisor) * mult;
        aux = aux % divisor;
    }

    if(soma == n)
        printf("O numero %d eh palindromo\n", n);
    else
        printf("O numero %d nao eh palindromo\n", n);

    // se quiser economizar linhas de código, o comando abaixo é equivalente ao if-else anterior
    //printf(soma == n ? "O numero %d eh palindromo\n" : "O numero %d nao eh palindromo\n", n);
    return 0;
}
