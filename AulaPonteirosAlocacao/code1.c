#include <stdio.h>
#include <stdlib.h>

void troca(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}


int main()
{
	int a = 10, b = 20;
	printf("%d %d\n", a, b);
	troca(a, b);
	printf("%d %d\n", a, b);
	return 0;
}
