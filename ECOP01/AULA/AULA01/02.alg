algoritmo "02"
// Autor : Gabriel Alves de Faria
// Data : 7/3/2017

var
 somb, alt, ang, rad : real
 
inicio
    escreval("Informe o tamanho da sombra e o angulo")
    leia(somb)
    leia(ang)
    rad <- tan(ang*PI/180)
    alt <- somb*rad
    escreval("Altura do predio e igual a ",alt)
 
fimalgoritmo
