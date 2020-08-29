#include <stdio.h>

void inicializaMatriz(int matriz[10][10])
{
    int i, j;
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            matriz[i][j] = 0;
}

void imprimeOpcoes()
{
    printf("\nEscolha uma opcao \n");
    printf("1 � Caneta para cima: Robo desenha a partir do proximo movimento. \n");
    printf("2 � Caneta para baixo: Robo pode se mover sem desenhar.\n");
    printf("3 � Anda para esquerda: Verifica se e possivel andar para esquerda. Caso seja, anda e exibe matriz. \n");
    printf("4 � Anda para direita: Verifica se e possivel andar para direita. Caso seja, anda e exibe matriz. \n ");
    printf("5 � Anda para cima: Verifica se e possivel andar para cima. Caso seja, anda e exibe matriz. \n");
    printf("6 � Anda para baixo: Verifica se e possivel andar para baixo. Caso seja, anda e exibe matriz. \n");
    printf("7 � Termina Desenho: Exibe a matriz pela �ltima vez e sai do programa} \n");
}

void imprimaPiso(int matriz[10][10])
{
    int i, j;

    for (i = 0; i < 10; i++)
    {
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            if (matriz[i][j] == 0)
                printf("   ");
            else
            {
                if (matriz[i][j] == 1)
                    printf(" * ");
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int piso[10][10], resp = 10, linha = 0, coluna = 0;
    int pos_caneta;
    inicializaMatriz(piso);

    while (resp != 7)
    {
        imprimeOpcoes();
        scanf("%d", &resp);
        switch (resp)
        {
        case 1:
            pos_caneta = 0;
            break;
        case 2:
            pos_caneta = 1;
            break;
        case 3:
            if (coluna > 0)
            {
                coluna--;
                if (pos_caneta == 0)
                {
                    piso[linha][coluna] = 1;
                }
            }
            else
            {
                printf("\nOperacao Impossivel \n");
            }
            imprimaPiso(piso);
            break;
        case 4:
            if (coluna < 9)
            {
                coluna++;
                if (pos_caneta == 0)
                {
                    piso[linha][coluna] = 1;
                }
            }
            else
            {
                printf("\nOperacao Impossivel \n");
            }
            imprimaPiso(piso);
            break;
        case 5:
            if (linha > 0)
            {
                linha--;
                if (pos_caneta == 0)
                {
                    piso[linha][coluna] = 1;
                }
            }
            else
            {
                printf("\nOperacao Impossivel \n");
            }
            imprimaPiso(piso);
            break;
        case 6:
            if (linha < 9)
            {
                linha++;
                if (pos_caneta == 0)
                {
                    piso[linha][coluna] = 1;
                }
            }
            else
            {
                printf("\nOperacao Impossivel \n");
            }
            imprimaPiso(piso);
            break;
        }
    }
    return 0;
}
