algoritmo "04"
// Autor : Gabriel Alves de Faria
// Data : 22/3/2017

var
    a : vetor[1..5,1..3]de inteiro
    b : vetor[1..5,1..3]de inteiro
    c : vetor[1..5,1..3]de inteiro
    x, y : inteiro

inicio
    para x de 1 ate 5 faca
        para y de 1 ate 3 faca
            escreval("Digite o valor da matriz A")
            leia(a[x,y])
            escreval("Digite o valor da matriz B")
            leia(b[x,y])
        fimpara
    fimpara
    para x de 1 a 5 faca
        para y de 1 a 3 faca
            c[x,y]<-a[x,y]+b[x,y]
        fimpara
    fimpara
 
fimalgoritmo
