//Gabriel Alves de Faria - 2017
algoritmo "03"

var
    xa, ya, xb, yb, xc, yc : inteiro
    y1, y2, x1, x2, y3, x3, y4 : real
    per : caracter

inicio
    repita
        escreval("Forne�a os pontos A")
        leia(xa)
        leia(ya)
        escreval("Forne�a os pontos B")
        leia(xb)
        leia(yb)
        escreval("Forne�a os pontos C")
        leia(xc)
        leia(yc)
        y1 <- (ya-yb)
        x1 <- (xa-xb)
        y2 <- (yb-yc)
        x2 <- (xb-xc)
        y3 <- y1/x1
        y4 <- y2/x2
        se(y3=y4)entao
            escreval("� colinear")
        senao
            escreval("N�o � colinear")
        fimse
        escreval("Voce quer cotinuar?")
        leia(per)
    ate (per="nao")
fimalgoritmo
