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
#line 1 "bison.y" /* yacc.c:339  */


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



#line 108 "y.tab.c" /* yacc.c:339  */

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

/* Copy the second part of user declarations.  */

#line 309 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  112
/* YYNRULES -- Number of rules.  */
#define YYNRULES  382
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  638

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
     233,   235,   239,   240,   241,   245,   246,   247,   251,   252,
     253,   257,   258,   259,   264,   265,   266,   271,   272,   274,
     275,   279,   280,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   301,   302,   305,   309,   313,   314,
     315,   319,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   339,   340,   341,   345,   345,   346,   347,
     356,   357,   358,   359,   360,   361,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   384,   385,   386,   387,   388,   389,   390,   394,
     395,   399,   400,   404,   405,   406,   410,   414,   415,   416,
     417,   418,   422,   423,   424,   425,   429,   430,   431,   439,
     440,   441,   442,   443,   444,   445,   450,   451,   453,   454,
     458,   459,   461,   463,   467,   471,   472,   473,   474,   478,
     479,   483,   484,   488,   489,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   511,
     512,   513,   517,   518,   519,   520,   525,   526,   527,   528,
     536,   537,   542,   543,   545,   549,   550,   551,   556,   557,
     558,   562,   563,   565,   569,   570,   572,   573,   577,   578,
     579,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   609,   610,   611,   615,   619,   620,   621,   622,
     623,   624,   628,   630,   634,   635,   639,   640,   641,   642,
     646,   647,   651,   652,   653,   654,   655,   656,   660,   661,
     661,   662,   662,   664,   665,   666,   672,   673,   673,   678,
     679,   683,   684,   688,   689,   691,   695,   695,   696,   696,
     696,   699,   700,   701,   710,   712,   712,   716,   716,   716,
     717,   717,   718,   718,   718,   719,   719,   719,   750,   751,
     751,   751,   756,   757,   758,   759,   760,   761,   762,   763,
     764,   765,   766,   770,   771,   775,   776,   780,   780,   785,
     783,   793,   794
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
  "equality_expression", "$@12", "$@13", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "$@14", "storage_class_specifier", "type_specifier",
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
  "static_assert_declaration", "statement", "labeled_statement", "$@15",
  "$@16", "compound_statement", "$@17", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "$@18", "$@19", "$@20",
  "else_statement", "$@21", "iteration_statement", "$@22", "$@23", "$@24",
  "$@25", "$@26", "$@27", "$@28", "for_prime", "$@29", "$@30",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "$@31", "$@32", "declaration_list", YY_NULLPTR
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

#define YYPACT_NINF -549

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-549)))

