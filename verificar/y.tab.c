/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bison.y" /* yacc.c:337  */


/* Taken from http://www.quut.com/c/ANSI-C-grammar-y.html*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "semanticStack.h"
#include "symbolTable.h"
#define FALSE 0
#define TRUE 1

#include "semanticActions.h"


void yyerror(const char *);
void yynote(char *noteInfo, int line, int column, int writeCode, int cursorPosi);
void yywarning(char *warningInfo, int line, int column, int writeCode, int cursorPosi);
extern int getToken(void);
extern char* yytext;
extern int yylineno;
extern int column;
extern int previousColumn;
extern void print(void);
extern int nextToken;

extern char* previousToken;
extern int cursorPos;
extern int previousTokenCode;

#define yylex getToken
#define YYERROR_VERBOSE 1

int errorFound = FALSE;
int inContext = FALSE;
int unDecleared = FALSE;
int inFor = FALSE;
char* actualFunction = "";



#line 112 "y.tab.c" /* yacc.c:337  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
    I_CONSTANT = 259,
    F_CONSTANT = 260,
    STRING_LITERAL = 261,
    FUNC_NAME = 262,
    SIZEOF = 263,
    PTR_OP = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LEFT_OP = 267,
    RIGHT_OP = 268,
    LE_OP = 269,
    GE_OP = 270,
    EQ_OP = 271,
    NE_OP = 272,
    AND_OP = 273,
    OR_OP = 274,
    MUL_ASSIGN = 275,
    DIV_ASSIGN = 276,
    MOD_ASSIGN = 277,
    ADD_ASSIGN = 278,
    SUB_ASSIGN = 279,
    LEFT_ASSIGN = 280,
    RIGHT_ASSIGN = 281,
    AND_ASSIGN = 282,
    XOR_ASSIGN = 283,
    OR_ASSIGN = 284,
    TYPEDEF_NAME = 285,
    ENUMERATION_CONSTANT = 286,
    TYPEDEF = 287,
    EXTERN = 288,
    STATIC = 289,
    AUTO = 290,
    REGISTER = 291,
    INLINE = 292,
    CONST = 293,
    RESTRICT = 294,
    VOLATILE = 295,
    BOOL = 296,
    CHAR = 297,
    SHORT = 298,
    INT = 299,
    LONG = 300,
    SIGNED = 301,
    UNSIGNED = 302,
    FLOAT = 303,
    DOUBLE = 304,
    VOID = 305,
    COMPLEX = 306,
    IMAGINARY = 307,
    STRUCT = 308,
    UNION = 309,
    ENUM = 310,
    ELLIPSIS = 311,
    CASE = 312,
    DEFAULT = 313,
    IF = 314,
    ELSE = 315,
    SWITCH = 316,
    WHILE = 317,
    DO = 318,
    FOR = 319,
    GOTO = 320,
    CONTINUE = 321,
    BREAK = 322,
    RETURN = 323,
    ALIGNAS = 324,
    ALIGNOF = 325,
    ATOMIC = 326,
    GENERIC = 327,
    NORETURN = 328,
    STATIC_ASSERT = 329,
    THREAD_LOCAL = 330
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define I_CONSTANT 259
#define F_CONSTANT 260
#define STRING_LITERAL 261
#define FUNC_NAME 262
#define SIZEOF 263
#define PTR_OP 264
#define INC_OP 265
#define DEC_OP 266
#define LEFT_OP 267
#define RIGHT_OP 268
#define LE_OP 269
#define GE_OP 270
#define EQ_OP 271
#define NE_OP 272
#define AND_OP 273
#define OR_OP 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define MOD_ASSIGN 277
#define ADD_ASSIGN 278
#define SUB_ASSIGN 279
#define LEFT_ASSIGN 280
#define RIGHT_ASSIGN 281
#define AND_ASSIGN 282
#define XOR_ASSIGN 283
#define OR_ASSIGN 284
#define TYPEDEF_NAME 285
#define ENUMERATION_CONSTANT 286
#define TYPEDEF 287
#define EXTERN 288
#define STATIC 289
#define AUTO 290
#define REGISTER 291
#define INLINE 292
#define CONST 293
#define RESTRICT 294
#define VOLATILE 295
#define BOOL 296
#define CHAR 297
#define SHORT 298
#define INT 299
#define LONG 300
#define SIGNED 301
#define UNSIGNED 302
#define FLOAT 303
#define DOUBLE 304
#define VOID 305
#define COMPLEX 306
#define IMAGINARY 307
#define STRUCT 308
#define UNION 309
#define ENUM 310
#define ELLIPSIS 311
#define CASE 312
#define DEFAULT 313
#define IF 314
#define ELSE 315
#define SWITCH 316
#define WHILE 317
#define DO 318
#define FOR 319
#define GOTO 320
#define CONTINUE 321
#define BREAK 322
#define RETURN 323
#define ALIGNAS 324
#define ALIGNOF 325
#define ATOMIC 326
#define GENERIC 327
#define NORETURN 328
#define STATIC_ASSERT 329
#define THREAD_LOCAL 330

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5142

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  117
/* YYNRULES -- Number of rules.  */
#define YYNRULES  387
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  643

#define YYUNDEFTOK  2
#define YYMAXUTOK   330

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,     2,     2,     2,    92,    85,     2,
      76,    77,    86,    87,    78,    88,    82,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    99,
      93,    98,    94,    97,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    80,     2,    81,    95,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    96,    84,    89,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    72,    73,    74,    75,    77,    81,    82,
      83,    87,    91,    92,    96,    97,    98,    99,   104,   105,
     107,   111,   112,   114,   115,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   139,   140,   141,   148,   149,
     153,   157,   158,   158,   159,   159,   160,   161,   162,   163,
     171,   172,   173,   174,   175,   176,   180,   181,   188,   189,
     189,   190,   190,   191,   191,   195,   199,   200,   200,   201,
     201,   206,   210,   211,   212,   214,   218,   219,   219,   220,
     220,   221,   221,   222,   222,   224,   231,   232,   232,   233,
     233,   235,   239,   240,   240,   241,   245,   246,   246,   247,
     251,   252,   252,   253,   257,   258,   258,   259,   264,   265,
     265,   266,   271,   272,   274,   275,   279,   280,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   301,
     302,   305,   309,   313,   314,   315,   319,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   339,   340,
     341,   345,   345,   346,   347,   356,   357,   358,   359,   360,
     361,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   384,   385,   386,
     387,   388,   389,   390,   394,   395,   399,   400,   404,   405,
     406,   410,   414,   415,   416,   417,   418,   422,   423,   424,
     425,   429,   430,   431,   439,   440,   441,   442,   443,   444,
     445,   450,   451,   453,   454,   458,   459,   461,   463,   467,
     471,   472,   473,   474,   478,   479,   483,   484,   488,   489,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   511,   512,   513,   517,   518,   519,
     520,   525,   526,   527,   528,   536,   537,   542,   543,   545,
     549,   550,   551,   556,   557,   558,   562,   563,   565,   569,
     570,   572,   573,   577,   578,   579,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   609,   610,   611,
     615,   619,   620,   621,   622,   623,   624,   628,   630,   634,
     635,   639,   640,   641,   642,   646,   647,   651,   652,   653,
     654,   655,   656,   660,   661,   661,   662,   662,   664,   665,
     666,   672,   673,   673,   678,   679,   683,   684,   688,   689,
     691,   695,   695,   696,   696,   696,   699,   700,   701,   710,
     712,   712,   716,   716,   716,   717,   717,   718,   718,   718,
     719,   719,   719,   750,   751,   751,   751,   756,   757,   758,
     759,   760,   761,   762,   763,   764,   765,   766,   770,   771,
     775,   776,   780,   780,   785,   783,   793,   794
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "I_CONSTANT", "F_CONSTANT",
  "STRING_LITERAL", "FUNC_NAME", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPEDEF_NAME", "ENUMERATION_CONSTANT", "TYPEDEF", "EXTERN",
  "STATIC", "AUTO", "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE",
  "BOOL", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT",
  "DOUBLE", "VOID", "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM",
  "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF",
  "ATOMIC", "GENERIC", "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "'('",
  "')'", "','", "':'", "'['", "']'", "'.'", "'{'", "'}'", "'&'", "'*'",
  "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'",
  "'?'", "'='", "';'", "$accept", "primary_expression", "constant",
  "enumeration_constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression",
  "argument_expression_list", "unary_expression", "$@1", "$@2",
  "unary_operator", "cast_expression", "multiplicative_expression", "$@3",
  "$@4", "$@5", "additive_expression", "$@6", "$@7", "shift_expression",
  "relational_expression", "$@8", "$@9", "$@10", "$@11",
  "equality_expression", "$@12", "$@13", "and_expression", "$@14",
  "exclusive_or_expression", "$@15", "inclusive_or_expression", "$@16",
  "logical_and_expression", "$@17", "logical_or_expression", "$@18",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "$@19", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement", "$@20",
  "$@21", "compound_statement", "$@22", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "$@23", "$@24", "$@25",
  "else_statement", "$@26", "iteration_statement", "$@27", "$@28", "$@29",
  "$@30", "$@31", "$@32", "$@33", "for_prime", "$@34", "$@35",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "$@36", "$@37", "declaration_list", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,    40,    41,    44,    58,
      91,    93,    46,   123,   125,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    63,    61,    59
};
# endif

#define YYPACT_NINF -529

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-529)))

