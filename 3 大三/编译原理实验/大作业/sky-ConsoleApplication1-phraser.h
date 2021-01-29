#pragma once
#define PHRASER 0
#include <string>
#include <stack>


#ifndef LEXER
#include "lexer.h"
#endif 

#ifndef RUNNINGTIME
#include "runningtime.h"
#endif 

#ifndef ERROR
#include "error.h"
#endif 

#ifndef SYMBOLTABLE
#include "symboltable.h"
#endif // SYMBOLTABLE

#ifndef PHRASEBASIC
#include "phrasebasic.h"
#endif // !PHRASEBASIC

#ifndef INITFUNCTINO
#include "initfunction.h"
#endif // !INITFUNCTINO


class phraser {
public:
	phraser(lexer* code_lexer, running_table_class* table);
	phrase::return_value function_return;
	void run();

private:
	lexer* code_lexer;
	running_table_class* table;
	std::stack<phrase::block> block_control;

	std::stack<phrase::bracket_type> bracket_balance;

	void file_input();
	void stmt();
	void simple_stmt();
	void small_stmt();
	void flow_stmt();

	void del_del_stmt();
	bool del_atom(std::string name);

	void pass();
	void expr_stmt();
	void break_stmt();
	void continue_stmt();
	void return_stmt();

	
	void import_stmt();
	void compound_stmt();

	//simple statement
	phrase::return_value array_def();

	phrase::return_value or_test();
	phrase::return_value and_test();
	phrase::return_value not_test();
	phrase::return_value comparison();
	phrase::return_value expr();
	phrase::return_value term();
	phrase::return_value factor();
	phrase::return_value atom();
	void trailer(phrase::return_value*);
	void subscript(phrase::return_value*);
	void arglist(phrase::return_value*);
	phrase::infunction_type* argument();

	//compound statement
	void if_stmt();
	void while_stmt();
	void for_stmt();
	void funcdef();
	void if_atom_format();


	bool value_transmit(phrase::return_value* name1, phrase::return_value* name2);
	void* basic_operate(running::name_type type, void* val1, void* val2, word::punctuation operator_);
	void switch_value(phrase::return_value* name,running::name_type type);

	void debug();

	bool break_sign = false;
	bool continue_sign = false;
	bool return_sign = false;
	int loop_conting = 0;     //counting of the loop level, there is no max level in principle.
};


phraser::phraser(lexer* code_lexer, running_table_class* table) {
	phraser::code_lexer = code_lexer;
	phraser::table = table;
}


void phraser::run() {
	code_lexer->get_next();
	file_input();
}


void phraser::file_input() {
	int word_code = code_lexer->word_code;
	while (word_code != word::control::ENDMARKER) {
		//执行到结束为止
		if (break_sign == true || continue_sign == true || return_sign==true	|| word_code == word::control::DEDENT) {
			break;
		}

		if (word_code == word::control::NEWLINE) {
			//如果是新的一行，则执行结束
			code_lexer->get_next();
			word_code = code_lexer->word_code;

		}
		else {
			stmt();
		}
		word_code = code_lexer->word_code;
		
	}
}


void phraser::stmt() {
	int word_code = code_lexer->word_code;
	
	if (word_code == word::reserved::DEL ||
		word_code == word::type::NAME ||
		word_code == word::reserved::PASS ||
		word_code == word::reserved::IMPORT ||
		word_code == word::reserved::BREAK ||
		word_code == word::reserved::CONTINUE ||
		word_code == word::reserved::RETURN) {
		simple_stmt();
	}
	else if (word_code == word::reserved::IF ||
		word_code == word::reserved::WHILE ||
		word_code == word::reserved::FOR ||
		word_code == word::reserved::DEF) {
		compound_stmt();
	}
	else {
		error::syntax_error(error::carry_return_error,code_lexer->lineloc);
	}
}


void phraser::simple_stmt() {
	small_stmt();
	int word_code = code_lexer->word_code;
	if (word_code == word::control::NEWLINE) {
		code_lexer->get_next();
	}
	else {
		error::syntax_error(error::carry_return_error, code_lexer->lineloc);
	}
}

void phraser::small_stmt() {
	
	int word_code = code_lexer->word_code;
	if (word_code == word::reserved::DEL) {
		code_lexer->get_next();
		del_del_stmt();
	}
	else if (word_code == word::type::NAME) {
		expr_stmt();
	}
	else if (word_code == word::reserved::PASS) {
		code_lexer->get_next();
		pass();
	}
	else if (word_code == word::reserved::BREAK ||
		word_code == word::reserved::CONTINUE ||
		word_code == word::reserved::RETURN) {
		flow_stmt();
	}
	else if (word_code == word::reserved::IMPORT) {
		code_lexer->get_next();
		import_stmt();
	}
	else{
		error::syntax_error(error::unrecognized_syntax_error, code_lexer->lineloc);
	}

}

void phraser::flow_stmt() {
	int word_code = code_lexer->word_code;
	if (word_code == word::reserved::BREAK) {
		code_lexer->get_next();
		break_stmt();
	}
	else if (word_code == word::reserved::CONTINUE) {
		code_lexer->get_next();
		continue_stmt();
	}
	else if (word_code == word::reserved::RETURN) {
		code_lexer->get_next();
		return_stmt();
	}
}



void phraser::return_stmt() {
	int word_code = code_lexer->word_code;
	phrase::return_value ret = or_test();
	
	function_return.type= ret.type;
	function_return.value = ret.value;
	
	return_sign = true;
}


void phraser::continue_stmt() {
	if (loop_conting >= 1) {
		continue_sign = true;
		return;
	}
	else {
		error::syntax_error(error::continue_used_error, code_lexer->lineloc);
	}

}



void phraser::break_stmt() {
	if (loop_conting >= 1) {
		break_sign = true;
		return;
	}
	else {
		error::syntax_error(error::break_used_error, code_lexer->lineloc);
	}
	
}


 
void phraser::pass() {
	return;
}


void phraser::del_del_stmt() {
	int word_code = code_lexer->word_code;
	if (word_code == word::type::NAME) {
		std::string name = code_lexer->word_name;
		if (!del_atom(name)) {
			error::syntax_error(error::del_name_error, code_lexer->lineloc);
		}
	}
	else {
		error::syntax_error(error::del_type_error, code_lexer->lineloc);
	}

	code_lexer->get_next();
	word_code = code_lexer->word_code;
	while (word_code == word::punctuation::COMMA) {
		code_lexer->get_next();
		if (word_code == word::type::NAME) {
			std::string name = code_lexer->word_name;
			if (!del_atom(name)) {
				error::syntax_error(error::del_name_error, code_lexer->lineloc);
			}
		}
		else {
			error::syntax_error(error::del_type_error, code_lexer->lineloc);
		}
		code_lexer->get_next();
		word_code = code_lexer->word_code;
	}
}	


