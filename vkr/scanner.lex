%{
#include <iostream>
#include <string>
#include "ast.h"
#include "parser.hpp"
#define SAVE_TOKEN yylval.string=new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
extern "C" int yywrap(){
return 1;
}
%}
%%
[ \t\n] ;
"(" return TOKEN(T_LPAREN);
")" return TOKEN(T_RPAREN);
"{" return TOKEN(T_LBRACE);
"}" return TOKEN(T_RBRACE);
"<" return TOKEN(T_LT);
">" return TOKEN(T_GT);
"," return TOKEN(T_COMMA);
";" return TOKEN(T_SEMICOLON);
"+" return TOKEN(T_PLUS);
"-" return TOKEN(T_MINUS);
"#" return TOKEN(T_HASH);
"=" return TOKEN(T_EQUALS);
":" return TOKEN(T_COLON);
"->" return TOKEN(T_ARROW);
"=>" return TOKEN(T_BIGARROW);
"model" return TOKEN(T_MODEL);
"class" return TOKEN(T_CLASS);
"interface" return TOKEN(T_INTERFACE);
"procedure" return TOKEN(T_PROCEDURE);
"function" return TOKEN(T_FUNCTION);
"type" return TOKEN(T_TYPE);
"builtin" return TOKEN(T_BUILTIN);
"constructor" return TOKEN(T_CONSTRUCTOR);
"destructor" return TOKEN(T_DESTRUCTOR);
"static" return TOKEN(T_STATIC);
"throw" return TOKEN(T_THROW);
"use" return TOKEN(T_USE);
"option" return TOKEN(T_OPTION);
"in" return TOKEN(T_IN);
"out" return TOKEN(T_OUT);
"inout" return TOKEN(T_INOUT);
[a-zA-Z_][a-zA-Z0-9_]* SAVE_TOKEN; return T_IDENTIFIER;
(([a-zA-Z_][a-zA-Z0-9_]*)?::)?[a-zA-Z_][a-zA-Z0-9_]*(\[\])? SAVE_TOKEN; return T_TYPENAME;
. std::cerr<<"bad token!\n"; yyterminate();
%%