#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;

typedef struct no
{
    int valor;
    struct no *prox;
} noCedula;

noCedula *pilha[7];

int valorNota[7] = {1, 2, 5, 10, 20, 50, 100};

void inicializaPilha();
void abastecePilha(int quant, int v);
void imprimeSaldo();
void imprimeSomaCedulas();
bool saqueDisponivel(int valor);
bool saque(int valor);

int main(int argc, char *argv[])
{
    int valor;

    inicializaPilha();

    abastecePilha(80, 100);
    abastecePilha(70, 50);
    abastecePilha(150, 20);
    abastecePilha(200, 10);
    abastecePilha(30, 5);
    abastecePilha(55, 2);
    abastecePilha(100, 1);

    imprimeSaldo();

    printf("\nDigite um valor a ser sacado !\n");
    scanf("%d", &valor);

    if (saqueDisponivel(valor) == true)
    {
        printf("\nSaque disponivel\n");
    }
    else
    {
        printf("\nNao disponivel\n");
    }
    if (saque(valor) == true)
    {
        printf("\nSaque realizado com sucesso");
    }
    else
    {
        printf("\nSem saque\n");
    }
    imprimeSaldo();

    return 0;
}

void inicializaPilha()
{
    int i;

    for (i = 0; i < 7; i++)
    {
        pilha[i] = NULL;
    }
}

void abastecePilha(int quant, int valor)
{
    int i, pos;
    noCedula *novo;

    switch (valor)
    {
    case 1:
        pos = 0;
        break;
    case 2:
        pos = 1;
        break;
    case 5:
        pos = 2;
        break;
    case 10:
        pos = 3;
        break;
    case 20:
        pos = 4;
        break;
    case 50:
        pos = 5;
        break;
    case 100:
        pos = 6;
        break;
    default:
        printf("\nValor de cedula inv�lido !\n");
        break;
    }
    for (i = 0; i < quant; i++)
    {
        novo = (noCedula *)malloc(sizeof(noCedula));
        novo->valor = valor;
        novo->prox = pilha[pos];
        pilha[pos] = novo;
    }
}

void imprimeSaldo()
{
    noCedula *atual;
    int i, soma = 0;

    for (i = 0; i < 7; i++)
    {
        atual = pilha[i];

        while (atual != NULL)
        {
            soma += atual->valor;
            atual = atual->prox;
        }
    }
    printf("\nSaldo = %d\n", soma);
}

void imprimeSomaCedulas()
{
    noCedula *atual;
    int i, soma = 0;

    for (i = 0; i < 7; i++)
    {
        atual = pilha[i];
        soma = 0;

        while (atual != NULL)
        {
            soma += atual->valor;
            atual = atual->prox;
        }
        printf("\nSaldo em notas de %d = %d\n", valorNota[i], soma);
    }
    printf("\n");
}

bool saqueDisponivel(int valor)
{
    int i;
    noCedula *atual;

    for (i = 6; i >= 0; i--)
    {
        atual = pilha[i];

        while ((atual != NULL) && ((valor / valorNota[i]) >= 1))
        {
            valor -= atual->valor;
            atual = atual->prox;
        }
    }

    if (valor == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool saque(int valor)
{
    int i;
    noCedula *atual;

    if (saqueDisponivel(valor) == true)
    {
        for (i = 6; i >= 0; i--)
        {
            atual = pilha[i];

            while ((pilha[i] != NULL) && ((valor / valorNota[i]) >= 1))
            {
                valor -= pilha[i]->valor;
                atual = pilha[i];
                pilha[i] = pilha[i]->prox;
                free(atual);
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
