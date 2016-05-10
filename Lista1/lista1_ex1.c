/*
  Objetivo: Ler um nome com até 15 letras (tamanho = 16 por conta do \0) e
  mostrar na tela o tamanho do nome lido sem usar a função strlen.
*/

#include <stdio.h>
#define MAX 16

int main(int argc, char **argv)
{
    char nome[MAX];
    int tamanho;
    printf("Entre com o nome: ");
    scanf("%s", nome);
    for(tamanho = 0; nome[tamanho] != '\0'; ++tamanho);
    printf("O nome digitado foi %s e seu tamanho eh %d.\n", nome, tamanho);
    return 0;
}
