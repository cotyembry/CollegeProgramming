CC = gcc
CFLAGS = -o solvequad
LDFLAGS = -lm

OBJS = mainmath.o solvelinear.o solvequad.o solvereal.o solvecomplex.o

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean: 
	rm $(OBJS) solvequad core
print:
	enscript -Plab01 *.c *.h
