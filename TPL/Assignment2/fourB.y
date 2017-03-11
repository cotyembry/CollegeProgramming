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

expr: expr '+' term     { $$ = $1 + $3; }
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

/*
 You will need to run the following test cases:
 1024 * 10 * 4
 3 + 3.3
 (8+4) / 2.00
 (24 – 12) % 5
 100500066
*/
