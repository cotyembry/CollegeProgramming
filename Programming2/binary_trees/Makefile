CC = gcc
CFLAGS = -o a.out
LDFLAGS =

OBJS = main.o binary_tree.o

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean: 
	rm $(OBJS) a.out
print:
	enscript -Plab01 *.c *.h
