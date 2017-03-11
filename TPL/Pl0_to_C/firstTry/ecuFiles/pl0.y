%{
//FileName: pl0.y
//Author:	John Coty Embry
//Last Modified: 04/03/2016
//Class:		Theory of Programming Languages
//This is a grammar for the PL0 language that will take in a PL0 program as input and 
//translate the program into C language

//Note: strdup will do the necessary allocation so that we can take the value for that
//particular string and assign it to another variable without worrying about if/when
//the string that's getting copied goes out of scope. This keeps the new copy independent

//just for reference, the content between the { /*...*/ } is called "Actions"...its the "semantic meaning"

#include <stdio.h>
#include <string.h>


//#include "symbolTable.h"
//** create symbol table
//rNode *symbols = NULL;
//** pointer to symbol table record
//rNode *smbRecord;


//-- Lexer prototype required by Bison => getNextToken()
int yylex();
int yyerror(const char *string) { 
	printf("Error! %s\n", string); 
}


//TODO: incorporate "ODD" into the tokens and also IDENT
//TODO: as a bonus, make it where 4(5) is recoginzed as multiplication just like 4*5 is

%}

%union {
   char *sval;
}

%token <sval> TWHILE
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
%token <sval> TEND
%token <sval> TPOUND
%token <sval> TLT 
%token <sval> TLTEQ
%token <sval> TGT
%token <sval> TGTEQ
%token <sval> TEQOP
%token <sval> TPLUS
%token <sval> TMINUS
%token <sval> TMULT
%token <sval> TDIV
%token <sval> TBEGIN
%token <sval> TIF
%token <sval> TTHEN
%token <sval> TDO
%token <sval> TCONST
%token <sval> TVAR
%token <sval> TPROCEDURE
%token <sval> TCALL

%type <sval> program
%type <sval> block
%type <sval> constexpr
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
start:	program { 
				//In program semantics
				printf("in start semantics...so parsing is done\n");
				return 0;
			}
	;

program:	block TPERIOD {
				//printf("in block TPERIOD\n");
				//now we can safely declare "main"
				char mainHelper[18];
				strcpy(mainHelper, "(void) main() {\n}\n");
				printf("%s\n", mainHelper);
				printf("%s\n", $2);
			}
   ;

block:	constexpr varexpr procedure {
				strcat($1, $2);
				strcat($1, $3);
				$$ = strdup($1);
			}
	|		constexpr procedure {
				strcat($1, $2);
				$$ = strdup($1);
			}
	|		varexpr procedure {
				strcat($1, $2);
				$$ = strdup($1);
			}
	|		procedure {
				//printf("in procedure semantics: %s\n", $1);
				$$ = strdup($1);
			}
	;

constexpr:	TCONST constList TEOL {
					//printf("Here\n");
					//output the equivalent C language constant variable declaration
					//printf("%s %s%s", $1, $2, $3);
					strcat($2, $3);
										
					$$ = strdup($2);
					//printf("now here with: %s\n", $$);
				}
   ;
constList: 	constList TCOMMA TIDENT TEQ TNUMBER {
					//first concatenate this rules string values all together
					strcat($1, $2);
					//add a space to format the variable list nicely
					strcat($1, " ");
					strcat($1, $3);
					strcat($1, $4);
					strcat($1, $5);
					//then assing the values that were concatenated to the non-terminal 
					//so that it can continue to be used elsewhere in the grammar
					$$ = strdup($1);
				}
   | 			TIDENT TEQ TNUMBER {
					//first concatenate this rules string values all together
					strcat($1, $2);
					strcat($1, $3);
					//then assigning the values that were concatenated to the non-terminal
					//so that it can continue to be used elsewhere in the grammar
					$$ = strdup($1);
					//printf("here with: %s\n", $$);
				}
   ;
varexpr:	TVAR varList TEOL {
				//TODO: add comment
				//output the equivalent C language variable declaration
				//printf("int %s%s\n", $2, $3);

				char intHelper[4];
				strcpy(intHelper, "int ");
				int lengthHelper = strlen($1) + strlen($2) + strlen($3) + strlen(intHelper);
				char temp[lengthHelper];
				strcpy(temp, intHelper);
				//strcat(temp, $1);
				strcat(temp, $2);
				strcat(temp, $3);
				strcat(temp, "\n");
				$$ = strdup(temp);

			}
	;
varList: TIDENT TCOMMA varList {
				//first concatenate this rules string values all together
				strcat($1, $2);
				//add a space to format the variable list nicely
				strcat($1, " ");
				strcat($1, $3);
				//then assing the values that were concatenated to the non-terminal 
				//so that it can continue to be used elsewhere in the grammar
				$$ = strdup($1);
			}
	| 		TIDENT {
				$$ = strdup($1);
			}
	;
