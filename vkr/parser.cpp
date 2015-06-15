
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
#line 2 "parser.y"

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



/* Line 189 of yacc.c  */
#line 91 "parser.cpp"

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



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 21 "parser.y"

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



/* Line 214 of yacc.c  */
#line 192 "parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 204 "parser.cpp"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNRULES -- Number of states.  */
#define YYNSTATES  101

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

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
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    12,    13,    15,    17,    19,    21,
      23,    27,    33,    37,    43,    48,    55,    63,    66,    67,
      70,    71,    75,    77,    80,    81,    84,    85,    87,    89,
      91,    97,   106,   110,   116,   118,   120,   121,   123,   124,
     128,   130,   135,   137,   139,   141,   142,   144,   146,   149,
     150,   154,   156,   158,   160,   162,   164
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    17,     3,     5,    38,     6,    -1,    38,
      39,    -1,    -1,    40,    -1,    41,    -1,    42,    -1,    43,
      -1,    44,    -1,    28,     3,    12,    -1,    29,     3,    13,
       3,    12,    -1,    29,     3,    12,    -1,    22,     3,    15,
      64,    12,    -1,    22,     3,    23,    12,    -1,    19,     3,
      45,     5,    48,     6,    -1,    18,     3,    46,    45,     5,
      49,     6,    -1,    15,    47,    -1,    -1,    16,    47,    -1,
      -1,    47,    11,     3,    -1,     3,    -1,    48,    50,    -1,
      -1,    49,    51,    -1,    -1,    53,    -1,    52,    -1,    53,
      -1,    63,     3,    14,    64,    12,    -1,    63,     3,     7,
      56,     8,    54,    61,    12,    -1,    14,    64,    55,    -1,
       9,     9,    60,    10,    10,    -1,    55,    -1,    26,    -1,
      -1,    57,    -1,    -1,    57,    11,    58,    -1,    58,    -1,
       3,    14,    64,    59,    -1,    30,    -1,    31,    -1,    32,
      -1,    -1,    24,    -1,    25,    -1,    27,    62,    -1,    -1,
      62,    11,     3,    -1,     3,    -1,    33,    -1,    34,    -1,
      35,    -1,     4,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
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

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "N_TypeName", 0
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
     285,   286,   287,   288,   289,   290
};
# endif

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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     0,     1,     1,     1,     1,     1,
       3,     5,     3,     5,     4,     6,     7,     2,     0,     2,
       0,     3,     1,     2,     0,     2,     0,     1,     1,     1,
       5,     8,     3,     5,     1,     1,     0,     1,     0,     3,
       1,     4,     1,     1,     1,     0,     1,     1,     2,     0,
       3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
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

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,    13,    14,    15,    16,    17,    18,    27,
      25,    34,    45,    49,    54,    58,    59,    55,    79,    80,
      67,    68,    69,    85,    92,    89,    95,    56,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -62
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,    64,
     -62,    65,   -62,   -62,   -62,   -62,   -62,    19,   -62,   -23,
     -62,   -62,     1,   -62,   -62,   -62,   -62,    27,   -61
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
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
        case 2:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    {
								(yyval.model) = new N_Model(*(yyvsp[(2) - (5)].string));
								for (auto i : *(yyvsp[(4) - (5)].model_member_list)) {
									N_ModelOption *opt = dynamic_cast<N_ModelOption*>(i);
									if (opt != nullptr) {
										(yyval.model)->addOption(*opt);
									} else {
										(yyval.model)->addMember(i);
									}
								}
								model = (yyval.model);
							;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {
								(yyval.model_member_list) = (yyvsp[(1) - (2)].model_member_list);
								if ((yyvsp[(2) - (2)].model_member)) {
									(yyval.model_member_list)->push_back((yyvsp[(2) - (2)].model_member));
								}
							;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    {
								(yyval.model_member_list) = new std::vector<N_ModelMember*>();
							;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { (yyval.model_member) = nullptr; /* TODO: implement import */ ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    { (yyval.model_member) = (yyvsp[(1) - (1)].model_option); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    { (yyval.model_member) = (yyvsp[(1) - (1)].model_type); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    { (yyval.model_member) = (yyvsp[(1) - (1)].model_interface); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    { (yyval.model_member) = (yyvsp[(1) - (1)].model_class); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    { LOG << "Model import is not supported in this version.\n"; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {
								(yyval.model_option) = new N_ModelOption(*(yyvsp[(2) - (5)].string), *(yyvsp[(4) - (5)].string));
							;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    {
								(yyval.model_option) = new N_ModelOption(*(yyvsp[(2) - (3)].string), "1");
							;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    {
								(yyval.model_type) = new N_Type(*(yyvsp[(2) - (5)].string), *(yyvsp[(4) - (5)].string));
							;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {
								(yyval.model_type) = new N_Type(*(yyvsp[(2) - (4)].string));
							;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {
								(yyval.model_interface) = new N_Interface(*(yyvsp[(2) - (6)].string));
								for (int i=0; i<(yyvsp[(3) - (6)].string_list)->size(); i++) {
									N_Interface intf((*(yyvsp[(3) - (6)].string_list))[i]);
									(yyval.model_interface)->addAncestorInterface(intf);
								}
								for (int i=0; i<(yyvsp[(5) - (6)].model_class_member_list)->size(); i++) {
									N_Method *m = dynamic_cast<N_Method*>((*(yyvsp[(5) - (6)].model_class_member_list))[i]);
									if (m)
										(yyval.model_interface)->addMethod(m);
								}
							;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {
								(yyval.model_class) = new N_Class(*(yyvsp[(2) - (7)].string));
								for (int i=0; i<(yyvsp[(3) - (7)].string_list)->size(); i++) {
									N_Class cl((*(yyvsp[(3) - (7)].string_list))[i]);
									(yyval.model_class)->addAncestorClass(cl);
								}
								for (int i=0; i<(yyvsp[(4) - (7)].string_list)->size(); i++) {
									N_Interface intf((*(yyvsp[(4) - (7)].string_list))[i]);
									(yyval.model_class)->addAncestorInterface(intf);
								}
								for (int i=0; i<(yyvsp[(6) - (7)].model_class_member_list)->size(); i++) {
									N_Method *m = dynamic_cast<N_Method*>((*(yyvsp[(6) - (7)].model_class_member_list))[i]);
									if (m)
										(yyval.model_class)->addMethod(m);
									N_Field *f = dynamic_cast<N_Field*>((*(yyvsp[(6) - (7)].model_class_member_list))[i]);
									if (f)
										(yyval.model_class)->addField(*f);
								}
							;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {
								(yyval.string_list) = (yyvsp[(2) - (2)].string_list);
							;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {
								(yyval.string_list) = new std::vector<std::string>();
							;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {
								(yyval.string_list) = (yyvsp[(2) - (2)].string_list);
							;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    {
								(yyval.string_list) = new std::vector<std::string>();
							;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    {
								(yyval.string_list) = (yyvsp[(1) - (3)].string_list);
								(yyval.string_list)->push_back(*(yyvsp[(3) - (3)].string));
							;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {
								(yyval.string_list) = new std::vector<std::string>();
								(yyval.string_list)->push_back(*(yyvsp[(1) - (1)].string));
							;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    {
								(yyval.model_class_member_list) = (yyvsp[(1) - (2)].model_class_member_list);
								(yyval.model_class_member_list)->push_back((yyvsp[(2) - (2)].model_class_member));
							;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {
								(yyval.model_class_member_list) = new std::vector<N_ClassMember*>();
							;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    {
								(yyval.model_class_member_list) = (yyvsp[(1) - (2)].model_class_member_list);
								(yyval.model_class_member_list)->push_back((yyvsp[(2) - (2)].model_class_member));
							;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {
								(yyval.model_class_member_list) = new std::vector<N_ClassMember*>();
							;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {
								(yyval.model_class_member) = (yyvsp[(1) - (1)].model_method);
							;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    {
								(yyval.model_class_member) = (yyvsp[(1) - (1)].model_field);
							;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {
								(yyval.model_class_member) = (yyvsp[(1) - (1)].model_method);
							;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {
								(yyval.model_field) = new N_Field(*(yyvsp[(2) - (5)].string), *(yyvsp[(4) - (5)].string), (yyvsp[(1) - (5)].model_visibility));
							;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {
								switch((yyvsp[(6) - (8)].model_method_type).method_type) {
								case MT_FUNCTION:
									(yyval.model_method) = new N_Method(*(yyvsp[(2) - (8)].string), *(yyvsp[(6) - (8)].model_method_type).return_type, (yyvsp[(1) - (8)].model_visibility));
									break;
								case MT_PROCEDURE:
									(yyval.model_method) = new N_Method(*(yyvsp[(2) - (8)].string), *(yyvsp[(6) - (8)].model_method_type).return_type, (yyvsp[(1) - (8)].model_visibility));
									break;
								case MT_CONSTRUCTOR:
									std::cout << "constructor " << *(yyvsp[(2) - (8)].string) << "\n";
									(yyval.model_method) = new N_Constructor(*(yyvsp[(2) - (8)].string), (yyvsp[(1) - (8)].model_visibility));
									break;
								case MT_DESTRUCTOR:
									std::cout << "destructor " << *(yyvsp[(2) - (8)].string) << "\n";
									(yyval.model_method) = new N_Destructor(*(yyvsp[(2) - (8)].string), (yyvsp[(1) - (8)].model_visibility));
									break;
								case MT_STATIC_FUNCTION:
									(yyval.model_method) = new N_Method(*(yyvsp[(2) - (8)].string), *(yyvsp[(6) - (8)].model_method_type).return_type, (yyvsp[(1) - (8)].model_visibility));
									(yyval.model_method)->setStatic(true);
									break;
								case MT_STATIC_PROCEDURE:
									(yyval.model_method) = new N_Method(*(yyvsp[(2) - (8)].string), *(yyvsp[(6) - (8)].model_method_type).return_type, (yyvsp[(1) - (8)].model_visibility));
									(yyval.model_method)->setStatic(true);
									break;
								default:
									(yyval.model_method) = nullptr;
									yyerror("wrong method type");
								}
								for (auto e: *(yyvsp[(7) - (8)].model_exception_list)) {
									(yyval.model_method)->addException(*e);
								}
								for (auto p: *(yyvsp[(4) - (8)].model_param_list)) {
									(yyval.model_method)->addParam(*p);
								}
								
							;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 253 "parser.y"
    {
								(yyval.model_method_type).return_type = (yyvsp[(2) - (3)].string);
								(yyval.model_method_type).method_type = (yyvsp[(3) - (3)].model_method_is_static)?MT_STATIC_FUNCTION:MT_FUNCTION;
							;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    {
								(yyval.model_method_type).return_type = new std::string("void");
								if ((yyvsp[(3) - (5)].model_stereotype) == ST_CONSTRUCTOR)
									(yyval.model_method_type).method_type = MT_CONSTRUCTOR;
								else
									(yyval.model_method_type).method_type = MT_DESTRUCTOR;
							;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    {
								(yyval.model_method_type).return_type = new std::string("");
								(yyval.model_method_type).method_type = (yyvsp[(1) - (1)].model_method_is_static)?MT_STATIC_PROCEDURE:MT_PROCEDURE;
							;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    {
								(yyval.model_method_is_static) = true;
							;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    {
								(yyval.model_method_is_static) = false;
							;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    {
								(yyval.model_param_list) = (yyvsp[(1) - (1)].model_param_list);
							;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    {
								(yyval.model_param_list) = new std::vector<N_Param*>();
							;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 283 "parser.y"
    {
								(yyval.model_param_list) = (yyvsp[(1) - (3)].model_param_list);
								(yyval.model_param_list)->push_back((yyvsp[(3) - (3)].model_param));
							;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 287 "parser.y"
    {
								(yyval.model_param_list) = new std::vector<N_Param*>();
								(yyval.model_param_list)->push_back((yyvsp[(1) - (1)].model_param));
							;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 292 "parser.y"
    {
								(yyval.model_param) = new N_Param(*(yyvsp[(1) - (4)].string), *(yyvsp[(3) - (4)].string), (yyvsp[(4) - (4)].model_param_direction));
							;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 296 "parser.y"
    {
								(yyval.model_param_direction) = FD_IN;
							;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 299 "parser.y"
    {
								(yyval.model_param_direction) = FD_OUT;
							;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 302 "parser.y"
    {
								(yyval.model_param_direction) = FD_INOUT;
							;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    {
								(yyval.model_param_direction) = FD_IN;
							;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
    {
								(yyval.model_stereotype) = ST_CONSTRUCTOR;
							;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 312 "parser.y"
    {
								(yyval.model_stereotype) = ST_DESTRUCTOR;
							;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 316 "parser.y"
    {
								(yyval.model_exception_list) = (yyvsp[(2) - (2)].model_exception_list);
							;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 319 "parser.y"
    {
								(yyval.model_exception_list) = new std::vector<N_Exception*>();
							;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    {
								(yyval.model_exception_list) = (yyvsp[(1) - (3)].model_exception_list);
								(yyval.model_exception_list)->push_back(new N_Exception(*(yyvsp[(3) - (3)].string)));
							;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 327 "parser.y"
    {
								(yyval.model_exception_list) = new std::vector<N_Exception*>();
								(yyval.model_exception_list)->push_back(new N_Exception(*(yyvsp[(1) - (1)].string)));
							;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 332 "parser.y"
    {
								(yyval.model_visibility) = MV_PUBLIC;
							;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 335 "parser.y"
    {
								(yyval.model_visibility) = MV_PRIVATE;
							;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 338 "parser.y"
    {
								(yyval.model_visibility) = MV_PROTECTED;
							;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 341 "parser.y"
    {
								(yyval.string) = (yyvsp[(1) - (1)].string);
							;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 344 "parser.y"
    {
								(yyval.string) = (yyvsp[(1) - (1)].string);
							;}
    break;



/* Line 1455 of yacc.c  */
#line 2055 "parser.cpp"
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
#line 348 "parser.y"



