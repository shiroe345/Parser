/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "compiler.y"

    #include "compiler_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol();
    static void insert_symbol();
    static void lookup_symbol();
    static void dump_symbol();

    /* Global variables */
    bool HAS_ERROR = false;
    static int scope_level = -1;
    static int addr = -1;
    char type[10];

    struct Symbol{
        char name[1000][100];
        int mut[1000];
        char type[1000][10];
        int addr[1000];
        int lineno[1000];
        char func_sig[1000][100];
        int size;
    };

    typedef struct Symbol symbol;

    symbol stack[100];

#line 117 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LET = 258,
    MUT = 259,
    NEWLINE = 260,
    INT = 261,
    FLOAT = 262,
    BOOL = 263,
    STR = 264,
    TRUE = 265,
    FALSE = 266,
    GEQ = 267,
    LEQ = 268,
    EQL = 269,
    NEQ = 270,
    LOR = 271,
    LAND = 272,
    ADD_ASSIGN = 273,
    SUB_ASSIGN = 274,
    MUL_ASSIGN = 275,
    DIV_ASSIGN = 276,
    REM_ASSIGN = 277,
    IF = 278,
    ELSE = 279,
    FOR = 280,
    WHILE = 281,
    LOOP = 282,
    PRINT = 283,
    PRINTLN = 284,
    FUNC = 285,
    RETURN = 286,
    BREAK = 287,
    ID = 288,
    ARROW = 289,
    AS = 290,
    IN = 291,
    DOTDOT = 292,
    RSHIFT = 293,
    LSHIFT = 294,
    IDENT = 295,
    INT_LIT = 296,
    STRING_LIT = 297,
    FLOAT_LIT = 298
  };
#endif
/* Tokens.  */
#define LET 258
#define MUT 259
#define NEWLINE 260
#define INT 261
#define FLOAT 262
#define BOOL 263
#define STR 264
#define TRUE 265
#define FALSE 266
#define GEQ 267
#define LEQ 268
#define EQL 269
#define NEQ 270
#define LOR 271
#define LAND 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define REM_ASSIGN 277
#define IF 278
#define ELSE 279
#define FOR 280
#define WHILE 281
#define LOOP 282
#define PRINT 283
#define PRINTLN 284
#define FUNC 285
#define RETURN 286
#define BREAK 287
#define ID 288
#define ARROW 289
#define AS 290
#define IN 291
#define DOTDOT 292
#define RSHIFT 293
#define LSHIFT 294
#define IDENT 295
#define INT_LIT 296
#define STRING_LIT 297
#define FLOAT_LIT 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 57 "compiler.y"

    int i_val;
    float f_val;
    char *s_val;
    /* ... */

#line 262 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   650

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  264

