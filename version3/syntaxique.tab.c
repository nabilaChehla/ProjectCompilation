
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
 extern  nb_ligne;
 extern Col;
 extern char fileName[50];
Stack *stack_type;
Stack *stack_value;
Stack *stack_name_Routine ; 
  char code [MAX_CODE_LENGTH];
  char Taille [MAX_VAL_LENGTH]; 
  int taille2 = 0 ; 


/* Line 189 of yacc.c  */
#line 90 "syntaxique.tab.c"

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
#line 18 "syntaxique.y"

  int     entier;
  char*   str;
  float reel; 



/* Line 214 of yacc.c  */
#line 180 "syntaxique.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 192 "syntaxique.tab.c"

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   262

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  218

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
       0,     0,     3,    10,    22,    23,    28,    33,    37,    39,
      41,    43,    44,    47,    50,    53,    54,    61,    66,    71,
      76,    80,    81,    86,    89,    93,    95,   103,   111,   114,
     115,   118,   121,   124,   127,   133,   137,   142,   149,   151,
     155,   158,   163,   166,   168,   170,   172,   175,   176,   178,
     180,   182,   184,   186,   188,   193,   198,   204,   209,   215,
     221,   225,   229,   231,   233,   239,   243,   247,   251,   253,
     257,   261,   263,   267,   269,   271,   273,   275,   279,   281,
     285,   287,   289,   291,   295,   297,   299,   305,   311,   315,
     319,   321,   323,   325,   327,   329,   331,   333,   335,   344,
     347,   348,   356,   360
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,     3,    32,    56,    64,     4,    -1,
      51,     5,    32,    44,    52,    45,    56,    64,    50,     6,
      49,    -1,    -1,    32,    36,    71,    41,    -1,    32,    36,
      35,    41,    -1,    32,    80,    41,    -1,    63,    -1,    10,
      -1,    53,    -1,    -1,    71,    54,    -1,    55,    53,    -1,
      42,    53,    -1,    -1,    32,    44,    33,    42,    33,    45,
      -1,    32,    44,    33,    45,    -1,    63,    57,    41,    56,
      -1,    10,    61,    41,    56,    -1,    58,    41,    56,    -1,
      -1,    32,    60,    42,    57,    -1,    32,    60,    -1,    32,
      42,    57,    -1,    32,    -1,    63,    32,    13,    44,    33,
      59,    45,    -1,    10,    32,    13,    44,    33,    59,    45,
      -1,    42,    33,    -1,    -1,    36,    33,    -1,    36,    34,
      -1,    36,     8,    -1,    36,     9,    -1,    32,    40,    33,
      42,    61,    -1,    32,    40,    33,    -1,    32,    40,    33,
      62,    -1,    32,    40,    33,    62,    42,    61,    -1,    32,
      -1,    32,    42,    61,    -1,    32,    62,    -1,    32,    62,
      42,    61,    -1,    36,    35,    -1,    12,    -1,    11,    -1,
       7,    -1,    64,    65,    -1,    -1,    66,    -1,    67,    -1,
      69,    -1,    83,    -1,    81,    -1,    85,    -1,    32,    36,
      71,    41,    -1,    32,    36,    35,    41,    -1,    32,    55,
      36,    71,    41,    -1,    32,    36,    80,    41,    -1,    15,
      44,    68,    45,    41,    -1,    14,    44,    32,    45,    41,
      -1,    35,    42,    68,    -1,    71,    42,    68,    -1,    35,
      -1,    71,    -1,    30,    70,    42,    70,    41,    -1,    44,
      53,    45,    -1,    71,    37,    72,    -1,    71,    38,    72,
      -1,    72,    -1,    72,    40,    73,    -1,    72,    39,    73,
      -1,    73,    -1,    44,    71,    45,    -1,    33,    -1,    34,
      -1,    55,    -1,    32,    -1,    74,    26,    75,    -1,    75,
      -1,    75,    27,    76,    -1,    76,    -1,    78,    -1,    77,
      -1,    78,    84,    78,    -1,    71,    -1,    80,    -1,    44,
      74,    26,    75,    45,    -1,    44,    75,    27,    76,    45,
      -1,    44,    77,    45,    -1,    44,    80,    45,    -1,    25,
      -1,    20,    -1,    23,    -1,    24,    -1,    21,    -1,    22,
      -1,     8,    -1,     9,    -1,    16,    44,    74,    45,    17,
      64,    82,    19,    -1,    18,    64,    -1,    -1,    28,    44,
      74,    45,    64,    29,    41,    -1,    43,    79,    43,    -1,
      32,    36,    31,    32,    44,    53,    45,    41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    28,    28,    30,    34,    36,    37,    38,    40,    40,
      42,    42,    44,    45,    47,    48,    51,    52,    56,    57,
      58,    59,    61,    62,    63,    64,    67,    68,    71,    72,
      74,    75,    76,    77,    79,    80,    81,    82,    83,    84,
      85,    86,    89,    91,    92,    93,    96,    97,    99,   100,
     101,   102,   103,   104,   107,   108,   109,   110,   113,   114,
     116,   116,   116,   116,   118,   120,   123,   124,   125,   128,
     129,   130,   133,   134,   135,   136,   137,   140,   141,   143,
     144,   146,   147,   150,   152,   153,   154,   155,   156,   157,
     159,   159,   159,   159,   159,   159,   161,   161,   165,   167,
     167,   169,   171,   174
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
  "par_ouvrante", "par_fermante", "points_sup", "$accept", "S",
  "Fonction_i", "Affectation_fonction", "type_fonc", "ARG",
  "liste_parametres", "SUITE_liste_parametres", "TAB_PAR", "DEC",
  "SUITE_DEC", "DEC_TAB", "LIST_PAR_TAB", "DEC_AFF", "DEC_CHAR",
  "DEC_CHAR_AFF", "type", "INSTRUCTIONS", "TYPE_INSTRUCTION",
  "Affectation", "Entre_Sortie_INST", "SORTIE_MESSAGE", "EQUIVALENCE_INST",
  "SUITE_EQUI", "EXPRESSION", "SUITE_EXPRESSION_1", "SUITE_EXPRESSION_2",
  "COND", "SUITE_COND_1", "SUITE_COND_2", "COND_SIMPLE", "EXPRESSION_BOOL",
  "SUITE_OPERATEUR_LOGIQUE_1", "LOGICAL_VALUE", "IF_INST", "SUITE_IF_INST",
  "BOUCLE_INST", "OPERATEUR_LOGIQUE_1", "INST_CALL", 0
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
       0,    47,    48,    49,    49,    50,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      56,    56,    57,    57,    57,    57,    58,    58,    59,    59,
      60,    60,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    63,    63,    63,    64,    64,    65,    65,
      65,    65,    65,    65,    66,    66,    66,    66,    67,    67,
      68,    68,    68,    68,    69,    70,    71,    71,    71,    72,
      72,    72,    73,    73,    73,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    78,    78,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    79,    80,    80,    81,    82,
      82,    83,    84,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,    11,     0,     4,     4,     3,     1,     1,
       1,     0,     2,     2,     2,     0,     6,     4,     4,     4,
       3,     0,     4,     2,     3,     1,     7,     7,     2,     0,
       2,     2,     2,     2,     5,     3,     4,     6,     1,     3,
       2,     4,     2,     1,     1,     1,     2,     0,     1,     1,
       1,     1,     1,     1,     4,     4,     5,     4,     5,     5,
       3,     3,     1,     1,     5,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     1,     1,     1,     3,     1,     3,
       1,     1,     1,     3,     1,     1,     5,     5,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     8,     2,
       0,     7,     3,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    45,     9,    44,    43,     0,     0,     0,     8,     1,
       0,     0,    21,     0,     0,    47,     0,     0,    11,    38,
       0,     0,    21,    25,     0,    76,    73,    74,     0,     0,
      10,    75,    15,    68,    71,     0,     0,     0,     0,    40,
      21,     2,     0,     0,     0,     0,     0,     0,    46,    48,
      49,    50,    52,    51,    53,    20,     0,     0,     0,    23,
      21,     0,    75,     0,    21,    13,     0,     0,     0,    12,
       0,     0,     0,    42,    35,    38,    39,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,    30,    31,    25,    24,     0,    18,     0,    72,    47,
      66,    67,    14,    70,    69,    29,     0,    36,    41,     0,
      62,     0,    63,    96,    97,     0,    84,     0,    78,    80,
      82,    81,    85,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    22,     0,    17,     0,     0,     0,    34,     0,
       0,     0,     0,     0,    84,     0,    78,    82,    85,     0,
       0,     0,     0,     0,    47,    65,     0,     0,    55,    54,
      57,     0,     0,     0,     0,     0,    28,    27,    37,    59,
      60,    58,    61,     0,     0,    88,    89,    77,    47,    79,
      91,    94,    95,    92,    93,    90,     0,    83,     0,    64,
       0,    56,    26,    16,     0,     0,     4,    77,    79,   100,
     102,     0,     0,     0,     0,     7,     3,    86,    87,    47,
       0,   101,     0,    55,    54,    99,    98,   103
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,   165,     7,    29,    30,    69,    62,    15,
      24,    16,   137,    59,    20,    39,    17,    21,    48,    49,
      50,   111,    51,    84,   116,    33,    34,   117,   118,   119,
     120,   121,   186,   122,    52,   210,    53,   153,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -133
