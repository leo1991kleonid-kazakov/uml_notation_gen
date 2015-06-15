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
#line 2 "parser.y" /* yacc.c:339  */

#include "util.h"
#include "ast.h"
#include "parser.hpp"
#include <map>
#include <exception>

extern int yylex();
N_Model *model = nullptr;

void yyerror(const char *s)
{
	std::cerr<<"error:"<<s<<"\n";
}


#line 83 "parser.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    T_IDENTIFIER = 258,
    T_TYPENAME = 259,
    T_LBRACE = 260,
    T_RBRACE = 261,
    T_LPAREN = 262,
    T_RPAREN = 263,
    T_LT = 264,
    T_GT = 265,
    T_COMMA = 266,
    T_SEMICOLON = 267,
    T_EQUALS = 268,
    T_COLON = 269,
    T_ARROW = 270,
    T_BIGARROW = 271,
    T_MODEL = 272,
    T_CLASS = 273,
    T_INTERFACE = 274,
    T_PROCEDURE = 275,
    T_FUNCTION = 276,
    T_TYPE = 277,
    T_BUILTIN = 278,
    T_CONSTRUCTOR = 279,
    T_DESTRUCTOR = 280,
    T_STATIC = 281,
    T_THROW = 282,
    T_USE = 283,
    T_OPTION = 284,
    T_IN = 285,
    T_OUT = 286,
    T_INOUT = 287,
    T_PLUS = 288,
    T_MINUS = 289,
    T_HASH = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "parser.y" /* yacc.c:355  */

	std::string *string;
	int token;
	int value;
	N_Model *model;
	std::vector<N_ModelMember*> *model_member_list;
	N_ModelMember *model_member;
	N_ModelOption *model_option;
	int model_import; // зарезервировано для будущих версий
	N_Type *model_type;
	N_Interface *model_interface;
	N_Class *model_class;
	std::vector<std::string> *string_list;
	N_ClassMember *model_class_member;
	std::vector<N_ClassMember*> *model_class_member_list;
	N_Method *model_method;
	N_Field *model_field;
	MemberVisibility model_visibility;
	MethodTypeInfo model_method_type;
	bool model_method_is_static;
	Stereotype model_stereotype;
	std::vector<N_Exception*> *model_exception_list;
	N_Exception *model_exception;
	N_Param *model_param;
	std::vector<N_Param*> *model_param_list;
	ParamDirection model_param_direction;

