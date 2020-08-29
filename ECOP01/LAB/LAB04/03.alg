algoritmo "03"

var
    a : vetor[1..3,1..2] de inteiro
    b : vetor[1..2,1..4] de inteiro
    c : vetor[1..3,1..4] de inteiro
    i, j, k : inteiro

inicio
    para i de 1 ate 3 faca
        escreval("Linha ",i)
        para j de 1 ate 2 faca
            escreval("Digite o valor da matriz A")
            leia(a[i,j])
        fimpara
    fimpara
    para i de 1 ate 2 faca
        escreval("Linha ",i)
        para j de 1 ate 4 faca
            escreval("Digite o valor da matriz B")
            leia(b[i,j])
        fimpara
    fimpara
    para i de 1 ate 3 faca
        para j de 1 ate 4 faca
            para k de 1 ate 2 faca
                c[i,j] <- a[i,1]*b[1,j]+a[i,2]*b[2,j]
            fimpara
        fimpara
    fimpara
 
fimalgoritmo


