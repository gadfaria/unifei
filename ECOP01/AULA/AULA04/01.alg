algoritmo "01"
// Autor : Gabriel Alves de Faria
// Data : 28/3/2017

var
    num1, num2, x : inteiro
 
funcao soma (num1:inteiro ;num2:inteiro) : inteiro
    var
        s : inteiro
    inicio
        s <- 0
        enquanto (num1<=num2) faca
            s <- s+num1
            num1 <- num1+1
        fimenquanto
        retorne (s)
fimfuncao

inicio
    escreval("Digite dois numeros")
    leia(num1)
    leia(num2)
    se(num1>=0) e (num2>=0) entao
        x<-soma(num1;num2)
    fimse
    escreval("Soma entre o numero ",num1," e o numero",num2," igual a",x)
 
fimalgoritmo
