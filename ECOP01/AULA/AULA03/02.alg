algoritmo "02"
// Autor : Gabriel Alves de Faria
// Data : 22/3/2017

var
  cal : vetor[1..60] de inteiro
  prog : vetor[1..60] de inteiro
  i, a, j : inteiro
  r1 , r2 : caracter
 
inicio
  i <- 1
  a <- 1
  j <- 0
  enquanto (i<=5) e (a<=5)faca
    j <- j+1
    se(i<=5)entao
      escreval("O aluno",j," faz calculo ?")
      leia(r1)
    fimse
    se(a<=5)entao
      escreval("O aluno",j," faz programa��o ?")
      leia(r2)
    fimse
    se (r1="sim")entao
      cal[i]<-j
      i<-i+1
      se (r2="sim")entao
        prog[a]<-j
        a<-a+1
      fimse
    fimse
  fimenquanto
  para j de 1 ate 5 faca
    se(cal[j]=prog[j])entao
      escreval("O aluno",cal[j],"cursa as duas disciplinas")
    fimse
  fimpara

fimalgoritmo
