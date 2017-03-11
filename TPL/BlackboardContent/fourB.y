%{
//** fourB.y **********

#include <stdio.h>

//-- Lexer prototype required by Bison => getNextToken()
int yylex();
int yyerror(const char *string) { printf("Error!\n"); }

%}

%token NUMBER

%%
start: expr				{ printf("= %d\n", $1); }
	;

expr: expr '+' term	{ $$ = $1 + $3; }
	|	expr '-' term	{ $$ = $1 - $3; }
	| term				{ $$ = $1; }
	;

term: term '*' factor	{ $$ = $1 * $3; }
	| term '/' factor	{ $$ = $1 / $3; }
	| term '%' factor	{ $$ = $1 % $3; }
	| factor				{ $$ = $1; }
	;

factor: '(' expr ')'	{ $$ = $2; }
	|	NUMBER				{ $$ = $1; }
	;

%%

//-- Function Definitions -----
int main() {
	yyparse();
	return 0;
}
