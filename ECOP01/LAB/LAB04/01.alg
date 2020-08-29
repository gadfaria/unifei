algoritmo "01"

var
    coord : vetor [1..5, 1..2] de inteiro
    m : vetor [1..5] de real
    i, j, x, y : inteiro
    dist,distm : real


inicio
    distm <- 0
    para i de 1 ate 5 faca
        escreva("digite ", i, " x: ")
        leia(coord[i,1])
        escreva("digite ", i, " y: ")
        leia(coord[i,2])
    fimpara
    para i de 1 ate 5 faca
        para j de 1 ate 5 faca
            dist <- raizq((coord[i,1]-coord[j,1])^2+(coord[i,2]-coord[j,2])^2)
            se(dist>distm)entao
                distm <- dist
            fimse
        fimpara
        m[i] <- distm
    fimpara
    dist <- 9999
    para i de 1 ate 5 faca
        se(dist<m[i])entao
            dist <- m[i]
            x <- coord[i,1]
            y <- coord[i,2]
        fimse
    fimpara
    escreval(x,y)

fimalgoritmo
