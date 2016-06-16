#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char entrada[30];
    int a;
    double b;

    scanf("%d;%[^;];%lf", &a, entrada, &b);

    printf("%d\n", a);
    printf("%s\n", entrada);
    printf("%lf\n", b);

    return 0;
}
