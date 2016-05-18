#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p, a = 10; 
	printf("%p\n", p); // nil
	*p = a; // errou feio, errou rude
	return 0;
}