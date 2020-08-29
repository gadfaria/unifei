algoritmo "03"
// Autor : Gabriel Alves de Faria
// Data : 22/3/2017

var
    mat : vetor[1..5,1..5]de inteiro
    c1, c2, soma2, soma1 : inteiro
    med1, med2  :real
    x, y : inteiro

inicio
    med1 <- 0
    med2 <- 0
    c1 <- 0
    soma1 <- 0
    soma2 <- 0
    c2 <- 0
    para x de 1 ate 5 faca
        para y de 1 ate 5 faca
            escreval("Digite o numero")
            leia(mat[x,y])
        fimpara
    fimpara
    para x de 1 ate 5 faca
        para y de 1 ate 5 faca
            se (x>y) entao
                soma1 <- soma1+mat[x,y]
                c1 <- c1+1
            fimse
            se (x<y) entao
                soma2 <- soma2+mat[x,y]
                c2 <- c2+1
            fimse
        fimpara
    fimpara
    med1 <- soma1/c1
    med2 <- soma2/c2
    escreval("Media 1",med1)
    escreval("Media 2",med2)
 
fimalgoritmo
