/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "mini.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tac.h"
#include "obj.h"

int yylex();
void yyerror(char* msg);


#line 84 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 201 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_EQ = 4,                         /* EQ  */
  YYSYMBOL_NE = 5,                         /* NE  */
  YYSYMBOL_LT = 6,                         /* LT  */
  YYSYMBOL_LE = 7,                         /* LE  */
  YYSYMBOL_GT = 8,                         /* GT  */
  YYSYMBOL_GE = 9,                         /* GE  */
  YYSYMBOL_UMINUS = 10,                    /* UMINUS  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_THEN = 12,                      /* THEN  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_FI = 14,                        /* FI  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_DONE = 17,                      /* DONE  */
  YYSYMBOL_CONTINUE = 18,                  /* CONTINUE  */
  YYSYMBOL_FUNC = 19,                      /* FUNC  */
  YYSYMBOL_PRINT = 20,                     /* PRINT  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_INTEGER = 23,                   /* INTEGER  */
  YYSYMBOL_IDENTIFIER = 24,                /* IDENTIFIER  */
  YYSYMBOL_TEXT = 25,                      /* TEXT  */
  YYSYMBOL_CHAR = 26,                      /* CHAR  */
  YYSYMBOL_CONST_CHAR = 27,                /* CONST_CHAR  */
  YYSYMBOL_ESCAPE_CHAR = 28,               /* ESCAPE_CHAR  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* '['  */
  YYSYMBOL_36_ = 36,                       /* ']'  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* '='  */
  YYSYMBOL_42_ = 42,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_function_declaration_list = 45, /* function_declaration_list  */
  YYSYMBOL_function_declaration = 46,      /* function_declaration  */
  YYSYMBOL_declaration = 47,               /* declaration  */
  YYSYMBOL_variable_list = 48,             /* variable_list  */
  YYSYMBOL_variable = 49,                  /* variable  */
  YYSYMBOL_char_variable_list = 50,        /* char_variable_list  */
  YYSYMBOL_char_variable = 51,             /* char_variable  */
  YYSYMBOL_function = 52,                  /* function  */
  YYSYMBOL_function_head = 53,             /* function_head  */
  YYSYMBOL_parameter_list = 54,            /* parameter_list  */
  YYSYMBOL_parameter = 55,                 /* parameter  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_block = 57,                     /* block  */
  YYSYMBOL_declaration_list = 58,          /* declaration_list  */
  YYSYMBOL_statement_list = 59,            /* statement_list  */
  YYSYMBOL_assignment_statement = 60,      /* assignment_statement  */
  YYSYMBOL_expression = 61,                /* expression  */
  YYSYMBOL_argument_list = 62,             /* argument_list  */
  YYSYMBOL_expression_list = 63,           /* expression_list  */
  YYSYMBOL_print_statement = 64,           /* print_statement  */
  YYSYMBOL_print_list = 65,                /* print_list  */
  YYSYMBOL_print_item = 66,                /* print_item  */
  YYSYMBOL_return_statement = 67,          /* return_statement  */
  YYSYMBOL_null_statement = 68,            /* null_statement  */
  YYSYMBOL_if_statement = 69,              /* if_statement  */
  YYSYMBOL_while_statement = 70,           /* while_statement  */
  YYSYMBOL_for_statement = 71,             /* for_statement  */
  YYSYMBOL_call_statement = 72,            /* call_statement  */
  YYSYMBOL_call_expression = 73,           /* call_expression  */
  YYSYMBOL_array_expression = 74           /* array_expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   254

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,     2,
      37,    38,    31,    29,    34,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    43,    43,    50,    51,    57,    58,    61,    65,    71,
      75,    81,    85,    89,    95,    99,   105,   109,   113,   119,
     125,   132,   140,   144,   149,   154,   158,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   181,   188,   191,
     197,   198,   204,   208,   212,   218,   222,   226,   230,   234,
     238,   242,   246,   250,   254,   258,   262,   266,   270,   274,
     278,   282,   286,   290,   295,   299,   306,   309,   312,   313,
     320,   326,   327,   333,   338,   344,   352,   358,   362,   368,
     374,   379,   385,   391
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "EQ", "NE",
  "LT", "LE", "GT", "GE", "UMINUS", "IF", "THEN", "ELSE", "FI", "WHILE",
  "DO", "DONE", "CONTINUE", "FUNC", "PRINT", "RETURN", "FOR", "INTEGER",
  "IDENTIFIER", "TEXT", "CHAR", "CONST_CHAR", "ESCAPE_CHAR", "'+'", "'-'",
  "'*'", "'/'", "';'", "','", "'['", "']'", "'('", "')'", "'{'", "'}'",
  "'='", "'&'", "$accept", "program", "function_declaration_list",
  "function_declaration", "declaration", "variable_list", "variable",
  "char_variable_list", "char_variable", "function", "function_head",
  "parameter_list", "parameter", "statement", "block", "declaration_list",
  "statement_list", "assignment_statement", "expression", "argument_list",
  "expression_list", "print_statement", "print_list", "print_item",
  "return_statement", "null_statement", "if_statement", "while_statement",
  "for_statement", "call_statement", "call_expression", "array_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    43,
      45,    42,    47,    59,    44,    91,    93,    40,    41,   123,
     125,    61,    38
};
#endif

#define YYPACT_NINF (-82)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-67)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     136,   -82,   -15,   -82,     8,    11,    12,   -82,   -82,   -82,
       3,    20,    19,    71,   -82,    34,    28,    85,   -82,   -82,
     -82,    17,    51,   -82,   -82,   -15,    56,   -82,   -82,     8,
     -82,    65,   -24,   -82,    62,   -82,    72,   -82,   -82,    17,
      82,   -82,   -82,   -82,   -82,   -82,   137,   -82,    90,    97,
     -82,    99,    86,   104,    31,   106,   -82,   -82,   -82,   111,
     116,   120,   121,   123,   -82,   -82,   -82,   131,    86,    86,
      53,   -82,   -82,    66,   -82,   -82,    86,    86,    86,   141,
     222,   -82,   -82,    18,    86,    69,    86,   125,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,    -1,    15,   -82,   222,    33,
     -82,    86,    69,   -82,   -82,   165,   -82,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    47,   134,   175,
     222,   109,   143,   222,    86,    82,    82,    53,   -82,   183,
     140,   -82,   114,   114,   114,   114,   114,   114,    93,    93,
     -82,   -82,    86,   144,   -82,    86,   222,   162,   -82,   -82,
     -82,   -82,   216,    86,   222,    82,    18,   222,   -82,   148,
      82,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    20,     0,    21,     0,     0,     0,     3,     6,     5,
       0,    11,     0,     0,     9,    16,     0,     0,    14,     1,
       4,    24,     0,    12,     7,     0,     0,    17,     8,     0,
      25,     0,     0,    22,     0,    10,     0,    15,    26,     0,
       0,    13,    18,    23,    38,    19,     0,    36,     0,     0,
      76,     0,     0,     0,     0,     0,    39,    40,    35,     0,
       0,     0,     0,     0,    32,    33,    34,     0,     0,     0,
       0,    63,    59,    60,    64,    65,     0,     0,     0,     0,
      75,    61,    62,     0,     0,     0,     0,     0,    37,    41,
      27,    30,    29,    31,    28,     0,     0,    74,    73,     0,
      71,     0,     0,    49,    57,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      68,     0,    67,    42,     0,     0,     0,     0,    70,     0,
       0,    58,    50,    51,    52,    53,    54,    55,    45,    46,
      47,    48,     0,     0,    81,     0,    43,    77,    79,    72,
      83,    82,     0,     0,    69,     0,     0,    44,    78,     0,
       0,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   -82,   187,   152,   -82,   174,   -82,   171,   -82,
     -82,   -82,   163,   142,   -40,   -82,   -82,   -81,   -51,   107,
     -82,   -82,   -82,    81,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    13,    14,    17,    18,     9,
      10,    32,    33,    57,    58,    46,    59,    60,    98,   121,
     122,    61,    99,   100,    62,    63,    64,    65,    66,    67,
      81,    82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    80,   118,   107,   108,   109,   110,   111,   112,    11,
      39,    19,    -2,     1,    40,     2,    12,    95,    96,   107,
     108,   109,   110,   111,   112,   103,   104,   105,   113,   114,
     115,   116,    15,   119,   120,   123,     3,   125,     4,    16,
      21,    30,   117,    23,   113,   114,   115,   116,    31,    55,
     129,   120,    27,   126,    71,    22,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    84,   127,    85,    26,
      71,   128,    86,   146,    34,   159,    72,    73,    97,    36,
      74,    75,    84,    76,    77,   147,   148,    71,    86,    38,
      78,   152,    72,    73,   154,    79,    74,    75,    41,    76,
      77,   101,   157,   102,    24,    25,    78,   -66,    42,    72,
      73,    79,    47,    74,    75,   158,    76,    77,    28,    29,
     161,    44,    48,    78,   115,   116,    49,    68,    79,    50,
      87,    51,    52,    53,    69,    54,    70,     1,    47,     2,
       2,    83,    55,   113,   114,   115,   116,   144,    48,    90,
      44,    88,    49,    91,    92,    50,    93,    51,    52,    53,
       3,    54,     4,     4,    94,   106,   124,   142,    55,   107,
     108,   109,   110,   111,   112,   155,    44,   145,   151,   107,
     108,   109,   110,   111,   112,   153,   160,   107,   108,   109,
     110,   111,   112,    20,   113,   114,   115,   116,    56,    35,
      37,    89,    43,   131,   113,   114,   115,   116,   149,   130,
       0,   143,   113,   114,   115,   116,     0,     0,     0,   150,
     107,   108,   109,   110,   111,   112,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,   114,   115,   116,   156,
       0,   113,   114,   115,   116
};

static const yytype_int16 yycheck[] =
{
      40,    52,    83,     4,     5,     6,     7,     8,     9,    24,
      34,     0,     0,     1,    38,     3,    31,    68,    69,     4,
       5,     6,     7,     8,     9,    76,    77,    78,    29,    30,
      31,    32,    24,    84,    85,    86,    24,    38,    26,    31,
      37,    24,    24,    24,    29,    30,    31,    32,    31,    31,
     101,   102,    24,    38,     1,    35,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,    35,    34,    37,    35,
       1,    38,    41,   124,    23,   156,    23,    24,    25,    23,
      27,    28,    35,    30,    31,   125,   126,     1,    41,    24,
      37,   142,    23,    24,   145,    42,    27,    28,    36,    30,
      31,    35,   153,    37,    33,    34,    37,    38,    36,    23,
      24,    42,     1,    27,    28,   155,    30,    31,    33,    34,
     160,    39,    11,    37,    31,    32,    15,    37,    42,    18,
      24,    20,    21,    22,    37,    24,    37,     1,     1,     3,
       3,    37,    31,    29,    30,    31,    32,    38,    11,    33,
      39,    40,    15,    33,    33,    18,    33,    20,    21,    22,
      24,    24,    26,    26,    33,    24,    41,    33,    31,     4,
       5,     6,     7,     8,     9,    13,    39,    34,    38,     4,
       5,     6,     7,     8,     9,    41,    38,     4,     5,     6,
       7,     8,     9,     6,    29,    30,    31,    32,    46,    25,
      29,    59,    39,    38,    29,    30,    31,    32,   127,   102,
      -1,    36,    29,    30,    31,    32,    -1,    -1,    -1,    36,
       4,     5,     6,     7,     8,     9,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      -1,    29,    30,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    24,    26,    44,    45,    46,    47,    52,
      53,    24,    31,    48,    49,    24,    31,    50,    51,     0,
      46,    37,    35,    24,    33,    34,    35,    24,    33,    34,
      24,    31,    54,    55,    23,    49,    23,    51,    24,    34,
      38,    36,    36,    55,    39,    57,    58,     1,    11,    15,
      18,    20,    21,    22,    24,    31,    47,    56,    57,    59,
      60,    64,    67,    68,    69,    70,    71,    72,    37,    37,
      37,     1,    23,    24,    27,    28,    30,    31,    37,    42,
      61,    73,    74,    37,    35,    37,    41,    24,    40,    56,
      33,    33,    33,    33,    33,    61,    61,    25,    61,    65,
      66,    35,    37,    61,    61,    61,    24,     4,     5,     6,
       7,     8,     9,    29,    30,    31,    32,    24,    60,    61,
      61,    62,    63,    61,    41,    38,    38,    34,    38,    61,
      62,    38,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    33,    36,    38,    34,    61,    57,    57,    66,
      36,    38,    61,    41,    61,    13,    33,    61,    57,    60,
      38,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    49,    49,    49,    50,    50,    51,    51,    51,    52,
      52,    53,    54,    54,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    58,    58,
      59,    59,    60,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    63,    63,
      64,    65,    65,    66,    66,    67,    68,    69,    69,    70,
      71,    72,    73,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     3,     1,
       3,     1,     2,     4,     1,     3,     1,     2,     4,     5,
       1,     1,     1,     3,     0,     1,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     4,     0,     2,
       1,     2,     3,     4,     6,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     3,
       4,     1,     3,     1,     1,     2,     1,     5,     7,     5,
       9,     4,     4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: function_declaration_list  */
