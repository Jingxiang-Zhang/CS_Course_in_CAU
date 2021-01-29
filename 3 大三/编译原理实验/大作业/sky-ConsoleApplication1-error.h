#pragma once
#define ERROR 0
#include <iostream>
#include <string>



namespace error {
	void syntax_error(int location, std::string reason);
	void syntax_error(std::string reason, int loc);

	void syntax_error(std::string reason);

	std::string space_error = "the Bad use of space";
	std::string number_exceeded_error = "number exceeded error!";
	std::string escape_character_error = "escape character error!";
	std::string float_number_error = "float number error!";
	std::string string_not_complete = "string not complete!";
	std::string type_unrecognized = "type unrecognized!";

	std::string code_level_exceed = "code level exceed, the max level of code is 9999!";
	std::string function_level_exceed = "function level exceed, the max level of function is 999!";

	std::string carry_return_error = "should be carry return";
	std::string unrecognized_syntax_error = "unrecognized syntax error";
	std::string del_type_error = "del type error";
	std::string del_name_error = "no name is found in variable table";
	std::string pass_used_error = "pass cannot used here";
	std::string break_used_error = "break can only used in for and while loop";
	std::string continue_used_error = "continue can only used in for and while loop";
	std::string return_used_error = "return used error";
	std::string value_not_found_error = "value not found error";
	std::string return_error = "return error";
	std::string return_function = "return value cannot be a function";

	std::string value_not_found = "value not found";
	std::string expression_error = "expression error";
	std::string value_type_error = "value type error";
	std::string operation_not_support = "operation not support";
	std::string unsupport_type = "unsupport type";

	std::string list_number_error = "list number error";
	std::string bracket_error = "bracket error";
	std::string not_function = "not a function";
	std::string name_not_found = "name not found";
	std::string array_created_error = "array created error";
	std::string list_number_outof_range = "list number outof range";

	std::string while_syntax_error = "while syntax error";
	std::string for_syntax_error = "for syntax error";
	std::string if_syntax_error = "if syntax error";
	std::string array_operate_length_error = "array operate length error";

	std::string function_parameter_num_error = "function parameter num error";
	std::string function_parameter_not_support_error = "function parameter not support error";
	std::string function_print_parameter_error = "function print parameter error";
	std::string function_define_error = "function define error";

	std::string import_error = "import error";
}

void error::syntax_error(int location, std::string reason){
	printf("\n\nsyntax error in line %d\n", location);
	printf("    %s\n\n", reason.c_str());
	throw("syntax error");
	
}
void error::syntax_error(std::string reason, int loc) {
	printf("\n\nsyntax error\n        in line%d\n",loc);
	printf("    %s\n\n", reason.c_str());
	throw("syntax error");

}

void error::syntax_error(std::string reason) {
	printf("\n\nsyntax error\n ");
	printf("    %s\n\n", reason.c_str());
	throw("syntax error");

}