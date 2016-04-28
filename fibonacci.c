/*
 Objetivo: dado um valor N, calcular e mostrar a sequ�ncia de Fibonacci at� o N-�simo elemento.
 A sequ�ncia de Fibonacci inicia-se com 1, 1 e o restante da sequ�ncia � calculada somando-se
 os dois elementos anteriores. Ent�o, por exemplo, o s�timo elemento da sequ�ncia � 13:
 1, 1, 2, 3, 5, 8, 13

 Aqui h� duas formas de calcular a sequ�ncia. Uma iterativa e outra recursiva. Note que
 n�o h� distin��o entre o resultado delas, mas h� uma diferen�a gigantesca na complexidade
 de cada abordagem.
*/

#include <stdio.h>
#include <stdlib.h>

int fib_recursivo(int num)
{
    if(num <= 2)
        return 1;
    else
        return fib_recursivo(num - 1) + fib_recursivo(num - 2);
    // quer economizar linhas de c�digo? A linha a seguir � equivalente a essas 4 anteriores :-)
    //return(num <= 2 ? 1 : fib_recursivo(num - 1) + fib_recursivo(num - 2));
}

int main(int argc, char **argv)
{
    int prim, seg, ter, tam, i;
    prim = seg = 1;
    printf("Entre com o tamanho da sequencia: ");
    scanf("%d", &tam);
    if(tam > 0)
    {
        printf("Calculando Fibonacci usando repeticao\n");
        if(tam == 1)
            printf("%d", prim);
        else
        {
            printf("%d %d", prim, seg);
            for(i = 0; i < tam - 2; ++i)
            {
                ter = prim + seg;
                prim = seg;
                seg = ter;
                printf(" %d", ter);
            }
        }
        printf("\n");
    }
    else
        printf("Entre com um valor maior que zero\n");

    printf("Calculando Fibonacci usando recursao\n");
    for(i = 1; i <= tam; ++i)
        printf("%d ", fib_recursivo(i));
    return 0;
}