#line 187 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  101

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    97,   103,   107,   108,   109,   110,   111,
     113,   115,   118,   122,   125,   129,   142,   162,   165,   169,
     172,   176,   180,   185,   189,   193,   197,   201,   205,   208,
     212,   216,   253,   257,   264,   269,   272,   276,   279,   283,
     287,   292,   296,   299,   302,   305,   309,   312,   316,   319,
     323,   327,   332,   335,   338,   341,   344
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_IDENTIFIER", "T_TYPENAME", "T_LBRACE",
  "T_RBRACE", "T_LPAREN", "T_RPAREN", "T_LT", "T_GT", "T_COMMA",
  "T_SEMICOLON", "T_EQUALS", "T_COLON", "T_ARROW", "T_BIGARROW", "T_MODEL",
  "T_CLASS", "T_INTERFACE", "T_PROCEDURE", "T_FUNCTION", "T_TYPE",
  "T_BUILTIN", "T_CONSTRUCTOR", "T_DESTRUCTOR", "T_STATIC", "T_THROW",
  "T_USE", "T_OPTION", "T_IN", "T_OUT", "T_INOUT", "T_PLUS", "T_MINUS",
  "T_HASH", "$accept", "N_Model", "N_ModelMemberList", "N_ModelMember",
  "N_ModelImport", "N_ModelOption", "N_Type", "N_Interface", "N_Class",
  "N_AncestorInterfaceList", "N_AncestorClassList", "N_IdentifierList",
  "N_InterfaceMemberList", "N_ClassMemberList", "N_InterfaceMember",
  "N_ClassMember", "N_Field", "N_Method", "N_MethodType", "N_Linkage",
  "N_ParamList", "N_NonEmptyParamList", "N_Param", "N_Direction",
  "N_Stereotype", "N_Throws", "N_ExceptionList", "N_Visibility",
  "N_TypeName", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290
};
# endif

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -11,     8,    15,    20,   -62,   -62,    -5,   -62,    34,    35,
      36,    37,    38,   -62,   -62,   -62,   -62,   -62,   -62,    26,
      28,     3,    32,    -4,    42,    28,    42,    41,    30,    39,
     -62,   -62,    44,   -62,    43,    45,    43,   -62,   -62,   -62,
      40,   -62,    46,    50,   -62,    -6,   -62,   -62,   -62,    -3,
     -62,   -62,   -62,   -62,   -62,   -62,    52,   -62,   -62,   -62,
     -62,    53,    54,    -2,    56,    30,    48,    49,    55,   -62,
      51,    30,    -7,    56,   -62,   -10,    58,    30,   -62,    21,
     -62,   -62,   -62,   -62,   -62,   -62,    11,    23,    57,    59,
     -62,   -62,    60,   -62,   -62,    61,   -62,    63,    62,   -62,
     -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,     0,     2,     0,     0,
       0,     0,     0,     3,     5,     6,     7,     8,     9,    20,
      18,     0,     0,     0,     0,    18,     0,     0,     0,     0,
      10,    12,     0,    22,    19,     0,    17,    24,    56,    55,
       0,    14,     0,     0,    26,     0,    13,    11,    21,     0,
      15,    52,    53,    54,    23,    27,     0,    16,    25,    28,
      29,     0,     0,     0,    38,     0,     0,     0,    37,    40,
       0,     0,    36,     0,    30,    45,     0,     0,    35,    49,
      34,    39,    42,    43,    44,    41,     0,    36,     0,     0,
      46,    47,     0,    32,    51,    48,    31,     0,     0,    33,
      50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,    64,
     -62,    65,   -62,   -62,   -62,   -62,   -62,    19,   -62,   -23,
     -62,   -62,     1,   -62,   -62,   -62,   -62,    27,   -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,    13,    14,    15,    16,    17,    18,    27,
      25,    34,    45,    49,    54,    58,    59,    55,    79,    80,
      67,    68,    69,    85,    92,    89,    95,    56,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      50,     7,    76,    57,    70,    64,     1,    77,    31,    32,
      75,     3,    65,     8,     9,     4,    87,    10,    28,    78,
      82,    83,    84,    11,    12,     5,    29,    51,    52,    53,
      51,    52,    53,    38,    39,    90,    91,    19,    20,    21,
      22,    23,    24,    26,    30,    33,    37,    42,    88,    78,
      44,    41,    46,    48,    43,    62,    63,    72,    47,    66,
      94,    64,    71,    74,    93,   100,    73,    86,    60,     0,
      97,    96,    98,    99,    81,     0,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,    36
};

