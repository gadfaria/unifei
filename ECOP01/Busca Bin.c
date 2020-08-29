#include <stdio.h>
#include <math.h>
#define MAX 20

int busca(int vet[20], int elem)
{
    int meio, inf = 0;
    int sup = MAX - 1;

    while (inf <= sup)
    {
        meio = (inf + sup) / 2;
        if (elem == vet[meio])
        {
            return meio;
        }
        else
        {
            if (elem < vet[meio])
            {
                sup = meio - 1;
            }
            else
            {
                inf = meio + 1;
            }
        }
    }
    return -1;
}

int buscaBin(int vet[], int elem, int esq, int dir)
{
    if (esq <= dir)
    {
        int meio;
        meio = (esq + dir) / 2;
        if (vet[meio] == elem)
            return meio;
        else if (vet[meio] < elem)
            return buscaBin(vet, elem, meio + 1, dir);
        else
            return buscaBin(vet, elem, esq, meio - 1);
    }
    return -1;
}

int main(int argc, char *argv[])
{
    int vet[MAX], elem, i, pos;
    vet[0] = 1;

    printf(" [%d] ", vet[0]);
    for (i = 1; i < MAX; i++)
    {
        vet[i] = vet[i - 1] + (rand() % 4) + 1;
        printf(" [%d] ", vet[i]);
    }
    printf("\n");
    printf("Elemento a ser procurado = ");
    scanf("%d", &elem);
    pos = busca(vet, elem);
    printf("Posicao  = %d\n", pos);
    pos = buscaBin(vet, elem, 0, 19);
    printf("Posicao = %d\n", pos);
    return 0;
}
