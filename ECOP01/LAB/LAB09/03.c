#include <stdio.h>

void ordena (int vetor[5]){
    int i, j, aux;

    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            if (vetor[i] < vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}


int main (int argc, char*argv []){
    int vetor[5], i;

    printf ("\nDigite um vetor de cinco elementos ! \n");
    for (i = 0; i < 5; i++) scanf ("%d", &vetor[i]);

    ordena(vetor);

    for (i = 0;i < 5; i++) printf ("%d", vetor[i]);

    return 0;

}