#define YYTABLE_NINF -385

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    4726,  4893,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,    92,   -37,    -1,  -529,
      57,  -529,  -529,   136,  1239,  1310,  -529,    85,  -529,  -529,
    1381,  1452,  1523,  -529,  4671,  -529,  -529,  -529,    29,   145,
    2959,  5037,  3093,  -529,   128,   563,  -529,    23,  -529,  1594,
     -14,    37,  -529,  -529,  4948,  1026,  4948,  -529,  -529,  -529,
    -529,  -529,   145,  -529,   107,   114,  -529,  4175,  -529,  -529,
    -529,  -529,  -529,  3887,  -529,  -529,  -529,   155,    53,  2959,
    -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
     574,  -529,  3975,  -529,  1856,   580,  2147,  2439,  2561,   171,
    2681,   334,   456,   232,  -529,   144,  1717,   246,  1779,   162,
     165,   168,   182,   185,  -529,  -529,  -529,   563,   216,   128,
    -529,  -529,  -529,  4726,   241,  4505,  3315,   -14,  5071,  4230,
    -529,   203,  -529,  4948,  4948,  4285,   222,  3975,  3183,   145,
      78,  -529,  4120,  3337,  -529,   -13,  -529,     7,  2959,  -529,
    3997,  3997,  5037,  3975,  3975,   764,  -529,  -529,   283,   198,
     325,  -529,  -529,  3733,  3975,   330,  -529,  3975,  -529,  -529,
    -529,  3975,  -529,  -529,  3975,  3975,  3975,  3975,  -529,  -529,
    -529,  -529,  3975,  -529,  -529,  3975,  -529,  3975,  -529,  3975,
    -529,  3975,  -529,  3975,  -529,  3975,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,   328,   336,  -529,  -529,  -529,  -529,  -529,
      26,  3755,  -529,   136,  4450,   264,  -529,  4560,  -529,  -529,
     197,   242,   326,  -529,   362,  3049,  -529,   291,   293,  3359,
    -529,  -529,  3975,  -529,    45,  -529,   301,  4340,  4395,  1097,
    -529,   145,   217,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,   304,   307,  3579,  -529,   335,   351,  3447,     7,
    4615,  3469,   345,  2959,  -529,  -529,   311,   358,    79,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    3975,  3975,  -529,  3975,   354,  3843,  -529,  -529,   370,  -529,
     273,  -529,  -529,  3975,  3975,  3975,  1879,  3975,  3975,  2013,
    2036,  2124,  2170,  3975,  3975,  3975,  3975,  2464,  3975,  3975,
    2584,  3975,  2633,  3975,  2690,  3975,  1708,  3975,  2416,   218,
    3975,   229,   364,   367,  3711,  -529,  -529,  -529,  -529,  -529,
     860,  -529,  4065,  -529,   344,  -529,  -529,  -529,  4781,  4837,
     442,  -529,   450,  3865,   377,  3071,  -529,  -529,  3975,  -529,
     382,   385,  -529,   117,   416,  -529,  3975,  -529,  1168,  -529,
    -529,  -529,  -529,   388,  3579,  -529,  -529,  3975,  -529,   389,
    -529,   403,  3579,  -529,   410,   413,  3491,   417,   384,  -529,
    5003,  5003,  5003,  -529,  -529,  -529,  -529,  3711,  -529,  3975,
    -529,  3975,  3975,  -529,  -529,  -529,  -529,  1902,  1990,  2258,
    2281,  2304,  2392,  2511,  2536,  2608,  2658,  2715,  2745,  3975,
    3975,  2772,  3975,  3975,   402,   404,  3205,   503,  -529,   252,
    3755,   129,  -529,   431,  3975,   101,   366,   375,  -529,  -529,
     436,    95,    33,    36,  2420,  -529,    83,  -529,  -529,  -529,
    -529,   770,  -529,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,   435,  -529,   438,   444,   455,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,   457,   469,  -529,  -529,
     476,  3579,  -529,  -529,  3975,  -529,   477,   417,   104,   372,
    -529,   468,   399,   401,   260,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,   481,   157,  -529,  3711,  3601,  -529,  -529,  -529,
    -529,  -529,  1649,   233,  2827,   484,  3975,  3975,  3975,   441,
     492,  2827,   950,  -529,    72,  -529,  -529,  -529,  -529,  -529,
    -529,    96,  3975,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,   488,   493,  -529,  3975,  3227,   671,  -529,
    5003,  3975,  5003,  -529,  -529,  3711,  3623,  -529,  -529,  -529,
    -529,  -529,  3755,  -529,  -529,  3755,  -529,  -529,  2827,   497,
    -529,  2827,   437,   454,   464,  3975,  3975,   516,  -529,  -529,
    -529,  -529,  3975,  -529,  -529,  -529,  -529,  -529,  -529,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,  2827,  -529,  2827,  2827,
    -529,  2827,   466,   482,   511,  2869,  2869,  -529,   528,   513,
     528,  2827,  -529,  -529,  -529,  3975,  -529,  -529,  -529,  -529,
    -529,   528,  2827,  2827,   487,   523,   523,  2827,  -529,  -529,
    -529,   505,  2827,  -529,  3975,  -529,  -529,  -529,  -529,   489,
    -529,  2827,  -529
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,   176,   155,   156,   157,   159,   160,   224,   220,
     221,   222,   170,   162,   163,   164,   165,   168,   169,   166,
     167,   161,   171,   172,   184,   185,     0,     0,   223,   225,
       0,   158,   381,     0,     0,     0,   174,     0,   175,   173,
       0,     0,     0,   135,     0,   378,   380,   147,   208,     0,
       0,     0,     0,   230,     0,   254,   133,     0,   148,     0,
     229,     0,   137,   139,     0,     0,     0,   141,   143,   145,
       1,   379,     0,    11,     0,     0,   211,     0,     2,     8,
       9,    12,    13,     0,    42,    44,    10,     0,     0,     0,
      50,    51,    52,    53,    54,    55,    25,     3,     4,     6,
      41,    56,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   223,   255,   253,   252,   136,     0,
     134,   154,   151,     0,     0,     0,     0,   228,     0,     0,
     186,     0,   190,     0,     0,     0,     0,     0,     0,   210,
       0,   204,     0,     0,   196,   274,   271,   275,     0,    47,
       0,     0,     0,     0,     0,    56,   116,   129,     0,     0,
       0,    31,    32,     0,     0,     0,    46,     0,    59,    61,
      63,     0,    67,    69,     0,     0,     0,     0,    81,    83,
      77,    79,     0,    87,    89,     0,    93,     0,    97,     0,
     101,     0,   105,     0,   109,     0,   227,   192,   272,   269,
     194,   226,   219,     0,     0,   244,   231,   256,   251,   149,
       0,     0,   386,     0,     0,   332,   385,     0,   266,   242,
     265,     0,     0,   260,     0,     0,   232,    51,     0,     0,
     180,   187,     0,   188,     0,   197,   203,     0,     0,     0,
     177,   209,     0,   206,   218,   217,   215,   214,   213,   205,
     212,   293,     0,     0,     0,   277,    51,     0,     0,   273,
       0,     0,     0,     0,    43,    45,     0,     0,     0,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   118,
       0,     7,     5,     0,     0,     0,    30,    27,     0,    38,
       0,    29,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   299,   152,   387,   383,   331,
       0,   249,     0,   263,   274,   264,   248,   241,     0,     0,
     250,   243,     0,     0,     0,     0,   233,   240,     0,   239,
      51,     0,   201,   191,     0,   189,     0,   182,     0,   178,
     207,   294,   276,     0,     0,   278,   284,     0,   283,     0,
     295,     0,     0,   285,    51,     0,     0,    48,     0,    49,
       0,     0,     0,   117,   131,   130,    37,     0,    57,    35,
      28,     0,    36,    26,    60,    62,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   302,     0,
       0,     0,   309,     2,     0,     0,     0,     0,   352,   355,
       0,     0,     0,     0,     0,   338,     0,   336,   337,   317,
     318,     0,   334,   319,   320,   321,   322,   259,   262,   257,
     261,   268,   267,   247,     0,   235,     0,     0,     0,   236,
     238,   200,   199,   198,   202,   280,     0,     0,   282,   296,
       0,     0,   286,   292,     0,   291,     0,     0,     0,     0,
      18,     0,     0,     0,     0,    40,    39,   115,   114,   113,
     316,   315,     0,     0,   312,   300,     0,   297,   301,   308,
     307,   310,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   377,     0,   375,   368,   374,   369,   372,
     370,     0,   340,   339,   333,   335,   245,   246,   234,   237,
     279,   281,   288,     0,     0,   289,     0,     0,     0,    15,
       0,     0,     0,    16,    14,     0,     0,    33,   313,   314,
     311,   305,     0,   298,   304,     0,   328,   323,     0,     0,
     330,     0,     0,     0,     0,     0,     0,     0,   360,   357,
     376,   367,   373,   371,   287,   290,    24,    23,    22,    20,
      19,    21,    34,   306,   303,   329,     0,   327,     0,     0,
     341,     0,     0,     0,     0,     0,     0,   325,   349,   129,
     349,     0,   348,   344,   353,     0,   361,   358,   350,   346,
     347,   349,     0,     0,     0,   364,   364,     0,   342,   345,
     354,     0,     0,   362,     0,   359,   351,   356,   363,     0,
     365,     0,   366
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -529,  -529,  -529,  -529,  -529,  -529,  -265,   -28,  -529,  -529,
     312,  -529,  -529,  -529,   -88,  -162,  -529,  -529,  -529,   -94,
    -529,  -529,  -149,  -177,  -529,  -529,  -529,  -529,  -170,  -529,
    -529,  -164,  -529,  -155,  -529,  -151,  -529,  -181,  -529,  -529,
    -529,   -29,    24,  -529,   -89,   -48,  -130,    30,  -529,   479,
    -529,  -529,    17,  -529,  -529,   225,   -92,   160,  -529,   -83,
    -529,   533,   -73,  -529,     1,  -529,  -529,   -22,   -54,   -49,
    -124,  -127,  -529,   -63,  -529,   -41,   -57,  -142,  -166,   212,
     -71,  -529,   179,     5,   -50,  -529,  -529,  -529,  -118,  -529,
    -529,   161,  -496,  -529,  -529,  -529,  -529,  -528,  -529,  -529,
    -529,  -529,  -529,  -529,  -529,  -529,  -529,   -15,  -529,  -529,
    -529,  -529,   569,  -529,  -529,  -529,  -529
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    96,    97,    74,    98,    99,   489,   490,   100,   298,
     165,   160,   161,   102,   103,   104,   303,   304,   305,   105,
     307,   308,   106,   107,   315,   316,   313,   314,   108,   318,
     319,   109,   321,   110,   323,   111,   325,   112,   327,   113,
     330,   166,   167,   290,   446,   115,    32,   230,    57,    58,
     221,    34,   116,    36,    37,   139,   140,   117,   244,   245,
      38,    75,    76,    39,   118,    41,    42,   246,    60,    61,
     127,   262,   232,   233,   234,   491,   263,   157,   428,   429,
     430,   431,   432,   142,   448,   449,   569,   515,   450,   340,
     451,   452,   453,   454,   611,   519,   622,   619,   627,   455,
     520,   623,   521,   606,   626,   605,   625,   633,   634,   641,
     456,    44,    45,    46,   133,   134,   224
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     168,    40,    40,   222,   122,    43,   126,   137,   231,   119,
     120,    59,   239,   269,   176,   317,   226,    35,    35,   306,
     156,   114,   328,   114,   128,   320,   579,   131,   155,   268,
      33,    47,   123,   322,   525,    40,    40,   527,   312,    50,
      53,    40,    40,    40,   324,    40,   363,   241,   169,    43,
     326,    35,    35,   241,   163,   336,   125,    35,    35,    35,
     209,    35,   135,   152,    62,    63,   136,   153,   155,   168,
      67,    68,    69,   580,    33,    51,   257,   260,   218,   258,
     391,    73,   620,   270,   532,   300,    64,   271,    65,   302,
     309,   310,   311,   628,   337,    48,   523,   582,   524,   254,
     256,   129,   514,   155,  -153,   546,   338,   220,   147,   616,
     617,   355,    72,    54,   329,   149,   331,   272,   114,   114,
      53,   276,   130,   364,   132,  -153,   492,   493,   217,   164,
     509,    53,   526,    52,    40,   528,    40,   125,    43,    53,
     374,   413,   414,   381,   365,   407,   408,   386,    73,   421,
      35,   415,    35,    40,   125,   241,   241,   392,   559,   416,
     238,   293,   259,   223,   409,   410,   411,   412,    66,    35,
     417,   581,   195,   345,   293,    49,   418,   267,   257,   260,
    -326,   344,   533,   547,   168,  -216,   215,   277,   278,   -96,
     -96,  -216,   150,    54,   362,   583,   242,   299,   151,   294,
      53,   220,   269,    55,    54,   148,    53,   398,   343,   426,
     447,   427,    54,   114,    55,   404,   405,   406,   258,   419,
      73,   206,    55,   251,   141,    40,   141,   510,    40,    43,
     422,   162,   388,   203,   568,    56,   125,   154,   560,   211,
     217,    35,   212,   346,    35,   335,   213,   208,   -96,   -96,
     -96,   204,   -96,   505,   223,   -96,   196,    47,   481,   354,
     214,   555,   216,   361,   508,   125,   -96,   -96,   -96,   217,
     -96,    40,   125,   342,   402,   295,   207,   153,   210,    54,
     471,   473,   242,    55,   291,   458,   460,    35,   373,    55,
     137,   145,   379,   344,  -150,   385,   293,   420,   154,   141,
     252,   370,   243,   141,   141,   141,   253,   293,   423,  -112,
    -112,  -112,  -324,  -112,   393,   394,  -112,   395,   474,   347,
     123,   447,   152,  -270,   225,  -270,   153,   348,   296,   205,
     506,  -112,    55,   301,   332,   199,   507,   114,   556,   561,
     564,    40,   333,    40,   557,    43,   294,    53,   339,    40,
      40,   293,  -104,  -104,   403,   531,   217,    35,   335,    35,
     292,   293,   101,   350,   101,    35,    35,   516,   247,   248,
     223,   399,   356,   548,   357,   217,   518,   464,   503,   467,
     366,   371,   468,   125,   372,   294,   513,   217,   389,   561,
     564,   497,   578,   498,   499,   159,   593,   114,   476,   594,
     552,   477,   552,  -258,   349,   114,   480,   141,   141,   154,
     486,  -104,  -104,  -104,   101,  -104,   375,   472,  -104,    53,
     342,   335,   387,   495,   153,   496,   394,   572,   573,   574,
     200,  -104,   376,  -104,   562,   565,   390,   396,   419,   351,
     352,   424,   517,   394,   425,   461,   394,   400,   401,   549,
     550,  -343,    40,   462,   335,   599,    43,   201,   465,   101,
     101,   487,   567,   469,   570,   419,   470,   419,    35,   475,
     478,   577,   274,   275,   202,  -108,   553,   550,   554,   550,
     479,   223,   217,   419,   562,   565,   602,   603,   419,   101,
     419,   482,    54,   101,   483,   242,   101,   101,   101,   101,
     397,   500,    55,   501,   101,   543,   504,   101,   544,   101,
     512,   101,   522,   101,   598,   293,   536,   575,   595,   537,
     589,   597,   590,    40,   589,   538,   624,    43,   154,   335,
     335,   600,   293,  -108,  -108,  -108,   539,  -108,   540,    35,
    -108,   601,   293,   613,   293,   639,   607,   551,   608,   610,
     541,   612,   223,  -108,   101,  -108,   394,   542,   545,   614,
     293,   621,   558,   571,   631,   293,   640,   293,   576,   584,
     586,   588,   629,   630,   585,   591,   596,   636,   604,   335,
     335,   181,   638,   170,   171,   172,   335,   615,   618,   335,
    -131,   642,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     632,     9,    10,    11,   637,   146,   394,   101,   219,   494,
     511,   635,   535,    71,     0,   101,   101,   101,     0,   101,
     101,     0,     0,   609,     0,   101,   101,   101,   101,     0,
     101,   101,     0,   101,   124,   101,     0,   101,     0,   101,
       0,     0,   101,     0,     0,     0,     0,     0,     0,    55,
     173,     0,     0,     0,   174,     0,   175,   -72,   -72,   -72,
       0,   -72,     0,     0,   -72,   -72,     0,   182,   183,     0,
       0,     0,    77,   -72,   -72,   -72,   -72,   -72,   101,   -72,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,     2,     0,     0,     0,     0,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,   488,
       0,     0,   101,     0,     0,   101,     0,     0,   101,     0,
       0,     0,    28,     0,     0,     0,   101,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,     0,   -17,   -17,   -17,   -17,   -17,
       0,     0,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,     1,     0,   433,    79,    80,    81,    82,    83,     0,
      84,    85,     0,     0,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,     0,     0,     0,     0,     0,     0,
       2,    86,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,   434,   435,   436,
       0,   437,   438,   439,   440,   441,   442,   443,   444,    27,
      87,    28,    88,    29,    30,    31,    89,     0,     0,     0,
       0,     0,     0,   225,   534,    90,    91,    92,    93,    94,
      95,     1,   289,   433,    79,    80,    81,    82,    83,   445,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,    86,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,   434,   435,   436,
       0,   437,   438,   439,   440,   441,   442,   443,   444,    27,
      87,    28,    88,    29,    30,    31,    89,     0,     0,     0,
       0,     0,     0,   225,     0,    90,    91,    92,    93,    94,
      95,     1,     0,    78,    79,    80,    81,    82,    83,   445,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,    86,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      87,    28,    88,    29,    30,    31,    89,   143,     0,  -179,
       0,     0,     0,     0,     0,    90,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,   445,
       0,     0,     0,     0,     0,     0,  -179,     0,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -179,     0,  -179,   138,  -179,
    -183,  -179,  -179,  -179,  -179,  -179,  -179,     0,     0,   144,
       0,     0,  -179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -179,     0,     2,     0,  -183,
    -183,  -183,  -183,  -183,  -183,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -183,     0,    28,   138,
    -183,  -181,  -183,  -183,  -183,  -183,  -183,  -183,     0,     0,
       0,     0,     0,  -183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -183,     0,     2,     0,
    -181,  -181,  -181,  -181,  -181,  -181,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -181,     0,    28,
       1,  -181,  -138,  -181,  -181,  -181,  -181,  -181,  -181,     0,
       0,     0,     0,     0,  -181,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -181,     0,     2,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
      28,     1,    29,  -140,    31,  -138,  -138,  -138,     0,  -138,
       0,     0,     0,     0,     0,  -138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -138,     0,
       2,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,    28,     1,    29,  -142,    31,  -140,  -140,  -140,     0,
    -140,     0,     0,     0,     0,     0,  -140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -140,
       0,     2,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    28,     1,    29,  -144,    31,  -142,  -142,  -142,
       0,  -142,     0,     0,     0,     0,     0,  -142,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -142,     0,     2,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,    28,     1,    29,  -146,    31,  -144,  -144,
    -144,     0,  -144,     0,     0,     0,     0,     0,  -144,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -144,     0,     2,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,    28,   131,    29,     0,    31,  -146,
    -146,  -146,     0,  -146,     0,     0,     0,     0,     0,  -146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -146,     0,  -382,     0,  -382,  -382,  -382,  -382,
    -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,
    -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,
     566,     0,   433,    79,    80,    81,    82,    83,     0,    84,
      85,     0,     0,  -382,     0,  -382,     0,  -382,  -382,  -382,
       0,     0,  -153,     0,     0,     0,     0,  -384,     0,     0,
      86,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   132,  -153,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   434,   435,   436,   199,
     437,   438,   439,   440,   441,   442,   443,   444,   138,    87,
    -193,    88,     0,     0,     0,    89,  -107,  -107,     0,     0,
       0,     0,   225,     0,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     2,   445,     0,
       0,     0,     0,     0,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
     138,     0,  -195,     0,     0,  -107,  -107,  -107,    28,  -107,
       0,     0,  -107,  -193,  -193,     0,  -193,  -193,     0,     0,
       0,     0,     0,  -193,   200,  -107,     0,  -107,     0,     2,
       0,     0,     0,     0,     0,     0,  -193,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,     0,     0,     0,     0,  -195,  -195,   177,  -195,  -195,
       0,     0,     0,     0,     0,  -195,     0,     0,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,     0,     0,  -195,     0,
     177,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,     0,
       0,     0,     0,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -66,   -66,   -66,     0,   -66,     0,     0,
     -66,   -66,   178,   -66,   -66,     0,     0,   179,   180,   -66,
     -66,   -66,   -66,   -66,     0,   -66,   -71,   -71,   -71,     0,
     -71,     0,     0,   -71,   -71,   178,   -71,   -71,     0,     0,
     179,   180,   -71,   -71,   -71,   -71,   -71,     0,   -71,   -68,
     -68,   -68,     0,   -68,     0,     0,   -68,   -68,   178,   -68,
     -68,   177,     0,   179,   180,   -68,   -68,   -68,   -68,   -68,
       0,   -68,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
       0,     0,     0,     0,   181,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,     0,     0,     0,     0,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -70,   -70,   -70,
       0,   -70,     0,     0,   -70,   -70,   178,   -70,   -70,     0,
       0,   179,   180,   -70,   -70,   -70,   -70,   -70,     0,   -70,
     -75,   -75,   -75,     0,   -75,     0,     0,   -75,   -75,     0,
     182,   183,     0,     0,     0,     0,   -75,   -75,   -75,   -75,
     -75,     0,   -75,   -73,   -73,   -73,     0,   -73,     0,     0,
     -73,   -73,     0,   182,   183,   181,     0,     0,     0,   -73,
     -73,   -73,   -73,   -73,     0,   -73,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,     0,     0,     0,     0,   184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   185,
     186,   -76,   -76,   -76,   -76,   -76,   -76,     0,     0,     0,
       0,   184,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,   186,   -85,   -85,   -85,   -85,   -85,   -85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -74,   -74,   -74,     0,   -74,     0,     0,   -74,   -74,
       0,   182,   183,     0,     0,     0,     0,   -74,   -74,   -74,
     -74,   -74,     0,   -74,   -76,   -76,   -76,     0,   -76,     0,
       0,   -76,   -76,     0,     0,     0,     0,     0,     0,     0,
     -76,   -76,   -76,   -76,   -76,     0,   -76,   -85,   -85,   -85,
       0,   -85,     0,     0,   -85,   -85,     0,     0,     0,   184,
       0,     0,     0,   -85,   -85,   -85,   -85,   -85,     0,   -85,
     185,   186,   -82,   -82,   -82,   -82,   -82,   -82,     0,     0,
       0,     0,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,   186,   -84,   -84,   -84,   -84,   -84,
     -84,     0,     0,     0,     0,   184,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   185,   186,   -78,   -78,
     -78,   -78,   -78,   -78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -82,   -82,   -82,     0,   -82,
       0,     0,   -82,   -82,     0,     0,     0,     0,     0,     0,
       0,   -82,   -82,   -82,   -82,   -82,     0,   -82,   -84,   -84,
     -84,     0,   -84,     0,     0,   -84,   -84,     0,     0,     0,
       0,     0,     0,     0,   -84,   -84,   -84,   -84,   -84,     0,
     -84,   -78,   -78,   -78,     0,   -78,     0,     0,   -78,   -78,
       0,     0,     0,   184,     0,     0,     0,   -78,   -78,   -78,
     -78,   -78,     0,   -78,   185,   186,   -80,   -80,   -80,   -80,
     -80,   -80,     0,     0,     0,     0,     0,   201,     0,     0,
       0,   529,     0,    78,    79,    80,    81,    82,    83,     0,
      84,    85,     0,     0,   202,  -108,     0,     0,     0,     0,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,     0,   188,   189,   -86,   -86,   -86,   -86,     0,
       0,     0,     0,     0,     0,   187,     0,     0,     0,   -80,
     -80,   -80,     0,   -80,     0,     0,   -80,   -80,   188,   189,
     -91,   -91,   -91,   -91,     0,   -80,   -80,   -80,   -80,   -80,
      87,   -80,    88,  -111,  -108,  -108,    89,  -111,     0,     0,
    -111,     0,     0,     0,     0,    90,    91,    92,    93,    94,
      95,     0,   187,  -108,     0,  -111,   -86,   -86,   -86,   530,
     -86,     0,     0,   -86,   -86,   188,   189,   -88,   -88,   -88,
     -88,     0,   190,   191,   -86,   -86,   -86,   187,   -86,     0,
       0,   -91,   -91,   -91,     0,   -91,     0,     0,   -91,   -91,
     188,   189,   -90,   -90,   -90,   -90,     0,   190,   191,   -91,
     -91,   -91,   192,   -91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,   194,   -92,
     -92,     0,     0,     0,     0,   192,     0,     0,   -88,   -88,
     -88,     0,   -88,     0,     0,   -88,   -88,     0,     0,     0,
     193,   194,   -95,   -95,   190,   191,   -88,   -88,   -88,   192,
     -88,     0,     0,   -90,   -90,   -90,     0,   -90,     0,     0,
     -90,   -90,     0,     0,   193,   194,   -94,   -94,     0,   190,
     191,   -90,   -90,   -90,   195,   -90,     0,     0,   -92,   -92,
     -92,     0,   -92,     0,     0,   -92,   -92,     0,     0,     0,
       0,   -99,   -99,     0,     0,     0,   -92,   -92,   -92,   195,
     -92,   -95,   -95,   -95,     0,   -95,     0,     0,   -95,   -95,
       0,     0,     0,     0,     0,     0,   -98,   -98,     0,   -95,
     -95,   -95,   197,   -95,     0,   -94,   -94,   -94,     0,   -94,
       0,   197,   -94,   -94,     0,     0,     0,     0,     0,  -100,
    -100,     0,     0,   -94,   -94,   -94,     0,   -94,  -103,  -103,
     -99,   -99,   -99,     0,   -99,     0,   197,   -99,   196,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -99,   -99,
     -99,     0,   -99,  -102,  -102,   -98,   -98,   -98,     0,   -98,
       0,     0,   -98,   196,     0,     0,   199,     0,     0,     0,
       0,     0,     0,   -98,   -98,   -98,     0,   -98,  -100,  -100,
    -100,     0,  -100,  -106,  -106,  -100,     0,  -103,  -103,  -103,
       0,  -103,     0,   201,  -103,     0,   198,  -100,  -100,     0,
    -100,     0,     0,     0,     0,   198,  -103,  -103,     0,  -103,
     202,  -110,  -102,  -102,  -102,     0,  -102,     0,     0,  -102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     198,  -102,  -102,     0,  -102,     0,     0,     0,     0,     0,
       0,     0,  -106,  -106,  -106,     0,  -106,     0,     0,  -106,
     433,    79,    80,    81,    82,    83,     0,    84,    85,     0,
       0,   200,  -106,     0,  -106,     0,     0,     0,     0,  -110,
    -110,  -110,     0,  -110,     0,     0,  -110,     0,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -110,
       0,  -110,    78,    79,    80,    81,    82,    83,     0,    84,
      85,     0,     0,     0,   434,   435,   436,     0,   437,   438,
     439,   440,   441,   442,   443,   444,     0,    87,     0,    88,
      86,     0,     0,    89,     0,     0,     0,     0,     0,     0,
     225,     0,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,   445,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,    88,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
      77,     0,    78,    79,    80,    81,    82,    83,   445,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
      86,     0,     0,     0,     0,     0,     0,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      28,    88,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
     353,     0,    78,    79,    80,    81,    82,    83,     0,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   466,     0,    78,    79,    80,    81,    82,    83,
      86,    84,    85,     0,     0,     0,     0,     9,    10,    11,
       0,     0,     0,     0,   121,     0,    78,    79,    80,    81,
      82,    83,    86,    84,    85,     0,     0,     0,     0,     9,
      10,    11,     0,     0,     0,     0,     0,     0,     0,    87,
     124,    88,     0,     0,    86,    89,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
       0,    87,   124,    88,     0,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    91,    92,    93,
      94,    95,     0,    87,     0,    88,     0,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,   255,     0,    78,    79,    80,    81,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   502,     0,    78,    79,
      80,    81,    82,    83,    86,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   587,     0,
      78,    79,    80,    81,    82,    83,    86,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,    88,     0,     0,    86,    89,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,     0,    87,     0,    88,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,     0,    87,     0,    88,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,    78,    79,
      80,    81,    82,    83,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    86,    84,    85,   235,
       0,     0,     0,     9,    10,    11,     0,     0,     0,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    86,    84,
      85,   264,     0,     0,     0,     9,    10,    11,     0,     0,
       0,     0,     0,     0,     0,    87,   124,    88,     0,     0,
      86,    89,     0,   358,     0,     0,   236,     9,    10,    11,
      90,   237,    92,    93,    94,    95,     0,    87,   124,    88,
       0,     0,     0,    89,     0,     0,     0,     0,   265,     0,
       0,     0,    90,   266,    92,    93,    94,    95,     0,    87,
     124,    88,     0,     0,     0,    89,     0,     0,     0,     0,
     359,     0,     0,     0,    90,   360,    92,    93,    94,    95,
      78,    79,    80,    81,    82,    83,     0,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    86,    84,
      85,   377,     0,     0,     0,     9,    10,    11,     0,     0,
       0,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      86,    84,    85,   382,     0,     0,     0,     9,    10,    11,
       0,     0,     0,     0,     0,     0,     0,    87,   124,    88,
       0,     0,    86,    89,     0,   484,     0,     0,   378,     9,
      10,    11,    90,    91,    92,    93,    94,    95,     0,    87,
     124,    88,     0,     0,     0,    89,     0,     0,     0,     0,
     383,     0,     0,     0,    90,   384,    92,    93,    94,    95,
       0,    87,   124,    88,     0,     0,     0,    89,     0,     0,
       0,     0,   485,     0,     0,     0,    90,    91,    92,    93,
      94,    95,    78,    79,    80,    81,    82,    83,     0,    84,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      86,    84,    85,     0,     0,     0,     0,     9,    10,    11,
       0,     0,     0,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    86,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
     124,    88,     0,     0,    86,    89,     0,     0,     0,     0,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
       0,    87,     0,    88,     0,     0,     0,    89,     0,     0,
       0,   426,     0,   427,   334,   563,    90,    91,    92,    93,
      94,    95,     0,    87,     0,    88,     0,     0,     0,    89,
       0,     0,     0,   426,     0,   427,   334,   592,    90,    91,
      92,    93,    94,    95,    78,    79,    80,    81,    82,    83,
       0,    84,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    86,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    86,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,    88,     0,     0,    86,    89,     0,     0,
       0,   426,     0,   427,   334,     0,    90,    91,    92,    93,
      94,    95,     0,    87,     0,    88,     0,     0,     0,    89,
     297,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,    93,    94,    95,     0,    87,     0,    88,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,   334,     0,
      90,    91,    92,    93,    94,    95,    78,    79,    80,    81,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,    79,
      80,    81,    82,    83,    86,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    86,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,    88,     0,     0,    86,    89,
       0,     0,     0,     0,     0,     0,   397,     0,    90,    91,
      92,    93,    94,    95,     0,    87,     0,    88,     0,     0,
       0,    89,     0,     0,     0,     0,   463,     0,     0,     0,
      90,    91,    92,    93,    94,    95,     0,    87,     0,    88,
       0,     0,     0,   158,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,    78,    79,
      80,    81,    82,    83,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    86,    84,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,    88,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,     1,    87,    53,    88,
       0,     0,     0,   273,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,    28,     0,    29,     0,
      31,   342,   261,     0,     0,   153,     0,     0,     0,     0,
       2,    55,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,    28,     0,    29,     0,    31,   152,   261,     0,     0,
     153,     0,     0,     0,     0,     2,    55,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
       0,   152,     0,     0,     0,   153,     0,     0,     0,     0,
       2,    55,     0,     0,     0,     0,     0,     0,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,     2,     0,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
       2,     0,     0,     0,     0,     0,     0,     0,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   368,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   367,     2,     0,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   369,
       2,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   227,     0,   228,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,    28,     0,    29,    30,    31,     0,     0,     0,     0,
       0,     0,     0,   225,     0,     2,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,    28,     0,    29,     0,
      31,     0,   229,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,    28,     0,    29,     0,    31,     0,   341,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    70,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,    28,     0,    29,     0,
      31,     0,   380,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    28,     0,    29,    30,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,    28,     0,    29,
      30,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   457,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    28,     0,    29,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   459,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,    28,     0,
      29,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,    28,     0,    29,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,    77,     0,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     0,
       0,   488,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     0,   138,     0,    28,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,     0,    28,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28
};

