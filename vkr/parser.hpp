/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 21 "parser.y" /* yacc.c:1909  */

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

#line 118 "parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
