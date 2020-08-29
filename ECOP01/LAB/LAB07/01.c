#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    char visual[10][10], jogo[10][10];
    int i, j, k, a = 0, lin, col;
    int linha, coluna;

    printf("  ");
    for (i = 0; i < 10; i++)
    {
        printf("  %d", i);
    }
    printf("\n");

    for (i = 0; i < 10; i++)
    {
        printf("\n%d  ", i);
        for (j = 0; j < 10; j++)
        {
            visual[i][j] = '?';
            jogo[i][j] = ' ';
            printf(" %c ", visual[i][j]);
        }
    }

    srand(time(NULL));
    while (a < 10)
    {
        lin = rand() % 10;
        col = rand() % 10;
        jogo[lin][col] = '*';
        a = a + 1;
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            k = 48;
            if (jogo[i][j] != '*')
            {
                if (jogo[i - 1][j - 1] == '*')
                {
                    k = k + 1;
                }
                if (jogo[i - 1][j] == '*')
                {
                    k = k + 1;
                }
                if (jogo[i - 1][j + 1] == '*')
                {
                    k = k + 1;
                }
                if (jogo[i][j - 1] == '*')
                {
                    k = k + 1;
                }
                if (jogo[i][j + 1] == '*')
                {
                    k = k + 1;
                }
                if (jogo[i + 1][j - 1] == '*')
                {
                    k = k + 1;
                }
                if (jogo[i + 1][j] == '*')
                {
                    k = k + 1;
                }
                if (jogo[i + 1][j + 1] == '*')
                {
                    k = k + 1;
                }
            }
            if (k != 48)
            {
                jogo[i][j] = k;
            }
        }
    }

    k = 0;
    while (k < 90)
    {

        printf("\n\nEscolha uma linha e uma coluna \n");
        scanf("%d", &linha);
        scanf("%d", &coluna);

        if (jogo[linha][coluna] != '*')
        {
            visual[linha][coluna] = jogo[linha][coluna];
            printf("\n\n\n  ");
            for (i = 0; i < 10; i++)
            {
                printf("  %d", i);
            }
            printf("\n");

            for (i = 0; i < 10; i++)
            {
                printf("\n%d  ", i);
                for (j = 0; j < 10; j++)
                {
                    printf(" %c ", visual[i][j]);
                }
            }
        }
        else
        {
            for (i = 0; i < 10; i++)
            {
                for (j = 0; j < 10; j++)
                {
                    visual[i][j] = 'X';
                }
            }
            visual[linha][coluna] = jogo[linha][coluna];
            for (i = 0; i < 10; i++)
            {
                printf("\n");
                for (j = 0; j < 10; j++)
                {
                    printf(" %c ", visual[i][j]);
                }
            }
            printf("\n ----------------------------\n");
            printf("\n         VOCE PERDEU \n");
            printf("\n ----------------------------\n");
            break;
        }
        k = k + 1;
    }
    return 0;
}
