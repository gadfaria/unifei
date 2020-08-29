algoritmo "01"
// Autor : Gabriel Alves de Faria

var
    i, num, metade, resto : inteiro

inicio
    escreva("digite numero inteiro: ")
    leia(num)
    metade <- num div 2
    i <- 2
    resto <- num mod i
    enquanto ((i <= metade) e (resto > 0)) faca
        i <- i + 1
        resto <- num mod i
    fimenquanto
    se i > metade entao
        escreva("Primo")
    senao
        escreva("N�o � primo")
    fimse
fimalgoritmo