bool phraser::del_atom(std::string name) {
	if (table->get_items(name) == NULL) {
		return false;
	}
	table->del_function(name);
	return true;
}


void phraser::expr_stmt() {
	std::string waiting_value = code_lexer->word_name; 
	code_lexer->get_next();
	int word_code = code_lexer->word_code;


	if (word_code == word::punctuation::ASSIGN) {
		//等号，表示赋值语句
		code_lexer->get_next();
		word_code = code_lexer->word_code;
		phrase::return_value value = or_test();
		table->append_table(value.type, waiting_value, value.value);
	}
	else //加等于的计算赋值语句
		if (word_code == word::punctuation::ADD_EQUAL ||
		word_code == word::punctuation::MINUS_EQUAL ||
		word_code == word::punctuation::MULTI_EQUAL ||
		word_code == word::punctuation::DIV_EQUAL) {
				
		running::name_table* name = table->get_items(waiting_value);
		if (name == NULL) {
			error::syntax_error(error::value_not_found_error, code_lexer->lineloc);
		}
		else {
			phrase::return_value frontal_value;
			frontal_value.type = name->ntype;
			frontal_value.hasvalue = true;
			frontal_value.value = name->pointer;
			code_lexer->get_next();
			
			phrase::return_value value = or_test();
			if (!value_transmit(&frontal_value, &value)) {
				error::syntax_error(error::value_type_error, code_lexer->lineloc);
			}
			void* result = basic_operate(frontal_value.type, (void*)(&frontal_value),
				(void*)(&value), (word::punctuation) word_code);
			if (frontal_value.type == running::name_type::ARRAY_INT) {
				frontal_value.type = running::name_type::ARRAY_FLOAT;
			}
			table->append_table(frontal_value.type, waiting_value, result);
		}
	}
	else {
		code_lexer->get_back();
		phrase::return_value ret = or_test();
		//error::syntax_error(error::expression_error, code_lexer->lineloc);
	}

}



phrase::return_value phraser::or_test() {
	int word_code = code_lexer->word_code;
	
	phrase::return_value ret1;
	phrase::return_value ret2;
	ret1 = and_test();
	
	word_code = code_lexer->word_code;
	while (word_code == word::reserved::OR) {
		code_lexer->get_next();
		ret2 = and_test();
		word_code = code_lexer->word_code;

		if (!(ret1.hasvalue && ret2.hasvalue)) {
			error::syntax_error(error::expression_error, code_lexer->lineloc);
		}
		bool b1 = true;
		bool b2 = true;
		if (ret1.type == running::name_type::INT) {
			if (*(int*)(ret1.value) == 0) 
				b1 = false;
		}
		else if(ret1.type == running::name_type::FLOAT) {
			if (*(double*)(ret1.value) == 0)
				b1 = false;
		}
		else {
			error::syntax_error(error::unsupport_type, code_lexer->lineloc);
		}

		if (ret2.type == running::name_type::INT) {
			if (*(int*)(ret2.value) == 0)
				b2 = false;
		}
		else if (ret2.type == running::name_type::FLOAT) {
			if (*(double*)(ret2.value) == 0)
				b2 = false;
		}
		else {
			error::syntax_error(error::unsupport_type, code_lexer->lineloc);
		}

		ret1.type = running::name_type::INT;
		if (b1 || b2) {
			ret1.value = (void*)(new int(1));
		}
		else {
			ret1.value = (void*)(new int(0));
		}
	}
	
	return ret1;
}


phrase::return_value phraser::and_test() {
	int word_code = code_lexer->word_code;
	phrase::return_value ret1;
	phrase::return_value ret2; 
	ret1 = not_test(); 
	
	word_code = code_lexer->word_code;
	while (word_code == word::reserved::AND) {
		code_lexer->get_next();
		ret2 = not_test();
		word_code = code_lexer->word_code;

		if (!(ret1.hasvalue && ret2.hasvalue)) {
			error::syntax_error(error::expression_error, code_lexer->lineloc);
		}
		bool b1 = true;
		bool b2 = true;
		if (ret1.type == running::name_type::INT) {
			if (*(int*)(ret1.value) == 0)
				b1 = false;
		}
		else if (ret1.type == running::name_type::FLOAT) {
			if (*(double*)(ret1.value) == 0)
				b1 = false;
		}
		else {
			error::syntax_error(error::unsupport_type, code_lexer->lineloc);
		}

		if (ret2.type == running::name_type::INT) {
			if (*(int*)(ret2.value) == 0)
				b2 = false;
		}
		else if (ret2.type == running::name_type::FLOAT) {
			if (*(double*)(ret2.value) == 0)
				b2 = false;
		}
		else {
			error::syntax_error(error::unsupport_type, code_lexer->lineloc);
		}

		ret1.type = running::name_type::INT;
		if (b1 && b2) {
			ret1.value = (void*)(new int(1));
		}
		else {
			ret1.value = (void*)(new int(0));
		}
	}
	return ret1;
}


phrase::return_value phraser::not_test() {
	int word_code = code_lexer->word_code;
	phrase::return_value ret;
	bool isnot = false;
	if (word_code == word::reserved::NOT) {
		isnot = true;
		code_lexer->get_next();
	}
	ret = comparison();
	if (isnot) {
		switch (ret.type) {
		case running::name_type::INT:
			if (*(int*)(ret.value) == 0) {
				ret.value = (void*)(new int(1));
			}
			else {
				ret.value = (void*)(new int(0));
			}
			break;
		case running::name_type::FLOAT:
			if (*(double*)(ret.value) == 0) {
				ret.value = (void*)(new double(1));
			}
			else {
				ret.value = (void*)(new double(0));
			}
			break;
		default:
			error::syntax_error(error::unsupport_type, code_lexer->lineloc);
		}
	}
	return ret;
}



phrase::return_value phraser::comparison() {
	int word_code = code_lexer->word_code;
	phrase::return_value ret1;
	phrase::return_value ret2; 
	ret1 = expr();
	word_code = code_lexer->word_code;
	if (word_code == word::punctuation::LESS ||
		word_code == word::punctuation::MORE ||
		word_code == word::punctuation::EQUAL ||
		word_code == word::punctuation::MORE_EQUAL ||
		word_code == word::punctuation::LESS_EQUAL) {
		code_lexer->get_next();
		
		ret2 = expr();
		switch_value(&ret1, running::name_type::INT);
		switch_value(&ret2, running::name_type::INT);
		int val1 = *(int*)ret1.value;
		int val2 = *(int*)ret2.value;
		int result = 1;
		
		switch (word_code) {
		case word::punctuation::LESS:
			if (val1 < val2) 
				result = 1;
			else result = 0;
			break;
		case word::punctuation::MORE:
			if (val1 > val2)
				result = 1;
			else result = 0;
			break;
		case word::punctuation::EQUAL:
			if (val1 == val2)
				result = 1;
			else result = 0;
			break;
		case word::punctuation::MORE_EQUAL:
			if (val1 >= val2)
				result = 1;
			else result = 0;
			break;
		case word::punctuation::LESS_EQUAL:
			if (val1 <= val2)
				result = 1;
			else result = 0;
			break;
		}
		ret1.value = (void*)(new int(result));
	}
	return ret1;
}


