/*
  Objetivo: ler uma string e transformar caracteres maiúsculos em minúsculos e vice-versa.
  Aqui se faz o uso da tabela ASCII. 
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 21

int main(int argc, char **argv)
{
    char entrada[TAM_MAX];
    int i, tamanho;

    printf("Entre com a string: ");
    scanf("%[^\n]s", entrada);

    for(tamanho = 0; entrada[tamanho] != '\0'; ++tamanho);

    for(i = 0; i < tamanho; ++i)
    {
        if((int)entrada[i] >= 65 && (int)entrada[i] <= 90) // é uma letra maiúscula (confira na tabela ASCII)
            entrada[i] += 32;
        else if((int)entrada[i] >= 97 && (int)entrada[i] <= 122) // é uma letra minúscula (confira na tabela ASCII)
            entrada[i] -= 32;
    }

    printf("%s\n", entrada);

    return 0;
}
