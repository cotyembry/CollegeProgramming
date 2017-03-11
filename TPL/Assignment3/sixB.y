%{
//** sixB.y **********

#include <stdio.h>
#include <string.h>
#include "symbolTable.h"

//** create symbol table
rNode *symbols = NULL;

//** pointer to symbol table record
rNode *smbRecord;

//-- Lexer prototype required by Bison => getNextToken()
int yylex();
int yyerror(const char *string) { printf("Error!\n"); return 0; }

//prototypes
void setType(rNode *precord, char cval[]);
void showSymbols(rNode **precord);

%}

%union {
   char sval[40];
}

%token <sval> INTEGER <sval> DOUBLE
%type <sval> expr
%type <sval> start

%%

start:	expr    {   if ((smbRecord = lookup(symbols, "expr")) != NULL ) {
                        if (!strcmp(smbRecord->type, "int")) {
                            printf("Value is: %d\n", smbRecord->value.ival);
                        }
                        else if (!strcmp(smbRecord->type, "double")) {
                                       printf("Value is: %f\n", smbRecord->value.dval);
                        } // end if
                                    
                    } // end if
                }
     ;

expr:   factor 	{
          
            if ((smbRecord = lookup(symbols, "factor")) != NULL ) {
                rNode *esmbRecord;
            
                if ((esmbRecord = lookup(symbols, "expr")) != NULL ) {
                    setType(esmbRecord, smbRecord->type);
                    setValue(esmbRecord, getValue(smbRecord));
                } // end if
            
            } // end if
            
        }

factor: INTEGER	{
            if ((smbRecord = lookup(symbols, "factor")) != NULL ) {
                setType(smbRecord, "int");
                setValue(smbRecord, $1);
            } // end if
            
        }
         
      | DOUBLE {
          
            if ((smbRecord = lookup(symbols, "factor")) != NULL ) {
                setType(smbRecord, "double");
                setValue(smbRecord, $1);
            } // end if
            
        }
      ;

%%

//-- Function Definitions -----
int main() {

insert( &symbols, "INTEGER", "int" );
insert( &symbols, "FLOAT", "float" );
insert( &symbols, "DOUBLE", "double" );
insert( &symbols, "expr", "int" );
insert( &symbols, "factor", "int" );

	yyparse();
    

    showSymbols(& symbols);
    
	return 0;
}



