#define YYUNDEFTOK  2
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,     2,    57,    50,     2,
      44,    45,    51,    52,    49,    53,    48,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,    65,
      58,    64,    59,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,    60,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,    61,    67,    54,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,    95,    96,   100,   101,   102,   106,   107,
     108,   109,   113,   114,   115,   116,   117,   121,   122,   123,
     124,   125,   126,   130,   131,   135,   136,   140,   141,   142,
     143,   144,   145,   149,   150,   154,   155,   156,   157,   161,
     162,   163,   167,   168,   169,   173,   174,   175,   176,   177,
     181,   182,   183,   187,   188,   192,   193,   197,   198,   202,
     203,   207,   208,   212,   213,   217,   218,   222,   223,   224,
     225,   226,   227,   231,   232,   236,   240,   241,   245,   246,
     247,   248,   252,   253,   257,   258,   262,   266,   267,   268,
     269,   270,   274,   277,   278,   282,   283,   287,   293,   294,
     295,   296,   297,   298,   302,   303,   307,   311,   312,   316,
     317,   318,   322,   323,   327,   328,   332,   333,   334,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   350,   351,
     352,   356,   357,   361,   362,   363,   364,   365,   366,   367,
     371,   375,   376,   377,   378,   382,   383,   387,   388,   392,
     393,   397,   398,   402,   403,   404,   408,   409,   410,   414,
     415
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LET", "MUT", "NEWLINE", "INT", "FLOAT",
  "BOOL", "STR", "TRUE", "FALSE", "GEQ", "LEQ", "EQL", "NEQ", "LOR",
  "LAND", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "REM_ASSIGN", "IF", "ELSE", "FOR", "WHILE", "LOOP", "PRINT", "PRINTLN",
  "FUNC", "RETURN", "BREAK", "ID", "ARROW", "AS", "IN", "DOTDOT", "RSHIFT",
  "LSHIFT", "IDENT", "INT_LIT", "STRING_LIT", "FLOAT_LIT", "'('", "')'",
  "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'",
  "'{'", "'}'", "$accept", "Program", "GlobalStatementList",
  "GlobalStatement", "FunctionDeclStmt", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "func_specifier",
  "type_specifier", "Type", "specifier_qualifier_list", "declarator",
  "direct_declarator", "pointer", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "print_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    40,    41,    91,    93,    46,    44,
      38,    42,    43,    45,   126,    33,    47,    37,    60,    62,
      94,   124,    63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF (-152)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-93)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     126,  -152,  -152,  -152,  -152,  -152,  -152,  -152,   128,   -23,
      40,   241,  -152,  -152,  -152,    -9,    54,    54,  -152,    58,
     119,    57,    12,  -152,  -152,  -152,  -152,   -15,  -152,   266,
    -152,  -152,   186,  -152,    -9,  -152,    58,   380,   515,   119,
    -152,   128,  -152,   466,  -152,    58,    15,    37,    51,    79,
      86,   483,    75,    87,  -152,  -152,  -152,   301,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,   162,    25,   595,
    -152,    91,    -1,   146,    10,   255,   105,   138,   112,   218,
       9,  -152,  -152,   -10,  -152,  -152,  -152,   236,   341,  -152,
    -152,  -152,  -152,  -152,   191,  -152,  -152,  -152,  -152,   253,
     212,   214,  -152,    76,  -152,  -152,  -152,  -152,   248,  -152,
     466,  -152,  -152,  -152,   595,   499,   595,   595,   595,  -152,
       5,  -152,   431,   108,   225,    31,   260,   243,   531,   595,
     277,  -152,  -152,  -152,  -152,  -152,  -152,   595,  -152,   595,
     595,   595,   595,   595,   595,   595,   595,   595,   595,   595,
     595,   595,   595,   595,   595,   595,   595,   595,   595,  -152,
    -152,   386,  -152,  -152,   317,   547,  -152,   161,  -152,   238,
    -152,    54,  -152,   289,  -152,  -152,   -19,   113,   499,   174,
     176,   209,  -152,  -152,  -152,  -152,   130,   272,  -152,   595,
    -152,  -152,   211,  -152,   173,  -152,  -152,  -152,  -152,  -152,
      91,    91,    -1,    -1,   146,   146,   146,   146,    10,    10,
     255,   105,   138,   112,   218,   -30,  -152,  -152,  -152,   288,
     290,  -152,   287,   238,   137,   563,  -152,  -152,   448,  -152,
     431,   579,   431,   235,   271,  -152,  -152,   595,  -152,   595,
    -152,  -152,  -152,  -152,   292,  -152,   291,  -152,  -152,   315,
     431,   249,  -152,  -152,  -152,  -152,  -152,  -152,  -152,   431,
    -152,   431,  -152,  -152
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      92,     7,    87,    88,    89,    90,    86,    97,     0,   104,
       0,     2,     4,     5,     6,     0,    80,    78,    91,    92,
      96,     0,     0,   105,     1,     3,    76,     0,    82,    92,
      81,    79,     0,   145,     0,    11,    92,    92,     0,    95,
      98,     0,    77,     0,     9,    92,     0,     0,     0,     0,
       0,     0,     0,    12,    13,    14,    15,    92,    27,    28,
      29,    30,    31,    32,   149,   141,    17,    25,    33,     0,
      35,    39,    42,    45,    50,    53,    55,    57,    59,    61,
      63,    65,    73,     0,   147,   133,   134,     0,     0,   135,
     136,   137,   138,   139,    84,   146,    10,   112,   103,   111,
       0,   106,   107,     0,    12,   100,    33,    75,     0,    83,
       0,   128,    85,     8,     0,     0,     0,     0,     0,   157,
       0,   156,     0,     0,    92,   114,     0,     0,     0,     0,
       0,    68,    69,    70,    71,    72,    67,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   150,
     143,     0,   142,   148,    92,     0,   109,   116,   110,   117,
     101,    92,   102,     0,    99,   131,     0,     0,     0,     0,
       0,     0,   158,   140,    16,    93,    92,   116,   115,     0,
      22,    19,     0,    23,     0,    21,    66,    36,    37,    38,
      40,    41,    44,    43,    49,    48,    46,    47,    51,    52,
      54,    56,    58,    60,    62,     0,    74,   144,   124,     0,
       0,   120,     0,   118,    92,     0,   108,   113,     0,   129,
       0,     0,     0,     0,     0,    34,    20,     0,    18,     0,
     125,   119,   121,   126,     0,   122,     0,   130,   132,   151,
       0,     0,   153,   159,   160,    24,    64,   127,   123,     0,
     154,     0,   152,   155
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,  -152,   329,  -152,  -152,  -152,  -152,   -37,  -152,
     -48,   177,   183,   165,   171,   194,   195,   196,   203,   193,
    -152,   -36,   -38,  -152,   -31,  -151,    13,     0,  -152,   318,
    -152,   -45,  -152,   247,    -5,   -13,    -3,   -33,  -152,   189,
    -152,  -152,   -72,  -149,  -101,  -152,   -81,  -152,   168,    44,
     278,  -100,  -152,  -152,  -152,  -152
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    66,    67,   192,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,   137,    83,   108,    33,    34,    27,    28,
      16,    17,    18,   125,    19,    20,    21,   219,   101,   102,
     103,   126,   220,   169,   112,   176,    84,    85,    86,    36,
      88,    89,    90,    91,    92,    93
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,   106,   107,    22,   100,   111,    23,   163,    39,   175,
      29,    15,   124,    14,   222,   178,    30,    31,   223,   158,
     120,   138,   146,   147,    14,   156,   123,   168,     9,    94,
     228,     7,   106,   239,    41,     8,    94,    99,   223,   158,
      24,   183,     9,   131,   132,   133,   134,   135,   229,    95,
      42,   142,   143,   188,   158,   159,    26,    40,    95,   114,
       2,     3,     4,     5,     2,     3,     4,     5,   148,   149,
     182,   157,   111,    45,   246,   186,    87,   165,   231,   124,
     163,   115,     9,   177,     6,   179,   180,   181,     6,   136,
     193,   197,   198,   199,   166,   116,   167,     7,   194,   196,
      95,     8,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     216,   172,   187,   117,    32,   173,   215,   248,   106,   107,
     118,     1,     2,     3,     4,     5,     2,     3,     4,     5,
     121,   235,   139,     2,     3,     4,     5,   140,   141,   249,
     122,   252,   106,   184,    39,   152,     6,   158,   230,    22,
       6,   167,   158,    37,    99,    38,     7,     6,     7,   260,
       8,    99,     8,   154,   186,   218,   165,     9,   262,     9,
     263,     9,   243,   187,   144,   145,    99,    35,   106,   107,
     111,   244,     2,     3,     4,     5,   127,    44,   153,   255,
     251,     7,   106,   256,    96,   164,   128,   165,   129,    46,
     130,    47,    48,   113,    49,    50,     6,    51,    52,   232,
     238,   233,   158,   158,    99,   158,    53,    54,    55,    56,
      57,     2,     3,     4,     5,   155,    58,    59,    60,    61,
      62,    63,     2,     3,     4,     5,     1,     2,     3,     4,
       5,    64,    32,    65,   234,    43,   236,   170,   158,    46,
     237,    47,    48,   171,    49,    50,     6,    51,    52,   150,
     151,     6,     2,     3,     4,     5,    53,    54,    55,    56,
      57,     7,   224,   190,   225,     8,    58,    59,    60,    61,
      62,    63,     9,     7,   261,   174,     6,   164,   158,   165,
     253,    64,    32,   160,     9,   189,   -92,     2,     3,     4,
       5,   204,   205,   206,   207,   -84,   186,   195,   165,   200,
     201,   208,   209,     2,     3,     4,     5,   202,   203,   227,
      43,   -84,    32,   240,   242,   241,   254,   257,   258,   259,
      25,   104,    54,    55,    56,    57,   210,     6,   211,   214,
     212,    58,    59,    60,    61,    62,    63,     7,   213,   109,
     226,   164,   218,   165,    46,   161,    47,    48,     9,    49,
      50,   185,    51,    52,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,     2,     3,     4,     5,
       0,    58,    59,    60,    61,    62,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    32,   162,    46,
       6,    47,    48,     0,    49,    50,     0,    51,    52,     0,
      97,     0,     0,     0,     0,    98,    53,    54,    55,    56,
      57,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    64,    32,   217,    46,     0,    47,    48,     0,    49,
      50,     0,    51,    52,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,    58,    59,    60,    61,    62,    63,     0,   104,    54,
      55,    56,    57,     0,     0,     0,    64,    32,    58,    59,
      60,    61,    62,    63,     0,     0,   104,    54,    55,    56,
      57,     0,     0,     0,   110,   247,    58,    59,    60,    61,
      62,    63,     0,   104,    54,    55,    56,    57,     0,     0,
       0,     0,   110,    58,    59,    60,    61,    62,    63,   104,
      54,    55,    56,    57,     0,     0,     0,     0,   119,    58,
      59,    60,    61,    62,    63,   104,    54,    55,    56,    57,
       0,     0,   105,     0,    64,    58,    59,    60,    61,    62,
      63,   104,    54,    55,    56,    57,   191,     0,     0,     0,
       0,    58,    59,    60,    61,    62,    63,   104,    54,    55,
      56,    57,     0,     0,   221,     0,     0,    58,    59,    60,
      61,    62,    63,   104,    54,    55,    56,    57,     0,     0,
     245,     0,     0,    58,    59,    60,    61,    62,    63,   104,
      54,    55,    56,    57,   250,     0,     0,     0,     0,    58,
      59,    60,    61,    62,    63,   104,    54,    55,    56,    57,
       0,     0,     0,     0,     0,    58,    59,    60,    61,    62,
      63
};

