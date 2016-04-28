/*
 Objetivo: dado um valor N, calcular e mostrar a sequência de Fibonacci até o N-ésimo elemento.
 A sequência de Fibonacci inicia-se com 1, 1 e o restante da sequência é calculada somando-se
 os dois elementos anteriores. Então, por exemplo, o sétimo elemento da sequência é 13:
 1, 1, 2, 3, 5, 8, 13

 Aqui há duas formas de calcular a sequência. Uma iterativa e outra recursiva. Note que
 não há distinção entre o resultado delas, mas há uma diferença gigantesca na complexidade
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
    // quer economizar linhas de código? A linha a seguir é equivalente a essas 4 anteriores :-)
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
