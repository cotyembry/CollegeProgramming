%{
//** threeB.y **********

#include <stdio.h>

//-- Lexer prototype required by Bison => getNextToken()
int yylex();
int yyerror(const char *string) { printf("Error!\n"); }

int isFloat = 0;

%}

%union {
	float fval;
}

%token <fval> INTEGER
%token <fval> FLOAT
%token NAME 
%type <fval> expr
%type <fval> factor

%%
statement: NAME '=' expr
	| expr						{ if (isFloat) printf("= %f\n", $1);
										else printf("= %d\n", (int)$1); }
	;

expr: expr '+' factor	{ $$ = $1 + $3; }
	|	expr '-' factor	{ $$ = $1 - $3; }
	| factor				{ $$ = $1; }
	;

factor: FLOAT	{ $$ = $1; isFloat = 1; }
	|	INTEGER	{ $$ = $1; }
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