static const yytype_int16 yycheck[] =
{
      89,     0,     1,   133,    52,     0,    55,    61,   135,    50,
      51,    33,   136,   155,   102,   192,   134,     0,     1,   181,
      77,    50,   203,    52,     1,   195,   522,     1,    77,   153,
       0,     1,    54,   197,     1,    34,    35,     1,   187,    76,
       3,    40,    41,    42,   199,    44,     1,   139,    89,    44,
     201,    34,    35,   145,     1,   221,    55,    40,    41,    42,
     117,    44,    76,    76,    34,    35,    80,    80,   117,   158,
      40,    41,    42,     1,    44,    76,   149,   150,   127,     1,
       1,     3,   610,    76,     1,   174,     1,    80,     3,   177,
     184,   185,   186,   621,   224,     3,     1,     1,     3,   147,
     148,    78,     1,   152,    78,     1,   224,   129,     1,   605,
     606,   235,    83,    76,   203,     1,   205,   158,   147,   148,
       3,   162,    99,    78,    98,    99,   391,   392,   127,    76,
       1,     3,    99,    76,   133,    99,   135,   136,   133,     3,
     264,   318,   319,   270,    99,   307,   308,   271,     3,   330,
     133,   321,   135,   152,   153,   247,   248,    78,     1,   323,
     136,    78,    84,   133,   313,   314,   315,   316,    83,   152,
     325,    99,     1,   230,    78,    83,   327,   153,   251,   252,
      79,   230,    99,    79,   273,    78,     1,   163,   164,    18,
      19,    84,    78,    76,   242,    99,    79,   173,    84,     1,
       3,   223,   344,    86,    76,    98,     3,   295,   230,    80,
     340,    82,    76,   242,    86,   303,   304,   305,     1,     1,
       3,    77,    86,     1,    64,   224,    66,    98,   227,   224,
       1,    76,   273,     1,     1,    99,   235,    77,    81,    77,
     239,   224,    77,     1,   227,   221,    78,     1,    77,    78,
      79,    19,    81,     1,   224,    84,    85,   227,   382,   235,
      78,     1,    77,   239,   430,   264,    95,    96,    97,   268,
      99,   270,   271,    76,     1,    77,   116,    80,   118,    76,
     363,   364,    79,    86,     1,   348,   349,   270,   264,    86,
     344,    66,   268,   342,    78,   271,    78,    79,   138,   139,
      78,    84,    99,   143,   144,   145,    84,    78,    79,    77,
      78,    79,    79,    81,   290,   291,    84,   293,   366,    77,
     342,   451,    76,    77,    83,    79,    80,     1,     3,    97,
      78,    99,    86,     3,     6,     1,    84,   366,    78,   505,
     506,   340,     6,   342,    84,   340,     1,     3,    84,   348,
     349,    78,    18,    19,    81,   444,   355,   340,   334,   342,
      77,    78,    50,     1,    52,   348,   349,     1,   143,   144,
     340,     1,    81,     1,    81,   374,     1,   353,   426,   355,
      79,    77,   358,   382,    77,     1,   434,   386,    77,   555,
     556,   420,   522,   422,   423,    83,   562,   426,   374,   565,
       1,   377,     1,    77,    78,   434,   382,   247,   248,   249,
     386,    77,    78,    79,   102,    81,    81,     1,    84,     3,
      76,   397,    77,   399,    80,   401,   402,   516,   517,   518,
      96,    97,    81,    99,   505,   506,    78,    83,     1,    77,
      78,    77,    76,   419,    77,     3,   422,    77,    78,    77,
      78,    76,   451,     3,   430,     1,   451,     1,    81,   147,
     148,    77,   512,    81,   514,     1,    81,     1,   451,    81,
      81,   521,   160,   161,    18,    19,    77,    78,    77,    78,
      77,   451,   481,     1,   555,   556,   575,   576,     1,   177,
       1,    81,    76,   181,    81,    79,   184,   185,   186,   187,
      83,    99,    86,    99,   192,   481,     3,   195,   484,   197,
      79,   199,    76,   201,    77,    78,    81,    76,   568,    81,
     548,   571,   550,   522,   552,    81,   615,   522,   368,   505,
     506,    77,    78,    77,    78,    79,    81,    81,    81,   522,
      84,    77,    78,    77,    78,   634,   596,    79,   598,   599,
      81,   601,   522,    97,   242,    99,   532,    81,    81,    77,
      78,   611,    81,    79,    77,    78,    77,    78,    76,    81,
     546,   547,   622,   623,    81,   551,    79,   627,    62,   555,
     556,     1,   632,     9,    10,    11,   562,    76,    60,   565,
      77,   641,    12,    13,    14,    15,    16,    17,    18,    19,
      77,    38,    39,    40,    99,    72,   582,   295,   129,   397,
     431,   626,   451,    44,    -1,   303,   304,   305,    -1,   307,
     308,    -1,    -1,   599,    -1,   313,   314,   315,   316,    -1,
     318,   319,    -1,   321,    71,   323,    -1,   325,    -1,   327,
      -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      76,    -1,    -1,    -1,    80,    -1,    82,    77,    78,    79,
      -1,    81,    -1,    -1,    84,    85,    -1,    87,    88,    -1,
      -1,    -1,     1,    93,    94,    95,    96,    97,   366,    99,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    58,
      -1,    -1,   420,    -1,    -1,   423,    -1,    -1,   426,    -1,
      -1,    -1,    71,    -1,    -1,    -1,   434,    76,    77,    78,
      79,    80,    81,    82,    -1,    84,    85,    86,    87,    88,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      90,     1,    98,     3,     4,     5,     6,     7,     8,    99,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,    89,
      90,     1,    -1,     3,     4,     5,     6,     7,     8,    99,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,     1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,     1,    73,
       3,    75,    76,    77,    78,    79,    80,    -1,    -1,    83,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,     1,
      73,     3,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
       1,    73,     3,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,     1,    73,     3,    75,    76,    77,    78,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,     1,    73,     3,    75,    76,    77,    78,    -1,
      80,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,     1,    73,     3,    75,    76,    77,    78,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,     1,    73,     3,    75,    76,    77,
      78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,     1,    73,    -1,    75,    76,
      77,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    69,    -1,    71,    -1,    73,    74,    75,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    83,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,     1,
      61,    62,    63,    64,    65,    66,    67,    68,     1,    70,
       3,    72,    -1,    -1,    -1,    76,    18,    19,    -1,    -1,
      -1,    -1,    83,    -1,    85,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,    -1,    -1,    77,    78,    79,    71,    81,
      -1,    -1,    84,    76,    77,    -1,    79,    80,    -1,    -1,
      -1,    -1,    -1,    86,    96,    97,    -1,    99,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    76,    77,     1,    79,    80,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    99,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    81,    -1,    -1,
      84,    85,    86,    87,    88,    -1,    -1,    91,    92,    93,
      94,    95,    96,    97,    -1,    99,    77,    78,    79,    -1,
      81,    -1,    -1,    84,    85,    86,    87,    88,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    -1,    99,    77,
      78,    79,    -1,    81,    -1,    -1,    84,    85,    86,    87,
      88,     1,    -1,    91,    92,    93,    94,    95,    96,    97,
      -1,    99,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    81,    -1,    -1,    84,    85,    86,    87,    88,    -1,
      -1,    91,    92,    93,    94,    95,    96,    97,    -1,    99,
      77,    78,    79,    -1,    81,    -1,    -1,    84,    85,    -1,
      87,    88,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    -1,    99,    77,    78,    79,    -1,    81,    -1,    -1,
      84,    85,    -1,    87,    88,     1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    -1,    99,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    81,    -1,    -1,    84,    85,
      -1,    87,    88,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    -1,    99,    77,    78,    79,    -1,    81,    -1,
      -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    -1,    99,    77,    78,    79,
      -1,    81,    -1,    -1,    84,    85,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    -1,    99,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    81,
      -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    -1,    99,    77,    78,
      79,    -1,    81,    -1,    -1,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,    -1,
      99,    77,    78,    79,    -1,    81,    -1,    -1,    84,    85,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    -1,    99,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    77,
      78,    79,    -1,    81,    -1,    -1,    84,    85,    14,    15,
      16,    17,    18,    19,    -1,    93,    94,    95,    96,    97,
      70,    99,    72,    77,    78,    79,    76,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,    -1,     1,    97,    -1,    99,    77,    78,    79,    99,
      81,    -1,    -1,    84,    85,    14,    15,    16,    17,    18,
      19,    -1,    93,    94,    95,    96,    97,     1,    99,    -1,
      -1,    77,    78,    79,    -1,    81,    -1,    -1,    84,    85,
      14,    15,    16,    17,    18,    19,    -1,    93,    94,    95,
      96,    97,     1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,     1,    -1,    -1,    77,    78,
      79,    -1,    81,    -1,    -1,    84,    85,    -1,    -1,    -1,
      16,    17,    18,    19,    93,    94,    95,    96,    97,     1,
      99,    -1,    -1,    77,    78,    79,    -1,    81,    -1,    -1,
      84,    85,    -1,    -1,    16,    17,    18,    19,    -1,    93,
      94,    95,    96,    97,     1,    99,    -1,    -1,    77,    78,
      79,    -1,    81,    -1,    -1,    84,    85,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    95,    96,    97,     1,
      99,    77,    78,    79,    -1,    81,    -1,    -1,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    95,
      96,    97,     1,    99,    -1,    77,    78,    79,    -1,    81,
      -1,     1,    84,    85,    -1,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,    95,    96,    97,    -1,    99,    18,    19,
      77,    78,    79,    -1,    81,    -1,     1,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    -1,    99,    18,    19,    77,    78,    79,    -1,    81,
      -1,    -1,    84,    85,    -1,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    -1,    99,    77,    78,
      79,    -1,    81,    18,    19,    84,    -1,    77,    78,    79,
      -1,    81,    -1,     1,    84,    -1,    95,    96,    97,    -1,
      99,    -1,    -1,    -1,    -1,    95,    96,    97,    -1,    99,
      18,    19,    77,    78,    79,    -1,    81,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    81,    -1,    -1,    84,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    96,    97,    -1,    99,    -1,    -1,    -1,    -1,    77,
      78,    79,    -1,    81,    -1,    -1,    84,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    99,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    -1,    72,
      31,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    85,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
       1,    -1,     3,     4,     5,     6,     7,     8,    99,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
       1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
      31,    10,    11,    -1,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,    31,    10,    11,    -1,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    31,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,     1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,    31,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,    31,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    31,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    70,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    70,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    31,    10,    11,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    31,    10,
      11,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,
      31,    76,    -1,    34,    -1,    -1,    81,    38,    39,    40,
      85,    86,    87,    88,    89,    90,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    31,    10,
      11,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      31,    10,    11,    34,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,    31,    76,    -1,    34,    -1,    -1,    81,    38,
      39,    40,    85,    86,    87,    88,    89,    90,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      31,    10,    11,    -1,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    31,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    31,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    80,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    80,    -1,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    31,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    31,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    31,    76,    -1,    -1,
      -1,    80,    -1,    82,    83,    -1,    85,    86,    87,    88,
      89,    90,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    70,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      85,    86,    87,    88,    89,    90,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    31,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    31,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    31,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,
      87,    88,    89,    90,    -1,    70,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    70,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    31,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,     1,    70,     3,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    -1,
      75,    76,    77,    -1,    -1,    80,    -1,    -1,    -1,    -1,
      30,    86,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    -1,    75,    76,    77,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    30,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,
      30,    86,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    -1,
      75,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    -1,
      75,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    -1,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    -1,    73,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,
      73,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,     1,    -1,    71,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    71,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    30,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    69,    71,    73,
      74,    75,   146,   147,   151,   152,   153,   154,   160,   163,
     164,   165,   166,   183,   211,   212,   213,   147,     3,    83,
      76,    76,    76,     3,    76,    86,    99,   148,   149,   167,
     168,   169,   147,   147,     1,     3,    83,   147,   147,   147,
       0,   212,    83,     3,   103,   161,   162,     1,     3,     4,
       5,     6,     7,     8,    10,    11,    31,    70,    72,    76,
      85,    86,    87,    88,    89,    90,   101,   102,   104,   105,
     108,   110,   113,   114,   115,   119,   122,   123,   128,   131,
     133,   135,   137,   139,   141,   145,   152,   157,   164,   175,
     175,     1,   145,   167,    71,   164,   169,   170,     1,    78,
      99,     1,    98,   214,   215,    76,    80,   168,     1,   155,
     156,   157,   183,     1,    83,   155,   161,     1,    98,     1,
      78,    84,    76,    80,   157,   169,   176,   177,    76,   110,
     111,   112,    76,     1,    76,   110,   141,   142,   144,   175,
       9,    10,    11,    76,    80,    82,   114,     1,    86,    91,
      92,     1,    87,    88,     1,    12,    13,     1,    14,    15,
      93,    94,     1,    16,    17,     1,    85,     1,    95,     1,
      96,     1,    18,     1,    19,    97,    77,   157,     1,   176,
     157,    77,    77,    78,    78,     1,    77,   164,   169,   149,
     167,   150,   146,   147,   216,    83,   188,     1,     3,    77,
     147,   171,   172,   173,   174,    34,    81,    86,   142,   170,
      84,   156,    79,    99,   158,   159,   167,   155,   155,     1,
      84,     1,    78,    84,   145,     1,   145,   162,     1,    84,
     162,    77,   171,   176,    34,    81,    86,   142,   170,   177,
      76,    80,   175,    76,   110,   110,   175,   142,   142,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    98,
     143,     1,    77,    78,     1,    77,     3,    77,   109,   142,
     144,     3,   114,   116,   117,   118,   115,   120,   121,   119,
     119,   119,   122,   126,   127,   124,   125,   123,   129,   130,
     128,   132,   131,   134,   133,   136,   135,   138,   137,   144,
     140,   144,     6,     6,    83,   142,   178,   146,   188,    84,
     189,    77,    76,   167,   169,   176,     1,    77,     1,    78,
       1,    77,    78,     1,   142,   170,    81,    81,    34,    81,
      86,   142,   145,     1,    78,    99,    79,    84,     1,    84,
      84,    77,    77,   142,   170,    81,    81,    34,    81,   142,
      77,   171,    34,    81,    86,   142,   170,    77,   175,    77,
      78,     1,    78,   142,   142,   142,    83,    83,   114,     1,
      77,    78,     1,    81,   114,   114,   114,   115,   115,   122,
     122,   122,   122,   123,   123,   128,   131,   133,   135,     1,
      79,   137,     1,    79,    77,    77,    80,    82,   178,   179,
     180,   181,   182,     3,    57,    58,    59,    61,    62,    63,
      64,    65,    66,    67,    68,    99,   144,   146,   184,   185,
     188,   190,   191,   192,   193,   199,   210,    56,   173,    56,
     173,     3,     3,    81,   142,    81,     1,   142,   142,    81,
      81,   159,     1,   159,   145,    81,   142,   142,    81,    77,
     142,   170,    81,    81,    34,    81,   142,    77,    58,   106,
     107,   175,   106,   106,   179,   142,   142,   141,   141,   141,
      99,    99,     1,   145,     3,     1,    78,    84,   178,     1,
      98,   182,    79,   145,     1,   187,     1,    76,     1,   195,
     200,   202,    76,     1,     3,     1,    99,     1,    99,     1,
      99,   144,     1,    99,    84,   191,    81,    81,    81,    81,
      81,    81,    81,   142,   142,    81,     1,    79,     1,    77,
      78,    79,     1,    77,    77,     1,    78,    84,    81,     1,
      81,   178,   180,    84,   178,   180,     1,   184,     1,   186,
     184,    79,   144,   144,   144,    76,    76,   184,   146,   192,
       1,    99,     1,    99,    81,    81,   142,     1,   142,   107,
     107,   142,    84,   178,   178,   184,    79,   184,    77,     1,
      77,    77,   144,   144,    62,   205,   203,   184,   184,   142,
     184,   194,   184,    77,    77,    76,   192,   192,    60,   197,
     197,   184,   196,   201,   144,   206,   204,   198,   197,   184,
     184,    77,    77,   207,   208,   207,   184,    99,   184,   144,
      77,   209,   184
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   101,   101,   101,   101,   101,   102,   102,
     102,   103,   104,   104,   105,   105,   105,   105,   106,   106,
     106,   107,   107,   107,   107,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     109,   110,   111,   110,   112,   110,   110,   110,   110,   110,
     113,   113,   113,   113,   113,   113,   114,   114,   115,   116,
     115,   117,   115,   118,   115,   115,   119,   120,   119,   121,
     119,   119,   122,   122,   122,   122,   123,   124,   123,   125,
     123,   126,   123,   127,   123,   123,   128,   129,   128,   130,
     128,   128,   131,   132,   131,   131,   133,   134,   133,   133,
     135,   136,   135,   135,   137,   138,   137,   137,   139,   140,
     139,   139,   141,   141,   141,   141,   142,   142,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   144,
     144,   144,   145,   146,   146,   146,   146,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   148,   148,
     148,   150,   149,   149,   149,   151,   151,   151,   151,   151,
     151,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   153,   153,   153,
     153,   153,   153,   153,   154,   154,   155,   155,   156,   156,
     156,   156,   157,   157,   157,   157,   157,   158,   158,   158,
     158,   159,   159,   159,   160,   160,   160,   160,   160,   160,
     160,   161,   161,   161,   161,   162,   162,   162,   162,   163,
     164,   164,   164,   164,   165,   165,   166,   166,   167,   167,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   169,   169,   169,   169,   170,   170,   171,   171,   171,
     172,   172,   172,   173,   173,   173,   174,   174,   174,   175,
     175,   175,   175,   176,   176,   176,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   178,   178,   178,
     178,   179,   179,   179,   179,   179,   179,   180,   180,   181,
     181,   182,   182,   182,   182,   183,   183,   184,   184,   184,
     184,   184,   184,   185,   186,   185,   187,   185,   185,   185,
     185,   188,   189,   188,   190,   190,   191,   191,   192,   192,
     192,   194,   193,   195,   196,   193,   193,   193,   193,   197,
     198,   197,   200,   201,   199,   202,   199,   203,   204,   199,
     205,   206,   199,   207,   208,   209,   207,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   211,   211,
     212,   212,   214,   213,   215,   213,   216,   216
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     6,     6,     6,     6,     1,     3,
       3,     3,     3,     3,     3,     1,     4,     3,     4,     3,
       3,     2,     2,     6,     7,     4,     4,     4,     1,     3,
       3,     1,     0,     3,     0,     3,     2,     2,     4,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     0,
       4,     0,     4,     0,     4,     3,     1,     0,     4,     0,
       4,     3,     1,     3,     3,     3,     1,     0,     4,     0,
       4,     0,     4,     0,     4,     3,     1,     0,     4,     0,
       4,     3,     1,     0,     4,     3,     1,     0,     4,     3,
       1,     0,     4,     3,     1,     0,     4,     3,     1,     0,
       4,     3,     1,     5,     5,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     2,     3,     1,     3,     2,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     3,
       2,     0,     4,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     2,
       4,     5,     5,     4,     1,     1,     1,     2,     2,     3,
       1,     3,     2,     1,     2,     1,     2,     1,     3,     3,
       3,     2,     3,     1,     4,     5,     5,     6,     2,     5,
       4,     1,     3,     3,     3,     3,     1,     3,     3,     4,
       1,     1,     1,     1,     1,     1,     4,     4,     2,     1,
       1,     3,     3,     4,     6,     5,     5,     6,     5,     4,
       4,     4,     3,     4,     3,     6,     6,     5,     4,     4,
       4,     3,     2,     2,     1,     1,     2,     3,     1,     3,
       1,     3,     3,     2,     2,     1,     1,     3,     3,     2,
       1,     2,     2,     2,     1,     1,     3,     2,     3,     5,
       4,     5,     4,     3,     3,     3,     4,     6,     5,     5,
       6,     4,     4,     2,     3,     3,     4,     3,     4,     1,
       3,     2,     1,     4,     3,     3,     4,     2,     2,     1,
       2,     3,     2,     3,     3,     7,     7,     1,     1,     1,
       1,     1,     1,     3,     0,     5,     0,     4,     3,     4,
       3,     2,     0,     4,     1,     2,     1,     1,     1,     2,
       2,     0,     7,     0,     0,     7,     6,     6,     5,     0,
       0,     3,     0,     0,     7,     0,     8,     0,     0,     7,
       0,     0,     7,     2,     0,     0,     5,     3,     2,     2,
       2,     3,     2,     3,     2,     2,     3,     2,     1,     2,
       1,     1,     0,     5,     0,     4,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
        case 2:
#line 63 "bison.y" /* yacc.c:1667  */
    { 
						
						if(nextToken == IDENTIFIER)
							process_id(); 
						else if (nextToken == '(')
							process_function(); 
						else if (nextToken == '=' || 275 <= nextToken <= 284)
							verify_id_for_Assign();
					}
#line 2803 "y.tab.c" /* yacc.c:1667  */
    break;

  case 7:
#line 77 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 2809 "y.tab.c" /* yacc.c:1667  */
    break;

  case 8:
#line 81 "bison.y" /* yacc.c:1667  */
    { process_literal(I_CONSTANT); }
#line 2815 "y.tab.c" /* yacc.c:1667  */
    break;

  case 15:
#line 97 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 2821 "y.tab.c" /* yacc.c:1667  */
    break;

  case 16:
#line 98 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 2827 "y.tab.c" /* yacc.c:1667  */
    break;

  case 17:
#line 99 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 2833 "y.tab.c" /* yacc.c:1667  */
    break;

  case 20:
#line 107 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 2839 "y.tab.c" /* yacc.c:1667  */
    break;

  case 23:
#line 114 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 2845 "y.tab.c" /* yacc.c:1667  */
    break;

  case 24:
#line 115 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 2851 "y.tab.c" /* yacc.c:1667  */
    break;

  case 27:
#line 121 "bison.y" /* yacc.c:1667  */
    { call_functionNoParams(); }
#line 2857 "y.tab.c" /* yacc.c:1667  */
    break;

  case 31:
#line 125 "bison.y" /* yacc.c:1667  */
    { save_op(); eval_unary(); }
#line 2863 "y.tab.c" /* yacc.c:1667  */
    break;

  case 32:
#line 126 "bison.y" /* yacc.c:1667  */
    { save_op(); eval_unary(); }
#line 2869 "y.tab.c" /* yacc.c:1667  */
    break;

  case 35:
#line 139 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 2875 "y.tab.c" /* yacc.c:1667  */
    break;

  case 36:
#line 140 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 2881 "y.tab.c" /* yacc.c:1667  */
    break;

  case 37:
#line 141 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 2887 "y.tab.c" /* yacc.c:1667  */
    break;

  case 40:
#line 153 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 2893 "y.tab.c" /* yacc.c:1667  */
    break;

  case 42:
#line 158 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 2899 "y.tab.c" /* yacc.c:1667  */
    break;

  case 43:
#line 158 "bison.y" /* yacc.c:1667  */
    { eval_unary(); }
#line 2905 "y.tab.c" /* yacc.c:1667  */
    break;

  case 44:
#line 159 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 2911 "y.tab.c" /* yacc.c:1667  */
    break;

  case 45:
#line 159 "bison.y" /* yacc.c:1667  */
    { eval_unary(); }
#line 2917 "y.tab.c" /* yacc.c:1667  */
    break;

  case 46:
#line 160 "bison.y" /* yacc.c:1667  */
    { eval_unary(); }
#line 2923 "y.tab.c" /* yacc.c:1667  */
    break;

  case 54:
#line 175 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 2929 "y.tab.c" /* yacc.c:1667  */
    break;

  case 55:
#line 176 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 2935 "y.tab.c" /* yacc.c:1667  */
    break;

  case 59:
#line 189 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 2941 "y.tab.c" /* yacc.c:1667  */
    break;

  case 60:
#line 189 "bison.y" /* yacc.c:1667  */
    {  eval_binary(); }
#line 2947 "y.tab.c" /* yacc.c:1667  */
    break;

  case 61:
#line 190 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 2953 "y.tab.c" /* yacc.c:1667  */
    break;

  case 62:
#line 190 "bison.y" /* yacc.c:1667  */
    {  eval_binary(); }
#line 2959 "y.tab.c" /* yacc.c:1667  */
    break;

  case 63:
#line 191 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 2965 "y.tab.c" /* yacc.c:1667  */
    break;

  case 64:
#line 191 "bison.y" /* yacc.c:1667  */
    {  eval_binary(); }
#line 2971 "y.tab.c" /* yacc.c:1667  */
    break;

  case 65:
#line 195 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 2977 "y.tab.c" /* yacc.c:1667  */
    break;

  case 67:
#line 200 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 2983 "y.tab.c" /* yacc.c:1667  */
    break;

  case 68:
#line 200 "bison.y" /* yacc.c:1667  */
    { eval_binary(); }
#line 2989 "y.tab.c" /* yacc.c:1667  */
    break;

  case 69:
#line 201 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 2995 "y.tab.c" /* yacc.c:1667  */
    break;

  case 70:
#line 201 "bison.y" /* yacc.c:1667  */
    { eval_binary(); }
#line 3001 "y.tab.c" /* yacc.c:1667  */
    break;

  case 71:
#line 206 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3007 "y.tab.c" /* yacc.c:1667  */
    break;

  case 75:
#line 214 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3013 "y.tab.c" /* yacc.c:1667  */
    break;

  case 77:
#line 219 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 3019 "y.tab.c" /* yacc.c:1667  */
    break;

  case 78:
#line 219 "bison.y" /* yacc.c:1667  */
    { eval_binary(); }
#line 3025 "y.tab.c" /* yacc.c:1667  */
    break;

  case 79:
#line 220 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 3031 "y.tab.c" /* yacc.c:1667  */
    break;

  case 80:
#line 220 "bison.y" /* yacc.c:1667  */
    { eval_binary(); }
#line 3037 "y.tab.c" /* yacc.c:1667  */
    break;

  case 81:
#line 221 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 3043 "y.tab.c" /* yacc.c:1667  */
    break;

  case 82:
#line 221 "bison.y" /* yacc.c:1667  */
    { eval_binary(); }
#line 3049 "y.tab.c" /* yacc.c:1667  */
    break;

  case 83:
#line 222 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 3055 "y.tab.c" /* yacc.c:1667  */
    break;

  case 84:
#line 222 "bison.y" /* yacc.c:1667  */
    { eval_binary(); }
#line 3061 "y.tab.c" /* yacc.c:1667  */
    break;

  case 87:
#line 232 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 3067 "y.tab.c" /* yacc.c:1667  */
    break;

  case 88:
#line 232 "bison.y" /* yacc.c:1667  */
    { eval_binary(); }
#line 3073 "y.tab.c" /* yacc.c:1667  */
    break;

  case 89:
#line 233 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 3079 "y.tab.c" /* yacc.c:1667  */
    break;

  case 90:
#line 233 "bison.y" /* yacc.c:1667  */
    { eval_binary(); }
#line 3085 "y.tab.c" /* yacc.c:1667  */
    break;

  case 91:
#line 235 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3091 "y.tab.c" /* yacc.c:1667  */
    break;

  case 93:
#line 240 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 3097 "y.tab.c" /* yacc.c:1667  */
    break;

  case 94:
#line 240 "bison.y" /* yacc.c:1667  */
    { eval_binary(); }
#line 3103 "y.tab.c" /* yacc.c:1667  */
    break;

  case 95:
#line 241 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3109 "y.tab.c" /* yacc.c:1667  */
    break;

  case 97:
#line 246 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 3115 "y.tab.c" /* yacc.c:1667  */
    break;

  case 98:
#line 246 "bison.y" /* yacc.c:1667  */
    { eval_binary(); }
#line 3121 "y.tab.c" /* yacc.c:1667  */
    break;

  case 99:
#line 247 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3127 "y.tab.c" /* yacc.c:1667  */
    break;

  case 101:
#line 252 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 3133 "y.tab.c" /* yacc.c:1667  */
    break;

  case 102:
#line 252 "bison.y" /* yacc.c:1667  */
    { eval_binary(); }
#line 3139 "y.tab.c" /* yacc.c:1667  */
    break;

  case 103:
#line 253 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3145 "y.tab.c" /* yacc.c:1667  */
    break;

  case 105:
#line 258 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 3151 "y.tab.c" /* yacc.c:1667  */
    break;

  case 106:
#line 258 "bison.y" /* yacc.c:1667  */
    { eval_binary(); }
#line 3157 "y.tab.c" /* yacc.c:1667  */
    break;

  case 107:
#line 259 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3163 "y.tab.c" /* yacc.c:1667  */
    break;

  case 109:
#line 265 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 3169 "y.tab.c" /* yacc.c:1667  */
    break;

  case 110:
#line 265 "bison.y" /* yacc.c:1667  */
    { eval_binary(); }
#line 3175 "y.tab.c" /* yacc.c:1667  */
    break;

  case 111:
#line 266 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3181 "y.tab.c" /* yacc.c:1667  */
    break;

  case 114:
#line 274 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3187 "y.tab.c" /* yacc.c:1667  */
    break;

  case 115:
#line 275 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3193 "y.tab.c" /* yacc.c:1667  */
    break;

  case 117:
#line 280 "bison.y" /* yacc.c:1667  */
    { process_assign(); }
#line 3199 "y.tab.c" /* yacc.c:1667  */
    break;

  case 118:
#line 287 "bison.y" /* yacc.c:1667  */
    {save_op();}
#line 3205 "y.tab.c" /* yacc.c:1667  */
    break;

  case 119:
#line 288 "bison.y" /* yacc.c:1667  */
    {save_op();}
#line 3211 "y.tab.c" /* yacc.c:1667  */
    break;

  case 120:
#line 289 "bison.y" /* yacc.c:1667  */
    {save_op();}
#line 3217 "y.tab.c" /* yacc.c:1667  */
    break;

  case 121:
#line 290 "bison.y" /* yacc.c:1667  */
    {save_op();}
#line 3223 "y.tab.c" /* yacc.c:1667  */
    break;

  case 122:
#line 291 "bison.y" /* yacc.c:1667  */
    {save_op();}
#line 3229 "y.tab.c" /* yacc.c:1667  */
    break;

  case 123:
#line 292 "bison.y" /* yacc.c:1667  */
    {save_op();}
#line 3235 "y.tab.c" /* yacc.c:1667  */
    break;

  case 124:
#line 293 "bison.y" /* yacc.c:1667  */
    {save_op();}
#line 3241 "y.tab.c" /* yacc.c:1667  */
    break;

  case 125:
#line 294 "bison.y" /* yacc.c:1667  */
    {save_op();}
#line 3247 "y.tab.c" /* yacc.c:1667  */
    break;

  case 126:
#line 295 "bison.y" /* yacc.c:1667  */
    {save_op();}
#line 3253 "y.tab.c" /* yacc.c:1667  */
    break;

  case 127:
#line 296 "bison.y" /* yacc.c:1667  */
    {save_op();}
#line 3259 "y.tab.c" /* yacc.c:1667  */
    break;

  case 128:
#line 297 "bison.y" /* yacc.c:1667  */
    {save_op();}
#line 3265 "y.tab.c" /* yacc.c:1667  */
    break;

  case 131:
#line 305 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3271 "y.tab.c" /* yacc.c:1667  */
    break;

  case 133:
#line 313 "bison.y" /* yacc.c:1667  */
    { declaration_end(); }
#line 3277 "y.tab.c" /* yacc.c:1667  */
    break;

  case 134:
#line 314 "bison.y" /* yacc.c:1667  */
    { declaration_end(); }
#line 3283 "y.tab.c" /* yacc.c:1667  */
    break;

  case 136:
#line 319 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3289 "y.tab.c" /* yacc.c:1667  */
    break;

  case 138:
#line 326 "bison.y" /* yacc.c:1667  */
    { save_type(); }
#line 3295 "y.tab.c" /* yacc.c:1667  */
    break;

  case 140:
#line 328 "bison.y" /* yacc.c:1667  */
    { save_type(); }
#line 3301 "y.tab.c" /* yacc.c:1667  */
    break;

  case 142:
#line 330 "bison.y" /* yacc.c:1667  */
    { save_type(); }
#line 3307 "y.tab.c" /* yacc.c:1667  */
    break;

  case 144:
#line 332 "bison.y" /* yacc.c:1667  */
    { save_type(); }
#line 3313 "y.tab.c" /* yacc.c:1667  */
    break;

  case 146:
#line 334 "bison.y" /* yacc.c:1667  */
    { save_type(); }
#line 3319 "y.tab.c" /* yacc.c:1667  */
    break;

  case 147:
#line 335 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3325 "y.tab.c" /* yacc.c:1667  */
    break;

  case 150:
#line 341 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3331 "y.tab.c" /* yacc.c:1667  */
    break;

  case 151:
#line 345 "bison.y" /* yacc.c:1667  */
    { save_op(); }
#line 3337 "y.tab.c" /* yacc.c:1667  */
    break;

  case 152:
#line 345 "bison.y" /* yacc.c:1667  */
    { process_assign(); }
#line 3343 "y.tab.c" /* yacc.c:1667  */
    break;

  case 153:
#line 346 "bison.y" /* yacc.c:1667  */
    { initializeID(); }
#line 3349 "y.tab.c" /* yacc.c:1667  */
    break;

  case 154:
#line 347 "bison.y" /* yacc.c:1667  */
    { 
					if(yychar == IDENTIFIER || yychar == I_CONSTANT || yychar == F_CONSTANT)
						yyerrok; 

					yyclearin;  
					clearSemanticRecords(); }
#line 3360 "y.tab.c" /* yacc.c:1667  */
    break;

  case 180:
#line 387 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3366 "y.tab.c" /* yacc.c:1667  */
    break;

  case 181:
#line 388 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3372 "y.tab.c" /* yacc.c:1667  */
    break;

  case 182:
#line 389 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3378 "y.tab.c" /* yacc.c:1667  */
    break;

  case 183:
#line 390 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3384 "y.tab.c" /* yacc.c:1667  */
    break;

  case 191:
#line 410 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3390 "y.tab.c" /* yacc.c:1667  */
    break;

  case 196:
#line 418 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3396 "y.tab.c" /* yacc.c:1667  */
    break;

  case 199:
#line 424 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3402 "y.tab.c" /* yacc.c:1667  */
    break;

  case 200:
#line 425 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3408 "y.tab.c" /* yacc.c:1667  */
    break;

  case 209:
#line 444 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3414 "y.tab.c" /* yacc.c:1667  */
    break;

  case 210:
#line 445 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3420 "y.tab.c" /* yacc.c:1667  */
    break;

  case 213:
#line 453 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3426 "y.tab.c" /* yacc.c:1667  */
    break;

  case 214:
#line 454 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3432 "y.tab.c" /* yacc.c:1667  */
    break;

  case 217:
#line 461 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3438 "y.tab.c" /* yacc.c:1667  */
    break;

  case 218:
#line 463 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3444 "y.tab.c" /* yacc.c:1667  */
    break;

  case 230:
#line 493 "bison.y" /* yacc.c:1667  */
    { save_id(); }
#line 3450 "y.tab.c" /* yacc.c:1667  */
    break;

  case 244:
#line 511 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3456 "y.tab.c" /* yacc.c:1667  */
    break;

  case 245:
#line 512 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3462 "y.tab.c" /* yacc.c:1667  */
    break;

  case 246:
#line 513 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3468 "y.tab.c" /* yacc.c:1667  */
    break;

  case 247:
#line 517 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3474 "y.tab.c" /* yacc.c:1667  */
    break;

  case 248:
#line 518 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3480 "y.tab.c" /* yacc.c:1667  */
    break;

  case 249:
#line 519 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3486 "y.tab.c" /* yacc.c:1667  */
    break;

  case 250:
#line 520 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3492 "y.tab.c" /* yacc.c:1667  */
    break;

  case 259:
#line 545 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3498 "y.tab.c" /* yacc.c:1667  */
    break;

  case 262:
#line 551 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3504 "y.tab.c" /* yacc.c:1667  */
    break;

  case 268:
#line 565 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3510 "y.tab.c" /* yacc.c:1667  */
    break;

  case 271:
#line 572 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3516 "y.tab.c" /* yacc.c:1667  */
    break;

  case 272:
#line 573 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3522 "y.tab.c" /* yacc.c:1667  */
    break;

  case 300:
#line 615 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3528 "y.tab.c" /* yacc.c:1667  */
    break;

  case 305:
#line 623 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3534 "y.tab.c" /* yacc.c:1667  */
    break;

  case 306:
#line 624 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3540 "y.tab.c" /* yacc.c:1667  */
    break;

  case 308:
#line 630 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3546 "y.tab.c" /* yacc.c:1667  */
    break;

  case 313:
#line 641 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3552 "y.tab.c" /* yacc.c:1667  */
    break;

  case 314:
#line 642 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3558 "y.tab.c" /* yacc.c:1667  */
    break;

  case 316:
#line 647 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3564 "y.tab.c" /* yacc.c:1667  */
    break;

  case 324:
#line 661 "bison.y" /* yacc.c:1667  */
    { begin_case(); }
#line 3570 "y.tab.c" /* yacc.c:1667  */
    break;

  case 325:
#line 661 "bison.y" /* yacc.c:1667  */
    { end_case(); }
#line 3576 "y.tab.c" /* yacc.c:1667  */
    break;

  case 326:
#line 662 "bison.y" /* yacc.c:1667  */
    { create_default(); }
#line 3582 "y.tab.c" /* yacc.c:1667  */
    break;

  case 327:
#line 662 "bison.y" /* yacc.c:1667  */
    { append_exit(); }
#line 3588 "y.tab.c" /* yacc.c:1667  */
    break;

  case 328:
#line 664 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3594 "y.tab.c" /* yacc.c:1667  */
    break;

  case 329:
#line 665 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3600 "y.tab.c" /* yacc.c:1667  */
    break;

  case 330:
#line 666 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3606 "y.tab.c" /* yacc.c:1667  */
    break;

  case 332:
#line 673 "bison.y" /* yacc.c:1667  */
    { inContext = TRUE; pushTable(); }
#line 3612 "y.tab.c" /* yacc.c:1667  */
    break;

  case 333:
#line 673 "bison.y" /* yacc.c:1667  */
    {inContext = FALSE;  popTable();}
#line 3618 "y.tab.c" /* yacc.c:1667  */
    break;

  case 339:
#line 689 "bison.y" /* yacc.c:1667  */
    { if (!inFor) popRecord(); }
#line 3624 "y.tab.c" /* yacc.c:1667  */
    break;

  case 340:
#line 691 "bison.y" /* yacc.c:1667  */
    {  yyerrok; }
#line 3630 "y.tab.c" /* yacc.c:1667  */
    break;

  case 341:
#line 695 "bison.y" /* yacc.c:1667  */
    { start_if(); }
#line 3636 "y.tab.c" /* yacc.c:1667  */
    break;

  case 342:
#line 695 "bison.y" /* yacc.c:1667  */
    { end_if(); }
#line 3642 "y.tab.c" /* yacc.c:1667  */
    break;

  case 343:
#line 696 "bison.y" /* yacc.c:1667  */
    { start_switch(); }
#line 3648 "y.tab.c" /* yacc.c:1667  */
    break;

  case 344:
#line 696 "bison.y" /* yacc.c:1667  */
    { save_comparator(); }
#line 3654 "y.tab.c" /* yacc.c:1667  */
    break;

  case 345:
#line 696 "bison.y" /* yacc.c:1667  */
    { end_switch(); }
#line 3660 "y.tab.c" /* yacc.c:1667  */
    break;

  case 346:
#line 699 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3666 "y.tab.c" /* yacc.c:1667  */
    break;

  case 347:
#line 700 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3672 "y.tab.c" /* yacc.c:1667  */
    break;

  case 348:
#line 701 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3678 "y.tab.c" /* yacc.c:1667  */
    break;

  case 350:
#line 712 "bison.y" /* yacc.c:1667  */
    { start_else(); }
#line 3684 "y.tab.c" /* yacc.c:1667  */
    break;

  case 352:
#line 716 "bison.y" /* yacc.c:1667  */
    { start_while(); }
#line 3690 "y.tab.c" /* yacc.c:1667  */
    break;

  case 353:
#line 716 "bison.y" /* yacc.c:1667  */
    { evaluate_expression(); }
#line 3696 "y.tab.c" /* yacc.c:1667  */
    break;

  case 354:
#line 716 "bison.y" /* yacc.c:1667  */
    { exit_while(); }
#line 3702 "y.tab.c" /* yacc.c:1667  */
    break;

  case 355:
#line 717 "bison.y" /* yacc.c:1667  */
    { start_doWhile(); }
#line 3708 "y.tab.c" /* yacc.c:1667  */
    break;

  case 356:
#line 717 "bison.y" /* yacc.c:1667  */
    { evaluate_expression(); exit_doWhile();}
#line 3714 "y.tab.c" /* yacc.c:1667  */
    break;

  case 357:
#line 718 "bison.y" /* yacc.c:1667  */
    { inFor = TRUE; begin_for(); }
#line 3720 "y.tab.c" /* yacc.c:1667  */
    break;

  case 358:
#line 718 "bison.y" /* yacc.c:1667  */
    { evaluate_expression(); inFor = FALSE; }
#line 3726 "y.tab.c" /* yacc.c:1667  */
    break;

  case 360:
#line 719 "bison.y" /* yacc.c:1667  */
    { inFor = TRUE; begin_for(); }
#line 3732 "y.tab.c" /* yacc.c:1667  */
    break;

  case 361:
#line 719 "bison.y" /* yacc.c:1667  */
    { evaluate_expression(); inFor = FALSE; }
#line 3738 "y.tab.c" /* yacc.c:1667  */
    break;

  case 364:
#line 751 "bison.y" /* yacc.c:1667  */
    { redirect_code(); }
#line 3744 "y.tab.c" /* yacc.c:1667  */
    break;

  case 365:
#line 751 "bison.y" /* yacc.c:1667  */
    { restore_code(); }
#line 3750 "y.tab.c" /* yacc.c:1667  */
    break;

  case 366:
#line 751 "bison.y" /* yacc.c:1667  */
    { popRecord(); end_for();}
#line 3756 "y.tab.c" /* yacc.c:1667  */
    break;

  case 369:
#line 758 "bison.y" /* yacc.c:1667  */
    { process_break(); }
#line 3762 "y.tab.c" /* yacc.c:1667  */
    break;

  case 372:
#line 761 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3768 "y.tab.c" /* yacc.c:1667  */
    break;

  case 373:
#line 762 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3774 "y.tab.c" /* yacc.c:1667  */
    break;

  case 374:
#line 763 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3780 "y.tab.c" /* yacc.c:1667  */
    break;

  case 375:
#line 764 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3786 "y.tab.c" /* yacc.c:1667  */
    break;

  case 376:
#line 765 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3792 "y.tab.c" /* yacc.c:1667  */
    break;

  case 377:
#line 766 "bison.y" /* yacc.c:1667  */
    { yyerrok; }
#line 3798 "y.tab.c" /* yacc.c:1667  */
    break;

  case 382:
#line 780 "bison.y" /* yacc.c:1667  */
    { start_function(); stackPos -= 4; }
#line 3804 "y.tab.c" /* yacc.c:1667  */
    break;

  case 383:
#line 780 "bison.y" /* yacc.c:1667  */
    { end_function(); unDecleared = FALSE; inContext = FALSE; popTable(); stackPos -= 4; }
#line 3810 "y.tab.c" /* yacc.c:1667  */
    break;

  case 384:
#line 785 "bison.y" /* yacc.c:1667  */
    { start_function(); stackPos -= 4; }
#line 3816 "y.tab.c" /* yacc.c:1667  */
    break;

  case 385:
#line 789 "bison.y" /* yacc.c:1667  */
    { end_function(); unDecleared = FALSE;  stackPos -= 4;}
#line 3822 "y.tab.c" /* yacc.c:1667  */
    break;


#line 3826 "y.tab.c" /* yacc.c:1667  */
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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 797 "bison.y" /* yacc.c:1918  */


#include "semanticActions.c"
