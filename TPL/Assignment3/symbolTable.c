/**********************************************************
   File: symbolTable.c
   Date: 2/18/16
   Author: Clay Carley co author (kinda) John Coty Embry
   
   Description: symbol table implementation
   
**********************************************************/

#include "symbolTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//** setValue *********************************************
void setValue( rNode *precord, char cval[]) {
   // store int value
   if (!strcmp(precord->type, "int") ) 
      precord->value.ival = atoi(cval);
      
   // store float value   
   if (!strcmp(precord->type, "float") )
      precord->value.fval = atof(cval);
      
   // store double value
   if (!strcmp(precord->type, "double") )
      precord->value.dval = atof(cval);

} // end setValue

//** getValue *********************************************
char *getValue( rNode *precord ) {
   static char string[40];
   
   // get int value
   if (!strcmp(precord->type, "int") ) 
      sprintf( string, "%d", precord->value.ival);
      
   // get float value   
   if (!strcmp(precord->type, "float") )
      sprintf( string, "%f", precord->value.fval);
      
   // get double value
   if (!strcmp(precord->type, "double") )
      sprintf( string, "%f", precord->value.dval);

   return string;
   
} // end getValue


//** setType *********************************************
void setType( rNode *precord, char cval[]) {

   precord->type = cval;

} // end setType

//** getType *********************************************
char *getType( rNode *precord ) {

   return precord->type; 
      
} // end getType


//** insert/add new record to symbol table ****************
void insert( rNode **precord, char* name, char* type ) {
    rNode *new = malloc(sizeof(rNode));
    new->name = name;
    new->type = type;
    new->next = NULL;
   
    if ( *precord == NULL ) {  // if table is empty - start it up
        *precord = new;
        return;
    }
    else {
        /*
        new->next = (*precord)->next;       // else insert record (add to start of table)
        (*precord)->next = new;
        */
        new->next = (*precord);             // revised on 3/1/16 by jce
        (*precord) = new;
    }
    
} // end insert (into table) function

 
//** lookup (get) symbol table record by name (if it exists, else returns NULL
rNode* lookup( rNode *precord, char* name ) {
   static rNode *iterator = NULL;
   iterator = precord;
   
   while (iterator != NULL) {
      
      if (!strcmp(iterator->name, name)) {
         return iterator;
      }
         
      iterator = iterator->next;
   } // end while
    
    return NULL;
   
} // end lookup

void showSymbols(rNode **precord) {
    static rNode **iterator = NULL;
    iterator = precord;
    
    while (iterator != NULL) {
        //go through the symbol table and print out each symbol
        printf("types in symbol table = >%s<\n", (*iterator)->name);
        
        //I did this if else because I was getting a seg fault without it
        //when trying to access (*iterator)->next when it was NULL
        if((*iterator)->next == NULL) {
            iterator = NULL;
        }
        else {
            (*iterator) = (*iterator)->next;
        }
    } // end while
}

