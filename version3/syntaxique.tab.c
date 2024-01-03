
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "syntaxique.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts_liste.h"
#include "quad.h"
 extern  nb_ligne;
 extern Col;
 int qc=0;
 extern char fileName[50];
Stack *stack_type;
Stack *stack_value;
Stack *stack_name_Routine ; 
Stack *stack_variable ; 
Stack *stack_BZ;
Stack *stack_deb_cond;
  char code [MAX_CODE_LENGTH];
  char save_type_operateur [MAX_TYPE_LENGTH];
  char op1 [MAX_STRING_SIZE];
  char op2 [MAX_STRING_SIZE];
  char strg[MAX_STRING_SIZE];
  char strg2[MAX_STRING_SIZE];    
  char TAB_reference[MAX_STRING_SIZE];
  char Type_routine[MAX_TYPE_LENGTH];
  char temp[10];
  char sauv_BZ1;
  int taille2 = 0 ; 
  int firstSize;
  int secondSize;
  int nbArg = 0 ; 
  int cmpt= 0; 
  int nbArg_Write=0 ; 
  int nbArg_Eqv =0 ; 
  int sauv_BR,Fin_inst_cond, deb_cond,sauv_BZ;
  bool divZero = false ;


/* Line 189 of yacc.c  */
#line 111 "syntaxique.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM_mc = 258,
     END_mc = 259,
     ROUTINE_mc = 260,
     ENDR_mc = 261,
     LOGICAL_mc = 262,
     TRUE_mc = 263,
     FALSE_mc = 264,
     CHARACTER_mc = 265,
     REAL_mc = 266,
     INTEGER_mc = 267,
     DIMENSION_mc = 268,
     READ_mc = 269,
     WRITE_mc = 270,
     IF_mc = 271,
     THEN_mc = 272,
     ELSE_mc = 273,
     ENDIF_mc = 274,
     GT_mc = 275,
     GE_mc = 276,
     EQ_mc = 277,
     NE_mc = 278,
     LE_mc = 279,
     LT_mc = 280,
     OR_mc = 281,
     AND_mc = 282,
     DOWHILE_mc = 283,
     ENDDO_mc = 284,
     EQUIVALENCE_mc = 285,
     CALL_mc = 286,
     idf = 287,
     cst_int = 288,
     cst_real = 289,
     character = 290,
     aff = 291,
     plus = 292,
     moins = 293,
     divis = 294,
     multip = 295,
     pvg = 296,
     ver = 297,
     point = 298,
     par_ouvrante = 299,
     par_fermante = 300,
     points_sup = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 39 "syntaxique.y"

  int     entier;
  char*   str;
  float reel; 



