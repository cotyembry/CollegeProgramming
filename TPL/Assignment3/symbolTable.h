/**********************************************************
   File: symbolTable.h
   Date: 2/18/16
   Author: Clay Carley
   
   Description: symbol table prototypes 
										
					e.g. to declare a symbol table all one need
					do is declare one like: rNode *table;
   
**********************************************************/

#ifndef SYMBOLTABLE
#define SYMBOLTABLE

// Symbol table record format
struct record {
   char *name,
         *type;
         
   union {
      int ival;
      float fval;
      double dval;
   } value;
   
   void *next; // pointer to next record
   
}; // end record


// Shortcut name for symbol table record format
typedef struct record rNode;

//** Function prototypes **********************************

//** setValue *********************************************
void setValue( rNode *precord, char cval[]);

//** getValue *********************************************
char *getValue( rNode *precord );

//** insert/add new record to symbol table ****************
void insert( rNode **precord, char* name, char* type );

//** lookup (get) symbol table record by name (if it exists, else returns NULL
rNode* lookup( rNode *precord, char* name );

//** setType *********************************************
void setValue( rNode *precord, char cval[]);

//** getType *********************************************
char *getValue( rNode *precord );

#endif

