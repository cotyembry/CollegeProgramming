%{
#include <stdio.h>
unsigned wordCount = 0;
%}

WHITESPACE [ \t\n]
WORD [a-zA-Z]+
%%
int{WHITESPACE}
main
float
include{WHITESPACE}
stdio\.h

{WHITESPACE}+
{WORD}{WHITESPACE}	wordCount++; printf("%s\n", yytext);
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
