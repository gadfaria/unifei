algoritmo "03"
// Autor : Gabriel Alves de Faria
// Data : 28/3/2017

var
    num : inteiro

procedimento TabelaMul(num:inteiro)
    var
        t, c : inteiro
    inicio
        para c de 1 ate 10 faca
            t <- 0
            t <- num*c
            escreval(num,"x",c,"=",t)
        fimpara
fimprocedimento

inicio
    escreval("Insira um numero")
    leia(num)
    TabelaMul(num)
fimalgoritmo
