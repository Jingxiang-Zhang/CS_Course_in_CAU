#define LEXER 0

#include <iostream>
#include <fstream>
#include <string>

#ifndef SYMBOLTABLE
#include "symboltable.h"
#endif 

#ifndef ERROR
#include "error.h"
#endif 


class lexer {
private:
	//lexer
	std::string line_buf;  //读取行缓存区
	char char_buf;       //读取字符缓冲
	char next_char_buf;  //下一个字符的缓冲
	char char_loc;       //字符位置指针
	int line_length;    //行的长度
	int level = 0;          //表示代码的层级
	int line_total = 0;  //表示总的行号
	int line_num = 0;  //表示当前读取行号

	std::ifstream* in_file;          //读入的文件

	int word_type;		//读入word的类型，详见namespace word
	int word_numvalue;  //数字类型返回
	double word_floatvalue;  //数字类型返回
	std::string word_stringvalue;  //数字类型返回
	std::string word_namevlaue;   //名字类型返回

	const int max_length_of_word = 250;  //变量名字的最长长度
	const int max_number_length = 14;
	char word_buffer[255];
	const int reserved_word_length = 17;
	bool is_reserved_word;

	void getchar();
	void getword();
	void letter_start();
	void number_start();
	int get_number_from_word();
	void string_start();
	void punctuation_start();

	std::vector<int> symbol_code_list;
	std::vector<int> symbol_location_list;
	int symbol_code_length;
	std::map<int, int> symbol_int_list;
	std::map<int, double> symbol_double_list;
	std::map<int, std::string> symbol_name_list;
	std::map<int, std::string> symbol_string_list;
	int symbol_code_location;  //执行指针位置

	std::string lexer_name;
	
public:
	lexer(char* filename,bool listlex);
	lexer();
	int get_location();  //获取当前代码段执行位置
	void jump_location(int location);  //跳转代码段
	void skip_block();    //跳过一个代码区
	void get_next();       //获取下一个word
	void get_back();         //获取上一个word
	int code_length();     //返回代码长度

	int word_code;          //返回读取的代码
	int word_int;          //返回的获取列表
	double word_double;
	std::string word_name;
	std::string word_string;
	int lineloc;
	const char* get_lexer_name();
};


void lexer::get_next() {
	if (lexer::symbol_code_location == lexer::symbol_code_length) {
		lexer::word_code = word::control::ENDMARKER;
		return;
	}
	int loc = lexer::symbol_code_location;
	lexer::word_code = lexer::symbol_code_list[loc];
	lexer::lineloc = lexer::symbol_location_list[loc];
	if (lexer::word_code >= word::type::NAME) {
		if (symbol_code_list[loc] == word::type::NAME)
			lexer::word_name = lexer::symbol_name_list[loc];
		if (symbol_code_list[loc] == word::type::STRING)
			lexer::word_string = lexer::symbol_string_list[loc];
		if (symbol_code_list[loc] == word::type::NUMBER)
			lexer::word_int = lexer::symbol_int_list[loc];
		if (symbol_code_list[loc] == word::type::FLOAT)
			lexer::word_double = lexer::symbol_double_list[loc];
	}
	lexer::symbol_code_location++;
}

void lexer::get_back() {
	if (lexer::symbol_code_location == lexer::symbol_code_length) {
		lexer::word_code = word::control::ENDMARKER;
		return;
	}
	int loc = lexer::symbol_code_location-2;
	lexer::word_code = lexer::symbol_code_list[loc];
	lexer::lineloc = lexer::symbol_location_list[loc];
	if (lexer::word_code >= word::type::NAME) {
		if (symbol_code_list[loc] == word::type::NAME)
			lexer::word_name = lexer::symbol_name_list[loc];
		if (symbol_code_list[loc] == word::type::STRING)
			lexer::word_string = lexer::symbol_string_list[loc];
		if (symbol_code_list[loc] == word::type::NUMBER)
			lexer::word_int = lexer::symbol_int_list[loc];
		if (symbol_code_list[loc] == word::type::FLOAT)
			lexer::word_double = lexer::symbol_double_list[loc];
	}
	lexer::symbol_code_location--;
}

void lexer::skip_block() {
	int i = symbol_code_location;
	int level_t=1;
	while(true) {
		symbol_code_location++;
		if (lexer::symbol_code_list[symbol_code_location] == word::control::DEDENT) {
			level_t--;
			if (level_t == 0) {
				break;
			}
		}
		else if (lexer::symbol_code_list[symbol_code_location] == word::control::INDENT) {
			level_t++;
		}
	}
	lexer::get_next();
} 