#line 44 "mini.y"
{
	tac_last=(yyvsp[0].tac);
	tac_complete();
}
#line 1394 "y.tab.c"
    break;

  case 4: /* function_declaration_list: function_declaration_list function_declaration  */
#line 52 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1402 "y.tab.c"
    break;

  case 7: /* declaration: INT variable_list ';'  */
#line 62 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1410 "y.tab.c"
    break;

  case 8: /* declaration: CHAR char_variable_list ';'  */
#line 66 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1418 "y.tab.c"
    break;

  case 9: /* variable_list: variable  */
#line 72 "mini.y"
{
	(yyval.tac)=(yyvsp[0].tac);
}
#line 1426 "y.tab.c"
    break;

  case 10: /* variable_list: variable_list ',' variable  */
#line 76 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 1434 "y.tab.c"
    break;

  case 11: /* variable: IDENTIFIER  */
#line 82 "mini.y"
{
	(yyval.tac)=declare_var((yyvsp[0].string));
}
#line 1442 "y.tab.c"
    break;

  case 12: /* variable: '*' IDENTIFIER  */
#line 86 "mini.y"
{
	(yyval.tac)=declare_pointer((yyvsp[0].string));
}
#line 1450 "y.tab.c"
    break;

  case 13: /* variable: IDENTIFIER '[' INTEGER ']'  */
