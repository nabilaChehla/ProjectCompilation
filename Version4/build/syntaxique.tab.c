
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
#line 2 "../src/syntaxique.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/modules/quad.c"
#include "../src/semantique.c"


 extern  nb_ligne;
 extern Col;
 int qc=0;
 int qc_cond = 0 ; 
 extern char fileName[50];
Stack *stack_type;
Stack *stack_value;
Stack *stack_name_Routine ; 
Stack *stack_variable ; 
Stack *stack_BZ;
Stack *stack_deb_cond;
Stack *stack_Qc_Cond;
Stack *stack_Qc_SOUS_Cond; 

  char code [MAX_CODE_LENGTH];
  char save_type_operateur [MAX_TYPE_LENGTH];
  char op1 [MAX_STRING_SIZE];
  char op2 [MAX_STRING_SIZE];
  char strg[MAX_STRING_SIZE];
  char strg2[MAX_STRING_SIZE];    
  char TAB_reference[MAX_STRING_SIZE];
  char Type_routine[MAX_TYPE_LENGTH];
  char temp[10];
  char value_op[MAX_STRING_SIZE];
  char taille2[MAX_STRING_SIZE];
  char taille1[MAX_STRING_SIZE]; 
  char firstSize[MAX_STRING_SIZE];
  char secondSize[MAX_STRING_SIZE];
  int nbArg = 0 ; 
  int cmpt= 0;
  bool isIDF1=false;
  bool isIDF2=false;
  int cmpt_TAB=0;
  int nbArg_Write=0 ; 
  int nbArg_Eqv =0 ; 
  int sauv_BR,Fin_inst_cond,tab_dec;
  bool divZero = false ;


/* Line 189 of yacc.c  */
#line 121 "syntaxique.tab.c"

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
#line 49 "../src/syntaxique.y"

  int     entier;
  char*   str;
  float reel; 



