%{
#include <stdio.h>
unsigned wordCount = 0;
%}

WORD [a-zA-Z]+
%%
int[ \t\n]
main
float
include
stdio\.h

[ \t\n]+
{WORD}[ \t\n]	wordCount++; printf("%s\n", yytext);
.

%%
int yywrap() {
	return 1;
}
main() {
	// lex through the input:
	yylex();
	printf("Number of Words: %d\n", wordCount);
}
