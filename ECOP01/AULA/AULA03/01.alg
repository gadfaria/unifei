algoritmo "01"
// Autor : Gabriel Alves de Faria
// Data : 22/3/2017

var
    v1 : vetor[1..100] de inteiro
    v2 : vetor[1..100] de inteiro
    v3 : vetor[1..100] de real
    med : real
    i : inteiro
 
inicio
    para i de 1 ate 100 faca
        med <- 0
        escreval("Digite o valor de V1")
        leia(v1[i])
        escreval("Digite o valor de V2")
        leia(v2[i])
        med <- (v1[i]+v2[i])
        v3[i] <- med
        escreval("(",v1[i],"+",v2[i],")/2 =",med)
    fimpara

fimalgoritmo