static const yytype_int16 yypact[] =
{
     182,  -133,  -133,  -133,  -133,    13,    23,    40,  -133,  -133,
      29,    42,   188,    60,    46,  -133,    81,    80,    48,    -3,
      89,    93,   188,    -4,   103,   107,  -133,  -133,    48,   108,
    -133,    48,    97,    71,  -133,   112,   123,   130,   143,   139,
     188,  -133,   146,   147,   153,   162,   167,   -14,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,   169,    68,   178,   172,
     188,   183,  -133,    34,   188,  -133,    48,    48,    48,  -133,
      48,    48,   184,  -133,   -15,    63,  -133,   143,  -133,   186,
     135,    16,    16,    48,   173,   107,    56,   185,   187,  -133,
    -133,  -133,  -133,    26,  -133,   178,  -133,   -22,  -133,  -133,
      71,    71,  -133,  -133,  -133,   177,   143,   180,  -133,   179,
     181,   189,   134,  -133,  -133,    16,    58,     2,   198,  -133,
    -133,   190,  -133,    30,   191,   167,   194,   196,   164,   197,
      48,   177,  -133,   195,  -133,   127,   199,   200,  -133,   143,
     201,   135,   202,   135,    34,   203,   204,   205,   206,    16,
     210,    16,   163,    16,  -133,  -133,   207,   208,  -133,  -133,
    -133,   166,   209,   211,    21,   224,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,    16,    16,  -133,  -133,   198,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,   192,  -133,   117,  -133,
      48,  -133,  -133,  -133,    85,   212,   182,   -10,   213,   122,
    -133,   214,   215,   216,   171,  -133,  -133,  -133,  -133,  -133,
     220,  -133,   218,   234,   235,   150,  -133,  -133
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,    50,  -133,  -133,  -133,   -28,  -133,   -16,    -6,
     -52,  -133,   113,  -133,   -33,   175,     0,   -95,  -133,  -133,
    -133,   -57,  -133,   136,   -17,    61,    90,   -74,  -103,  -132,
     132,   109,  -133,   -79,  -133,  -133,  -133,  -133,  -133
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -7
static const yytype_int16 yytable[] =
{
       8,    32,    31,    65,   135,    76,    94,   129,   123,    56,
      35,    63,   146,     9,    32,    31,    55,   151,    85,   179,
     133,    36,    86,   134,   113,   114,    10,   106,   149,   113,
     114,    87,    57,    36,    78,   207,   148,    37,    58,    38,
     102,   145,   198,   132,   108,    11,   177,   150,    25,    26,
      27,    32,    31,    85,    96,   124,   149,   194,    99,   188,
     115,    12,    57,   112,   113,   114,    32,    31,    58,   128,
     197,    66,    67,   138,    13,   154,    89,    90,    19,    98,
      25,    26,    27,   199,   170,   195,   172,   126,    25,    26,
      27,   127,    28,   113,   114,    66,    67,    41,   144,    36,
      28,    91,    92,    37,    18,    38,   168,    42,    43,    44,
      70,    71,    23,   161,   215,   129,   126,    25,    26,    27,
     203,    45,    22,    46,   112,    47,   112,   100,   101,    28,
      40,    42,    43,    44,    66,    67,    42,    43,    44,    68,
     209,    42,    43,    44,    60,    45,   201,    46,    87,    47,
      45,    61,    46,    64,    47,    45,    72,    46,    73,   164,
     103,   104,   202,    74,    42,    43,    44,    25,    26,    27,
     110,    66,    67,    32,    31,    75,   143,   204,    45,    28,
      46,    77,    47,   180,   181,   182,   183,   184,   185,     1,
      79,    80,     2,     3,     4,     1,     8,    81,    14,     3,
       4,    66,    67,    66,    67,   159,    82,   191,    66,    67,
      93,    83,   214,    88,    95,   125,    97,   105,   109,   136,
     131,   130,   139,   141,   140,   151,   157,   178,   163,   173,
     196,   174,   166,   152,   142,   200,   155,   158,   160,   216,
      -6,    -5,   169,   171,   162,   167,   206,   147,   189,   107,
     175,   176,   190,   205,   192,   211,   193,   213,   208,   217,
     212,   156,   187
};

static const yytype_uint8 yycheck[] =
{
       0,    18,    18,    31,    99,    38,    58,    86,    82,    13,
      13,    28,   115,     0,    31,    31,    22,    27,    32,   151,
      42,    36,    36,    45,     8,     9,     3,    42,    26,     8,
       9,    47,    36,    36,    40,    45,   115,    40,    42,    42,
      68,   115,   174,    95,    77,     5,   149,    45,    32,    33,
      34,    68,    68,    32,    60,    83,    26,    36,    64,   154,
      44,    32,    36,    80,     8,     9,    83,    83,    42,    86,
     173,    37,    38,   106,    32,    45,     8,     9,    32,    45,
      32,    33,    34,   178,   141,   164,   143,    31,    32,    33,
      34,    35,    44,     8,     9,    37,    38,     4,   115,    36,
      44,    33,    34,    40,    44,    42,   139,    14,    15,    16,
      39,    40,    32,   130,   209,   194,    31,    32,    33,    34,
      35,    28,    41,    30,   141,    32,   143,    66,    67,    44,
      41,    14,    15,    16,    37,    38,    14,    15,    16,    42,
      18,    14,    15,    16,    41,    28,    29,    30,   164,    32,
      28,    44,    30,    45,    32,    28,    44,    30,    35,    32,
      70,    71,   190,    33,    14,    15,    16,    32,    33,    34,
      35,    37,    38,   190,   190,    32,    42,   194,    28,    44,
      30,    42,    32,    20,    21,    22,    23,    24,    25,     7,
      44,    44,    10,    11,    12,     7,   196,    44,    10,    11,
      12,    37,    38,    37,    38,    41,    44,    41,    37,    38,
      32,    44,    41,    44,    42,    42,    33,    33,    32,    42,
      33,    36,    42,    42,    45,    27,    32,    17,    33,    26,
       6,    27,    33,    43,    45,    43,    45,    41,    41,    19,
       6,     6,    41,    41,   131,    45,   196,   115,    41,    74,
      45,    45,    44,    41,    45,    41,    45,    41,    45,    41,
      45,   125,   153
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    10,    11,    12,    48,    49,    51,    63,     0,
       3,     5,    32,    32,    10,    56,    58,    63,    44,    32,
      61,    64,    41,    32,    57,    32,    33,    34,    44,    52,
      53,    55,    71,    72,    73,    13,    36,    40,    42,    62,
      41,     4,    14,    15,    16,    28,    30,    32,    65,    66,
      67,    69,    81,    83,    85,    56,    13,    36,    42,    60,
      41,    44,    55,    71,    45,    53,    37,    38,    42,    54,
      39,    40,    44,    35,    33,    32,    61,    42,    56,    44,
      44,    44,    44,    44,    70,    32,    36,    55,    44,     8,
       9,    33,    34,    32,    57,    42,    56,    33,    45,    56,
      72,    72,    53,    73,    73,    33,    42,    62,    61,    32,
      35,    68,    71,     8,     9,    44,    71,    74,    75,    76,
      77,    78,    80,    74,    53,    42,    31,    35,    71,    80,
      36,    33,    57,    42,    45,    64,    42,    59,    61,    42,
      45,    42,    45,    42,    71,    74,    75,    77,    80,    26,
      45,    27,    43,    84,    45,    45,    70,    32,    41,    41,
      41,    71,    59,    33,    32,    50,    33,    45,    61,    41,
      68,    41,    68,    26,    27,    45,    45,    75,    17,    76,
      20,    21,    22,    23,    24,    25,    79,    78,    64,    41,
      44,    41,    45,    45,    36,    80,     6,    75,    76,    64,
      43,    29,    53,    35,    71,    41,    49,    45,    45,    18,
      82,    41,    45,    41,    41,    64,    19,    41
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
#line 31 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(3) - (11)].str),top(stack_type));pop(stack_type);add_CODE_Cst_Idf((yyvsp[(3) - (11)].str),"ROUTINE");
                          if(strcmp(top(stack_name_Routine),(yyvsp[(3) - (11)].str))!=0) yyerrorSemantique("Error: the last line of ROUTINE should be affectation with name of ROUTINE") ;
                          pop(stack_name_Routine);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 36 "syntaxique.y"
    {push(stack_name_Routine,(yyvsp[(1) - (4)].str));}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 37 "syntaxique.y"
    {push(stack_name_Routine,(yyvsp[(1) - (4)].str));}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 38 "syntaxique.y"
    {push(stack_name_Routine,(yyvsp[(1) - (3)].str));}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 40 "syntaxique.y"
    {push(stack_type, "CHARACTER")  ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 56 "syntaxique.y"
    {pop(stack_type);}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 61 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_type)); add_VALUE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_value));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(1) - (4)].str),"variable");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 62 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(1) - (2)].str),top(stack_type)); add_VALUE_Cst_Idf((yyvsp[(1) - (2)].str),top(stack_value));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(1) - (2)].str),"variable");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 63 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(1) - (3)].str),top(stack_type));add_CODE_Cst_Idf((yyvsp[(1) - (3)].str),"variable");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 64 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(1) - (1)].str),top(stack_type));add_CODE_Cst_Idf((yyvsp[(1) - (1)].str),"variable");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 67 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(2) - (7)].str),top(stack_type));ConcatTaille((yyvsp[(5) - (7)].entier),taille2,Taille,sizeof(Taille));add_VALUE_Cst_Idf((yyvsp[(2) - (7)].str),Taille) ;taille2= 0;add_CODE_Cst_Idf((yyvsp[(2) - (7)].str),code);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 68 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(2) - (7)].str),"CHARACTER");ConcatTaille((yyvsp[(5) - (7)].entier),taille2,Taille,sizeof(Taille));add_VALUE_Cst_Idf((yyvsp[(2) - (7)].str),Taille) ;taille2= 0;add_CODE_Cst_Idf((yyvsp[(2) - (7)].str),code);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 71 "syntaxique.y"
    {taille2 = (yyvsp[(2) - (2)].entier); strcpy(code,"matrice");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 72 "syntaxique.y"
    {strcpy(code,"tableau");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 74 "syntaxique.y"
    {push(stack_value, intToString((yyvsp[(2) - (2)].entier))) ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 75 "syntaxique.y"
    {push(stack_value, floatToString((yyvsp[(2) - (2)].reel)))  ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 76 "syntaxique.y"
    {push(stack_value, (yyvsp[(2) - (2)].str))  ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 77 "syntaxique.y"
    {push(stack_value, (yyvsp[(2) - (2)].str))  ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 79 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(1) - (5)].str), "CHARACTER");add_CODE_Cst_Idf((yyvsp[(1) - (5)].str),"variable");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 80 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(1) - (3)].str), "CHARACTER");add_CODE_Cst_Idf((yyvsp[(1) - (3)].str),"variable");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 81 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(1) - (4)].str), "CHARACTER"); add_VALUE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_value));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(1) - (4)].str),"variable");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 82 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(1) - (6)].str), "CHARACTER"); add_VALUE_Cst_Idf((yyvsp[(1) - (6)].str),top(stack_value));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(1) - (6)].str),"variable");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 83 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(1) - (1)].str), "CHARACTER");add_CODE_Cst_Idf((yyvsp[(1) - (1)].str),"variable");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 84 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(1) - (3)].str), "CHARACTER");add_CODE_Cst_Idf((yyvsp[(1) - (3)].str),"variable");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 85 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(1) - (2)].str), "CHARACTER"); add_VALUE_Cst_Idf((yyvsp[(1) - (2)].str),top(stack_value));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(1) - (2)].str),"variable");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 86 "syntaxique.y"
    {add_TYPE_Cst_Idf((yyvsp[(1) - (4)].str), "CHARACTER"); add_VALUE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_value));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(1) - (4)].str),"variable");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 89 "syntaxique.y"
    {push(stack_value,(yyvsp[(2) - (2)].str));}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 91 "syntaxique.y"
    {push(stack_type, "INTEGER");}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 92 "syntaxique.y"
    {push(stack_type, "REAL");}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 93 "syntaxique.y"
    {push(stack_type, "LOGICAL");}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 107 "syntaxique.y"
    {if(!idf_exist((yyvsp[(1) - (4)].str)) || strcmp(return_CODE_Cst_Idf((yyvsp[(1) - (4)].str)),"ROUTINE")==0) yyerrorSemantique("affectation a une variable non declare ou afftectation a une fonction\n");}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 108 "syntaxique.y"
    {if(!idf_exist((yyvsp[(1) - (4)].str)) || strcmp(return_CODE_Cst_Idf((yyvsp[(1) - (4)].str)),"ROUTINE")==0)yyerrorSemantique("affectation a une variable non declare ou afftectation a une fonction\n");}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 109 "syntaxique.y"
    {if(!idf_exist((yyvsp[(1) - (5)].str)) || strcmp(return_CODE_Cst_Idf((yyvsp[(1) - (5)].str)),"ROUTINE")==0)yyerrorSemantique("affectation a une variable non declare ou afftectation a une fonction\n");}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 110 "syntaxique.y"
    {if(!idf_exist((yyvsp[(1) - (4)].str)) || strcmp(return_CODE_Cst_Idf((yyvsp[(1) - (4)].str)),"ROUTINE")==0)yyerrorSemantique("affectation a une variable non declare ou afftectation a une fonction\n");}
    break;



/* Line 1455 of yacc.c  */
#line 1830 "syntaxique.tab.c"
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
#line 176 "syntaxique.y"



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
              stack_value = initializeStack();
              stack_name_Routine = initializeStack();
            yyrestart(fileLex);

              //initialisation
               initList_Cst_Idf();
               initList_Sep_MotCle();
              yyparse(); 
              printf("syntaxe correcte \n");
              displayList_Sep_MotCle();
              displayList_Cst_Idf();
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
      exit(EXIT_FAILURE); 
}
 int yyerrorSemantique ( char*  msg )  
{
      printf("%s",msg);
      printf("\nFile %s, line %d, character %d: semantic error\n",fileName ,nb_ligne, Col);
      displayList_Sep_MotCle();
      displayList_Cst_Idf();
      exit(EXIT_FAILURE); 
}


