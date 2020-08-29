algoritmo "04"

var
 algo: vetor [1..10] de inteiro
 prog : vetor [1..5] de inteiro
 estru : vetor [1..7] de inteiro
 a, b, c, j : inteiro
 resp : caracter

inicio
    a <- 1
    b <- 1
    c <- 1
    j <- 1
    enquanto (a<=10) e (b<=5) e (c<=7) faca
        se (a<=10) entao
            escreval("O aluno ",j," cursa algoritimo ?")
            leia(resp)
            se (resp="sim") entao
                algo[a] <- j
                a <- a+1
            fimse
        fimse
        se (b<=5) entao
            escreval("O aluno",j," cursa programa�ao ?")
            leia(resp)
            se (resp="sim") entao
                prog[b] <- j
                b <- b+1
            fimse
        fimse
        se(c<=7) entao
            escreval("O aluno",j," cursa estrutura de dados ?")
            leia(resp)
            se (resp="sim") entao
                estru[c] <- j
                c <- c+1
            fimse
        fimse
        j<-j+1
    fimenquanto
    se (a=b) e (b<>c) entao
        escreval("O aluno ",a," cursa algoritmo e programa�ao")
    fimse
fimalgoritmo
