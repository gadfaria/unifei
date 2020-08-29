algoritmo "04"
// Autor : Gabriel Alves de Faria

var
    m : vetor[1..5,1..5] de inteiro
    n : vetor[1..5,1..5] de inteiro
    x, y, k, pri, t, seg, sub : inteiro

inicio
    pri <- 0
    seg <- 0
    k <- 0
    escreval("Forne�a os valores da matriz")
    para x de 1 ate 5 faca
        escreval("Linha ",x)
        para y de 1 ate 5 faca
            leia(m[x,y])
            se (x=y) entao
                pri <- pri+m[x,y]
            fimse
        fimpara
    fimpara
    para x de 1 ate 5 faca
        y < -5
        y < -y-k
        seg <- seg+m[x,y]
        k <- k+1
    fimpara
    sub <- pri-seg
    escreval("Diferen�a ",sub)

fimalgoritmo

