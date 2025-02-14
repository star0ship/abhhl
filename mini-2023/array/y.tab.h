/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    EQ = 259,                      /* EQ  */
    NE = 260,                      /* NE  */
    LT = 261,                      /* LT  */
    LE = 262,                      /* LE  */
    GT = 263,                      /* GT  */
    GE = 264,                      /* GE  */
    UMINUS = 265,                  /* UMINUS  */
    IF = 266,                      /* IF  */
    THEN = 267,                    /* THEN  */
    ELSE = 268,                    /* ELSE  */
    FI = 269,                      /* FI  */
    WHILE = 270,                   /* WHILE  */
    DO = 271,                      /* DO  */
    DONE = 272,                    /* DONE  */
    CONTINUE = 273,                /* CONTINUE  */
    FUNC = 274,                    /* FUNC  */
    PRINT = 275,                   /* PRINT  */
    RETURN = 276,                  /* RETURN  */
    FOR = 277,                     /* FOR  */
    INTEGER = 278,                 /* INTEGER  */
    IDENTIFIER = 279,              /* IDENTIFIER  */
    TEXT = 280,                    /* TEXT  */
    CHAR = 281,                    /* CHAR  */
    CONST_CHAR = 282,              /* CONST_CHAR  */
    ESCAPE_CHAR = 283              /* ESCAPE_CHAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define EQ 259
#define NE 260
#define LT 261
#define LE 262
#define GT 263
#define GE 264
#define UMINUS 265
#define IF 266
#define THEN 267
#define ELSE 268
#define FI 269
#define WHILE 270
#define DO 271
#define DONE 272
#define CONTINUE 273
#define FUNC 274
#define PRINT 275
#define RETURN 276
#define FOR 277
#define INTEGER 278
#define IDENTIFIER 279
#define TEXT 280
#define CHAR 281
#define CONST_CHAR 282
#define ESCAPE_CHAR 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "mini.y"

	char character;
	char *string;
	SYM *sym;
	TAC *tac;
	EXP	*exp;

#line 131 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
