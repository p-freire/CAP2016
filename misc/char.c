/*
 Objetivo: ler um (e apenas um) char do terminal (stdin) usando scanf
 Referência: http://www.cplusplus.com/reference/cstdio/scanf/?kw=scanf

 O "enter" introduz quebra de linha e carriage return. Em outras palavras,
 o "enter" introduz whitespace. Sabendo disso, basta indicar ao scanf
 que os whitespaces devem ser ignorados na leitura.

 Tente rodar esse programa sem o espaço antes do %c no scanf para ver
 o que acontece.
 Depois descomente os comandos de getchar() e rode novamente.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char a, b;
	scanf(" %c", &a);
	//getchar();
	scanf(" %c", &b);
	//getchar();
	printf("%c %c\n", a, b);

	return 0;
}
