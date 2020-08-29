--1)Encontra o n-esimo termo da lista
nEsimo :: Int->[Int]->Int --Posicao->Lista
nEsimo 1 (cabeca:_) = cabeca
nEsimo pos (_:cauda) = nEsimo (pos-1) cauda


--2)Insere um elemento na primeira posição da lista
inserePrimeiro :: Int->[Int]->[Int] --Elemento->Lista
inserePrimeiro elem (lista) = elem:lista


--3)Insere um elemento na última posição da lista
insereUltimo :: Int->[Int]->[Int] --Elemento->Lista
insereUltimo elem [] = [elem]
insereUltimo elem (cabeca:cauda) = cabeca : insereUltimo elem cauda 


--4)Insere um elemento na n-esima posição da lista
inserePos :: Int->Int->[Int]->[Int] --Elemento->Posicao->Lista
inserePos elem 1 (lista) = elem:lista
inserePos elem pos (cabeca:cauda) = cabeca:inserePos elem (pos-1) cauda


--5)Retira um elemento na lista de caracteres
retiraCaracter :: Char->[Char]->[Char] --Elemento->Lista
retiraCaracter elem [] = []
retiraCaracter elem (cabeca:cauda) | (elem==cabeca) = retiraCaracter elem cauda
			           | otherwise = cabeca : retiraCaracter elem cauda


--6)Substitui todas as ocorrencias de um elemento por outro em uma lista
trocaCaracter :: Char->Char->[Char]->[Char] --ElementoAntigo->ElementoNovo->Lista
trocaCaracter elemAnt elemNovo [] = []
trocaCaracter elemAnt elemNovo (cabeca:cauda) | (elemAnt==cabeca) = elemNovo : trocaCaracter elemAnt elemNovo cauda 
                                 | otherwise = cabeca : trocaCaracter elemAnt elemNovo cauda


--7)Inverte uma lista
inverteLista :: [Int]->[Int] --Lista
inverteLista [] = []
inverteLista (cabeca:cauda) = insereUltimo cabeca (inverteLista cauda)


--8)Constroe uma lista com n primeiros numeros da serie de Fibonacci 
--Funcao para inverter a lista de Fibonacci
serieFibonacci :: Int->[Int] --Numero de elementos desejados
serieFibonacci num = inverteLista (calculoFibonacci num)
--Funcao para encontrar a sequencia
calculoFibonacci :: Int->[Int]
calculoFibonacci 0 = [0]
calculoFibonacci 1 = [1,0]
calculoFibonacci num = ((nEsimo 1 (calculoFibonacci (num-1))) + (nEsimo 1 (calculoFibonacci (num-2)))) : calculoFibonacci (num-1)


--9)Verifica se uma lista de caracteres e palindromo
--Funcao para verificar se a lista e palindromo
palindromo :: [Char]->Bool --Lista
palindromo (lista) | (lista == (inverteListaCaracter lista)) = True
                   | otherwise = False
--Funcao para inverter a lista de caracteres
inverteListaCaracter :: [Char]->[Char] 
inverteListaCaracter [] = []
inverteListaCaracter (cabeca:cauda) = insereUltCaracter cabeca (inverteListaCaracter cauda)
--Funcao para inserir ultimo caracter em uma lista
insereUltCaracter :: Char->[Char]->[Char]
insereUltCaracter elem [] = [elem]
insereUltCaracter elem (cabeca:cauda) = cabeca : insereUltCaracter elem cauda 


--10)Retorna uma substring de uma string a partir de uma determinada posição
substring :: [Char]->Int->Int->[Char]--Lista->Posicao->Quantidade
substring (lista) 1 0 = []
substring (cabeca:cauda) 1 qtn = cabeca : substring cauda 1 (qtn-1)
substring (cabeca:cauda) pos qtn = substring cauda (pos-1) qtn


