algoritmo "02"
// Autor : Gabriel Alves de Faria

var
    v : vetor [1..20] de inteiro
    soma, c, x : inteiro
    med, vr, a : real

inicio
    soma <- 0    
    c <- 0   
    a <- 0   
    escreval("Digite os 20 numeros da matriz") 
    para x de 1 ate 8 faca 
        leia(v[x])     
        soma<-soma+v[x]    
        c<-c+1     
    fimpara    
    med <- soma/c    
    para x de 1 ate 8 faca 
        a <- a+(v[x]-med)^2 
    fimpara    
    vr <- (a/(c-1))  
    escreval("A vari�ncia e igual a ",vr)  
fimalgoritmo
