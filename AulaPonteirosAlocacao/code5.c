#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a = 10, b = 20;
	printf("%d %d\n", a, b); // 10 20
	troca(&a, &b);
	printf("%d %d\n", a, b); // 20 10
	return 0;
}
