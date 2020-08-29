algoritmo "02"
// Autor : Gabriel Alves de Faria
// Data : 28/3/2017

var
    valor : inteiro
 
procedimento conv(valor:inteiro)
    var
        hor, min, seg : real
    inicio
        hor <- valor/3600
        hor <- int(hor)
        min <- (valor-(hor*3600))/60
        min <- int(min)
        seg <- valor-(hor*3600)-(min*60)
        escreval(valor," seg tem um total de ",hor," horas, ",min," minutos e ",seg," segundos")
fimprocedimento

inicio
    escreval("Forne�a os segundos")
    leia(valor)
    conv(valor)
 
fimalgoritmo
