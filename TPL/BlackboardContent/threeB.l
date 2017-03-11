%{
//** threeB.l ****

#undef yywrap
#include <stdio.h>
#include <stdlib.h>
#include "threeB.tab.h"  // changed to be part of threeB project

//extern yylval; // found in Bison C code
%}

%%
[0-9]+\.[0-9]*	{ yylval.fval = atof(yytext); return FLOAT; }
[0-9]+	{ yylval.fval = atoi(yytext); return INTEGER; }
[ \t]		; /* Ignore the whitespaces */
\n			return 0; /* logical EOF */
.			return yytext[0]; 
%%

int yywrap() { return 1; }
