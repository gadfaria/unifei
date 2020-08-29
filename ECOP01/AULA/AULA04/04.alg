algoritmo "04"
// Autor : Gabriel Alves de Faria
// Data : 28/3/2017

var
    n1, n2, n3 : inteiro
    opcao : caracter
    med : real
 
funcao MediaA(n1,n2,n3:inteiro):real
    var
        media : real
    inicio
        media <- 0
        media <- (n1+n2+n3)/3
        retorne(media)
fimfuncao

funcao MediaP(n1,n2,n3:inteiro):real
    var
        media : real
    inicio
        media <- 0
        media <- ((n1*5)+(n2*3)+(n3*2))/10
        retorne(media)
fimfuncao

inicio
    med <- 0
    escreval("Digite as 3 notas de um aluno")
    leia(n1,n2,n3)
    escreval("Digite A para media aritmetica ou P para media ponderada")
    leia(opcao)
    se (opcao="A")entao
        med <- MediaA(n1,n2,n3)
        escreval("Media aritmetica do aluno igual a ",med)
    senao
        se (opcao="P") entao
            med <- MediaP(n1,n2,n3)
            escreval("Media ponderada do aluno igual a ",med)
        fimse
    fimse
 
fimalgoritmo
