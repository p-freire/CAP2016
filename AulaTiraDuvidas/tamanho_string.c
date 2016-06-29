/*
   Objetivo: fazer uma funcao que calcula o tamanho 
   de uma string passada como parametro.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 512

int conta_tamanho(char *buffer)
{
	int tam;
	for(tam = 0; buffer[tam] != '\0'; ++tam);
	return tam;
}


int main()
{
	char buffer[TAM_MAX];
	printf("Entre com a string: ");
	scanf(" %[^\n]s", buffer);
	printf("O tamanho da string eh: %d\n", conta_tamanho(buffer));

	return 0;
}