static const yytype_int16 yycheck[] =
{
       0,    38,    38,     8,    37,    43,     9,    88,    21,   110,
      15,    11,    57,     0,   165,   115,    16,    17,   167,    49,
      51,    69,    12,    13,    11,    16,    57,    99,    51,    34,
      49,    40,    69,    63,    49,    44,    41,    37,   187,    49,
       0,   122,    51,    18,    19,    20,    21,    22,    67,    36,
      65,    52,    53,   125,    49,    65,    65,    45,    45,    44,
       6,     7,     8,     9,     6,     7,     8,     9,    58,    59,
      65,    62,   110,    29,   225,    44,    32,    46,   178,   124,
     161,    44,    51,   114,    30,   116,   117,   118,    30,    64,
     128,   139,   140,   141,    99,    44,    99,    40,   129,   137,
      87,    44,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     158,    45,   125,    44,    66,    49,   157,   228,   165,   165,
      44,     5,     6,     7,     8,     9,     6,     7,     8,     9,
      65,   189,    51,     6,     7,     8,     9,    56,    57,   230,
      63,   232,   189,    45,   167,    50,    30,    49,    45,   164,
      30,   164,    49,    44,   164,    46,    40,    30,    40,   250,
      44,   171,    44,    61,    44,    45,    46,    51,   259,    51,
     261,    51,    45,   186,    38,    39,   186,    19,   225,   225,
     228,   224,     6,     7,     8,     9,    34,    29,    60,   237,
     231,    40,   239,   239,    36,    44,    44,    46,    46,    23,
      48,    25,    26,    45,    28,    29,    30,    31,    32,    45,
      47,    45,    49,    49,   224,    49,    40,    41,    42,    43,
      44,     6,     7,     8,     9,    17,    50,    51,    52,    53,
      54,    55,     6,     7,     8,     9,     5,     6,     7,     8,
       9,    65,    66,    67,    45,    64,    45,    45,    49,    23,
      49,    25,    26,    49,    28,    29,    30,    31,    32,    14,
      15,    30,     6,     7,     8,     9,    40,    41,    42,    43,
      44,    40,    44,    40,    46,    44,    50,    51,    52,    53,
      54,    55,    51,    40,    45,    47,    30,    44,    49,    46,
      65,    65,    66,    67,    51,    45,    65,     6,     7,     8,
       9,   146,   147,   148,   149,    49,    44,    40,    46,   142,
     143,   150,   151,     6,     7,     8,     9,   144,   145,    40,
      64,    65,    66,    45,    47,    45,    65,    45,    47,    24,
      11,    40,    41,    42,    43,    44,   152,    30,   153,   156,
     154,    50,    51,    52,    53,    54,    55,    40,   155,    41,
     171,    44,    45,    46,    23,    87,    25,    26,    51,    28,
      29,   124,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    44,     6,     7,     8,     9,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    23,
      30,    25,    26,    -1,    28,    29,    -1,    31,    32,    -1,
      40,    -1,    -1,    -1,    -1,    45,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    23,    -1,    25,    26,    -1,    28,
      29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    -1,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    65,    66,    50,    51,
      52,    53,    54,    55,    -1,    -1,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    66,    67,    50,    51,    52,    53,
      54,    55,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    66,    50,    51,    52,    53,    54,    55,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    65,    50,
      51,    52,    53,    54,    55,    40,    41,    42,    43,    44,
      -1,    -1,    47,    -1,    65,    50,    51,    52,    53,    54,
      55,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    40,    41,    42,
      43,    44,    -1,    -1,    47,    -1,    -1,    50,    51,    52,
      53,    54,    55,    40,    41,    42,    43,    44,    -1,    -1,
      47,    -1,    -1,    50,    51,    52,    53,    54,    55,    40,
      41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    30,    40,    44,    51,
      69,    70,    71,    72,    94,    95,    98,    99,   100,   102,
     103,   104,   102,   104,     0,    71,    65,    96,    97,   102,
      95,    95,    66,    94,    95,   116,   117,    44,    46,   103,
      45,    49,    65,    64,   116,   117,    23,    25,    26,    28,
      29,    31,    32,    40,    41,    42,    43,    44,    50,    51,
      52,    53,    54,    55,    65,    67,    73,    74,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    92,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   102,    94,   116,    40,    45,    95,
     105,   106,   107,   108,    40,    47,    76,    89,    93,    97,
      66,    90,   112,   116,    44,    44,    44,    44,    44,    65,
      92,    65,    63,    92,    99,   101,   109,    34,    44,    46,
      48,    18,    19,    20,    21,    22,    64,    91,    78,    51,
      56,    57,    52,    53,    38,    39,    12,    13,    58,    59,
      14,    15,    50,    60,    61,    17,    16,    62,    49,    65,
      67,   118,    67,   114,    44,    46,   102,   104,   110,   111,
      45,    49,    45,    49,    47,   112,   113,    92,   119,    92,
      92,    92,    65,   114,    45,   101,    44,   104,   110,    45,
      40,    45,    75,    90,    92,    40,    90,    78,    78,    78,
      79,    79,    80,    80,    81,    81,    81,    81,    82,    82,
      83,    84,    85,    86,    87,    92,    90,    67,    45,   105,
     110,    47,    93,   111,    44,    46,   107,    40,    49,    67,
      45,   119,    45,    45,    45,    78,    45,    49,    47,    63,
      45,    45,    47,    45,   105,    47,    93,    67,   112,   114,
      45,    92,   114,    65,    65,    90,    89,    45,    47,    24,
     114,    45,   114,   114
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    70,    70,    71,    71,    71,    72,    72,
      72,    72,    73,    73,    73,    73,    73,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    79,    79,    80,
      80,    80,    81,    81,    81,    82,    82,    82,    82,    82,
      83,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    91,
      91,    91,    91,    92,    92,    93,    94,    94,    95,    95,
      95,    95,    96,    96,    97,    97,    98,    99,    99,    99,
      99,    99,   100,   101,   101,   102,   102,   103,   103,   103,
     103,   103,   103,   103,   104,   104,   105,   106,   106,   107,
     107,   107,   108,   108,   109,   109,   110,   110,   110,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   112,   112,
     112,   113,   113,   114,   114,   114,   114,   114,   114,   114,
     115,   116,   116,   116,   116,   117,   117,   118,   118,   119,
     119,   120,   120,   121,   121,   121,   122,   122,   122,   123,
     123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     4,     3,
       3,     2,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     1,     3,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     0,     2,     1,     2,     1,     1,     3,     4,
       3,     4,     4,     3,     1,     2,     1,     1,     3,     2,
       2,     1,     1,     3,     1,     2,     1,     1,     2,     3,
       2,     3,     3,     4,     2,     3,     3,     4,     1,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     4,     1,     2,     1,     2,     1,
       2,     5,     7,     5,     6,     7,     2,     2,     3,     5,
       5
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

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
# undef YYSTACK_RELOCATE
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
  case 5:
#line 100 "compiler.y"
                       { dump_symbol(); }
#line 1725 "y.tab.c"
    break;

  case 7:
#line 102 "compiler.y"
              {}
#line 1731 "y.tab.c"
    break;

  case 12:
#line 113 "compiler.y"
                { printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_val), ++addr); }
