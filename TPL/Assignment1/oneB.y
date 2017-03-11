%{
#include <stdio.h>

//-- Lexer prototype required by Bison => getNextToken()
int yylex();
int yyerror(const char *string) { printf("Error!\n"); }

%}

%token NAME NUMBER

%%
statement: NAME '=' expr
	| expr						{ printf("= %d\n", $1); }
	;

expr: expr '+' NUMBER	{ $$ = $1 + $3; }
	|	expr '-' NUMBER	{ $$ = $1 - $3; }
	|	NUMBER				{ $$ = $1; }
	;

%%

//-- Function Definitions -----
int main() {
	yyparse();
	return 0;
}