phrase::return_value phraser::expr() {
	int word_code = code_lexer->word_code;
	phrase::return_value ret1;
	phrase::return_value ret2;
	ret1 = term();
	word_code = code_lexer->word_code;
	while (word_code == word::punctuation::ADD ||
		   word_code == word::punctuation::MINUS) {
		
		int temp_operator = word_code;
		code_lexer->get_next();
		ret2 = term();
		word_code = code_lexer->word_code;
		if (!(ret1.hasvalue && ret2.hasvalue)) {
			error::syntax_error(error::expression_error, code_lexer->lineloc);
		}
		value_transmit(&ret1, &ret2);

		void* res = basic_operate(ret1.type, &ret1, &ret2, (word::punctuation)temp_operator);
		if (ret1.type == running::name_type::ARRAY_INT) {
			ret1.type = running::name_type::ARRAY_FLOAT;
		}
		ret1.value = res;
	}
	return ret1;
}

phrase::return_value phraser::term() {
	int word_code = code_lexer->word_code;
	phrase::return_value ret1;
	phrase::return_value ret2;
	ret1 = factor();

	word_code = code_lexer->word_code;
	while (word_code == word::punctuation::MULTI ||
		word_code == word::punctuation::DIV) {
		int temp_operator = word_code;
		code_lexer->get_next();
		ret2 = factor();
		
		word_code = code_lexer->word_code;
		if (!(ret1.hasvalue && ret2.hasvalue)) {
			error::syntax_error(error::expression_error, code_lexer->lineloc);
		}
		value_transmit(&ret1, &ret2);
		void* res = basic_operate(ret1.type, &ret1, &ret2, (word::punctuation)temp_operator);
		if (ret1.type == running::name_type::ARRAY_INT) {
			ret1.type = running::name_type::ARRAY_FLOAT;
		}
		ret1.value = res;
	}
	return ret1;
}

phrase::return_value phraser::factor() {
	phrase::return_value ret; 
	ret = atom(); 
	trailer(&ret); 
	return ret;
}

void phraser::trailer(phrase::return_value* ret) {
	int word_code = code_lexer->word_code;
	if (word_code == word::punctuation::BRACKET_L ||
		word_code == word::punctuation::PAREN_L) {
		if (word_code == word::punctuation::BRACKET_L) {
			code_lexer->get_next();
			subscript(ret);
			word_code = code_lexer->word_code;
			if (word_code == word::punctuation::BRACKET_R) {		
				code_lexer->get_next();
			}
			else {
				
				error::syntax_error(error::bracket_error, code_lexer->lineloc);
			}
		}
		else {
			code_lexer->get_next(); 
			arglist(ret);
			word_code = code_lexer->word_code;
			if (word_code == word::punctuation::PAREN_R) {
				code_lexer->get_next();
			}
			else {
				error::syntax_error(error::bracket_error, code_lexer->lineloc);
			}
		}
	}
	else 
		if (word_code == word::punctuation::BRACKET_R ||
		word_code == word::punctuation::PAREN_R) {
		if (bracket_balance.size() == 0) {
			error::syntax_error(error::bracket_error, code_lexer->lineloc);
		}
		if (word_code == word::punctuation::BRACKET_R) {
			
			if (bracket_balance.top() == phrase::bracket_type::bracket) {
				bracket_balance.pop();				
			}
			else {
				error::syntax_error(error::bracket_error, code_lexer->lineloc);
			}
		}
		else {
			if (bracket_balance.top() == phrase::bracket_type::para) {
				bracket_balance.pop();
			}
			else {
				error::syntax_error(error::bracket_error, code_lexer->lineloc);
			}
		}
	}

}

void phraser::subscript(phrase::return_value* ret) {
	phrase::return_value* retsub=new phrase::return_value;
	retsub->type = ret->type;
	retsub->name = ret->name;

	if (!(ret->type == running::name_type::ARRAY_FLOAT ||
		ret->type == running::name_type::ARRAY_INT ||
		ret->type == running::name_type::ARRAY_STRING ||
		ret->type == running::name_type::STRING)) {
		error::syntax_error(error::list_number_error, code_lexer->lineloc);
	}
	
	bracket_balance.push(phrase::bracket_type::bracket);
	
	phrase::return_value ret2 = or_test();
	
	int listnumber = 0;

	if (ret2.type == running::name_type::INT) {
		listnumber = *(int*)ret2.value;
	}
	else {
		error::syntax_error(error::list_number_error, code_lexer->lineloc);
	}

	if (ret->type == running::name_type::ARRAY_FLOAT) {
		retsub->type = running::name_type::FLOAT;
		std::vector<double>* temp = (std::vector<double>*)(ret->value);
		if ((int)temp->size() <= listnumber) {
			error::syntax_error(error::list_number_outof_range, code_lexer->lineloc);
		}
		double val = (*temp)[listnumber];
		
		retsub->value = (void*)(new double(val));
	}
	else if (ret->type == running::name_type::ARRAY_INT) {
		retsub->type = running::name_type::INT;
		std::vector<int>* temp = (std::vector<int>*)(ret->value);
		if ((int)temp->size() <= listnumber) {
			error::syntax_error(error::list_number_outof_range, code_lexer->lineloc);
		}
		int val = (*temp)[listnumber];
		retsub->value = (void*)(new int(val));
	}
	else if (ret->type == running::name_type::ARRAY_STRING) {
		retsub->type = running::name_type::STRING;
		std::vector<std::string>* temp = (std::vector<std::string>*)(ret->value);
		if ((int)temp->size() <= listnumber) {
			error::syntax_error(error::list_number_outof_range, code_lexer->lineloc);
		}
		std::string val = (*temp)[listnumber];
		retsub->value = (void*)(new std::string(val));
	}
	else if (ret->type == running::name_type::STRING) {
		retsub->type = running::name_type::STRING;
		std::string* temp = (std::string*)(ret->value);
		if ((int)temp->size() <= listnumber) {
			error::syntax_error(error::list_number_outof_range, code_lexer->lineloc);
		}
		std::string val = "";
		val.push_back((*temp)[listnumber]);
		retsub->value = (void*)(new std::string(val));
	}
	*ret = *retsub;
}