/* Line 214 of yacc.c  */
#line 211 "syntaxique.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 223 "syntaxique.tab.c"

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
#define YYLAST   267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNRULES -- Number of states.  */
#define YYNSTATES  253

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
     263,   267,   269,   273,   277,   281,   283,   285,   287,   291,
     295,   297,   301,   305,   308,   310,   312,   316,   318,   320,
     322,   324,   326,   328,   335,   340,   342,   345,   348,   351,
     353,   356,   358,   360,   362,   368,   374,   380,   386,   392,
     398,   400,   402,   406,   410,   412,   414,   418,   422,   426,
     432,   436,   441,   443,   452,   454,   455,   459,   461,   463,
     465
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    50,    49,    57,    65,     4,    -1,     3,
      32,    -1,    51,    50,    -1,    -1,    52,    44,    55,    45,
      57,    65,    53,     6,    -1,    54,     5,    32,    -1,    32,
      36,    75,    41,    -1,    32,    36,    35,    41,    -1,    32,
      36,    90,    41,    -1,    64,    -1,    10,    -1,    56,    -1,
      -1,    32,    42,    56,    -1,    32,    44,    33,    42,    33,
      45,    42,    56,    -1,    32,    44,    33,    45,    42,    56,
      -1,    32,    -1,    32,    44,    33,    42,    33,    45,    -1,
      32,    44,    33,    45,    -1,    64,    58,    41,    57,    -1,
      10,    62,    41,    57,    -1,    59,    41,    57,    -1,    -1,
      32,    61,    42,    58,    -1,    32,    61,    -1,    32,    42,
      58,    -1,    32,    -1,    64,    32,    13,    44,    80,    60,
      45,    -1,    10,    32,    13,    44,    80,    60,    45,    -1,
      42,    80,    -1,    -1,    36,    33,    -1,    36,    34,    -1,
      36,     8,    -1,    36,     9,    -1,    62,    42,    32,    40,
      33,    -1,    32,    40,    33,    -1,    32,    40,    33,    63,
      -1,    62,    42,    32,    40,    33,    63,    -1,    32,    -1,
      62,    42,    32,    -1,    32,    63,    -1,    62,    42,    32,
      63,    -1,    36,    35,    -1,    12,    -1,    11,    -1,     7,
      -1,    65,    66,    -1,    -1,    67,    -1,    68,    -1,    71,
      -1,    94,    -1,    91,    -1,    97,    -1,    32,    36,    75,
      41,    -1,    32,    36,    35,    41,    -1,    81,    36,    75,
      41,    -1,    32,    36,    90,    41,    -1,    15,    44,    69,
      45,    41,    -1,    14,    44,    32,    45,    41,    -1,    14,
      44,    81,    45,    41,    -1,    69,    42,   100,    -1,    69,
      42,    75,    -1,   100,    -1,    75,    -1,    35,    -1,    30,
      72,    41,    -1,    72,    42,    73,    -1,    73,    -1,    44,
      74,    45,    -1,    74,    42,    32,    -1,    74,    42,    81,
      -1,    32,    -1,    81,    -1,    76,    -1,    76,    37,    77,
      -1,    76,    38,    77,    -1,    77,    -1,    77,    40,    79,
      -1,    77,    39,    78,    -1,    38,    79,    -1,    79,    -1,
      79,    -1,    44,    76,    45,    -1,    33,    -1,    34,    -1,
      81,    -1,    32,    -1,    33,    -1,    32,    -1,    32,    44,
      80,    42,    80,    45,    -1,    32,    44,    80,    45,    -1,
      85,    -1,    85,    26,    -1,    86,    27,    -1,    83,    86,
      -1,    86,    -1,    84,    87,    -1,    87,    -1,    89,    -1,
      88,    -1,    89,    43,    25,    43,    89,    -1,    89,    43,
      20,    43,    89,    -1,    89,    43,    23,    43,    89,    -1,
      89,    43,    24,    43,    89,    -1,    89,    43,    21,    43,
      89,    -1,    89,    43,    22,    43,    89,    -1,    75,    -1,
      90,    -1,    44,    88,    45,    -1,    44,    90,    45,    -1,
       8,    -1,     9,    -1,    92,    65,    19,    -1,    93,    65,
      19,    -1,    93,    65,    18,    -1,    16,    44,    82,    45,
      17,    -1,    95,    65,    29,    -1,    96,    44,    82,    45,
      -1,    28,    -1,    32,    36,    31,    32,    44,    98,    45,
      41,    -1,    99,    -1,    -1,    99,    42,    75,    -1,    75,
      -1,   101,    -1,   102,    -1,    70,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    61,    63,    65,    67,    70,    72,    73,
      79,    89,    89,    91,    92,    94,    95,    96,    97,    98,
      99,   102,   103,   104,   105,   107,   108,   109,   110,   113,
     133,   154,   157,   159,   160,   161,   162,   164,   165,   166,
     167,   168,   169,   170,   171,   174,   176,   177,   178,   181,
     182,   184,   185,   186,   187,   188,   189,   192,   202,   210,
     220,   231,   232,   239,   247,   248,   249,   250,   252,   254,
     256,   257,   259,   261,   262,   263,   264,   266,   268,   269,
     270,   273,   274,   275,   276,   278,   280,   281,   288,   295,
     296,   308,   308,   311,   352,   381,   383,   385,   389,   390,
     392,   393,   395,   396,   398,   399,   400,   401,   402,   403,
     405,   406,   407,   408,   410,   410,   412,   416,   421,   427,
     436,   442,   446,   449,   459,   460,   462,   463,   466,   468,
     470
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
  "SUITE_EXPRESSION_1", "suiteDiv", "SUITE_EXPRESSION_2", "bound_tab",
  "TAB_PAR", "CONDITION", "COND_OR", "COND_AND", "COND", "SUITE_COND_1",
  "SUITE_COND_2", "COND_SIMPLE", "EXPRESSION_BOOL", "LOGICAL_VALUE",
  "IF_INST", "DEBUT_INST_IF", "DEBUT_IF", "BOUCLE_INST", "BOUCLE_INST1",
  "BOUCLE_INST2", "INST_CALL", "ARG_CALL", "liste_parametres_CALL",
  "char_niv1", "char_niv2", "char_niv3", 0
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
      72,    72,    73,    74,    74,    74,    74,    75,    76,    76,
      76,    77,    77,    77,    77,    78,    79,    79,    79,    79,
      79,    80,    80,    81,    81,    82,    83,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    88,    88,    88,    88,
      89,    89,    89,    89,    90,    90,    91,    91,    92,    93,
      94,    95,    96,    97,    98,    98,    99,    99,   100,   101,
     102
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
       3,     1,     3,     3,     3,     1,     1,     1,     3,     3,
       1,     3,     3,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     6,     4,     1,     2,     2,     2,     1,
       2,     1,     1,     1,     5,     5,     5,     5,     5,     5,
       1,     1,     3,     3,     1,     1,     3,     3,     3,     5,
       3,     4,     1,     8,     1,     0,     3,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    48,    12,    47,    46,     0,     0,     5,     0,     0,
      11,     1,     0,    24,     4,    14,     0,     3,     0,    50,
       0,     0,    18,     0,    13,     7,    41,     0,     0,    24,
      28,     0,     0,     0,    24,     0,     0,     0,    43,    24,
       0,     2,     0,     0,     0,   122,     0,     0,    49,    51,
      52,    53,     0,    55,    50,    50,    54,    50,     0,    56,
      23,     0,     0,     0,    26,    24,    15,     0,    50,     0,
      45,    38,    22,    42,     0,     0,     0,     0,     0,    71,
       0,     0,     0,     0,     0,     0,     0,     0,    35,    36,
      33,    34,    28,    27,     0,    21,     0,    20,     0,    92,
      91,    32,    39,     0,    44,     0,     0,    90,    87,    88,
      68,     0,     0,     0,   130,    67,    77,    80,    84,    89,
      66,   128,   129,   114,   115,     0,   110,     0,     0,     0,
      95,    99,   101,   103,   102,   111,    75,     0,    76,    69,
       0,     0,     0,     0,     0,     0,     0,   116,   118,   117,
     120,     0,    32,    25,     0,     0,     0,     0,     0,     0,
      37,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,   111,     0,    98,   100,    96,    97,
       0,     0,    72,    70,     0,    58,    57,    60,     0,    94,
      59,   121,     0,    19,    17,     0,     6,    31,    30,    40,
      62,    63,    86,    65,    64,    61,    78,    79,    82,    85,
      81,   112,   113,   119,     0,     0,     0,     0,     0,     0,
      73,    74,   125,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,   124,    93,    16,
      58,    57,    60,   105,   108,   109,   106,   107,   104,     0,
       0,   123,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    13,     6,     7,     8,   157,     9,    23,    24,
      19,    31,    20,   159,    64,    27,    38,    21,    28,    48,
      49,    50,   113,   114,    51,    78,    79,   137,   126,   116,
     117,   208,   118,   101,   119,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    53,    54,    55,    56,    57,    58,
      59,   236,   237,   120,   121,   122
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -123
static const yytype_int16 yypact[] =
{
     176,  -123,  -123,  -123,  -123,    40,    67,   176,   -15,    58,
    -123,  -123,    42,   184,  -123,    57,    64,  -123,    71,  -123,
      79,    90,    60,    83,  -123,  -123,    26,   104,    69,   184,
      29,    91,    57,   106,   184,    97,   115,   126,  -123,   184,
     133,  -123,   146,   164,   165,  -123,   166,    51,  -123,  -123,
    -123,  -123,   135,  -123,  -123,  -123,  -123,  -123,   167,  -123,
    -123,   168,    72,   169,   171,   184,  -123,   -20,  -123,   142,
    -123,   170,  -123,    24,   175,   129,    12,   182,   143,  -123,
       3,   142,    92,   119,    99,   128,    12,   142,  -123,  -123,
    -123,  -123,    25,  -123,   169,  -123,   183,   173,   138,  -123,
    -123,   177,  -123,   185,  -123,   153,   172,   178,  -123,  -123,
    -123,    -1,    92,    95,  -123,  -123,   162,   163,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,    12,  -123,   179,    12,    12,
     194,   196,  -123,  -123,   186,  -123,   178,   127,  -123,  -123,
     166,   189,   187,   190,   191,   147,   192,  -123,  -123,  -123,
    -123,   180,   177,  -123,   181,    57,    54,   221,   142,   193,
     170,   195,   198,  -123,    55,   129,   199,    92,    92,    -1,
      -1,    55,   197,   186,   200,   213,   196,  -123,  -123,  -123,
     157,   202,  -123,  -123,   203,  -123,  -123,  -123,   142,  -123,
    -123,  -123,   201,   206,  -123,    44,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,   163,   163,  -123,  -123,
    -123,  -123,  -123,  -123,   207,   208,   209,   210,   211,   212,
     178,  -123,    92,   204,  -123,    57,   215,   216,   217,    12,
      12,    12,    12,    12,    12,  -123,   214,   218,  -123,  -123,
     229,   231,   235,  -123,  -123,  -123,  -123,  -123,  -123,   220,
      92,  -123,  -123
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,   236,  -123,  -123,  -123,  -123,  -123,   -32,
     -11,   -39,  -123,   110,  -123,  -123,   -66,    19,   -41,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,   123,  -123,   -74,   -95,
      37,  -123,  -101,   -72,   -26,   158,  -123,  -123,  -123,   136,
     137,   140,  -122,   -76,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,   102,  -123,  -123
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -11
static const yytype_int16 yytable[] =
{
      66,   115,    52,   173,   144,   102,   143,   104,   146,   145,
     163,   123,   124,    83,    84,   152,    85,   164,    60,    10,
     123,   124,    96,    68,    93,    97,    10,    98,    72,    15,
     171,   107,   108,   109,   141,   107,   108,   109,   142,    35,
      11,   111,    61,   112,   107,   108,   109,   112,   106,   174,
     111,   138,   123,   124,    95,   153,   125,    52,    52,    52,
      36,    62,    36,    16,   103,    62,    37,    63,   209,   210,
      12,    63,    52,    41,    17,   141,   107,   108,   109,   226,
      88,    89,   111,    42,    43,    44,   197,    80,   112,    22,
     195,   203,   167,   168,   199,    81,    25,    45,    81,    46,
     202,    47,    32,    26,    33,    90,    91,   243,   244,   245,
     246,   247,   248,    42,    43,    44,   223,   148,   149,   228,
      29,   227,    30,   194,   107,   108,   109,    45,    34,    46,
     111,    47,    65,    42,    43,    44,   112,   165,   147,    67,
     166,    69,    42,    43,    44,    39,    40,    45,   235,    46,
      70,    47,    42,    43,    44,   221,    45,   150,    46,    71,
      47,   107,   108,   109,   110,    73,    45,   111,    46,   181,
     156,    82,   182,   112,    99,   100,   252,   214,   215,   216,
     217,   218,   219,     1,   139,   140,     2,     3,     4,   188,
      74,     1,   189,   239,    18,     3,     4,    81,   161,   167,
     168,    92,   169,   170,   206,   207,    36,   105,    75,    76,
      77,    86,    87,    94,   136,   155,   154,   162,   160,   158,
     178,   184,    81,   179,   175,   191,   193,   196,   185,   180,
     213,   186,   187,   190,   220,    -9,   200,    -8,   198,   201,
     205,   -10,   211,    14,   151,   212,   224,   222,   225,   238,
     229,   230,   231,   232,   233,   234,   240,   241,   242,   249,
     250,   251,   192,   183,   176,   172,   177,   204
};

static const yytype_uint8 yycheck[] =
{
      32,    75,    28,   125,    80,    71,    80,    73,    82,    81,
     111,     8,     9,    54,    55,    87,    57,   112,    29,     0,
       8,     9,    42,    34,    63,    45,     7,    68,    39,    44,
     125,    32,    33,    34,    31,    32,    33,    34,    35,    13,
       0,    38,    13,    44,    32,    33,    34,    44,    74,   125,
      38,    77,     8,     9,    65,    94,    44,    83,    84,    85,
      36,    36,    36,     5,    40,    36,    40,    42,   169,   170,
       3,    42,    98,     4,    32,    31,    32,    33,    34,    35,
       8,     9,    38,    14,    15,    16,   158,    36,    44,    32,
      36,   165,    37,    38,   160,    44,    32,    28,    44,    30,
      45,    32,    42,    32,    44,    33,    34,   229,   230,   231,
     232,   233,   234,    14,    15,    16,   188,    18,    19,   195,
      41,   195,    32,   155,    32,    33,    34,    28,    45,    30,
      38,    32,    41,    14,    15,    16,    44,    42,    19,    33,
      45,    44,    14,    15,    16,    41,    42,    28,   222,    30,
      35,    32,    14,    15,    16,   181,    28,    29,    30,    33,
      32,    32,    33,    34,    35,    32,    28,    38,    30,    42,
      32,    36,    45,    44,    32,    33,   250,    20,    21,    22,
      23,    24,    25,     7,    41,    42,    10,    11,    12,    42,
      44,     7,    45,   225,    10,    11,    12,    44,    45,    37,
      38,    32,    39,    40,   167,   168,    36,    32,    44,    44,
      44,    44,    44,    42,    32,    42,    33,    45,    33,    42,
      26,    32,    44,    27,    45,    45,    45,     6,    41,    43,
      17,    41,    41,    41,    32,     6,    41,     6,    45,    41,
      41,     6,    45,     7,    86,    45,    45,    44,    42,    45,
      43,    43,    43,    43,    43,    43,    41,    41,    41,    45,
      42,    41,   152,   140,   128,   125,   129,   165
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    10,    11,    12,    48,    50,    51,    52,    54,
      64,     0,     3,    49,    50,    44,     5,    32,    10,    57,
      59,    64,    32,    55,    56,    32,    32,    62,    65,    41,
      32,    58,    42,    44,    45,    13,    36,    40,    63,    41,
      42,     4,    14,    15,    16,    28,    30,    32,    66,    67,
      68,    71,    81,    91,    92,    93,    94,    95,    96,    97,
      57,    13,    36,    42,    61,    41,    56,    33,    57,    44,
      35,    33,    57,    32,    44,    44,    44,    44,    72,    73,
      36,    44,    36,    65,    65,    65,    44,    44,     8,     9,
      33,    34,    32,    58,    42,    57,    42,    45,    65,    32,
      33,    80,    63,    40,    63,    32,    81,    32,    33,    34,
      35,    38,    44,    69,    70,    75,    76,    77,    79,    81,
     100,   101,   102,     8,     9,    44,    75,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    32,    74,    81,    41,
      42,    31,    35,    75,    90,    80,    75,    19,    18,    19,
      29,    82,    80,    58,    33,    42,    32,    53,    42,    60,
      33,    45,    45,    79,    76,    42,    45,    37,    38,    39,
      40,    76,    88,    89,    90,    45,    86,    87,    26,    27,
      43,    42,    45,    73,    32,    41,    41,    41,    42,    45,
      41,    45,    60,    45,    56,    36,     6,    80,    45,    63,
      41,    41,    45,    75,   100,    41,    77,    77,    78,    79,
      79,    45,    45,    17,    20,    21,    22,    23,    24,    25,
      32,    81,    44,    80,    45,    42,    35,    75,    90,    43,
      43,    43,    43,    43,    43,    75,    98,    99,    45,    56,
      41,    41,    41,    89,    89,    89,    89,    89,    89,    45,
      42,    41,    75
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
#line 61 "../src/syntaxique.y"
    {push(stack_name_Routine,"main");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 64 "../src/syntaxique.y"
    { traitement_Fin_Routine(stack_name_Routine,stack_value,stack_type);  nbArg = 0;;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 67 "../src/syntaxique.y"
    { check_Affectation_fin_Routine(stack_type,save_type_operateur,&cmpt);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 70 "../src/syntaxique.y"
    {push(stack_name_Routine,(yyvsp[(3) - (3)].str));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 72 "../src/syntaxique.y"
    {Check_Retour_Routine((yyvsp[(1) - (4)].str), stack_name_Routine);strcpy(strg,top(stack_variable));quadr(":=",strg,"vide",(yyvsp[(1) - (4)].str));pop(stack_variable);quadr("return",(yyvsp[(1) - (4)].str),"vide","vide");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 73 "../src/syntaxique.y"
    {Check_Retour_Routine((yyvsp[(1) - (4)].str), stack_name_Routine);
                                             strcpy(save_type_operateur,"CHARACTER");
                                             cmpt=cmpt+2;
                                             quadr(":=",(yyvsp[(3) - (4)].str),"vide",(yyvsp[(1) - (4)].str));
                                             quadr("return",(yyvsp[(1) - (4)].str),"vide","vide");
                                            ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 79 "../src/syntaxique.y"
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
#line 89 "../src/syntaxique.y"
    {push(stack_type, "CHARACTER")  ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 91 "../src/syntaxique.y"
    {push(stack_value,intToString(nbArg));quadParametre(stack_variable,nbArg);nbArg=0; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 92 "../src/syntaxique.y"
    {push(stack_value,"0"); nbArg=0;;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 94 "../src/syntaxique.y"
    {add_SCOPE_Cst_Idf((yyvsp[(1) - (3)].str),top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (3)].str),"VARIABLE",top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (3)].str),"-",top(stack_name_Routine));nbArg++;push(stack_variable,(yyvsp[(1) - (3)].str));initVar((yyvsp[(1) - (3)].str),stack_name_Routine);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 95 "../src/syntaxique.y"
    {add_SCOPE_Cst_Idf((yyvsp[(1) - (8)].str),top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (8)].str),"MATRICE",top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (8)].str),"-",top(stack_name_Routine));add_Taille_Tab_Mat((yyvsp[(1) - (8)].str),intToString((yyvsp[(3) - (8)].entier)),intToString((yyvsp[(5) - (8)].entier)),stack_name_Routine);nbArg++;Tab_idfInStack_Quad(stack_variable,(yyvsp[(1) - (8)].str),intToString((yyvsp[(3) - (8)].entier)),intToString((yyvsp[(5) - (8)].entier)));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 96 "../src/syntaxique.y"
    {add_SCOPE_Cst_Idf((yyvsp[(1) - (6)].str),top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (6)].str),"TABLEAU",top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (6)].str),"-",top(stack_name_Routine));add_Taille_Tab_Mat((yyvsp[(1) - (6)].str),intToString((yyvsp[(3) - (6)].entier)),"0",stack_name_Routine);nbArg++;Tab_idfInStack_Quad(stack_variable,(yyvsp[(1) - (6)].str),intToString((yyvsp[(3) - (6)].entier)),"-1");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 97 "../src/syntaxique.y"
    {add_SCOPE_Cst_Idf((yyvsp[(1) - (1)].str),top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (1)].str),"VARIABLE",top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (1)].str),"-",top(stack_name_Routine));nbArg++;push(stack_variable,(yyvsp[(1) - (1)].str));initVar((yyvsp[(1) - (1)].str),stack_name_Routine);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 98 "../src/syntaxique.y"
    {add_SCOPE_Cst_Idf((yyvsp[(1) - (6)].str),top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (6)].str),"MATRICE",top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (6)].str),"-",top(stack_name_Routine));add_Taille_Tab_Mat((yyvsp[(1) - (6)].str),intToString((yyvsp[(3) - (6)].entier)),intToString((yyvsp[(5) - (6)].entier)),stack_name_Routine);nbArg++;Tab_idfInStack_Quad(stack_variable,(yyvsp[(1) - (6)].str),intToString((yyvsp[(3) - (6)].entier)),intToString((yyvsp[(5) - (6)].entier)));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 99 "../src/syntaxique.y"
    {add_SCOPE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (4)].str),"TABLEAU",top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (4)].str),"-",top(stack_name_Routine));add_Taille_Tab_Mat((yyvsp[(1) - (4)].str),intToString((yyvsp[(3) - (4)].entier)),"0",stack_name_Routine);nbArg++;Tab_idfInStack_Quad(stack_variable,(yyvsp[(1) - (4)].str),intToString((yyvsp[(3) - (4)].entier)),"-1");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 102 "../src/syntaxique.y"
    {pop(stack_type);}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 107 "../src/syntaxique.y"
    {Taitement_SUITE_DEC((yyvsp[(1) - (4)].str),stack_name_Routine,stack_type); add_VALUE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_value),top(stack_name_Routine)); pop(stack_value);strcpy(strg,top(stack_variable));quadr(":=",strg,"vide",(yyvsp[(1) - (4)].str));pop(stack_variable);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 108 "../src/syntaxique.y"
    {Taitement_SUITE_DEC((yyvsp[(1) - (2)].str),stack_name_Routine,stack_type); add_VALUE_Cst_Idf((yyvsp[(1) - (2)].str),top(stack_value),top(stack_name_Routine)); pop(stack_value);strcpy(strg,top(stack_variable));quadr(":=",strg,"vide",(yyvsp[(1) - (2)].str));pop(stack_variable);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 109 "../src/syntaxique.y"
    {Taitement_SUITE_DEC((yyvsp[(1) - (3)].str),stack_name_Routine,stack_type);}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 110 "../src/syntaxique.y"
    {Taitement_SUITE_DEC((yyvsp[(1) - (1)].str),stack_name_Routine,stack_type);}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 113 "../src/syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(2) - (7)].str),stack_name_Routine);                                                                                    
                                                                                    add_SCOPE_Cst_Idf((yyvsp[(2) - (7)].str),top(stack_name_Routine));
                                                                                    add_TYPE_Cst_Idf((yyvsp[(2) - (7)].str),top(stack_type),top(stack_name_Routine));
                                                                                    add_CODE_Cst_Idf((yyvsp[(2) - (7)].str),code,top(stack_name_Routine));
                                                                                    strcpy(taille1,top(stack_variable));
                                                                                    quadr("BOUNDS","0",taille1,"vide");
                                                                                    if(strcmp(code,"MATRICE")==0)quadr("BOUNDS","0",taille2,"vide");
                                                                                    if(isIDF1){if(strcmp(return_TYPE_Cst_Idf(taille1,top(stack_name_Routine)),"INTEGER")!=0)semantiqueError("La variable doit etre un entier");strcpy(taille1,return_VALUE_SIZE_Cst_Idf(taille1,top(stack_name_Routine)));}
                                                                                    if(isIDF2){if(strcmp(return_TYPE_Cst_Idf(taille2,top(stack_name_Routine)),"INTEGER")!=0)semantiqueError("La variable doit etre un entier"); strcpy(taille2,return_VALUE_SIZE_Cst_Idf(taille2,top(stack_name_Routine)));}
                                                                                    Traitement_taille_DEC_TAB_MAT((yyvsp[(2) - (7)].str),taille1,taille2,stack_name_Routine);
                                                                                    pop(stack_type);
                                                                                    pop(stack_variable);
                                                                                    quadr("ADEC",(yyvsp[(2) - (7)].str),"vide","vide");
                                                                                    cmpt=0;  
                                                                                    strcpy(taille1,"0");
                                                                                    strcpy(taille2,"0");
                                                                                    isIDF1 = false ; 
                                                                                    isIDF2 = false ;
                                                                                    cmpt_TAB = 0 ; 
                                                                                    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 133 "../src/syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(2) - (7)].str),stack_name_Routine);
                                                                                    add_SCOPE_Cst_Idf((yyvsp[(2) - (7)].str),top(stack_name_Routine));
                                                                                    add_TYPE_Cst_Idf((yyvsp[(2) - (7)].str),"CHARACTER 1",top(stack_name_Routine));
                                                                                    add_CODE_Cst_Idf((yyvsp[(2) - (7)].str),code,top(stack_name_Routine));                                                       
                                                                                    strcpy(taille1,top(stack_variable));
                                                                                    quadr("BOUNDS","0",taille1,"vide");
                                                                                    if(strcmp(code,"MATRICE")==0)quadr("BOUNDS","0",taille2,"vide");
                                                                                    if(isIDF1){if(strcmp(return_TYPE_Cst_Idf(taille1,top(stack_name_Routine)),"INTEGER")!=0)semantiqueError("La variable doit etre un entier");strcpy(taille1,return_VALUE_SIZE_Cst_Idf(taille1,top(stack_name_Routine)));}
                                                                                    if(isIDF2){if(strcmp(return_TYPE_Cst_Idf(taille2,top(stack_name_Routine)),"INTEGER")!=0)semantiqueError("La variable doit etre un entier");strcpy(taille2,return_VALUE_SIZE_Cst_Idf(taille2,top(stack_name_Routine)));}
                                                                                    Traitement_taille_DEC_TAB_MAT((yyvsp[(2) - (7)].str),taille1,taille2,stack_name_Routine);
                                                                                    pop(stack_variable);                 
                                                                                    quadr("ADEC",(yyvsp[(2) - (7)].str),"vide","vide");
                                                                                    cmpt=0;
                                                                                    isIDF1 = false ; 
                                                                                    isIDF2 = false ;
                                                                                    strcpy(taille1,"0");
                                                                                    strcpy(taille2,"0");
                                                                                    cmpt_TAB = 0 ; 
                                                                                    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 154 "../src/syntaxique.y"
    { strcpy(taille2,top(stack_variable));
                        pop(stack_variable); 
                        strcpy(code,"MATRICE");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 157 "../src/syntaxique.y"
    { strcpy(code,"TABLEAU");strcpy(taille2,"0");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 159 "../src/syntaxique.y"
    {push(stack_value, intToString((yyvsp[(2) - (2)].entier)));push(stack_variable,intToString((yyvsp[(2) - (2)].entier)));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 160 "../src/syntaxique.y"
    {push(stack_value, floatToString((yyvsp[(2) - (2)].reel)));push(stack_variable,floatToString((yyvsp[(2) - (2)].reel))) ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 161 "../src/syntaxique.y"
    {push(stack_value, (yyvsp[(2) - (2)].str));push(stack_variable,(yyvsp[(2) - (2)].str));  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 162 "../src/syntaxique.y"
    {push(stack_value, (yyvsp[(2) - (2)].str));push(stack_variable,(yyvsp[(2) - (2)].str));  ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 164 "../src/syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(3) - (5)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(3) - (5)].str),top(stack_name_Routine));strcpy(strg,"CHARACTER ");strcat(strg,intToString((yyvsp[(5) - (5)].entier)));add_TYPE_Cst_Idf((yyvsp[(3) - (5)].str), strg,top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(3) - (5)].str),"VARIABLE",top(stack_name_Routine));;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 165 "../src/syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(1) - (3)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(1) - (3)].str),top(stack_name_Routine));strcpy(strg,"CHARACTER ");strcat(strg,intToString((yyvsp[(3) - (3)].entier)));add_TYPE_Cst_Idf((yyvsp[(1) - (3)].str), strg,top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (3)].str),"VARIABLE",top(stack_name_Routine));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 166 "../src/syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(1) - (4)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_name_Routine));strcpy(strg,"CHARACTER ");strcat(strg,intToString((yyvsp[(3) - (4)].entier)));add_TYPE_Cst_Idf((yyvsp[(1) - (4)].str), strg,top(stack_name_Routine));add_VALUE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(1) - (4)].str),"VARIABLE",top(stack_name_Routine));check_taille_character((yyvsp[(1) - (4)].str),top(stack_name_Routine));strcpy(strg,top(stack_variable));quadr(":=",strg,"vide",(yyvsp[(1) - (4)].str));pop(stack_variable);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 167 "../src/syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(3) - (6)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(3) - (6)].str),top(stack_name_Routine));strcpy(strg,"CHARACTER ");strcat(strg,intToString((yyvsp[(5) - (6)].entier)));add_TYPE_Cst_Idf((yyvsp[(3) - (6)].str), strg,top(stack_name_Routine));add_VALUE_Cst_Idf((yyvsp[(3) - (6)].str),top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(3) - (6)].str),"VARIABLE",top(stack_name_Routine));check_taille_character((yyvsp[(3) - (6)].str),top(stack_name_Routine));;strcpy(strg,top(stack_variable));quadr(":=",strg,"vide",(yyvsp[(3) - (6)].str));pop(stack_variable);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 168 "../src/syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(1) - (1)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(1) - (1)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (1)].str), "CHARACTER 1",top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(1) - (1)].str),"VARIABLE",top(stack_name_Routine));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 169 "../src/syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(3) - (3)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(3) - (3)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(3) - (3)].str), "CHARACTER 1",top(stack_name_Routine));add_CODE_Cst_Idf((yyvsp[(3) - (3)].str),"VARIABLE",top(stack_name_Routine));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 170 "../src/syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(1) - (2)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(1) - (2)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(1) - (2)].str), "CHARACTER 1",top(stack_name_Routine));add_VALUE_Cst_Idf((yyvsp[(1) - (2)].str),top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(1) - (2)].str),"VARIABLE",top(stack_name_Routine));check_taille_character((yyvsp[(1) - (2)].str),top(stack_name_Routine));strcpy(strg,top(stack_variable));quadr(":=",strg,"vide",(yyvsp[(1) - (2)].str));pop(stack_variable);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 171 "../src/syntaxique.y"
    {checkDoubleDeclaration((yyvsp[(3) - (4)].str),stack_name_Routine);add_SCOPE_Cst_Idf((yyvsp[(3) - (4)].str),top(stack_name_Routine));add_TYPE_Cst_Idf((yyvsp[(3) - (4)].str), "CHARACTER 1",top(stack_name_Routine));add_VALUE_Cst_Idf((yyvsp[(3) - (4)].str),top(stack_value),top(stack_name_Routine));pop(stack_value);add_CODE_Cst_Idf((yyvsp[(3) - (4)].str),"VARIABLE",top(stack_name_Routine));check_taille_character((yyvsp[(3) - (4)].str),top(stack_name_Routine));strcpy(strg,top(stack_variable));quadr(":=",strg,"vide",(yyvsp[(3) - (4)].str));pop(stack_variable);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 174 "../src/syntaxique.y"
    {push(stack_value,(yyvsp[(2) - (2)].str));push(stack_variable,(yyvsp[(2) - (2)].str));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 176 "../src/syntaxique.y"
    {push(stack_type, "INTEGER");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 177 "../src/syntaxique.y"
    {push(stack_type, "REAL");}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 178 "../src/syntaxique.y"
    {push(stack_type, "LOGICAL");}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 192 "../src/syntaxique.y"
    {check_idf_Variable_Existe((yyvsp[(1) - (4)].str),stack_name_Routine);
                                          checkType_affectation_idf((yyvsp[(1) - (4)].str),save_type_operateur,stack_name_Routine,cmpt);    
                                                if(cmpt==2) {add_VALUE_Cst_Idf((yyvsp[(1) - (4)].str),value_op,top(stack_name_Routine));}

                                                strcpy(strg,top(stack_variable));
                                                quadr(":=",strg,"vide",(yyvsp[(1) - (4)].str));
                                                pop(stack_variable);
                                                initVar((yyvsp[(1) - (4)].str),stack_name_Routine);
                                                cmpt=0;
                                          ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 202 "../src/syntaxique.y"
    {check_idf_Variable_Existe((yyvsp[(1) - (4)].str),stack_name_Routine);
                                          
                                           check_Type_char((yyvsp[(1) - (4)].str),stack_name_Routine);
                                           quadr(":=",(yyvsp[(3) - (4)].str),"vide",(yyvsp[(1) - (4)].str));
                                           add_VALUE_Cst_Idf((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str),top(stack_name_Routine));
                                           check_taille_character((yyvsp[(1) - (4)].str),top(stack_name_Routine));
                                            
                                          ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 210 "../src/syntaxique.y"
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
#line 220 "../src/syntaxique.y"
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
#line 231 "../src/syntaxique.y"
    {quadr("CALL", "WRITE", intToString(nbArg_Write), "vide");nbArg_Write=0; ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 232 "../src/syntaxique.y"
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
#line 239 "../src/syntaxique.y"
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
#line 247 "../src/syntaxique.y"
    {quadArgument(stack_variable);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 248 "../src/syntaxique.y"
    { cmpt=0;nbArg_Write++; quadArgument(stack_variable);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 249 "../src/syntaxique.y"
    {quadArgument(stack_variable);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 250 "../src/syntaxique.y"
    { cmpt=0; nbArg_Write++;quadArgument(stack_variable);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 252 "../src/syntaxique.y"
    {push(stack_variable,(yyvsp[(1) - (1)].str));nbArg_Write++;;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 259 "../src/syntaxique.y"
    {quadr("CALL","EQUIVALENCE",intToString(nbArg_Eqv),"vide");nbArg_Eqv=0;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 261 "../src/syntaxique.y"
    {strcpy(strg,top(stack_name_Routine)); check_idf_Equivalence((yyvsp[(3) - (3)].str),strg);push(stack_variable,(yyvsp[(3) - (3)].str));             quadArgument(stack_variable);nbArg_Eqv++; ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 262 "../src/syntaxique.y"
    {  quadArgument(stack_variable);nbArg_Eqv++;;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 263 "../src/syntaxique.y"
    {strcpy(strg,top(stack_name_Routine)); check_idf_Equivalence((yyvsp[(1) - (1)].str), strg);  push(stack_variable,(yyvsp[(1) - (1)].str));          quadArgument(stack_variable);nbArg_Eqv++; ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 264 "../src/syntaxique.y"
    { quadArgument(stack_variable);nbArg_Eqv++; ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 266 "../src/syntaxique.y"
    {divZero=false; ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 268 "../src/syntaxique.y"
    {divZero=false;check_Type_operateurs(stack_variable,stack_name_Routine,true);quadExpression(stack_variable,"+");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 269 "../src/syntaxique.y"
    {divZero=false;check_Type_operateurs(stack_variable,stack_name_Routine,true);quadExpression(stack_variable,"-");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 273 "../src/syntaxique.y"
    {divZero=false;check_Type_operateurs(stack_variable,stack_name_Routine,true);quadExpression(stack_variable,"*");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 274 "../src/syntaxique.y"
    {divZero=false;check_Type_operateurs(stack_variable,stack_name_Routine,true);quadExpression(stack_variable,"/");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 275 "../src/syntaxique.y"
    {divZero=false;check_Type_operateurs(stack_variable,stack_name_Routine,false);quadOpUnaire(stack_variable,"Moins Unaire");}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 278 "../src/syntaxique.y"
    {checkDivPar0(divZero);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 280 "../src/syntaxique.y"
    {;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 281 "../src/syntaxique.y"
    {if((yyvsp[(1) - (1)].entier)==0)divZero=true;else divZero = false ;
                              if (cmpt==0 || cmpt==1){ strcpy(save_type_operateur,"INTEGER"); strcpy(value_op,intToString((yyvsp[(1) - (1)].entier)));}
                              if(cmpt==2) strcpy(strg,"INTEGER");
                              cmpt=cmpt+2;
                              strcpy(strg,"INTEGER");
                              push(stack_variable,intToString((yyvsp[(1) - (1)].entier)));
                              ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 288 "../src/syntaxique.y"
    {if((yyvsp[(1) - (1)].reel)==0)divZero=true;else divZero = false;
                              if (cmpt==0 || cmpt==1){ strcpy(save_type_operateur,"REAL");  strcpy(value_op,floatToString((yyvsp[(1) - (1)].reel)));}
                                  
                              if(cmpt==2) strcpy(strg,"REAL"); 
                              push(stack_variable, floatToString((yyvsp[(1) - (1)].reel)));
                              cmpt = cmpt + 2 ; 
                              ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 295 "../src/syntaxique.y"
    {  divZero = false  ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 296 "../src/syntaxique.y"
    {
                              check_idf_Variable_Existe((yyvsp[(1) - (1)].str),stack_name_Routine);
                              checkInit((yyvsp[(1) - (1)].str),stack_name_Routine); // verifier que la variable est initialisee
                              divZero = activerDivPar0((yyvsp[(1) - (1)].str),stack_name_Routine);
                             
                              if(cmpt==2) strcpy(strg,return_TYPE_Cst_Idf((yyvsp[(1) - (1)].str),top(stack_name_Routine)));  
                              if (cmpt==0 || cmpt==1) { strcpy(save_type_operateur,return_TYPE_Cst_Idf((yyvsp[(1) - (1)].str),top(stack_name_Routine)));strcpy(value_op,return_VALUE_SIZE_Cst_Idf((yyvsp[(1) - (1)].str),top(stack_name_Routine)));}
                             
                              cmpt=cmpt+2;
                              push(stack_variable,(yyvsp[(1) - (1)].str));
                        ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 308 "../src/syntaxique.y"
    {push(stack_variable,intToString((yyvsp[(1) - (1)].entier))); cmpt_TAB++;;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 308 "../src/syntaxique.y"
    {check_idf_Variable_Existe((yyvsp[(1) - (1)].str),stack_name_Routine); push(stack_variable,(yyvsp[(1) - (1)].str)); if (cmpt_TAB==1){isIDF2=true;}else{isIDF1=true;}  cmpt_TAB++; ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 311 "../src/syntaxique.y"
    {check_idf_Matrice_Existe((yyvsp[(1) - (6)].str),stack_name_Routine);// idf n'existe pas dans TS ou pas un nom de matrice 
                                                             strcpy(secondSize,top(stack_variable));
                                                             pop(stack_variable);
                                                             strcpy(firstSize,top(stack_variable));
                                                             pop(stack_variable);
                                                             

                                                            if (isIDF1==true){
                                                                 if (isIDF2==true){
                                                                       if(strcmp(return_TYPE_Cst_Idf(firstSize,top(stack_name_Routine)),"INTEGER")==0 && strcmp(return_TYPE_Cst_Idf(secondSize,top(stack_name_Routine)),"INTEGER")==0)
                                                                       {
                                                                       checkSize((yyvsp[(1) - (6)].str),stack_name_Routine,return_VALUE_SIZE_Cst_Idf(firstSize,top(stack_name_Routine)),return_VALUE_SIZE_Cst_Idf(secondSize,top(stack_name_Routine))); }
                                                                       else{semantiqueError("we can reference an array with only integer indexes ");}
                                                                  }else{
                                                                        if(strcmp(return_TYPE_Cst_Idf(firstSize,top(stack_name_Routine)),"INTEGER")==0)
                                                                        {checkSize((yyvsp[(1) - (6)].str),stack_name_Routine,return_VALUE_SIZE_Cst_Idf(firstSize,top(stack_name_Routine)),secondSize);}
                                                                        else{semantiqueError("we can reference an array with only integer indexes ");}
                                                                  }
                                                            }else{
                                                                  if (isIDF2==true){
                                                                       if(strcmp(return_TYPE_Cst_Idf(secondSize,top(stack_name_Routine)),"INTEGER")==0)
                                                                       {checkSize((yyvsp[(1) - (6)].str),stack_name_Routine,firstSize,return_VALUE_SIZE_Cst_Idf(secondSize,top(stack_name_Routine))); }
                                                                       else{semantiqueError("we can reference an array with only integer indexes ");}
                                                                  }else{
                                                                        checkSize((yyvsp[(1) - (6)].str),stack_name_Routine,firstSize,secondSize);
                                                                  }
                                                            }
                                                                     
                                                            if (cmpt ==0)
                                                            {   strcpy(TAB_reference,return_TYPE_Cst_Idf((yyvsp[(1) - (6)].str),top(stack_name_Routine))); }
                                                            
                                                            strcpy(save_type_operateur,return_TYPE_Cst_Idf((yyvsp[(1) - (6)].str),top(stack_name_Routine)));  
                                                            
                                                            Tab_idfInStack_Quad(stack_variable,(yyvsp[(1) - (6)].str),firstSize,secondSize);
                                                             strcpy(firstSize," ");
                                                             strcpy(secondSize," ");
                                                             cmpt_TAB=0;
                                                             cmpt++;
                                                             isIDF1=false;
                                                             isIDF2=false;
                                                            ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 352 "../src/syntaxique.y"
    {check_idf_Tableau_Existe((yyvsp[(1) - (4)].str),stack_name_Routine);
                                                             strcpy(firstSize,top(stack_variable));
                                                             
                                                             pop(stack_variable);
                                                            if(isIDF1==true)
                                                            {
                                                                  if (strcmp(return_TYPE_Cst_Idf(firstSize,top(stack_name_Routine)),"INTEGER")!=0)
                                                                  {
                                                                        semantiqueError("we can reference an array with only integer indexes ");
                                                                  }else{
                                                                       checkSize((yyvsp[(1) - (4)].str),stack_name_Routine,return_VALUE_SIZE_Cst_Idf(firstSize,top(stack_name_Routine)),"0"); 
                                                                  }
                                                            }
                                                            else {checkSize((yyvsp[(1) - (4)].str),stack_name_Routine,firstSize,"0"); }
      
                                                            if (cmpt==0 )
                                                                 { strcpy(TAB_reference,return_TYPE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_name_Routine))); }
                                                            
                                                            strcpy(save_type_operateur,return_TYPE_Cst_Idf((yyvsp[(1) - (4)].str),top(stack_name_Routine))); 
                                                           
                                                           
                                                            Tab_idfInStack_Quad(stack_variable,(yyvsp[(1) - (4)].str),firstSize,"-1");
                                                             cmpt_TAB=0;
                                                             cmpt++;
                                                             isIDF1=false;
                                                             isIDF2=false;
                                                            ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 381 "../src/syntaxique.y"
    {;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 383 "../src/syntaxique.y"
    {push(stack_Qc_SOUS_Cond,intToString(qc));strcpy(strg,top(stack_variable));quadr("BNZ","",strg,"vide");pop(stack_variable);strcpy(temp, "temp");strcat(temp, intToString(actTemp));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 385 "../src/syntaxique.y"
    {push(stack_Qc_SOUS_Cond,intToString(qc));strcpy(strg,top(stack_variable));quadr("BZ","",strg,"vide");pop(stack_variable);strcpy(temp, "temp");strcat(temp, intToString(actTemp));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 389 "../src/syntaxique.y"
    { if(!isEmpty(stack_Qc_SOUS_Cond)){strcpy(strg,top(stack_Qc_SOUS_Cond));ajour_quad(atoi(strg),1,intToString(qc));pop(stack_Qc_SOUS_Cond);};}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 392 "../src/syntaxique.y"
    { if(!isEmpty(stack_Qc_SOUS_Cond)){strcpy(strg,top(stack_Qc_SOUS_Cond));ajour_quad(atoi(strg),1,intToString(qc));pop(stack_Qc_SOUS_Cond);};}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 398 "../src/syntaxique.y"
    {quadExpression(stack_variable,"LT");if(!isEmpty(stack_Qc_SOUS_Cond)){strcpy(strg,top(stack_Qc_SOUS_Cond));ajour_quad(atoi(strg),1,intToString(qc));pop(stack_Qc_SOUS_Cond);};}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 399 "../src/syntaxique.y"
    {quadExpression(stack_variable,"GT");if(!isEmpty(stack_Qc_SOUS_Cond)){strcpy(strg,top(stack_Qc_SOUS_Cond));ajour_quad(atoi(strg),1,intToString(qc));pop(stack_Qc_SOUS_Cond);};}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 400 "../src/syntaxique.y"
    {quadExpression(stack_variable,"NE");if(!isEmpty(stack_Qc_SOUS_Cond)){strcpy(strg,top(stack_Qc_SOUS_Cond));ajour_quad(atoi(strg),1,intToString(qc));pop(stack_Qc_SOUS_Cond);};}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 401 "../src/syntaxique.y"
    {quadExpression(stack_variable,"LE");if(!isEmpty(stack_Qc_SOUS_Cond)){strcpy(strg,top(stack_Qc_SOUS_Cond));ajour_quad(atoi(strg),1,intToString(qc));pop(stack_Qc_SOUS_Cond);};}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 402 "../src/syntaxique.y"
    {quadExpression(stack_variable,"GE");if(!isEmpty(stack_Qc_SOUS_Cond)){strcpy(strg,top(stack_Qc_SOUS_Cond));ajour_quad(atoi(strg),1,intToString(qc));pop(stack_Qc_SOUS_Cond);};}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 403 "../src/syntaxique.y"
    {quadExpression(stack_variable,"EQ");if(!isEmpty(stack_Qc_SOUS_Cond)){strcpy(strg,top(stack_Qc_SOUS_Cond));ajour_quad(atoi(strg),1,intToString(qc));pop(stack_Qc_SOUS_Cond);};}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 405 "../src/syntaxique.y"
    {cmpt=0;;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 406 "../src/syntaxique.y"
    {pop(stack_value);;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 408 "../src/syntaxique.y"
    {pop(stack_value);;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 410 "../src/syntaxique.y"
    {push(stack_variable,(yyvsp[(1) - (1)].str));push(stack_value,(yyvsp[(1) - (1)].str));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 410 "../src/syntaxique.y"
    {push(stack_variable,(yyvsp[(1) - (1)].str));push(stack_value,(yyvsp[(1) - (1)].str));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 412 "../src/syntaxique.y"
    {
                                             ajour_quad(sauv_BR,1,intToString(qc));
						         ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 416 "../src/syntaxique.y"
    {  sprintf(strg,"%d",qc);
                                             ajour_quad(atoi(top(stack_BZ)),1,intToString(qc));
                                             pop(stack_BZ);
						      ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 421 "../src/syntaxique.y"
    {sauv_BR=qc;
                                               quadr("BR","","vide","vide");   
                                               ajour_quad(atoi(top(stack_BZ)),1,intToString(qc));
                                               pop(stack_BZ);;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 427 "../src/syntaxique.y"
    {
                                                           push(stack_BZ,intToString(qc));
                                                           strcpy(temp,top(stack_variable));
                                                           quadr("BZ", "",temp, "vide"); ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 436 "../src/syntaxique.y"
    {strcpy(strg,top(stack_deb_cond));
                                                quadr("BR", strg ,"vide", "vide"); 
                                                pop(stack_deb_cond);
                                                ajour_quad(atoi(top(stack_BZ)),1,intToString(qc));
                                                pop(stack_BZ);;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 442 "../src/syntaxique.y"
    {push(stack_BZ,intToString(qc)); // J'ai laisser le champs 2 vide. Je dois le remplir apres
                                                            strcpy(temp,top(stack_variable));
                                                            quadr("BZ", "",temp, "vide"); ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 446 "../src/syntaxique.y"
    {push(stack_deb_cond,intToString(qc));;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 449 "../src/syntaxique.y"
    {
                                                                      check_idf_Aff_Call((yyvsp[(1) - (8)].str),stack_name_Routine); // verifier qu'il existe + n'est pas une routine
                                                                      CheckRoutineExiste ((yyvsp[(4) - (8)].str));
                                                                      check_Routine_Signature((yyvsp[(4) - (8)].str),stack_name_Routine,nbArg);
                                                                      check_TypeRetour_compatible((yyvsp[(1) - (8)].str),(yyvsp[(4) - (8)].str),stack_name_Routine);
                                                                      quadr("CALL",(yyvsp[(4) - (8)].str),intToString(nbArg),"vide");//(call, nomFonc, nbArg, vide )
                                                                       nbArg = 0;
                                                                       initVar((yyvsp[(1) - (8)].str),stack_name_Routine);
                                                                      ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 462 "../src/syntaxique.y"
    {nbArg++; cmpt=0;quadArgument(stack_variable); ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 463 "../src/syntaxique.y"
    {nbArg++; cmpt=0;quadArgument(stack_variable);  ;}
    break;



/* Line 1455 of yacc.c  */
#line 2570 "syntaxique.tab.c"
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
#line 472 "../src/syntaxique.y"



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
              stack_Qc_Cond= initializeStack();
              stack_Qc_SOUS_Cond= initializeStack();
              strcpy(taille1,"0");
              strcpy(taille2,"0");
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


