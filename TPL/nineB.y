%{
//** nineB.y **********

#include <stdio.h>
#include <string.h>
//#include "symbolTable.h"

//** create symbol table
//rNode *symbols = NULL;

//** pointer to symbol table record
//rNode *smbRecord;

//-- Lexer prototype required by Bison => getNextToken()
int yylex();
int yyerror(const char *string) { printf("Error! %s\n", string); return 1; }


%}

%union {
   char *sval;
}

%token <sval> TNUMBER // integer
%token <sval> TCOMMA  // ","
%token <sval> TEOL    // ";"
%token <sval> TPERIOD // "."
%token <sval> TQUESTIONMARK	// "?"
%token <sval> TEXCLAMATION	// "!"
%token <sval> TLP		// "("
%token <sval> TRP		// ")"
%token <sval> TIDENT  // identifier
%token <sval> TEQ   	// "="
%token <sval> TPOUND	// "#"
%token <sval> TLT		// "<"
%token <sval> TLTEQ	// "<="
%token <sval> TGT		//	">"
%token <sval> TGTEQ	// ">="
%token <sval> TEQOP	// ":="
%token <sval> TPLUS	// "+"
%token <sval> TMINUS	// "-"
%token <sval> TMULT	// "*"
%token <sval> TDIV		// "/"
%token <sval> TBEGIN	// "BEGIN"
%token <sval> TEND		// "END"
%token <sval> TIF		// "IF"
%token <sval> TTHEN	// "THEN"
%token <sval> TWHILE	// "WHILE"
%token <sval> TDO		// "DO"
%token <sval> TCONST  // "CONST"
%token <sval> TVAR    // "VAR"
%token <sval> TPROCEDURE	// "PROCEDURE"
%token <sval> TCALL	// "CALL"
%token <sval> TODD		// "ODD"

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
program: block TPERIOD   {return 0;}
   ;
block: constexpr varexpr procedure {;}
   ;
constexpr: /* empty */    {;}
   | TCONST constList TEOL  {;}
   ;
constList: constList TCOMMA TIDENT TEQ TNUMBER	{;} 
   | TIDENT TEQ TNUMBER	{;}
   ;
varexpr: /* empty */       {;}
   | TVAR varList TEOL      {;}
   ;
varList: TIDENT TCOMMA varList  {;}
   | TIDENT	{;}
   ;
procedure: TPROCEDURE TIDENT TEOL block TEOL procedure	{;}
	| TPROCEDURE TIDENT TEOL block TEOL	{;}
	| statement	{;}
	;
statement: TIDENT TEQOP expression	{;}
	| TCALL TIDENT	{;}
	| TQUESTIONMARK TIDENT	{;}
	| TEXCLAMATION expression	{;}
	| TBEGIN statementList TEND	{;}
	| TIF condition TTHEN statement	{;}
	| TWHILE condition TDO statement	{;}
	;
statementList: statement TEOL statementList {;}
	| statement {;}
	;
condition: TODD expression	{;}
	| expression logicOP expression	{;}
	;
logicOP: TEQ	{;}
	| TPOUND	{;} 
	| TLT	{;} 
	| TLTEQ	{;} 
	| TGT	{;} 
	| TGTEQ	{;} 
	;
expression: term	{;}
	| expression TPLUS term	{;}
	| expression TMINUS term	{;}
	;
term: factor	{;}
	| term TMULT factor	{;}
	| term TDIV	factor	{;}
	;
factor: TIDENT	{;}
	| TNUMBER	{;}
	| TLP expression TRP	{;}
	;
%%

//-- Function Definitions -----
int main() {


	yyparse();
	return 0;
}
