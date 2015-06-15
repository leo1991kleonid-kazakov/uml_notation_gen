#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include "ast.h"
#include "parser.hpp"
#include "util.h"
#include <getopt.h>

extern void yyparse();

extern N_Model *model;

void show_help(const char *bin_name)
{
	std::cout << "Usage:\n"
			  << "\t" << bin_name << " -h\n"
			  << "\t" << bin_name << " [-q] [-l <language>] < <infile>\n"
			  << " -h            - display this help\n"
			  << " -q            - quiet operation\n"
			  << " -l <language> - override output language\n"
			  << "                     cpp       - C++\n"
			  << "                     java      - Java\n"
			  << "                     pascal    - Pascal (FreePascal / TurboPascal variant)\n"
			  << "                     objpascal - ObjectPascal (FreePascal {$mode objfpc} / Delphi variant)\n";
	exit(0);
}

int main(int argc, char ** argv)
{
	bool lflag = false;
	bool qflag = false;
	int c;

	const char *lang_str = "<undefined>";

	opterr = 0;

	while ((c = getopt(argc, argv, "hql:")) != -1) {
		switch(c) {
		case 'h':
			show_help(argv[0]);
			break;
		case 'q':
			qflag = true;
			quiet = true;
			break;
		case 'l':
			lflag = true;
			lang_str = strdup(optarg);
			break;
		case '?':
			if (optopt == 'l') {
				std::cerr << "Option -l requires an argument.\n";
				exit(1);
			} else if (isprint (optopt)) {
				std::cerr << "Unknown option '-" << char(optopt) << "'.\n";
				exit(1);
			}
			else {
				std::cerr << "Unknown option character '\\x" << std::setbase(16) << optopt << "'.\n";
				exit(1);
			}
			break;
		default:
			break;
		}

	}

	yyparse();

	int optionCount = model->getOptionCount();
	for (int i=0; i<optionCount; i++) {
		if (model->getOption(i).getName().compare("lang") == 0)
			if (!lflag)
				lang_str = model->getOption(i).getValue().c_str();
		if (model->getOption(i).getName().compare("quiet") == 0)
			quiet = true;
	}

	Language lang;
	if (strcmp(lang_str, "cpp")==0) {
		lang = L_CPP;
	} else if (strcmp(lang_str, "java")==0) {
		lang = L_JAVA;
	} else if (strcmp(lang_str, "pascal")==0) {
		lang = L_PASCAL;
	} else if (strcmp(lang_str, "objpascal")==0) {
		lang = L_OBJPASCAL;
	} else if (strcmp(lang_str, "<undefined>")==0) {
		std::cerr << "Please define a target language. Valid languages are: cpp, java, pascal, objpascal\n";
		exit(2);
	} else {
		std::cerr << "Target language '" << lang_str << "' is not supported.\n";
		exit(1);
	}
	LOG << "Target language: " << lang_str << "\n";
	Generator *gen = Generator::create(lang, std::cout);
	gen->generate(*model);

	return 0;
}
