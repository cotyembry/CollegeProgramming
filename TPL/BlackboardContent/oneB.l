%{
#undef yywrap
#include <stdio.h>
#include <stdlib.h>
#include "oneB.tab.h"

extern yylval; // found in Bison C code
%}

%%
[0-9]+	{ yylval = atoi(yytext); return NUMBER; }
[ \t]		; /* Ignore the whitespaces */
\n			return 0; /* logical EOF */
.			return yytext[0]; 
%%

int yywrap() { return 1; }
