%{
#include <stdio.h>

%}

WORD [a-zA-Z]
%%

[ \t\n]+
\_*{WORD}[0-9a-zA-Z\_]+		printf("%s\n", yytext);
.

%%
int yywrap() {
	return 1;
}
main() {
	// lex through the input:
	yylex();

}
