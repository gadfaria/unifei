#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define preordem 0
#define emordem 1
#define posordem 2

#define MAX 10

typedef struct no
{
  char cep[9];
  char uf[3];
  char cidade[31];
  char logradouro[61];
  struct no *esq;
  struct no *dir;
} noCEP;

noCEP *arvBinaria;

int quant;

void inserirNoArvoreBinaria(FILE *arq)
{
  char linha[200];
  char *substring;
  int i;
  noCEP *ant = NULL;
  noCEP *atual = arvBinaria;
  noCEP *novo;

  //aloca o novo na memoria
  novo = (noCEP *)malloc(sizeof(noCEP));

  //le a linha completa e preenche os dados no novo cep
  fgets(linha, 200, arq);

  //separa os tokens pelo delimitador \t
  substring = strtok(linha, "\t");

  //obtem o cep
  if (substring != NULL)
  {
    strcpy(novo->cep, substring);
  }
  substring = strtok(NULL, "\t");

  //obtem a uf
  if (substring != NULL)
    strcpy(novo->uf, substring);

  substring = strtok(NULL, "\t");

  //obtem a cidade
  if (substring != NULL)
    strcpy(novo->cidade, substring);

  substring = strtok(NULL, "\t");

  //obtem o logradouro
  if (substring != NULL)
    strcpy(novo->logradouro, substring);

  novo->esq = NULL;
  novo->dir = NULL;

  while (atual != NULL)
  {
    ant = atual;

    if (strcmp(novo->cep, atual->cep) < 0)
    {
      atual = atual->esq;
    }
    else
    {
      atual = atual->dir;
    }
  }

  if (ant == NULL)
  {
    arvBinaria = novo;
  }
  else
  {
    if (atual == NULL)
    {
      if (strcmp(novo->cep, ant->cep) < 0)
      {
        ant->esq = novo;
      }
      else
      {
        ant->dir = novo;
      }
    }
  }
  quant++;
}

void imprimeNoCep(noCEP *novo)
{
  printf("%s - %s - %s - %s\n", novo->cep, novo->uf, novo->cidade, novo->logradouro);
}

void imprimePreOrdem(noCEP *atual)
{
  if (atual != NULL)
  {
    imprimeNoCep(atual);
    imprimePreOrdem(atual->esq);
    imprimePreOrdem(atual->dir);
  }
}

void imprimeEmOrdem(noCEP *atual)
{
  if (atual != NULL)
  {
    imprimeEmOrdem(atual->esq);
    imprimeNoCep(atual);
    imprimeEmOrdem(atual->dir);
  }
}

void imprimePosOrdem(noCEP *atual)
{
  if (atual != NULL)
  {
    imprimePosOrdem(atual->esq);
    imprimePosOrdem(atual->dir);
    imprimeNoCep(atual);
  }
}

void buscaArvoreBinaria(noCEP *atual, char cep[9])
{
  if (atual != NULL)
  {
    if (strcmp(cep, atual->cep) == 0)
    {
      imprimeNoCep(atual);
    }
    else
    {
      if (strcmp(cep, atual->cep) < 0)
      {
        buscaArvoreBinaria(atual->esq, cep);
      }
      else
      {
        buscaArvoreBinaria(atual->dir, cep);
      }
    }
  }
  else
  {
    printf("\nNao encontrado\n");
  }
}

int main(int argc, char *argv[])
{
  FILE *arq;
  int opcaoMenu, c = 0;
  char cepProcurado[9];
  noCEP *cepEncontrado;

  arvBinaria = NULL;

  //o arquivo eh lido e inserido os elementos na arvore
  arq = fopen("baseCep.txt", "r");

  if (!arq)
  {
    printf("O arquivo nao pode ser aberto.\n");
    exit(1);
  }

  printf("\nInserindo elementos na arvore... \n");
  while (!feof(arq) && (c < 10))
  {
    //para cada linha do arquivo pe chamada
    //a funcao de insercao na arvore binaria
    inserirNoArvoreBinaria(arq);
    c++;
  }
  fclose(arq);

  opcaoMenu = 1;
  while (opcaoMenu != 4)
  {
    quant = 0;

    printf("|Selecione uma das opcoes do menu: |\n");
    printf("|1 - Pre-ordem                |\n");
    printf("|2 - Em-ordem                 |\n");
    printf("|3 - Pos-ordem                |\n");
    printf("|4 - Sair                     |\n\n");
    printf(">");

    scanf("%d", &opcaoMenu);
    switch (opcaoMenu)
    {
    case 1:
      printf("Imprime em pre-ordem: \n");
      imprimePreOrdem(arvBinaria);
      printf("\n");
      break;

    case 2:
      printf("Imprime em in-ordem: \n");
      imprimeEmOrdem(arvBinaria);
      printf("\n");
      break;

    case 3:
      printf("Imprime em pos-ordem: \n");
      imprimePosOrdem(arvBinaria);
      printf("\n");
      break;

    case 4:
      printf("Saindo do menu impressoes: ");
      break;
    }
  }

  printf("\n>>> Busca por um cep: \n");
  printf(">> Digite um cep: ");
  scanf("%s", cepProcurado);
  buscaArvoreBinaria(arvBinaria, cepProcurado);

  printf("Encerrando o programa...\n");

  free(arvBinaria);

  system("PAUSE");
  return 0;
}
