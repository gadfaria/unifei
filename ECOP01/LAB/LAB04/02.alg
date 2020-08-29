algoritmo "02"

var
    algo: vetor [1..10] de inteiro
    prog : vetor [1..5] de inteiro
    estru : vetor [1..7] de inteiro
    i, a, b, c : inteiro
    resp : caracter
 
inicio
    para i de 1 ate 100 faca
        se (a<=10) entao
            escreval("O aluno ",i," cursa algoritimo ?")
            leia(resp)
            se (resp="sim") entao
                algo[i] <- 1
                a <- a+1
            senao
                algo[i] <- 0
            fimse
        fimse
        se (b<=5) entao
            escreval("O aluno",i," cursa programa�ao ?")
            leia(resp)
            se (resp="sim") entao
                prog[i] <- 1
                b <- b+1
            senao
                prog[i] <- 0
            fimse
        fimse
        se(c<=7) entao
            escreval("O aluno",i," cursa estrutura de dados ?")
            leia(resp)
            se (resp="sim") entao
                estru[i] <- 1
                c <- c+1
            senao
                estru[i] <- 0
            fimse
        fimse
    fimpara
    para i de 1 ate 100 faca
        se(algo[i]=1) e (prog[i]=1) e (estru[i]=0) entao
            escreval("O aluno ",i," cursa algoritmo e programa�ao e nao cursa estrutura de dados")
        fimse
    fimpara
    
fimalgoritmo
