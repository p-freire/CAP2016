/*
    Objetivo: fazer a soma de duas matrizes retornando 
    um vetor da função de soma.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* soma(int **m1, int **m2, int linhas, int colunas)
{
    int *v;
    int i, j;

    v = (int*)malloc(linhas * colunas * sizeof(int));

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
            v[i*linhas + j] = m1[i][j] + m2[i][j];
    }
    return v;
}

void imprime(int **mat, int linhas, int colunas)
{
    int i, j;
    for(i = 0; i < linhas; ++i)
    {
        for(j = 0; j < colunas; ++j)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int main()
{
    int *v1, *v2, **m1, **m2, **m3, *conta;
    int i, j, linhas, colunas;
    srand (time(NULL));
    printf("Insira o numero de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);

    v1 = (int*)malloc(linhas * colunas * sizeof(int));
    v2 = (int*)malloc(linhas * colunas * sizeof(int));
    m1 = (int**)malloc(linhas * sizeof(int*));
    m2 = (int**)malloc(linhas * sizeof(int*));
    m3 = (int**)malloc(linhas * sizeof(int*));

    for(i = 0; i < linhas; i++)
    {
        m1[i] = &v1[colunas*i];
        m2[i] = &v2[colunas*i];
    }

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            m1[i][j] = rand()%10;
            m2[i][j] = rand()%10;
        }
    }

    printf("Matriz 1:\n\n");
    imprime(m1, linhas, colunas);

    printf("\nMatriz 2:\n\n");
    imprime(m2, linhas, colunas);

    conta = soma(m1, m2, linhas, colunas);

    for(i = 0; i < linhas; i++)
        m3[i] = &conta[i*colunas];

    printf("\nSoma das matrizes:\n\n");
    imprime(m3, linhas, colunas);

    free(v1);
    free(v2);
    free(conta);
    free(m1);
    free(m2);
    free(m3);

    return 0;
}
