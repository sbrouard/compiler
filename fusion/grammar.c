/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "grammar.y" /* yacc.c:339  */

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

   enum simple_type liste_parametres[16];
   int nb_parametres = 0;

#line 100 "grammar.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 53 "grammar.y" /* yacc.c:355  */

  char *string;
  int n;
  double f;
  enum simple_type t;
  struct declarator *d;
  struct expression_symbol *s;
  //struct expression expr;

#line 184 "grammar.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "grammar.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    69,    70,    89,    90,   177,   193,   194,
     198,   216,   220,   225,   231,   235,   242,   243,   265,   290,
     291,   299,   300,   327,   354,   388,   392,   393,   494,   600,
     643,   647,   745,   846,   850,   930,  1013,  1096,  1180,  1242,
    1307,  1478,  1482,  1483,  1484,  1485,  1486,  1487,  1488,  1489,
    1493,  1582,  1587,  1595,  1597,  1599,  1604,  1609,  1613,  1617,
    1624,  1630,  1639,  1657,  1658,  1659,  1660,  1661,  1665,  1666,
    1667,  1668,  1672,  1676,  1688,  1689,  1693,  1694,  1698,  1699,
    1703,  1720,  1738,  1774,  1808,  1825,  1840,  1873,  1903,  1917,
    1933,  1966,  2008,  2009,  2037,  2045,  2046,  2050,  2051,  2055
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
  "external_declaration", "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    40,    41,    44,    45,    42,    47,
      43,    60,    62,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -58

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -58,   -58,   -58,   -58,     3,    17,     4,   -58,   -58,
     -58,     3,   -16,   -18,   -58,   -58,    22,     3,   -58,    61,
     -58,   -58,   142,   -58,   -13,   -58,     3,    54,   -58,   -10,
     -58,   -58,   273,   273,    -2,   196,     2,    76,     7,   273,
     -58,   -58,   -58,   -58,    31,    37,    83,   -58,    99,   280,
     273,    -5,   -22,    36,    41,   -58,     3,   -58,   -58,   -58,
     142,   177,   -58,   -58,   -58,   -58,   -13,   -58,     4,     5,
     -58,   -58,   273,    30,   273,   -58,    64,    88,    77,   273,
     273,   273,   273,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   273,   -58,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   -58,   -13,   -58,   -58,
     177,   -58,   -58,   -58,   -58,    79,   -58,    86,    84,    91,
     -58,   212,    90,   -58,    37,   -58,    36,   -22,   -22,   -58,
     -58,   -58,   -58,    -5,    -5,    83,    83,    83,    83,    83,
      83,   -58,   -58,   273,   196,   273,   196,   155,    93,   231,
     -58,    94,   115,   -58,   196,   116,   247,   254,   108,   196,
     -58,   -58,   196,   196,   119,   196,   120,   266,   -58,   -58,
     -58,   196,   -58,   196,   196,   121,   -58,   -58,   -58,   196,
     -58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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
      35,    70,    15,     0,     0,     0,     0,     0,     0,     0,
      20,    80,     0,    90,     0,     0,     0,     0,     0,     0,
      91,    89,     0,     0,     0,     0,     0,     0,    81,    88,
      87,     0,    85,     0,     0,     0,    86,    84,    83,     0,
      82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,    70,   -58,    78,    -3,   -58,   -58,   -58,   -31,   -58,
      18,    59,    85,   -14,   -58,   -17,   -58,    16,    -4,   -58,
      96,   -35,   153,   -58,   -57,   -58,   111,   -58,   -58,   -58,
     -58,   -58,   -58,   170,   -58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    43,    44,    45,    46,    47,    48,   115,    49,    50,
      51,    52,    53,    54,    93,     4,    12,     5,    13,    27,
      28,    57,    58,    22,    59,    60,    61,    62,    63,    64,
      65,     6,     7,     8,     9
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      73,    70,    71,   109,   112,    55,    10,    16,    29,    30,
      31,    32,    33,    24,    95,    98,    19,    14,    99,    94,
      17,    19,    66,    76,    69,    78,   111,    20,    18,     1,
       2,     3,    72,    96,    97,    26,    74,    11,    56,    39,
     114,    77,    40,   108,   100,   101,   102,   103,   125,   125,
     125,   125,   107,   141,    79,   116,    19,    23,   117,    80,
     119,   118,   125,   122,   130,   131,   132,   125,   125,   125,
     125,   125,   125,   125,   125,   111,    56,   104,   105,    29,
      30,    31,    32,    33,    26,   106,     1,     2,     3,    67,
      68,    29,    30,    31,    32,    33,    25,   135,   136,   137,
     138,   139,   140,    81,    82,    83,    84,   148,   120,   151,
      39,   153,   123,    40,   142,   143,   133,   134,   145,   161,
      75,   144,    39,   159,   168,    40,   146,   169,   170,   150,
     172,   152,   121,   155,   149,   158,   176,   156,   177,   178,
     127,   128,   164,   166,   180,    29,    30,    31,    32,    33,
     160,   162,   167,   175,   171,   173,   179,   124,    29,    30,
      31,    32,    33,   129,   113,   126,    21,     1,     2,     3,
      34,   110,    35,    36,    37,    38,    39,    15,     0,    40,
      29,    30,    31,    32,    33,     0,    41,    20,    42,    39,
     154,     0,    40,     0,     0,     0,     0,     0,     0,    29,
      30,    31,    32,    33,     0,    34,     0,    35,    36,    37,
      38,    39,     0,     0,    40,    29,    30,    31,    32,    33,
       0,    41,    20,    42,    34,     0,    35,    36,    37,    38,
      39,     0,     0,    40,    29,    30,    31,    32,    33,     0,
      41,    20,     0,     0,     0,     0,    39,     0,     0,    40,
      29,    30,    31,    32,    33,     0,   147,    29,    30,    31,
      32,    33,     0,     0,     0,    39,     0,     0,    40,    29,
      30,    31,    32,    33,     0,   157,    29,    30,    31,    32,
      33,    39,   163,     0,    40,     0,     0,     0,    39,   165,
       0,    40,    85,    86,    87,    88,    89,    90,    91,     0,
      39,   174,     0,    40,     0,     0,     0,    39,     0,     0,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92
};

static const yytype_int16 yycheck[] =
{
      35,    32,    33,    60,    61,    22,     3,    11,     3,     4,
       5,     6,     7,    17,    19,    37,    34,     0,    40,    50,
      36,    34,    26,    37,    34,    39,    61,    45,    44,    25,
      26,    27,    34,    38,    39,    19,    34,    34,    22,    34,
      35,    34,    37,    60,     8,     9,    10,    11,    79,    80,
      81,    82,    56,   110,    23,    69,    34,    35,    72,    22,
      74,    31,    93,    77,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   110,    60,    41,    42,     3,
       4,     5,     6,     7,    68,    44,    25,    26,    27,    35,
      36,     3,     4,     5,     6,     7,    35,   100,   101,   102,
     103,   104,   105,    20,    21,     6,     7,   121,    44,   144,
      34,   146,    35,    37,    35,    36,    98,    99,    34,   154,
      44,    35,    34,    29,   159,    37,    35,   162,   163,   143,
     165,   145,    44,   147,    44,   149,   171,    44,   173,   174,
      81,    82,   156,   157,   179,     3,     4,     5,     6,     7,
      35,    35,    44,   167,    35,    35,    35,    79,     3,     4,
       5,     6,     7,    93,    68,    80,    13,    25,    26,    27,
      28,    60,    30,    31,    32,    33,    34,     7,    -1,    37,
       3,     4,     5,     6,     7,    -1,    44,    45,    46,    34,
      35,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    28,    -1,    30,    31,    32,
      33,    34,    -1,    -1,    37,     3,     4,     5,     6,     7,
      -1,    44,    45,    46,    28,    -1,    30,    31,    32,    33,
      34,    -1,    -1,    37,     3,     4,     5,     6,     7,    -1,
      44,    45,    -1,    -1,    -1,    -1,    34,    -1,    -1,    37,
       3,     4,     5,     6,     7,    -1,    44,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    34,    -1,    -1,    37,     3,
       4,     5,     6,     7,    -1,    44,     3,     4,     5,     6,
       7,    34,    35,    -1,    37,    -1,    -1,    -1,    34,    35,
      -1,    37,    12,    13,    14,    15,    16,    17,    18,    -1,
      34,    35,    -1,    37,    -1,    -1,    -1,    34,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43
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
      60,    68,    60,    68,    35,    60,    44,    44,    60,    29,
      35,    68,    35,    35,    60,    35,    60,    44,    68,    68,
      68,    35,    68,    35,    35,    60,    68,    68,    68,    35,
      68
};

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
      76,    76,    77,    77,    78,    79,    79,    80,    80,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
       5,     6,     2,     3,     1,     1,     2,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
        case 2:
