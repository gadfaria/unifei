algoritmo "02"
// Autor : Gabriel Alves de Faria
// Data : 15/3/2017

var
    a1, a2, a3 : inteiro
    a, b : inteiro
 
inicio
    escreval("Forne�a os tres angulos do triangulo")
    leia(a1)
    leia(a2)
    leia(a3)
    a <- 0
    b <- 0
    a <- a1+a2
    b <- a+a3
    se((a1+a2)>=a3) e ((a2+a3)>=a1) e ((a3+a1)>=a2) e (b=180) entao
        escreval("Forma um triangulo")
        se(a1=a2) e (a2=a3)entao
            escreval("Equil�tero")
        senao
            se(a1<>a2) e (a2<>a3) e (a3<>a1)entao
                escreval("Escaleno")
            senao
                escreval("Is�sceles")
            fimse
        fimse
    senao
        escreval("Nao forma um triangulo")
    fimse
 
fimalgoritmo
