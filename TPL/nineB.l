%{
/* nineB.l ****/
#undef yywrap
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "symbolTable.h"
#include "nineB.tab.h"  

// IDENT is an identifier
// NUMBER is an integer

//extern yylval; // found in Bison C code
/*#undef yylval
union {
	char * sval;
} yylval;
*/

%}

%option debug

%%

"PROCEDURE"	{yylval.sval = strdup(yytext); return TPROCEDURE;}
"CONST" 	{yylval.sval = strdup(yytext); return TCONST;}
"VAR"   	{yylval.sval = strdup(yytext); return TVAR;}
"BEGIN" 	{yylval.sval = strdup(yytext); return TBEGIN; }
"END" 		{yylval.sval = strdup(yytext); return TEND;}
"IF" 		{yylval.sval = strdup(yytext); return TIF;}
"THEN" 		{yylval.sval = strdup(yytext); return TTHEN;}
"WHILE" 	{yylval.sval = strdup(yytext); return TWHILE;}
"DO" 		{yylval.sval = strdup(yytext); return TDO;}
"CALL" 		{yylval.sval = strdup(yytext); return TCALL;}
"ODD" 		{yylval.sval = strdup(yytext); return TODD;}
[a-zA-Z]+ 	{yylval.sval = strdup(yytext); return TIDENT;}

[0-9]+		{yylval.sval = strdup(yytext); return TNUMBER;}

">="		{yylval.sval = strdup(yytext); return TGTEQ;}
"<="		{yylval.sval = strdup(yytext); return TLTEQ;}
":="		{yylval.sval = strdup(yytext); return TEQOP;}
">"		{yylval.sval = strdup(yytext); return TGT;}
"<"		{yylval.sval = strdup(yytext); return TLT;}
"?"		{yylval.sval = strdup(yytext); return TQUESTIONMARK;}
"("		{yylval.sval = strdup(yytext); return TLP;}
")"		{yylval.sval = strdup(yytext); return TRP;}
"+"		{yylval.sval = strdup(yytext); return TPLUS;}
"-"		{yylval.sval = strdup(yytext); return TMINUS;}
"\*"		{yylval.sval = strdup(yytext); return TMULT;}
"\/"		{yylval.sval = strdup(yytext); return TDIV;}
";"   		{yylval.sval = strdup(yytext); return TEOL;}
","   		{yylval.sval = strdup(yytext); return TCOMMA;}
"\."  		{yylval.sval = strdup(yytext); return TPERIOD;}
"!"		{yylval.sval = strdup(yytext); return TEXCLAMATION;}
"\="    	{yylval.sval = strdup(yytext); return TEQ;}
"#"		{yylval.sval = strdup(yytext); return TPOUND;}  

[ \t\n]		{; /*Ignore the whitespaces */}


%%

int yywrap() { return 1; }

/*int main() {
   yylex();
   return 0;
}*/
