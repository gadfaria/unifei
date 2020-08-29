Domains
	listaInt=integer*
	no=no(integer, listaInt)
	grafo=no*

Predicates
	grau(listaInt,integer).
	ordem(grafo,integer).
	tamanho(grafo,integer).
	tamanhoAux(grafo,integer).
	complemento(grafo,grafo).
	complementoAux(grafo,grafo,grafo).
	verificaComp(grafo,listaInt,listaInt,integer,listaInt).
	multigrafo(grafo).	
	multiAux(listaInt,integer).
	mod2(integer).
	eureliano(grafo).
	eurelianoAux(grafo).
	conexo(listaInt,integer,integer).
	buscaProf(grafo,integer,listaInt).
	buscaPAux(grafo,listaInt,listaInt,listaInt,listaInt).
	vizinhos(grafo,integer,listaInt).
	insereAdj(listaInt,listaInt,listaInt,listaInt,listaInt).
	pertence(integer,listaInt).
	insereUlt(listaInt,integer,listaInt).	
	componentesConex(grafo,integer).
	remove(grafo,listaInt,listaInt,grafo).
		
Clauses
	insereUlt([],E,[E]):- !.
	insereUlt([X|Y],E,[X|L]):- insereUlt(Y,E,L).
	
	mod2(0).
	mod2(X):- X>0, X1=X-2,!, mod2(X1).

	grau([],0).
	grau([_|Cauda],N):-
		grau(Cauda,N1),N=N1+1.



	ordem([],0).
	ordem([no(_,_)|Cauda],N):-
		ordem(Cauda,N1), N=N1+1.
		

		
	tamanho(G,N):- tamanhoAux(G,N1), N=N1/2.
	tamanhoAux([],0).
	tamanhoAux([no(_,A)|Cauda],N):-
		grau(A,N1), tamanhoAux(Cauda,N2),
		N=(N1+N2).


		
	complemento(G,R):-
		complementoAux(G,G,R).
			
	complementoAux(_,[],[]):-!.
	complementoAux(G,[no(V,A)|Cauda],R):-
		verificaComp(G,A,A,V,R1),
		complementoAux(G,Cauda,R2), R=[no(V,R1)|R2].
		
	verificaComp([],_,_,_,[]):-!.
	verificaComp([no(V1,_)|Cauda],A,[],V,[V1|R]):-!,
		verificaComp(Cauda,A,A,V,R).
	verificaComp([no(V,_)|Cauda],A,A1,V,R):-!,
		verificaComp(Cauda,A,A1,V,R).
	verificaComp([no(A1,_)|Cauda],A,[A1|_],V,R):-!,
		verificaComp(Cauda,A,A,V,R).
	verificaComp(G,A,[_|B],V,R):-!,
		verificaComp(G,A,B,V,R).
		
		
		
	multigrafo([no(_,[A|B])|Cauda]):-
		not(multiAux(B,A)), !,
		multigrafo(Cauda).
	multigrafo([no(_,[A|B])|_]):-
		multiAux(B,A), !.
		
	multiAux([A|_],A).
	multiAux([A|B],_):- !,
		multiAux(B,A).
	
	
	eureliano([no(A,B)|Cauda]):-
		eurelianoAux([no(A,B)|Cauda]), !,
		buscaProf([no(A,B)|Cauda],A,V), !,
		ordem([no(A,B)|Cauda],O), !,
		conexo(V,O,0).
	
	conexo([],O,O):-!.
	conexo([_|B],O,C):- C1=C+1,
		conexo(B,O,C1).
	
	eurelianoAux([]).
	eurelianoAux([no(_,A)|Cauda]):-
		grau(A,N), mod2(N),!,
		eurelianoAux(Cauda).



	buscaProf(G,V,X) :-
		buscaPAux(G,[V],[],[],X).

	buscaPAux(_,[],_,V,V).
	buscaPAux(G,[V|Pilha],S,X,R):-
		vizinhos(G,V,Adj),
		insereAdj(Pilha,Adj,NovaPilha,[V|S],SModif),
	        insereUlt(X,V,X1) ,buscaPAux(G,NovaPilha,SModif,X1,R).

	vizinhos([no(X,Adj)|_],X,Adj):-!.
	vizinhos([_|Cauda],X,Adj):-Vizinhos(Cauda,X,Adj).

	insereAdj(X,[],X,S,S):-!.
	insereAdj(Pilha,[X|Y],NovaPilha,S,SModif):-
		not(pertence(X,S)),!,
		insereAdj([X|Pilha],Y,NovaPilha,[X|S],SModif).
	insereAdj(Pilha,[_|Y],NovaPilha,S,SModif):-
		insereAdj(Pilha,Y,NovaPilha,S,SModif).

	pertence(X,[X|_]).
	pertence(X,[_|Y]):-pertence(X,Y).
	
	
	componentesConex([],0).
	componentesConex([no(A,B)|Cauda],C):-
		buscaProf([no(A,B)|Cauda],A,V),!,
		remove([no(A,B)|Cauda],V,V,G),!,
		componentesConex(G,C1),!,C=C1+1.
	
	remove([],_,_,[]):-!.
	remove([Cabeca|Cauda],[],V,[Cabeca|Gn]):-!,
		remove(Cauda,V,V,Gn).
	remove([no(A,_)|Cauda],[A|_],V,Gn):-!,
		remove(Cauda,V,V,Gn).
	remove(G,[_|B],V,Gn):-!, remove(G,B,V,Gn).
	