void phraser::arglist(phrase::return_value* ret) {
	
	if (!(ret->type == running::name_type::FUNCTION)) {
		error::syntax_error(error::not_function, code_lexer->lineloc);
	}

	bracket_balance.push(phrase::bracket_type::para);

	phrase::infunction_type* retlist = argument(); 		
	
	running::function_table* func = (running::function_table*)ret->value;
	if (func->insert_function) {
		//嵌入式函数，用c语言实现
		typedef phrase::return_value(*funpointer)(phrase::infunction_type * infunction);
		
		funpointer funp = (funpointer)func->function_pointer;
		phrase::return_value rettemp = funp( retlist);
		ret->type = rettemp.type;
		ret->value = rettemp.value;
		if (rettemp.error) {
			error::syntax_error(rettemp.error_type, code_lexer->lineloc);
		}
	}
	else {
		
		int length = retlist->parameter->size();
		if (func->parameter_num != length) {
			error::syntax_error(error::function_parameter_num_error, code_lexer->lineloc);
		}
		int function_start_table_loc = table->in_function(ret->name);
		if (function_start_table_loc == -1) {
			error::syntax_error(error::not_function, code_lexer->lineloc);
		}
		int now_loc = code_lexer->get_location();
		int fun_loc = func->start_position;
		lexer* lex = func->lex_table;
		lex->jump_location(fun_loc);
		for (int i = 0; i < func->parameter_num; i++) {
			running::name_type type = (*(retlist->type))[i];
			void* val = (*(retlist->parameter))[i];
			std::string name = (*(func->name_list))[i];
			table->append_table(type, name, val);
		}
		phraser phr(lex, table); 
		//create the return val
		phrase::return_value rettemp;
		rettemp.type = running::name_type::INT;
		rettemp.value = (void*)(new int(0));
		phr.function_return = rettemp;
		phr.run(); 

		rettemp = phr.function_return;
		ret->type = rettemp.type;
		ret->value = rettemp.value;

		table->out_function(function_start_table_loc);
		code_lexer->jump_location(now_loc);
		code_lexer->get_back();
		code_lexer->get_next();
	}
	
}


phrase::infunction_type* phraser::argument() {
	phrase::infunction_type* ret=new phrase::infunction_type;
	ret->type = new std::vector<running::name_type>();
	ret->parameter = new std::vector<void*>();

	int word_code = code_lexer->word_code;
	if (word_code == word::punctuation::PAREN_R) {
		return ret;
	}
	phrase::return_value temp = or_test(); 
	
	ret->type->push_back(temp.type);
	ret->parameter->push_back(temp.value);

	word_code = code_lexer->word_code;
	while (word_code == word::punctuation::COMMA) {
		code_lexer->get_next();
		temp = or_test();
		
		ret->type->push_back(temp.type);
		ret->parameter->push_back(temp.value);
		word_code = code_lexer->word_code;
	}
	return ret;
}


phrase::return_value phraser::atom() {
	
	int word_code = code_lexer->word_code;
	phrase::return_value ret;
	ret.hasvalue = false;

	if (word_code == word::punctuation::BRACKET_L ||
		word_code == word::punctuation::PAREN_L) {
		//圆括号，生成向量	
		if (word_code == word::punctuation::PAREN_L) {
			code_lexer->get_next();

			phrase::return_value ret = array_def();
			word_code = code_lexer->word_code;
			if (word_code == word::punctuation::PAREN_R) {
				code_lexer->get_next();
			}
			else {
				error::syntax_error(error::expression_error, code_lexer->lineloc);
			}
			return ret;
		}
		//方括号，生成列表
		else {
			/*
			phrase::return_value ret = list_def();
			table->append_table(ret.type, waiting_value, ret.value);
			if (word_code == word::punctuation::BRACKET_R) {
				code_lexer->get_next();
			}
			else {
				error::syntax_error(error::expression_error, code_lexer->lineloc);
			}
			*/
		}
	}

	if (word_code == word::type::NAME ||
		word_code == word::type::NUMBER ||
		word_code == word::type::FLOAT ||
		word_code == word::type::STRING) {
		ret.hasvalue = true;
		if (word_code == word::type::NUMBER) {
			ret.type = running::name_type::INT;
			int val = code_lexer->word_int;
			ret.value = (void*)(new int(val));
		}
		else if (word_code == word::type::FLOAT) {
			ret.type = running::name_type::FLOAT;
			double val = code_lexer->word_double;
			ret.value = (void*)(new double(val));
		}
		else if (word_code == word::type::STRING) {
			ret.type = running::name_type::STRING;
			std::string val = code_lexer->word_string;
			ret.value = (void*)(new std::string(val));
		}
		else if (word_code == word::type::NAME) {
			running::name_table* name = table->get_items(code_lexer->word_name);
			if (name == NULL) {
				error::syntax_error(error::name_not_found, code_lexer->lineloc);
			}
			ret.name = code_lexer->word_name;
			if (name->ntype == running::name_type::INT) {
				ret.type = running::name_type::INT;
				int val = *(int*)(name->pointer);
				ret.value = (void*)(new int(val));
			}
			else if (name->ntype == running::name_type::FLOAT) {
				ret.type = running::name_type::FLOAT;
				double val = *(double*)(name->pointer);
				ret.value = (void*)(new double(val));
			}
			else if (name->ntype == running::name_type::STRING) {
				ret.type = running::name_type::STRING;
				std::string val = *(std::string*)(name->pointer);
				ret.value = (void*)(new std::string(val));
			}
			else{
				ret.type = name->ntype;
				ret.value = name->pointer;
			}
		}
	}
	else if (word_code == word::PAREN_L) {
		
		code_lexer->get_next();
		ret = or_test();
		if (word_code == word::PAREN_R) {
			code_lexer->get_next();
		}
		else {	
			error::syntax_error(error::expression_error, code_lexer->lineloc);
		}
	}
	else {
		error::syntax_error(error::expression_error, code_lexer->lineloc);
	}
	code_lexer->get_next();
	return ret;
}



void phraser::switch_value(phrase::return_value* name, running::name_type type){
	switch (name->type) {
	case running::name_type::INT:
		if (type == running::name_type::INT) {
			return;
		}
		else if (type == running::name_type::FLOAT) {
			name->type = running::name_type::FLOAT;
			int val = *(int*)name->value;
			name->value = (void*)(new double(val));
		}
		else {
			error::syntax_error(error::unsupport_type, code_lexer->lineloc);
		}
	case running::name_type::FLOAT:
		if (type == running::name_type::FLOAT) {
			return;
		}
		else if (type == running::name_type::INT) {
			name->type = running::name_type::INT;
			double val = *(int*)name->value;
			int temp = (int)val;
			name->value = (void*)(new int(temp));
		}
		else {
			error::syntax_error(error::unsupport_type, code_lexer->lineloc);
		}
	}

}


