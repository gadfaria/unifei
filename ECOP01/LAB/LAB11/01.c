#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;
typedef struct
{
    char matricula[15];
    char nome[30], curso[5], disciplina[5];
    float nota1, nota2;
} t_aluno;

FILE *arq;

void consultarAluno();
void adicionaAluno();
void exameAluno();
char menu();

int main(int argc, char **argv)
{
    char resp;

    arq = fopen("alunos.txt", "r+");
    if (arq == NULL)
    {
        arq = fopen("alunos.txt", "w+");
    }

    while (resp != 'S')
    {
        resp = menu();
        switch (resp)
        {
        case 'A':
            adicionaAluno();
            break;
        case 'C':
            consultarAluno();
            break;
        case 'E':
            exameAluno();
            break;
        case 'S':
            printf("\nSaiu\n");
        default:
            printf("\nOpcao invalida\n");
        }
    }

    fclose(arq);
    return 0;
}

char menu()
{
    char resp;

    printf("\nEscolha uma das op��es\n");
    printf("\n(A) - Adicionar aluno \n");
    printf("\n(C) - Consultar alunos \n");
    printf("\n(E) - Consultar alunos de exame \n");
    printf("\n(S) - Sair \n");

    resp = getchar();
    getchar();

    return resp;
}

void exameAluno()
{
    t_aluno dadosAluno;
    float media;

    fseek(arq, 0, SEEK_SET);

    while (fread(&dadosAluno, sizeof(t_aluno), 1, arq))
    {
        media = 0;
        media = (dadosAluno.nota1 + dadosAluno.nota2) / 2;
        if (media >= 3 && media < 6)
        {
            printf("\nO aluno %s esta de exame\n", dadosAluno.nome);
        }
    }
}

void consultarAluno()
{
    t_aluno dadosAluno;
    float media;

    fseek(arq, 0, SEEK_SET);

    while (fread(&dadosAluno, sizeof(t_aluno), 1, arq))
    {
        media = (dadosAluno.nota1 + dadosAluno.nota2) / 2;
        printf("\n%s %s %.2f", dadosAluno.nome, dadosAluno.matricula, media);
    }
}

void adicionaAluno()
{
    t_aluno dadosAluno;
    int c = 1;
    char matricula[15];

    while (c == 1)
    {
        printf("\nDigite o numero de matricula do aluno a ser cadastrado !\n");
        scanf("%s", matricula);
        getchar();

        fseek(arq, 0, SEEK_SET);
        c = 0;
        while (fread(&dadosAluno, sizeof(t_aluno), 1, arq))
        {
            if (strcmp(dadosAluno.matricula, matricula) == 0)
            {
                printf("\nNumero de matricula ja existente !\n");
                c = 1;
            }
        }
    }

    strcpy(dadosAluno.matricula, matricula);

    printf("\nDigite o nome do aluno, curso e a disciplina cursada !\n");
    gets(dadosAluno.nome);
    getchar();
    gets(dadosAluno.curso);
    getchar();
    gets(dadosAluno.disciplina);
    printf("\nAgora digite a nota 1 e 2\n");
    scanf("%f", &dadosAluno.nota1);
    getchar();
    scanf("%f", &dadosAluno.nota2);
    getchar();

    fseek(arq, 0, SEEK_END);

    fwrite(&dadosAluno, sizeof(t_aluno), 1, arq);
}
