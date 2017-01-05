/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "grammar.y"

  #define _GNU_SOURCE
  
   #include <stdio.h>
   #include <stdlib.h> 
   #include "expression_symbols.h"
  //#include "expression.h"
   #include "search.h"
   #include "hash.h"

char *double_to_hex_str(double d){
  char *s = NULL;
  union {
    double a;
    long long int b;
  } u;
  u.a = d;
  asprintf(&s, "%#08llx", u.b);
  return s;
}
  
   extern int yylineno;
   int yylex ();
   int yyerror ();
   int level = 0;
   struct declarator *liste_declarators[16];
   int nb_declarators = 0;
   

/* Line 371 of yacc.c  */
#line 98 "grammar.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "grammar.tab.h".  */
#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANTI = 259,
     CONSTANTF = 260,
     INC_OP = 261,
     DEC_OP = 262,
     LE_OP = 263,
     GE_OP = 264,
     EQ_OP = 265,
     NE_OP = 266,
     SUB_ASSIGN = 267,
     MUL_ASSIGN = 268,
     ADD_ASSIGN = 269,
     DIV_ASSIGN = 270,
     SHL_ASSIGN = 271,
     SHR_ASSIGN = 272,
     REM_ASSIGN = 273,
     REM = 274,
     SHL = 275,
     SHR = 276,
     AND = 277,
     OR = 278,
     TYPE_NAME = 279,
     INT = 280,
     DOUBLE = 281,
     VOID = 282,
     IF = 283,
     ELSE = 284,
     DO = 285,
     WHILE = 286,
     RETURN = 287,
     FOR = 288
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 49 "grammar.y"

  char *string;
  int n;
  double f;
  enum simple_type t;
  struct declarator *d;
  struct expression_symbol *s;
  //struct expression expr;


