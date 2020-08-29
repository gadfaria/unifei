//Gabriel Alves de Faria - 2017
algoritmo "02"

var
    h1, h2, h : inteiro
    m1, m2, m3, r, m : inteiro

inicio
    escreval("Escreve a hora de inicio do jogo em horas e minutos")
    leia(h1)
    leia(m1)
    escreval("Escreva a hora de termino do jogo em horas e minutos")
    leia(h2)
    leia(m2)
    se(h1>h2)entao
        h2 <- h2+24
        h <- (h2-h1)
    senao
        h <- (h2-h1)
    fimse
    se(m1>m2)entao
        m2 <- m2+60
        h <- h-1
        m <- m2-m1
    senao
        m <- m2-m1
    fimse
    escreval("O jogo teve duracao de ",h," horas e ",m," minutos")
fimalgoritmo