void lexer::jump_location(int location) {
	if (location >= 0 && location < lexer::symbol_code_length) {
		lexer::symbol_code_location = location;
	}
}

int lexer::get_location() {
	return lexer::symbol_code_location;
}

int lexer::code_length() {
	return lexer::symbol_code_length;
}

const char* lexer::get_lexer_name() {
	return lexer::lexer_name.c_str();
}

lexer::lexer(char *filename,bool listlex=false)
{
	std::ifstream *myfile=new std::ifstream(filename);
	if (!(*myfile).is_open())
	{
		throw("未成功打开文件");
	}
	lexer::lexer_name = filename;

	lexer::in_file = myfile;
	lexer::symbol_code_location = 0;

	lexer::getchar();
	while (true) {
		lexer::getword();
		lexer::symbol_code_list.push_back(lexer::word_type);
		lexer::symbol_location_list.push_back(lexer::line_num);
		if (lexer::word_type == word::control::ENDMARKER) {
			lexer::symbol_code_location++;
			break;
		}
		if (lexer::word_type >= word::type::NAME) {
			if (lexer::word_type == word::type::NAME)
				lexer::symbol_name_list[lexer::symbol_code_location] = lexer::word_namevlaue;
			if (lexer::word_type == word::type::STRING)
				lexer::symbol_string_list[lexer::symbol_code_location] = lexer::word_stringvalue;
			if (lexer::word_type == word::type::NUMBER)
				lexer::symbol_int_list[lexer::symbol_code_location] = lexer::word_numvalue;
			if (lexer::word_type == word::type::FLOAT)
				lexer::symbol_double_list[lexer::symbol_code_location] = lexer::word_floatvalue;
		}
		lexer::symbol_code_location++;
	}
	lexer::symbol_code_length = lexer::symbol_code_location;
	lexer::symbol_code_location = 0;
	
	if (listlex) {
		jump_location(0);
		std::cout << lexer::symbol_code_location << std::endl;
		while (true) {
			get_next();
			std::cout << lexer::word_code << std::endl;
			if (lexer::word_code == word::control::ENDMARKER) {
				break;
			}
			if (lexer::word_code == word::control::INDENT) {
				skip_block();
			}
			if (lexer::word_code >= 60) {
				if (lexer::word_code == 60)
					std::cout << lexer::word_name << std::endl;
				if (lexer::word_code == 61)
					std::cout << lexer::word_string << std::endl;
				if (lexer::word_code == 62)
					std::cout << lexer::word_int << std::endl;
				if (lexer::word_code == 63)
					std::cout << lexer::word_double << std::endl;
			}
		}
	}
}


void lexer::getchar() 
{
	if (lexer::char_loc == lexer::line_length) {
		line_num += 1;
		//字符缓冲区满，则读取下一行
		if (lexer::in_file->eof()) {
			if (lexer::level == 0) {
				lexer::char_buf = 0;
				return;
			}
			lexer::char_buf = '\b';
			lexer::level--;
			return;
		}
		std::string temp;
		getline(*lexer::in_file, temp);
		//空行只显示\n
		int i;
		
		for (i = 0; i < (int)temp.length(); i++) {
			if (!(temp[i] == ' ' || temp[i] == '\t')) {
				break;
			}
		}
		if (i == (int)temp.length()) {
			lexer::char_loc = lexer::line_length;
			lexer::char_buf = word::control::NEWLINE;
		}
		
		lexer::line_total++;
		//去掉前面的空格
		for (i = 0; i < (int)temp.length(); i++) {
			if (!(temp[i] == ' ' || temp[i] == '\t')) {
				break;
			}
		}
		//按照空格的数量判断前后的层次结构
		lexer::line_buf = temp.substr(i, temp.length() - i);
		lexer::line_buf.append("\n");

		if (i > lexer::level + 1) {
			error::syntax_error(lexer::line_total, error::space_error);
		}
		else if (i < lexer::level) {
			std::string tempp = "";
			for (int j = i; j < lexer::level; j++) {
				tempp.append("\b");
			}
			lexer::line_buf = tempp + lexer::line_buf;
		}
		else if (i == lexer::level+1) {
			lexer::line_buf = '\t' + lexer::line_buf;
		}
		//记录信息
		lexer::level = i;
		lexer::line_length = lexer::line_buf.length();
		lexer::char_loc = 0;
	}

	lexer::char_buf = lexer::line_buf[lexer::char_loc];
	lexer::char_loc++;

}


