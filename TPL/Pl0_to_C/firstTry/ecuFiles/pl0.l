%{
//** pl0.l ****
#undef yywrap
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pl0.tab.h"  // changed to be part of threeB project
#include "toString.h"

// IDENT is an identifier
// NUMBER is an integer

//extern yylval; // found in Bison C code
/*
BEGIN		{ strcpy(yylval.sval, yytext); return BEGIN; }

*/

%}



%%

"\."						{ yylval.sval = strdup(yytext); printf("found %s\n", yytext); return TPERIOD; }
","						{ yylval.sval = strdup(yytext); return TCOMMA; }
";"						{ yylval.sval = strdup(yytext); return TEOL; }

"?"						{ yylval.sval = strdup(yytext); return TQUESTIONMARK; }
"!"						{ yylval.sval = strdup(yytext); return TEXCLAMATION; }
"("						{ yylval.sval = strdup(yytext); return TLP; }
")"						{ yylval.sval = strdup(yytext); return TRP; }
"="						{ yylval.sval = strdup(yytext); return TEQ; }
"#"						{ yylval.sval = strdup(yytext); return TPOUND; }
"<"						{ yylval.sval = strdup(yytext); return TLT; }
"<="						{ yylval.sval = strdup(yytext); return TLTEQ; }
">"						{ yylval.sval = strdup(yytext); return TGT; }
">="						{ yylval.sval = strdup(yytext); return TGTEQ; }
":="						{ yylval.sval = strdup(yytext); return TEQOP; }
"+"						{ yylval.sval = strdup(yytext); return TPLUS; }
"-"						{ yylval.sval = strdup(yytext); return TMINUS; }
"*"						{ yylval.sval = strdup(yytext); return TMULT; }
"/"						{ yylval.sval = strdup(yytext); return TDIV; }

"BEGIN"					{ yylval.sval = strdup(yytext); return TBEGIN; }
"END"						{ yylval.sval = strdup(yytext); return TEND; }
"IF"						{ yylval.sval = strdup(yytext); return TIF; }
"THEN"					{ yylval.sval = strdup(yytext); return TTHEN; }
"WHILE"					{ yylval.sval = strdup(yytext); return TWHILE; }
"DO"						{ yylval.sval = strdup(yytext); return TDO; }
"CONST"					{ yylval.sval = strdup(yytext); return TCONST; }
"VAR"						{ yylval.sval = strdup(yytext); return TVAR; }
"PROCEDURE"				{ yylval.sval = strdup(yytext); return TPROCEDURE; }
"CALL"					{ yylval.sval = strdup(yytext); return TCALL; }

[a-zA-Z\_]+[a-zA-Z]*	{ yylval.sval = strdup(yytext); return TIDENT; }
[ \t\n]					; /* ignore white space */
[0-9]+					{ yylval.sval = strdup(yytext); return TNUMBER; }
.							return yytext[0];
%%

int yywrap() { 
	return 1;
}
