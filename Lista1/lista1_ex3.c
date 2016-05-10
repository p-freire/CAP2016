/*
  Objetivo: ler uma string e imprimi-la ao contrário.
*/

#include <stdio.h>
#define MAX 21

int main(int argc, char **argv)
{
    char entrada[MAX];
    int tamanho;
    printf("Entre com uma string: ");
    scanf("%[^\n]s", entrada);
    for(tamanho = 0; entrada[tamanho] != '\0'; ++tamanho);
    printf("String digitada: %s\n", entrada);
    printf("String ao contrario: ");
    --tamanho;
    while(tamanho >= 0)
        printf("%c", entrada[tamanho--]);
    printf("\n");

    return 0;
}