void lexer::getword() {
	if (lexer::char_buf == 0) {
		//如果是0则直接返回结束标识符
		lexer::word_type = word::control::ENDMARKER;
		return;
	}
	while (lexer::char_buf == ' '){
		lexer::getchar();
	}
	char ch = lexer::char_buf;
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch=='_') {
		//字母开头分析
		lexer::letter_start();
	}
	else if (ch >= '0' && ch <= '9') {
		//数字开头分析
		lexer::number_start();
	}
	else if (ch == '"') {
		lexer::string_start();
	}
	else {
		lexer::punctuation_start();
	}
}


void lexer::string_start() {
	std::string temp = "";
	lexer::getchar();
	while (lexer::char_buf != '\"') {
		if (lexer::char_buf == '\\') {
			lexer::getchar();
			char ch = lexer::char_buf;
			int i;
			for (i = 0; i < word::escape_character_table_length; i++) {
				if (ch == word::escape_character_table[i * 2]) {
					temp = temp + word::escape_character_table[i * 2 + 1];
					lexer::getchar();
					break;
				}
			}
			if (i == 12) {
				error::syntax_error(lexer::line_total, error::escape_character_error);
			}
		}
		else if (lexer::char_buf == '\n') {
			error::syntax_error(lexer::line_total, error::string_not_complete);
		}
		else {
			temp = temp + lexer::char_buf;
			lexer::getchar();
		}
	}
	lexer::getchar();
	lexer::word_stringvalue = temp;
	lexer::word_type = word::type::STRING;
}



void lexer::punctuation_start() {
	if (lexer::char_buf == '\n') {
		lexer::word_type = word::control::NEWLINE;
		lexer::getchar();
	}
	else if (lexer::char_buf == '\t') {
		lexer::word_type = word::control::INDENT;
		lexer::getchar();
	}
	else if (lexer::char_buf == '\b') {
		lexer::word_type = word::control::DEDENT;
		lexer::getchar();
	}
	else if (lexer::char_buf == ',') {
		lexer::word_type = word::punctuation::COMMA;
		lexer::getchar();
	}
	else if (lexer::char_buf == ':') {
		lexer::word_type = word::punctuation::COLON;
		lexer::getchar();
	}
	else if (lexer::char_buf == '.') {
		lexer::word_type = word::punctuation::PERIOD;
		lexer::getchar();
	}
	else if (lexer::char_buf == '%') {
		lexer::word_type = word::punctuation::REMAINDER;
		lexer::getchar();
	}
	else if (lexer::char_buf == '(') {
		lexer::word_type = word::punctuation::PAREN_L;
		lexer::getchar();
	}
	else if (lexer::char_buf == ')') {
		lexer::word_type = word::punctuation::PAREN_R;
		lexer::getchar();
	}
	else if (lexer::char_buf == '[') {
		lexer::word_type = word::punctuation::BRACKET_L;
		lexer::getchar();
	}
	else if (lexer::char_buf == ']') {
		lexer::word_type = word::punctuation::BRACKET_R;
		lexer::getchar();
	}
	else if (lexer::char_buf == '|') {
		lexer::word_type = word::punctuation::LOGICAL_OR;
		lexer::getchar();
	}
	else if (lexer::char_buf == '&') {
		lexer::word_type = word::punctuation::LOGICAL_AND;
		lexer::getchar();
	}
	else if (lexer::char_buf == '=') {
		lexer::getchar();
		if (lexer::char_buf == '=') {
			lexer::word_type = word::punctuation::EQUAL;
			lexer::getchar();
		}
		else {
			lexer::word_type = word::punctuation::ASSIGN;
		}
	}
	else if (lexer::char_buf == '+') {
		lexer::getchar();
		if (lexer::char_buf == '=') {
			lexer::word_type = word::punctuation::ADD_EQUAL;
			lexer::getchar();
		}
		else {
			lexer::word_type = word::punctuation::ADD;
		}
	}
	else if (lexer::char_buf == '-') {
		lexer::getchar();
		if (lexer::char_buf == '=') {
			lexer::word_type = word::punctuation::MINUS_EQUAL;
			lexer::getchar();
		}
		else {
			lexer::word_type = word::punctuation::MINUS;
		}
	}
	else if (lexer::char_buf == '*') {
		lexer::getchar();
		if (lexer::char_buf == '=') {
			lexer::word_type = word::punctuation::MULTI_EQUAL;
			lexer::getchar();
		}
		else {
			lexer::word_type = word::punctuation::MULTI;
		}
	}
	else if (lexer::char_buf == '/') {
		lexer::getchar();
		if (lexer::char_buf == '=') {
			lexer::word_type = word::punctuation::DIV_EQUAL;
			lexer::getchar();
		}
		else if (lexer::char_buf == '/') {
			lexer::word_type = word::punctuation::DIV_CEIL;
			lexer::getchar();
		}
		else {
			lexer::word_type = word::punctuation::DIV;
		}
	}
	else if (lexer::char_buf == '<') {
		lexer::getchar();
		if (lexer::char_buf == '=') {
			lexer::word_type = word::punctuation::LESS_EQUAL;
			lexer::getchar();
		}
		else {
			lexer::word_type = word::punctuation::LESS;
		}
	}
	else if (lexer::char_buf == '>') {
		lexer::getchar();
		if (lexer::char_buf == '=') {
			lexer::word_type = word::punctuation::MORE_EQUAL;
			lexer::getchar();
		}
		else {
			lexer::word_type = word::punctuation::MORE;
		}
	}
	else {
		error::syntax_error(lexer::line_total, error::type_unrecognized);
		do {
			lexer::getchar();
		} while (lexer::char_buf == ' ');
	}
}



