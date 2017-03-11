    %{
#include <stdio.h>

//-- Lexer prototype required by Bison => getNextToken()
int yylex();
int yyerror(const char *string) { printf("Error!\n"); return 1; }

int isFloat = 0;
%}

%union {
    float fval;
}

%token <fval> FLOAT
%token <fval> INTEGER
%type <fval> expr
%type <fval> term
%type <fval> factor

%%
start:  expr                { if(isFloat) printf("= %f\n", $1);
                              else        printf("= %d\n", (int)$1); }
    ;

expr:   expr '+' term     { $$ = $1 + $3; }
    |   expr '-' term     { $$ = $1 - $3; }
    |   term              { $$ = $1; }
    ;

term:   term '*' factor   { $$ = $1 * $3; }
    |   term '/' factor   { $$ = $1 / $3; }
    |   term '%' factor   { $$ = (int)$1 % (int)$3; }
    |   factor            { $$ = $1;  }
    ;

factor: '(' expr ')'      { $$ = $2; }
    |   FLOAT             { $$ = $1; isFloat = 1;}
    |   INTEGER           { $$ = $1; }
    ;

%%

//-- Function Definitions -----
int main() {
	yyparse();
	return 0;
}
