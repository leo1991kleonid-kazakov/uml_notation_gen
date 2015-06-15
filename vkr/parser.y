
%{
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

%}

%define parse.error verbose

%union{
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
}

%token <string> T_IDENTIFIER T_TYPENAME
%token <token> T_LBRACE T_RBRACE T_LPAREN T_RPAREN T_LT T_GT
%token <token> T_COMMA T_SEMICOLON T_EQUALS T_COLON T_ARROW T_BIGARROW
%token <token> T_MODEL T_CLASS T_INTERFACE T_PROCEDURE T_FUNCTION T_TYPE T_BUILTIN
%token <token> T_CONSTRUCTOR T_DESTRUCTOR T_STATIC T_THROW
%token <token> T_USE T_OPTION
%token <token> T_IN T_OUT T_INOUT T_PLUS T_MINUS T_HASH

%type <model> N_Model
%type <model_member_list> N_ModelMemberList
%type <model_member> N_ModelMember
%type <model_option> N_ModelOption
%type <model_import> N_ModelImport
%type <model_type> N_Type
%type <string> N_TypeName
%type <model_interface> N_Interface
%type <model_class> N_Class
%type <string_list> N_AncestorInterfaceList N_AncestorClassList N_IdentifierList
%type <model_class_member_list> N_InterfaceMemberList N_ClassMemberList
%type <model_class_member> N_InterfaceMember N_ClassMember
%type <model_method> N_Method
%type <model_field> N_Field
%type <model_visibility> N_Visibility
%type <model_method_type> N_MethodType
%type <model_method_is_static> N_Linkage
%type <model_stereotype> N_Stereotype
%type <model_exception_list> N_Throws N_ExceptionList
%type <model_param_list> N_ParamList N_NonEmptyParamList
%type <model_param> N_Param
%type <model_param_direction> N_Direction

%start N_Model

%%

N_Model					:	T_MODEL T_IDENTIFIER T_LBRACE N_ModelMemberList T_RBRACE {
								$$ = new N_Model(*$2);
								for (auto i : *$4) {
									N_ModelOption *opt = dynamic_cast<N_ModelOption*>(i);
									if (opt != nullptr) {
										$$->addOption(*opt);
									} else {
										$$->addMember(i);
									}
								}
								model = $$;
							};

N_ModelMemberList		:	N_ModelMemberList N_ModelMember {
								$$ = $1;
								if ($2) {
									$$->push_back($2);
								}
							}
						|	{
								$$ = new std::vector<N_ModelMember*>();
							};

N_ModelMember			:	N_ModelImport { $$ = nullptr; /* TODO: implement import */ }
						|	N_ModelOption { $$ = $1; }
						|	N_Type { $$ = $1; }
						|	N_Interface { $$ = $1; }
						|	N_Class { $$ = $1; };

N_ModelImport			:	T_USE T_IDENTIFIER T_SEMICOLON { LOG << "Model import is not supported in this version.\n"; };

N_ModelOption			:	T_OPTION T_IDENTIFIER T_EQUALS T_IDENTIFIER T_SEMICOLON {
								$$ = new N_ModelOption(*$2, *$4);
							}
						|	T_OPTION T_IDENTIFIER T_SEMICOLON {
								$$ = new N_ModelOption(*$2, "1");
							};

N_Type					:	T_TYPE T_IDENTIFIER T_ARROW N_TypeName T_SEMICOLON {
								$$ = new N_Type(*$2, *$4);
							}
						|	T_TYPE T_IDENTIFIER T_BUILTIN T_SEMICOLON {
								$$ = new N_Type(*$2);
							};

N_Interface				:	T_INTERFACE T_IDENTIFIER N_AncestorInterfaceList T_LBRACE N_InterfaceMemberList T_RBRACE {
								$$ = new N_Interface(*$2);
								for (int i=0; i<$3->size(); i++) {
									N_Interface intf((*$3)[i]);
									$$->addAncestorInterface(intf);
								}
								for (int i=0; i<$5->size(); i++) {
									N_Method *m = dynamic_cast<N_Method*>((*$5)[i]);
									if (m)
										$$->addMethod(m);
								}
							};

N_Class					:	T_CLASS T_IDENTIFIER N_AncestorClassList N_AncestorInterfaceList T_LBRACE N_ClassMemberList T_RBRACE {
								$$ = new N_Class(*$2);
								for (int i=0; i<$3->size(); i++) {
									N_Class cl((*$3)[i]);
									$$->addAncestorClass(cl);
								}
								for (int i=0; i<$4->size(); i++) {
									N_Interface intf((*$4)[i]);
									$$->addAncestorInterface(intf);
								}
								for (int i=0; i<$6->size(); i++) {
									N_Method *m = dynamic_cast<N_Method*>((*$6)[i]);
									if (m)
										$$->addMethod(m);
									N_Field *f = dynamic_cast<N_Field*>((*$6)[i]);
									if (f)
										$$->addField(*f);
								}
							};
							
N_AncestorInterfaceList	:	T_ARROW N_IdentifierList {
								$$ = $2;
							}
						|	{
								$$ = new std::vector<std::string>();
							};

