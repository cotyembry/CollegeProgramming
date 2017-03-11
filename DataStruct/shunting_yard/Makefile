CC = gcc
CFLAGS = -o shunting_yard
LDFLAGS =

OBJS = main.o shunting_yard.o cstack.o RPN.o fstack.o 

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean: 
	rm $(OBJS) shunting_yard
print:
	enscript -Plab01 *.c *.h