#line 65 "grammar.y" /* yacc.c:1646  */
    {(yyval.s) = (yyvsp[0].s);}
#line 1439 "grammar.c" /* yacc.c:1646  */
    break;

  case 3:
#line 69 "grammar.y" /* yacc.c:1646  */
    {(yyval.s) = (yyvsp[0].s);}
#line 1445 "grammar.c" /* yacc.c:1646  */
    break;

  case 4:
#line 71 "grammar.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n || (yyvsp[0].s)->v.n);
  }
  else if ((yyvsp[-2].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n || (yyvsp[0].s)->v.f);
  }
  else if ((yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f || (yyvsp[0].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f || (yyvsp[0].s)->v.f);
  }
  asprintf(&(yyval.s)->code,"%s%s %s%d = add i32 %d,0\n",(yyvsp[-2].s)->code,(yyvsp[0].s)->code,"%x",(yyval.s)->var,(yyval.s)->v.n);
}
#line 1465 "grammar.c" /* yacc.c:1646  */
    break;

  case 5:
#line 89 "grammar.y" /* yacc.c:1646  */
    {(yyval.s) = (yyvsp[0].s);}
#line 1471 "grammar.c" /* yacc.c:1646  */
    break;

  case 6:
#line 91 "grammar.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n && (yyvsp[0].s)->v.n);
  }
  else if ((yyvsp[-2].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n && (yyvsp[0].s)->v.f);
  }
  else if ((yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f && (yyvsp[0].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f && (yyvsp[0].s)->v.f);
  }

  asprintf(&(yyval.s)->code, "%s%s", (yyvsp[-2].s)->code, (yyvsp[0].s)->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if((yyvsp[-2].s)->is_var){
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32, i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double, double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  else{
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  
  if((yyvsp[0].s)->is_var){
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32, i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double, double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }
  else{
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }
  
  int reg3 = var_name();
  int reg4 =var_name();
  if((yyvsp[-2].s)->t == (yyvsp[0].s)->t){
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = and i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg2);
    }
    else{
      int reg5 = var_name();
      asprintf(&(yyval.s)->code, "%s %s%d = fptosi double %s%d to i32\n",(yyval.s)->code,"%x",reg4,"%x",reg1);
      asprintf(&(yyval.s)->code, "%s %s%d = fptosi double %s%d to i32\n",(yyval.s)->code,"%x",reg5,"%x",reg2);
      asprintf(&(yyval.s)->code, "%s %s%d = and i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg4, "%x", reg4);
    }
  }
  else{
    
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = fptosi double %s%d to i32\n",(yyval.s)->code,"%x",reg4,"%x",reg2);
      asprintf(&(yyval.s)->code, "%s %s%d = and i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg4);
    }
    else if ((yyvsp[0].s)->t == ENTIER){
    asprintf(&(yyval.s)->code, "%s %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg1,"%x",reg4);
    asprintf(&(yyval.s)->code, "%s %s%d = and i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg4, "%x", reg2);
    }
  }
  (yyval.s)->var = reg3;
  (yyval.s)->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
#line 1558 "grammar.c" /* yacc.c:1646  */
    break;

  case 7:
#line 178 "grammar.y" /* yacc.c:1646  */
    {
      if ((yyvsp[0].s)->t == ENTIER){
            printf("Résultat : %d\n", (yyvsp[0].s)->v.n);
	    /*$$ = create_expression_symbol_int($1->v.n);
	      $$->var = $1->var;*/
	    
      }
      else{
            printf("Résultat : %f\n", (yyvsp[0].s)->v.f);
	    /*$$ = create_expression_symbol_int($1->v.f);
	      $$->var = $1->var;*/
      }
      //$$->code = $1->code;
      (yyval.s) = (yyvsp[0].s);
    }
#line 1578 "grammar.c" /* yacc.c:1646  */
    break;

  case 10:
#line 199 "grammar.y" /* yacc.c:1646  */
    {
  if(!is_in_hash((yyvsp[0].string))){
    yyerror("utilisation d'une variable non déclarée");
  }
  else {
    struct expression_symbol *e = recup_hash((yyvsp[0].string));
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
#line 1600 "grammar.c" /* yacc.c:1646  */
    break;

  case 11:
#line 216 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.s) = create_expression_symbol_int((yyvsp[0].n));
  asprintf(&(yyval.s)->code,"%s%d = add i32 %d,0\n","%x",(yyval.s)->var,(yyvsp[0].n));
  }
#line 1609 "grammar.c" /* yacc.c:1646  */
    break;

  case 12:
#line 221 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.s) = create_expression_symbol_float((yyvsp[0].f)); // _float, mais en fait double
  asprintf(&(yyval.s)->code,"%s%d = fadd double %s,0.0\n","%x",(yyval.s)->var,double_to_hex_str((yyvsp[0].f)));
}
#line 1618 "grammar.c" /* yacc.c:1646  */
    break;

  case 13:
#line 226 "grammar.y" /* yacc.c:1646  */
    {
  //$$ = NULL; // Not implemented
  (yyval.s) = (yyvsp[-1].s);
  //$2->code = "";
}
#line 1628 "grammar.c" /* yacc.c:1646  */
    break;

  case 14:
#line 232 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.s) = create_expression_symbol_int(0);
}
#line 1636 "grammar.c" /* yacc.c:1646  */
    break;

  case 15:
#line 235 "grammar.y" /* yacc.c:1646  */
    {
  //$$ = create_expression_symbol_int(0);
  (yyval.s) = (yyvsp[-1].s);
  }
#line 1645 "grammar.c" /* yacc.c:1646  */
    break;

  case 16:
#line 242 "grammar.y" /* yacc.c:1646  */
    {(yyval.s) = (yyvsp[0].s);}
#line 1651 "grammar.c" /* yacc.c:1646  */
    break;

  case 17:
#line 244 "grammar.y" /* yacc.c:1646  */
    {
      (yyval.s) = (yyvsp[-1].s);
      if ((yyval.s)->t == ENTIER){
	((yyval.s)->v.n)++;
	//asprintf(&$$->code,"%s%s%d = add i32 %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
	int reg1 = var_name();
	int reg2 = var_name();
	asprintf(&(yyval.s)->code,"%s%s%d = load i32, i32* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[-1].s)->var);
	asprintf(&(yyval.s)->code,"%s%s%d = add i32 %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
	asprintf(&(yyval.s)->code,"%s store i32 %s%d, i32* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[-1].s)->var);
      }
      else{
	((yyval.s)->v.f)++;
	//asprintf(&$$->code,"%s%s%d = fadd double %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
	int reg1 = var_name();
	int reg2 = var_name();
	asprintf(&(yyval.s)->code,"%s%s%d = load double, double* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[-1].s)->var);
	asprintf(&(yyval.s)->code,"%s%s%d = fadd double %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
	asprintf(&(yyval.s)->code,"%s store double %s%d, double* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[-1].s)->var);
      }
    }
#line 1677 "grammar.c" /* yacc.c:1646  */
    break;

  case 18:
#line 266 "grammar.y" /* yacc.c:1646  */
    {
      (yyval.s) = (yyvsp[-1].s);
      if ((yyval.s)->t == ENTIER){
	((yyval.s)->v.n)--;
	//asprintf(&$$->code,"%s%s%d = sub i32 %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
	int reg1 = var_name();
	int reg2 = var_name();
	asprintf(&(yyval.s)->code,"%s%s%d = load i32, i32* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[-1].s)->var);
	asprintf(&(yyval.s)->code,"%s%s%d = sub i32 %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
	asprintf(&(yyval.s)->code,"%s store i32 %s%d, i32* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[-1].s)->var);
      }
      else{
	((yyval.s)->v.f)--;
	//asprintf(&$$->code,"%s%s%d = sub double %s%d,1\n",$$->code,"%x",$$->var,"%x", $1->var);
	int reg1 = var_name();
	int reg2 = var_name();
	asprintf(&(yyval.s)->code,"%s%s%d = load  double* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[-1].s)->var);
	asprintf(&(yyval.s)->code,"%s%s%d = sub double %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
	asprintf(&(yyval.s)->code,"%s store double %s%d, double* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[-1].s)->var);
      }
    }
#line 1703 "grammar.c" /* yacc.c:1646  */
    break;

  case 19:
#line 290 "grammar.y" /* yacc.c:1646  */
    {(yyval.s) = (yyvsp[0].s);}
#line 1709 "grammar.c" /* yacc.c:1646  */
    break;

  case 20:
#line 292 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.s) = (yyvsp[-2].s);
  asprintf(&(yyval.s)->code,"%s %s\n",(yyvsp[-2].s)->code,(yyvsp[0].s)->code);
}
#line 1718 "grammar.c" /* yacc.c:1646  */
    break;

  case 21:
#line 299 "grammar.y" /* yacc.c:1646  */
    {(yyval.s) = (yyvsp[0].s);}
#line 1724 "grammar.c" /* yacc.c:1646  */
    break;

  case 22:
#line 301 "grammar.y" /* yacc.c:1646  */
    {   
  if ((yyvsp[0].s)->t == ENTIER){
  //$$ = create_expression_symbol_int($2->v.n+1);
  //$$->var = $2->var;
    (yyval.s) = (yyvsp[0].s);
    ((yyval.s)->v.n)++;
    //asprintf(&$$->code,"%s%s%d = add i32 %s%d,1\n",$2->code,"%x",$$->var,"%x",$2->var); //pre incrementation
    int reg1 = var_name();
    int reg2 = var_name();
    asprintf(&(yyval.s)->code,"%s%s%d = load i32, i32* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[0].s)->var);
    asprintf(&(yyval.s)->code,"%s%s%d = add i32 %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
    asprintf(&(yyval.s)->code,"%s store i32 %s%d, i32* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[0].s)->var);
  }
  else{
    //$$ = create_expression_symbol_float($2->v.f+1.0);
    //$$->var = $2->var;
    (yyval.s) = (yyvsp[0].s);
    (yyval.s)->v.f++;
    //asprintf(&$$->code,"%s%s%d = fadd double %s%d,1\n",$$->code,"%x",$$->var,"%x", $2->var);
    int reg1 = var_name();
    int reg2 = var_name();
    asprintf(&(yyval.s)->code,"%s%s%d = load  double* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[0].s)->var);
    asprintf(&(yyval.s)->code,"%s%s%d = fadd double %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
    asprintf(&(yyval.s)->code,"%s store double %s%d, double* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[0].s)->var);
  }
}
#line 1755 "grammar.c" /* yacc.c:1646  */
    break;

  case 23:
#line 328 "grammar.y" /* yacc.c:1646  */
    { 
  if ((yyvsp[0].s)->t == ENTIER){
    //$$ = create_expression_symbol_int($2->v.n-1);
    //$$->var = $2->var;
    (yyval.s) = (yyvsp[0].s);
    (yyvsp[0].s)->v.n--;
    //asprintf(&$$->code,"%s%s%d = sub %s%d,1\n",$2->code,"%x",$$->var,"%x",$2->var); //pre incrementation
    int reg1 = var_name();
    int reg2 = var_name();
    asprintf(&(yyval.s)->code,"%s%s%d = load i32, i32* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[0].s)->var);
    asprintf(&(yyval.s)->code,"%s%s%d = sub i32 %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
    asprintf(&(yyval.s)->code,"%s store i32 %s%d, i32* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[0].s)->var);
  }
  else{
    //$$ = create_expression_symbol_float($2->v.f-1.0);
    //$$->var = $2->var;
    (yyval.s) = (yyvsp[0].s);
    (yyval.s)->v.n--;
    //asprintf(&$$->code,"%s%s%d = sub double %s%d,1\n",$$->code,"%x",$$->var,"%x", $2->var);
    int reg1 = var_name();
    int reg2 = var_name();
    asprintf(&(yyval.s)->code,"%s%s%d = load  double* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[0].s)->var);
    asprintf(&(yyval.s)->code,"%s%s%d = sub double %s%d,1\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
    asprintf(&(yyval.s)->code,"%s store double %s%d, double* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[0].s)->var);
  }
}
#line 1786 "grammar.c" /* yacc.c:1646  */
    break;

  case 24:
#line 355 "grammar.y" /* yacc.c:1646  */
    { 
  if ((yyval.s)->t == ENTIER){ 
    (yyval.s) = create_expression_symbol_int(-((yyvsp[0].s)->v.n));
    (yyval.s)->var = (yyvsp[0].s)->var;
    if (!(yyvsp[0].s)->is_var){
      asprintf(&(yyval.s)->code,"%s %s%d = mul i32 %s%d,-1\n",(yyvsp[0].s)->code,"%x",(yyval.s)->var,"%x",(yyval.s)->var);
    }
    else {
      int reg1 = var_name();
      int reg2 = var_name();
      asprintf(&(yyval.s)->code,"%s%s%d = load i32, i32* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[0].s)->var);
      asprintf(&(yyval.s)->code,"%s%s%d = sub i32 0,%s%d\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
      asprintf(&(yyval.s)->code,"%s store i32 %s%d, i32* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[0].s)->var);
    }
  }
  else{
    (yyval.s) = create_expression_symbol_float(-((yyvsp[0].s)->v.f));
    (yyval.s)->var = (yyvsp[0].s)->var;
    if ((yyvsp[0].s)->is_var){
      asprintf(&(yyval.s)->code,"%s %s%d = fmul double %s%d,-1\n",(yyvsp[0].s)->code,"%x",(yyval.s)->var,"%x",(yyval.s)->var);
    }
    else{
      int reg1 = var_name();
      int reg2 = var_name();
      asprintf(&(yyval.s)->code,"%s%s%d = load double, double* %s%d\n",(yyval.s)->code,"%x",reg1,"%x", (yyvsp[0].s)->var);
      asprintf(&(yyval.s)->code,"%s%s%d = sub double 0,%s%d\n",(yyval.s)->code,"%x",reg2,"%x", reg1);
      asprintf(&(yyval.s)->code,"%s store double %s%d, double* %s%d\n",(yyval.s)->code,"%x",reg2,"%x", (yyvsp[0].s)->var);
    }
  }
}
#line 1821 "grammar.c" /* yacc.c:1646  */
    break;

  case 26:
#line 392 "grammar.y" /* yacc.c:1646  */
    {(yyval.s) = (yyvsp[0].s);}
#line 1827 "grammar.c" /* yacc.c:1646  */
    break;

  case 27:
#line 394 "grammar.y" /* yacc.c:1646  */
    {
  asprintf(&(yyval.s)->code,"%s%s",(yyvsp[-2].s)->code,(yyvsp[0].s)->code);
  //gestion variable ou pas
  int reg1 = var_name();
  int reg2 = var_name();
  char *s = "";
  int i = 0;
    
  if ((yyvsp[-2].s)->is_var){
    if((yyvsp[-2].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load  double* %s%d\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
    }
  }
  else{
    if((yyvsp[-2].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
    }
  }

  if ((yyvsp[0].s)->is_var){
    if((yyvsp[0].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
    }
  }
  else {
    if((yyvsp[0].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
    }
  }

  switch(i){
  case 0:
    (yyval.s) = create_expression_symbol_int( ((yyvsp[-2].s)->v.n) * ((yyvsp[0].s)->v.n) );
    asprintf(&s, "%s %s%d = add i32 %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  case 1:
    (yyval.s) = create_expression_symbol_float( ((yyvsp[-2].s)->v.f) * ((yyvsp[0].s)->v.n) );
    asprintf(&s, "%s %s%d = fmul double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  case 2:
    (yyval.s) = create_expression_symbol_float( ((yyvsp[-2].s)->v.n) * ((yyvsp[0].s)->v.f) );
    asprintf(&s, "%s %s%d = fmul double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  default: // case 3
    (yyval.s) = create_expression_symbol_float( ((yyvsp[-2].s)->v.f) * ((yyvsp[0].s)->v.f) );
    asprintf(&s, "%s %s%d = fmul double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", (yyval.s)->var, "%x", reg1);
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
#line 1932 "grammar.c" /* yacc.c:1646  */
    break;

  case 28:
#line 495 "grammar.y" /* yacc.c:1646  */
    {
  if (((yyvsp[0].s)->t == ENTIER && (yyvsp[0].s)->v.n == 0) || ((yyvsp[0].s)->t == DOUBL && (yyvsp[0].s)->v.f == 0)){
    yyerror("Division par 0");
  }
  else{
    char *s = "";
    asprintf(&s,"%s%s",(yyvsp[-2].s)->code,(yyvsp[0].s)->code);
    //gestion variable ou pas
    int reg1 = var_name();
    int reg2 = var_name();
    int i = 0;
    
    if ((yyvsp[-2].s)->is_var){
      if((yyvsp[-2].s)->t == DOUBL){
	asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
	i++;
      }
      else{
	asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
      }
    }
    else{
      if((yyvsp[-2].s)->t == DOUBL){
	asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
	i++;
      }
      else{
	asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
      }
    }

    if ((yyvsp[0].s)->is_var){
      if((yyvsp[0].s)->t == DOUBL){
	asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
	i += 2;
      }
      else{
	asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
      }
    }
    else {
      if((yyvsp[0].s)->t == DOUBL){
	asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
	i += 2;
      }
      else{
	asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
      }
    }


    int reg = var_name();
    switch(i){
    case 0:
      (yyval.s) = create_expression_symbol_int( ((yyvsp[-2].s)->v.n) * ((yyvsp[0].s)->v.n) );
      asprintf(&s, "%s %s%d = sdiv i32 %s%d,%s%d\n", s, "%x", reg, "%x", reg1, "%x", reg2);
      asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", s, "%x", (yyval.s)->var, "%x", reg1);
      break;
    case 1:
      (yyval.s) = create_expression_symbol_float( ((yyvsp[-2].s)->v.f) * ((yyvsp[0].s)->v.n) );
      asprintf(&s, "%s %s%d = fdiv double %s%d,%s%d\n", s, "%x", reg, "%x", reg1, "%x", reg2);
      asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", (yyval.s)->var, "%x", reg1);
      break;
    case 2:
      (yyval.s) = create_expression_symbol_float( ((yyvsp[-2].s)->v.n) * ((yyvsp[0].s)->v.f) );
      asprintf(&s, "%s %s%d = fdiv double %s%d,%s%d\n", s, "%x", reg, "%x", reg1, "%x", reg2);
      asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", (yyval.s)->var, "%x", reg1);
      break;
    default: // case 3
      (yyval.s) = create_expression_symbol_float( ((yyvsp[-2].s)->v.f) * ((yyvsp[0].s)->v.f) );
      asprintf(&s, "%s %s%d = fdiv double %s%d,%s%d\n", s, "%x", reg, "%x", reg1, "%x", reg2);
      asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", (yyval.s)->var, "%x", reg1);
      break;
    }
    (yyval.s)->var = reg;
 
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
}
#line 2042 "grammar.c" /* yacc.c:1646  */
    break;

  case 29:
#line 601 "grammar.y" /* yacc.c:1646  */
    { // REM = %
  if ((yyvsp[-2].s)->t == DOUBL || (yyvsp[0].s)->t == DOUBL)
    yyerror("Erreur de type : modulo pas autorisé avec double");
  else{
    (yyval.s) = create_expression_symbol_int(((yyvsp[-2].s)->v.n) % ((yyvsp[0].s)->v.n));
    asprintf(&(yyval.s)->code,"%s%s \n",(yyvsp[-2].s)->code,(yyvsp[0].s)->code);
    
    //gestion variable ou pas
    int reg1 = var_name();
    int reg2 = var_name();
    
    if ((yyvsp[-2].s)->is_var){
      asprintf(&(yyval.s)->code,"%s %s%d = load i32, i32* %s%d\n", (yyval.s)->code,"%x",reg1,"%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code,"%s %s%d = add i32 %s%d,0\n", (yyval.s)->code,"%x",reg1,"%x", (yyvsp[-2].s)->var);
    }

    if ((yyvsp[0].s)->is_var){
      asprintf(&(yyval.s)->code,"%s %s%d = load i32, i32* %s%d\n", (yyval.s)->code,"%x",reg2,"%x", (yyvsp[0].s)->var);      
    }
    else {
      asprintf(&(yyval.s)->code,"%s %s%d = add i32 %s%d,0\n", (yyval.s)->code,"%x",reg2,"%x", (yyvsp[0].s)->var);
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
#line 2086 "grammar.c" /* yacc.c:1646  */
    break;

  case 30:
#line 644 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.s) = (yyvsp[0].s);
}
#line 2094 "grammar.c" /* yacc.c:1646  */
    break;

  case 31:
#line 648 "grammar.y" /* yacc.c:1646  */
    {
  asprintf(&(yyval.s)->code,"%s%s",(yyvsp[-2].s)->code,(yyvsp[0].s)->code);
  //gestion variable ou pas
  int reg1 = var_name();
  int reg2 = var_name();
  char *s = "";
  int i = 0;
    
  if ((yyvsp[-2].s)->is_var){
    if((yyvsp[-2].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
    }
  }
  else{
    if((yyvsp[-2].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
    }
  }

  if ((yyvsp[0].s)->is_var){
    if((yyvsp[0].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
    }
  }
  else {
    if((yyvsp[0].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
    }
  }

  switch(i){
  case 0:
    (yyval.s) = create_expression_symbol_int( ((yyvsp[-2].s)->v.n) * ((yyvsp[0].s)->v.n) );
    asprintf(&s, "%s %s%d = add i32 %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  case 1:
    (yyval.s) = create_expression_symbol_float( ((yyvsp[-2].s)->v.f) * ((yyvsp[0].s)->v.n) );
    asprintf(&s, "%s %s%d = fadd double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  case 2:
    (yyval.s) = create_expression_symbol_float( ((yyvsp[-2].s)->v.n) * ((yyvsp[0].s)->v.f) );
    asprintf(&s, "%s %s%d = fadd double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  default: // case 3
    (yyval.s) = create_expression_symbol_float( ((yyvsp[-2].s)->v.f) * ((yyvsp[0].s)->v.f) );
    asprintf(&s, "%s %s%d = fadd double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  }
  /*
  if ($1->t == DOUBL)
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.f) + ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = fadd double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_float(($1->v.f) + ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = fadd double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  else
    {
      if ($3->t == DOUBL){
	$$ = create_expression_symbol_float(($1->v.n) + ($3->v.f));
	asprintf(&$$->code,"%s%s %s%d = fadd double %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
      else{
	$$ = create_expression_symbol_int(($1->v.n) + ($3->v.n));
	asprintf(&$$->code,"%s%s %s%d = add i32 %s%d,%s%d\n",$1->code,$3->code,"%x",$$->var,"%x",$1->var,"%x",$3->var);
      }
    }
  */
}
#line 2196 "grammar.c" /* yacc.c:1646  */
    break;

  case 32:
#line 746 "grammar.y" /* yacc.c:1646  */
    {
  asprintf(&(yyval.s)->code,"%s%s",(yyvsp[-2].s)->code,(yyvsp[0].s)->code);
  //gestion variable ou pas
  int reg1 = var_name();
  int reg2 = var_name();
  char *s = "";
  int i = 0;
    
  if ((yyvsp[-2].s)->is_var){
    if((yyvsp[-2].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
    }
  }
  else{
    if((yyvsp[-2].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
      i++;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg1,"%x", (yyvsp[-2].s)->var);
    }
  }

  if ((yyvsp[0].s)->is_var){
    if((yyvsp[0].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
    }
  }
  else {
    if((yyvsp[0].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
    }
  }

  switch(i){
  case 0:
    (yyval.s) = create_expression_symbol_int( ((yyvsp[-2].s)->v.n) * ((yyvsp[0].s)->v.n) );
    asprintf(&s, "%s %s%d = sub i32 %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  case 1:
    (yyval.s) = create_expression_symbol_float( ((yyvsp[-2].s)->v.f) * ((yyvsp[0].s)->v.n) );
    asprintf(&s, "%s %s%d = sub double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  case 2:
    (yyval.s) = create_expression_symbol_float( ((yyvsp[-2].s)->v.n) * ((yyvsp[0].s)->v.f) );
    asprintf(&s, "%s %s%d = sub double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", (yyval.s)->var, "%x", reg1);
    break;
  default: // case 3
    (yyval.s) = create_expression_symbol_float( ((yyvsp[-2].s)->v.f) * ((yyvsp[0].s)->v.f) );
    asprintf(&s, "%s %s%d = sub double %s%d,%s%d\n", s, "%x", reg1, "%x", reg1, "%x", reg2);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyval.s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0", s, "%x", (yyval.s)->var, "%x", reg1);
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
#line 2298 "grammar.c" /* yacc.c:1646  */
    break;

  case 33:
#line 847 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.s) = (yyvsp[0].s);
}
#line 2306 "grammar.c" /* yacc.c:1646  */
    break;

  case 34:
#line 851 "grammar.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n < (yyvsp[0].s)->v.n);
  }
  else if((yyvsp[-2].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n < (yyvsp[0].s)->v.f);
  }
  else if((yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f < (yyvsp[0].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f < (yyvsp[0].s)->v.f);
  }
  
  asprintf(&(yyval.s)->code, "%s%s", (yyvsp[-2].s)->code, (yyvsp[0].s)->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if((yyvsp[-2].s)->is_var){
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32, i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double, double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  else{
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  
  if((yyvsp[0].s)->is_var){
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32, i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double, double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }
  else{
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }
  
  int reg3 = var_name();
  int reg4 = var_name();
  int reg5 = var_name();
  if((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == ENTIER){
    asprintf(&(yyval.s)->code, "%s %s%d = icmp slt i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg2);
  }
  else if((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == DOUBL){
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg5,"%x",reg2);
    asprintf(&(yyval.s)->code, "%s %s%d = icmp slt i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg5);
  }
  else if((yyvsp[-2].s)->t == DOUBL && (yyvsp[0].s)->t == ENTIER){
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg4,"%x",reg1);
    asprintf(&(yyval.s)->code, "%s %s%d = icmp slt i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg4, "%x", reg2);
  }
  else{
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg4,"%x",reg1);
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg5,"%x",reg2);
    asprintf(&(yyval.s)->code, "%s %s%d = icmp slt i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg4, "%x", reg5);
  }
  int reg_final = var_name();
  asprintf(&(yyval.s)->code,"%s %s%d = zext i1 %s%d to i32\n",(yyval.s)->code,"%x",reg_final,"%x",reg3);
  (yyval.s)->var = reg_final;
  (yyval.s)->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
#line 2390 "grammar.c" /* yacc.c:1646  */
    break;

  case 35:
#line 931 "grammar.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n > (yyvsp[0].s)->v.n);
  }
  else if((yyvsp[-2].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n > (yyvsp[0].s)->v.f);
  }
  else if((yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f > (yyvsp[0].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f > (yyvsp[0].s)->v.f);
  }
  
  asprintf(&(yyval.s)->code, "%s%s", (yyvsp[-2].s)->code, (yyvsp[0].s)->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if((yyvsp[-2].s)->is_var){
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  else{
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  
  if((yyvsp[0].s)->is_var){
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }
  else{
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }



  int reg3 = var_name();
  int reg4 = var_name();
  int reg5 = var_name();
  if((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == ENTIER){
    asprintf(&(yyval.s)->code, "%s %s%d = icmp sgt i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg2);
  }
  else if((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == DOUBL){
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg5,"%x",reg2);
    asprintf(&(yyval.s)->code, "%s %s%d = icmp sgt i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg5);
  }
  else if((yyvsp[-2].s)->t == DOUBL && (yyvsp[0].s)->t == ENTIER){
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg4,"%x",reg1);
    asprintf(&(yyval.s)->code, "%s %s%d = icmp sgt i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg4, "%x", reg2);
  }
  else{
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg4,"%x",reg1);
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg5,"%x",reg2);
    asprintf(&(yyval.s)->code, "%s %s%d = icmp sgt i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg4, "%x", reg5);
  }
  int reg_final = var_name();
  asprintf(&(yyval.s)->code,"%s %s%d = zext i1 %s%d to i32\n",(yyval.s)->code,"%x",reg_final,"%x",reg3);
  (yyval.s)->var = reg_final;
  (yyval.s)->is_var = 0;

    
  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
#line 2477 "grammar.c" /* yacc.c:1646  */
    break;

  case 36:
#line 1014 "grammar.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n <= (yyvsp[0].s)->v.n);
  }
  else if((yyvsp[-2].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n <= (yyvsp[0].s)->v.f);
  }
  else if((yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f <= (yyvsp[0].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f <= (yyvsp[0].s)->v.f);
  }

    asprintf(&(yyval.s)->code, "%s%s", (yyvsp[-2].s)->code, (yyvsp[0].s)->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if((yyvsp[-2].s)->is_var){
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  else{
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  
  if((yyvsp[0].s)->is_var){
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }
  else{
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }


  


  int reg3 = var_name();
  int reg4 = var_name();
  int reg5 = var_name();
  if((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == ENTIER){
    asprintf(&(yyval.s)->code, "%s %s%d = icmp sle i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg2);
  }
  else if((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == DOUBL){
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg5,"%x",reg2);
    asprintf(&(yyval.s)->code, "%s %s%d = icmp sle i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg5);
  }
  else if((yyvsp[-2].s)->t == DOUBL && (yyvsp[0].s)->t == ENTIER){
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg4,"%x",reg1);
    asprintf(&(yyval.s)->code, "%s %s%d = icmp sle i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg4, "%x", reg2);
  }
  else{
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg4,"%x",reg1);
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg5,"%x",reg2);
    asprintf(&(yyval.s)->code, "%s %s%d = icmp sle i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg4, "%x", reg5);
  }
  int reg_final = var_name();
  asprintf(&(yyval.s)->code,"%s %s%d = zext i1 %s%d to i32\n",(yyval.s)->code,"%x",reg_final,"%x",reg3);
  (yyval.s)->var = reg_final;
  (yyval.s)->is_var = 0;

}
#line 2564 "grammar.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1097 "grammar.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n >= (yyvsp[0].s)->v.n);
  }
  else if((yyvsp[-2].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n >= (yyvsp[0].s)->v.f);
  }
  else if((yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f >= (yyvsp[0].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f >= (yyvsp[0].s)->v.f);
  }
  
    asprintf(&(yyval.s)->code, "%s%s", (yyvsp[-2].s)->code, (yyvsp[0].s)->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if((yyvsp[-2].s)->is_var){
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  else{
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  
  if((yyvsp[0].s)->is_var){
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }
  else{
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }
  

  

  int reg3 = var_name();
  int reg4 = var_name();
  int reg5 = var_name();
  if((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == ENTIER){
    asprintf(&(yyval.s)->code, "%s %s%d = icmp sge i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg2);
  }
  else if((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == DOUBL){
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg5,"%x",reg2);
    asprintf(&(yyval.s)->code, "%s %s%d = icmp sge i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg5);
  }
  else if((yyvsp[-2].s)->t == DOUBL && (yyvsp[0].s)->t == ENTIER){
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg4,"%x",reg1);
    asprintf(&(yyval.s)->code, "%s %s%d = icmp sge i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg4, "%x", reg2);
  }
  else{
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg4,"%x",reg1);
    asprintf(&(yyval.s)->code,"%s\n %s%d = fptosi double %s%d to i32",(yyval.s)->code,"%x",reg5,"%x",reg2);
    asprintf(&(yyval.s)->code, "%s %s%d = icmp sge i32 %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg4, "%x", reg5);
  }
  int reg_final = var_name();
  asprintf(&(yyval.s)->code,"%s %s%d = zext i1 %s%d to i32\n",(yyval.s)->code,"%x",reg_final,"%x",reg3);
  (yyval.s)->var = reg_final;
  (yyval.s)->is_var = 0;



}
#line 2652 "grammar.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1181 "grammar.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n == (yyvsp[0].s)->v.n);
  }
  else if((yyvsp[-2].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n == (yyvsp[0].s)->v.f);
  }
  else if((yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f == (yyvsp[0].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f == (yyvsp[0].s)->v.f);
  }

    asprintf(&(yyval.s)->code, "%s%s", (yyvsp[-2].s)->code, (yyvsp[0].s)->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if((yyvsp[-2].s)->is_var){
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  else{
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  
  if((yyvsp[0].s)->is_var){
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }
  else{
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }
  
  int reg3 = var_name();

  asprintf(&(yyval.s)->code, "%s %s%d = icmp eq %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg2);
  (yyval.s)->var = reg3;
  (yyval.s)->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
#line 2718 "grammar.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1243 "grammar.y" /* yacc.c:1646  */
    {
  if ((yyvsp[-2].s)->t == ENTIER && (yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n != (yyvsp[0].s)->v.n);
  }
  else if((yyvsp[-2].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.n != (yyvsp[0].s)->v.f);
  }
  else if((yyvsp[0].s)->t == ENTIER){
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f != (yyvsp[0].s)->v.n);
  }
  else{
    (yyval.s) = create_expression_symbol_int((yyvsp[-2].s)->v.f != (yyvsp[0].s)->v.f);
  }
  
    asprintf(&(yyval.s)->code, "%s%s", (yyvsp[-2].s)->code, (yyvsp[0].s)->code);

  int reg1 = var_name();
  int reg2 = var_name();

  if((yyvsp[-2].s)->is_var){
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  else{
    if((yyvsp[-2].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    }
  }
  
  if((yyvsp[0].s)->is_var){
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = load i32; i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = load double; double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }
  else{
    if((yyvsp[0].s)->t == ENTIER){
      asprintf(&(yyval.s)->code, "%s %s%d = add i32 %s%d,0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
    else{
      asprintf(&(yyval.s)->code, "%s %s%d = fadd double %s%d,0.0\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[0].s)->var);
    }
  }
  
  int reg3 = var_name();

  asprintf(&(yyval.s)->code, "%s %s%d = icmp ne %s%d,%s%d\n", (yyval.s)->code, "%x", reg3, "%x", reg1, "%x", reg2);
  (yyval.s)->var = reg3;
  (yyval.s)->is_var = 0;

  //asprintf(&$$->code,"%s%s %s%d = add i32 %d,0\n",$1->code,$3->code,"%x",$$->var,$$->v.n);
}
#line 2784 "grammar.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1308 "grammar.y" /* yacc.c:1646  */
    {
  //asprintf(&$$->code,"%s%s",$1->code,$3->code);
  //gestion variable ou pas
  int reg1 = var_name();
  int reg2 = var_name();
  char *s = "";
  int i = 0;
    
  if ((yyvsp[-2].s)->is_var){
    if((yyvsp[-2].s)->t == DOUBL){
      i++;
    }
  }
  else{
    if((yyvsp[-2].s)->t == DOUBL){
      i++;
    }
  }

  if ((yyvsp[0].s)->is_var){
    if((yyvsp[0].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = load double, double* %s%d\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = load i32, i32* %s%d\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
    }
  }
  else {
    if((yyvsp[0].s)->t == DOUBL){
      asprintf(&s,"%s %s%d = fadd double %s%d,0.0\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
      i += 2;
    }
    else{
      asprintf(&s,"%s %s%d = add i32 %s%d,0\n",s,"%x",reg2,"%x", (yyvsp[0].s)->var);
    }
  }

  // TODO : case 1, 2, default
  int reg_cast = var_name();
  switch(i){
  case 0: // int int
    (yyvsp[-2].s)->v.n = (yyvsp[0].s)->v.n;
    (yyval.s) = (yyvsp[-2].s);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyvsp[0].s)->code, s);
    asprintf(&(yyval.s)->code, "%s store i32 %s%d, i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[-2].s)->var);
    break;
  case 1: // double int
    (yyvsp[-2].s)->v.f = (yyvsp[0].s)->v.n;
    (yyval.s) = (yyvsp[-2].s);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyvsp[0].s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = sitofp i32 %s%d to double\n",(yyval.s)->code, "%x", reg_cast, "%x",reg2);
    asprintf(&(yyval.s)->code, "%s store double %s%d, double* %s%d\n", (yyval.s)->code, "%x", reg1, "%x", (yyvsp[-2].s)->var);
    break;
  case 2: // int double
    (yyvsp[-2].s)->v.n = (yyvsp[0].s)->v.f;
    (yyval.s) = (yyvsp[-2].s);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyvsp[0].s)->code, s);
    asprintf(&(yyval.s)->code, "%s %s%d = fptosi double %s%d to i32\n",(yyval.s)->code,"%x",reg_cast,"%x",reg1);
    asprintf(&(yyval.s)->code, "%s store i32 %s%d, i32* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[-2].s)->var);
    break;
  default: // case 3 double double 
    (yyvsp[-2].s)->v.f = (yyvsp[0].s)->v.f;
    (yyval.s) = (yyvsp[-2].s);
    asprintf(&(yyval.s)->code, "%s %s\n", (yyvsp[0].s)->code, s);
    asprintf(&(yyval.s)->code, "%s store double %s%d, double* %s%d\n", (yyval.s)->code, "%x", reg2, "%x", (yyvsp[-2].s)->var);
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
      asprintf(&$$->code,"%s %s%d = fadd double %s%d,0.0\n",$3->code,"%x",$1->var,"%x",$3->var);
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
#line 2959 "grammar.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1478 "grammar.y" /* yacc.c:1646  */
    {(yyval.s) = (yyvsp[0].s);}
#line 2965 "grammar.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1482 "grammar.y" /* yacc.c:1646  */
    {(yyval.n) = ASSIGN;}
#line 2971 "grammar.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1483 "grammar.y" /* yacc.c:1646  */
    {(yyval.n) = ASSIGN_MUL;}
#line 2977 "grammar.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1484 "grammar.y" /* yacc.c:1646  */
    {(yyval.n) = ASSIGN_DIV;}
#line 2983 "grammar.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1485 "grammar.y" /* yacc.c:1646  */
    {(yyval.n) = ASSIGN_REM;}
#line 2989 "grammar.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1486 "grammar.y" /* yacc.c:1646  */
    {(yyval.n) = ASSIGN_SHL;}
#line 2995 "grammar.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1487 "grammar.y" /* yacc.c:1646  */
    {(yyval.n) = ASSIGN_SHR;}
#line 3001 "grammar.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1488 "grammar.y" /* yacc.c:1646  */
    {(yyval.n) = ASSIGN_ADD;}
#line 3007 "grammar.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1489 "grammar.y" /* yacc.c:1646  */
    {(yyval.n) = ASSIGN_SUB;}
#line 3013 "grammar.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1494 "grammar.y" /* yacc.c:1646  */
    {
  int i;
  ENTRY e, *ep;


  for (i = 0; i < nb_declarators ; i++){
      
    // Erreur declaration : void var;
    if (liste_declarators[i]->d == VAR) {
	
      if((yyvsp[-2].t) == VIDE){

	yyerror("Erreur : la variable suivante est de type void :");
	printf("%s\n", liste_declarators[i]->nom);
	
      } else {
	// Si pas d'erreur de declaration, on rentre la variable dans la hash table.
	
	e.key = liste_declarators[i]->nom;
	struct expression_symbol *v = create_expression_symbol_general((yyvsp[-2].t), level);
	e.data = (void *) v;
	
	// On verifie que la variable a pas ete deja declaree <=> variable deja presente dans la hash table avec un niveau inferieur
	ep = hsearch(e, FIND);
	
	if( ep != NULL){
	  yyerror("Erreur : la variable suivante est deja declaree ou porte le meme nom qu'une fonction : ");
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
    } else { // FONCTION
      
      e.key = liste_declarators[i]->nom;
      e.data = (void *) liste_declarators[i];
      
      // On verifie que la variable a pas ete deja declaree <=> variable deja presente dans la hash table
      ep = hsearch(e, FIND);
      
      if( ep != NULL){
	yyerror("Erreur : la fonction suivante est deja declaree ou porte le meme nom qu'une variable: ");
	printf("%s\n", e.key);
      } else {
	// Si pas d'erreur, on l'ajoute
	
	ep = hsearch(e, ENTER);
      }
      if (ep == NULL) {
	fprintf(stderr, "hash table : entry failed\n");
	exit(EXIT_FAILURE);
      }
    }
  }  

  printf("\n");


  // Pour la correction, on affiche ce qu'on a rajouté dans la table de hash...
  for (i = 0; i < nb_declarators; i++){
    e.key = liste_declarators[i]->nom;
    ep = hsearch(e, FIND);

    if(ep != NULL){

      struct expression_symbol *v = (struct expression_symbol *) (ep->data);
      printf("nom : %s \t type : %s \t level : %d\n", ep->key, get_expression_symbol_type(v), v->lvl);
    }
  }

  // Declaration finie, on réinitialise le nombre de declarators et parametres.
  nb_declarators = 0;
  nb_parametres = 0;
}
#line 3103 "grammar.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1583 "grammar.y" /* yacc.c:1646  */
    { 
  nb_declarators++;
  liste_declarators[nb_declarators-1] = (yyvsp[0].d);
}
#line 3112 "grammar.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1588 "grammar.y" /* yacc.c:1646  */
    {
  nb_declarators++;
  liste_declarators[nb_declarators-1] = (yyvsp[0].d);
}
#line 3121 "grammar.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1596 "grammar.y" /* yacc.c:1646  */
    { (yyval.t) = VIDE; }
#line 3127 "grammar.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1598 "grammar.y" /* yacc.c:1646  */
    { (yyval.t) = ENTIER; }
#line 3133 "grammar.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1600 "grammar.y" /* yacc.c:1646  */
    { (yyval.t) = DOUBL; }
#line 3139 "grammar.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1605 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.d) = create_declarator(VAR, (yyvsp[0].string));
  printf("Identifier : %s\n",(yyvsp[0].string));  
}
#line 3148 "grammar.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1610 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.d) = create_declarator(VAR, (yyvsp[-1].d)->nom);
}
#line 3156 "grammar.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1614 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.d) = create_declarator_fonction(FONCTION, (yyvsp[-3].d)->nom, VIDE, liste_parametres, nb_parametres); // VIDE en attendant de savoir son type de retour... Connue à la règle declaration
}
#line 3164 "grammar.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1618 "grammar.y" /* yacc.c:1646  */
    { 
  (yyval.d) = create_declarator_fonction(FONCTION, (yyvsp[-2].d)->nom, VIDE, NULL, 0); // VIDE en attendant de savoir son type de retour... Connue à la règle declaration
}
#line 3172 "grammar.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1625 "grammar.y" /* yacc.c:1646  */
    {
  nb_parametres++;
  liste_parametres[nb_parametres-1] = (yyvsp[0].t);
  nb_declarators++;
}
#line 3182 "grammar.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1631 "grammar.y" /* yacc.c:1646  */
    {
  nb_parametres++;
  liste_parametres[nb_parametres-1] = (yyvsp[0].t);
  nb_declarators++;
}
#line 3192 "grammar.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1640 "grammar.y" /* yacc.c:1646  */
    {
  // Erreur parametre : void arg;
  if( (yyvsp[-1].t) == VIDE && (yyvsp[0].d)->d == VAR){
    yyerror("Erreur : l'argument suivant est de type void :");
    printf("%s\n", (yyvsp[0].d)->nom); 
  } else if( (yyvsp[0].d)->d == FONCTION){
    yyerror("Erreur : la fonction suivante ne peut pas etre un paramètre :");
    printf("%s\n", (yyvsp[0].d)->nom);
  } else {
    (yyval.t) = (yyvsp[-1].t);
    liste_declarators[nb_declarators] = (yyvsp[0].d);
  }
  
}
#line 3211 "grammar.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1657 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 3217 "grammar.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1658 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 3223 "grammar.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1659 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 3229 "grammar.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1660 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 3235 "grammar.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1661 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 3241 "grammar.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1666 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[-1].string);}
#line 3247 "grammar.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1667 "grammar.y" /* yacc.c:1646  */
    {asprintf(&(yyval.string),"%s%s",(yyvsp[-2].string),(yyvsp[-1].string));}
#line 3253 "grammar.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1668 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[-1].string);}
#line 3259 "grammar.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1672 "grammar.y" /* yacc.c:1646  */
    { level++; }
#line 3265 "grammar.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1677 "grammar.y" /* yacc.c:1646  */
    {
  level--;
  
  if(level == 0){
    hdestroy();
    hcreate(MAX_VAR);
  }
}
#line 3278 "grammar.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1688 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 3284 "grammar.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1689 "grammar.y" /* yacc.c:1646  */
    {asprintf(&(yyval.string),"%s%s",(yyvsp[-1].string),(yyvsp[0].string));}
#line 3290 "grammar.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1693 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 3296 "grammar.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1694 "grammar.y" /* yacc.c:1646  */
    {asprintf(&(yyval.string),"%s%s",(yyvsp[-1].string),(yyvsp[0].string));}
#line 3302 "grammar.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1698 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = '\0';}
#line 3308 "grammar.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1699 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[-1].s)->code;}
#line 3314 "grammar.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1704 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "";
  //printf("code:%s\nreg:%d\n",$3->code,$3->var);
  int cond = var_name();
  int label = var_name();
  if ((yyvsp[-2].s)->is_var){
    asprintf(&(yyval.string),"%s%s%d = load i32, i32* %s%d\n","%x",(yyvsp[-2].s)->code,label,"%x",(yyvsp[-2].s)->var);
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",label);
  }
  else{
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyvsp[-2].s)->code,"%x",cond,"%x",(yyvsp[-2].s)->var);
  } 
  asprintf(&(yyval.string),"%s br i1 %s%d, label %s%d, label %s%d\n",(yyval.string),"%x",cond,"%then",label,"%endif",label);
  asprintf(&(yyval.string),"%s then%d:\n %s br label %s%d\n",(yyval.string),label,(yyvsp[0].string),"%endif",label);
  asprintf(&(yyval.string),"%s endif%d:\n",(yyval.string),label);
}
#line 3335 "grammar.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1721 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "";
  int cond = var_name();
  int label = var_name();
  //  asprintf(&$$,"\n\n\n Objet du délit : \n %s\n\n\n\n",$3->code);
  if ((yyvsp[-4].s)->is_var){
  asprintf(&(yyval.string),"%s%s%d = load i32, i32* %s%d\n","%x",(yyvsp[-4].s)->code,label,"%x",(yyvsp[-4].s)->var);
  asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",label);
  }
  else{
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyvsp[-4].s)->code,"%x",cond,"%x",(yyvsp[-4].s)->var);
  } 
  asprintf(&(yyval.string),"%s br i1 %s%d, label %s%d, label %s%d\n",(yyval.string),"%x",cond,"%then",label,"%else",label);
  asprintf(&(yyval.string),"%s then%d:\n %s br label %s%d\n",(yyval.string),label,(yyvsp[-2].string),"%endif",label);
  asprintf(&(yyval.string),"%s else%d:\n %s br label %s%d\n",(yyval.string),label,(yyvsp[0].string),"%endif",label);
  asprintf(&(yyval.string),"%s endif%d:\n",(yyval.string),label);
}
#line 3357 "grammar.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1739 "grammar.y" /* yacc.c:1646  */
    {
  // debugage
  int cond = var_name();
  int label = var_name();
  // initialisation
  (yyval.string) = (yyvsp[-6].s)->code;

  // test condition
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); //saut à la ligne en dessous
  asprintf(&(yyval.string),"%s condfor%d:\n",(yyval.string),label); // label

  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[-4].s)->code); // code de la condition

  if ((yyvsp[-4].s)->is_var){ // si est variable il faut faire un load
    asprintf(&(yyval.string),"%s%s%d = load i32, i32* %s%d\n",(yyval.string),"%x",label,"%x",(yyvsp[-4].s)->var);
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",label);
  }
  else{ // si constante pas de pb
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",(yyvsp[-4].s)->var);
  } 

  asprintf(&(yyval.string),"%s br i1 %s%d, label %s%d, label %s%d\n",(yyval.string),"%x",cond,"%bodyfor",label,"%endfor",label); // test condition
  
  // contenu for
  asprintf(&(yyval.string),"%s bodyfor%d:\n",(yyval.string),label); // label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[0].string)); // code du corps du for
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%incfor",label); // jump -> expression
  
  //expression
  asprintf(&(yyval.string),"%s incfor%d:\n",(yyval.string),label);// label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[-2].s)->code); // code de l'expression
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); // jump -> condition
  // sortie de boucle
  asprintf(&(yyval.string),"%s endfor%d:\n\n",(yyval.string),label); // label
}
#line 3397 "grammar.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1775 "grammar.y" /* yacc.c:1646  */
    {
  int cond = var_name();
  int label = var_name();
  // initialisation
  (yyval.string) = (yyvsp[-5].s)->code;

  // test condition
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); //saut à la ligne en dessous
  asprintf(&(yyval.string),"%s condfor%d:\n",(yyval.string),label); // label

  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[-3].s)->code); // code de la condition

  if ((yyvsp[-3].s)->is_var){ // si est variable il faut faire un load
    asprintf(&(yyval.string),"%s%s%d = load i32, i32* %s%d\n",(yyval.string),"%x",label,"%x",(yyvsp[-3].s)->var);
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",label);
  }
  else{ // si constante pas de pb
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",(yyvsp[-3].s)->var);
  } 

  asprintf(&(yyval.string),"%s br i1 %s%d, label %s%d, label %s%d\n",(yyval.string),"%x",cond,"%bodyfor",label,"%endfor",label); // test condition
  
  // contenu for
  asprintf(&(yyval.string),"%s bodyfor%d:\n",(yyval.string),label); // label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[0].string)); // code du corps du for
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%incfor",label); // jump -> expression
  
  //expression
  asprintf(&(yyval.string),"%s incfor%d:\n",(yyval.string),label);// label
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); // jump -> condition
  // sortie de boucle
  asprintf(&(yyval.string),"%s endfor%d:\n\n",(yyval.string),label); // label
}
#line 3435 "grammar.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1809 "grammar.y" /* yacc.c:1646  */
    {

  int label = var_name();
  // initialisation
  (yyval.string) = (yyvsp[-5].s)->code;

  // test condition
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); //saut à la ligne en dessous
  asprintf(&(yyval.string),"%s condfor%d:\n",(yyval.string),label); // label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[0].string));
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); //saut à la ligne en dessus

  // sortie de boucle
  asprintf(&(yyval.string),"%s endfor%d:\n\n",(yyval.string),label); // label

}
#line 3456 "grammar.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1826 "grammar.y" /* yacc.c:1646  */
    {
  int label = var_name();
  // initialisation
  (yyval.string) = (yyvsp[-4].s)->code;

  // test condition
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); //saut à la ligne en dessous
  asprintf(&(yyval.string),"%s condfor%d:\n",(yyval.string),label); // label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[0].string));
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); //saut à la ligne en dessus

  // sortie de boucle
  asprintf(&(yyval.string),"%s endfor%d:\n\n",(yyval.string),label); // label
}
#line 3475 "grammar.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1841 "grammar.y" /* yacc.c:1646  */
    {
  int cond = var_name();
  int label = var_name();
  // test condition
  (yyval.string) = "";
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); //saut à la ligne en dessous
  asprintf(&(yyval.string),"%s condfor%d:\n",(yyval.string),label); // label

  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[-4].s)->code); // code de la condition

  if ((yyvsp[-4].s)->is_var){ // si est variable il faut faire un load
    asprintf(&(yyval.string),"%s%s%d = load i32, i32* %s%d\n",(yyval.string),"%x",label,"%x",(yyvsp[-4].s)->var);
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",label);
  }
  else{ // si constante pas de pb
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",(yyvsp[-4].s)->var);
  } 

  asprintf(&(yyval.string),"%s br i1 %s%d, label %s%d, label %s%d\n",(yyval.string),"%x",cond,"%bodyfor",label,"%endfor",label); // test condition
  
  // contenu for
  asprintf(&(yyval.string),"%s bodyfor%d:\n",(yyval.string),label); // label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[0].string)); // code du corps du for
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%incfor",label); // jump -> expression
  
  //expression
  asprintf(&(yyval.string),"%s incfor%d:\n",(yyval.string),label);// label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[-2].s)->code); // code de l'expression
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); // jump -> condition
  // sortie de boucle
  asprintf(&(yyval.string),"%s endfor%d:\n\n",(yyval.string),label); // label
}
#line 3512 "grammar.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1874 "grammar.y" /* yacc.c:1646  */
    {
  int cond = var_name();
  int label = var_name();
  (yyval.string) = "";
  // test condition
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); //saut à la ligne en dessous
  asprintf(&(yyval.string),"%s condfor%d:\n",(yyval.string),label); // label

  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[-3].s)->code); // code de la condition

  if ((yyvsp[-3].s)->is_var){ // si est variable il faut faire un load
    asprintf(&(yyval.string),"%s%s%d = load i32, i32* %s%d\n",(yyval.string),"%x",label,"%x",(yyvsp[-3].s)->var);
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",label);
  }
  else{ // si constante pas de pb
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",(yyvsp[-3].s)->var);
  } 

  asprintf(&(yyval.string),"%s br i1 %s%d, label %s%d, label %s%d\n",(yyval.string),"%x",cond,"%bodyfor",label,"%endfor",label); // test condition
  
  // contenu for
  asprintf(&(yyval.string),"%s bodyfor%d:\n",(yyval.string),label); // label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[0].string)); // code du corps du for
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); // jump -> expression

  // sortie de boucle
  asprintf(&(yyval.string),"%s endfor%d:\n\n",(yyval.string),label); // label

}
#line 3546 "grammar.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1904 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "";
  int label = var_name();
  // test condition
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); //saut à la ligne en dessous
  asprintf(&(yyval.string),"%s condfor%d:\n",(yyval.string),label); // label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[0].string));
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[-2].s)->code);
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); //saut à la ligne en dessus

  // sortie de boucle
  asprintf(&(yyval.string),"%s endfor%d:\n\n",(yyval.string),label); // label
}
#line 3564 "grammar.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1918 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "";
  int label = var_name();
  // test condition
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); //saut à la ligne en dessous
  asprintf(&(yyval.string),"%s condfor%d:\n",(yyval.string),label); // label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[0].string));
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condfor",label); //saut à la ligne en dessus

  // sortie de boucle
  asprintf(&(yyval.string),"%s endfor%d:\n\n",(yyval.string),label); // label
}
#line 3581 "grammar.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1934 "grammar.y" /* yacc.c:1646  */
    {
  (yyval.string) = "";
  // debugage
  int cond = var_name();
  int label = var_name();

  // test condition
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condwhile",label); //saut à la ligne en dessous
  asprintf(&(yyval.string),"%s condwhile%d:\n",(yyval.string),label); // label

  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[-2].s)->code); // code de la condition

  if ((yyvsp[-2].s)->is_var){ // si est variable il faut faire un load
    asprintf(&(yyval.string),"%s%s%d = load i32, i32* %s%d\n",(yyval.string),"%x",label,"%x",(yyvsp[-2].s)->var);
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",label);
  }
  else{ // si constante pas de pb
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",(yyvsp[-2].s)->var);
  } 

  asprintf(&(yyval.string),"%s br i1 %s%d, label %s%d, label %s%d\n",(yyval.string),"%x",cond,"%bodywhile",label,"%endwhile",label); // test condition
  
  // contenu while
  asprintf(&(yyval.string),"%s bodywhile%d:\n",(yyval.string),label); // label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[0].string)); // code du corps du for
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condwhile",label); // jump -> condition
  
  // sortie de boucle
  asprintf(&(yyval.string),"%s endwhile%d:\n\n",(yyval.string),label); // label


}
#line 3618 "grammar.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1967 "grammar.y" /* yacc.c:1646  */
    {

  (yyval.string) = "";
  // debugage
  int cond = var_name();
  int label = var_name();

 
  
  // contenu while
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%bodywhile",label); //saut à la ligne en dessous
  asprintf(&(yyval.string),"%s bodywhile%d:\n",(yyval.string),label); // label
  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[-4].string)); // code du corps du for
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condwhile",label); // jump -> condition
  

   // test condition
  asprintf(&(yyval.string),"%s br label %s%d\n",(yyval.string),"%condwhile",label); //saut à la ligne en dessous
  asprintf(&(yyval.string),"%s condwhile%d:\n",(yyval.string),label); // label

  asprintf(&(yyval.string),"%s%s",(yyval.string),(yyvsp[-1].s)->code); // code de la condition

  if ((yyvsp[-1].s)->is_var){ // si est variable il faut faire un load
    asprintf(&(yyval.string),"%s%s%d = load i32, i32* %s%d\n",(yyval.string),"%x",label,"%x",(yyvsp[-1].s)->var);
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",label);
  }
  else{ // si constante pas de pb
    asprintf(&(yyval.string),"%s %s%d = icmp ne i32 %s%d,0\n",(yyval.string),"%x",cond,"%x",(yyvsp[-1].s)->var);
  } 

  asprintf(&(yyval.string),"%s br i1 %s%d, label %s%d, label %s%d\n",(yyval.string),"%x",cond,"%bodywhile",label,"%endwhile",label); // test condition


  // sortie de boucle
  asprintf(&(yyval.string),"%s endwhile%d:\n\n",(yyval.string),label); // label


}
#line 3661 "grammar.c" /* yacc.c:1646  */
    break;

  case 92:
#line 2008 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = "ret void\n";}
#line 3667 "grammar.c" /* yacc.c:1646  */
    break;

  case 93:
#line 2010 "grammar.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].s)->t == ENTIER){
    if((yyvsp[-1].s)->is_var){
      int reg = var_name();
      asprintf(&(yyval.string),"%s %s%d = load i32, i32* %s%d\n",(yyvsp[-1].s)->code,"%x",reg,"%x",(yyvsp[-1].s)->var);
      asprintf(&(yyval.string),"%s ret i32 %s%d\n",(yyval.string),"%x",reg);
    }
    else{
      asprintf(&(yyval.string),"ret i32 %d",(yyvsp[-1].s)->v.n);
    }
  }
  else if((yyvsp[-1].s)->t == DOUBL){
    if((yyvsp[-1].s)->is_var){
      int reg = var_name();
      asprintf(&(yyval.string),"%s %s%d = load double, double* %s%d\n",(yyvsp[-1].s)->code,"%x",reg,"%x",(yyvsp[-1].s)->var);
      asprintf(&(yyval.string),"%s ret double %s%d\n",(yyval.string),"%x",reg);
    }
    else{
    asprintf(&(yyval.string),"ret double %lf",(yyvsp[-1].s)->v.f);
    }
  }
  else if ((yyvsp[-1].s)->t == VIDE){
    (yyval.string) = "ret void\n";
  }
}
#line 3696 "grammar.c" /* yacc.c:1646  */
    break;

  case 94:
#line 2038 "grammar.y" /* yacc.c:1646  */
    {
  FILE* fichier = fopen("test_llvm.ll","w+");
  fprintf(fichier,"%s",(yyvsp[0].string));
  fclose(fichier);
}
#line 3706 "grammar.c" /* yacc.c:1646  */
    break;

  case 95:
#line 2045 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 3712 "grammar.c" /* yacc.c:1646  */
    break;

  case 96:
#line 2046 "grammar.y" /* yacc.c:1646  */
    {asprintf(&(yyval.string),"%s%s",(yyvsp[-1].string),(yyvsp[0].string));}
#line 3718 "grammar.c" /* yacc.c:1646  */
    break;

  case 97:
#line 2050 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 3724 "grammar.c" /* yacc.c:1646  */
    break;

  case 98:
#line 2051 "grammar.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 3730 "grammar.c" /* yacc.c:1646  */
    break;

  case 99:
#line 2056 "grammar.y" /* yacc.c:1646  */
    {
  char *type;
  if ((yyvsp[-2].t) == ENTIER)
    type = "i32";
  else if((yyvsp[-2].t) == DOUBL)
    type = "double";
  else if ((yyvsp[-2].t) == VIDE)
    type = "void";
  asprintf(&(yyval.string),"define %s @%s(){\n %s \n}\n",type,(yyvsp[-1].d)->nom,(yyvsp[0].string));
}
#line 3745 "grammar.c" /* yacc.c:1646  */
    break;


#line 3749 "grammar.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 2068 "grammar.y" /* yacc.c:1906  */

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