#line 90 "mini.y"
{
	(yyval.tac)=declare_array((yyvsp[-3].string),atoi((yyvsp[-1].string)),SYM_VAR);
}
#line 1458 "y.tab.c"
    break;

  case 14: /* char_variable_list: char_variable  */
#line 96 "mini.y"
{
	(yyval.tac)=(yyvsp[0].tac);
}
#line 1466 "y.tab.c"
    break;

  case 15: /* char_variable_list: char_variable_list ',' char_variable  */
#line 100 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 1474 "y.tab.c"
    break;

  case 16: /* char_variable: IDENTIFIER  */
#line 106 "mini.y"
{
	(yyval.tac)=declare_char((yyvsp[0].string));
}
#line 1482 "y.tab.c"
    break;

  case 17: /* char_variable: '*' IDENTIFIER  */
#line 110 "mini.y"
{
	(yyval.tac)=declare_pointer((yyvsp[0].string));
}
#line 1490 "y.tab.c"
    break;

  case 18: /* char_variable: IDENTIFIER '[' INTEGER ']'  */
#line 114 "mini.y"
{
	(yyval.tac)=declare_array((yyvsp[-3].string),atoi((yyvsp[-1].string)),SYM_CONST_CHAR);
}
#line 1498 "y.tab.c"
    break;

  case 19: /* function: function_head '(' parameter_list ')' block  */
