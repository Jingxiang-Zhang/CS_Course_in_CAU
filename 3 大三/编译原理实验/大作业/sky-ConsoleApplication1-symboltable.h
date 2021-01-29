#pragma once
#define SYMBOLTABLE 0
#include <fstream>
#include <vector>
#include <map>





namespace word {
	enum reserved {
		NULLWORD,	AND,		BREAK,		CONTINUE,	DEF,
		DEL,		ELIF,		ELSE,		FOR,		IF,
		IMPORT,		IN,			NOT,		OR,			PASS,
		RETURN,		WHILE
	};
	char reserved_content[][15] = {
		"",			"and",		"break",	"continue",	"def",
		"del",		"elif",		"else",		"for",		"if",
		"import",	"in",		"not",		"or",		"pass",
		"return",	"while"
	};
	enum punctuation {
		COMMA=20,	ASSIGN,		ADD_EQUAL,	MINUS_EQUAL,MULTI_EQUAL,
		DIV_EQUAL,	COLON,		LESS,		MORE,		EQUAL,
		LESS_EQUAL,	MORE_EQUAL,	ADD,		MINUS,		MULTI,		
		DIV,		REMAINDER,	DIV_CEIL,	PERIOD,		PAREN_L,
		PAREN_R,	BRACKET_L,	BRACKET_R,	LOGICAL_OR,	LOGICAL_AND
	};
	char punctuation_content[][5]{
		",",		"=",		"+=",		"-=",		"*=",
		"/=",		":",		"<",		">",		"==",
		">=",		"<=",		"+",		"-",		"*",
		"/",		"%",		"//",		".",		"(",
		")",		"[",		"]",		"|",		""
	};
	enum control {
		NEWLINE=50,	ENDMARKER,	INDENT,		DEDENT
		//INDENT表示tab，DEDENT表示退格
	};
	char control_content[]{
		'\n',		'\0',		'\t',		'\b'
	};

	enum type {
		NAME=60,	STRING,		NUMBER,		FLOAT
	};

	const int escape_character_table_length = 12;
	char escape_character_table[]{
		'a',	'\a',	'b',	'\b',	'f',	'\f',
		'n',	'\n',	'r',	'\r',	't',	'\t',
		'v',	'\v',	'\\',	'\\',	'\'',	'\'',
		'\"',	'\"',	'?',	'\?',	'0',	'\0',
	};
}







