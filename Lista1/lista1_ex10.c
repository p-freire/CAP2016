/*
  Objetivo: ler duas sequências como um vetor de char (de mesmo tamanho) e 
  armazenar num terceiro vetor o resultado da soma dos dois vetores lidos.
  Exemplo:
    V1 = [5, 0, 0]
    V2 = [5, 5, 0]
    V3 = [1, 0, 5, 0]
*/

#include <stdio.h>
#define MAX 11

int main(int argc, char **argv)
{
    char num_1[MAX], num_2[MAX], resultado[MAX];
    int carry, tamanho, i;
    printf("Entre com primeiro numero: ");
    scanf("%s", num_1);
    printf("Entre com o segundo numero: ");
    scanf("%s", num_2);
    for(tamanho = 0; num_1[tamanho] != '\0'; ++tamanho);
    for(i = 0; i < MAX; ++i)
        resultado[i] = '\0';
    --tamanho;
    i = 0;
    carry = 0;
    while(tamanho >= 0)
    {
        // [0..9] = [48..57] em ASC
        resultado[i] = ((carry + ((int)num_1[tamanho] - 48) + ((int)num_2[tamanho] - 48)) % 10) + 48;
        carry = (((int)num_1[tamanho] - 48) + ((int)num_2[tamanho] - 48)) / 10;
        --tamanho;
        ++i;
    }
    if(carry)
        resultado[i] = '1';

    for(tamanho = 0; resultado[tamanho] != '\0'; ++tamanho);
    --tamanho;
    printf("\nO resultado final eh: ");
    while(tamanho >= 0)
        printf("%c", resultado[tamanho--]);

    return 0;
}
