%{
//** eightB.y **********

#include <stdio.h>
#include <string.h>
#include "symbolTable.h"

//** create symbol table
rNode *symbols = NULL;

//** pointer to symbol table record
rNode *smbRecord;

//-- Lexer prototype required by Bison => getNextToken()
int yylex();
int yyerror(const char *string) { printf("Error! %s\n", string); }


%}

%union {
   char *sval;
}

%token <sval> NUMBER // integer
%token <sval> COMMA  // ","
%token <sval> EOL    // ";"
%token <sval> PERIOD // "."
%token <sval> QUESTIONMARK	// "?"
%token <sval> EXCLAMATION	// "!"
%token <sval> LP		// "("
%token <sval> RP		// ")"
%token <sval> IDENT  // identifier
%token <sval> EQ   	// "="
%token <sval> POUND	// "#"
%token <sval> LT		// "<"
%token <sval> LTEQ	// "<="
%token <sval> GT		//	">"
%token <sval> GTEQ	// ">="
%token <sval> EQOP	// ":="
%token <sval> PLUS	// "+"
%token <sval> MINUS	// "-"
%token <sval> MULT	// "*"
%token <sval> DIV		// "/"
%token <sval> BEGIN	// "BEGIN"
%token <sval> END		// "END"
%token <sval> IF		// "IF"
%token <sval> THEN	// "THEN"
%token <sval> WHILE	// "WHILE"
%token <sval> DO		// "DO"
%token <sval> CONST  // "CONST"
%token <sval> VAR    // "VAR"
%token <sval> PROCEDURE	// "PROCEDURE"
%token <sval> CALL	// "CALL"
%token <sval> ODD		// "ODD"

%type <sval> program
%type <sval> block
%type <sval> constList
%type <sval> varexpr
%type <sval> varList
%type <sval> procedure
%type <sval> statement
%type <sval> statementList
%type <sval> condition
%type <sval> logicOP
%type <sval> expression
%type <sval> term
%type <sval> factor


%%
program: block PERIOD   {return 0;}
   ;
block: constexpr varexpr procedure {;}
      ;
constexpr: /* empty */    {;}
   | CONST constList EOL  {;}
   ;
constList: constList COMMA IDENT EQ NUMBER 
   | IDENT EQ NUMBER
   ;
varexpr: /* empty */       {;}
    | VAR varList EOL      {;}
    ;
varList: IDENT COMMA varList  {;}
      | IDENT
      ;
procedure: procedure PROCEDURE IDENT EOL block EOL
		| PROCEDURE IDENT EOL block EOL
		| statement
		;
statement: IDENT EQOP expression
		| CALL IDENT
		| QUESTIONMARK IDENT
		| EXCLAMATION expression
		| BEGIN statementList END
		| IF condition THEN statement
		| WHILE condition DO statement
		;
statementList: statement
		| statement EOL statementList
		;
condition: ODD expression
		| expression logicOP expression
		;
logicOP: EQ | POUND | LT | LTEQ | GT | GTEQ 
			;
expression: term
	| expression PLUS term
	| expression MINUS term
	;
term: factor
	| term MULT factor
	| term DIV	factor
	;
factor: IDENT
	| NUMBER
	| LP expression RP
	;
%%

//-- Function Definitions -----
int main() {


	yyparse();
	return 0;
}
