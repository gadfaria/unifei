#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 2000000

int grafo[MAX][MAX]; //Representacao matricial dos grafos
bool visitado[MAX];

typedef struct no
{
    int aresta;
    struct no *prox;
} noGrafo;

noGrafo *listaGrafo[MAX];

//Funcao para ler a matriz
void leGrafo(int g[][MAX], int ordem, int tamanho)
{
    for (int i = 0; i < ordem; i++)
        for (int j = 0; j < tamanho; j++)
            scanf("%d", &g[i][j]);
}

//Imprime as opcoes
void menu()
{
    printf("\n1 - Verifica se o grafo e regular (Matriz de Adjacencia)\n2 - Verifica se o grafo e K-regular (Matriz de Incidencia)\n");
    printf("3 - Verifica se o grafo e eureliano (Matriz de Incidencia)\n4 - Encontra o numero cromatico do grafo (Matriz de Incidencia)\n");
    printf("5 - Verifica se o grafo e completo (Lista de Adjacencia)\n6 - Encontra o complemento do grafo (Matriz de Adjacencia)\n");
    printf("7 - Encontra o numero de componentes conexas (Matriz de Adjacencia)\n");
    printf("11 - Busca em profundidade em um grafo (Matriz de Adjacencia)\n12 - Busca em largura em um grafo (Matriz de Adjacencia)\n");
}

//Impressao da matriz
void imprimeMatriz(int g[][MAX], int ordem, int tamanho)
{
    for (int i = 0; i < ordem; i++)
    {
        printf("\n");
        for (int j = 0; j < tamanho; j++)
            printf("%d ", g[i][j]);
    }
    printf("\n\n");
}

//Verifica se grafo e regular com Matriz de Adjacencias
bool regular(int ordem)
{
    int grau = 0, grau_aux;
    for (int i = 0; i < ordem; i++)
        grau += (grafo[0][i] != 0 ? 1 : 0);
    for (int i = 1; i < ordem; i++)
    {
        grau_aux = 0;
        for (int j = 0; j < ordem; j++)
            grau_aux += (grafo[i][j] != 0 ? 1 : 0);
        if (grau != grau_aux)
            return false;
    }
    return true;
}

//Verifica se o grafo e K-Regular com Matriz de Incidencia
bool kRegular(int ordem, int tamanho, int k)
{
    int aux;

    for (int i = 0; i < ordem; i++)
    {
        aux = 0;
        for (int j = 0; j < tamanho; j++)
            aux = aux + grafo[i][j];
        if (aux != k)
            return false;
    }

    return true;
}

//Busca em profundidade para matriz de incidencia
bool buscaProfInc(int ordem, int tamanho, int inicio)
{
    visitado[inicio] = true;
    for (int j = 0; j < tamanho; j++)
        if (grafo[inicio][j] > 0)
            for (int i = 0; i < ordem; i++)
                if (!visitado[i] && grafo[i][j] > 0)
                    buscaProfInc(ordem, tamanho, i);
}

//Colocar o vetor visitado como false
void zeraVisitados(int ordem)
{
    for (int i = 0; i < ordem; i++)
        visitado[i] = false;
}

//Verifica se o grafo � eureliano com matriz de incidencia
bool eureliano(int ordem, int tamanho)
{
    int grau;

    zeraVisitados(ordem);
    buscaProfInc(ordem, tamanho, 0);

    for (int i = 0; i < ordem; i++)
        if (!visitado[i])
            return false;

    for (int i = 0; i < ordem; i++)
    {
        grau = 0;
        for (int j = 0; j < tamanho; j++)
            if (grafo[i][j] > 0)
                grau++;
        if (grau % 2 != 0)
            return false;
    }
    return true;
}

