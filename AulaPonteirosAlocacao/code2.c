#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p, **q;
	int a = 10;
	p = &a;
	q = &p; // ponteiro c/ endereco de outro ponteiro
	(*p)++; // incrementa o conteudo
	printf("%d %d %d\n", a, *p, **q); // 11 11 11
	return 0;
}