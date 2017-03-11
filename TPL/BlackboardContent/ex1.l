%{
#include <stdio.h>
#undef yywrap

%}

%%
stop    printf("Stop command received\n");
start   printf("Start command received\n");
%%
int yywrap() { return 1; }

void main() {
	yylex();
}