bool phraser::value_transmit(phrase::return_value* name1, phrase::return_value* name2) {
	running::name_type type1 = name1->type;
	running::name_type type2 = name2->type;
	if (type1 == type2) {
		return true;
	}
	if (type1 == running::name_type::FLOAT && type2 == running::name_type::INT) {
		name2->type = running::name_type::FLOAT;
		int value = *(int*)(name2->value);
		name2->value = (void*)(new double(value));
		return true;
	}
	else if (type1 == running::name_type::INT && type2 == running::name_type::FLOAT) {
		name1->type = running::name_type::FLOAT;
		int value = *(int*)(name1->value);
		name1->value = (void*)(new double(value));
		return true;
	}
	return false;
}



void* phraser::basic_operate(running::name_type type, void* val1, void* val2, word::punctuation operator_) {
	int val1_int = 0;
	int val2_int = 0;
	int val_int = 0;
	double val1_double = 0;
	double val2_double = 0;
	double val_double = 0;
	std::string val1_str;
	std::string val2_str;
	std::string val_str;

	running::name_type type1 = ((phrase::return_value*)(val1))->type;
	running::name_type type2 = ((phrase::return_value*)(val2))->type;
	val1 = ((phrase::return_value*)(val1))->value;
	val2 = ((phrase::return_value*)(val2))->value;
	
	

	switch (type) {
	case running::name_type::INT:
		val1_int = *(int*)(val1);
		val2_int = *(int*)(val2);
		if (operator_ == word::punctuation::MULTI || operator_ == word::punctuation::MULTI_EQUAL) {
			val_int = val1_int * val2_int;
		}
		else if (operator_ == word::punctuation::DIV || operator_ == word::punctuation::DIV_EQUAL) {
			val_int = val1_int / val2_int;
		}
		else if (operator_ == word::punctuation::ADD || operator_ == word::punctuation::ADD_EQUAL) {
			val_int = val1_int + val2_int;
		}
		else if (operator_ == word::punctuation::MINUS || operator_ == word::punctuation::MINUS_EQUAL) {
			val_int = val1_int - val2_int;
		}
		else {
			error::syntax_error(error::operation_not_support, code_lexer->lineloc);
		}
		
		return (void*)(new int(val_int));
		break;

	case running::name_type::FLOAT:
		val1_double = *(double*)(val1);
		val2_double = *(double*)(val2);

		if (operator_ == word::punctuation::MULTI || operator_ == word::punctuation::MULTI_EQUAL) {
			val_double = val1_double * val2_double;
		}
		else if (operator_ == word::punctuation::DIV || operator_ == word::punctuation::DIV_EQUAL) {
			val_double = val1_double / val2_double;
		}
		else if (operator_ == word::punctuation::ADD || operator_ == word::punctuation::ADD_EQUAL) {
			val_double = val1_double + val2_double;
		}
		else if (operator_ == word::punctuation::MINUS || operator_ == word::punctuation::MINUS_EQUAL) {
			val_double = val1_double - val2_double;
		}
		else {
			error::syntax_error(error::operation_not_support, code_lexer->lineloc);
		}
		return (void*)(new double(val_double));
		break;

	case running::name_type::STRING:
		val1_str = *(std::string*)(val1);
		val2_str = *(std::string*)(val2);
		if (operator_ == word::punctuation::ADD || operator_ == word::punctuation::MULTI_EQUAL) {
			val_str = val1_str + val2_str;
		}
		else {
			error::syntax_error(error::operation_not_support, code_lexer->lineloc);
		}
		return (void*)(new std::string(val_str));
		break;

	case running::name_type::ARRAY_STRING:
		error::syntax_error(error::operation_not_support, code_lexer->lineloc);
	}


	if (type == running::name_type::ARRAY_INT || type == running::name_type::ARRAY_FLOAT) {
		std::vector<int>* val_array1_int;
		std::vector<double>* val_array1_double;
		std::vector<int>* val_array2_int;
		std::vector<double>* val_array2_double;
		int length1 = 0;
		int length2 = 0;
		std::vector<double> temp1;
		std::vector<double> temp2;
		if (type1 == running::name_type::ARRAY_INT) {
			val_array1_int = (std::vector<int>*)(val1);
			length1 = val_array1_int->size();
			for (int i = 0; i < length1; i++) {
				temp1.push_back((double)((*val_array1_int)[i]));
			}
		}
		else if (type1 == running::name_type::ARRAY_FLOAT) {
			val_array1_double = (std::vector<double>*)(val1);
			length1 = val_array1_double->size();
			for (int i = 0; i < length1; i++) {
				temp1.push_back((double)((*val_array1_double)[i]));
			}
		}
		else {
			error::syntax_error(error::operation_not_support, code_lexer->lineloc);
		}

		if (type2 == running::name_type::ARRAY_INT) {
			val_array2_int = (std::vector<int>*)(val2);
			length2 = val_array2_int->size();
			for (int i = 0; i < length2; i++) {
				temp2.push_back((double)((*val_array2_int)[i]));
			}
		}
		else if (type2 == running::name_type::ARRAY_FLOAT) {
			val_array2_double = (std::vector<double>*)(val2);
			length2 = val_array2_double->size();
			for (int i = 0; i < length2; i++) {
				temp2.push_back((double)((*val_array2_double)[i]));
			}
		}
		else {
			error::syntax_error(error::operation_not_support, code_lexer->lineloc);
		}

		if (length1 != length2) {
			error::syntax_error(error::array_operate_length_error, code_lexer->lineloc);
		}
		

		std::vector<double>* val_array = new std::vector<double>();
		if (operator_ == word::punctuation::MULTI || operator_ == word::punctuation::MULTI_EQUAL) {
			for (int i = 0; i < length1; i++) {
				double val = temp1[i] * temp2[i];
				val_array->push_back(val);
			}
		}
		else if (operator_ == word::punctuation::DIV || operator_ == word::punctuation::DIV_EQUAL) {
			for (int i = 0; i < length1; i++) {
				double val = temp1[i] / temp2[i];
				val_array->push_back(val);
			}
		}
		else if (operator_ == word::punctuation::ADD || operator_ == word::punctuation::ADD_EQUAL) {
			for (int i = 0; i < length1; i++) {
				double val = temp1[i] + temp2[i];
				val_array->push_back(val);
			}
		}
		else if (operator_ == word::punctuation::MINUS || operator_ == word::punctuation::MINUS_EQUAL) {
			for (int i = 0; i < length1; i++) {
				double val = temp1[i] - temp2[i];
				val_array->push_back(val);
			}
		}
		else {
			error::syntax_error(error::operation_not_support, code_lexer->lineloc);
		}
		return val_array;
	}

	return NULL;

}