//Retorna o numero cromatico do grafo
int cromatico(int ordem, int tamanho)
{
    noGrafo *grau[ordem];
    int grauD[ordem], aux = -1, pos;
    int cores[ordem], cor = 1, vizinho;

    for (int i = 0; i < ordem; i++)
    {
        grau[i] = (noGrafo *)malloc(sizeof(noGrafo));
        cores[i] = 0;
    }

    for (int i = 0; i < ordem; i++)
    {
        grau[i]->aresta = 0;
        for (int j = 0; j < tamanho; j++)
            if (grafo[i][j] == 1)
                grau[i]->aresta = grau[i]->aresta + 1;
    }

    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
            if (grau[j]->aresta > aux)
            {
                aux = grau[j]->aresta;
                pos = j;
            }
        grauD[i] = pos;
        aux = -1;
        grau[pos]->aresta = -2;
    }

    for (int i = 0; i < ordem; i++)
    {
        if (cores[grauD[i]] == 0)
        {
            cores[grauD[i]] = cor;
            for (int j = 0; j < ordem; j++)
            {
                if (grauD[i] != j)
                {
                    vizinho = false;
                    for (int k = 0; k < tamanho; k++)
                    {
                        if ((grafo[grauD[i]][k] == grafo[j][k]) && (grafo[j][k] == 1))
                            vizinho = true;
                    }
                    if (vizinho == false)
                        cores[j] = cor;
                }
            }
            cor++;
        }
    }
    return cor - 1;
}

//Imprime uma matriz do complemento de um grafo
void complemento(int ordem)
{
    int grafoAux[MAX][MAX];

    for (int i = 0; i < ordem; i++)
        for (int j = 0; j < ordem; j++)
        {
            if (i == j)
            {
                grafoAux[i][j] = 0;
            }
            else
            {
                if (grafo[i][j] == 1)
                {
                    grafoAux[i][j] = 0;
                }
                else
                {
                    if (grafo[i][j] == 0)
                    {
                        grafoAux[i][j] = 1;
                    }
                }
            }
        }
    imprimeMatriz(grafoAux, ordem, ordem);
}

//Busca em profundidade para matriz de adjacencia
bool buscaProfAdj(int ordem, int inicio)
{
    visitado[inicio] = true;
    printf("%d - ", inicio);
    for (int i = 0; i < ordem; i++)
        if (!visitado[i] && grafo[inicio][i] > 0)
            buscaProfAdj(ordem, i);
}

//Verifica se o grafo e completo
bool completo(int ordem)
{
    int grau;
    noGrafo *aux;

    for (int i = 0; i < ordem; i++)
    {
        aux = listaGrafo[i];
        grau = 0;
        while (aux->aresta != -1)
        {
            grau++;
            aux = aux->prox;
        }
        if (grau != ordem - 1)
            return false;
    }
    return true;
}

//Le valores para uma lista de adjacencia
void leLista(int ordem)
{
    noGrafo *novo;
    int aux = 0;
    for (int i = 0; i < ordem; i++)
    {
        listaGrafo[i] = (noGrafo *)malloc(sizeof(noGrafo));
        novo = listaGrafo[i];
        aux = 0;
        while (aux != -1)
        {
            scanf("%d", &aux);
            novo->aresta = aux;
            novo->prox = (noGrafo *)malloc(sizeof(noGrafo));
            novo = novo->prox;
        }
    }
}

//Imprime a lista de adjacencia
void imprimeLista(int ordem)
{
    noGrafo *aux;

    for (int i = ordem - 1; i >= 0; i--)
    {
        aux = listaGrafo[i];
        printf("%d -> ", i);
        do
        {
            printf("%d ", aux->aresta);
            aux = aux->prox;
        } while (aux->aresta != -1);
        printf("\n");
    }
}

//Retorna o numero de componentes conexas do grafo
int componentesConexas(int ordem, int componentes, int inicio)
{
    buscaProfAdj(ordem, inicio);
    componentes++;
    for (int i = 0; i < ordem; i++)
    {
        if (visitado[i] == false)
        {
            componentes = componentesConexas(ordem, componentes, i);
        }
    }
    return componentes;
}
/*
.,,, primColorido(int ordem, int inicio){
    int cores[ordem-1], peso[ordem-1];

    while(1){
        for(int i=0; i<ordem; i++){
            if(grafo[inicio][i] && visitado[]){

            }
        }
    }
}
*/
//Teste de busca em largura com matriz de adjacencia
void buscaLargAjd(int ordem, int inicio)
{
    int vizinhos[ordem], c = 0;

    visitado[inicio] = true;
    for (int i = 0; i < ordem; i++)
        if (!visitado[i] && grafo[inicio][i])
        {
            vizinhos[c] = i;
            visitado[i] = true;
            printf("%d - ", i);
            c++;
        }
    if (c != 0)
    {
        for (int i = 0; i <= c; i++)
            buscaLargAjd(ordem, vizinhos[i]);
    }
}