#line 1737 "y.tab.c"
    break;

  case 13:
#line 114 "compiler.y"
              { printf("INT_LIT %d\n", (yyvsp[0].i_val)); strcpy(type, "i32");}
#line 1743 "y.tab.c"
    break;

  case 14:
#line 115 "compiler.y"
                     { printf("STRING_LIT %s\n", (yyvsp[0].s_val)); strcpy(type, "str"); }
#line 1749 "y.tab.c"
    break;

  case 15:
#line 116 "compiler.y"
                { printf("FLOAT_LIT %f\n", (yyvsp[0].f_val)); strcpy(type, "f32"); }
#line 1755 "y.tab.c"
    break;

  case 86:
#line 262 "compiler.y"
           { printf("func: "); strcpy(type, "func"); }
#line 1761 "y.tab.c"
    break;

  case 97:
#line 287 "compiler.y"
                { printf("%s\n", (yyvsp[0].s_val));
            if(strcmp(type, "func") == 0){
                insert_symbol((yyvsp[0].s_val), -1);
                create_symbol();
            }
    }
#line 1772 "y.tab.c"
    break;

  case 159:
#line 414 "compiler.y"
                                   { printf("PRINT %s\n", type); }
#line 1778 "y.tab.c"
    break;

  case 160:
#line 415 "compiler.y"
                                     { printf("PRINTLN %s\n", type); }
