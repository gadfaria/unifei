%
%	       GNU - PROLOG
%

% E(Elemento) | L(Lista) | R(Resultado) | S(Soma) | X(Cabeca) | Y(Cauda)

potencia(_,0,1) :-!. 
potencia(X,Y,R) :- Y1 is Y-1,
	           potencia(X,Y1,R1),
                   R is R1*X.

compLista([],0)    :- !.
compLista([_|Y],T) :- compLista(Y,T1),
		      T is (T1+1).

somaLista([],0)    :- !.
somaLista([X|Y],S) :- somaLista(Y,S1),	
		      S is (S1+X).

encontraN([X|_],1,X) :- !.
encontraN([_|Y],C,E) :- C1 is (C-1),
			encontraN(Y,C1,E).
			
inserePrim(L,E,[E|L]).

insereUlt([],E,[E])      :- !.
insereUlt([X|Y],E,[X|L]) :- insereUlt(Y,E,L).

insereN(L,N,1,[N|L])     :- !.
insereN([X|Y],N,C,[X|L]) :- C1 is (C-1),
			    insereN(Y,N,C1,L).		 

insereOrd([],E,[E])       :- !.
insereOrd([X|Y],E,[X|Y1]) :- X<E,!,
			     insereOrd(Y,E,Y1).     
insereOrd(L,E,[E|L])      :- !.

retiraElem([],_,[])       :- !.
retiraElem([X|Y],X,L)     :- !,retiraElem(Y,X,L).
retiraElem([X|Y],E,[X|L]) :- retiraElem(Y,E,L).

substituiElem([],_,_,[])       :- !.
substituiElem([X|Y],X,E,[E|L]) :- !,substituiElem(Y,X,E,L).
substituiElem(L,E,E1,L1)       :- !,substituiElem(L,E,E1,L1).