static const yytype_int8 yycheck[] =
{
       6,     6,     9,     6,    65,     7,    17,    14,    12,    13,
      71,     3,    14,    18,    19,     0,    77,    22,    15,    26,
      30,    31,    32,    28,    29,     5,    23,    33,    34,    35,
      33,    34,    35,     3,     4,    24,    25,     3,     3,     3,
       3,     3,    16,    15,    12,     3,     5,     3,    27,    26,
       5,    12,    12,     3,    11,     3,     3,     8,    12,     3,
       3,     7,    14,    12,    87,     3,    11,     9,    49,    -1,
      10,    12,    11,    10,    73,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      -1,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    37,     3,     0,     5,    38,     6,    18,    19,
      22,    28,    29,    39,    40,    41,    42,    43,    44,     3,
       3,     3,     3,     3,    16,    46,    15,    45,    15,    23,
      12,    12,    13,     3,    47,    45,    47,     5,     3,     4,
      64,    12,     3,    11,     5,    48,    12,    12,     3,    49,
       6,    33,    34,    35,    50,    53,    63,     6,    51,    52,
      53,    63,     3,     3,     7,    14,     3,    56,    57,    58,
      64,    14,     8,    11,    12,    64,     9,    14,    26,    54,
      55,    58,    30,    31,    32,    59,     9,    64,    27,    61,
      24,    25,    60,    55,     3,    62,    12,    10,    11,    10,
       3
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    39,    39,
      40,    41,    41,    42,    42,    43,    44,    45,    45,    46,
      46,    47,    47,    48,    48,    49,    49,    50,    51,    51,
      52,    53,    54,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    59,    59,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    63,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     0,     1,     1,     1,     1,     1,
       3,     5,     3,     5,     4,     6,     7,     2,     0,     2,
       0,     3,     1,     2,     0,     2,     0,     1,     1,     1,
       5,     8,     3,     5,     1,     1,     0,     1,     0,     3,
       1,     4,     1,     1,     1,     0,     1,     1,     2,     0,
       3,     1,     1,     1,     1,     1,     1
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
#line 84 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model) = new N_Model(*(yyvsp[-3].string));
								for (auto i : *(yyvsp[-1].model_member_list)) {
									N_ModelOption *opt = dynamic_cast<N_ModelOption*>(i);
									if (opt != nullptr) {
										(yyval.model)->addOption(*opt);
									} else {
										(yyval.model)->addMember(i);
									}
								}
								model = (yyval.model);
							}
#line 1366 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 97 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_member_list) = (yyvsp[-1].model_member_list);
								if ((yyvsp[0].model_member)) {
									(yyval.model_member_list)->push_back((yyvsp[0].model_member));
								}
							}
#line 1377 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 103 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_member_list) = new std::vector<N_ModelMember*>();
							}
#line 1385 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval.model_member) = nullptr; /* TODO: implement import */ }
#line 1391 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "parser.y" /* yacc.c:1646  */
    { (yyval.model_member) = (yyvsp[0].model_option); }
#line 1397 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval.model_member) = (yyvsp[0].model_type); }
#line 1403 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.model_member) = (yyvsp[0].model_interface); }
#line 1409 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.model_member) = (yyvsp[0].model_class); }
#line 1415 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "parser.y" /* yacc.c:1646  */
    { LOG << "Model import is not supported in this version.\n"; }
#line 1421 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 115 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_option) = new N_ModelOption(*(yyvsp[-3].string), *(yyvsp[-1].string));
							}
#line 1429 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 118 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_option) = new N_ModelOption(*(yyvsp[-1].string), "1");
							}
#line 1437 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 122 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_type) = new N_Type(*(yyvsp[-3].string), *(yyvsp[-1].string));
							}
#line 1445 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 125 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_type) = new N_Type(*(yyvsp[-2].string));
							}
#line 1453 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 129 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_interface) = new N_Interface(*(yyvsp[-4].string));
								for (int i=0; i<(yyvsp[-3].string_list)->size(); i++) {
									N_Interface intf((*(yyvsp[-3].string_list))[i]);
									(yyval.model_interface)->addAncestorInterface(intf);
								}
								for (int i=0; i<(yyvsp[-1].model_class_member_list)->size(); i++) {
									N_Method *m = dynamic_cast<N_Method*>((*(yyvsp[-1].model_class_member_list))[i]);
									if (m)
										(yyval.model_interface)->addMethod(m);
								}
							}
#line 1470 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 142 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_class) = new N_Class(*(yyvsp[-5].string));
								for (int i=0; i<(yyvsp[-4].string_list)->size(); i++) {
									N_Class cl((*(yyvsp[-4].string_list))[i]);
									(yyval.model_class)->addAncestorClass(cl);
								}
								for (int i=0; i<(yyvsp[-3].string_list)->size(); i++) {
									N_Interface intf((*(yyvsp[-3].string_list))[i]);
									(yyval.model_class)->addAncestorInterface(intf);
								}
								for (int i=0; i<(yyvsp[-1].model_class_member_list)->size(); i++) {
									N_Method *m = dynamic_cast<N_Method*>((*(yyvsp[-1].model_class_member_list))[i]);
									if (m)
										(yyval.model_class)->addMethod(m);
									N_Field *f = dynamic_cast<N_Field*>((*(yyvsp[-1].model_class_member_list))[i]);
									if (f)
										(yyval.model_class)->addField(*f);
								}
							}
