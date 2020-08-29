algoritmo "04"
// Autor : Gabriel Alves de Faria
// Data : 15/3/2017

var
 x, c, num : inteiro
 
inicio
    escreval("Informe um numero")
    leia(num)
    x <- 0
    para c de 2 ate (num-1)faca
        se((num mod c)=0)entao
            x<-x+1
        fimse
    fimpara
    se(x=0)entao
        escreval("� um numero primo")
    senao
        escreval("N�o � um numero primo")
    fimse
 
fimalgoritmo
