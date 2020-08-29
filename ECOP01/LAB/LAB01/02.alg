//Gabriel Alves de Faria - 2017
algoritmo "02"

var
    lad1, lad2, ang, est : real

inicio
    escreval("Indique os lados do paralelogramo e o angulo: ")
    leia(lad1)
    leia(lad2)
    leia(ang)
    ang <- cos(ang*PI/180)
    est <- lad1^2+lad2^2-2*lad1*lad2*ang
    est <- est^(1/2)
    escreval("O tamanho da estrada e ",est)
fimalgoritmo