#line 1494 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 162 "parser.y" /* yacc.c:1646  */
    {
								(yyval.string_list) = (yyvsp[0].string_list);
							}
#line 1502 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 165 "parser.y" /* yacc.c:1646  */
    {
								(yyval.string_list) = new std::vector<std::string>();
							}
#line 1510 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 169 "parser.y" /* yacc.c:1646  */
    {
								(yyval.string_list) = (yyvsp[0].string_list);
							}
#line 1518 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 172 "parser.y" /* yacc.c:1646  */
    {
								(yyval.string_list) = new std::vector<std::string>();
							}
#line 1526 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 176 "parser.y" /* yacc.c:1646  */
    {
								(yyval.string_list) = (yyvsp[-2].string_list);
								(yyval.string_list)->push_back(*(yyvsp[0].string));
							}
#line 1535 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 180 "parser.y" /* yacc.c:1646  */
    {
								(yyval.string_list) = new std::vector<std::string>();
								(yyval.string_list)->push_back(*(yyvsp[0].string));
							}
#line 1544 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 185 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_class_member_list) = (yyvsp[-1].model_class_member_list);
								(yyval.model_class_member_list)->push_back((yyvsp[0].model_class_member));
							}
#line 1553 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 189 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_class_member_list) = new std::vector<N_ClassMember*>();
							}
#line 1561 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 193 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_class_member_list) = (yyvsp[-1].model_class_member_list);
								(yyval.model_class_member_list)->push_back((yyvsp[0].model_class_member));
							}
#line 1570 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 197 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_class_member_list) = new std::vector<N_ClassMember*>();
							}
#line 1578 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 201 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_class_member) = (yyvsp[0].model_method);
							}
#line 1586 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 205 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_class_member) = (yyvsp[0].model_field);
							}
#line 1594 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 208 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_class_member) = (yyvsp[0].model_method);
							}
#line 1602 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 212 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_field) = new N_Field(*(yyvsp[-3].string), *(yyvsp[-1].string), (yyvsp[-4].model_visibility));
							}
#line 1610 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 216 "parser.y" /* yacc.c:1646  */
    {
								switch((yyvsp[-2].model_method_type).method_type) {
								case MT_FUNCTION:
									(yyval.model_method) = new N_Method(*(yyvsp[-6].string), *(yyvsp[-2].model_method_type).return_type, (yyvsp[-7].model_visibility));
									break;
								case MT_PROCEDURE:
									(yyval.model_method) = new N_Method(*(yyvsp[-6].string), *(yyvsp[-2].model_method_type).return_type, (yyvsp[-7].model_visibility));
									break;
								case MT_CONSTRUCTOR:
									std::cout << "constructor " << *(yyvsp[-6].string) << "\n";
									(yyval.model_method) = new N_Constructor(*(yyvsp[-6].string), (yyvsp[-7].model_visibility));
									break;
								case MT_DESTRUCTOR:
									std::cout << "destructor " << *(yyvsp[-6].string) << "\n";
									(yyval.model_method) = new N_Destructor(*(yyvsp[-6].string), (yyvsp[-7].model_visibility));
									break;
								case MT_STATIC_FUNCTION:
									(yyval.model_method) = new N_Method(*(yyvsp[-6].string), *(yyvsp[-2].model_method_type).return_type, (yyvsp[-7].model_visibility));
									(yyval.model_method)->setStatic(true);
									break;
								case MT_STATIC_PROCEDURE:
									(yyval.model_method) = new N_Method(*(yyvsp[-6].string), *(yyvsp[-2].model_method_type).return_type, (yyvsp[-7].model_visibility));
									(yyval.model_method)->setStatic(true);
									break;
								default:
									(yyval.model_method) = nullptr;
									yyerror("wrong method type");
								}
								for (auto e: *(yyvsp[-1].model_exception_list)) {
									(yyval.model_method)->addException(*e);
								}
								for (auto p: *(yyvsp[-4].model_param_list)) {
									(yyval.model_method)->addParam(*p);
								}
								
							}
