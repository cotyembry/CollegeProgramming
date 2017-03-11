%{
#include <stdio.h>
unsigned lineCount = 1;
%}

%%

\n	lineCount++;
.
%%
int yywrap() {
	return 1;
}
int main () {
	yylex();
	printf("Number of lines %d\n", lineCount);
}