void lexer::number_start() {
	// 检测是否为数字：以0..9开头
	int num = lexer::get_number_from_word();
	int flo = 0;
	if (lexer::char_buf == '.') {
		//浮点数
		lexer::getchar();
		if (!(lexer::char_buf >='0' && lexer::char_buf <= '9')) {
			error::syntax_error(lexer::line_total, error::float_number_error);
		}
		flo = lexer::get_number_from_word();
		if (lexer::char_buf == 'f') {
			lexer::getchar();
		}
		double temp = (double)flo;
		while (temp >= 1) {
			temp = temp / 10;
		}
		temp = temp + (double)num;
		lexer::word_type = word::type::FLOAT;
		lexer::word_floatvalue = temp;
	}
	else if (lexer::char_buf == 'f') {
		//f结尾强行转化为浮点数
		lexer::word_type = word::type::FLOAT;
		lexer::word_floatvalue = (double)num;
	}
	else {
		//整数
		lexer::word_type = word::type::NUMBER;
		lexer::word_numvalue = num;
	}
}


int lexer::get_number_from_word() {
	int k = 0;
	int num = 0;
	do {
		if (char_buf == '_')
			continue;
		num = 10 * num + lexer::char_buf - '0';
		k++;
		lexer::getchar();
	} while((lexer::char_buf >= '0' && lexer::char_buf <= '9') || lexer::char_buf == '_'); 
	// 获取数字的值 
	k--;
	if (k > max_number_length) {
		error::syntax_error(lexer::line_total, error::number_exceeded_error);
	}
	return num;
}


void lexer::letter_start() {
	int k = 0;
	do {
		if (k < lexer::max_length_of_word)
		{
			lexer::word_buffer[k] = lexer::char_buf;
			k++;
		}
		lexer::getchar();
	} while ((lexer::char_buf >= 'a' && lexer::char_buf <= 'z') ||
		(lexer::char_buf >= 'A' && lexer::char_buf <= 'Z') ||
		(lexer::char_buf >= '0' && lexer::char_buf <= '9') ||
		lexer::char_buf == '_');
	lexer::word_buffer[k] = 0;

	//判断lexer::word_buffer是不是保留字，是保留字则记录为相应的类型，否则记录为NAME类型，并
	int i = 0;
	int j = lexer::reserved_word_length - 1;
	do {    // 搜索当前符号是否为保留字 
		k = (i + j) / 2;
		if (strcmp(lexer::word_buffer, word::reserved_content[k]) <= 0)
		{
			j = k - 1;
		}
		if (strcmp(lexer::word_buffer, word::reserved_content[k]) >= 0)
		{
			i = k + 1;
		}
	} while (i <= j);
	if (i - 1 > j){
		lexer::word_type = k;
	}
	else {
		lexer::word_type = word::type::NAME;
		lexer::word_namevlaue = lexer::word_buffer;
	}
}