void phraser::import_stmt() {
	int word_code = code_lexer->word_code;
	std::string name;
	if (word_code == word::type::NAME) {
		name = code_lexer->word_name;
	}
	else if (word_code == word::type::STRING) {
		name = code_lexer->word_string;
	}
	else {
		error::syntax_error(error::import_error, code_lexer->lineloc);
	}
	code_lexer->get_next();

	if (table->in_import(name)) {
		char* name2 = (char*	)name.c_str();
		lexer* lex = new lexer(name2);
		phraser phr(lex, table);
		phr.run();
	}

}


void phraser::compound_stmt() {
	int word_code = code_lexer->word_code;
	if (word_code == word::reserved::IF) {
		if_stmt();
	}
	else if (word_code == word::reserved::WHILE) {
		while_stmt();
	}
	else if (word_code == word::reserved::FOR) {
		for_stmt();
	}
	else if (word_code == word::reserved::DEF) {
		funcdef();
	}
	else {
		error::syntax_error(error::carry_return_error, code_lexer->lineloc);
	}
}

phrase::return_value phraser::array_def() {
	bracket_balance.push(phrase::bracket_type::para);

	phrase::return_value ret;
	int word_code = code_lexer->word_code;
	phrase::return_value ret1 = or_test();
	
	running::name_type type = ret1.type;
	std::vector<phrase::return_value> vec;
	running::name_type nowtype = type;
	if (type == running::name_type::INT ||
		type == running::name_type::FLOAT ||
		type == running::name_type::STRING) {
		
		vec.push_back(ret1);
		word_code = code_lexer->word_code;
		while (word_code == word::punctuation::COMMA) {
			code_lexer->get_next();
			phrase::return_value ret2;
			ret2 = or_test();
			word_code = code_lexer->word_code;
			type = ret2.type;
			if (nowtype == running::name_type::STRING) {
				if (type == running::name_type::INT || type == running::name_type::FLOAT) {
					error::syntax_error(error::array_created_error, code_lexer->lineloc);
				}
			}
			else if (nowtype == running::name_type::INT) {
				if (type == running::name_type::STRING) {
					error::syntax_error(error::array_created_error, code_lexer->lineloc);
				}
				else if (type == running::name_type::FLOAT) {
					nowtype = running::name_type::FLOAT;
				}
			}
			else if (nowtype == running::name_type::FLOAT) {
				if (type == running::name_type::STRING) {
					error::syntax_error(error::array_created_error, code_lexer->lineloc);
				}
			}
			
			if (type == running::name_type::INT ||
				type == running::name_type::FLOAT ||
				type == running::name_type::STRING) {
				vec.push_back(ret2);
			}
			else {
				error::syntax_error(error::array_created_error, code_lexer->lineloc);
			}
		}
	}
	else {
		error::syntax_error(error::array_created_error, code_lexer->lineloc);
	}
	

	if (nowtype == running::name_type::INT) {
		ret.type = running::name_type::ARRAY_INT;
		std::vector<int>* tempvec = new std::vector<int>();
		for (int i = 0; i < (int)vec.size(); i++) {
			
			phrase::return_value teret = vec[i];
			if (teret.type == running::name_type::INT) {
				int val = *(int*)teret.value;
				
				tempvec->push_back(val);
			}
			else if (teret.type == running::name_type::FLOAT) {
				double val = *(double*)teret.value;
				tempvec->push_back((int)val);
			}
			else {
				error::syntax_error(error::array_created_error, code_lexer->lineloc);
			}
		}
		ret.value = (void*)tempvec;
	}
	else if (nowtype == running::name_type::FLOAT) {
		ret.type = running::name_type::ARRAY_FLOAT;
		std::vector<double>* tempvec = new std::vector<double>();
		for (int i = 0; i < (int)vec.size(); i++) {
			phrase::return_value teret = vec[i];
			if (teret.type == running::name_type::INT) {
				int val = *(int*)teret.value;
				tempvec->push_back((double)val);
			}
			else if (teret.type == running::name_type::FLOAT) {
				double val = *(double*)teret.value;
				tempvec->push_back(val);
			}
			else {
				error::syntax_error(error::array_created_error, code_lexer->lineloc);
			}
		}
		ret.value = (void*)tempvec;
	}
	else if (nowtype == running::name_type::STRING) {
		ret.type = running::name_type::ARRAY_STRING;
		std::vector<std::string>* tempvec = new std::vector<std::string>();
		for (int i = 0; i < (int)vec.size(); i++) {
			phrase::return_value teret = vec[i];
			std::string val = *(std::string*)teret.value;
			tempvec->push_back(val);
		}
		ret.value = (void*)tempvec;
	}
	else {
		error::syntax_error(error::array_created_error, code_lexer->lineloc);
	}
	
	return ret;
}


void phraser::while_stmt() {
	int while_start_loc = code_lexer->get_location();
	code_lexer->get_next();
	int word_code = code_lexer->word_code;
	phrase::return_value ret = or_test();
	word_code = code_lexer->word_code;
	//while head
	if (word_code == word::punctuation::COLON) {
		code_lexer->get_next();
	}
	else {
		error::syntax_error(error::while_syntax_error, code_lexer->lineloc);
	}
	word_code = code_lexer->word_code;
	while (word_code == word::control::NEWLINE) {
		code_lexer->get_next();
		word_code = code_lexer->word_code;
	}
	if (word_code == word::control::INDENT) {
		code_lexer->get_next();
	}
	else {
		error::syntax_error(error::while_syntax_error, code_lexer->lineloc);
	}
	//add the counting of the loop
	loop_conting += 1;
	//in while
	table->running_levelup();
	while (true) {
		
		if (ret.type == running::name_type::INT) {
			if (*(int*)(ret.value) == 0) {
				break;
			}
		}
		else if (ret.type == running::name_type::FLOAT) {
			if (*(double*)(ret.value) == 0) {
				break;
			}
		}
		else {
			error::syntax_error(error::while_syntax_error, code_lexer->lineloc);
		}
		
		//running the while loop
		
		file_input();
		
		if (break_sign == true) {
			break_sign = false;
			break;
		}
		if (continue_sign == true) {
			continue_sign = false;
		}

		//go to the beginning of the while loop

		table->running_leveldown();
		code_lexer->jump_location(while_start_loc);
		code_lexer->get_next();	
		ret = or_test();
		code_lexer->get_next();
		code_lexer->get_next();
		while (word_code == word::control::NEWLINE) {
			code_lexer->get_next();
			word_code = code_lexer->word_code;
		}
		code_lexer->get_next();
		word_code = code_lexer->word_code;
		
		
		table->running_levelup();
	}
	if (code_lexer->word_code != word::control::DEDENT) {
		code_lexer->skip_block();
	}
	
	code_lexer->get_next();
	table->running_leveldown();
	loop_conting -= 1;
}



