#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char frase[256], palavra[256], aux[256];
    int c = 0, cc = 0, tam, i;

    printf("Digite uma frase \n");
    gets(frase);

    printf("Digite uma palavra \n");
    gets(palavra);

    tam = strlen(frase);

    for (i = 0; i < tam; i++)
        ;
    {
        if ((frase[i] != ' ') && (frase[i] != '\0'))
        {
            aux[cc] = frase[i];
            cc++;
        }
        else
        {
            aux[cc] = '\0';
            if (strcmp(aux, palavra) == 0)
            {
                c++;
            }
            strcpy(aux, '\0');
            cc = 0;
        }
    }

    printf("%d", c);

    return 0;
}