#line 120 "mini.y"
{
	(yyval.tac)=do_func((yyvsp[-4].sym), (yyvsp[-2].tac), (yyvsp[0].tac));
	scope_local=0; /* Leave local scope. */
	sym_tab_local=NULL; /* Clear local symbol table. */
}
#line 1508 "y.tab.c"
    break;

  case 20: /* function: error  */
#line 126 "mini.y"
{
	error("Bad function syntax");
	(yyval.tac)=NULL;
}
#line 1517 "y.tab.c"
    break;

  case 21: /* function_head: IDENTIFIER  */
#line 133 "mini.y"
{
	(yyval.sym)=declare_func((yyvsp[0].string));
	scope_local=1; /* Enter local scope. */
	sym_tab_local=NULL; /* Init local symbol table. */
}
#line 1527 "y.tab.c"
    break;

  case 22: /* parameter_list: parameter  */
#line 141 "mini.y"
{
	(yyval.tac)=(yyvsp[0].tac);
}
#line 1535 "y.tab.c"
    break;

  case 23: /* parameter_list: parameter_list ',' parameter  */
#line 145 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 1543 "y.tab.c"
    break;

  case 24: /* parameter_list: %empty  */
#line 149 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1551 "y.tab.c"
    break;

  case 25: /* parameter: IDENTIFIER  */
#line 155 "mini.y"
{	
	(yyval.tac)=declare_para((yyvsp[0].string));
}
#line 1559 "y.tab.c"
    break;

  case 26: /* parameter: '*' IDENTIFIER  */
#line 159 "mini.y"
{
	(yyval.tac)=declare_para_ptr((yyvsp[0].string));
}
#line 1567 "y.tab.c"
    break;

  case 36: /* statement: error  */