procedure:	procedure TPROCEDURE TIDENT TEOL block TEOL
	| 			TPROCEDURE TIDENT TEOL block TEOL {
					strcpy($1,"(void) ");
					strcat($1, $2);
					strcat($1, "() {\n\t");


					printf("\n\n%s\n", $4);
					strcat($1, $4);
					strcat($1, "\n}\n\n");
					$$ = strdup($1);
					//printf("here >%s<\n", $$);
					//printf("(void) %s() {\n\t%s\n}\n", $2, $4);
				}
	|			statement {
					//TODO: add a comment explaining what is happening here
					//printf("in procedure: $$ = %s\n", $$);
					$$ = strdup($1);
				}
	;
statement: 	TIDENT TEQOP expression {
					//this is equivalent to a variable being assigned to the result of an
					//expression
					
					strcat($1, " ");
					strcat($1, "= ");
					strcat($1, $3);
					$$ = strdup($1);
				}
	| 			TCALL TIDENT {
					//this is equivalent to a function call
					strcat($2, "();");					
					$$ = strdup($2);
				}
	| 			TQUESTIONMARK TIDENT {
					//this should output the value of what is in this TIDENT variable
					//printf("printf(\"%%d\", %s);\n", $2);
					$$ = strdup($2);
				}
	| 			TEXCLAMATION expression {
					//TODO: add a comment explaining this	
					//this outputs the equivalant C language code for the code that is in
					//the PL0 input file
					//printf("printf(\"%%d\", %s);\n", $2); //this works
			
					
					int lengthToAllocate = strlen("printf(\"%d\", ") + strlen($2) + strlen(");\0");
					
					char formattedExpression[lengthToAllocate];

					strcpy(formattedExpression, "printf(\"%d\", ");
					strcat(formattedExpression, $2);
					strcat(formattedExpression, ");\0");	

					$$ = strdup(formattedExpression);				
					//printf("in expression: $$ = %s\n", $$);
					
		 		}			
	| 			TBEGIN statementList TEND {
					strcpy($1, "{\n\t%s\n}");
					strcat($1, $2);
					$$ = strdup($1);
					//printf("{\n\t%s\n}", $2);
				}
	| 			TIF condition TTHEN statement {
					strcpy($1, "if(");
					strcat($1, $2);
					strcat($1, ") {\n\t");
					strcat($1, $4);
					strcat($1, "\n}\n");
					$$ = strdup($1);
				}
	| 			TWHILE condition TDO statement {
					strcpy($1, "\twhile(");
					strcat($1, $2);
					strcat($1, ") {\n\t");
					strcat($1, $4);
					strcat($1, "\n}\n");
				}
	;
statementList:	statement TEOL statementList {
						strcat($1, $2);
						strcat($1, $3);
						$$ = strdup($1);
					}
	|				statement {
						$$ = strdup($1);					
					}
	;
condition:	expression logicOP expression {
					strcat($1, " ");
					strcat($1, $2);
					strcat($1, " ");
					strcat($1, $3);
					$$ = strdup($1);

				}
	;
logicOP:	TEQ
	|		TPOUND {
				//most of these are equivalent in C from what the PL0 language has set up
				//but the "not" operator is different so I'm account for that here
				$$ = strdup("!");
			}
	|		TLT
	|		TLTEQ
	|		TGT
	|		TGTEQ
	;
expression: term					
	| 			expression TPLUS term {
					//this simply takes the string values from this rule and assigns it back
					//to the non-terminal	
					strcat($1, $2);
					strcat($1, $3);
					$$ = strdup($1);
				}
	|			expression TMINUS term {
					//this simply takes the string values from this rule and assigns it back
					//to the non-terminal
					strcat($1, $2);
					strcat($1, $3);
					$$ = strdup($1);
				}	
	;
term: factor
	| 	term TMULT factor { 
			//this simply takes the string values from this rule and assigns it back to the 
			//non-terminal
			strcat($1, $2);
			strcat($1, $3);
			$$ = strdup($1);
		}
	| 	term TDIV factor { 
			//this simply takes the string values from this rule and assigns it back to the
			//non-terminal
			strcat($1, $2);
			strcat($1, $3);
			$$ = strdup($1);
		}	
	;
factor: 	TIDENT
	| 		TNUMBER					
	| 		TLP expression TRP { 
				//this simply takes the string values from this rule and assigns it back to
				//the non-terminal
				strcat($1, $2);
				strcat($1, $3);
				$$ = strdup($1);
				
			}
	;
%%

//-- Function Definitions -----

int main() {
	yyparse();
	return 0;
}
