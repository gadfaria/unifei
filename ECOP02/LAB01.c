#include <stdio.h>
#include <string.h>

typedef enum
{
    false,
    true
} bool;

char lista[5][20];
int dispo = 0;

bool buscaNome(char nome[20]);
bool insereNome(char nome[20]);
void imprimeListaEst();

int main(int argc, char *argv)
{
    char nome[20];
    int i = 0;

    while (i < 5)
    {
        printf("\nDigite um nome\n");
        gets(nome);

        if (buscaNome(nome) == false)
        {
            if (insereNome(nome) == true)
            {
                printf("\nNome inserido\n");
                i++;
            }
        }
        else
        {
            printf("\nNome ja esta na lista\n");
        }
    }
    imprimeListaEst();
}

bool buscaNome(char nome[20])
{
    int i = 0;

    while ((i < dispo) && (strcmp(lista[i], nome) < 0))
    {
        i++;
    }

    if ((i < dispo) && (strcmp(lista[i], nome) == 0))
        return true;
    else
        return false;
}

bool insereNome(char nome[20])
{
    int i = dispo;

    if (dispo > 5)
    {
        return false;
    }
    else
    {
        while ((i > 0) && (strcmp(lista[i - 1], nome) > 0))
        {
            strcpy(lista[i], lista[i - 1]);
            i--;
        }
        strcpy(lista[i], nome);
        dispo++;
        return true;
    }
}

void imprimeListaEst()
{
    int i = 0;

    while (i < dispo)
    {
        printf(" %s ", lista[i]);
        i++;
    }
}
