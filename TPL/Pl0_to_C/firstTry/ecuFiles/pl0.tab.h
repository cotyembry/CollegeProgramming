/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TWHILE = 258,
     TNUMBER = 259,
     TCOMMA = 260,
     TEOL = 261,
     TPERIOD = 262,
     TQUESTIONMARK = 263,
     TEXCLAMATION = 264,
     TLP = 265,
     TRP = 266,
     TIDENT = 267,
     TEQ = 268,
     TEND = 269,
     TPOUND = 270,
     TLT = 271,
     TLTEQ = 272,
     TGT = 273,
     TGTEQ = 274,
     TEQOP = 275,
     TPLUS = 276,
     TMINUS = 277,
     TMULT = 278,
     TDIV = 279,
     TBEGIN = 280,
     TIF = 281,
     TTHEN = 282,
     TDO = 283,
     TCONST = 284,
     TVAR = 285,
     TPROCEDURE = 286,
     TCALL = 287
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 38 "pl0.y"

   char *sval;



/* Line 2068 of yacc.c  */
#line 88 "pl0.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


