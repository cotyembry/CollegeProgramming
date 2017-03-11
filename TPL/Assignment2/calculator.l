%{
#undef yywrap
#include <stdio.h>
#include <stdlib.h>
#include "calculator.tab.h"

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


/*

 You will need to run the following test cases:
 1024 * 10 * 4
 3 + 3.3
 (8+4) / 2.00
 (24 – 12) % 5
 100500066

*/