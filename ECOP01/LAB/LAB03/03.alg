algoritmo "03"
// Autor : Gabriel Alves de Faria

var
    m : vetor[1..5,1..5] de inteiro
    n : vetor[1..5,1..5] de inteiro
    x, y, pri, t, seg, sub : inteiro
 
inicio
    pri <- 0
    seg <- 0
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
        para y de 1 ate 5 faca
            t <- m[x,y]
            m[x,y]<-m[x,5-y+1]
            n[x,5-y+1]<-t
        fimpara
    fimpara
    para x de 1 ate 5 faca
        para y de 1 ate 5 faca
            se(x=y) entao
                seg <- seg+n[x,y]
            fimse
        fimpara
    fimpara
    sub <- pri-seg
    escreval("Diferen�a ",sub)

fimalgoritmo

