//Gabriel Alves de Faria - 2017
algoritmo "01"

var
    gra, rad, comp, sup, rep : real

inicio
    escreva("Digite o angulo em graus: ")
    leia(gra)
    comp <- 90-gra
    sup <- 180-gra
    rep <- 360-gra
    rad <- gra*PI/180
    sup <- sup*PI/180
    comp <- comp*PI/180
    rep <- rep*PI/180
    escreval(gra,"graus = ",rad," radianos")
    escreval("Complemento =",comp)
    escreval("Suplemento =",sup)
    escreval("Replemento =",rep)
fimalgoritmo