--11)Insere uma string em uma determinada posicao em outro string
insereString :: [Char]->Int->[Char]->[Char]--Lista->Posicao->Lista
insereString (string1) 1 (string2) = concatenaString (string2) (string1)   
insereString (cabeca:corpo) pos (string2) = cabeca : insereString corpo (pos-1) (string2)
--Funcao para concatenar duas strings--
concatenaString :: [Char]->[Char]->[Char]
concatenaString [] (string2) = (string2)
concatenaString (cabeca:cauda) (string2) = cabeca : concatenaString cauda (string2) 


--12)Verifica se uma substring faz parte de outra string
verificaSubstring :: [Char]->[Char]->Bool --SubString->String
verificaSubstring (lista) [] = False 
verificaSubstring (lista) (cabeca:cauda) | (testaSubstring (lista) (cabeca:cauda) == True) = True
                                         | (testaSubstring (lista) (cabeca:cauda) == False) = verificaSubstring (lista) (cauda)
--Funcao para testar
testaSubstring :: [Char]->[Char]->Bool
testaSubstring [] (lista) = True
testaSubstring (cabeca:cauda) (cabeca1:cauda1) | (cabeca==cabeca1) = testaSubstring (cauda) (cauda1)
                                               | otherwise = False


--13)Calcula a media de uma lista de numeros reais
media :: [Float]->Float --Lista de numeros
media (lista) = calculaMedia (lista) 0 0
--Funcao para calcular a media
calculaMedia :: [Float]->Float->Float->Float
calculaMedia [] qtn soma = (soma/qtn)
calculaMedia (cabeca:cauda) qtn soma = calculaMedia (cauda) (qtn+1) (soma+cabeca)


--14)Calcula a mediana de uma lista de numeros reais
mediana :: [Float]->Float --Lista de numeros
mediana (lista) | (mod (tamLista lista 0) 2 == 0) = medianaPar (ordenaLista lista) (div (tamLista lista 0) 2)
                | otherwise = medianaImpar (ordenaLista lista) (div (tamLista lista 0) 2)
--Funcao para ordenar a lista de Float
ordenaLista :: [Float]->[Float]
ordenaLista [] = []
ordenaLista (cabeca:cauda) = insere cabeca (ordenaLista cauda)

insere :: Float->[Float]->[Float]
insere e [] = [e]
insere e (cabeca:cauda)
              |(e <= cabeca) = e:cabeca:cauda
              |otherwise = cabeca:insere e cauda
--Funcao para verificar o tamanho da lista
tamLista :: [Float]->Int->Int
tamLista [] qtn = qtn
tamLista (cabeca:cauda) qtn = tamLista cauda (qtn+1)
--Funcao para achar a mediana impar
medianaImpar :: [Float]->Int->Float
medianaImpar (cabeca:cauda) 0 = cabeca
medianaImpar (cabeca:cauda) pos = medianaImpar cauda (pos-1) 
--Funcao para achar a mediana par
medianaPar :: [Float]->Int->Float
medianaPar (cabeca:meio:cauda) 1 = (cabeca+meio)/2
medianaPar (cabeca:cauda) pos = medianaPar cauda (pos-1)


--15)Encontra a moda de uma lista de numeros reais
moda :: [Float]->Float
moda (lista) = encontraModa (lista) 0 0
--Encontra a moda da lista
encontraModa :: [Float]->Int->Float->Float
encontraModa [] qtn elem = elem
encontraModa (cabeca:cauda) qtn elem | (testaModa (cabeca:cauda) 0 cabeca > qtn) = encontraModa cauda (testaModa (cabeca:cauda) 0 cabeca) cabeca
                                     | otherwise = encontraModa cauda qtn elem
--Funcao para encontrar numero de vezes que o elemento aparece
testaModa :: [Float]->Int->Float->Int
testaModa [] qtn elem = qtn
testaModa (cabeca:cauda) qtn elem | (cabeca==elem) = testaModa cauda (qtn+1) elem
                                  | otherwise = testaModa cauda qtn elem