#define YYTABLE_NINF -380

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    4721,  4888,  -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,
    -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,
    -549,  -549,  -549,  -549,  -549,  -549,    59,   -21,    44,  -549,
     115,  -549,  -549,    81,  1272,  1343,  -549,   211,  -549,  -549,
    1414,  1485,  1556,  -549,  4666,  -549,  -549,  -549,   -33,    76,
    2954,  5032,  3088,  -549,   114,   621,  -549,     9,  -549,  1627,
       1,   182,  -549,  -549,  4943,   595,  4943,  -549,  -549,  -549,
    -549,  -549,    76,  -549,    31,    95,  -549,  4170,  -549,  -549,
    -549,  -549,  -549,  3882,  -549,  -549,  -549,   137,    27,  2954,
    -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,
     479,  -549,  3970,  -549,  1828,  1985,  2142,  2478,   206,  2615,
    1116,   230,  2736,   378,  -549,    46,  1689,   407,  1751,    64,
     157,   142,   167,    23,  -549,  -549,  -549,   621,   175,   114,
    -549,  -549,  -549,  4721,   156,  4500,  3310,     1,  5066,  4225,
    -549,   353,  -549,  4943,  4943,  4280,   188,  3970,  3178,    76,
     194,  -549,  4115,  3332,  -549,    12,  -549,   164,  2954,  -549,
    3992,  3992,  5032,  3970,  3970,   675,  -549,  -549,   269,   209,
     256,  -549,  -549,  3728,  3970,   279,  -549,  3970,  -549,  -549,
    -549,  3970,  -549,  -549,  3970,  3970,  3970,  3970,  -549,  -549,
    -549,  -549,  3970,  -549,  -549,  3970,  3970,  3970,  3970,  3970,
    3970,  3970,  3970,  3970,  3970,  3970,  -549,  -549,  -549,  -549,
    -549,  -549,  -549,   307,   318,  -549,  -549,  -549,  -549,  -549,
      20,  3750,  -549,    81,  4445,   248,  -549,  4555,  -549,  -549,
     161,   278,   276,  -549,   294,  3044,  -549,   258,   268,  3354,
    -549,  -549,  3970,  -549,    33,  -549,   283,  4335,  4390,  1130,
    -549,    76,   208,  -549,  -549,  -549,  -549,  -549,  -549,  -549,
    -549,  -549,   299,   304,  3574,  -549,   302,   310,  3442,   164,
    4610,  3464,   368,  2954,  -549,  -549,   322,   329,    65,  -549,
    -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,
    3970,  3970,  -549,  3970,   335,  3838,  -549,  -549,   327,  -549,
     218,  -549,  -549,  3970,  3970,  3970,  1851,  3970,  3970,  2008,
    2096,  2119,  2230,  3970,  3970,  3970,  3970,  2505,  3970,  3970,
     317,  2575,  2639,  2648,  2672,  2703,  2434,  2712,  2745,   109,
    2759,   173,   343,   376,  3706,  -549,  -549,  -549,  -549,  -549,
     964,  -549,  4060,  -549,   341,  -549,  -549,  -549,  4776,  4832,
     470,  -549,   475,  3860,   399,  3066,  -549,  -549,  3970,  -549,
     417,   419,  -549,   314,   262,  -549,  3970,  -549,  1201,  -549,
    -549,  -549,  -549,   428,  3574,  -549,  -549,  3970,  -549,   429,
    -549,   438,  3574,  -549,   435,   442,  3486,   443,   440,  -549,
    4998,  4998,  4998,  -549,  -549,  -549,  -549,  3706,  -549,  3970,
    -549,  3970,  3970,  -549,  -549,  -549,  -549,  1874,  1962,  2253,
    2276,  2364,  2387,  2528,  2551,  3970,  3970,  3970,  3970,   432,
     433,  3200,   525,  -549,   220,  3750,    88,  -549,   454,  3970,
      74,    48,    96,  -549,  -549,   462,    92,    38,    41,  2415,
    -549,    34,  -549,  -549,  -549,  -549,   874,  -549,  -549,  -549,
    -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,   458,
    -549,   471,   476,   481,  -549,  -549,  -549,  -549,  -549,  -549,
    -549,   484,   485,  -549,  -549,   487,  3574,  -549,  -549,  3970,
    -549,   488,   443,   149,   356,  -549,   493,   359,   418,   228,
    -549,  -549,  -549,  -549,  -549,  -549,  -549,   492,    85,  -549,
    3706,  3596,  -549,  -549,  -549,  -549,  -549,   679,   231,  2842,
     495,  3970,  3970,  3970,   478,   502,  2842,  1054,  -549,    47,
    -549,  -549,  -549,  -549,  -549,  -549,    35,  3970,  -549,  -549,
    -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,   500,   501,
    -549,  3970,  3222,   775,  -549,  4998,  3970,  4998,  -549,  -549,
    3706,  3618,  -549,  -549,  -549,  -549,  -549,  3750,  -549,  -549,
    3750,  -549,  -549,  2842,   504,  -549,  2842,   424,   426,   434,
    3970,  3970,   498,  -549,  -549,  -549,  -549,  3970,  -549,  -549,
    -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,  -549,
    -549,  2842,  -549,  2842,  2842,  -549,  2842,   457,   466,   508,
    2864,  2864,  -549,   527,   511,   527,  2842,  -549,  -549,  -549,
    3970,  -549,  -549,  -549,  -549,  -549,   527,  2842,  2842,   468,
     513,   513,  2842,  -549,  -549,  -549,   486,  2842,  -549,  3970,
    -549,  -549,  -549,  -549,   473,  -549,  2842,  -549
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,   171,   150,   151,   152,   154,   155,   219,   215,
     216,   217,   165,   157,   158,   159,   160,   163,   164,   161,
     162,   156,   166,   167,   179,   180,     0,     0,   218,   220,
       0,   153,   376,     0,     0,     0,   169,     0,   170,   168,
       0,     0,     0,   130,     0,   373,   375,   142,   203,     0,
       0,     0,     0,   225,     0,   249,   128,     0,   143,     0,
     224,     0,   132,   134,     0,     0,     0,   136,   138,   140,
       1,   374,     0,    11,     0,     0,   206,     0,     2,     8,
       9,    12,    13,     0,    42,    44,    10,     0,     0,     0,
      50,    51,    52,    53,    54,    55,    25,     3,     4,     6,
      41,    56,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   218,   250,   248,   247,   131,     0,
     129,   149,   146,     0,     0,     0,     0,   223,     0,     0,
     181,     0,   185,     0,     0,     0,     0,     0,     0,   205,
       0,   199,     0,     0,   191,   269,   266,   270,     0,    47,
       0,     0,     0,     0,     0,    56,   111,   124,     0,     0,
       0,    31,    32,     0,     0,     0,    46,     0,    59,    61,
      63,     0,    67,    69,     0,     0,     0,     0,    81,    83,
      77,    79,     0,    87,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   187,   267,   264,
     189,   221,   214,     0,     0,   239,   226,   251,   246,   144,
       0,     0,   381,     0,     0,   327,   380,     0,   261,   237,
     260,     0,     0,   255,     0,     0,   227,    51,     0,     0,
     175,   182,     0,   183,     0,   192,   198,     0,     0,     0,
     172,   204,     0,   201,   213,   212,   210,   209,   208,   200,
     207,   288,     0,     0,     0,   272,    51,     0,     0,   268,
       0,     0,     0,     0,    43,    45,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   113,
       0,     7,     5,     0,     0,     0,    30,    27,     0,    38,
       0,    29,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   294,   147,   382,   378,   326,
       0,   244,     0,   258,   269,   259,   243,   236,     0,     0,
     245,   238,     0,     0,     0,     0,   228,   235,     0,   234,
      51,     0,   196,   186,     0,   184,     0,   177,     0,   173,
     202,   289,   271,     0,     0,   273,   279,     0,   278,     0,
     290,     0,     0,   280,    51,     0,     0,    48,     0,    49,
       0,     0,     0,   112,   126,   125,    37,     0,    57,    35,
      28,     0,    36,    26,    60,    62,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   297,     0,     0,     0,   304,     2,     0,
       0,     0,     0,   347,   350,     0,     0,     0,     0,     0,
     333,     0,   331,   332,   312,   313,     0,   329,   314,   315,
     316,   317,   254,   257,   252,   256,   263,   262,   242,     0,
     230,     0,     0,     0,   231,   233,   195,   194,   193,   197,
     275,     0,     0,   277,   291,     0,     0,   281,   287,     0,
     286,     0,     0,     0,     0,    18,     0,     0,     0,     0,
      40,    39,   110,   109,   108,   311,   310,     0,     0,   307,
     295,     0,   292,   296,   303,   302,   305,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   372,     0,
     370,   363,   369,   364,   367,   365,     0,   335,   334,   328,
     330,   240,   241,   229,   232,   274,   276,   283,     0,     0,
     284,     0,     0,     0,    15,     0,     0,     0,    16,    14,
       0,     0,    33,   308,   309,   306,   300,     0,   293,   299,
       0,   323,   318,     0,     0,   325,     0,     0,     0,     0,
       0,     0,     0,   355,   352,   371,   362,   368,   366,   282,
     285,    24,    23,    22,    20,    19,    21,    34,   301,   298,
     324,     0,   322,     0,     0,   336,     0,     0,     0,     0,
       0,     0,   320,   344,   124,   344,     0,   343,   339,   348,
       0,   356,   353,   345,   341,   342,   344,     0,     0,     0,
     359,   359,     0,   337,   340,   349,     0,     0,   357,     0,
     354,   346,   351,   358,     0,   360,     0,   361
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -549,  -549,  -549,  -549,  -549,  -549,  -309,  -467,  -549,  -549,
     416,  -549,  -549,  -549,   -87,  -163,  -549,  -549,  -549,   286,
    -549,  -549,  -154,  -170,  -549,  -549,  -549,  -549,   214,  -549,
    -549,   245,   251,   259,   260,  -549,   -43,    29,  -549,   -89,
     -41,  -125,    30,  -549,   463,  -549,  -549,    19,  -549,  -549,
     132,   -72,   117,  -549,   143,  -549,   519,  -124,  -549,     3,
    -549,  -549,   -27,   -56,   -26,  -113,  -123,  -549,   165,  -549,
     -37,   -61,  -138,  -220,   197,    -9,  -549,   169,     2,   -69,
    -549,  -549,  -549,   -93,  -549,  -549,   153,  -423,  -549,  -549,
    -549,  -549,  -548,  -549,  -549,  -549,  -549,  -549,  -549,  -549,
    -549,  -549,   -17,  -549,  -549,  -549,  -549,   561,  -549,  -549,
    -549,  -549
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    96,    97,    74,    98,    99,   484,   485,   100,   298,
     165,   160,   161,   102,   103,   104,   303,   304,   305,   105,
     307,   308,   106,   107,   315,   316,   313,   314,   108,   318,
     319,   109,   110,   111,   112,   113,   166,   167,   290,   441,
     115,    32,   230,    57,    58,   221,    34,   116,    36,    37,
     139,   140,   117,   244,   245,    38,    75,    76,    39,   118,
      41,    42,   246,    60,    61,   127,   262,   232,   233,   234,
     486,   263,   157,   423,   424,   425,   426,   427,   142,   443,
     444,   564,   510,   445,   340,   446,   447,   448,   449,   606,
     514,   617,   614,   622,   450,   515,   618,   516,   601,   621,
     600,   620,   628,   629,   636,   451,    44,    45,    46,   133,
     134,   224
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     168,   336,    43,    40,    40,   137,    59,   114,   222,   114,
     128,   122,   231,   119,   120,   176,   156,   269,   306,    35,
      35,   131,   317,   239,   215,   257,   260,   123,   163,   126,
      33,    47,   147,   312,   363,   527,   577,    40,    40,   520,
     268,   226,   522,    40,    40,    40,    43,    40,   575,   511,
      72,   155,   169,    35,    35,    50,   209,   615,   125,    35,
      35,    35,    48,    35,    62,    63,   391,   241,   623,   168,
      67,    68,    69,   241,    33,   509,   584,   135,   585,    73,
     584,   136,   487,   488,    53,   300,   554,   129,   152,   504,
     302,   155,   153,   518,   574,   519,   149,   513,  -148,   337,
     216,   218,   220,   164,   114,   114,   254,   256,   130,  -211,
     415,   364,   293,   293,   329,  -211,   331,    53,   132,  -148,
      51,   272,   355,   206,   512,   276,   155,   257,   260,   148,
     217,   338,   365,   528,   578,    43,    40,   521,    40,   125,
     523,   211,    49,   392,   407,   408,   576,   381,   413,   414,
     541,   374,    35,  -321,    35,    40,   125,    54,   386,   409,
     410,   411,   412,   223,    53,   238,   555,    55,   421,   345,
     422,    35,  -338,   150,   417,   241,   241,   611,   612,   151,
      56,   141,   267,   141,   168,    53,   505,   293,   416,   251,
      54,    52,   277,   278,   154,   258,   220,    73,   145,   114,
      55,   362,   299,   343,   344,   503,   269,   192,   398,   258,
     294,    73,    64,   162,    65,   442,   404,   405,   406,   402,
     213,   500,   193,   194,   -92,   -92,    43,    40,   542,   550,
      40,   199,   563,   207,   212,   210,   388,   342,   125,   225,
     270,   153,   217,    35,   271,   214,    35,    55,  -101,  -101,
     335,   293,   418,  -145,   223,   154,   141,    47,    54,   296,
     141,   141,   141,   467,   354,    53,   252,   125,   361,   476,
     291,   217,   253,    40,   125,   247,   248,   348,   259,   346,
     556,   559,   301,   -92,   -92,   -92,   295,   -92,   137,    35,
     -92,   -92,   370,   373,    66,   350,   293,   379,   501,   403,
     385,   -92,   -92,   -92,   502,   -92,   551,  -101,  -101,  -101,
    -319,  -101,   552,   332,  -101,   123,   344,    53,   192,   393,
     394,   442,   395,   114,   333,   469,   200,  -101,   399,  -101,
     556,   559,   339,   193,   194,   -94,   -94,   588,    54,   356,
     589,   242,    43,    40,    53,    40,   292,   293,    55,   357,
     526,    40,    40,  -253,   349,   347,    53,   543,   217,    35,
     547,    35,   366,   335,   141,   141,   154,    35,    35,   294,
     223,   351,   352,   492,   493,   494,   371,   217,   114,   203,
     498,   372,   459,   375,   462,   125,   114,   463,   508,   217,
      54,   376,   573,   242,   -94,   -94,   -94,   204,   -94,   389,
      55,   -94,   -94,   471,   400,   401,   472,   390,   208,   320,
     321,   475,   -94,   -94,   -94,   481,   -94,   342,   396,   547,
     419,   153,   567,   568,   569,   415,   335,   594,   490,    54,
     491,   394,   242,   544,   545,   415,   548,   545,   562,    55,
     565,   294,   322,   323,   394,   387,   394,   572,    43,    40,
     324,   325,   243,   420,   335,  -107,  -107,  -107,   415,  -107,
     326,   327,  -107,   328,   330,    35,   101,   415,   101,   415,
     309,   310,   311,   456,   415,   205,   223,  -107,   457,   217,
     460,   597,   598,   152,  -265,   154,  -265,   153,   170,   171,
     172,   557,   560,    55,   590,   549,   545,   592,   464,   159,
     465,   593,   293,   595,   293,   538,   466,   468,   539,   470,
     473,   596,   293,   453,   455,   474,   477,   482,   101,    43,
      40,   619,   602,   478,   603,   605,   397,   607,   499,   335,
     335,   495,   496,   507,   608,   293,    35,   616,   517,   531,
     634,   557,   560,   609,   293,   626,   293,   223,   624,   625,
     635,   293,   532,   631,   570,   173,   394,   533,   633,   174,
     599,   175,   534,   101,   101,   535,   536,   637,   537,   540,
     581,   583,   546,   553,   566,   586,   274,   275,   571,   335,
     335,   579,   580,   591,   610,   632,   335,   613,  -126,   335,
     627,   146,   219,   101,   489,   506,   143,   101,  -174,   530,
     101,   101,   101,   101,   630,    71,   394,     0,   101,     0,
       0,   101,   101,   101,   101,   101,   101,   101,   101,     0,
     101,     0,     0,   604,     0,  -174,     0,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,     0,     0,     0,     0,     0,     0,     0,   101,     9,
      10,    11,     0,     0,  -174,     0,  -174,     0,  -174,     0,
    -174,  -174,  -174,  -174,  -174,  -174,     0,     0,   144,     0,
     561,  -174,   428,    79,    80,    81,    82,    83,     0,    84,
      85,     0,   124,     0,  -174,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,     0,     0,    55,     0,     0,
      86,   101,     0,     0,     0,     0,     0,     0,     0,   101,
     101,   101,     0,   101,   101,     0,     0,     0,     0,   101,
     101,   101,   101,     0,   101,   101,   429,   430,   431,     0,
     432,   433,   434,   435,   436,   437,   438,   439,     0,    87,
       0,    88,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,   225,     0,    90,    91,    92,    93,    94,    95,
       0,     0,     0,   289,     0,     0,    77,     0,   440,     0,
       0,     0,   101,     0,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,     2,     0,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     0,   101,   483,   101,     0,     0,   101,     0,     0,
       0,     0,     0,     0,     0,   101,    28,     0,     0,     0,
       0,   -17,   -17,   -17,   -17,   -17,   -17,   -17,     0,   -17,
     -17,   -17,   -17,   -17,     0,     0,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,     1,     0,   428,    79,    80,
      81,    82,    83,     0,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,    86,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,   429,   430,   431,     0,   432,   433,   434,   435,   436,
     437,   438,   439,    27,    87,    28,    88,    29,    30,    31,
      89,     0,     0,     0,     0,     0,     0,   225,   529,    90,
      91,    92,    93,    94,    95,     1,     0,   428,    79,    80,
      81,    82,    83,   440,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,    86,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,   429,   430,   431,     0,   432,   433,   434,   435,   436,
     437,   438,   439,    27,    87,    28,    88,    29,    30,    31,
      89,     0,     0,     0,     0,     0,     0,   225,     0,    90,
      91,    92,    93,    94,    95,     1,     0,    78,    79,    80,
      81,    82,    83,   440,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,    86,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     0,     0,     0,   197,     0,     0,
       0,     0,     0,    27,    87,    28,    88,    29,    30,    31,
      89,   138,     0,  -178,   -98,   -98,     0,     0,     0,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,   440,     0,     0,     0,     0,     0,     0,
       2,     0,  -178,  -178,  -178,  -178,  -178,  -178,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
       0,     0,     0,   -98,   -98,   -98,     0,   -98,     0,  -178,
     -98,    28,   138,  -178,  -176,  -178,  -178,  -178,  -178,  -178,
    -178,   198,   -98,   -98,     0,   -98,  -178,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -178,
       0,     2,     0,  -176,  -176,  -176,  -176,  -176,  -176,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -176,     0,    28,     1,  -176,  -133,  -176,  -176,  -176,  -176,
    -176,  -176,     0,     0,     0,     0,     0,  -176,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -176,     0,     2,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,    28,     1,    29,  -135,    31,  -133,  -133,
    -133,     0,  -133,     0,     0,     0,     0,     0,  -133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -133,     0,     2,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,    28,     1,    29,  -137,    31,  -135,
    -135,  -135,     0,  -135,     0,     0,     0,     0,     0,  -135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -135,     0,     2,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,    28,     1,    29,  -139,    31,
    -137,  -137,  -137,     0,  -137,     0,     0,     0,     0,     0,
    -137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -137,     0,     2,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,    28,     1,    29,  -141,
      31,  -139,  -139,  -139,     0,  -139,     0,     0,     0,     0,
       0,  -139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -139,     0,     2,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,    28,   131,    29,
       0,    31,  -141,  -141,  -141,     0,  -141,     0,     0,     0,
       0,     0,  -141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -141,     0,  -377,     0,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,     0,     0,     0,     0,     0,     0,     0,
     138,     0,  -188,     0,     0,     0,  -377,     0,  -377,     0,
    -377,  -377,  -377,     0,     0,  -148,     0,     0,     0,     0,
    -379,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,     0,     0,   132,  -148,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     0,     0,     0,     0,     0,
       0,     0,   138,     0,  -190,     0,     0,     0,     0,     0,
      28,     0,     0,     0,     0,  -188,  -188,     0,  -188,  -188,
       0,     0,     0,     0,     0,  -188,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,     0,  -188,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,     0,     0,  -190,  -190,   177,
    -190,  -190,     0,     0,     0,     0,     0,  -190,     0,     0,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,     0,     0,
    -190,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,     0,     0,     0,     0,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -66,   -66,   -66,     0,   -66,
       0,     0,   -66,   -66,   178,   -66,   -66,     0,     0,   179,
     180,   -66,   -66,   -66,   -66,   -66,     0,   -66,   -71,   -71,
     -71,     0,   -71,     0,     0,   -71,   -71,   178,   -71,   -71,
       0,     0,   179,   180,   -71,   -71,   -71,   -71,   -71,     0,
     -71,   -68,   -68,   -68,     0,   -68,     0,     0,   -68,   -68,
     178,   -68,   -68,   177,     0,   179,   180,   -68,   -68,   -68,
     -68,   -68,     0,   -68,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,     0,     0,     0,     0,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,     0,     0,     0,     0,   181,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -70,
     -70,   -70,     0,   -70,     0,     0,   -70,   -70,   178,   -70,
     -70,     0,     0,   179,   180,   -70,   -70,   -70,   -70,   -70,
       0,   -70,   -72,   -72,   -72,     0,   -72,     0,     0,   -72,
     -72,     0,   182,   183,     0,     0,     0,     0,   -72,   -72,
     -72,   -72,   -72,     0,   -72,   -75,   -75,   -75,     0,   -75,
       0,     0,   -75,   -75,     0,   182,   183,   181,     0,     0,
       0,   -75,   -75,   -75,   -75,   -75,     0,   -75,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,     0,     0,     0,     0,
     181,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,     0,
       0,     0,     0,   184,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   185,   186,   -76,   -76,   -76,   -76,
     -76,   -76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -73,   -73,   -73,     0,   -73,     0,     0,
     -73,   -73,     0,   182,   183,     0,     0,     0,     0,   -73,
     -73,   -73,   -73,   -73,     0,   -73,   -74,   -74,   -74,     0,
     -74,     0,     0,   -74,   -74,     0,   182,   183,     0,     0,
       0,     0,   -74,   -74,   -74,   -74,   -74,     0,   -74,   -76,
     -76,   -76,     0,   -76,     0,     0,   -76,   -76,     0,     0,
       0,   184,     0,     0,     0,   -76,   -76,   -76,   -76,   -76,
       0,   -76,   185,   186,   -85,   -85,   -85,   -85,   -85,   -85,
       0,     0,     0,     0,   184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   185,   186,   -82,   -82,   -82,
     -82,   -82,   -82,     0,     0,     0,     0,   184,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   185,   186,
     -84,   -84,   -84,   -84,   -84,   -84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -85,   -85,   -85,
       0,   -85,     0,     0,   -85,   -85,     0,     0,     0,     0,
       0,     0,     0,   -85,   -85,   -85,   -85,   -85,     0,   -85,
     -82,   -82,   -82,     0,   -82,     0,     0,   -82,   -82,     0,
       0,     0,     0,     0,     0,     0,   -82,   -82,   -82,   -82,
     -82,     0,   -82,   -84,   -84,   -84,     0,   -84,     0,     0,
     -84,   -84,     0,     0,     0,   184,     0,     0,     0,   -84,
     -84,   -84,   -84,   -84,     0,   -84,   185,   186,   -78,   -78,
     -78,   -78,   -78,   -78,     0,     0,     0,     0,   184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   185,
     186,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   524,     0,    78,    79,
      80,    81,    82,    83,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,   199,     0,     0,     0,     0,
       0,   -78,   -78,   -78,     0,   -78,    86,     0,   -78,   -78,
       0,     0,  -103,  -103,     0,     0,     0,   -78,   -78,   -78,
     -78,   -78,     0,   -78,   -80,   -80,   -80,     0,   -80,     0,
       0,   -80,   -80,     0,     0,     0,     0,     0,     0,   187,
     -80,   -80,   -80,   -80,   -80,    87,   -80,    88,     0,     0,
       0,    89,   188,   189,   -86,   -86,   -86,   -86,     0,     0,
      90,    91,    92,    93,    94,    95,   187,     0,     0,     0,
       0,  -103,  -103,  -103,   525,  -103,     0,     0,  -103,   188,
     189,   -91,   -91,   -91,   -91,     0,     0,     0,     0,   187,
     200,  -103,     0,  -103,     0,     0,     0,     0,     0,     0,
       0,     0,   188,   189,   -88,   -88,   -88,   -88,     0,     0,
       0,     0,   187,     0,     0,   -86,   -86,   -86,     0,   -86,
       0,     0,   -86,   -86,     0,   188,   189,   -90,   -90,   -90,
     -90,   190,   191,   -86,   -86,   -86,   192,   -86,     0,     0,
       0,     0,   -91,   -91,   -91,     0,   -91,     0,     0,   -91,
     -91,   193,   194,   -93,   -93,     0,     0,     0,   190,   191,
     -91,   -91,   -91,     0,   -91,   -88,   -88,   -88,     0,   -88,
       0,     0,   -88,   -88,     0,     0,   195,     0,     0,     0,
       0,   190,   191,   -88,   -88,   -88,     0,   -88,   -90,   -90,
     -90,     0,   -90,   -95,   -95,   -90,   -90,     0,     0,     0,
     195,     0,     0,     0,   190,   191,   -90,   -90,   -90,   195,
     -90,     0,   -93,   -93,   -93,     0,   -93,   -97,   -97,   -93,
     -93,     0,     0,     0,     0,     0,   -96,   -96,     0,     0,
     -93,   -93,   -93,   197,   -93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -100,  -100,   -95,   -95,   -95,     0,   -95,     0,     0,   -95,
     196,     0,     0,     0,   197,     0,     0,     0,     0,     0,
     -95,   -95,   -95,   199,   -95,     0,   -97,   -97,   -97,     0,
     -97,   -99,   -99,   -97,   196,   -96,   -96,   -96,     0,   -96,
    -102,  -102,   -96,   196,   -97,   -97,   -97,   201,   -97,     0,
       0,     0,     0,   -96,   -96,   -96,   201,   -96,     0,  -100,
    -100,  -100,     0,  -100,   202,  -104,  -100,     0,     0,     0,
     201,     0,     0,   202,  -104,     0,     0,   198,  -100,  -100,
       0,  -100,     0,     0,     0,     0,     0,   202,  -105,     0,
     -99,   -99,   -99,     0,   -99,     0,     0,   -99,     0,  -102,
    -102,  -102,     0,  -102,     0,     0,  -102,     0,   198,   -99,
     -99,     0,   -99,     0,     0,     0,     0,     0,   200,  -102,
       0,  -102,     0,  -104,  -104,  -104,     0,  -104,     0,     0,
    -104,     0,  -106,  -104,  -104,     0,  -106,     0,     0,  -106,
       0,     0,     0,  -104,     0,  -104,  -105,  -105,  -105,     0,
    -105,     0,  -104,  -105,  -106,   428,    79,    80,    81,    82,
      83,     0,    84,    85,     0,     0,  -105,     0,  -105,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    86,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,     0,   429,
     430,   431,     0,   432,   433,   434,   435,   436,   437,   438,
     439,     0,    87,     0,    88,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,   225,     0,    90,    91,    92,
      93,    94,    95,     0,    87,     0,    88,     0,     0,     0,
      89,   440,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,    77,     0,    78,    79,    80,
      81,    82,    83,   440,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,    86,     0,     0,     0,     0,
       0,     0,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,    28,    88,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,   353,     0,    78,    79,    80,
      81,    82,    83,     0,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   461,     0,    78,
      79,    80,    81,    82,    83,    86,    84,    85,     0,     0,
       0,     0,     9,    10,    11,     0,     0,     0,     0,   121,
       0,    78,    79,    80,    81,    82,    83,    86,    84,    85,
       0,     0,     0,     0,     9,    10,    11,     0,     0,     0,
       0,     0,     0,     0,    87,   124,    88,     0,     0,    86,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,     0,    87,   124,    88,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,    93,    94,    95,     0,    87,     0,
      88,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,    94,    95,   255,
       0,    78,    79,    80,    81,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   497,     0,    78,    79,    80,    81,    82,    83,    86,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   582,     0,    78,    79,    80,    81,    82,
      83,    86,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
      88,     0,     0,    86,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,    94,    95,     0,
      87,     0,    88,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,    94,
      95,     0,    87,     0,    88,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,    94,    95,    78,    79,    80,    81,    82,    83,     0,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    86,    84,    85,   235,     0,     0,     0,     9,    10,
      11,     0,     0,     0,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    86,    84,    85,   264,     0,     0,     0,
       9,    10,    11,     0,     0,     0,     0,     0,     0,     0,
      87,   124,    88,     0,     0,    86,    89,     0,   358,     0,
       0,   236,     9,    10,    11,    90,   237,    92,    93,    94,
      95,     0,    87,   124,    88,     0,     0,     0,    89,     0,
       0,     0,     0,   265,     0,     0,     0,    90,   266,    92,
      93,    94,    95,     0,    87,   124,    88,     0,     0,     0,
      89,     0,     0,     0,     0,   359,     0,     0,     0,    90,
     360,    92,    93,    94,    95,    78,    79,    80,    81,    82,
      83,     0,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    86,    84,    85,   377,     0,     0,     0,
       9,    10,    11,     0,     0,     0,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    86,    84,    85,   382,     0,
       0,     0,     9,    10,    11,     0,     0,     0,     0,     0,
       0,     0,    87,   124,    88,     0,     0,    86,    89,     0,
     479,     0,     0,   378,     9,    10,    11,    90,    91,    92,
      93,    94,    95,     0,    87,   124,    88,     0,     0,     0,
      89,     0,     0,     0,     0,   383,     0,     0,     0,    90,
     384,    92,    93,    94,    95,     0,    87,   124,    88,     0,
       0,     0,    89,     0,     0,     0,     0,   480,     0,     0,
       0,    90,    91,    92,    93,    94,    95,    78,    79,    80,
      81,    82,    83,     0,    84,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
      79,    80,    81,    82,    83,    86,    84,    85,     0,     0,
       0,     0,     9,    10,    11,     0,     0,     0,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    86,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,   124,    88,     0,     0,    86,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,     0,    87,     0,    88,     0,
       0,     0,    89,     0,     0,     0,   421,     0,   422,   334,
     558,    90,    91,    92,    93,    94,    95,     0,    87,     0,
      88,     0,     0,     0,    89,     0,     0,     0,   421,     0,
     422,   334,   587,    90,    91,    92,    93,    94,    95,    78,
      79,    80,    81,    82,    83,     0,    84,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    86,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    86,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    87,     0,    88,     0,
       0,    86,    89,     0,     0,     0,   421,     0,   422,   334,
       0,    90,    91,    92,    93,    94,    95,     0,    87,     0,
      88,     0,     0,     0,    89,   297,     0,     0,     0,     0,
       0,     0,     0,    90,    91,    92,    93,    94,    95,     0,
      87,     0,    88,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,   334,     0,    90,    91,    92,    93,    94,
      95,    78,    79,    80,    81,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    86,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    86,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
      88,     0,     0,    86,    89,     0,     0,     0,     0,     0,
       0,   397,     0,    90,    91,    92,    93,    94,    95,     0,
      87,     0,    88,     0,     0,     0,    89,     0,     0,     0,
       0,   458,     0,     0,     0,    90,    91,    92,    93,    94,
      95,     0,    87,     0,    88,     0,     0,     0,   158,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,    94,    95,    78,    79,    80,    81,    82,    83,     0,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    86,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,     0,    88,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,    90,    91,    92,    93,    94,
      95,     1,    87,    53,    88,     0,     0,     0,   273,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,    28,     0,    29,     0,    31,   342,   261,     0,     0,
     153,     0,     0,     0,     0,     2,    55,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,    28,     0,    29,     0,
      31,   152,   261,     0,     0,   153,     0,     0,     0,     0,
       2,    55,     0,     0,     0,     0,     0,     0,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,     0,     0,   152,     0,     0,     0,
     153,     0,     0,     0,     0,     2,    55,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   249,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
       2,     0,     0,     0,     0,     0,     0,     0,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,     2,     0,     0,     0,     0,
       0,     0,     0,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   368,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   367,
       2,     0,     0,     0,     0,     0,     0,     0,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   369,     2,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   227,     0,   228,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,    28,     0,    29,    30,
      31,     0,     0,     0,     0,     0,     0,     0,   225,     0,
       2,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,    28,     0,    29,     0,    31,     0,   229,     0,     0,
       0,     0,     0,     0,     0,     2,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,    28,     0,    29,     0,
      31,     0,   341,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    70,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,    28,     0,    29,     0,    31,     0,   380,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,    28,     0,    29,
      30,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    28,     0,    29,    30,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   452,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,    28,     0,    29,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   454,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,    28,     0,    29,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,    28,
       0,    29,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,     0,     0,
       0,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     0,    77,     0,     0,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,     0,   483,     0,     0,     0,
       0,     0,     2,     0,     0,     0,     0,   138,     0,    28,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     2,     0,     0,     0,
       0,     0,     0,    28,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28
};

