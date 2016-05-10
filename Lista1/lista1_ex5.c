/*
  Objetivo: ler uma string e verificar se ela é um palíndromo.
*/

#include <stdio.h>
#define MAX 21

int main(int argc, char **argv)
{
    char entrada[MAX];
    int tamanho, i;

    printf("Entre com a string: ");
    scanf("%s", entrada);
    for(tamanho = 0; entrada[tamanho] != '\0'; ++tamanho);

    if(tamanho == 1)
        printf("A string %s eh um palindromo.\n", entrada);
    else
    {
        i = 0;
        --tamanho;
        // "divide" a string em duas e vai verificando se 
        // os valores são iguais
        while(i < tamanho && entrada[i] == entrada[tamanho])
        {
            ++i;
            --tamanho;
        }
        // se o valor de i ficou menor que tamanho
        // siginifica que a varredura encontrou uma diferença entre as metades analisadas
        printf(i < tamanho ? "A string %s nao eh um palindromo.\n" : "A string %s eh um palindromo.\n", entrada);
    }

    return 0;
}
