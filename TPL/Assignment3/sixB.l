%{
//** sixB.l ****
#undef yywrap
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"
#include "sixB.tab.h"  // changed to be part of threeB project

//extern yylval; // found in Bison C code
%}

%%
[0-9]+\.[0-9]* { strcpy(yylval.sval, yytext); return DOUBLE; }
[0-9]+	{ strcpy(yylval.sval, yytext); return INTEGER; }
[ \t]		; /* Ignore the whitespaces */
\n			return 0; /* logical EOF */
.			return yytext[0]; 
%%

int yywrap() { return 1; }