int main()
{
    int operacao, ordem, tamanho;
    int a, b, p;
    int i, j, k;

    int soma;

    while (true)
    {
        menu(); //Menu para imprimir as opcoes
        scanf("%d", &operacao);
        printf("\n");
        if (!operacao)
            break;

        switch (operacao)
        {
        case 1: //Regular
            printf("Informe a ordem do grafo: ");
            scanf("%d", &ordem);
            leGrafo(grafo, ordem, ordem);
            imprimeMatriz(grafo, ordem, ordem);
            if (regular(ordem))
                printf("Grafo regular\n");
            else
                printf("Grafo nao regular\n");
            break;

        case 2: //K-Regular
            printf("Informe a quantidade de vertices, arestas e o valor do K a ser verificado: ");
            scanf("%d %d %d", &ordem, &tamanho, &k);
            leGrafo(grafo, ordem, tamanho);
            imprimeMatriz(grafo, ordem, tamanho);
            if (kRegular(ordem, tamanho, k))
                printf("Grafo %d-regular\n", k);
            else
                printf("Grafo nao %d-regular\n", k);
            break;

        case 3: //Eureliano
            printf("Informe a quantidade de vertices e arestas: ");
            scanf("%d %d", &ordem, &tamanho);
            leGrafo(grafo, ordem, tamanho);
            imprimeMatriz(grafo, ordem, tamanho);
            if (eureliano(ordem, tamanho))
            {
                printf("Grafo Eureliano\n");
            }
            else
            {
                printf("Grafo nao Eureliano\n");
            }
            break;

        case 4: //Numero cromatico
            printf("Informe a quantidade de vertices e arestas: ");
            scanf("%d %d", &ordem, &tamanho);
            leGrafo(grafo, ordem, tamanho);
            imprimeMatriz(grafo, ordem, tamanho);
            printf("%d \n", cromatico(ordem, tamanho));
            break;

        case 5: //Completo
            printf("Informe a quantidade de vertices: ");
            scanf("%d", &ordem);
            leLista(ordem);
            imprimeLista(ordem);

            if (completo(ordem))
            {
                printf("Grafo Completo\n");
            }
            else
            {
                printf("Grafo nao Completo\n");
            }
            break;

        case 6: //Complemento
            printf("Informe a ordem do grafo: ");
            scanf("%d", &ordem);
            leGrafo(grafo, ordem, ordem);
            imprimeMatriz(grafo, ordem, ordem);
            complemento(ordem);
            break;

        case 7: //Componentes conexas
            printf("Informe a ordem do grafo: ");
            scanf("%d", &ordem);
            leGrafo(grafo, ordem, ordem);
            imprimeMatriz(grafo, ordem, ordem);
            printf("%d \n", componentesConexas(ordem, 0, 0));
            break;

            /* case 10: //Prim-Colorido
                printf("Informe a ordem do grafo: ");
                scanf("%d", &ordem);
                leGrafo(grafo, ordem, ordem);
                imprimeMatriz(grafo, ordem, ordem);
            */

        case 11: //Busca em prof
            printf("Informe a ordem do grafo: ");
            scanf("%d", &ordem);
            leGrafo(grafo, ordem, ordem);
            imprimeMatriz(grafo, ordem, ordem);
            zeraVisitados(ordem);
            buscaProfAdj(ordem, 0);
            break;

        case 12: //Busca em largura
            printf("Informe a ordem do grafo: ");
            scanf("%d", &ordem);
            leGrafo(grafo, ordem, ordem);
            imprimeMatriz(grafo, ordem, ordem);
            zeraVisitados(ordem);
            buscaLargAjd(ordem, 0);
            break;
        }
    }
    return (0);
}
