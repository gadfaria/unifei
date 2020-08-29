#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef enum
{
    false,
    true
} bool;

//Modo recursivo !
int listaPrimosR[MAX];
bool testaPrimoR(int num, int div);
int inserePrimoR(int num, int pos);
void goldbachR(int num, int pos);

//Modo interativo !
int *primLista;
bool testaPrimoI(int n);
void inserePrimoI(int n);
void goldbachI(int n);

int main(int argc, char *argv[])
{
    int num;

    printf("\nDigite um numero par maior do que 4 para o teste !\n");
    scanf("%d", &num);

    goldbachI(num);
    goldbachR(num, 0);

    free(primLista);
    return 0;
}

bool testaPrimoR(int num, int div)
{

    if (num == 1)
    {
        return false;
    }
    if (div == 1)
    {
        return true;
    }
    else
    {
        if (num % div == 0)
        {
            return false;
        }
        else
        {
            testaPrimoR(num, div - 1);
        }
    }
}

int inserePrimoR(int num, int pos)
{

    if (num == 1)
    {
        return 0;
    }
    else
    {
        if (testaPrimoR(num, num - 1) == true)
        {
            listaPrimosR[pos] = num;
            inserePrimoR(num - 1, pos + 1);
        }
        else
        {
            inserePrimoR(num - 1, pos);
        }
    }
}

void goldbachR(int num, int pos)
{
    int teste;

    inserePrimoR(num, 0);
    teste = num - listaPrimosR[pos];

    if (testaPrimoR(teste, teste - 1) == true)
    {
        printf("\nForma recursiva :\n");
        printf("%d + %d = %d\n", listaPrimosR[pos], teste, num);
    }
    else
    {
        goldbachR(num, pos + 1);
    }
}

bool testaPrimoI(int num)
{
    int i;

    if (num == 1)
    {
        return false;
    }
    for (i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void inserePrimoI(int num)
{
    int i, pos = 0;
    primLista = (int *)malloc((num / 2) * sizeof(int *));

    for (i = 2; i < num; i++)
    {
        if (testaPrimoI(i) == true)
        {
            primLista[pos] = i;
            pos++;
        }
    }
}

void goldbachI(int num)
{
    int i;
    inserePrimoI(num);

    for (i = 0; i < num; i++)
    {
        if (testaPrimoI(num - primLista[i]) == true)
        {
            printf("\nForma interativa : \n");
            printf("%d + %d = %d\n", (num - primLista[i]), primLista[i], num);
            return;
        }
    }
}