N_AncestorClassList		:	T_BIGARROW N_IdentifierList {
								$$ = $2;
							}
						|	{
								$$ = new std::vector<std::string>();
							};
							
N_IdentifierList		:	N_IdentifierList T_COMMA T_IDENTIFIER {
								$$ = $1;
								$$->push_back(*$3);
							}
						|	T_IDENTIFIER {
								$$ = new std::vector<std::string>();
								$$->push_back(*$1);
							};

N_InterfaceMemberList	:	N_InterfaceMemberList N_InterfaceMember {
								$$ = $1;
								$$->push_back($2);
							}
						|	{
								$$ = new std::vector<N_ClassMember*>();
							};

N_ClassMemberList		:	N_ClassMemberList N_ClassMember {
								$$ = $1;
								$$->push_back($2);
							}
						|	{
								$$ = new std::vector<N_ClassMember*>();
							};

N_InterfaceMember		:	N_Method {
								$$ = $1;
							};

N_ClassMember			:	N_Field {
								$$ = $1;
							}
						|	N_Method {
								$$ = $1;
							};

N_Field					:	N_Visibility T_IDENTIFIER T_COLON N_TypeName T_SEMICOLON {
								$$ = new N_Field(*$2, *$4, $1);
							};

N_Method				:	N_Visibility T_IDENTIFIER T_LPAREN N_ParamList T_RPAREN N_MethodType N_Throws T_SEMICOLON {
								switch($6.method_type) {
								case MT_FUNCTION:
									$$ = new N_Method(*$2, *$6.return_type, $1);
									break;
								case MT_PROCEDURE:
									$$ = new N_Method(*$2, *$6.return_type, $1);
									break;
								case MT_CONSTRUCTOR:
									std::cout << "constructor " << *$2 << "\n";
									$$ = new N_Constructor(*$2, $1);
									break;
								case MT_DESTRUCTOR:
									std::cout << "destructor " << *$2 << "\n";
									$$ = new N_Destructor(*$2, $1);
									break;
								case MT_STATIC_FUNCTION:
									$$ = new N_Method(*$2, *$6.return_type, $1);
									$$->setStatic(true);
									break;
								case MT_STATIC_PROCEDURE:
									$$ = new N_Method(*$2, *$6.return_type, $1);
									$$->setStatic(true);
									break;
								default:
									$$ = nullptr;
									yyerror("wrong method type");
								}
								for (auto e: *$7) {
									$$->addException(*e);
								}
								for (auto p: *$4) {
									$$->addParam(*p);
								}
								
							};

N_MethodType			:	T_COLON N_TypeName N_Linkage {
								$$.return_type = $2;
								$$.method_type = $3?MT_STATIC_FUNCTION:MT_FUNCTION;
							}
						|	T_LT T_LT N_Stereotype T_GT T_GT {
								$$.return_type = new std::string("void");
								if ($3 == ST_CONSTRUCTOR)
									$$.method_type = MT_CONSTRUCTOR;
								else
									$$.method_type = MT_DESTRUCTOR;
							}
						|	N_Linkage {
								$$.return_type = new std::string("");
								$$.method_type = $1?MT_STATIC_PROCEDURE:MT_PROCEDURE;
							};

N_Linkage				:	T_STATIC {
								$$ = true;
							}
						|	{
								$$ = false;
							};

N_ParamList				:	N_NonEmptyParamList {
								$$ = $1;
							}
						|	{
								$$ = new std::vector<N_Param*>();
							};

N_NonEmptyParamList		:	N_NonEmptyParamList T_COMMA N_Param {
								$$ = $1;
								$$->push_back($3);
							}
						|	N_Param {
								$$ = new std::vector<N_Param*>();
								$$->push_back($1);
							};

N_Param					:	T_IDENTIFIER T_COLON N_TypeName N_Direction {
								$$ = new N_Param(*$1, *$3, $4);
							};

N_Direction				:	T_IN {
								$$ = FD_IN;
							}
						|	T_OUT {
								$$ = FD_OUT;
							}
						|	T_INOUT {
								$$ = FD_INOUT;
							}
						|	{
								$$ = FD_IN;
							};

N_Stereotype			:	T_CONSTRUCTOR {
								$$ = ST_CONSTRUCTOR;
							}
						|	T_DESTRUCTOR {
								$$ = ST_DESTRUCTOR;
							};

N_Throws				:	T_THROW N_ExceptionList {
								$$ = $2;
							}
						|	{
								$$ = new std::vector<N_Exception*>();
							};

N_ExceptionList			:	N_ExceptionList T_COMMA T_IDENTIFIER {
								$$ = $1;
								$$->push_back(new N_Exception(*$3));
							}
						|	T_IDENTIFIER {
								$$ = new std::vector<N_Exception*>();
								$$->push_back(new N_Exception(*$1));
							};
						
N_Visibility			:	T_PLUS {
								$$ = MV_PUBLIC;
							}
						|	T_MINUS {
								$$ = MV_PRIVATE;
							}
						|	T_HASH {
								$$ = MV_PROTECTED;
							};
N_TypeName				:	T_TYPENAME {
								$$ = $1;
							}
						|	T_IDENTIFIER {
								$$ = $1;
							}
						
%%

