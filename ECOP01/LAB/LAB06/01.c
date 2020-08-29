#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    char computador, usuario, sorteio, resp = 's';

    printf("(r)ocha - (p)apel - (t)esoura - (l)agarto - (s)pock \n");

    do
    {
        printf("Digite a letra da opcao do usuario\n");
        srand(time(NULL));
        usuario = getchar();
        getchar();

        sorteio = rand() % 5;

        switch (sorteio)
        {
        case 0:
            computador = 'r';
            if (usuario == 'r')
                printf("EMPATE\n");
            else if (usuario == 'l')
                printf("VOCE PERDEU\n");
            else if (usuario == 'p')
                printf("VOCE VENCEU\n");
            else if (usuario == 't')
                printf("VOCE PERDEU\n");
            else if (usuario == 's')
                printf("VOCE VENCEU\n");
            break;

        case 1:
            computador = 'p';
            if (usuario == 'r')
                printf("VOCE PERDEU\n");
            else if (usuario == 'l')
                printf("VOCE VENCEU\n");
            else if (usuario == 'p')
                printf("EMPATE\n");
            else if (usuario == 't')
                printf("VOCE VENCEU\n");
            else if (usuario == 's')
                printf("VOCE PERDEU\n");
            break;

        case 2:
            computador = 't';
            if (usuario == 'r')
                printf("VOCE VENCEU\n");
            else if (usuario == 'l')
                printf("VOCE PERDEU\n");
            else if (usuario == 'p')
                printf("VOCE PERDEU\n");
            else if (usuario == 't')
                printf("EMPATE\n");
            else if (usuario == 's')
                printf("VOCE VENCEU\n");
            break;

        case 3:
            computador = 'l';
            if (usuario == 'r')
                printf("VOCE VENCEU\n");
            else if (usuario == 'l')
                printf("EMPATE\n");
            else if (usuario == 'p')
                printf("VOCE PERDEU\n");
            else if (usuario == 't')
                printf("VOCE VENCEU\n");
            else if (usuario == 's')
                printf("VOCE PERDEU\n");
            break;

        case 4:
            computador = 's';
            if (usuario == 'r')
                printf("VOCE PERDEU\n");
            else if (usuario == 'l')
                printf("VOCE VENCEU\n");
            else if (usuario == 'p')
                printf("VOCE VENCEU\n");
            else if (usuario == 't')
                printf("VOCE PERDEU\n");
            else if (usuario == 's')
                printf("EMPATE\n");
            break;
        }
        printf("Usuario %c\n", usuario);
        printf("Computador %c\n", computador);

        printf("Voce deseja continuar ? Digite s para continuar ou n para sair\n");
        scanf("%c", &resp);
        getchar();

    } while (resp == 's');

    return 0;
}
