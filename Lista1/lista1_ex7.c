/*
  Objetivo: verificar os acertos em uma prova de testes com gabarito.
*/

#include <stdio.h>
#define NUM_QUESTOES 5

int main(int argc, char **argv)
{
    char respostas[NUM_QUESTOES], gabarito[NUM_QUESTOES];
    int num_alunos, pontuacao, i, j;

    printf("Entre com o gabarito\n");
    for(i = 0; i < NUM_QUESTOES; ++i)
    {
        printf("Resposta correta da questao %d: ", i + 1);
        scanf(" %c", &gabarito[i]); // perceba o uso do espaço antes de %c
    }

    printf("\nEntre com o numero de alunos: ");
    scanf("%d", &num_alunos);
    printf("\n");

    for(i = 0; i < num_alunos; ++i)
    {
        pontuacao = 0;
        printf("Entre com as respostas do aluno %d.\n", i + 1);
        for(j = 0; j < NUM_QUESTOES; ++j)
        {
            printf("Resposta do aluno %d na questao %d: ", i + 1, j + 1);
            scanf(" %c", &respostas[j]);
            if(respostas[j] == gabarito[j])
                ++pontuacao;
        }
        printf("\nA pontuacao do aluno %d foi %d de %d.\n\n", i + 1, pontuacao, NUM_QUESTOES);
    }
    return 0;
}