#line 1651 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 253 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_method_type).return_type = (yyvsp[-1].string);
								(yyval.model_method_type).method_type = (yyvsp[0].model_method_is_static)?MT_STATIC_FUNCTION:MT_FUNCTION;
							}
#line 1660 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 257 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_method_type).return_type = new std::string("void");
								if ((yyvsp[-2].model_stereotype) == ST_CONSTRUCTOR)
									(yyval.model_method_type).method_type = MT_CONSTRUCTOR;
								else
									(yyval.model_method_type).method_type = MT_DESTRUCTOR;
							}
#line 1672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 264 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_method_type).return_type = new std::string("");
								(yyval.model_method_type).method_type = (yyvsp[0].model_method_is_static)?MT_STATIC_PROCEDURE:MT_PROCEDURE;
							}
#line 1681 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 269 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_method_is_static) = true;
							}
#line 1689 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 272 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_method_is_static) = false;
							}
#line 1697 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 276 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_param_list) = (yyvsp[0].model_param_list);
							}
#line 1705 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 279 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_param_list) = new std::vector<N_Param*>();
							}
#line 1713 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 283 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_param_list) = (yyvsp[-2].model_param_list);
								(yyval.model_param_list)->push_back((yyvsp[0].model_param));
							}
#line 1722 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 287 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_param_list) = new std::vector<N_Param*>();
								(yyval.model_param_list)->push_back((yyvsp[0].model_param));
							}
#line 1731 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 292 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_param) = new N_Param(*(yyvsp[-3].string), *(yyvsp[-1].string), (yyvsp[0].model_param_direction));
							}
#line 1739 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 296 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_param_direction) = FD_IN;
							}
#line 1747 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 299 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_param_direction) = FD_OUT;
							}
#line 1755 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 302 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_param_direction) = FD_INOUT;
							}
#line 1763 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 305 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_param_direction) = FD_IN;
							}
#line 1771 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 309 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_stereotype) = ST_CONSTRUCTOR;
							}
#line 1779 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 312 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_stereotype) = ST_DESTRUCTOR;
							}
#line 1787 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 316 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_exception_list) = (yyvsp[0].model_exception_list);
							}
#line 1795 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 319 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_exception_list) = new std::vector<N_Exception*>();
							}
#line 1803 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 323 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_exception_list) = (yyvsp[-2].model_exception_list);
								(yyval.model_exception_list)->push_back(new N_Exception(*(yyvsp[0].string)));
							}
#line 1812 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 327 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_exception_list) = new std::vector<N_Exception*>();
								(yyval.model_exception_list)->push_back(new N_Exception(*(yyvsp[0].string)));
							}
#line 1821 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 332 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_visibility) = MV_PUBLIC;
							}
#line 1829 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 335 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_visibility) = MV_PRIVATE;
							}
#line 1837 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 338 "parser.y" /* yacc.c:1646  */
    {
								(yyval.model_visibility) = MV_PROTECTED;
							}
#line 1845 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 341 "parser.y" /* yacc.c:1646  */
    {
								(yyval.string) = (yyvsp[0].string);
							}
#line 1853 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 344 "parser.y" /* yacc.c:1646  */
    {
								(yyval.string) = (yyvsp[0].string);
							}
#line 1861 "parser.cpp" /* yacc.c:1646  */
    break;


#line 1865 "parser.cpp" /* yacc.c:1646  */
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
#line 348 "parser.y" /* yacc.c:1906  */