void phraser::for_stmt() {
	code_lexer->get_next();
	int word_code = code_lexer->word_code;
	std::string for_name;
	//find the name of the variable of the for loop.
	if (word_code == word::type::NAME) {
		for_name = code_lexer->word_name;
		code_lexer->get_next();
		word_code = code_lexer->word_code;
	}
	else {
		error::syntax_error(error::for_syntax_error, code_lexer->lineloc);	
	}

	if (word_code == word::reserved::IN) {
		code_lexer->get_next();
		word_code = code_lexer->word_code;
	}
	else {
		error::syntax_error(error::for_syntax_error, code_lexer->lineloc);
	}

	//for loop only support the array type of variable
	phrase::return_value ret = or_test();
	if (!(ret.type == running::name_type::ARRAY_INT ||
		ret.type == running::name_type::ARRAY_FLOAT ||
		ret.type == running::name_type::ARRAY_STRING)) {
		error::syntax_error(error::for_syntax_error, code_lexer->lineloc);
	}
	word_code = code_lexer->word_code;

	//record the location of the beginning of the for loop.
	int for_start_loc = code_lexer->get_location();
	if (word_code == word::punctuation::COLON) {
		code_lexer->get_next();
		word_code = code_lexer->word_code;
	}
	else {
		error::syntax_error(error::while_syntax_error, code_lexer->lineloc);
	}
	
	while (word_code == word::control::NEWLINE) {
		code_lexer->get_next();
		word_code = code_lexer->word_code;
	}
	if (word_code == word::control::INDENT) {
		code_lexer->get_next();
	}
	else {
		error::syntax_error(error::while_syntax_error, code_lexer->lineloc);
	}
	word_code = code_lexer->word_code;

	loop_conting += 1;
	//int type of for loop
	if (ret.type == running::name_type::ARRAY_INT) {
		table->append_table(running::name_type::INT, for_name, new int(0));
		std::vector<int>* vec = (std::vector<int>*)ret.value;

		table->running_levelup();
		for (int i = 0; i < (int)vec->size(); i++) {
			int val = (*vec)[i];
			running::name_table* tab = table->get_items(for_name);
			tab->pointer = (void*)(new int(val));

			file_input();
			
			if (break_sign == true) {	
				break_sign = false;
				break;
			}
			if (continue_sign == true) {
				continue_sign = false;
			}

			table->running_leveldown();
			code_lexer->jump_location(for_start_loc);
			code_lexer->get_next();
			word_code = code_lexer->word_code;
			while (word_code == word::control::NEWLINE) {
				code_lexer->get_next();
				word_code = code_lexer->word_code;
			}
			
			code_lexer->get_next();
			table->running_levelup();
		}
		if (code_lexer->word_code != word::control::DEDENT) {
			code_lexer->skip_block();

		}
		code_lexer->get_next();
		table->running_leveldown();
		
	}

	//double type of for loop
	else if (ret.type == running::name_type::ARRAY_FLOAT) {
		table->append_table(running::name_type::FLOAT, for_name, new double(0));
		std::vector<double>* vec = (std::vector<double>*)ret.value;

		table->running_levelup();
		for (int i = 0; i < (int)vec->size(); i++) {
			double val = (*vec)[i];
			running::name_table* tab = table->get_items(for_name);
			tab->pointer = (void*)(new double(val));

			file_input();

			if (break_sign == true) {
				break_sign = false;
				break;
			}
			if (continue_sign == true) {
				continue_sign = false;
			}

			table->running_leveldown();
			code_lexer->jump_location(for_start_loc);
			code_lexer->get_next();
			word_code = code_lexer->word_code;
			while (word_code == word::control::NEWLINE) {
				code_lexer->get_next();
				word_code = code_lexer->word_code;
			}

			code_lexer->get_next();
			table->running_levelup();
		}
		code_lexer->skip_block();
		code_lexer->get_next();
		table->running_leveldown();
	}

	//string type of for loop
	else if (ret.type == running::name_type::ARRAY_STRING) {
		table->append_table(running::name_type::STRING, for_name, new std::string(""));
		std::vector<std::string>* vec = (std::vector<std::string>*)ret.value;

		table->running_levelup();
		for (int i = 0; i < (int)vec->size(); i++) {
			std::string val = (*vec)[i];
			running::name_table* tab = table->get_items(for_name);
			tab->pointer = (void*)(new std::string(val));

			file_input();

			if (break_sign == true) {
				break_sign = false;
				break;
			}
			if (continue_sign == true) {
				continue_sign = false;
			}
			
			table->running_leveldown();
			code_lexer->jump_location(for_start_loc);
			code_lexer->get_next();
			word_code = code_lexer->word_code;
			while (word_code == word::control::NEWLINE) {
				code_lexer->get_next();
				word_code = code_lexer->word_code;
			}

			code_lexer->get_next();
			table->running_levelup();
		}
		code_lexer->skip_block();
		code_lexer->get_next();
		table->running_leveldown();
	}
	loop_conting -= 1;
}


