a.out: getSetTest2.o symbolTable.o
	gcc getSetTest2.o symbolTable.o

getSetTest2.o: getSetTest2.c symbolTable.h
	gcc -c getSetTest2.c

symboleTable.o: symbolTable.h symbolTable.c
	gcc -c symbolTable.c