static const yytype_int16 yycheck[] =
{
      89,   221,     0,     0,     1,    61,    33,    50,   133,    52,
       1,    52,   135,    50,    51,   102,    77,   155,   181,     0,
       1,     1,   192,   136,     1,   149,   150,    54,     1,    55,
       0,     1,     1,   187,     1,     1,     1,    34,    35,     1,
     153,   134,     1,    40,    41,    42,    44,    44,     1,     1,
      83,    77,    89,    34,    35,    76,   117,   605,    55,    40,
      41,    42,     3,    44,    34,    35,     1,   139,   616,   158,
      40,    41,    42,   145,    44,     1,   543,    76,   545,     3,
     547,    80,   391,   392,     3,   174,     1,    78,    76,     1,
     177,   117,    80,     1,   517,     3,     1,     1,    78,   224,
      77,   127,   129,    76,   147,   148,   147,   148,    99,    78,
       1,    78,    78,    78,   203,    84,   205,     3,    98,    99,
      76,   158,   235,    77,    76,   162,   152,   251,   252,    98,
     127,   224,    99,    99,    99,   133,   133,    99,   135,   136,
      99,    77,    83,    78,   307,   308,    99,   270,   318,   319,
       1,   264,   133,    79,   135,   152,   153,    76,   271,   313,
     314,   315,   316,   133,     3,   136,    81,    86,    80,   230,
      82,   152,    76,    78,     1,   247,   248,   600,   601,    84,
      99,    64,   153,    66,   273,     3,    98,    78,    79,     1,
      76,    76,   163,   164,    77,     1,   223,     3,    66,   242,
      86,   242,   173,   230,   230,   425,   344,     1,   295,     1,
       1,     3,     1,    76,     3,   340,   303,   304,   305,     1,
      78,     1,    16,    17,    18,    19,   224,   224,    79,     1,
     227,     1,     1,   116,    77,   118,   273,    76,   235,    83,
      76,    80,   239,   224,    80,    78,   227,    86,    18,    19,
     221,    78,    79,    78,   224,   138,   139,   227,    76,     3,
     143,   144,   145,     1,   235,     3,    78,   264,   239,   382,
       1,   268,    84,   270,   271,   143,   144,     1,    84,     1,
     500,   501,     3,    77,    78,    79,    77,    81,   344,   270,
      84,    85,    84,   264,    83,     1,    78,   268,    78,    81,
     271,    95,    96,    97,    84,    99,    78,    77,    78,    79,
      79,    81,    84,     6,    84,   342,   342,     3,     1,   290,
     291,   446,   293,   366,     6,   366,    96,    97,     1,    99,
     550,   551,    84,    16,    17,    18,    19,   557,    76,    81,
     560,    79,   340,   340,     3,   342,    77,    78,    86,    81,
     439,   348,   349,    77,    78,    77,     3,     1,   355,   340,
       1,   342,    79,   334,   247,   248,   249,   348,   349,     1,
     340,    77,    78,   416,   417,   418,    77,   374,   421,     1,
     421,    77,   353,    81,   355,   382,   429,   358,   429,   386,
      76,    81,   517,    79,    77,    78,    79,    19,    81,    77,
      86,    84,    85,   374,    77,    78,   377,    78,     1,   195,
     196,   382,    95,    96,    97,   386,    99,    76,    83,     1,
      77,    80,   511,   512,   513,     1,   397,     1,   399,    76,
     401,   402,    79,    77,    78,     1,    77,    78,   507,    86,
     509,     1,   197,   198,   415,    77,   417,   516,   446,   446,
     199,   200,    99,    77,   425,    77,    78,    79,     1,    81,
     201,   202,    84,   203,   204,   446,    50,     1,    52,     1,
     184,   185,   186,     3,     1,    97,   446,    99,     3,   476,
      81,   570,   571,    76,    77,   368,    79,    80,     9,    10,
      11,   500,   501,    86,   563,    77,    78,   566,    81,    83,
      81,    77,    78,    77,    78,   476,   363,   364,   479,    81,
      81,    77,    78,   348,   349,    77,    81,    77,   102,   517,
     517,   610,   591,    81,   593,   594,    83,   596,     3,   500,
     501,    99,    99,    79,    77,    78,   517,   606,    76,    81,
     629,   550,   551,    77,    78,    77,    78,   517,   617,   618,
      77,    78,    81,   622,    76,    76,   527,    81,   627,    80,
      62,    82,    81,   147,   148,    81,    81,   636,    81,    81,
     541,   542,    79,    81,    79,   546,   160,   161,    76,   550,
     551,    81,    81,    79,    76,    99,   557,    60,    77,   560,
      77,    72,   129,   177,   397,   426,     1,   181,     3,   446,
     184,   185,   186,   187,   621,    44,   577,    -1,   192,    -1,
      -1,   195,   196,   197,   198,   199,   200,   201,   202,    -1,
     204,    -1,    -1,   594,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,    38,
      39,    40,    -1,    -1,    69,    -1,    71,    -1,    73,    -1,
      75,    76,    77,    78,    79,    80,    -1,    -1,    83,    -1,
       1,    86,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    71,    -1,    99,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    86,    -1,    -1,
      31,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
     304,   305,    -1,   307,   308,    -1,    -1,    -1,    -1,   313,
     314,   315,   316,    -1,   318,   319,    57,    58,    59,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    85,    86,    87,    88,    89,    90,
      -1,    -1,    -1,    98,    -1,    -1,     1,    -1,    99,    -1,
      -1,    -1,   366,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,   416,    58,   418,    -1,    -1,   421,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   429,    71,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,    -1,    84,
      85,    86,    87,    88,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,
      86,    87,    88,    89,    90,     1,    -1,     3,     4,     5,
       6,     7,     8,    99,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,
      86,    87,    88,    89,    90,     1,    -1,     3,     4,     5,
       6,     7,     8,    99,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,     1,    -1,     3,    18,    19,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    81,    -1,    69,
      84,    71,     1,    73,     3,    75,    76,    77,    78,    79,
      80,    95,    96,    97,    -1,    99,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,     1,    73,     3,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
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
      -1,    -1,    69,    -1,    71,     1,    73,     3,    75,    76,
      77,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    30,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,     1,    73,     3,    75,
      76,    77,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,     1,    73,     3,
      75,    76,    77,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,     1,    73,
      -1,    75,    76,    77,    78,    -1,    80,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    99,    -1,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,    -1,    -1,    -1,    69,    -1,    71,    -1,
      73,    74,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    98,    99,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    76,    77,    -1,    79,    80,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    99,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    76,    77,     1,
      79,    80,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      99,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    -1,    81,
      -1,    -1,    84,    85,    86,    87,    88,    -1,    -1,    91,
      92,    93,    94,    95,    96,    97,    -1,    99,    77,    78,
      79,    -1,    81,    -1,    -1,    84,    85,    86,    87,    88,
      -1,    -1,    91,    92,    93,    94,    95,    96,    97,    -1,
      99,    77,    78,    79,    -1,    81,    -1,    -1,    84,    85,
      86,    87,    88,     1,    -1,    91,    92,    93,    94,    95,
      96,    97,    -1,    99,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    -1,    81,    -1,    -1,    84,    85,    86,    87,
      88,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      -1,    99,    77,    78,    79,    -1,    81,    -1,    -1,    84,
      85,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    -1,    99,    77,    78,    79,    -1,    81,
      -1,    -1,    84,    85,    -1,    87,    88,     1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    -1,    99,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    -1,    81,    -1,    -1,
      84,    85,    -1,    87,    88,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    -1,    99,    77,    78,    79,    -1,
      81,    -1,    -1,    84,    85,    -1,    87,    88,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    -1,    99,    77,
      78,    79,    -1,    81,    -1,    -1,    84,    85,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      -1,    99,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    81,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    -1,    99,
      77,    78,    79,    -1,    81,    -1,    -1,    84,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    -1,    99,    77,    78,    79,    -1,    81,    -1,    -1,
      84,    85,    -1,    -1,    -1,     1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    -1,    99,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    -1,    81,    31,    -1,    84,    85,
      -1,    -1,    18,    19,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    -1,    99,    77,    78,    79,    -1,    81,    -1,
      -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      93,    94,    95,    96,    97,    70,    99,    72,    -1,    -1,
      -1,    76,    14,    15,    16,    17,    18,    19,    -1,    -1,
      85,    86,    87,    88,    89,    90,     1,    -1,    -1,    -1,
      -1,    77,    78,    79,    99,    81,    -1,    -1,    84,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,     1,
      96,    97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,     1,    -1,    -1,    77,    78,    79,    -1,    81,
      -1,    -1,    84,    85,    -1,    14,    15,    16,    17,    18,
      19,    93,    94,    95,    96,    97,     1,    99,    -1,    -1,
      -1,    -1,    77,    78,    79,    -1,    81,    -1,    -1,    84,
      85,    16,    17,    18,    19,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    -1,    99,    77,    78,    79,    -1,    81,
      -1,    -1,    84,    85,    -1,    -1,     1,    -1,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    -1,    99,    77,    78,
      79,    -1,    81,    18,    19,    84,    85,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    93,    94,    95,    96,    97,     1,
      99,    -1,    77,    78,    79,    -1,    81,    18,    19,    84,
      85,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      95,    96,    97,     1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    77,    78,    79,    -1,    81,    -1,    -1,    84,
      85,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,     1,    99,    -1,    77,    78,    79,    -1,
      81,    18,    19,    84,    85,    77,    78,    79,    -1,    81,
      18,    19,    84,    85,    95,    96,    97,     1,    99,    -1,
      -1,    -1,    -1,    95,    96,    97,     1,    99,    -1,    77,
      78,    79,    -1,    81,    18,    19,    84,    -1,    -1,    -1,
       1,    -1,    -1,    18,    19,    -1,    -1,    95,    96,    97,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,
      77,    78,    79,    -1,    81,    -1,    -1,    84,    -1,    77,
      78,    79,    -1,    81,    -1,    -1,    84,    -1,    95,    96,
      97,    -1,    99,    -1,    -1,    -1,    -1,    -1,    96,    97,
      -1,    99,    -1,    77,    78,    79,    -1,    81,    -1,    -1,
      84,    -1,    77,    78,    79,    -1,    81,    -1,    -1,    84,
      -1,    -1,    -1,    97,    -1,    99,    77,    78,    79,    -1,
      81,    -1,    97,    84,    99,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    97,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    31,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    57,
      58,    59,    -1,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
      88,    89,    90,    -1,    70,    -1,    72,    -1,    -1,    -1,
      76,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,     1,    -1,     3,     4,     5,
       6,     7,     8,    99,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,     1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,     7,     8,    31,    10,    11,    -1,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,    31,    10,    11,
      -1,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,    31,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    -1,    70,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,     1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,    31,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,    31,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    31,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    -1,
      70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    31,    10,    11,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    31,    10,    11,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    -1,    -1,    31,    76,    -1,    34,    -1,
      -1,    81,    38,    39,    40,    85,    86,    87,    88,    89,
      90,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,    -1,    70,    71,    72,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    31,    10,    11,    34,    -1,    -1,    -1,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    31,    10,    11,    34,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    -1,    31,    76,    -1,
      34,    -1,    -1,    81,    38,    39,    40,    85,    86,    87,
      88,    89,    90,    -1,    70,    71,    72,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    -1,    70,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    31,    10,    11,    -1,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    31,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,    31,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    -1,    70,    -1,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    70,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    31,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    31,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,
      -1,    31,    76,    -1,    -1,    -1,    80,    -1,    82,    83,
      -1,    85,    86,    87,    88,    89,    90,    -1,    70,    -1,
      72,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    -1,
      70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,    89,
      90,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    31,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    31,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      72,    -1,    -1,    31,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    -1,    85,    86,    87,    88,    89,    90,    -1,
      70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,    -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    31,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,
      90,     1,    70,     3,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    -1,    75,    76,    77,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    30,    86,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    -1,
      75,    76,    77,    -1,    -1,    80,    -1,    -1,    -1,    -1,
      30,    86,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    30,    86,    -1,    -1,    -1,
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
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    -1,
      75,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     0,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    -1,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,
      -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    -1,    73,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      -1,    73,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,     1,    -1,    71,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    30,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    69,    71,    73,
      74,    75,   141,   142,   146,   147,   148,   149,   155,   158,
     159,   160,   161,   178,   206,   207,   208,   142,     3,    83,
      76,    76,    76,     3,    76,    86,    99,   143,   144,   162,
     163,   164,   142,   142,     1,     3,    83,   142,   142,   142,
       0,   207,    83,     3,   103,   156,   157,     1,     3,     4,
       5,     6,     7,     8,    10,    11,    31,    70,    72,    76,
      85,    86,    87,    88,    89,    90,   101,   102,   104,   105,
     108,   110,   113,   114,   115,   119,   122,   123,   128,   131,
     132,   133,   134,   135,   136,   140,   147,   152,   159,   170,
     170,     1,   140,   162,    71,   159,   164,   165,     1,    78,
      99,     1,    98,   209,   210,    76,    80,   163,     1,   150,
     151,   152,   178,     1,    83,   150,   156,     1,    98,     1,
      78,    84,    76,    80,   152,   164,   171,   172,    76,   110,
     111,   112,    76,     1,    76,   110,   136,   137,   139,   170,
       9,    10,    11,    76,    80,    82,   114,     1,    86,    91,
      92,     1,    87,    88,     1,    12,    13,     1,    14,    15,
      93,    94,     1,    16,    17,     1,    85,     1,    95,     1,
      96,     1,    18,     1,    19,    97,    77,   152,     1,   171,
     152,    77,    77,    78,    78,     1,    77,   159,   164,   144,
     162,   145,   141,   142,   211,    83,   183,     1,     3,    77,
     142,   166,   167,   168,   169,    34,    81,    86,   137,   165,
      84,   151,    79,    99,   153,   154,   162,   150,   150,     1,
      84,     1,    78,    84,   140,     1,   140,   157,     1,    84,
     157,    77,   166,   171,    34,    81,    86,   137,   165,   172,
      76,    80,   170,    76,   110,   110,   170,   137,   137,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    98,
     138,     1,    77,    78,     1,    77,     3,    77,   109,   137,
     139,     3,   114,   116,   117,   118,   115,   120,   121,   119,
     119,   119,   122,   126,   127,   124,   125,   123,   129,   130,
     128,   128,   131,   131,   132,   132,   133,   133,   134,   139,
     134,   139,     6,     6,    83,   137,   173,   141,   183,    84,
     184,    77,    76,   162,   164,   171,     1,    77,     1,    78,
       1,    77,    78,     1,   137,   165,    81,    81,    34,    81,
      86,   137,   140,     1,    78,    99,    79,    84,     1,    84,
      84,    77,    77,   137,   165,    81,    81,    34,    81,   137,
      77,   166,    34,    81,    86,   137,   165,    77,   170,    77,
      78,     1,    78,   137,   137,   137,    83,    83,   114,     1,
      77,    78,     1,    81,   114,   114,   114,   115,   115,   122,
     122,   122,   122,   123,   123,     1,    79,     1,    79,    77,
      77,    80,    82,   173,   174,   175,   176,   177,     3,    57,
      58,    59,    61,    62,    63,    64,    65,    66,    67,    68,
      99,   139,   141,   179,   180,   183,   185,   186,   187,   188,
     194,   205,    56,   168,    56,   168,     3,     3,    81,   137,
      81,     1,   137,   137,    81,    81,   154,     1,   154,   140,
      81,   137,   137,    81,    77,   137,   165,    81,    81,    34,
      81,   137,    77,    58,   106,   107,   170,   106,   106,   174,
     137,   137,   136,   136,   136,    99,    99,     1,   140,     3,
       1,    78,    84,   173,     1,    98,   177,    79,   140,     1,
     182,     1,    76,     1,   190,   195,   197,    76,     1,     3,
       1,    99,     1,    99,     1,    99,   139,     1,    99,    84,
     186,    81,    81,    81,    81,    81,    81,    81,   137,   137,
      81,     1,    79,     1,    77,    78,    79,     1,    77,    77,
       1,    78,    84,    81,     1,    81,   173,   175,    84,   173,
     175,     1,   179,     1,   181,   179,    79,   139,   139,   139,
      76,    76,   179,   141,   187,     1,    99,     1,    99,    81,
      81,   137,     1,   137,   107,   107,   137,    84,   173,   173,
     179,    79,   179,    77,     1,    77,    77,   139,   139,    62,
     200,   198,   179,   179,   137,   179,   189,   179,    77,    77,
      76,   187,   187,    60,   192,   192,   179,   191,   196,   139,
     201,   199,   193,   192,   179,   179,    77,    77,   202,   203,
     202,   179,    99,   179,   139,    77,   204,   179
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
     128,   128,   131,   131,   131,   132,   132,   132,   133,   133,
     133,   134,   134,   134,   135,   135,   135,   136,   136,   136,
     136,   137,   137,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   139,   139,   139,   140,   141,   141,
     141,   141,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   143,   143,   143,   145,   144,   144,   144,
     146,   146,   146,   146,   146,   146,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   148,   148,   148,   148,   148,   148,   148,   149,
     149,   150,   150,   151,   151,   151,   151,   152,   152,   152,
     152,   152,   153,   153,   153,   153,   154,   154,   154,   155,
     155,   155,   155,   155,   155,   155,   156,   156,   156,   156,
     157,   157,   157,   157,   158,   159,   159,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   164,   164,   164,   164,
     165,   165,   166,   166,   166,   167,   167,   167,   168,   168,
     168,   169,   169,   169,   170,   170,   170,   170,   171,   171,
     171,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   173,   173,   173,   173,   174,   174,   174,   174,
     174,   174,   175,   175,   176,   176,   177,   177,   177,   177,
     178,   178,   179,   179,   179,   179,   179,   179,   180,   181,
     180,   182,   180,   180,   180,   180,   183,   184,   183,   185,
     185,   186,   186,   187,   187,   187,   189,   188,   190,   191,
     188,   188,   188,   188,   192,   193,   192,   195,   196,   194,
     197,   194,   198,   199,   194,   200,   201,   194,   202,   203,
     204,   202,   205,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   206,   206,   207,   207,   209,   208,   210,
     208,   211,   211
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
       4,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     5,     5,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     2,     3,
       1,     3,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     3,     2,     0,     4,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     2,     4,     5,     5,     4,     1,
       1,     1,     2,     2,     3,     1,     3,     2,     1,     2,
       1,     2,     1,     3,     3,     3,     2,     3,     1,     4,
       5,     5,     6,     2,     5,     4,     1,     3,     3,     3,
       3,     1,     3,     3,     4,     1,     1,     1,     1,     1,
       1,     4,     4,     2,     1,     1,     3,     3,     4,     6,
       5,     5,     6,     5,     4,     4,     4,     3,     4,     3,
       6,     6,     5,     4,     4,     4,     3,     2,     2,     1,
       1,     2,     3,     1,     3,     1,     3,     3,     2,     2,
       1,     1,     3,     3,     2,     1,     2,     2,     2,     1,
       1,     3,     2,     3,     5,     4,     5,     4,     3,     3,
       3,     4,     6,     5,     5,     6,     4,     4,     2,     3,
       3,     4,     3,     4,     1,     3,     2,     1,     4,     3,
       3,     4,     2,     2,     1,     2,     3,     2,     3,     3,
       7,     7,     1,     1,     1,     1,     1,     1,     3,     0,
       5,     0,     4,     3,     4,     3,     2,     0,     4,     1,
       2,     1,     1,     1,     2,     2,     0,     7,     0,     0,
       7,     6,     6,     5,     0,     0,     3,     0,     0,     7,
       0,     8,     0,     0,     7,     0,     0,     7,     2,     0,
       0,     5,     3,     2,     2,     2,     3,     2,     3,     2,
       2,     3,     2,     1,     2,     1,     1,     0,     5,     0,
       4,     1,     2
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
      YYCASE_(0, YY_("Error de sintaxis"));
      YYCASE_(1, YY_("Error de sintaxis, carácter %s inesperado "));
      YYCASE_(2, YY_("Error de sintaxis, carácter %s inesperado, se esperaba %s"));
      YYCASE_(3, YY_("Error de sintaxis, carácter %s inesperado, se esperaba %s ó %s"));
      YYCASE_(4, YY_("Error de sintaxis, carácter %s inesperado, se esperaba %s ó %s ó %s"));
      YYCASE_(5, YY_("Error de sintaxis, carácter %s inesperado, se esperaba %s ó %s ó %s ó %s"));
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
#line 63 "bison.y" /* yacc.c:1646  */
    {

						if(nextToken == IDENTIFIER)
							process_id();
						else if (nextToken == '(')
							process_function();
						else if (nextToken == '=' || 275 <= nextToken <= 284)
							verify_id_for_Assign();
					}
#line 2793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 77 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 81 "bison.y" /* yacc.c:1646  */
    { process_literal(I_CONSTANT); }
#line 2805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 97 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 98 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 99 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 107 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 114 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 115 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 121 "bison.y" /* yacc.c:1646  */
    { call_functionNoParams(); }
#line 2847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 125 "bison.y" /* yacc.c:1646  */
    { save_op(); eval_unary(); }
#line 2853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 126 "bison.y" /* yacc.c:1646  */
    { save_op(); eval_unary(); }
#line 2859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 139 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 140 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 141 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 153 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 158 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 2889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 158 "bison.y" /* yacc.c:1646  */
    { eval_unary(); }
#line 2895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 159 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 2901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 159 "bison.y" /* yacc.c:1646  */
    { eval_unary(); }
#line 2907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 160 "bison.y" /* yacc.c:1646  */
    { eval_unary(); }
#line 2913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 175 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 2919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 176 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 2925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 189 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 2931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 189 "bison.y" /* yacc.c:1646  */
    {  eval_binary(); }
#line 2937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 190 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 2943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 190 "bison.y" /* yacc.c:1646  */
    {  eval_binary(); }
#line 2949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 191 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 2955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 191 "bison.y" /* yacc.c:1646  */
    {  eval_binary(); }
#line 2961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 195 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 200 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 2973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 200 "bison.y" /* yacc.c:1646  */
    { eval_binary(); }
#line 2979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 201 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 2985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 201 "bison.y" /* yacc.c:1646  */
    { eval_binary(); }
#line 2991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 206 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 214 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 219 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 3009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 219 "bison.y" /* yacc.c:1646  */
    { eval_binary(); }
#line 3015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 220 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 3021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 220 "bison.y" /* yacc.c:1646  */
    { eval_binary(); }
#line 3027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 221 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 3033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 221 "bison.y" /* yacc.c:1646  */
    { eval_binary(); }
#line 3039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 222 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 3045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 222 "bison.y" /* yacc.c:1646  */
    { eval_binary(); }
#line 3051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 232 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 3057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 232 "bison.y" /* yacc.c:1646  */
    { eval_binary(); }
#line 3063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 233 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 3069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 233 "bison.y" /* yacc.c:1646  */
    { eval_binary(); }
#line 3075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 235 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 241 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 247 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 253 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 259 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 266 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 274 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 275 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 280 "bison.y" /* yacc.c:1646  */
    { process_assign(); }
#line 3129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 287 "bison.y" /* yacc.c:1646  */
    {save_op();}
#line 3135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 288 "bison.y" /* yacc.c:1646  */
    {save_op();}
#line 3141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 289 "bison.y" /* yacc.c:1646  */
    {save_op();}
#line 3147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 290 "bison.y" /* yacc.c:1646  */
    {save_op();}
#line 3153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 291 "bison.y" /* yacc.c:1646  */
    {save_op();}
#line 3159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 292 "bison.y" /* yacc.c:1646  */
    {save_op();}
#line 3165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 293 "bison.y" /* yacc.c:1646  */
    {save_op();}
#line 3171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 294 "bison.y" /* yacc.c:1646  */
    {save_op();}
#line 3177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 295 "bison.y" /* yacc.c:1646  */
    {save_op();}
#line 3183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 296 "bison.y" /* yacc.c:1646  */
    {save_op();}
#line 3189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 297 "bison.y" /* yacc.c:1646  */
    {save_op();}
#line 3195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 305 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 313 "bison.y" /* yacc.c:1646  */
    { declaration_end(); }
#line 3207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 314 "bison.y" /* yacc.c:1646  */
    { declaration_end(); }
#line 3213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 319 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 326 "bison.y" /* yacc.c:1646  */
    { save_type(); }
#line 3225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 328 "bison.y" /* yacc.c:1646  */
    { save_type(); }
#line 3231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 330 "bison.y" /* yacc.c:1646  */
    { save_type(); }
#line 3237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 332 "bison.y" /* yacc.c:1646  */
    { save_type(); }
#line 3243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 334 "bison.y" /* yacc.c:1646  */
    { save_type(); }
#line 3249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 335 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 341 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 345 "bison.y" /* yacc.c:1646  */
    { save_op(); }
#line 3267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 345 "bison.y" /* yacc.c:1646  */
    { process_assign(); }
#line 3273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 346 "bison.y" /* yacc.c:1646  */
    { initializeID(); }
#line 3279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 347 "bison.y" /* yacc.c:1646  */
    {
					if(yychar == IDENTIFIER || yychar == I_CONSTANT || yychar == F_CONSTANT)
						yyerrok;

					yyclearin;
					clearSemanticRecords(); }
#line 3290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 387 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 388 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 389 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 390 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 410 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 418 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 424 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 425 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 444 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 445 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 453 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 454 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 461 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 463 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 493 "bison.y" /* yacc.c:1646  */
    { save_id(); }
#line 3380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 511 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 512 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 513 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 517 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 518 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 519 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 520 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 545 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 551 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 263:
#line 565 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 266:
#line 572 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 267:
#line 573 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 615 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 623 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 624 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 630 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 641 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 642 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 647 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 319:
#line 661 "bison.y" /* yacc.c:1646  */
    { begin_case(); }
#line 3500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 320:
#line 661 "bison.y" /* yacc.c:1646  */
    { end_case(); }
#line 3506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 321:
#line 662 "bison.y" /* yacc.c:1646  */
    { create_default(); }
#line 3512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 322:
#line 662 "bison.y" /* yacc.c:1646  */
    { append_exit(); }
#line 3518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 664 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 665 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 666 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 673 "bison.y" /* yacc.c:1646  */
    { inContext = TRUE; pushTable(); }
#line 3542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 673 "bison.y" /* yacc.c:1646  */
    {inContext = FALSE;  popTable();}
#line 3548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 689 "bison.y" /* yacc.c:1646  */
    { if (!inFor) popRecord(); }
#line 3554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 691 "bison.y" /* yacc.c:1646  */
    {  yyerrok; }
#line 3560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 695 "bison.y" /* yacc.c:1646  */
    { start_if(); }
#line 3566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 695 "bison.y" /* yacc.c:1646  */
    { end_if(); }
#line 3572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 696 "bison.y" /* yacc.c:1646  */
    { start_switch(); }
#line 3578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 696 "bison.y" /* yacc.c:1646  */
    { save_comparator(); }
#line 3584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 696 "bison.y" /* yacc.c:1646  */
    { end_switch(); }
#line 3590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 699 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 700 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 701 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 712 "bison.y" /* yacc.c:1646  */
    { start_else(); }
#line 3614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 716 "bison.y" /* yacc.c:1646  */
    { start_while(); }
#line 3620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 716 "bison.y" /* yacc.c:1646  */
    { evaluate_expression(); }
#line 3626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 716 "bison.y" /* yacc.c:1646  */
    { exit_while(); }
#line 3632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 717 "bison.y" /* yacc.c:1646  */
    { start_doWhile(); }
#line 3638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 717 "bison.y" /* yacc.c:1646  */
    { evaluate_expression(); exit_doWhile();}
#line 3644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 718 "bison.y" /* yacc.c:1646  */
    { inFor = TRUE; begin_for(); }
#line 3650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 718 "bison.y" /* yacc.c:1646  */
    { evaluate_expression(); }
#line 3656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 719 "bison.y" /* yacc.c:1646  */
    { inFor = TRUE; begin_for(); }
#line 3662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 719 "bison.y" /* yacc.c:1646  */
    { evaluate_expression(); }
#line 3668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 751 "bison.y" /* yacc.c:1646  */
    { redirect_code(); }
#line 3674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 751 "bison.y" /* yacc.c:1646  */
    { restore_code(); }
#line 3680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 751 "bison.y" /* yacc.c:1646  */
    { end_for(); }
#line 3686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 761 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 368:
#line 762 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 369:
#line 763 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 370:
#line 764 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 371:
#line 765 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 372:
#line 766 "bison.y" /* yacc.c:1646  */
    { yyerrok; }
#line 3722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 780 "bison.y" /* yacc.c:1646  */
    { start_function(); stackPos -= 4; }
#line 3728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 780 "bison.y" /* yacc.c:1646  */
    { end_function(); unDecleared = FALSE; inContext = FALSE; popTable(); stackPos -= 4; }
#line 3734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 785 "bison.y" /* yacc.c:1646  */
    { start_function(); stackPos -= 4; }
#line 3740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 789 "bison.y" /* yacc.c:1646  */
    { end_function(); unDecleared = FALSE;  stackPos -= 4;}
#line 3746 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3750 "y.tab.c" /* yacc.c:1646  */
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
#line 797 "bison.y" /* yacc.c:1906  */


#include "semanticActions.c"
