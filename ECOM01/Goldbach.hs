--Verifica se o numero x é primo--
testaPrimo :: Int->Int->Int
testaPrimo x y |(y==0) = 0
	       |(y==1) = 1 
	       |(mod x y == 0) = 0
               |otherwise = testaPrimo x (y-1)

--Lista de numeros primos menores que n--
listaPrimo :: Int->[Int]
listaPrimo 2 = [2]
listaPrimo n |(testaPrimo n (n-1) == 1) = n: listaPrimo (n-1)
             |otherwise = listaPrimo (n-1)

--Procura os dois numeros primos--
testeGoldbach :: Int->[Int]->[Int]
testeGoldbach z [] = testeGoldbach z (listaPrimo z)
testeGoldbach z (cabeca:cauda) | (testaPrimo (z-cabeca) (z-cabeca-1) == 1) = [cabeca,(z-cabeca)]
                               | otherwise = testeGoldbach z cauda

--Funcao para receber o numero a ser testado--
goldbach :: Int->[Int]
goldbach x = testeGoldbach x []
