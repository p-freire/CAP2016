#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int *a, int n)
{
	int i, j, pos_menor;
	for(i = 0; i < n; ++i)
	{
		pos_menor = i;
		for(j = i + 1; j < n; ++j)
			if(a[j] < a[pos_menor])
				pos_menor = j;
		if(pos_menor != i)
			troca(&a[i], &a[pos_menor]);
	}
}

int main()
{
    int a[5] = {10, 8, 1, 3, 15};
    int b[5] = {15, 1, 35, 0, 2};
    int i;

    selection_sort(a, 5);
    selection_sort(b, 5);

    printf("Vetor A\n");
    for(i = 0; i < 5; ++i)
        printf("%d ", a[i]);
    printf("\n");

    printf("Vetor B\n");
    for(i = 0; i < 5; ++i)
        printf("%d ", b[i]);
    printf("\n");

    return 0;
}
