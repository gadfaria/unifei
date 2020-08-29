algoritmo "01"
// Autor : Gabriel Alves de Faria
// Data : 15/3/2017

var
    num : inteiro
 
inicio
    escreval("Insira um numero")
    leia(num)
    se(num>0)entao
        escreval("Positivo")
    senao
        escreval("Negativo")
    fimse
    se((num mod 2)=0)entao
        escreval("Divisivel por 2")
    senao
        se((num mod 3)=0)entao
            escreval("Divisivel por 3")
        senao
            se((num mod 5)=0)entao
                escreval("Divisivel por 5")
            senao
                se((num mod 7)=0)entao
                    escreval("Divisivel por 7")
                senao
                    se((num mod 11)=0)entao
                        escreval("Divisivel por 11")
                    fimse
                fimse
            fimse
        fimse
    fimse
 
fimalgoritmo