void phraser::if_stmt() {
	code_lexer->get_next();
	int word_code = code_lexer->word_code;
	phrase::return_value ret = or_test();
	
	if_atom_format();
	word_code = code_lexer->word_code;

	//judge the return value of the or test.
	bool judge = true;
	if (ret.type == running::name_type::INT) {
		if (*(int*)(ret.value) == 0) {
			judge = false;
		}
	}
	else if (ret.type == running::name_type::FLOAT) {
		if (*(double*)(ret.value) == 0) {
			judge = false;
		}
	}
	else {
		error::syntax_error(error::if_syntax_error, code_lexer->lineloc);
	}
	
	//judge is true
	if (judge) {
		//run the if block
		table->running_levelup();
		file_input();
		table->running_leveldown();
		code_lexer->get_next();
		word_code = code_lexer->word_code;
		while (word_code == word::control::NEWLINE) {
			code_lexer->get_next();
			word_code = code_lexer->word_code;
		}
		
		//skip all the elif block
		while(word_code == word::reserved::ELIF) {
			
			code_lexer->get_next();
			phrase::return_value temp_ret = or_test();
			if_atom_format();
			word_code = code_lexer->word_code;

			code_lexer->skip_block();
			code_lexer->get_next();
			word_code = code_lexer->word_code;
		}
		
		if (word_code == word::reserved::ELSE) {
			code_lexer->get_next();

			if_atom_format();
			word_code = code_lexer->word_code;

			code_lexer->skip_block();
			code_lexer->get_next();
			word_code = code_lexer->word_code;
		}
	}
	//judge is false
	else {
		code_lexer->skip_block();
		code_lexer->get_next();
		word_code = code_lexer->word_code;
		while (word_code == word::control::NEWLINE) {
			code_lexer->get_next();
			word_code = code_lexer->word_code;
		}
		
		int already_elif = false;
		//state of else if
		while (word_code == word::reserved::ELIF) {
			
			code_lexer->get_next();
			ret = or_test();
			judge = true;
			if (ret.type == running::name_type::INT) {
				if (*(int*)(ret.value) == 0) {
					judge = false;
				}
			}
			else if (ret.type == running::name_type::FLOAT) {
				if (*(double*)(ret.value) == 0) {
					judge = false;
				}
			}
			else {
				error::syntax_error(error::if_syntax_error, code_lexer->lineloc);
			}
			
			if_atom_format();
			word_code = code_lexer->word_code;
				
			//else if state, the judge is true
			if (judge && !already_elif) {
				table->running_levelup();
				file_input();
				table->running_leveldown();
				code_lexer->get_next();
				word_code = code_lexer->word_code;
				while (word_code == word::control::NEWLINE) {
					code_lexer->get_next();
					word_code = code_lexer->word_code;
				}
				already_elif = true;
			}
			else {
				code_lexer->skip_block();
				code_lexer->get_next();
				word_code = code_lexer->word_code;
			}
		}

		
		//all of the judge aformationed is false, the run the else block
		word_code = code_lexer->word_code;
		if (word_code == word::reserved::ELSE) {
			code_lexer->get_next();
			if_atom_format();
			word_code = code_lexer->word_code;
			if (judge == true) {
				code_lexer->skip_block();
				code_lexer->get_next();
				word_code = code_lexer->word_code;
			}
			else {
				table->running_levelup();
				file_input();
				table->running_leveldown();
				code_lexer->get_next();
				word_code = code_lexer->word_code;
				while (word_code == word::control::NEWLINE) {
					code_lexer->get_next();
					word_code = code_lexer->word_code;
				}
			}
		}
	}
}



void phraser::if_atom_format() {
	int word_code = code_lexer->word_code;
	if (word_code == word::punctuation::COLON) {
		code_lexer->get_next();
		word_code = code_lexer->word_code;
	}
	else {
		error::syntax_error(error::while_syntax_error, code_lexer->lineloc);
	}

	while (word_code == word::control::NEWLINE) {
		code_lexer->get_next();
		word_code = code_lexer->word_code;
	}
	if (word_code == word::control::INDENT) {
		code_lexer->get_next();
	}
	else {
		error::syntax_error(error::while_syntax_error, code_lexer->lineloc);
	}
}


void phraser::funcdef() {
	code_lexer->get_next();
	int word_code = code_lexer->word_code;
	if (word_code != word::type::NAME) {
		error::syntax_error(error::function_define_error, code_lexer->lineloc);
	}
	std::string function_name = code_lexer->word_name;
	code_lexer->get_next();
	word_code = code_lexer->word_code;

	int para_num = 0;
	std::vector<std::string> arg_list; 
	if (word_code != word::punctuation::PAREN_L) {
		error::syntax_error(error::function_define_error, code_lexer->lineloc);
	}
	else {
		code_lexer->get_next();
		word_code = code_lexer->word_code;
	}
	if (word_code != word::punctuation::PAREN_R) {
		if (word_code == word::type::NAME) {
			arg_list.push_back(code_lexer->word_name);
			para_num++;
			code_lexer->get_next();
			word_code = code_lexer->word_code;
		}
		else {
			error::syntax_error(error::function_define_error, code_lexer->lineloc);
		}
		
		while (word_code == word::punctuation::COMMA) {
			code_lexer->get_next();
			word_code = code_lexer->word_code;
			if (word_code == word::type::NAME) {
				arg_list.push_back(code_lexer->word_name);
				para_num++;
				code_lexer->get_next();
				word_code = code_lexer->word_code;
			}
			else {
				error::syntax_error(error::function_define_error, code_lexer->lineloc);
			}
		}
		
		if (word_code != word::punctuation::PAREN_R) {
			error::syntax_error(error::function_define_error, code_lexer->lineloc);
		}
		else {
			code_lexer->get_next();
			word_code = code_lexer->word_code;
		}
	}
	else {
		code_lexer->get_next();
		word_code = code_lexer->word_code;
	}
	
	if (word_code != word::punctuation::COLON) {
		error::syntax_error(error::function_define_error, code_lexer->lineloc);
	}
	else {
		code_lexer->get_next();
		word_code = code_lexer->word_code;
	}

	while (word_code == word::control::NEWLINE) {
		code_lexer->get_next();
		word_code = code_lexer->word_code;
	}
	int fun_start_loc = 0;
	if (word_code != word::control::INDENT) {
		error::syntax_error(error::function_define_error, code_lexer->lineloc);
	}
	else {
		fun_start_loc = code_lexer->get_location();
		code_lexer->get_next();
		word_code = code_lexer->word_code;
	}


	running::function_table* fun = new running::function_table;
	fun->insert_function = false;

	fun->parameter_num = para_num;
	fun->name_list = new std::vector<std::string>();
	for (int i = 0; i < (int)arg_list.size(); i++) {
		fun->name_list->push_back(arg_list[i]);
	}
	fun->lex_table = code_lexer;
	fun->start_position = fun_start_loc;

	table->append_table(running::name_type::FUNCTION, function_name, (void*)fun);
	code_lexer->skip_block();
	code_lexer->get_next();
}


void phraser::debug() {
	int word_code = code_lexer->word_code;
	if (word_code < 20) {
		printf("type: reserved word.  name: %s\n", word::reserved_content[word_code]);
	}
	else if (word_code < 50) {
		printf("type: punctuation. value: %s\n", word::punctuation_content[word_code-20]);
	}
	else if (word_code == word::control::NEWLINE) {
		printf("type: control.  value: new line\n");
	}
	else if (word_code == word::control::DEDENT) {
		printf("type: control.  value: ded ent\n");
	}
	else if (word_code == word::control::INDENT) {
		printf("type: control.  value: ind ent\n");
	}
	else if (word_code == word::control::ENDMARKER) {
		printf("type: control.  value: end mark\n");
	}
	else if (word_code == word::type::NAME) {
		printf("type: name.  value: %s\n",code_lexer->word_name.c_str());
	}
	else if (word_code == word::type::NUMBER) {
		printf("type: number.  value: %d\n", code_lexer->word_int);
	}
	else if (word_code == word::type::FLOAT) {
		printf("type: float.  value: %f\n", code_lexer->word_double);
	}
	else if (word_code == word::type::STRING) {
		printf("type: string.  value: %s\n", code_lexer->word_string.c_str());
	}
}


