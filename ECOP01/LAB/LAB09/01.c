#include <stdio.h>
#include <string.h>

void inicializaMatriz(char matriz[10][10]);
void mostraMatriz(char matriz[10][10]);

int main(int argc, char *argv[])
{

    char matriz[10][10], animal[5];
    int i, j, linhaF, colunaF;

    inicializaMatriz(matriz);
    mostraMatriz(matriz);

    printf("\n\nDigite o nome de um animal ! \n");
    gets(animal);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {

            if (matriz[i][j] == animal[0])
            {

                if (i > 3)
                {
                    if (matriz[i - 1][j] == animal[1])
                    {
                        if (matriz[i - 2][j] == animal[2])
                        {
                            if (matriz[i - 3][j] == animal[3])
                            {
                                linhaF = i - 3;
                                colunaF = j;
                                printf("\nCome�a em %d, %d e termina em %d,%d \n", i, j, linhaF, colunaF);
                                break;
                            }
                        }
                    }
                }

                if (i < 7)
                {
                    if (matriz[i + 1][j] == animal[1])
                    {
                        if (matriz[i + 2][j] == animal[2])
                        {
                            if (matriz[i + 3][j] == animal[3])
                            {
                                linhaF = i + 3;
                                colunaF = j;
                                printf("\nCome�a em %d, %d e termina em %d,%d \n", i, j, linhaF, colunaF);
                                break;
                            }
                        }
                    }
                }

                if (j > 3)
                {
                    if (matriz[i][j - 1] == animal[1])
                    {
                        if (matriz[i][j - 2] == animal[2])
                        {
                            if (matriz[i][j - 3] == animal[3])
                            {
                                linhaF = i;
                                colunaF = j - 3;
                                printf("\nCome�a em %d, %d e termina em %d,%d \n", i, j, linhaF, colunaF);
                                break;
                            }
                        }
                    }
                }

                if (j < 7)
                {
                    if (matriz[i][j + 1] == animal[1])
                    {
                        if (matriz[i][j + 2] == animal[2])
                        {
                            if (matriz[i][j + 3] == animal[3])
                            {
                                linhaF = i;
                                colunaF = j + 3;
                                printf("\nCome�a em %d, %d e termina em %d,%d \n", i, j, linhaF, colunaF);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void mostraMatriz(char matriz[10][10])
{
    int i, j;

    for (i = 0; i < 10; i++)
        printf("  %d", i);
    for (i = 0; i < 10; i++)
    {
        printf("\n%d", i);
        for (j = 0; j < 10; j++)
            printf(" %c ", matriz[i][j]);
    }
}

void inicializaMatriz(char matriz[10][10])
{

    matriz[0][0] = 'Q';
    matriz[0][1] = 'F';
    matriz[0][2] = 'H';
    matriz[0][3] = 'Q';
    matriz[0][4] = 'P';
    matriz[0][5] = 'L';
    matriz[0][6] = 'P';
    matriz[0][7] = 'W';
    matriz[0][8] = 'S';
    matriz[0][9] = 'Y';
    matriz[1][0] = 'A';
    matriz[1][1] = 'B';
    matriz[1][2] = 'N';
    matriz[1][3] = 'W';
    matriz[1][4] = 'A';
    matriz[1][5] = 'Z';
    matriz[1][6] = 'O';
    matriz[1][7] = 'Q';
    matriz[1][8] = 'A';
    matriz[1][9] = 'T';
    matriz[2][0] = 'Z';
    matriz[2][1] = 'O';
    matriz[2][2] = 'U';
    matriz[2][3] = 'E';
    matriz[2][4] = 'S';
    matriz[2][5] = 'O';
    matriz[2][6] = 'T';
    matriz[2][7] = 'A';
    matriz[2][8] = 'G';
    matriz[2][9] = 'R';
    matriz[3][0] = 'W';
    matriz[3][1] = 'D';
    matriz[3][2] = 'J';
    matriz[3][3] = 'R';
    matriz[3][4] = 'D';
    matriz[3][5] = 'X';
    matriz[3][6] = 'I';
    matriz[3][7] = 'L';
    matriz[3][8] = 'M';
    matriz[3][9] = 'E';
    matriz[4][0] = 'S';
    matriz[4][1] = 'E';
    matriz[4][2] = 'M';
    matriz[4][3] = 'T';
    matriz[4][4] = 'F';
    matriz[4][5] = 'C';
    matriz[4][6] = 'U';
    matriz[4][7] = 'K';
    matriz[4][8] = 'N';
    matriz[4][9] = 'W';
    matriz[5][0] = 'X';
    matriz[5][1] = 'V';
    matriz[5][2] = 'I';
    matriz[5][3] = 'V';
    matriz[5][4] = 'A';
    matriz[5][5] = 'C';
    matriz[5][6] = 'A';
    matriz[5][7] = 'J';
    matriz[5][8] = 'B';
    matriz[5][9] = 'A';
    matriz[6][0] = 'E';
    matriz[6][1] = 'T';
    matriz[6][2] = 'K';
    matriz[6][3] = 'Y';
    matriz[6][4] = 'G';
    matriz[6][5] = 'V';
    matriz[6][6] = 'Y';
    matriz[6][7] = 'H';
    matriz[6][8] = 'V';
    matriz[6][9] = 'T';
    matriz[7][0] = 'D';
    matriz[7][1] = 'G';
    matriz[7][2] = 'O';
    matriz[7][3] = 'U';
    matriz[7][4] = 'H';
    matriz[7][5] = 'B';
    matriz[7][6] = 'T';
    matriz[7][7] = 'G';
    matriz[7][8] = 'C';
    matriz[7][9] = 'N';
    matriz[8][0] = 'C';
    matriz[8][1] = 'B';
    matriz[8][2] = 'L';
    matriz[8][3] = 'I';
    matriz[8][4] = 'J';
    matriz[8][5] = 'N';
    matriz[8][6] = 'R';
    matriz[8][7] = 'F';
    matriz[8][8] = 'X';
    matriz[8][9] = 'A';
    matriz[9][0] = 'R';
    matriz[9][1] = 'Y';
    matriz[9][2] = 'P';
    matriz[9][3] = 'O';
    matriz[9][4] = 'K';
    matriz[9][5] = 'M';
    matriz[9][6] = 'E';
    matriz[9][7] = 'D';
    matriz[9][8] = 'Z';
    matriz[9][9] = 'Q';
}
