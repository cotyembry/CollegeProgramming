%{
// Ada source code lexical scanner

#include <stdio.h>

%}

WORD [a-zA-Z]
DIGIT [0-9]
%%
real|integer|procedure|end|if|else|is|type|then|begin|[Ss][Tt][Rr][Ii][Nn][Gg]
\+|\-|\=|\:\=|\*|\/|\^|\=\>	printf("operator: %s\n", yytext);
with.*\;
use.*\;
^\#.*$
\:|\,							printf("separator %s\n", yytext);
{DIGIT}+						printf("int const: %s\n", yytext);
{DIGIT}+\.{DIGIT}+ 		printf("real const: %s\n", yytext);
\".*\"						printf("string const: %s\n", yytext);
\-\-.*$
[ \t\n]+
{WORD}[0-9a-zA-Z\_]+		printf("%s\n", yytext);
.
%%
int yywrap() {
	return 1;
}
main() {
	// lex through the input:
	yylex();

}
