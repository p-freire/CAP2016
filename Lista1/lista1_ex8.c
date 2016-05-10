/*
  Objetivo: recalcular números em uma máquina com problema nos dígitos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DIGITOS 110

char numero[MAX_DIGITOS];

int main()
{
    int n, i; 
    int ehApenasZeros = 1;

    while(scanf("%d", &n) && n != 0)
    {
       scanf("%s", numero);
       for(i = 0; numero[i] != '\0'; ++i)
       {
          if((int)numero[i] - 48 != n)
          {
             if((int)numero[i] - 48 != 0)
             {
                ehApenasZeros = 0;
                printf("%c", numero[i]);
             }
             else if((int)numero[i] - 48 == 0 && !ehApenasZeros)
                printf("%c", numero[i]);
          }
       }
       if(ehApenasZeros)
          printf("0");
       printf("\n");
       ehApenasZeros = 1;
    }
    return 0;
}
