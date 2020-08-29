--FUNCOES PARA VERIFICAR A RELACAO DE CONJUNTOS

type ConjuntoInt = [Int]
type RelacaoInt = [(Int,Int)]

-------------------------------------------------------------------------------------------------------------------
--1)
reflexiva :: ConjuntoInt -> RelacaoInt -> Bool
reflexiva [] _ = True
reflexiva (a:b) relacao | not(elem (a,a) relacao) = False
                        | otherwise = reflexiva b relacao

-------------------------------------------------------------------------------------------------------------------
--2)
irreflexiva :: ConjuntoInt -> RelacaoInt -> Bool
irreflexiva [] _ = True
irreflexiva (a:b) relacao | (elem (a,a) relacao) = False
                          | otherwise = irreflexiva b relacao

-------------------------------------------------------------------------------------------------------------------
--3)
simetrica :: ConjuntoInt -> RelacaoInt -> Bool
simetrica _ relacao = simetricaAux relacao relacao
	where
	 simetricaAux :: RelacaoInt -> RelacaoInt -> Bool
	 simetricaAux [] _ = True
         simetricaAux ((a,b):r) relacao | not(elem (b,a) relacao) = False
                                        | otherwise = simetricaAux r relacao

-------------------------------------------------------------------------------------------------------------------
--4)
antisimetrica :: ConjuntoInt -> RelacaoInt -> Bool
antisimetrica _ relacao = antisimetricaAux relacao relacao
	where
	 antisimetricaAux :: RelacaoInt -> RelacaoInt -> Bool
	 antisimetricaAux [] _ = True
	 antisimetricaAux ((a,b):r) relacao | (a==b) = antisimetricaAux r relacao
                                            | (elem (b,a) relacao) = False
                                            | otherwise = antisimetricaAux r relacao

-------------------------------------------------------------------------------------------------------------------
--5)
assimetrica :: ConjuntoInt -> RelacaoInt -> Bool
assimetrica _ relacao = assimetricaAux relacao relacao
	where
	 assimetricaAux :: RelacaoInt -> RelacaoInt -> Bool
	 assimetricaAux [] _ = True
	 assimetricaAux ((a,b):r) relacao | (elem (b,a) relacao) = False
					  | otherwise = assimetricaAux r relacao

-------------------------------------------------------------------------------------------------------------------
--6)
transitiva :: ConjuntoInt -> RelacaoInt -> Bool
transitiva _ relacao = transitivaAux relacao relacao
	where
	 transitivaAux :: RelacaoInt -> RelacaoInt -> Bool
	 transitivaAux [] _ = True
	 transitivaAux ((a,b):r) relacao = (testaPares a (geraPares b relacao) relacao) && (transitivaAux r relacao)

	 geraPares :: Int -> RelacaoInt -> ConjuntoInt
	 geraPares _ [] = []
	 geraPares y ((a,b):r) | (a==y) = b : geraPares y r
			       | otherwise = geraPares y r
         
	 testaPares :: Int -> ConjuntoInt -> RelacaoInt -> Bool
	 testaPares _ [] _ = True
	 testaPares x (a:b) r | not(elem (x,a) r) = False
			      | otherwise = testaPares x b r 
	
-------------------------------------------------------------------------------------------------------------------
--7)
ordemParcial :: ConjuntoInt -> RelacaoInt -> Bool
ordemParcial c r | ((reflexiva c r) && (antisimetrica c r) && (transitiva c r)) = True
                 | otherwise = False

-------------------------------------------------------------------------------------------------------------------
--8)
ordemParcialEstrita :: ConjuntoInt -> RelacaoInt -> Bool
ordemParcialEstrita c r | ((irreflexiva c r) && (antisimetrica c r) && (transitiva c r)) = True
                        | otherwise = False

-------------------------------------------------------------------------------------------------------------------
--9)
ordemTotal :: ConjuntoInt -> RelacaoInt -> Bool
ordemTotal conj relacao | (ordemParcial conj relacao) = testaOrdemTotal conj relacao
			| otherwise = False
	where
	 testaOrdemTotal :: ConjuntoInt -> RelacaoInt -> Bool
	 testaOrdemTotal [] _ = True
	 testaOrdemTotal (a:b) relacao | not(verificaPar a b relacao) = False
				       | otherwise = testaOrdemTotal b relacao

	 verificaPar :: Int -> ConjuntoInt-> RelacaoInt -> Bool
	 verificaPar _ [] _ = True
	 verificaPar a (x:y) relacao | not(elem (a,x) relacao) = False
				     | otherwise = verificaPar a y relacao

-------------------------------------------------------------------------------------------------------------------
--10)
equivalencia :: ConjuntoInt -> RelacaoInt -> Bool
equivalencia c r | ((reflexiva c r) && (simetrica c r) && (transitiva c r)) = True
                 | otherwise = False

-------------------------------------------------------------------------------------------------------------------
--11)
funcional :: ConjuntoInt -> ConjuntoInt -> RelacaoInt -> Bool
funcional [] _ _ = True
funcional (a:b) c2 relacao | not(procura1 a 0 relacao) = False
			   | otherwise = funcional b c2 relacao
	where
	 procura1 :: Int -> Int -> RelacaoInt -> Bool
	 procura1 _ 2 _  = False
	 procura1 _ _ [] = True 
	 procura1 x c ((a,b):r) | (x==a) = procura1 x (c+1) r
				| otherwise = procura1 x c r
 
-------------------------------------------------------------------------------------------------------------------
--12)
injetora :: ConjuntoInt -> ConjuntoInt -> RelacaoInt -> Bool
injetora [] _ _ = True
injetora c1 (a:b) relacao | not(procura2 a 0 relacao) = False
			  | otherwise = funcional c1 b relacao
	where
	 procura2 :: Int -> Int -> RelacaoInt -> Bool
	 procura2 _ 2 _  = False
	 procura2 _ _ [] = True
	 procura2 x c ((a,b):r) | (x==b) = procura2 x (c+1) r
				| otherwise = procura2 x c r 

-------------------------------------------------------------------------------------------------------------------
--13)
total :: ConjuntoInt -> ConjuntoInt -> RelacaoInt -> Bool
total [] _ _ = True
total (a:b) c2 relacao | not(procura3 a relacao) = False
                       | otherwise = total b c2 relacao
	where
	 procura3 :: Int -> RelacaoInt -> Bool
	 procura3 _ [] = False
	 procura3 x ((a,b):r) | (x==a) = True
	 	  	      | otherwise = procura3 x r

-------------------------------------------------------------------------------------------------------------------
--14)
sobrejetora :: ConjuntoInt -> ConjuntoInt -> RelacaoInt -> Bool
sobrejetora _ [] _ = True
sobrejetora c1 (a:b) relacao | not(procura4 a relacao) = False
			     | otherwise = sobrejetora c1 b relacao
	where
	 procura4 :: Int -> RelacaoInt -> Bool
	 procura4 _ [] = False
	 procura4 x ((a,b):r) | (x==b) = True
			      | otherwise = procura4 x r
 
-------------------------------------------------------------------------------------------------------------------
--15)
isorrelacao :: ConjuntoInt -> ConjuntoInt -> RelacaoInt -> Bool
isorrelacao c1 c2 r | ((total c1 c2 r) && (injetora c1 c2 r) && (funcional c1 c2 r) && (sobrejetora c1 c2 r)) = True
	            | otherwise = False

-------------------------------------------------------------------------------------------------------------------
