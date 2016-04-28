/*
 Objetivo: dado um limite superior, calcular os números primos dentro do intervalo [1, limite]

 Duas formas são apresentadas aqui. Uma delas usando força bruta e outra usando o crivo de Eratóstenes.
 Experimente colocar um limite grande... 100000 por exemplo. Veja o que acontece.
 Pra ter uma ideia melhor da diferença entre as abordagens, comente a impressão dos resultados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void primos_forca_bruta(int lim_max)
{
    int i, j, num_divisores, raiz;
    for(i = 1; i <= lim_max; ++i)
    {
        num_divisores = 0;
        j = 1;

        // para achar os divisores, eu preciso ir apenas até a raiz do número.
        // Explicação -> https://stackoverflow.com/questions/5811151/why-do-we-check-upto-the-square-root-of-a-prime-number-to-determine-if-it-is-pri
        raiz = (int)sqrt(i);
        while(num_divisores <= 2 && j <= raiz)
        {
            if(i % j == 0 && j * j != i)
                num_divisores += 2;
            else if(i % j == 0 && j * j == i)
                ++num_divisores;
            ++j;
        }

        // Se não quiser imprimir os primos encontrados, comente o trecho a seguir
        if(num_divisores == 2)
            printf("[FORCA_BRUTA] O numero %d eh primo\n", i);
    }
}

int* crivo_eratostenes(int lim_max)
{
    int i, j;
    int *crivo = (int *) malloc(lim_max * sizeof(int));
    if(crivo == NULL)
        return;

    for(i = 0; i < lim_max; ++i)
        crivo[i] = i;

    for(i = 2; i < lim_max; ++i)
    {
        if(crivo[i] != 0)
        {
            // j = i << 1; -> multiplica o numero por dois usando deslocamento de bits
            for(j = i << 1; j < lim_max; j += i)
                crivo[j] = 0;
        }
    }
    return crivo;
}


int main(int argc, char **argv)
{
    clock_t inicio, fim;
    double tempo_total;
    int lim_superior, i;

    printf("Entre com o limite superior: ");
    scanf("%d", &lim_superior);

    inicio = clock();
    int *primos = crivo_eratostenes(lim_superior + 1);
    fim = clock();
    tempo_total = ((double) fim - inicio) / CLOCKS_PER_SEC;

    printf("O crivo levou %.3f segundos para rodar\n", tempo_total);

    // Se não quiser imprimir os primos encontrados, comente o trecho a seguir
    for(i = 2; i < lim_superior + 1; ++i)
        if(primos[i])
            printf("[CRIVO] O numero %d eh primo\n", primos[i]);

    inicio = clock();
    primos_forca_bruta(lim_superior);
    fim = clock();
    tempo_total = ((double) fim - inicio) / CLOCKS_PER_SEC;
    printf("A forca bruta levou %.3f segundos para rodar\n", tempo_total);

    free(primos);
    return 0;
}


