//Gabriel Alves de Faria - 2017
algoritmo "01"

var
    cat1, cat2, hipo, a1, a2, a3 : real

inicio
    escreva("Digite o valor do cateto 1: ")
    leia(cat1)
    escreva("Digite o valor da hipotenusa: ")
    leia(hipo)
    cat2 < -raizq(hipo*hipo - cat1*cat1)
    escreval("cateto2 = ", cat2)
    a1 <- arcsen(cat1/hipo)/PI*180
    a2 <- arcsen(cat2/hipo)/PI*180
    a3 <- 180-a1-a2
    escreval("Angulos: ",a1:2:2," , ",a2:2:2," , ",a3)
fimalgoritmo