#line 175 "mini.y"
{
	error("Bad statement syntax");
	(yyval.tac)=NULL;
}
#line 1576 "y.tab.c"
    break;

  case 37: /* block: '{' declaration_list statement_list '}'  */
#line 182 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[-1].tac));
}
#line 1584 "y.tab.c"
    break;

  case 38: /* declaration_list: %empty  */
#line 188 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1592 "y.tab.c"
    break;

  case 39: /* declaration_list: declaration_list declaration  */
#line 192 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1600 "y.tab.c"
    break;

  case 41: /* statement_list: statement_list statement  */
#line 199 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1608 "y.tab.c"
    break;

  case 42: /* assignment_statement: IDENTIFIER '=' expression  */
#line 205 "mini.y"
{
	(yyval.tac)=do_assign(get_var((yyvsp[-2].string)), (yyvsp[0].exp));
}
#line 1616 "y.tab.c"
    break;

  case 43: /* assignment_statement: '*' IDENTIFIER '=' expression  */
#line 209 "mini.y"
{
    (yyval.tac) = do_assign_pointer(get_var((yyvsp[-2].string)), (yyvsp[0].exp)); // 对解引用指针赋值
}
#line 1624 "y.tab.c"
    break;

  case 44: /* assignment_statement: IDENTIFIER '[' expression ']' '=' expression  */
#line 213 "mini.y"
{
	(yyval.tac) = do_assign_array(get_var((yyvsp[-5].string)),(yyvsp[-3].exp),(yyvsp[0].exp));
}
#line 1632 "y.tab.c"
    break;

  case 45: /* expression: expression '+' expression  */
