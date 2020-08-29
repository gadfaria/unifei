algoritmo "A1xE3"
// Autor : Gabriel Alves de Faria
// Data : 7/3/2017

var
l1, l2, l3 : real
a1, a2, a3 : real
 
inicio
    escreval("Informe os dois lado do triangulo e o angulo formado")
    leia(l1)
    leia(l2)
    leia(a1)
    a1<-cos(a1*PI/180)
 
    l3 <- l1^2+l2^2-2*l1*l2*a1
    l3 <- l3^(1/2)
    a2 <- (l1^2-l2^2-l3^2)/(-2*l2*l3)
    a2 <- arccos(a2)
  
    a3 <- (l2^2-l1^2-l3^2)/(-2*l1*l3)
    a3 <- arccos(a3)
 
 
    escreval("O lado e igual a ",l3)
    escreval("Os angulos formados sao ",a2,",",a3)
 
fimalgoritmo
