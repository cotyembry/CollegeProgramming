%{
//** eightB.l ****
#undef yywrap
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"
#include "eightB.tab.h"  // changed to be part of threeB project

// IDENT is an identifier
// NUMBER is an integer

//extern yylval; // found in Bison C code
%}

%%
[a-zA-Z\_]+[a-zA-Z]	{strcpy(yylval.sval, yytext); return IDENT;}
[0-9]+	{ strcpy(yylval.sval, yytext); return NUMBER; }
[ \t\n]		; /* Ignore the whitespaces */
\n			return 0; /* logical EOF */
.			return yytext[0]; 
%%

int yywrap() { return 1; }
