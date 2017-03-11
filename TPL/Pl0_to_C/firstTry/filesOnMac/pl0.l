%{
/*
File Name: 		pl0.l 
Author: 		John Coty Embry
Last Modified: 	03/28/16
Program Comment:This is the lexical scanner that is used to return tokens to my Bison grammar file
*/
#undef yywrap
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pl0.tab.h"

// IDENT is an identifier
// NUMBER is an integer

//extern yylval; // found in Bison C code
%}

%%
","										{ printf("found ','"); }

[a-zA-Z\_]+[a-zA-Z]	{strcpy(yylval.sval, yytext); return IDENT;}
[0-9]+	{ strcpy(yylval.sval, yytext); return NUMBER; }
[ \t\n]		; /* Ignore the whitespaces */
";"			return 0; /* End of Statement */
.			return yytext[0]; 
%%

int yywrap() { return 1; }
