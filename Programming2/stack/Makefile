CC = gcc
CFLAGS = -o a.out
LDFLAGS = -lm

OBJS = main.o stack.o

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean: 
	rm $(OBJS) a.out
print:
	enscript -Plab01 *.c *.h
