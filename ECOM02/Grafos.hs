type Vertice = (Int, [Int])
type Grafo = [Vertice]

grau :: [Int] -> Int
grau [] = 0
grau (_:cauda) = 1 + grau(cauda)

quickSort :: [Int] -> [Int]
quickSort [] = []
quickSort (cabeca:cauda) = quickSort [y | y<-cauda, y<cabeca] ++[cabeca] ++ quickSort [y | y<-cauda, y>=cabeca]

insereUltimo :: Int -> [Int] -> [Int] 
insereUltimo elem [] = [elem]
insereUltimo elem (cabeca:cauda) = cabeca : insereUltimo elem cauda 

--1)Ordem 
ordem :: Grafo -> Int
ordem [] = 0
ordem (_:cauda) = 1 + ordem(cauda)

--2)Tamanho
tamanho :: Grafo -> Int
tamanho grafo = div (tamanhoAux grafo) 2
	where
	 tamanhoAux :: Grafo -> Int
	 tamanhoAux [] = 0
	 tamanhoAux ((_,a):cauda) = grau(a) + tamanhoAux(cauda) 

--3)Verifica Eureliano
eureliano :: Grafo -> Bool
eureliano ((v,a):cauda) = eurelianoAux ((v,a):cauda) && conexo (length(buscaProf ((v,a):cauda) v)) (ordem ((v,a):cauda))
	where
	eurelianoAux :: Grafo -> Bool	
	eurelianoAux [] = True
	eurelianoAux ((_,a):cauda) | (mod(grau(a)) 2 == 0) = eurelianoAux(cauda)
			           | otherwise = False
	conexo :: Int -> Int -> Bool
	conexo a b | (a==b) = True
		   | otherwise = False
	
	

--4)Encontra o Complemento 
complemento :: Grafo -> Grafo
complemento grafo = complementoAux grafo grafo
	where
	 complementoAux :: Grafo -> Grafo -> Grafo
	 complementoAux _ [] = []
	 complementoAux grafo ((v,a):cauda) = (v, verificaLigacao v a grafo) : complementoAux grafo cauda
	 	where
	  	 verificaLigacao :: Int -> [Int] -> Grafo -> [Int]
		 verificaLigacao _ _ [] = []
	 	 verificaLigacao v1 a ((v,_):cauda) | (v1 == v) = verificaLigacao v1 a cauda
						    | (elem v a) = verificaLigacao v1 a cauda
				  	     	    | otherwise = v : verificaLigacao v1 a cauda    

--5)Verifica Multigrafo
multigrafo :: Grafo -> Bool
multigrafo [] = False
multigrafo ((_,a:b):cauda) | (verificaArestas (quickSort b) a) = True
			     | otherwise = multigrafo cauda
	where
	 verificaArestas :: [Int] -> Int -> Bool
	 verificaArestas [] _ = False
	 verificaArestas (a:b) num | (a == num) = True
	 			   | otherwise = verificaArestas b a

--6)Busca em Profundidade
buscaProf :: Grafo -> Int -> [Int]
buscaProf grafo num = buscaProfI grafo num []

buscaProfI :: Grafo -> Int -> [Int] -> [Int]
buscaProfI grafo num visitados = buscaProfAux grafo (buscaVert grafo num) (insereUltimo num visitados)   

buscaProfAux :: Grafo -> [Int] -> [Int] -> [Int]
buscaProfAux _ [] visitados = visitados
buscaProfAux grafo (a1:a) visitados | (elem a1 visitados) = buscaProfAux grafo a visitados
		     	 	    | (otherwise) = buscaProfAux grafo a (buscaProfI grafo a1 visitados)

buscaVert :: Grafo -> Int -> [Int]
buscaVert ((v,a):cauda) num | (num == v) = a
			    | otherwise = buscaVert cauda num

--7)Busca em largura
buscaLarg :: Grafo -> Int -> [Int]
buscaLarg grafo num = buscaLargAux grafo (buscaVert grafo num) [num] [] 

buscaLargAux :: Grafo -> [Int] -> [Int] -> [Int] -> [Int]
buscaLargAux _ _ [] visitados = visitados
buscaLargAux grafo [] (a1:a) visitados = buscaLargAux grafo (buscaVert grafo a1) a (insereUltimo a1 visitados)   
buscaLargAux grafo (a1:a) fila visitados | (elem a1 fila || elem a1 visitados) = buscaLargAux grafo a fila visitados
					 | otherwise = buscaLargAux grafo a  (insereUltimo a1 fila) visitados