/* Line 214 of yacc.c  */
#line 201 "syntaxique.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 213 "syntaxique.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   299

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNRULES -- Number of states.  */
#define YYNSTATES  256

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    15,    16,    25,    29,    34,
      39,    44,    46,    48,    50,    51,    55,    64,    71,    73,
      80,    85,    90,    95,    99,   100,   105,   108,   112,   114,
     122,   130,   133,   134,   137,   140,   143,   146,   152,   156,
     161,   168,   170,   174,   177,   182,   185,   187,   189,   191,
     194,   195,   197,   199,   201,   203,   205,   207,   212,   217,
     222,   227,   233,   239,   245,   249,   253,   255,   257,   259,
     263,   267,   269,   273,   277,   279,   281,   285,   289,   291,
     295,   299,   302,   304,   306,   310,   312,   314,   316,   318,
     325,   330,   334,   336,   340,   342,   344,   346,   352,   358,
     364,   370,   376,   382,   384,   386,   392,   398,   402,   406,
     408,   410,   414,   418,   422,   428,   432,   437,   439,   448,
     450,   451,   455,   457,   459,   461
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    50,    49,    57,    65,     4,    -1,     3,
      32,    -1,    51,    50,    -1,    -1,    52,    44,    55,    45,
      57,    65,    53,     6,    -1,    54,     5,    32,    -1,    32,
      36,    75,    41,    -1,    32,    36,    35,    41,    -1,    32,
      36,    86,    41,    -1,    64,    -1,    10,    -1,    56,    -1,
      -1,    32,    42,    56,    -1,    32,    44,    33,    42,    33,
      45,    42,    56,    -1,    32,    44,    33,    45,    42,    56,
      -1,    32,    -1,    32,    44,    33,    42,    33,    45,    -1,
      32,    44,    33,    45,    -1,    64,    58,    41,    57,    -1,
      10,    62,    41,    57,    -1,    59,    41,    57,    -1,    -1,
      32,    61,    42,    58,    -1,    32,    61,    -1,    32,    42,
      58,    -1,    32,    -1,    64,    32,    13,    44,    33,    60,
      45,    -1,    10,    32,    13,    44,    33,    60,    45,    -1,
      42,    33,    -1,    -1,    36,    33,    -1,    36,    34,    -1,
      36,     8,    -1,    36,     9,    -1,    32,    40,    33,    42,
      62,    -1,    32,    40,    33,    -1,    32,    40,    33,    63,
      -1,    32,    40,    33,    63,    42,    62,    -1,    32,    -1,
      32,    42,    62,    -1,    32,    63,    -1,    32,    63,    42,
      62,    -1,    36,    35,    -1,    12,    -1,    11,    -1,     7,
      -1,    65,    66,    -1,    -1,    67,    -1,    68,    -1,    71,
      -1,    90,    -1,    87,    -1,    93,    -1,    32,    36,    75,
      41,    -1,    32,    36,    35,    41,    -1,    80,    36,    75,
      41,    -1,    32,    36,    86,    41,    -1,    15,    44,    69,
      45,    41,    -1,    14,    44,    32,    45,    41,    -1,    14,
      44,    80,    45,    41,    -1,    69,    42,    96,    -1,    69,
      42,    75,    -1,    96,    -1,    75,    -1,    35,    -1,    30,
      72,    41,    -1,    72,    42,    73,    -1,    73,    -1,    44,
      74,    45,    -1,    74,    42,    75,    -1,    75,    -1,    76,
      -1,    76,    37,    77,    -1,    76,    38,    77,    -1,    77,
      -1,    77,    40,    79,    -1,    77,    39,    78,    -1,    38,
      79,    -1,    79,    -1,    79,    -1,    44,    76,    45,    -1,
      33,    -1,    34,    -1,    80,    -1,    32,    -1,    32,    44,
      33,    42,    33,    45,    -1,    32,    44,    33,    45,    -1,
      81,    26,    82,    -1,    82,    -1,    82,    27,    83,    -1,
      83,    -1,    85,    -1,    84,    -1,    85,    43,    25,    43,
      85,    -1,    85,    43,    20,    43,    85,    -1,    85,    43,
      23,    43,    85,    -1,    85,    43,    24,    43,    85,    -1,
      85,    43,    21,    43,    85,    -1,    85,    43,    22,    43,
      85,    -1,    75,    -1,    86,    -1,    44,    81,    26,    82,
      45,    -1,    44,    82,    27,    83,    45,    -1,    44,    84,
      45,    -1,    44,    86,    45,    -1,     8,    -1,     9,    -1,
      88,    65,    19,    -1,    89,    65,    19,    -1,    89,    65,
      18,    -1,    16,    44,    81,    45,    17,    -1,    91,    65,
      29,    -1,    92,    44,    81,    45,    -1,    28,    -1,    32,
      36,    31,    32,    44,    94,    45,    41,    -1,    95,    -1,
      -1,    95,    42,    75,    -1,    75,    -1,    97,    -1,    98,
      -1,    70,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    49,    49,    51,    53,    55,    57,    60,    62,    63,
      70,    80,    80,    82,    83,    85,    86,    87,    88,    89,
      90,    93,    94,    95,    96,    98,    99,   100,   101,   104,
     105,   108,   109,   111,   112,   113,   114,   116,   117,   118,
     119,   120,   121,   122,   123,   126,   128,   129,   130,   133,
     134,   136,   137,   138,   139,   140,   141,   144,   152,   157,
     167,   178,   179,   186,   194,   195,   196,   197,   199,   203,
     205,   206,   208,   210,   211,   213,   215,   216,   217,   220,
     223,   224,   225,   227,   229,   230,   235,   240,   241,   251,
     264,   277,   278,   280,   281,   283,   284,   286,   287,   288,
     289,   290,   291,   293,   294,   295,   296,   297,   298,   300,
     300,   302,   306,   311,   317,   325,   331,   334,   337,   347,
     348,   350,   351,   354,   356,   358
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM_mc", "END_mc", "ROUTINE_mc",
  "ENDR_mc", "LOGICAL_mc", "TRUE_mc", "FALSE_mc", "CHARACTER_mc",
  "REAL_mc", "INTEGER_mc", "DIMENSION_mc", "READ_mc", "WRITE_mc", "IF_mc",
  "THEN_mc", "ELSE_mc", "ENDIF_mc", "GT_mc", "GE_mc", "EQ_mc", "NE_mc",
  "LE_mc", "LT_mc", "OR_mc", "AND_mc", "DOWHILE_mc", "ENDDO_mc",
  "EQUIVALENCE_mc", "CALL_mc", "idf", "cst_int", "cst_real", "character",
  "aff", "plus", "moins", "divis", "multip", "pvg", "ver", "point",
  "par_ouvrante", "par_fermante", "points_sup", "$accept", "S", "MAIN",
  "Fonction_i", "fonc", "save_name_func", "Affectation_fonction",
  "type_fonc", "ARG", "liste_parametres", "DEC", "SUITE_DEC", "DEC_TAB",
  "LIST_PAR_TAB", "DEC_AFF", "DEC_CHAR", "DEC_CHAR_AFF", "type",
  "INSTRUCTIONS", "TYPE_INSTRUCTION", "Affectation", "Entre_Sortie_INST",
  "SORTIE_MESSAGE", "char_niv4", "EQUIVALENCE_INST", "liste_Equivalance",
  "SUITE_EQUI", "liste_parametres_Eq", "EXP", "EXPRESSION",
  "SUITE_EXPRESSION_1", "suiteDiv", "SUITE_EXPRESSION_2", "TAB_PAR",
  "COND", "SUITE_COND_1", "SUITE_COND_2", "COND_SIMPLE", "EXPRESSION_BOOL",
  "LOGICAL_VALUE", "IF_INST", "DEBUT_INST_IF", "DEBUT_IF", "BOUCLE_INST",
  "BOUCLE_INST1", "BOUCLE_INST2", "INST_CALL", "ARG_CALL",
  "liste_parametres_CALL", "char_niv1", "char_niv2", "char_niv3", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    50,    51,    52,    53,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    57,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    61,    61,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    64,    64,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    67,    67,    67,
      67,    68,    68,    68,    69,    69,    69,    69,    70,    71,
      72,    72,    73,    74,    74,    75,    76,    76,    76,    77,
      77,    77,    77,    78,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    84,
      84,    84,    84,    85,    85,    85,    85,    85,    85,    86,
      86,    87,    87,    88,    89,    90,    91,    92,    93,    94,
      94,    95,    95,    96,    97,    98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     2,     0,     8,     3,     4,     4,
       4,     1,     1,     1,     0,     3,     8,     6,     1,     6,
       4,     4,     4,     3,     0,     4,     2,     3,     1,     7,
       7,     2,     0,     2,     2,     2,     2,     5,     3,     4,
       6,     1,     3,     2,     4,     2,     1,     1,     1,     2,
       0,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     5,     5,     5,     3,     3,     1,     1,     1,     3,
       3,     1,     3,     3,     1,     1,     3,     3,     1,     3,
       3,     2,     1,     1,     3,     1,     1,     1,     1,     6,
       4,     3,     1,     3,     1,     1,     1,     5,     5,     5,
       5,     5,     5,     1,     1,     5,     5,     3,     3,     1,
       1,     3,     3,     3,     5,     3,     4,     1,     8,     1,
       0,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    48,    12,    47,    46,     0,     0,     5,     0,     0,
      11,     1,     0,    24,     4,    14,     0,     3,     0,    50,
       0,     0,    18,     0,    13,     7,    41,     0,     0,    24,
      28,     0,     0,     0,    24,     0,     0,     0,     0,    43,
      24,     2,     0,     0,     0,   117,     0,     0,    49,    51,
      52,    53,     0,    55,    50,    50,    54,    50,     0,    56,
      23,     0,     0,     0,    26,    24,    15,     0,    50,     0,
      45,    38,    41,    42,     0,    22,     0,     0,     0,     0,
       0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    36,    33,    34,    28,    27,     0,    21,     0,    20,
       0,    32,     0,    39,    44,     0,     0,    88,    85,    86,
      68,     0,     0,     0,   125,    67,    75,    78,    82,    87,
      66,   123,   124,   109,   110,     0,   103,     0,    92,    94,
      96,    95,   104,     0,    74,    69,     0,     0,     0,     0,
       0,     0,     0,   111,   113,   112,   115,     0,    32,    25,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,    75,     0,
      92,    96,   104,     0,     0,     0,     0,     0,    72,    70,
       0,    58,    57,    60,     0,    90,    59,   116,     0,    19,
      17,     0,     6,    31,    30,    40,    62,    63,    84,    65,
      64,    61,    76,    77,    80,    83,    79,     0,     0,   107,
     108,    91,   114,    93,     0,     0,     0,     0,     0,     0,
      73,   120,     0,    29,     0,     0,     0,     0,    91,    93,
       0,     0,     0,     0,     0,     0,   122,     0,   119,    89,
      16,    58,    57,    60,   105,   106,    98,   101,   102,    99,
     100,    97,     0,     0,   118,   121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    13,     6,     7,     8,   153,     9,    23,    24,
      19,    31,    20,   155,    64,    27,    39,    21,    28,    48,
      49,    50,   113,   114,    51,    80,    81,   133,   126,   116,
     117,   204,   118,   119,   127,   128,   129,   130,   131,   132,
      53,    54,    55,    56,    57,    58,    59,   237,   238,   120,
     121,   122
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -153
static const yytype_int16 yypact[] =
{
     175,  -153,  -153,  -153,  -153,    24,    34,   175,   -17,    47,
    -153,  -153,    25,   198,  -153,    32,    49,  -153,    79,  -153,
      98,    85,    56,    96,  -153,  -153,    57,   102,    74,   198,
      -2,   117,    32,   143,   198,   139,   156,   178,   180,   171,
     198,  -153,   170,   172,   174,  -153,   176,   -19,  -153,  -153,
    -153,  -153,   179,  -153,  -153,  -153,  -153,  -153,   177,  -153,
    -153,   181,    75,   185,   182,   198,  -153,    35,  -153,   186,
    -153,    78,    76,  -153,   180,  -153,   190,   137,    27,   146,
     112,  -153,    10,   193,   146,   114,   108,   133,    27,   194,
    -153,  -153,  -153,  -153,    89,  -153,   185,  -153,   195,   187,
     136,   188,   180,   189,  -153,   115,   191,   196,  -153,  -153,
    -153,   123,   146,    65,  -153,  -153,   151,   134,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,    27,  -153,   -13,   205,  -153,
    -153,   192,  -153,    90,  -153,  -153,   176,   201,   197,   200,
     202,    92,   203,  -153,  -153,  -153,  -153,   -12,   188,  -153,
     204,    32,    -5,   217,   206,   207,  -153,   180,   209,   210,
    -153,    58,   137,   212,   146,   146,   123,   123,    58,   208,
     215,   211,   213,    27,   220,    27,   173,   146,  -153,  -153,
     216,  -153,  -153,  -153,   214,  -153,  -153,  -153,   218,   219,
    -153,    41,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,   134,   134,  -153,  -153,  -153,    27,    27,  -153,
    -153,   205,  -153,  -153,   221,   222,   223,   224,   225,   226,
    -153,   146,   227,  -153,    32,   229,   230,   232,   -15,   231,
      27,    27,    27,    27,    27,    27,  -153,   233,   235,  -153,
    -153,   239,   240,   242,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,   234,   146,  -153,  -153
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,  -153,   247,  -153,  -153,  -153,  -153,  -153,   -32,
     -14,   -41,  -153,   107,  -153,   -36,   228,    21,    37,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,   121,  -153,   -76,   -96,
      42,  -153,  -104,   -18,   -79,  -120,  -152,   149,   -31,   -78,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,    97,
    -153,  -153
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -11
static const yytype_int16 yytable[] =
{
      66,   115,    73,   134,   140,   170,   139,   160,   142,   147,
      52,    61,   175,   173,   173,    60,   161,    82,   123,   124,
      68,    10,    95,   213,    11,    83,    75,    15,    10,   168,
     244,   191,   174,   187,    62,   123,   124,    12,   104,    83,
      63,   137,   107,   108,   109,   138,   169,   172,   111,   123,
     124,    97,    16,   211,   112,   149,   229,    17,   106,   107,
     108,   109,   205,   206,    22,   111,   156,    52,    52,    52,
      35,   125,   137,   107,   108,   109,   225,    98,    41,   111,
      99,    25,    52,    90,    91,   112,   199,   228,    42,    43,
      44,    85,    86,    36,    87,   164,   165,    37,    32,    38,
      33,   220,    45,   198,    46,   100,    47,   162,    92,    93,
     163,    26,    36,   227,    36,   226,    37,    30,    38,   190,
     102,   195,    42,    43,    44,    62,   144,   145,    42,    43,
      44,    63,   177,   143,   184,   178,    45,   185,    46,    29,
      47,    34,    45,    40,    46,   236,    47,    42,    43,    44,
      42,    43,    44,   135,   136,   107,   108,   109,    65,    83,
     158,    45,   146,    46,    45,    47,    46,   112,   152,   107,
     108,   109,   110,   166,   167,   111,    67,   255,   107,   108,
     109,   112,     1,    69,   111,     2,     3,     4,   164,   165,
     112,    70,   240,   214,   215,   216,   217,   218,   219,   246,
     247,   248,   249,   250,   251,     1,   202,   203,    18,     3,
       4,    71,    72,    74,    76,    84,    77,    94,    78,   101,
      79,    88,   105,   192,    96,    89,   141,   148,   150,   151,
     154,   157,   175,   180,   207,   176,   159,   212,   181,   193,
      83,   182,   208,   183,   186,    -9,    -8,   222,   -10,   189,
     196,   197,   194,   201,    14,   188,   209,   179,   210,   200,
     221,   224,     0,   223,   230,   231,   232,   233,   234,   235,
     241,   242,   239,   243,   171,   254,   245,   253,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103
};

static const yytype_int16 yycheck[] =
{
      32,    77,    38,    79,    82,   125,    82,   111,    84,    88,
      28,    13,    27,    26,    26,    29,   112,    36,     8,     9,
      34,     0,    63,   175,     0,    44,    40,    44,     7,   125,
      45,    36,    45,    45,    36,     8,     9,     3,    74,    44,
      42,    31,    32,    33,    34,    35,   125,   125,    38,     8,
       9,    65,     5,   173,    44,    96,   208,    32,    76,    32,
      33,    34,   166,   167,    32,    38,   102,    85,    86,    87,
      13,    44,    31,    32,    33,    34,    35,    42,     4,    38,
      45,    32,   100,     8,     9,    44,   162,   207,    14,    15,
      16,    54,    55,    36,    57,    37,    38,    40,    42,    42,
      44,   177,    28,    45,    30,    68,    32,    42,    33,    34,
      45,    32,    36,   191,    36,   191,    40,    32,    42,   151,
      42,   157,    14,    15,    16,    36,    18,    19,    14,    15,
      16,    42,    42,    19,    42,    45,    28,    45,    30,    41,
      32,    45,    28,    41,    30,   221,    32,    14,    15,    16,
      14,    15,    16,    41,    42,    32,    33,    34,    41,    44,
      45,    28,    29,    30,    28,    32,    30,    44,    32,    32,
      33,    34,    35,    39,    40,    38,    33,   253,    32,    33,
      34,    44,     7,    44,    38,    10,    11,    12,    37,    38,
      44,    35,   224,    20,    21,    22,    23,    24,    25,   230,
     231,   232,   233,   234,   235,     7,   164,   165,    10,    11,
      12,    33,    32,    42,    44,    36,    44,    32,    44,    33,
      44,    44,    32,     6,    42,    44,    33,    33,    33,    42,
      42,    42,    27,    32,    26,    43,    45,    17,    41,    33,
      44,    41,    27,    41,    41,     6,     6,    33,     6,    45,
      41,    41,    45,    41,     7,   148,    45,   136,    45,   162,
      44,    42,    -1,    45,    43,    43,    43,    43,    43,    43,
      41,    41,    45,    41,   125,    41,    45,    42,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    10,    11,    12,    48,    50,    51,    52,    54,
      64,     0,     3,    49,    50,    44,     5,    32,    10,    57,
      59,    64,    32,    55,    56,    32,    32,    62,    65,    41,
      32,    58,    42,    44,    45,    13,    36,    40,    42,    63,
      41,     4,    14,    15,    16,    28,    30,    32,    66,    67,
      68,    71,    80,    87,    88,    89,    90,    91,    92,    93,
      57,    13,    36,    42,    61,    41,    56,    33,    57,    44,
      35,    33,    32,    62,    42,    57,    44,    44,    44,    44,
      72,    73,    36,    44,    36,    65,    65,    65,    44,    44,
       8,     9,    33,    34,    32,    58,    42,    57,    42,    45,
      65,    33,    42,    63,    62,    32,    80,    32,    33,    34,
      35,    38,    44,    69,    70,    75,    76,    77,    79,    80,
      96,    97,    98,     8,     9,    44,    75,    81,    82,    83,
      84,    85,    86,    74,    75,    41,    42,    31,    35,    75,
      86,    33,    75,    19,    18,    19,    29,    81,    33,    58,
      33,    42,    32,    53,    42,    60,    62,    42,    45,    45,
      79,    76,    42,    45,    37,    38,    39,    40,    76,    81,
      82,    84,    86,    26,    45,    27,    43,    42,    45,    73,
      32,    41,    41,    41,    42,    45,    41,    45,    60,    45,
      56,    36,     6,    33,    45,    62,    41,    41,    45,    75,
      96,    41,    77,    77,    78,    79,    79,    26,    27,    45,
      45,    82,    17,    83,    20,    21,    22,    23,    24,    25,
      75,    44,    33,    45,    42,    35,    75,    86,    82,    83,
      43,    43,    43,    43,    43,    43,    75,    94,    95,    45,
      56,    41,    41,    41,    45,    45,    85,    85,    85,    85,
      85,    85,    45,    42,    41,    75
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 51 "syntaxique.y"
    {push(stack_name_Routine,"main");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 54 "syntaxique.y"
    { traitement_Fin_Routine(stack_name_Routine,stack_value,stack_type);  nbArg = 0;;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 57 "syntaxique.y"
    { check_Affectation_fin_Routine(stack_type,save_type_operateur,&cmpt);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 60 "syntaxique.y"
    {push(stack_name_Routine,(yyvsp[(3) - (3)].str));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 62 "syntaxique.y"
    {Check_Retour_Routine((yyvsp[(1) - (4)].str), stack_name_Routine);strcpy(strg,top(stack_variable));quadr(":=",strg,"vide",(yyvsp[(1) - (4)].str));pop(stack_variable);quadr("return",(yyvsp[(1) - (4)].str),"vide","vide");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 63 "syntaxique.y"
    {Check_Retour_Routine((yyvsp[(1) - (4)].str), stack_name_Routine);
                                             strcpy(save_type_operateur,"CHARACTER");
                                             cmpt=cmpt+2;
                                             quadr(":=",(yyvsp[(3) - (4)].str),"vide",(yyvsp[(1) - (4)].str));
                                             quadr("return",(yyvsp[(1) - (4)].str),"vide","vide");
                                             cmpt =0;
                                            ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 70 "syntaxique.y"
    {Check_Retour_Routine((yyvsp[(1) - (4)].str), stack_name_Routine);
                                             strcpy(save_type_operateur,"LOGICAL");
                                              cmpt=cmpt+2;
                                              strcpy(strg,top(stack_variable));
                                              quadr(":=",strg,"vide",(yyvsp[(1) - (4)].str));
                                              pop(stack_variable);
                                              quadr("return",(yyvsp[(1) - (4)].str),"vide","vide");
                                              pop(stack_value);
                                            ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 80 "syntaxique.y"
    {push(stack_type, "CHARACTER")  ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 82 "syntaxique.y"
    {push(stack_value,intToString(nbArg));quadParametre(stack_variable,nbArg);nbArg=0; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 83 "syntaxique.y"
    {push(stack_value,"0"); nbArg=0;;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 85 "syntaxique.y"
    {add_SCOPE_Cst_Idf((yyvsp[(1) - (3)].str),top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (3)].str),"VARIABLE",top(stack_name_Routine));nbArg++;push(stack_variable,(yyvsp[(1) - (3)].str));initVar((yyvsp[(1) - (3)].str),stack_name_Routine);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 86 "syntaxique.y"
    {add_SCOPE_Cst_Idf((yyvsp[(1) - (8)].str),top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (8)].str),"MATRICE",top(stack_name_Routine));add_Taille_Tab_Mat((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].entier),(yyvsp[(5) - (8)].entier),stack_name_Routine);nbArg++;Tab_idfInStack_Quad(stack_variable,(yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].entier),(yyvsp[(5) - (8)].entier));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 87 "syntaxique.y"
    {add_SCOPE_Cst_Idf((yyvsp[(1) - (6)].str),top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (6)].str),"TABLEAU",top(stack_name_Routine));add_Taille_Tab_Mat((yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].entier),0,stack_name_Routine);nbArg++;Tab_idfInStack_Quad(stack_variable,(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].entier),-1);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 88 "syntaxique.y"
    {add_SCOPE_Cst_Idf((yyvsp[(1) - (1)].str),top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (1)].str),"VARIABLE",top(stack_name_Routine));nbArg++;push(stack_variable,(yyvsp[(1) - (1)].str));initVar((yyvsp[(1) - (1)].str),stack_name_Routine);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 89 "syntaxique.y"
    {add_SCOPE_Cst_Idf((yyvsp[(1) - (6)].str),top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (6)].str),"MATRICE",top(stack_name_Routine));add_Taille_Tab_Mat((yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].entier),(yyvsp[(5) - (6)].entier),stack_name_Routine);nbArg++;Tab_idfInStack_Quad(stack_variable,(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].entier),(yyvsp[(5) - (6)].entier));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 90 "syntaxique.y"
    {add_SCOPE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (4)].str),"TABLEAU",top(stack_name_Routine));add_Taille_Tab_Mat((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].entier),0,stack_name_Routine);nbArg++;Tab_idfInStack_Quad(stack_variable,(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].entier),-1);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 93 "syntaxique.y"
    {pop(stack_type);}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 98 "syntaxique.y"
    {Taitement_SUITE_DEC((yyvsp[(1) - (4)].str),stack_name_Routine,stack_type); add_VALUE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_value),top(stack_name_Routine)); pop(stack_value);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 99 "syntaxique.y"
    {Taitement_SUITE_DEC((yyvsp[(1) - (2)].str),stack_name_Routine,stack_type); add_VALUE_Cst_Idf((yyvsp[(1) - (2)].str),top(stack_value),top(stack_name_Routine)); pop(stack_value);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 100 "syntaxique.y"
    {Taitement_SUITE_DEC((yyvsp[(1) - (3)].str),stack_name_Routine,stack_type);}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 101 "syntaxique.y"
    {Taitement_SUITE_DEC((yyvsp[(1) - (1)].str),stack_name_Routine,stack_type);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 104 "syntaxique.y"
    {if(idf_exist((yyvsp[(2) - (7)].str),top(stack_name_Routine)))semantiqueError("Double declaration");add_SCOPE_Cst_Idf((yyvsp[(2) - (7)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(2) - (7)].str),top(stack_type),top(stack_name_Routine));add_Taille_Tab_Mat((yyvsp[(2) - (7)].str),(yyvsp[(5) - (7)].entier),taille2,stack_name_Routine) ;taille2= 0;add_CODE_Cst_Idf((yyvsp[(2) - (7)].str),code,top(stack_name_Routine));pop(stack_type);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 105 "syntaxique.y"
    {if(idf_exist((yyvsp[(2) - (7)].str),top(stack_name_Routine)))semantiqueError("Double declaration");add_SCOPE_Cst_Idf((yyvsp[(2) - (7)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(2) - (7)].str),"CHARACTER",top(stack_name_Routine));add_Taille_Tab_Mat((yyvsp[(2) - (7)].str),(yyvsp[(5) - (7)].entier),taille2,stack_name_Routine) ;taille2= 0;add_CODE_Cst_Idf((yyvsp[(2) - (7)].str),code,top(stack_name_Routine));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 108 "syntaxique.y"
    {taille2 = (yyvsp[(2) - (2)].entier); strcpy(code,"MATRICE");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 109 "syntaxique.y"
    {strcpy(code,"TABLEAU");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 111 "syntaxique.y"
    {push(stack_value, intToString((yyvsp[(2) - (2)].entier)));push(stack_variable,intToString((yyvsp[(2) - (2)].entier)));}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 112 "syntaxique.y"
    {push(stack_value, floatToString((yyvsp[(2) - (2)].reel)));push(stack_variable,floatToString((yyvsp[(2) - (2)].reel))) ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 113 "syntaxique.y"
    {push(stack_value, (yyvsp[(2) - (2)].str));push(stack_variable,(yyvsp[(2) - (2)].str));  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 114 "syntaxique.y"
    {push(stack_value, (yyvsp[(2) - (2)].str));push(stack_variable,(yyvsp[(2) - (2)].str));  ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 116 "syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(1) - (5)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(1) - (5)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (5)].str), "CHARACTER",top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (5)].str),"VARIABLE",top(stack_name_Routine));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 117 "syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(1) - (3)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(1) - (3)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (3)].str), "CHARACTER",top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (3)].str),"VARIABLE",top(stack_name_Routine));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 118 "syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(1) - (4)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (4)].str), "CHARACTER",top(stack_name_Routine));add_VALUE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(1) - (4)].str),"VARIABLE",top(stack_name_Routine));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 119 "syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(1) - (6)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(1) - (6)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (6)].str), "CHARACTER",top(stack_name_Routine));add_VALUE_Cst_Idf((yyvsp[(1) - (6)].str),top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(1) - (6)].str),"VARIABLE",top(stack_name_Routine));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 120 "syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(1) - (1)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(1) - (1)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (1)].str), "CHARACTER",top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (1)].str),"VARIABLE",top(stack_name_Routine));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 121 "syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(1) - (3)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(1) - (3)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (3)].str), "CHARACTER",top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (3)].str),"VARIABLE",top(stack_name_Routine));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 122 "syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(1) - (2)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(1) - (2)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (2)].str), "CHARACTER",top(stack_name_Routine));add_VALUE_Cst_Idf((yyvsp[(1) - (2)].str),top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(1) - (2)].str),"VARIABLE",top(stack_name_Routine));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 123 "syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(1) - (4)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (4)].str), "CHARACTER",top(stack_name_Routine));add_VALUE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(1) - (4)].str),"VARIABLE",top(stack_name_Routine));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 126 "syntaxique.y"
    {push(stack_value,(yyvsp[(2) - (2)].str));push(stack_variable,(yyvsp[(2) - (2)].str));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 128 "syntaxique.y"
    {push(stack_type, "INTEGER");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 129 "syntaxique.y"
    {push(stack_type, "REAL");}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 130 "syntaxique.y"
    {push(stack_type, "LOGICAL");}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 144 "syntaxique.y"
    {check_idf_Variable_Existe((yyvsp[(1) - (4)].str),stack_name_Routine);
                                          checkType_affectation_idf((yyvsp[(1) - (4)].str),save_type_operateur,stack_name_Routine,cmpt);
                                                cmpt=0;
                                                strcpy(strg,top(stack_variable));
                                                quadr(":=",strg,"vide",(yyvsp[(1) - (4)].str));
                                                pop(stack_variable);
                                                initVar((yyvsp[(1) - (4)].str),stack_name_Routine);
                                          ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 152 "syntaxique.y"
    {check_idf_Variable_Existe((yyvsp[(1) - (4)].str),stack_name_Routine);
                                           if(strcmp(return_TYPE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_name_Routine)),"CHARACTER")) semantiqueError("Incompatible types\n");
                                           quadr(":=",(yyvsp[(3) - (4)].str),"vide",(yyvsp[(1) - (4)].str));
                                           add_VALUE_Cst_Idf((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),top(stack_name_Routine));
                                          ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 157 "syntaxique.y"
    {
                                          checkType_affectation_TAB(TAB_reference,save_type_operateur,stack_name_Routine,cmpt);
                                                cmpt=0; 
                                                strcpy(strg,top(stack_variable));
                                                pop(stack_variable);
                                                strcpy(strg2,top(stack_variable));
                                                pop(stack_variable);
                                                quadr(":=",strg,"vide",strg2 );
                                          ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 167 "syntaxique.y"
    {check_idf_Variable_Existe((yyvsp[(1) - (4)].str),stack_name_Routine);
                                           checkType_affectation_idf_Logical((yyvsp[(1) - (4)].str),stack_name_Routine);
                                           strcpy(strg,top(stack_variable));
                                           quadr(":=",strg,"vide",(yyvsp[(1) - (4)].str));
                                           pop(stack_variable);
                                           add_VALUE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_value),top(stack_name_Routine));
                                           pop(stack_value);
                                           ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 178 "syntaxique.y"
    {quadr("CALL", "WRITE", intToString(nbArg_Write), "vide");nbArg_Write=0; ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 179 "syntaxique.y"
    {        //verifier si c'est le bon idf : 
                                                                  checkIdfRead_Variable_elem((yyvsp[(3) - (5)].str), stack_name_Routine);
                                                                  // remlir quadruplets
                                                                  quadRead((yyvsp[(3) - (5)].str));
                                                                  // La variable devient initialise apres la lecture 
                                                                  initVar((yyvsp[(3) - (5)].str),stack_name_Routine);
                                                                  ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 186 "syntaxique.y"
    { //verifier si c'est le bon idf : 
                                                                  checkIdfRead_Variable_Tableau(stack_variable,stack_name_Routine);
                                                                  // remlir quadruplets
                                                                  strcpy(strg, top(stack_variable));
                                                                  quadRead(strg);
                                                                  pop(stack_variable);
                                                                  ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 194 "syntaxique.y"
    {quadArgument(stack_variable);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 195 "syntaxique.y"
    { cmpt=0;nbArg_Write++; quadArgument(stack_variable);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 196 "syntaxique.y"
    {quadArgument(stack_variable);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 197 "syntaxique.y"
    { cmpt=0; nbArg_Write++;quadArgument(stack_variable);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 199 "syntaxique.y"
    {push(stack_variable,(yyvsp[(1) - (1)].str));nbArg_Write++;;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 208 "syntaxique.y"
    {quadr("CALL","EQUIVALENCE",intToString(nbArg_Eqv),"vide");nbArg_Eqv=0;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 210 "syntaxique.y"
    { cmpt=0; quadArgument(stack_variable);nbArg_Eqv++;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 211 "syntaxique.y"
    { cmpt=0; quadArgument(stack_variable);nbArg_Eqv++; ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 213 "syntaxique.y"
    {divZero=false; ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 215 "syntaxique.y"
    {divZero=false;quadExpression(stack_variable,"+",temp);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 216 "syntaxique.y"
    {divZero=false;quadExpression(stack_variable,"-",temp);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 220 "syntaxique.y"
    {divZero=false;quadExpression(stack_variable,"*",temp);

                                                                    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 223 "syntaxique.y"
    {divZero=false;quadExpression(stack_variable,"/",temp);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 224 "syntaxique.y"
    {divZero=false;quadOpUnaire(stack_variable,"Moins Unaire");}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 227 "syntaxique.y"
    {checkDivPar0(divZero);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 229 "syntaxique.y"
    {;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 230 "syntaxique.y"
    {if((yyvsp[(1) - (1)].entier)==0)divZero=true;else divZero = false ; 
                              if (cmpt==0 || cmpt==1) strcpy(save_type_operateur,"INTEGER"); 
                              cmpt=cmpt+2;
                              push(stack_variable,intToString((yyvsp[(1) - (1)].entier)));
                              ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 235 "syntaxique.y"
    {if((yyvsp[(1) - (1)].reel)==0)divZero=true;else divZero = false;
                              if (cmpt==0 || cmpt==1) strcpy(save_type_operateur,"REAL");            
                              cmpt=cmpt+2;
                              push(stack_variable, floatToString((yyvsp[(1) - (1)].reel)));
                              ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 240 "syntaxique.y"
    {  divZero = false  ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 241 "syntaxique.y"
    {
                              check_idf_Variable_Existe((yyvsp[(1) - (1)].str),stack_name_Routine);
                              checkInit((yyvsp[(1) - (1)].str),stack_name_Routine); // verifier que la variable est initialisee 
                              divZero = activerDivPar0((yyvsp[(1) - (1)].str),stack_name_Routine);   
                              if (cmpt==0 || cmpt==1) strcpy(save_type_operateur,return_TYPE_Cst_Idf((yyvsp[(1) - (1)].str),top(stack_name_Routine))); 
                              cmpt=cmpt+2;
                              push(stack_variable,(yyvsp[(1) - (1)].str));
                            ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 251 "syntaxique.y"
    {check_idf_Matrice_Existe((yyvsp[(1) - (6)].str),stack_name_Routine);
                                                            checkSize( (yyvsp[(1) - (6)].str), stack_name_Routine,  (yyvsp[(3) - (6)].entier),  (yyvsp[(5) - (6)].entier)); 
                                                            if (cmpt ==0)
                                                              strcpy(TAB_reference,return_TYPE_Cst_Idf((yyvsp[(1) - (6)].str),top(stack_name_Routine))); 

                                                            if (cmpt==1 ) { 
                                                                  
                                                                  strcpy(save_type_operateur,return_TYPE_Cst_Idf((yyvsp[(1) - (6)].str),top(stack_name_Routine))); 
                                                                  
                                                             }
                                                             cmpt++;
                                                                  Tab_idfInStack_Quad(stack_variable,(yyvsp[(1) - (6)].str),(yyvsp[(3) - (6)].entier),(yyvsp[(5) - (6)].entier));
                                                            ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 264 "syntaxique.y"
    {check_idf_Tableau_Existe((yyvsp[(1) - (4)].str),stack_name_Routine);
                                                            checkSize( (yyvsp[(1) - (4)].str), stack_name_Routine,  (yyvsp[(3) - (4)].entier),  0); 
                                                            if (cmpt==0)
                                                                  strcpy(TAB_reference,return_TYPE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_name_Routine))); 
                                                            if (cmpt==1 ) { 
                                                                  
                                                                  strcpy(save_type_operateur,return_TYPE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_name_Routine))); 
                                                             }
                                                             cmpt++;
                                                             Tab_idfInStack_Quad(stack_variable,(yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].entier),-1);
                                                            ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 277 "syntaxique.y"
    {quadExpression(stack_variable,"OR",temp);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 280 "syntaxique.y"
    {quadExpression(stack_variable,"AND",temp);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 286 "syntaxique.y"
    {quadExpression(stack_variable,"LT",temp);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 287 "syntaxique.y"
    {quadExpression(stack_variable,"GT",temp);;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 288 "syntaxique.y"
    {quadExpression(stack_variable,"NE",temp);;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 289 "syntaxique.y"
    {quadExpression(stack_variable,"LE",temp);;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 290 "syntaxique.y"
    {quadExpression(stack_variable,"GE",temp);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 291 "syntaxique.y"
    {quadExpression(stack_variable,"EQ",temp);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 293 "syntaxique.y"
    {cmpt=0;;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 294 "syntaxique.y"
    {pop(stack_value);;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 295 "syntaxique.y"
    {quadExpression(stack_variable,"OR",temp);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 296 "syntaxique.y"
    {quadExpression(stack_variable,"AND",temp);;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 298 "syntaxique.y"
    {pop(stack_value);;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 300 "syntaxique.y"
    {push(stack_variable,(yyvsp[(1) - (1)].str));push(stack_value,(yyvsp[(1) - (1)].str));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 300 "syntaxique.y"
    {push(stack_variable,(yyvsp[(1) - (1)].str));push(stack_value,(yyvsp[(1) - (1)].str));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 302 "syntaxique.y"
    {
                                             ajour_quad(sauv_BR,1,intToString(qc));
						         ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 306 "syntaxique.y"
    {  sprintf(strg,"%d",qc);
                                             ajour_quad(atoi(top(stack_BZ)),1,intToString(qc));
                                             pop(stack_BZ);
						      ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 311 "syntaxique.y"
    {sauv_BR=qc;
                                               quadr("BR","","vide","vide");   
                                               ajour_quad(atoi(top(stack_BZ)),1,intToString(qc));
                                               pop(stack_BZ);;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 317 "syntaxique.y"
    {
                                                           push(stack_BZ,intToString(qc));
                                                           quadr("BZ", "",temp, "vide"); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 325 "syntaxique.y"
    {strcpy(strg,top(stack_deb_cond));
                                                quadr("BR", strg ,"vide", "vide"); 
                                                pop(stack_deb_cond);
                                                ajour_quad(atoi(top(stack_BZ)),1,intToString(qc));
                                                pop(stack_BZ);;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 331 "syntaxique.y"
    {push(stack_BZ,intToString(qc)); // J'ai laisser le champs 2 vide. Je dois le remplir apres
                                                            quadr("BZ", "",temp, "vide"); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 334 "syntaxique.y"
    {push(stack_deb_cond,intToString(qc));;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 337 "syntaxique.y"
    {
                                                                      check_idf_Aff_Call((yyvsp[(3) - (8)].str),stack_name_Routine); // verifier qu'il existe + n'est pas une routine
                                                                      CheckRoutineExiste ((yyvsp[(4) - (8)].str));
                                                                      check_Routine_Signature((yyvsp[(4) - (8)].str),stack_name_Routine,nbArg);
                                                                      check_TypeRetour_compatible((yyvsp[(1) - (8)].str),(yyvsp[(3) - (8)].str),stack_name_Routine);
                                                                      quadr("CALL",(yyvsp[(4) - (8)].str),intToString(nbArg),"vide");//(call, nomFonc, nbArg, vide )
                                                                       nbArg = 0;
                                                                       initVar((yyvsp[(1) - (8)].str),stack_name_Routine);
                                                                      ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 350 "syntaxique.y"
    {nbArg++; cmpt=0;quadArgument(stack_variable); ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 351 "syntaxique.y"
    {nbArg++; cmpt=0;quadArgument(stack_variable);  ;}
    break;



/* Line 1455 of yacc.c  */
#line 2432 "syntaxique.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 360 "syntaxique.y"



int main(int argc , char *argv[]) {
    if(argc==2){
        FILE* fileLex =  fopen( argv[1], "r"); 
        strcpy(fileName,argv[1]);
        if(fileLex == NULL ){
            printf("ERROR:probably file doesn't exist ");
            return EXIT_FAILURE ; 
        }
        else{
              stack_type = initializeStack();
              stack_BZ = initializeStack();
              stack_deb_cond = initializeStack();
              stack_value = initializeStack();
              stack_name_Routine = initializeStack();
              stack_variable = initializeStack();
            yyrestart(fileLex);

              //initialisation
               initList_Cst_Idf();
               initList_Sep_MotCle();
              yyparse(); 
              printf("syntaxe correcte \n");
              displayList_Sep_MotCle();
              displayList_Cst_Idf();
              afficher_qdr();
            fclose(fileLex); 
             return EXIT_SUCCESS;
        }


    }
    else{
        printf("too much or too littel aruments \n"); 
                return EXIT_FAILURE ; 
    }

}
yywrap ()
{}
int yyerror ( char*  msg )  
{
      printf("\nFile %s, line %d, character %d: Syntaxic error\n",fileName ,nb_ligne, Col);
      displayList_Sep_MotCle();
      displayList_Cst_Idf();
      afficher_qdr();
      exit(EXIT_FAILURE); 
}


