/*
  Objetivo: Ler um nome composto (isto é, com espaços) e mostrar na tela
  A ideia é fazer uso do %[^\n], que indica que a leitura deve ser feita
  até encontrar uma quebra de linha.
*/

#include <stdio.h>
#define MAX 31

int main(int argc, char **argv)
{
    char nome_composto[MAX];
    printf("Entre com um nome composto: ");
    scanf("%[^\n]s", nome_composto);
    printf("O nome digitado foi %s\n.", nome_composto);

    return 0;
}
