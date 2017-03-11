%{
#include <stdio.h>
#undef yywrap

%}

%%
[ \t]*
stop    printf("Stop command received\n");
start   printf("Start command received\n");
started printf("Started my motor\n");
%%
int yywrap() { return 1; }

void main() {
	yylex();
}
