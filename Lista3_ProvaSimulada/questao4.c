/*
    Objetivo: ler e ordenar uma lista de alunos, ordena-la por nota e por nome e
    salvar cada ordenacao em arquivo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    double nota;
    char nome[30];
} aluno;

void swap(aluno *a, aluno *b)
{
    aluno temp;
    temp.nota = a->nota;
    strcpy(temp.nome, a->nome);

    *a = *b;
    *b = temp;
}

void selection_sort_nome(aluno *v, int n)
{
    int i, j, pos_menor;
    for(i = 0; i < n; ++i)
    {
        pos_menor = i;
        for(j = i + 1; j < n; ++j)
            if(strcmp(v[j].nome, v[pos_menor].nome) < 0)
                pos_menor = j;
        if(pos_menor != i)
            swap(&v[pos_menor], &v[i]);
    }
}

void selection_sort_nota(aluno *v, int n)
{
    int i, j, pos_maior;
    for(i = 0; i < n; ++i)
    {
        pos_maior = i;
        for(j = i + 1; j < n; ++j)
            if(v[j].nota > v[pos_maior].nota)
                pos_maior = j;
        if(pos_maior != i)
            swap(&v[pos_maior], &v[i]);
    }
}


int main()
{
    FILE *nomes, *notas;
    aluno *alunos;
    int n, i;

    nomes = fopen("nomes_ordenados.txt", "w");
    notas = fopen("notas_ordenadas.txt", "w");
    printf("Entre com o numero de alunos: ");
    scanf("%d", &n);

    if((alunos = (aluno*)malloc(n * sizeof(aluno))) == NULL)
        return -1;

    for(i = 0; i < n; ++i)
    {
        printf("Entre com os dados do aluno %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", alunos[i].nome);
        printf("\nNota: ");
        scanf(" %lf", &alunos[i].nota);
        printf("\n\n");
    }

    // ordenando por ordem alfabetica
    selection_sort_nome(alunos, n);
    for(i = 0; i < n; ++i)
    {
        fprintf(nomes, "Dados do aluno %d\n", i + 1);
        fprintf(nomes, "\tNome: %s\n\tNota: %lf\n\n", alunos[i].nome, alunos[i].nota);
    }

    // ordenando por ordem decresente de nota
    selection_sort_nota(alunos, n);
    for(i = 0; i < n; ++i)
    {
        fprintf(notas, "Dados do aluno %d\n", i + 1);
        fprintf(notas, "\tNome: %s\n\tNota: %lf\n\n", alunos[i].nome, alunos[i].nota);
    }

    free(alunos);
    fclose(nomes);
    fclose(notas);
    return 0;
}