#line 219 "mini.y"
{
	(yyval.exp)=do_bin(TAC_ADD, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1640 "y.tab.c"
    break;

  case 46: /* expression: expression '-' expression  */
#line 223 "mini.y"
{
	(yyval.exp)=do_bin(TAC_SUB, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1648 "y.tab.c"
    break;

  case 47: /* expression: expression '*' expression  */
#line 227 "mini.y"
{
	(yyval.exp)=do_bin(TAC_MUL, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1656 "y.tab.c"
    break;

  case 48: /* expression: expression '/' expression  */
#line 231 "mini.y"
{
	(yyval.exp)=do_bin(TAC_DIV, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1664 "y.tab.c"
    break;

  case 49: /* expression: '-' expression  */
#line 235 "mini.y"
{
	(yyval.exp)=do_un(TAC_NEG, (yyvsp[0].exp));
}
#line 1672 "y.tab.c"
    break;

  case 50: /* expression: expression EQ expression  */
#line 239 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_EQ, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1680 "y.tab.c"
    break;

  case 51: /* expression: expression NE expression  */
#line 243 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_NE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1688 "y.tab.c"
    break;

  case 52: /* expression: expression LT expression  */
#line 247 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1696 "y.tab.c"
    break;

  case 53: /* expression: expression LE expression  */
#line 251 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1704 "y.tab.c"
    break;

  case 54: /* expression: expression GT expression  */
#line 255 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1712 "y.tab.c"
    break;

  case 55: /* expression: expression GE expression  */
#line 259 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1720 "y.tab.c"
    break;

  case 56: /* expression: '&' IDENTIFIER  */
#line 263 "mini.y"
{
    (yyval.exp) = get_address(get_var((yyvsp[0].string))); // 取变量地址
}
#line 1728 "y.tab.c"
    break;

  case 57: /* expression: '*' expression  */
#line 267 "mini.y"
{
    (yyval.exp) = mk_dereference((yyvsp[0].exp)); // 解引用指针
}
#line 1736 "y.tab.c"
    break;

  case 58: /* expression: '(' expression ')'  */
#line 271 "mini.y"
{
	(yyval.exp)=(yyvsp[-1].exp);
}
#line 1744 "y.tab.c"
    break;

  case 59: /* expression: INTEGER  */
#line 275 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_const(atoi((yyvsp[0].string))), NULL);
}
#line 1752 "y.tab.c"
    break;

  case 60: /* expression: IDENTIFIER  */
#line 279 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, get_var((yyvsp[0].string)), NULL);
}
#line 1760 "y.tab.c"
    break;

  case 61: /* expression: call_expression  */
#line 283 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1768 "y.tab.c"
    break;

  case 62: /* expression: array_expression  */
#line 287 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1776 "y.tab.c"
    break;

  case 63: /* expression: error  */
#line 291 "mini.y"
{
	error("Bad expression syntax");
	(yyval.exp)=mk_exp(NULL, NULL, NULL);
}
#line 1785 "y.tab.c"
    break;

  case 64: /* expression: CONST_CHAR  */
#line 296 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_char((yyvsp[0].string)), NULL);
}
#line 1793 "y.tab.c"
    break;

  case 65: /* expression: ESCAPE_CHAR  */
#line 300 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_escape_char((yyvsp[0].string)), NULL);
}
#line 1801 "y.tab.c"
    break;

  case 66: /* argument_list: %empty  */
#line 306 "mini.y"
{
	(yyval.exp)=NULL;
}
#line 1809 "y.tab.c"
    break;

  case 69: /* expression_list: expression_list ',' expression  */
#line 314 "mini.y"
{
	(yyvsp[0].exp)->next=(yyvsp[-2].exp);
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1818 "y.tab.c"
    break;

  case 70: /* print_statement: PRINT '(' print_list ')'  */
#line 321 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1826 "y.tab.c"
    break;

  case 72: /* print_list: print_list ',' print_item  */
#line 328 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 1834 "y.tab.c"
    break;

  case 73: /* print_item: expression  */
#line 334 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[0].exp)->tac,
	do_lib("PRINTN", (yyvsp[0].exp)->ret));
}
#line 1843 "y.tab.c"
    break;

  case 74: /* print_item: TEXT  */
#line 339 "mini.y"
{
	(yyval.tac)=do_lib("PRINTS", mk_text((yyvsp[0].string)));
}
#line 1851 "y.tab.c"
    break;

  case 75: /* return_statement: RETURN expression  */
#line 345 "mini.y"
{
	TAC *t=mk_tac(TAC_RETURN, (yyvsp[0].exp)->ret, NULL, NULL);
	t->prev=(yyvsp[0].exp)->tac;
	(yyval.tac)=t;
}
#line 1861 "y.tab.c"
    break;

  case 76: /* null_statement: CONTINUE  */
#line 353 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1869 "y.tab.c"
    break;

  case 77: /* if_statement: IF '(' expression ')' block  */
#line 359 "mini.y"
{
	(yyval.tac)=do_if((yyvsp[-2].exp), (yyvsp[0].tac));
}
#line 1877 "y.tab.c"
    break;

  case 78: /* if_statement: IF '(' expression ')' block ELSE block  */
#line 363 "mini.y"
{
	(yyval.tac)=do_test((yyvsp[-4].exp), (yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 1885 "y.tab.c"
    break;

  case 79: /* while_statement: WHILE '(' expression ')' block  */
#line 369 "mini.y"
{
	(yyval.tac)=do_while((yyvsp[-2].exp), (yyvsp[0].tac));
}
#line 1893 "y.tab.c"
    break;

  case 80: /* for_statement: FOR '(' assignment_statement ';' expression ';' assignment_statement ')' block  */
#line 375 "mini.y"
{
	(yyval.tac)=do_for((yyvsp[-6].tac), (yyvsp[-4].exp), (yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 1901 "y.tab.c"
    break;

  case 81: /* call_statement: IDENTIFIER '(' argument_list ')'  */
#line 380 "mini.y"
{
	(yyval.tac)=do_call((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 1909 "y.tab.c"
    break;

  case 82: /* call_expression: IDENTIFIER '(' argument_list ')'  */
#line 386 "mini.y"
{
	(yyval.exp)=do_call_ret((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 1917 "y.tab.c"
    break;

  case 83: /* array_expression: IDENTIFIER '[' expression ']'  */
#line 392 "mini.y"
{
	(yyval.exp)=do_array(get_var((yyvsp[-3].string)),(yyvsp[-1].exp));
}
#line 1925 "y.tab.c"
    break;


#line 1929 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 397 "mini.y"


void yyerror(char* msg) 
{
	fprintf(stderr, "%s: line %d\n", msg, yylineno);
	exit(0);
}

int main(int argc,   char *argv[])
{
	if(argc != 2)
	{
		printf("usage: %s filename\n", argv[0]);
		exit(0);
	}
	
	char *input, *output;

	input = argv[1];
	if(freopen(input, "r", stdin)==NULL)
	{
		printf("error: open %s failed\n", input);
		return 0;
	}

	output=(char *)malloc(strlen(input + 10));
	strcpy(output,input);
	strcat(output,".t");

	if(freopen(output, "w", stdout)==NULL)
	{
		printf("error: open %s failed\n", output);
		return 0;
	}

	tac_init();

	yyparse();

	tac_dump();

	tac_obj();

	return 0;
}