#line 1784 "y.tab.c"
    break;


#line 1788 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yystos[+*yyssp], yyvsp);
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
#line 418 "compiler.y"


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    create_symbol();
    yylineno = 0;
    yyparse();
    dump_symbol();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol() {
    printf("> Create symbol table (scope level %d)\n", ++scope_level);
    stack[scope_level].size = 0;
}
static void insert_symbol(char *str, int addr) {
    printf("> Insert `%s` (addr: %d) to scope level %d\n", str, addr, scope_level);
    int cur_size = stack[scope_level].size;
    strcpy(stack[scope_level].name[cur_size], str);
    stack[scope_level].mut[cur_size] = strcmp(type, "func") ? 0 : -1;  
    strcpy(stack[scope_level].type[cur_size], type);
    stack[scope_level].addr[cur_size] = strcmp(type, "func") ? addr++ : -1;  
    stack[scope_level].lineno[cur_size] = yylineno+1;
    strcpy(stack[scope_level].func_sig[cur_size], strcmp(type, "func") ? "-" : "(V)V" );
    stack[scope_level].size++;
}

static void lookup_symbol() {
}

static void dump_symbol() {
    printf("\n> Dump symbol table (scope level: %d)\n", scope_level);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
        "Index", "Name", "Mut","Type", "Addr", "Lineno", "Func_sig");
    for(int i = 0;i<stack[scope_level].size;i++){
        printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
                i, stack[scope_level].name[i], stack[scope_level].mut[i], stack[scope_level].type[i], stack[scope_level].addr[i], stack[scope_level].lineno[i], stack[scope_level].func_sig[i]); 
    }
    scope_level--;
}
