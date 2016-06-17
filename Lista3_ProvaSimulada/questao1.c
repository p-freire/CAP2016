/*
  Objetivo: ler uma string S e um padrão P e retornar quantas vezes P aparece em S.
  Exemplo:
  	S = "Giovana e Mariana gostam de banana"
  	P = "ana"
  	Ocorrências de P em S = 4 (banana possui duas ocorrências)
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 100

int main(int argc, char **argv)
{
	char s[TAM_MAX], p[TAM_MAX], tam_s, tam_p, i, j, contador, num_ocorrencias;
	num_ocorrencias = 0;
	printf("Entre com a string: ");
	scanf(" %[^\n]s", s);
	printf("Entre com o padrao a ser buscado: ");
	scanf(" %[^\n]s", p);

	for(tam_s = 0; s[tam_s] != '\0'; ++tam_s); // tamanho da string s
	for(tam_p = 0; p[tam_p] != '\0'; ++tam_p); // tamanho da string p

	while(i < tam_s)
	{
		if(s[i] == p[0])
		{
			j = 1;
			contador = 1;
			while(j < tam_p && i + 1 < tam_s && s[++i] == p[j++])
				++contador;

			if(contador == tam_p) // achou uma ocorrencia
				++num_ocorrencias;
		}
		else
			++i;
	}

	if(num_ocorrencias == 0)
		printf("Nenhuma ocorrencia do padrao (%s) foi encontrada na string (%s)\n", p, s);
	else
		printf("A string (%s) possui %d ocorrencia(s) do padrao (%s).\n", s, num_ocorrencias, p);

	return 0;

}
