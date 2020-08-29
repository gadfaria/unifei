#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[30];
    int numConta;
    float saldo;
} stContaCliente;

void cadastro(stContaCliente cliente[15]; int i);

int main(int argc, char *argv[])
{
    stContaCliente cliente[15];
    int i = 0, j, menor, valorM, resp;

    printf(" \nEscolha uma op��o\n");
    printf(" \n1.cadastro de conta\n");
    printf(" \n2.visualizar todas as contas de um cliente\n");
    printf(" \n3.excluir a conta com menor saldo\n");
    scanf("%d", &resp);
    getchar();

    switch (resp){
        case 1:
            void(cliente, i);
            i++;
        break;

        case 2:
            printf(" \nDigite o nome da conta\n");
            gets(nomeconta);
            getchar();

            for(j=0; j<i; j++){
                if(strcmp(nomeconta,cliente[j].numConta)==0){
                    printf("%d", cliente[j].numConta);
                }
            }
        break;
        
        case 3:
            menor=9999
            for (j=0; j<i; j++){
                if(cliente[j].saldo < menor){
                    menor=cliente[j].saldo;
                    valorM=j
                }
            }
            free(cliente[valorM]);
            break;
        }

    return 0;

}


void cadastro (stContaCliente cliente[15]; int i){
    int c=0,a=0,numeroC;

        printf(" \nDigite o nome do cliente \n");
        gets(cliente[i].nome);
        getchar();

        while(d=0){
            printf(" \nDigite o numero da conta \n");
            scanf("%d", &numeroC);
            getchar();

            for(j=0, j<i, j++){
                if(numeroC==cliente[j].numConta){
                    c++;
                }
            }

            if(c=0){
                cliente[i].numConta==numeroC;
                d++
            }
            else{
                prinf(" \nDigite novamente \n")
            }
        }

        printf(" \nDigite o saldo da conta \n");
        scanf("%f", &cliente[i].saldo);
        getchar();
}
