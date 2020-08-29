#include <stdio.h>
#include <string.h>

int main (int argc, char*argv []){
    char frase[50], i, tam;

    printf ("\nEscreva uma frase ! \n");
    gets (frase);

    tam = strlen (frase);

    for (i = 0; i < tam; i++){
        if (frase[i] == ' ')

        else if (frase[i] == 'X') frase[i] = 'A';
        else if (frase[i] == 'Y') frase[i] = 'B';
        else if (frase[i] == 'Z') frase[i]='C';
        else frase[i] = frase[i]+3;
    }

    printf ("%s", frase);

    return 0;


}