/* Line 387 of yacc.c  */
#line 185 "grammar.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 213 "grammar.c"

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   305

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNRULES -- Number of states.  */
#define YYNSTATES  180

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,    35,    38,    40,    36,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      41,    43,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    13,    17,    19,    23,
      27,    29,    31,    33,    37,    41,    46,    48,    51,    54,
      56,    60,    62,    65,    68,    71,    73,    75,    79,    83,
      87,    89,    93,    97,    99,   103,   107,   111,   115,   119,
     123,   127,   129,   131,   133,   135,   137,   139,   141,   143,
     145,   149,   151,   155,   157,   159,   161,   163,   167,   172,
     176,   178,   182,   185,   187,   189,   191,   193,   195,   198,
     202,   207,   211,   213,   215,   217,   220,   222,   225,   227,
     230,   236,   244,   254,   263,   272,   280,   289,   297,   305,
     312,   317,   324,   327,   331,   333,   335,   338,   340,   342
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      78,     0,    -1,    49,    -1,    50,    -1,    49,    23,    50,
      -1,    59,    -1,    50,    22,    59,    -1,    58,    -1,    51,
      20,    58,    -1,    51,    21,    58,    -1,     3,    -1,     4,
      -1,     5,    -1,    34,    60,    35,    -1,     3,    34,    35,
      -1,     3,    34,    54,    35,    -1,    52,    -1,    53,     6,
      -1,    53,     7,    -1,    60,    -1,    54,    36,    60,    -1,
      53,    -1,     6,    55,    -1,     7,    55,    -1,    56,    55,
      -1,    37,    -1,    55,    -1,    57,    38,    55,    -1,    57,
      39,    55,    -1,    57,    19,    55,    -1,    57,    -1,    58,
      40,    57,    -1,    58,    37,    57,    -1,    51,    -1,    59,
      41,    51,    -1,    59,    42,    51,    -1,    59,     8,    51,
      -1,    59,     9,    51,    -1,    59,    10,    51,    -1,    59,
      11,    51,    -1,    55,    61,    48,    -1,    48,    -1,    43,
      -1,    13,    -1,    15,    -1,    18,    -1,    16,    -1,    17,
      -1,    14,    -1,    12,    -1,    64,    63,    44,    -1,    65,
      -1,    63,    36,    65,    -1,    27,    -1,    25,    -1,    26,
      -1,     3,    -1,    34,    65,    35,    -1,    65,    34,    66,
      35,    -1,    65,    34,    35,    -1,    67,    -1,    66,    36,
      67,    -1,    64,    65,    -1,    69,    -1,    74,    -1,    75,
      -1,    76,    -1,    77,    -1,    70,    71,    -1,    70,    72,
      71,    -1,    70,    72,    73,    71,    -1,    70,    73,    71,
      -1,    45,    -1,    46,    -1,    62,    -1,    72,    62,    -1,
      68,    -1,    73,    68,    -1,    44,    -1,    60,    44,    -1,
      28,    34,    60,    35,    68,    -1,    28,    34,    60,    35,
      68,    29,    68,    -1,    33,    34,    60,    44,    60,    44,
      60,    35,    68,    -1,    33,    34,    60,    44,    60,    44,
      35,    68,    -1,    33,    34,    60,    44,    44,    60,    35,
      68,    -1,    33,    34,    60,    44,    44,    35,    68,    -1,
      33,    34,    44,    60,    44,    60,    35,    68,    -1,    33,
      34,    44,    60,    44,    35,    68,    -1,    33,    34,    44,
      44,    60,    35,    68,    -1,    33,    34,    44,    44,    35,
      68,    -1,    31,    34,    60,    35,    -1,    30,    68,    31,
      34,    60,    35,    -1,    32,    44,    -1,    32,    60,    44,
      -1,    79,    -1,    80,    -1,    79,    80,    -1,    81,    -1,
      62,    -1,    64,    65,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    65,    66,    85,    86,   106,   122,   123,
     127,   145,   149,   154,   160,   164,   171,   172,   194,   219,
     220,   228,   229,   256,   283,   317,   321,   322,   423,   521,
     564,   568,   666,   767,   771,   833,   895,   957,  1019,  1081,
    1146,  1317,  1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,
    1332,  1405,  1410,  1418,  1420,  1422,  1427,  1432,  1436,  1440,
    1447,  1448,  1452,  1463,  1464,  1465,  1466,  1467,  1471,  1472,
    1473,  1474,  1478,  1482,  1494,  1495,  1499,  1500,  1504,  1505,
    1509,  1526,  1544,  1580,  1581,  1582,  1583,  1584,  1585,  1586,
    1590,  1591,  1595,  1596,  1624,  1632,  1633,  1637,  1638,  1642
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANTI", "CONSTANTF",
  "INC_OP", "DEC_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "SUB_ASSIGN",
  "MUL_ASSIGN", "ADD_ASSIGN", "DIV_ASSIGN", "SHL_ASSIGN", "SHR_ASSIGN",
  "REM_ASSIGN", "REM", "SHL", "SHR", "AND", "OR", "TYPE_NAME", "INT",
  "DOUBLE", "VOID", "IF", "ELSE", "DO", "WHILE", "RETURN", "FOR", "'('",
  "')'", "','", "'-'", "'*'", "'/'", "'+'", "'<'", "'>'", "'='", "';'",
  "'{'", "'}'", "$accept", "conditional_expression",
  "logical_or_expression", "logical_and_expression", "shift_expression",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "comparison_expression", "expression",
  "assignment_operator", "declaration", "declarator_list", "type_name",
  "declarator", "parameter_list", "parameter_declaration", "statement",
  "compound_statement", "LB", "RB", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "compilation_program", "program",
  "external_declaration", "function_definition", YY_NULL
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
     285,   286,   287,   288,    40,    41,    44,    45,    42,    47,
      43,    60,    62,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    51,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    54,
      54,    55,    55,    55,    55,    56,    57,    57,    57,    57,
      58,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    63,    63,    64,    64,    64,    65,    65,    65,    65,
      66,    66,    67,    68,    68,    68,    68,    68,    69,    69,
      69,    69,    70,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      76,    68,    77,    77,    78,    79,    79,    80,    80,    81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     1,     1,     3,     3,     4,     1,     2,     2,     1,
       3,     1,     2,     2,     2,     1,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     3,     4,     3,
       1,     3,     2,     1,     1,     1,     1,     1,     2,     3,
       4,     3,     1,     1,     1,     2,     1,     2,     1,     2,
       5,     7,     9,     8,     8,     7,     8,     7,     7,     6,
       4,     6,     2,     3,     1,     1,     2,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    54,    55,    53,    98,     0,     0,    94,    95,    97,
      56,     0,     0,    51,     1,    96,     0,     0,    50,     0,
      72,    99,     0,    57,    52,    59,     0,     0,    60,    10,
      11,    12,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    78,    73,    41,     2,     3,    33,    16,    21,    26,
       0,    30,     7,     5,     0,    74,     0,    76,    63,    68,
       0,     0,    64,    65,    66,    67,    62,    58,     0,     0,
      22,    23,     0,     0,     0,    92,     0,     0,     0,     0,
       0,     0,     0,    17,    18,    49,    43,    48,    44,    46,
      47,    45,    42,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    51,    75,    69,
       0,    77,    71,    61,    14,     0,    19,     0,     0,     0,
      93,     0,     0,    13,     4,    26,     6,     8,     9,    40,
      29,    27,    28,    32,    31,    36,    37,    38,    39,    34,
      35,    70,    15,     0,     0,     0,    90,     0,     0,     0,
      20,    80,     0,     0,     0,     0,     0,     0,     0,    91,
      89,     0,     0,     0,     0,     0,     0,    81,    88,    87,
       0,    85,     0,     0,     0,    86,    84,    83,     0,    82
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    43,    44,    45,    46,    47,    48,   115,    49,    50,
      51,    52,    53,    54,    93,     4,    12,     5,    13,    27,
      28,    57,    58,    22,    59,    60,    61,    62,    63,    64,
      65,     6,     7,     8,     9
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int16 yypact[] =
{
     129,   -60,   -60,   -60,   -60,    22,     3,   129,   -60,   -60,
     -60,    22,    69,   -27,   -60,   -60,   -14,    22,   -60,   174,
     -60,   -60,    66,   -60,   -26,   -60,    22,    72,   -60,   -11,
     -60,   -60,   258,   258,    -1,     8,    10,    24,    12,   258,
     -60,   -60,   -60,   -60,    14,    26,    81,   -60,   110,   262,
     258,    76,    -5,   111,     6,   -60,    22,   -60,   -60,   -60,
      66,   141,   -60,   -60,   -60,   -60,   -26,   -60,   129,   201,
     -60,   -60,   258,    29,   258,   -60,    23,   154,    39,   258,
     258,   258,   258,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   258,   -60,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   -60,   -26,   -60,   -60,
     141,   -60,   -60,   -60,   -60,    89,   -60,    41,    44,    55,
     -60,   159,    60,   -60,    26,   -60,   111,    -5,    -5,   -60,
     -60,   -60,   -60,    76,    76,    81,    81,    81,    81,    81,
      81,   -60,   -60,   258,     8,   258,   -60,   211,    87,   176,
     -60,   104,   101,     8,   107,   218,   223,    95,     8,   -60,
     -60,     8,     8,   135,     8,   142,   236,   -60,   -60,   -60,
       8,   -60,     8,     8,   149,   -60,   -60,   -60,     8,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,    83,   -60,   113,   181,   -60,   -60,   -60,   -16,   -60,
      51,    86,   109,   -15,   -60,   -17,   -60,   -13,    -7,   -60,
     122,   -35,   182,   -60,   -59,   -60,   134,   -60,   -60,   -60,
     -60,   -60,   -60,   190,   -60
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      73,   109,   112,    14,    16,    55,    26,    19,    19,    56,
      24,    29,    30,    31,    32,    33,    70,    71,    20,    66,
      19,    23,    76,    69,    78,    10,   111,    29,    30,    31,
      32,    33,    98,    72,    94,    99,    34,    79,    35,    36,
      37,    38,    39,   108,    74,    40,    77,    56,    80,   107,
     106,   141,    41,    20,   116,    26,    11,   117,    39,   119,
     118,    40,   122,   125,   125,   125,   125,   120,    75,    29,
      30,    31,    32,    33,   123,   111,   144,   125,   145,   130,
     131,   132,   125,   125,   125,   125,   125,   125,   125,   125,
     146,     1,     2,     3,    34,    95,    35,    36,    37,    38,
      39,    81,    82,    40,   149,    17,   148,    67,    68,   151,
      41,    20,    42,    18,    96,    97,    83,    84,   160,   100,
     101,   102,   103,   167,   142,   143,   168,   169,   150,   171,
     152,   155,   154,   158,   157,   175,   159,   176,   177,   166,
     163,   165,   161,   179,    29,    30,    31,    32,    33,   133,
     134,   174,   104,   105,     1,     2,     3,    29,    30,    31,
      32,    33,    29,    30,    31,    32,    33,   127,   128,    34,
     170,    35,    36,    37,    38,    39,   129,   172,    40,    29,
      30,    31,    32,    33,   178,    41,    20,    42,    39,   126,
     113,    40,   124,    39,   110,    21,    40,    15,   121,     1,
       2,     3,     0,   147,    29,    30,    31,    32,    33,    25,
      39,     0,     0,    40,    29,    30,    31,    32,    33,     0,
     156,    29,    30,    31,    32,    33,    29,    30,    31,    32,
      33,     0,     0,     0,     0,    39,   114,     0,    40,    29,
      30,    31,    32,    33,     0,    39,   153,     0,    40,     0,
       0,     0,    39,   162,     0,    40,     0,    39,   164,     0,
      40,    29,    30,    31,    32,    33,     0,     0,     0,     0,
      39,   173,     0,    40,    85,    86,    87,    88,    89,    90,
      91,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,    39,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-60)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      35,    60,    61,     0,    11,    22,    19,    34,    34,    22,
      17,     3,     4,     5,     6,     7,    32,    33,    45,    26,
      34,    35,    37,    34,    39,     3,    61,     3,     4,     5,
       6,     7,    37,    34,    50,    40,    28,    23,    30,    31,
      32,    33,    34,    60,    34,    37,    34,    60,    22,    56,
      44,   110,    44,    45,    69,    68,    34,    72,    34,    74,
      31,    37,    77,    79,    80,    81,    82,    44,    44,     3,
       4,     5,     6,     7,    35,   110,    35,    93,    34,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      35,    25,    26,    27,    28,    19,    30,    31,    32,    33,
      34,    20,    21,    37,    44,    36,   121,    35,    36,   144,
      44,    45,    46,    44,    38,    39,     6,     7,   153,     8,
       9,    10,    11,   158,    35,    36,   161,   162,   143,   164,
     145,    44,   147,    29,   149,   170,    35,   172,   173,    44,
     155,   156,    35,   178,     3,     4,     5,     6,     7,    98,
      99,   166,    41,    42,    25,    26,    27,     3,     4,     5,
       6,     7,     3,     4,     5,     6,     7,    81,    82,    28,
      35,    30,    31,    32,    33,    34,    93,    35,    37,     3,
       4,     5,     6,     7,    35,    44,    45,    46,    34,    80,
      68,    37,    79,    34,    60,    13,    37,     7,    44,    25,
      26,    27,    -1,    44,     3,     4,     5,     6,     7,    35,
      34,    -1,    -1,    37,     3,     4,     5,     6,     7,    -1,
      44,     3,     4,     5,     6,     7,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,     3,
       4,     5,     6,     7,    -1,    34,    35,    -1,    37,    -1,
      -1,    -1,    34,    35,    -1,    37,    -1,    34,    35,    -1,
      37,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    12,    13,    14,    15,    16,    17,
      18,   100,   101,   102,   103,   104,   105,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    26,    27,    62,    64,    78,    79,    80,    81,
       3,    34,    63,    65,     0,    80,    65,    36,    44,    34,
      45,    69,    70,    35,    65,    35,    64,    66,    67,     3,
       4,     5,     6,     7,    28,    30,    31,    32,    33,    34,
      37,    44,    46,    48,    49,    50,    51,    52,    53,    55,
      56,    57,    58,    59,    60,    62,    64,    68,    69,    71,
      72,    73,    74,    75,    76,    77,    65,    35,    36,    34,
      55,    55,    34,    68,    34,    44,    60,    34,    60,    23,
      22,    20,    21,     6,     7,    12,    13,    14,    15,    16,
      17,    18,    43,    61,    55,    19,    38,    39,    37,    40,
       8,     9,    10,    11,    41,    42,    44,    65,    62,    71,
      73,    68,    71,    67,    35,    54,    60,    60,    31,    60,
      44,    44,    60,    35,    50,    55,    59,    58,    58,    48,
      55,    55,    55,    57,    57,    51,    51,    51,    51,    51,
      51,    71,    35,    36,    35,    34,    35,    44,    60,    44,
      60,    68,    60,    35,    60,    44,    44,    60,    29,    35,
      68,    35,    35,    60,    35,    60,    44,    68,    68,    68,
      35,    68,    35,    35,    60,    68,    68,    68,    35,    68
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
/* Line 1792 of yacc.c  */
#line 61 "grammar.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 65 "grammar.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 67 "grammar.y"
    {
  if ((yyvsp[(1) - (3)].s)->t == ENTIER && (yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n || (yyvsp[(3) - (3)].s)->v.n);
  }
  else if ((yyvsp[(1) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n || (yyvsp[(3) - (3)].s)->v.f);
  }
  else if ((yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f || (yyvsp[(3) - (3)].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f || (yyvsp[(3) - (3)].s)->v.f);
  }
  asprintf(&(yyval.s)->code,"%s%s %s%d = add i32 %d,0\n",(yyvsp[(1) - (3)].s)->code,(yyvsp[(3) - (3)].s)->code,"%x",(yyval.s)->var,(yyval.s)->v.n);
}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 85 "grammar.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 87 "grammar.y"
    {
  if ((yyvsp[(1) - (3)].s)->t == ENTIER && (yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n && (yyvsp[(3) - (3)].s)->v.n);
  }
  else if ((yyvsp[(1) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n && (yyvsp[(3) - (3)].s)->v.f);
  }
  else if ((yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f && (yyvsp[(3) - (3)].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f && (yyvsp[(3) - (3)].s)->v.f);
  }
  asprintf(&(yyval.s)->code,"%s%s %s%d = add i32 %d,0\n",(yyvsp[(1) - (3)].s)->code,(yyvsp[(3) - (3)].s)->code,"%x",(yyval.s)->var,(yyval.s)->v.n);
}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 107 "grammar.y"
    {
      if ((yyvsp[(1) - (1)].s)->t == ENTIER){
            printf("Résultat : %d\n", (yyvsp[(1) - (1)].s)->v.n);
	    /*$$ = create_expression_symbol_int($1->v.n);
	      $$->var = $1->var;*/
	    
      }
      else{
            printf("Résultat : %f\n", (yyvsp[(1) - (1)].s)->v.f);
	    /*$$ = create_expression_symbol_int($1->v.f);
	      $$->var = $1->var;*/
      }
      //$$->code = $1->code;
      (yyval.s) = (yyvsp[(1) - (1)].s);
    }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 128 "grammar.y"
    {
  if(!is_in_hash((yyvsp[(1) - (1)].string))){
    yyerror("utilisation d'une variable non déclarée");
  }
  else {
    struct expression_symbol *e = recup_hash((yyvsp[(1) - (1)].string));
    /*if(e->t == ENTIER)
      $$ = create_expression_symbol_int(e->v.n);
    else if(e->t == DOUBL)
      $$ = create_expression_symbol_float(e->v.f);
      $$->var = e->var;*/

    struct expression_symbol *res = expression_symbol_copie(e);
    (yyval.s) = res;
    //$$->code = "";
 }
}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 145 "grammar.y"
    {
  (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (1)].n));
  asprintf(&(yyval.s)->code,"%s%d = add i32 %d,0\n","%x",(yyval.s)->var,(yyvsp[(1) - (1)].n));
  }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 150 "grammar.y"
    {
  (yyval.s) = create_expression_symbol_float((yyvsp[(1) - (1)].f)); // _float, mais en fait double
  asprintf(&(yyval.s)->code,"%s%d = add double %s,0\n","%x",(yyval.s)->var,double_to_hex_str((yyvsp[(1) - (1)].f)));
}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 155 "grammar.y"
    {
  //$$ = NULL; // Not implemented
  (yyval.s) = (yyvsp[(2) - (3)].s);
  //$2->code = "";
}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 161 "grammar.y"
    {
  (yyval.s) = create_expression_symbol_int(0);
}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 164 "grammar.y"
    {
  //$$ = create_expression_symbol_int(0);
  (yyval.s) = (yyvsp[(3) - (4)].s);
  }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 171 "grammar.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 173 "grammar.y"
    {
      (yyval.s) = (yyvsp[(1) - (2)].s);
      if ((yyval.s)->t == ENTIER){
	((yyval.s)->v.n)++;
	//asprintf(&$$->code,"%s%s%d = add i32 %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
	int reg1 = var_name();
	int reg2 = var_name();
	asprintf(&(yyval.s)->code,"%s%s%d = load i32, i32* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[(1) - (2)].s)->var);
	asprintf(&(yyval.s)->code,"%s%s%d = add i32 %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
	asprintf(&(yyval.s)->code,"%s store i32 %s%d, i32* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[(1) - (2)].s)->var);
      }
      else{
	((yyval.s)->v.f)++;
	//asprintf(&$$->code,"%s%s%d = add double %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
	int reg1 = var_name();
	int reg2 = var_name();
	asprintf(&(yyval.s)->code,"%s%s%d = load double, double* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[(1) - (2)].s)->var);
	asprintf(&(yyval.s)->code,"%s%s%d = add double %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
	asprintf(&(yyval.s)->code,"%s store double %s%d, double* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[(1) - (2)].s)->var);
      }
    }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 195 "grammar.y"
    {
      (yyval.s) = (yyvsp[(1) - (2)].s);
      if ((yyval.s)->t == ENTIER){
	((yyval.s)->v.n)--;
	//asprintf(&$$->code,"%s%s%d = sub i32 %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
	int reg1 = var_name();
	int reg2 = var_name();
	asprintf(&(yyval.s)->code,"%s%s%d = load i32, i32* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[(1) - (2)].s)->var);
	asprintf(&(yyval.s)->code,"%s%s%d = sub i32 %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
	asprintf(&(yyval.s)->code,"%s store i32 %s%d, i32* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[(1) - (2)].s)->var);
      }
      else{
	((yyval.s)->v.f)--;
	//asprintf(&$$->code,"%s%s%d = sub double %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
	int reg1 = var_name();
	int reg2 = var_name();
	asprintf(&(yyval.s)->code,"%s%s%d = load  double* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[(1) - (2)].s)->var);
	asprintf(&(yyval.s)->code,"%s%s%d = sub double %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
	asprintf(&(yyval.s)->code,"%s store double %s%d, double* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[(1) - (2)].s)->var);
      }
    }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 219 "grammar.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 221 "grammar.y"
    {
  (yyval.s) = (yyvsp[(1) - (3)].s);
  asprintf(&(yyval.s)->code,"%s %s\n",(yyvsp[(1) - (3)].s)->code,(yyvsp[(3) - (3)].s)->code);
}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 228 "grammar.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 230 "grammar.y"
    {   
  if ((yyvsp[(2) - (2)].s)->t == ENTIER){
  //$$ = create_expression_symbol_int($2->v.n+1);
  //$$->var = $2->var;
    (yyval.s) = (yyvsp[(2) - (2)].s);
    ((yyval.s)->v.n)++;
    //asprintf(&$$->code,"%s%s%d = add i32 %s%d,1\n",$2->code,"%x",$$->var,"%x",$2->var); //pre incrementation
    int reg1 = var_name();
    int reg2 = var_name();
    asprintf(&(yyval.s)->code,"%s%s%d = load i32, i32* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[(2) - (2)].s)->var);
    asprintf(&(yyval.s)->code,"%s%s%d = add i32 %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
    asprintf(&(yyval.s)->code,"%s store i32 %s%d, i32* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[(2) - (2)].s)->var);
  }
  else{
    //$$ = create_expression_symbol_float($2->v.f+1.0);
    //$$->var = $2->var;
    (yyval.s) = (yyvsp[(2) - (2)].s);
    (yyval.s)->v.f++;
    //asprintf(&$$->code,"%s%s%d = add double %s%d,1\n",$$->code,"%x",$$->var,"%x", $2->var);
    int reg1 = var_name();
    int reg2 = var_name();
    asprintf(&(yyval.s)->code,"%s%s%d = load  double* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[(2) - (2)].s)->var);
    asprintf(&(yyval.s)->code,"%s%s%d = add double %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
    asprintf(&(yyval.s)->code,"%s store double %s%d, double* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[(2) - (2)].s)->var);
  }
}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 257 "grammar.y"
    { 
  if ((yyvsp[(2) - (2)].s)->t == ENTIER){
    //$$ = create_expression_symbol_int($2->v.n-1);
    //$$->var = $2->var;
    (yyval.s) = (yyvsp[(2) - (2)].s);
    (yyvsp[(2) - (2)].s)->v.n--;
    //asprintf(&$$->code,"%s%s%d = sub %s%d,1\n",$2->code,"%x",$$->var,"%x",$2->var); //pre incrementation
    int reg1 = var_name();
    int reg2 = var_name();
    asprintf(&(yyval.s)->code,"%s%s%d = load i32, i32* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[(2) - (2)].s)->var);
    asprintf(&(yyval.s)->code,"%s%s%d = sub i32 %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
    asprintf(&(yyval.s)->code,"%s store i32 %s%d, i32* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[(2) - (2)].s)->var);
  }
  else{
    //$$ = create_expression_symbol_float($2->v.f-1.0);
    //$$->var = $2->var;
    (yyval.s) = (yyvsp[(2) - (2)].s);
    (yyval.s)->v.n--;
    //asprintf(&$$->code,"%s%s%d = sub double %s%d,1\n",$$->code,"%x",$$->var,"%x", $2->var);
    int reg1 = var_name();
    int reg2 = var_name();
    asprintf(&(yyval.s)->code,"%s%s%d = load  double* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[(2) - (2)].s)->var);
    asprintf(&(yyval.s)->code,"%s%s%d = sub double %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
    asprintf(&(yyval.s)->code,"%s store double %s%d, double* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[(2) - (2)].s)->var);
  }
}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 284 "grammar.y"
    { 
  if ((yyval.s)->t == ENTIER){ 
    (yyval.s) = create_expression_symbol_int(-((yyvsp[(2) - (2)].s)->v.n));
    (yyval.s)->var = (yyvsp[(2) - (2)].s)->var;
    if (!(yyvsp[(2) - (2)].s)->is_var){
      asprintf(&(yyval.s)->code,"%s %s%d = mul i32 %s%d,-1\n",(yyvsp[(2) - (2)].s)->code,"%x",(yyval.s)->var,"%x",(yyval.s)->var);
    }
    else {
      int reg1 = var_name();
      int reg2 = var_name();
      asprintf(&(yyval.s)->code,"%s%s%d = load i32, i32* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[(2) - (2)].s)->var);
      asprintf(&(yyval.s)->code,"%s%s%d = sub i32 0,%s%d\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
      asprintf(&(yyval.s)->code,"%s store i32 %s%d, i32* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[(2) - (2)].s)->var);
    }
  }
  else{
    (yyval.s) = create_expression_symbol_float(-((yyvsp[(2) - (2)].s)->v.f));
    (yyval.s)->var = (yyvsp[(2) - (2)].s)->var;
    if ((yyvsp[(2) - (2)].s)->is_var){
      asprintf(&(yyval.s)->code,"%s %s%d = fmul double %s%d,-1\n",(yyvsp[(2) - (2)].s)->code,"%x",(yyval.s)->var,"%x",(yyval.s)->var);
    }
    else{
      int reg1 = var_name();
      int reg2 = var_name();
      asprintf(&(yyval.s)->code,"%s%s%d = load double, double* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[(2) - (2)].s)->var);
      asprintf(&(yyval.s)->code,"%s%s%d = sub double 0,%s%d\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
      asprintf(&(yyval.s)->code,"%s store double %s%d, double* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[(2) - (2)].s)->var);
    }
  }
}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 321 "grammar.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 323 "grammar.y"
    {
  asprintf(&(yyval.s)->code,"%s%s",(yyvsp[(1) - (3)].s)->code,(yyvsp[(3) - (3)].s)->code);
  //gestion variable ou pas
  int reg1 = var_name();
  int reg2 = var_name();
  char *s = "";
  int i = 0;
    
  if ((yyvsp[(1) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load  double* %s%d\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(1) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = add double %s%d,0\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
    }
  }

  if ((yyvsp[(3) - (3)].s)->is_var){
    if((yyvsp[(3) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  else {
    if((yyvsp[(3) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = add double %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
    }
  }

  switch(i){
  case 0:
    (yyval.s) = create_expression_symbol_int( ((yyvsp[(1) - (3)].s)->v.n) * ((yyvsp[(3) - (3)].s)->v.n) );
    asprintf(&s, "%s %s%d = add i32 %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  case 1:
    (yyval.s) = create_expression_symbol_float( ((yyvsp[(1) - (3)].s)->v.f) * ((yyvsp[(3) - (3)].s)->v.n) );
    asprintf(&s, "%s %s%d = fmul double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  case 2:
    (yyval.s) = create_expression_symbol_float( ((yyvsp[(1) - (3)].s)->v.n) * ((yyvsp[(3) - (3)].s)->v.f) );
    asprintf(&s, "%s %s%d = fmul double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  default: // case 3
    (yyval.s) = create_expression_symbol_float( ((yyvsp[(1) - (3)].s)->v.f) * ((yyvsp[(3) - (3)].s)->v.f) );
    asprintf(&s, "%s %s%d = fmul double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  }

  //gestion du type
  /*
  if ($1->t == DOUBL)
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float( ($1->v.f) * ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = fmul double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_float( ($1->v.f) * ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = fmul double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
	  
    }
  else
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float( ($1->v.n) * ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = fmul double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_int( ($1->v.n) * ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = mul i32 %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  */
}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 424 "grammar.y"
    {
      asprintf(&(yyval.s)->code,"%s%s",(yyvsp[(1) - (3)].s)->code,(yyvsp[(3) - (3)].s)->code);
      //gestion variable ou pas
      int reg1 = var_name();
      int reg2 = var_name();
      char *s = "";
      int i = 0;
    
      if ((yyvsp[(1) - (3)].s)->is_var){
	if((yyvsp[(1) - (3)].s)->t == DOUBL){
	  asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
	  i++;
	}
	else{
	  asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
	}
      }
      else{
	if((yyvsp[(1) - (3)].s)->t == DOUBL){
	  asprintf(&s,"%s %s%d = add double %s%d,0\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
	  i++;
	}
	else{
	  asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
	}
      }

      if ((yyvsp[(3) - (3)].s)->is_var){
	if((yyvsp[(3) - (3)].s)->t == DOUBL){
	  asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
	  i += 2;
	}
	else{
	  asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
	}
      }
      else {
	if((yyvsp[(3) - (3)].s)->t == DOUBL){
	  asprintf(&s,"%s %s%d = add double %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
	  i += 2;
	}
	else{
	  asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
	}
      }

      switch(i){
      case 0:
	(yyval.s) = create_expression_symbol_int( ((yyvsp[(1) - (3)].s)->v.n) * ((yyvsp[(3) - (3)].s)->v.n) );
	asprintf(&s, "%s %s%d = sdiv i32 %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
	asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
	asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
	break;
      case 1:
	(yyval.s) = create_expression_symbol_float( ((yyvsp[(1) - (3)].s)->v.f) * ((yyvsp[(3) - (3)].s)->v.n) );
	asprintf(&s, "%s %s%d = fdiv double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
	asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
	asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
	break;
      case 2:
	(yyval.s) = create_expression_symbol_float( ((yyvsp[(1) - (3)].s)->v.n) * ((yyvsp[(3) - (3)].s)->v.f) );
	asprintf(&s, "%s %s%d = fdiv double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
	asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
	asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
	break;
      default: // case 3
	(yyval.s) = create_expression_symbol_float( ((yyvsp[(1) - (3)].s)->v.f) * ((yyvsp[(3) - (3)].s)->v.f) );
	asprintf(&s, "%s %s%d = fdiv double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
	asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
	asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
	break;
      }
 
      /*if ($1->t == DOUBL)
        {
	  if ($3->t == DOUBL){
                $$ = create_expression_symbol_float( ($1->v.f) / ($3->v.f));
		asprintf(&$$->code,"%s%s %s%d = fdiv double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	  }
	  else{
                $$ = create_expression_symbol_float( ($1->v.f) / ($3->v.n));
		asprintf(&$$->code,"%s%s %s%d = fdiv double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	  }
        }
        else
        {
	  if ($3->t == DOUBL){
                $$ = create_expression_symbol_float(($1->v.n) / ($3->v.f));
		asprintf(&$$->code,"%s%s %s%d = fdiv double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	  }
	  else{
                $$ = create_expression_symbol_int(($1->v.n) / ($3->v.n));
		asprintf(&$$->code,"%s%s %s%d = sdiv i32 %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
	  }
        }
      */
    }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 522 "grammar.y"
    { // REM = %
  if ((yyvsp[(1) - (3)].s)->t == DOUBL || (yyvsp[(3) - (3)].s)->t == DOUBL)
    yyerror("Erreur de type : modulo pas autorisé avec double");
  else{
    (yyval.s) = create_expression_symbol_int(((yyvsp[(1) - (3)].s)->v.n) % ((yyvsp[(3) - (3)].s)->v.n));
    asprintf(&(yyval.s)->code,"%s%s \n",(yyvsp[(1) - (3)].s)->code,(yyvsp[(3) - (3)].s)->code);
    
    //gestion variable ou pas
    int reg1 = var_name();
    int reg2 = var_name();
    
    if ((yyvsp[(1) - (3)].s)->is_var){
      asprintf(&(yyval.s)->code,"%s %s%d = load i32, i32* %s%d\n", (yyval.s)->code,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code,"%s %s%d = add i32 %s%d,0\n", (yyval.s)->code,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
    }

    if ((yyvsp[(3) - (3)].s)->is_var){
      asprintf(&(yyval.s)->code,"%s %s%d = load i32, i32* %s%d\n", (yyval.s)->code,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);      
    }
    else {
      asprintf(&(yyval.s)->code,"%s %s%d = add i32 %s%d,0\n", (yyval.s)->code,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
    }

    int x1 = var_name();
    int x2 = var_name();
    int x3 = var_name();
    asprintf(&(yyval.s)->code,"%s %s%d = sdiv i32 %s%d,%s%d\n", (yyval.s)->code, "%x", x1, "%x", reg1,"%x", reg2);
    asprintf(&(yyval.s)->code,"%s %s%d = mul i32 %s%d,%s%d\n", (yyval.s)->code, "%x", x2, "%x", x1, "%x", reg2);
    asprintf(&(yyval.s)->code,"%s %s%d = sub i32 %s%d,%s%d\n", (yyval.s)->code, "%x", x3, "%x", reg1, "%x", x2);
    
    /*
      asprintf(&$$->code,"%s %s%d = sdiv i32 %s%d,%s%d\n",$$->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      asprintf(&$$->code,"%s %s%d = mul i32 %s%d,%s%d\n",$$->code,"%x",$3->var,"%x",$3->var,"%x",$$->var);
      asprintf(&$$->code,"%s %s%d = sub i32 %s%d,%s%d\n",$$->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
    */
  }
}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 565 "grammar.y"
    {
  (yyval.s) = (yyvsp[(1) - (1)].s);
}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 569 "grammar.y"
    {
  asprintf(&(yyval.s)->code,"%s%s",(yyvsp[(1) - (3)].s)->code,(yyvsp[(3) - (3)].s)->code);
  //gestion variable ou pas
  int reg1 = var_name();
  int reg2 = var_name();
  char *s = "";
  int i = 0;
    
  if ((yyvsp[(1) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(1) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = add double %s%d,0\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
    }
  }

  if ((yyvsp[(3) - (3)].s)->is_var){
    if((yyvsp[(3) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  else {
    if((yyvsp[(3) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = add double %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
    }
  }

  switch(i){
  case 0:
    (yyval.s) = create_expression_symbol_int( ((yyvsp[(1) - (3)].s)->v.n) * ((yyvsp[(3) - (3)].s)->v.n) );
    asprintf(&s, "%s %s%d = add i32 %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  case 1:
    (yyval.s) = create_expression_symbol_float( ((yyvsp[(1) - (3)].s)->v.f) * ((yyvsp[(3) - (3)].s)->v.n) );
    asprintf(&s, "%s %s%d = add double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  case 2:
    (yyval.s) = create_expression_symbol_float( ((yyvsp[(1) - (3)].s)->v.n) * ((yyvsp[(3) - (3)].s)->v.f) );
    asprintf(&s, "%s %s%d = add double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  default: // case 3
    (yyval.s) = create_expression_symbol_float( ((yyvsp[(1) - (3)].s)->v.f) * ((yyvsp[(3) - (3)].s)->v.f) );
    asprintf(&s, "%s %s%d = add double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  }
  /*
  if ($1->t == DOUBL)
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.f) + ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = add double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_float(($1->v.f) + ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = add double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  else
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.n) + ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = add double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_int(($1->v.n) + ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = add i32 %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  */
}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 667 "grammar.y"
    {
  asprintf(&(yyval.s)->code,"%s%s",(yyvsp[(1) - (3)].s)->code,(yyvsp[(3) - (3)].s)->code);
  //gestion variable ou pas
  int reg1 = var_name();
  int reg2 = var_name();
  char *s = "";
  int i = 0;
    
  if ((yyvsp[(1) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(1) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = add double %s%d,0\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg1,"%x", (yyvsp[(1) - (3)].s)->var);
    }
  }

  if ((yyvsp[(3) - (3)].s)->is_var){
    if((yyvsp[(3) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  else {
    if((yyvsp[(3) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = add double %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
    }
  }

  switch(i){
  case 0:
    (yyval.s) = create_expression_symbol_int( ((yyvsp[(1) - (3)].s)->v.n) * ((yyvsp[(3) - (3)].s)->v.n) );
    asprintf(&s, "%s %s%d = sub i32 %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  case 1:
    (yyval.s) = create_expression_symbol_float( ((yyvsp[(1) - (3)].s)->v.f) * ((yyvsp[(3) - (3)].s)->v.n) );
    asprintf(&s, "%s %s%d = sub double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  case 2:
    (yyval.s) = create_expression_symbol_float( ((yyvsp[(1) - (3)].s)->v.n) * ((yyvsp[(3) - (3)].s)->v.f) );
    asprintf(&s, "%s %s%d = sub double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  default: // case 3
    (yyval.s) = create_expression_symbol_float( ((yyvsp[(1) - (3)].s)->v.f) * ((yyvsp[(3) - (3)].s)->v.f) );
    asprintf(&s, "%s %s%d = sub double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  }
  /*
  if ($1->t == DOUBL)
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.f) - ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = sub double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_float(($1->v.f) - ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = sub double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  else
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.n) - ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = sub double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_int(($1->v.n) - ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = sub i32 %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  */
}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 768 "grammar.y"
    {
  (yyval.s) = (yyvsp[(1) - (1)].s);
}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 772 "grammar.y"
    {
  if ((yyvsp[(1) - (3)].s)->t == ENTIER && (yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n < (yyvsp[(3) - (3)].s)->v.n);
  }
  else if((yyvsp[(1) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n < (yyvsp[(3) - (3)].s)->v.f);
  }
  else if((yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f < (yyvsp[(3) - (3)].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f < (yyvsp[(3) - (3)].s)->v.f);
  }
  
  asprintf(&(yyval.s)->code, "%s%s", (yyvsp[(1) - (3)].s)->code, (yyvsp[(3) - (3)].s)->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if((yyvsp[(1) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  
  if((yyvsp[(3) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(3) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  
  int reg3 = var_name();

  asprintf(&(yyval.s)->code, "%s %s%d = icmp slt %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg2);
  (yyval.s)->var = reg3;
  (yyval.s)->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 834 "grammar.y"
    {
  if ((yyvsp[(1) - (3)].s)->t == ENTIER && (yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n > (yyvsp[(3) - (3)].s)->v.n);
  }
  else if((yyvsp[(1) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n > (yyvsp[(3) - (3)].s)->v.f);
  }
  else if((yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f > (yyvsp[(3) - (3)].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f > (yyvsp[(3) - (3)].s)->v.f);
  }
  
  asprintf(&(yyval.s)->code, "%s%s", (yyvsp[(1) - (3)].s)->code, (yyvsp[(3) - (3)].s)->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if((yyvsp[(1) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  
  if((yyvsp[(3) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(3) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  
  int reg3 = var_name();

  asprintf(&(yyval.s)->code, "%s %s%d = icmp sgt %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg2);
  (yyval.s)->var = reg3;
  (yyval.s)->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 896 "grammar.y"
    {
  if ((yyvsp[(1) - (3)].s)->t == ENTIER && (yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n <= (yyvsp[(3) - (3)].s)->v.n);
  }
  else if((yyvsp[(1) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n <= (yyvsp[(3) - (3)].s)->v.f);
  }
  else if((yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f <= (yyvsp[(3) - (3)].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f <= (yyvsp[(3) - (3)].s)->v.f);
  }

    asprintf(&(yyval.s)->code, "%s%s", (yyvsp[(1) - (3)].s)->code, (yyvsp[(3) - (3)].s)->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if((yyvsp[(1) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  
  if((yyvsp[(3) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(3) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  
  int reg3 = var_name();

  asprintf(&(yyval.s)->code, "%s %s%d = icmp sle %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg2);
  (yyval.s)->var = reg3;
  (yyval.s)->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 958 "grammar.y"
    {
  if ((yyvsp[(1) - (3)].s)->t == ENTIER && (yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n >= (yyvsp[(3) - (3)].s)->v.n);
  }
  else if((yyvsp[(1) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n >= (yyvsp[(3) - (3)].s)->v.f);
  }
  else if((yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f >= (yyvsp[(3) - (3)].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f >= (yyvsp[(3) - (3)].s)->v.f);
  }
  
    asprintf(&(yyval.s)->code, "%s%s", (yyvsp[(1) - (3)].s)->code, (yyvsp[(3) - (3)].s)->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if((yyvsp[(1) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  
  if((yyvsp[(3) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(3) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  
  int reg3 = var_name();

  asprintf(&(yyval.s)->code, "%s %s%d = icmp sge %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg2);
  (yyval.s)->var = reg3;
  (yyval.s)->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 1020 "grammar.y"
    {
  if ((yyvsp[(1) - (3)].s)->t == ENTIER && (yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n == (yyvsp[(3) - (3)].s)->v.n);
  }
  else if((yyvsp[(1) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n == (yyvsp[(3) - (3)].s)->v.f);
  }
  else if((yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f == (yyvsp[(3) - (3)].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f == (yyvsp[(3) - (3)].s)->v.f);
  }

    asprintf(&(yyval.s)->code, "%s%s", (yyvsp[(1) - (3)].s)->code, (yyvsp[(3) - (3)].s)->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if((yyvsp[(1) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  
  if((yyvsp[(3) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(3) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  
  int reg3 = var_name();

  asprintf(&(yyval.s)->code, "%s %s%d = icmp eq %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg2);
  (yyval.s)->var = reg3;
  (yyval.s)->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 1082 "grammar.y"
    {
  if ((yyvsp[(1) - (3)].s)->t == ENTIER && (yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n != (yyvsp[(3) - (3)].s)->v.n);
  }
  else if((yyvsp[(1) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.n != (yyvsp[(3) - (3)].s)->v.f);
  }
  else if((yyvsp[(3) - (3)].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f != (yyvsp[(3) - (3)].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[(1) - (3)].s)->v.f != (yyvsp[(3) - (3)].s)->v.f);
  }
  
    asprintf(&(yyval.s)->code, "%s%s", (yyvsp[(1) - (3)].s)->code, (yyvsp[(3) - (3)].s)->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if((yyvsp[(1) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    }
  }
  
  if((yyvsp[(3) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  else{
    if((yyvsp[(3) - (3)].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = add double %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  
  int reg3 = var_name();

  asprintf(&(yyval.s)->code, "%s %s%d = icmp ne %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg2);
  (yyval.s)->var = reg3;
  (yyval.s)->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 1147 "grammar.y"
    {
  //asprintf(&$$->code,"%s%s",$1->code,$3->code);
  //gestion variable ou pas
  int reg1 = var_name();
  int reg2 = var_name();
  char *s = "";
  int i = 0;
    
  if ((yyvsp[(1) - (3)].s)->is_var){
    if((yyvsp[(1) - (3)].s)->t == DOUBL){
      i++;
    }
  }
  else{
    if((yyvsp[(1) - (3)].s)->t == DOUBL){
      i++;
    }
  }

  if ((yyvsp[(3) - (3)].s)->is_var){
    if((yyvsp[(3) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
    }
  }
  else {
    if((yyvsp[(3) - (3)].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = add double %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[(3) - (3)].s)->var);
    }
  }

  // TODO : case 1, 2, default
  
  switch(i){
  case 0:
    (yyvsp[(1) - (3)].s)->v.n = (yyvsp[(3) - (3)].s)->v.n;
    (yyval.s) = (yyvsp[(1) - (3)].s);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyvsp[(3) - (3)].s)->code, s);
    asprintf(&(yyval.s)->code, "%s store i32 %s%d, i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(1) - (3)].s)->var);
    break;
  case 1:
    (yyvsp[(1) - (3)].s)->v.f = (yyvsp[(3) - (3)].s)->v.n;
    (yyval.s) = (yyvsp[(1) - (3)].s);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyvsp[(3) - (3)].s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = fptosi double %s%d to i32\n",(yyval.s)->code, "%x", reg1, "%x",reg2);
    asprintf(&(yyval.s)->code, "%s store i32 %s%d, i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[(1) - (3)].s)->var);
    break;
  case 2:
    (yyvsp[(1) - (3)].s)->v.n = (yyvsp[(3) - (3)].s)->v.f;
    (yyval.s) = (yyvsp[(1) - (3)].s);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyvsp[(3) - (3)].s)->code, s);
    //asprintf(&$$->code, "%s %s%d =",);
    asprintf(&(yyval.s)->code, "%s store i32 %s%d, i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(1) - (3)].s)->var);
    break;
  default: // case 3
    (yyvsp[(1) - (3)].s)->v.f = (yyvsp[(3) - (3)].s)->v.f;
    (yyval.s) = (yyvsp[(1) - (3)].s);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyvsp[(3) - (3)].s)->code, s);
    asprintf(&(yyval.s)->code, "%s store i32 %s%d, i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[(1) - (3)].s)->var);
    break;
  }
  /*
  if ($2 == ASSIGN){
    if ($1->t == ENTIER && $3->t == ENTIER){
      $1->v.n = $3->v.n;
      asprintf(&$$->code,"%s store i32 %s%d, i32* %s%d\n",$3->code,"%x",$1->var,"%x",$3->var);
      $$ = $1; 
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
      $1->v.n = $3->v.f;      
      asprintf(&$$->code,"%s %s%d = sitofp i32 %s%d to double\n",$3->code,"%x",$1->var,"%x",$3->var);
      $$ = $1;
      printf("ATTENTION: affectation d'un DOUBLE à une variable de type ENTIER sans conversion\n");
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
      $1->v.f = $3->v.n;
      asprintf(&$$->code,"%s %s%d = fptosi double %s%d to i32\n",$3->code,"%x",$1->var,"%x",$3->var);
      $$ = $1;
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
      $1->v.f = $3->v.f;
      asprintf(&$$->code,"%s %s%d = add double %s%d,0\n",$3->code,"%x",$1->var,"%x",$3->var);
      $$ = $1;
    }
  */
  
  /* pas demandé dans le sujet !!


  else if ($2 == ASSIGN_MUL){
    if ($1->t == ENTIER && $3->t == ENTIER){
      $1->v.n *= $3->v.n;
      $$ = $3;
      asprintf(&$$->code,"%s %s%d = mul i32 %s%d,%s%d\n",$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
  }
  else if ($2 == ASSIGN_DIV){
    if ($1->t == ENTIER && $3->t == ENTIER){
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
  }
  else if ($2 == ASSIGN_REM){
    if ($1->t == ENTIER && $3->t == ENTIER){
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
  }
  else if ($2 == ASSIGN_SHL){
    if ($1->t == ENTIER && $3->t == ENTIER){
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
  }
  else if ($2 == ASSIGN_SHR){
    if ($1->t == ENTIER && $3->t == ENTIER){
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
  }
  else if ($2 == ASSIGN_ADD){
    if ($1->t == ENTIER && $3->t == ENTIER){
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
  }
  else if ($2 == ASSIGN_SUB){
    if ($1->t == ENTIER && $3->t == ENTIER){
    }
    else if ($1->t == ENTIER && $3->t == DOUBL){
    }
    else if ($1->t == DOUBL && $3->t == ENTIER){
    }
    else if ($1->t == DOUBL && $3->t == DOUBL){
    }
    }*/
}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 1317 "grammar.y"
    {(yyval.s) = (yyvsp[(1) - (1)].s);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 1321 "grammar.y"
    {(yyval.n) = ASSIGN;}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 1322 "grammar.y"
    {(yyval.n) = ASSIGN_MUL;}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 1323 "grammar.y"
    {(yyval.n) = ASSIGN_DIV;}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 1324 "grammar.y"
    {(yyval.n) = ASSIGN_REM;}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 1325 "grammar.y"
    {(yyval.n) = ASSIGN_SHL;}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 1326 "grammar.y"
    {(yyval.n) = ASSIGN_SHR;}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 1327 "grammar.y"
    {(yyval.n) = ASSIGN_ADD;}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 1328 "grammar.y"
    {(yyval.n) = ASSIGN_SUB;}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 1333 "grammar.y"
    {
  int i;
  ENTRY e, *ep;
  
  for (i = 0; i < nb_declarators ; i++){

    // Erreur declaration : void var;
    if (liste_declarators[i]->d == VAR) {

      if((yyvsp[(1) - (3)].t) == VIDE){

	yyerror("Erreur : la variable suivante est de type void :");
	printf("%s\n", liste_declarators[i]->nom);
	
      } else {
	// Si pas d'erreur de declaration, on rentre la variable dans la hash table.
	
	e.key = liste_declarators[i]->nom;
	struct expression_symbol *v = create_expression_symbol_general((yyvsp[(1) - (3)].t), level);
	e.data = (void *) v;
	
	// On verifie que la variable a pas ete deja declaree <=> variable deja presente dans la hash table avec un niveau inferieur
	ep = hsearch(e, FIND);
	
	if( ep != NULL && ((struct expression_symbol *)(ep->data))->lvl <= v->lvl){
	  yyerror("Erreur : la variable suivante est deja declaree : ");
	  printf("%s\n", e.key);
	} else {
	  // Si pas d'erreur, on l'ajoute, et on remplace l'ancienne variable si elle a ete declaree a un niveau superieur (cela veut dire qu'on est sorti de ce niveau, la variable n'est plus dans la pile)
	  
	  ep = hsearch(e, ENTER);
	}
	if (ep == NULL) {
	  fprintf(stderr, "hash table : entry failed\n");
	  exit(EXIT_FAILURE);
	} else {
	  if(v->t == ENTIER)
	    asprintf(&(yyval.string), "%s%d = alloca i32\n", "%x", v->var);
	  else if(v->t == DOUBL)
	    asprintf(&(yyval.string), "%s%d = alloca double\n", "%x", v->var);
	}
      }
    }
      
    
    // Erreur declaration : void f(), n ,...;
    if( liste_declarators[i]->d == FONCTION && nb_declarators > 1){
      yyerror("Erreur : la fonction suivante doit etre declaree individuellement :");
      printf("%s\n", liste_declarators[i]->nom);
    }

  }

  printf("\n");

  for (i = 0; i < nb_declarators; i++){
    e.key = liste_declarators[i]->nom;
    ep = hsearch(e, FIND);

    if(ep != NULL){

      struct expression_symbol *v = (struct expression_symbol *) (ep->data);
      printf("nom : %s \t type : %s \t level : %d\n", ep->key, get_expression_symbol_type(v), v->lvl);
    }
  }

  // Declaration finie, on réinitialise le nombre de declarators.
  nb_declarators = 0;
}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 1406 "grammar.y"
    { 
  nb_declarators++;
  liste_declarators[nb_declarators-1] = (yyvsp[(1) - (1)].d);
}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 1411 "grammar.y"
    {
  nb_declarators++;
  liste_declarators[nb_declarators-1] = (yyvsp[(3) - (3)].d);
}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 1419 "grammar.y"
    { (yyval.t) = VIDE; }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 1421 "grammar.y"
    { (yyval.t) = ENTIER; }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 1423 "grammar.y"
    { (yyval.t) = DOUBL; }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 1428 "grammar.y"
    {
  (yyval.d) = create_declarator(VAR, (yyvsp[(1) - (1)].string));
  printf("Identifier : %s\n",(yyvsp[(1) - (1)].string));  
}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 1433 "grammar.y"
    {
  (yyval.d) = create_declarator(VAR, (yyvsp[(2) - (3)].d)->nom);
}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 1437 "grammar.y"
    {
  (yyval.d) = create_declarator(FONCTION, (yyvsp[(1) - (4)].d)->nom);
}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 1441 "grammar.y"
    { 
  (yyval.d) = create_declarator(FONCTION, (yyvsp[(1) - (3)].d)->nom);
}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 1453 "grammar.y"
    {
  // Erreur parametre : void arg;
  if( (yyvsp[(1) - (2)].t) == VIDE && (yyvsp[(2) - (2)].d)->d == VAR){
    yyerror("Erreur : l'argument suivant est de type void :");
    printf("%s\n", (yyvsp[(2) - (2)].d)->nom); 
  }
}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 1463 "grammar.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 1464 "grammar.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 1465 "grammar.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 1466 "grammar.y"
    {(yyval.string) = "";}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 1467 "grammar.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 1472 "grammar.y"
    {(yyval.string) = (yyvsp[(2) - (3)].string);}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 1473 "grammar.y"
    {asprintf(&(yyval.string),"%s%s",(yyvsp[(2) - (4)].string),(yyvsp[(3) - (4)].string));}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 1474 "grammar.y"
    {(yyval.string) = (yyvsp[(2) - (3)].string);}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 1478 "grammar.y"
    { level++; }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 1483 "grammar.y"
    {
  level--;
  
  if(level == 0){
    hdestroy();
    hcreate(MAX_VAR);
  }
}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 1494 "grammar.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 1495 "grammar.y"
    {asprintf(&(yyval.string),"%s%s",(yyvsp[(1) - (2)].string),(yyvsp[(2) - (2)].string));}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 1499 "grammar.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 1500 "grammar.y"
    {asprintf(&(yyval.string),"%s%s",(yyvsp[(1) - (2)].string),(yyvsp[(2) - (2)].string));}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 1504 "grammar.y"
    {(yyval.string) = '\0';}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 1505 "grammar.y"
    {(yyval.string) = (yyvsp[(1) - (2)].s)->code;}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 1510 "grammar.y"
    {
  (yyval.string) = "";
  //printf("code:%s\nreg:%d\n",$3->code,$3->var);
  int cond = var_name();
  int label = var_name();
  if ((yyvsp[(3) - (5)].s)->is_var){
    asprintf(&(yyval.string),"%s%s%d = load i32, i32* %s%d\n","%x",(yyvsp[(3) - (5)].s)->code,label,"%x",(yyvsp[(3) - (5)].s)->var);
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",label);
  }
  else{
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyvsp[(3) - (5)].s)->code,"%x",cond,"%x",(yyvsp[(3) - (5)].s)->var);
  } 
  asprintf(&(yyval.string),"%s br i1 %s%d, label %s%d, label %s%d\n",(yyval.string),"%x",cond,"%then",label,"%endif",label);
  asprintf(&(yyval.string),"%s then%d:\n %s br label %s%d\n",(yyval.string),label,(yyvsp[(5) - (5)].string),"%endif",label);
  asprintf(&(yyval.string),"%s endif%d:\n",(yyval.string),label);
}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 1527 "grammar.y"
    {
  (yyval.string) = "";
  int cond = var_name();
  int label = var_name();
  //  asprintf(&$$,"\n\n\n Objet du délit : \n %s\n\n\n\n",$3->code);
  if ((yyvsp[(3) - (7)].s)->is_var){
  asprintf(&(yyval.string),"%s%s%d = load i32, i32* %s%d\n","%x",(yyvsp[(3) - (7)].s)->code,label,"%x",(yyvsp[(3) - (7)].s)->var);
  asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",label);
  }
  else{
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyvsp[(3) - (7)].s)->code,"%x",cond,"%x",(yyvsp[(3) - (7)].s)->var);
  } 
  asprintf(&(yyval.string),"%s br i1 %s%d, label %s%d, label %s%d\n",(yyval.string),"%x",cond,"%then",label,"%else",label);
  asprintf(&(yyval.string),"%s then%d:\n %s br label %s%d\n",(yyval.string),label,(yyvsp[(5) - (7)].string),"%endif",label);
  asprintf(&(yyval.string),"%s else%d:\n %s br label %s%d\n",(yyval.string),label,(yyvsp[(7) - (7)].string),"%endif",label);
  asprintf(&(yyval.string),"%s endif%d:\n",(yyval.string),label);
}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 1545 "grammar.y"
    {
  // debugage
  int cond = var_name();
  int label = var_name();
  // initialisation
  (yyval.string) = (yyvsp[(3) - (9)].s)->code;

  // test condition
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); //saut à la ligne en dessous
  asprintf(&(yyval.string),"%s condfor%d:\n",(yyval.string),label); // label

  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[(5) - (9)].s)->code); // code de la condition

  if ((yyvsp[(5) - (9)].s)->is_var){ // si est variable il faut faire un load
    asprintf(&(yyval.string),"%s%s%d = load i32, i32* %s%d\n",(yyval.string),"%x",label,"%x",(yyvsp[(5) - (9)].s)->var);
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",label);
  }
  else{ // si constante pas de pb
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",(yyvsp[(5) - (9)].s)->var);
  } 

  asprintf(&(yyval.string),"%s br i1 %s%d, label %s%d, label %s%d\n",(yyval.string),"%x",cond,"%bodyfor",label,"%endfor",label); // test condition
  
  // contenu for
  asprintf(&(yyval.string),"%s bodyfor%d:\n",(yyval.string),label); // label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[(9) - (9)].string)); // code du corps du for
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%incfor",label); // jump -> expression
  
  //expression
  asprintf(&(yyval.string),"%s incfor%d:\n",(yyval.string),label);// label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[(7) - (9)].s)->code); // code de l'expression
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); // jump -> condition
  // sortie de boucle
  asprintf(&(yyval.string),"%s endfor%d:\n\n",(yyval.string),label); // label
}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 1580 "grammar.y"
    {(yyval.string) = "";}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 1581 "grammar.y"
    {(yyval.string) = "";}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 1582 "grammar.y"
    {(yyval.string) = "";}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 1583 "grammar.y"
    {(yyval.string) = "";}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 1584 "grammar.y"
    {(yyval.string) = "";}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 1585 "grammar.y"
    {(yyval.string) = "";}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 1586 "grammar.y"
    {(yyval.string) = "";}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 1595 "grammar.y"
    {(yyval.string) = "ret void\n";}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 1597 "grammar.y"
    { if ((yyvsp[(2) - (3)].s)->t == ENTIER){
    if((yyvsp[(2) - (3)].s)->is_var){
      int reg = var_name();
      asprintf(&(yyval.string),"%s %s%d = load i32, i32* %s%d\n",(yyvsp[(2) - (3)].s)->code,"%x",reg,"%x",(yyvsp[(2) - (3)].s)->var);
      asprintf(&(yyval.string),"%s ret i32 %s%d\n",(yyval.string),"%x",reg);
    }
    else{
      asprintf(&(yyval.string),"ret i32 %d",(yyvsp[(2) - (3)].s)->v.n);
    }
  }
  else if((yyvsp[(2) - (3)].s)->t == DOUBL){
    if((yyvsp[(2) - (3)].s)->is_var){
      int reg = var_name();
      asprintf(&(yyval.string),"%s %s%d = load double, double* %s%d\n",(yyvsp[(2) - (3)].s)->code,"%x",reg,"%x",(yyvsp[(2) - (3)].s)->var);
      asprintf(&(yyval.string),"%s ret double %s%d\n",(yyval.string),"%x",reg);
    }
    else{
    asprintf(&(yyval.string),"ret double %lf",(yyvsp[(2) - (3)].s)->v.f);
    }
  }
  else if ((yyvsp[(2) - (3)].s)->t == VIDE){
    (yyval.string) = "ret void\n";
  }
}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 1625 "grammar.y"
    {
  FILE* fichier = fopen("test_llvm.ll","w+");
  fprintf(fichier,"%s",(yyvsp[(1) - (1)].string));
  fclose(fichier);
}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 1632 "grammar.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 1633 "grammar.y"
    {asprintf(&(yyval.string),"%s%s",(yyvsp[(1) - (2)].string),(yyvsp[(2) - (2)].string));}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 1637 "grammar.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 1638 "grammar.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 1643 "grammar.y"
    {
  char *type;
  if ((yyvsp[(1) - (3)].t) == ENTIER)
    type = "i32";
  else if((yyvsp[(1) - (3)].t) == DOUBL)
    type = "double";
  else if ((yyvsp[(1) - (3)].t) == VIDE)
    type = "void";
  asprintf(&(yyval.string),"define %s @%s(){\n %s \n}\n",type,(yyvsp[(2) - (3)].d)->nom,(yyvsp[(3) - (3)].string));
}
    break;


/* Line 1792 of yacc.c  */
#line 3487 "grammar.c"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 1655 "grammar.y"

#include <stdio.h>
#include <string.h>

#define MAX_VAR 1024

extern char yytext[];
extern int column;
extern int yylineno;
extern FILE *yyin;

char *file_name = NULL;

int yyerror (char *s) {
    fflush (stdout);
    fprintf (stderr, "%s:%d:%d: %s\n", file_name, yylineno, column, s);
    return 0;
}


int main (int argc, char *argv[]) {
    FILE *input = NULL;
    if (argc==2) {
	input = fopen (argv[1], "r");
	file_name = strdup (argv[1]);
	if (input) {
	    yyin = input;
	}
	else {
	  fprintf (stderr, "%s: Could not open %s\n", *argv, argv[1]);
	    return 1;
	}
    }
    else {
	fprintf (stderr, "%s: error: no input file\n", *argv);
	return 1;
    }

    hcreate(MAX_VAR);
    
    yyparse ();
    free (file_name);
    return 0;
}
