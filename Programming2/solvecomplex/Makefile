CC = gcc
CFLAGS = -o solvecomplex
LDFLAGS = -lm

OBJS = add_complex.o subtract_complex.o negate_complex.o conjugate_complex.o multiply_complex.o divide_complex.o main.o read_complex.o write_complex.o

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean: 
	rm $(OBJS) solvecomplex core
print:
	enscript -Plab01 *.c *.h
