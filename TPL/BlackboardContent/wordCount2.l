%{
#include <stdio.h>
unsigned wordCount = 0;
%}

WORD [a-zA-Z]+
%%

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
