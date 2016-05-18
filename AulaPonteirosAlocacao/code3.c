#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p; 
	int a = 10;
	p = &a;
	printf("%p\n", p); // 0x7ffff1c233f4 
	p++; // incrementa... 
	printf("%d %d\n", a, *p); // 10 sabe-se-la-o-que
	printf("%p\n", p); // 0x7ffff1c233f8
	return 0;
}