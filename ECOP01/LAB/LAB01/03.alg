//Gabriel Alves de Faria - 2017
algoritmo "03"

var
    B, C, BC : real
    A, AB, AC : real

inicio
    escreval("Informe os dois angulos e o lado entre eles(BC): ")
    leia(B)
    leia(C)
    leia(BC)
    A <- 180-(B+C)
    A <- sen(A*PI/180)
    B <- sen(B*PI/180)
    C <- sen(C*PI/180)
    AB <- (BC/A)*C
    AC <- (AB/C)*B
    escreval("Tamanho da ponte AB = ",AB," e ponte AC = ",AC)
    se (AB<AC) entao
        escreval("A menor ponte e AB")
    senao
        escreval("A menor ponte e AC")
    fimse
fimalgoritmo
