#pragma once

#define INITFUNCTINO 0
#include <vector>
#include <stdlib.h>
#include <string>
#ifndef ERROR
#include "error.h"
#endif 

#ifndef RUNNINGTIME
#include"runningtime.h"
#endif


#ifndef PHRASEBASIC
#include "phrasebasic.h"
#endif // !PHRASEBASIC


namespace init_name {
	struct infunction_type {
		std::vector<running::name_type> type;
		std::vector<void*> parameter;
	};

	running_table_class* table;
	//function name
	phrase::return_value function_max(phrase::infunction_type*);
	phrase::return_value function_min(phrase::infunction_type*);

	phrase::return_value function_show_table(phrase::infunction_type*);

	phrase::return_value function_print(phrase::infunction_type*);
	phrase::return_value function_input(phrase::infunction_type*);

	phrase::return_value function_int(phrase::infunction_type*);
	phrase::return_value function_float(phrase::infunction_type*);
	phrase::return_value function_string(phrase::infunction_type*);

	phrase::return_value function_range(phrase::infunction_type*);

}


class init_function {

public:
	init_function(running_table_class*);


private:
	running_table_class* table;

};




init_function::init_function(running_table_class* table) {  //running_table_class* table
	this->table = table;
	init_name::table = table;
	typedef phrase::return_value(*funpointer)(phrase::infunction_type * infunction);

	//register the function "max"
	running::function_table *fun_max = new running::function_table;
	fun_max->insert_function = true;
	funpointer function_max = init_name::function_max;
	fun_max->function_pointer = (void*)(function_max);
	table->append_table(running::name_type::FUNCTION, "max", (void*)(fun_max));

	//register the function "min"
	running::function_table* fun_min = new running::function_table;
	fun_min->insert_function = true;
	funpointer function_min = init_name::function_min;
	fun_min->function_pointer = (void*)(function_min);
	table->append_table(running::name_type::FUNCTION, "min", (void*)(fun_min));

	//register the function "show_table"
	running::function_table* fun_show_table = new running::function_table;
	fun_show_table->insert_function = true;
	funpointer function_show_table = init_name::function_show_table;
	fun_show_table->function_pointer = (void*)(function_show_table);
	table->append_table(running::name_type::FUNCTION, "show_table", (void*)(fun_show_table));

	//register the function "print"
	running::function_table* fun_print = new running::function_table;
	fun_print->insert_function = true;
	funpointer function_print = init_name::function_print;
	fun_print->function_pointer = (void*)(function_print);
	table->append_table(running::name_type::FUNCTION, "print", (void*)(fun_print));
	
	//register the function "input"
	running::function_table* fun_input = new running::function_table;
	fun_input->insert_function = true;
	funpointer function_input = init_name::function_input;
	fun_input->function_pointer = (void*)(function_input);
	table->append_table(running::name_type::FUNCTION, "input", (void*)(fun_input));

	//register the function "int"
	running::function_table* fun_int = new running::function_table;
	fun_int->insert_function = true;
	funpointer function_int = init_name::function_int;
	fun_int->function_pointer = (void*)(function_int);
	table->append_table(running::name_type::FUNCTION, "int", (void*)(fun_int));

	//register the function "float"
	running::function_table* fun_float = new running::function_table;
	fun_float->insert_function = true;
	funpointer function_float = init_name::function_float;
	fun_float->function_pointer = (void*)(function_float);
	table->append_table(running::name_type::FUNCTION, "float", (void*)(fun_float));

	//register the function "string"
	running::function_table* fun_string = new running::function_table;
	fun_string->insert_function = true;
	funpointer function_string = init_name::function_string;
	fun_string->function_pointer = (void*)(function_string);
	table->append_table(running::name_type::FUNCTION, "string", (void*)(fun_string));

	//register the function "range"
	running::function_table* fun_range = new running::function_table;
	fun_range->insert_function = true;
	funpointer function_range = init_name::function_range;
	fun_range->function_pointer = (void*)(function_range);
	table->append_table(running::name_type::FUNCTION, "range", (void*)(fun_range));
}


phrase::return_value init_name::function_max(phrase::infunction_type* infunction) {	
	std::vector<running::name_type>* type = infunction->type;
	std::vector<void*>* parameter = infunction->parameter;
	//printf("%d", type[0]);
	phrase::return_value ret;

	if (type->size() == 1) {
		if ((*type)[0] == running::name_type::ARRAY_INT ||
			(*type)[1] == running::name_type::ARRAY_FLOAT) {
			if ((*type)[0] == running::name_type::ARRAY_INT) {
				std::vector<int>* vec = (std::vector<int>*)((*parameter)[0]);
				int maxx = (*vec)[0];
				for (int i = 1; i < (int)vec->size(); i++) {
					if ((*vec)[i] > maxx) {
						maxx = (*vec)[i];
					}
				}
				ret.type = running::name_type::INT;
				ret.value = (void*)(new int(maxx));
			}
			else {
				std::vector<double>* vec = (std::vector<double>*)((*parameter)[0]);
				double maxx = (*vec)[0];
				for (int i = 1; i < (int)vec->size(); i++) {
					if ((*vec)[i] > maxx) {
						maxx = (*vec)[i];
					}
				}
				ret.type = running::name_type::FLOAT;
				ret.value = (void*)(new double(maxx));
			}
		}
		else {
			ret.error = true;
			ret.error_type = error::function_parameter_not_support_error;
		}
	}
	else {
		ret.error = true;
		ret.error_type = error::function_parameter_num_error;
	}
	return ret;
}


phrase::return_value init_name::function_min(phrase::infunction_type* infunction) {
	std::vector<running::name_type>* type = infunction->type;
	std::vector<void*>* parameter = infunction->parameter;
	//printf("%d", type[0]);
	phrase::return_value ret;

	if (type->size() == 1) {
		if ((*type)[0] == running::name_type::ARRAY_INT ||
			(*type)[1] == running::name_type::ARRAY_FLOAT) {
			if ((*type)[0] == running::name_type::ARRAY_INT) {
				std::vector<int>* vec = (std::vector<int>*)((*parameter)[0]);
				int minn = (*vec)[0];
				for (int i = 1; i < (int)vec->size(); i++) {
					if ((*vec)[i] < minn) {
						minn = (*vec)[i];
					}
				}
				ret.type = running::name_type::INT;
				ret.value = (void*)(new int(minn));
			}
			else {
				std::vector<double>* vec = (std::vector<double>*)((*parameter)[0]);
				double minn = (*vec)[0];
				for (int i = 1; i < (int)vec->size(); i++) {
					if ((*vec)[i] < minn) {
						minn = (*vec)[i];
					}
				}
				ret.type = running::name_type::FLOAT;
				ret.value = (void*)(new double(minn));
			}
		}
		else {
			ret.error = true;
			ret.error_type = error::function_parameter_not_support_error;
		}
	}
	else {
		ret.error = true;
		ret.error_type = error::function_parameter_num_error;
	}
	return ret;
}



phrase::return_value init_name::function_show_table(phrase::infunction_type* infunction) {
	std::vector<running::name_type>* type = infunction->type;
	std::vector<void*>* parameter = infunction->parameter;
	phrase::return_value ret;

	if (type->size() != 0) {
		ret.error = true;
		ret.error_type = error::function_parameter_num_error;
	}
	ret.type = running::name_type::INT;
	ret.value = (void*)(new int(0));

	table->show_table();
	return ret;
}



phrase::return_value init_name::function_input(phrase::infunction_type* infunction) {
	std::vector<running::name_type>* type = infunction->type;
	std::vector<void*>* parameter = infunction->parameter;
	phrase::return_value ret;

	if (type->size() == 1) {
		printf("%s", (*(std::string*)((*parameter)[0])).c_str());
	}
	else if (type->size() >= 2) {
		ret.error = true;
		ret.error_type = error::function_parameter_num_error;
		return ret;
	}

	ret.type = running::name_type::STRING;
	char buf[255];
	scanf_s("%s", buf, 254);
	buf[254] = '\0';
	ret.value = (void*)(new std::string(buf));
	return ret;
}


phrase::return_value init_name::function_print(phrase::infunction_type* infunction) {
	std::vector<running::name_type>* type = infunction->type;
	std::vector<void*>* parameter = infunction->parameter;
	phrase::return_value ret;

	if (type->size() == 0) {
		ret.error = true;
		ret.error_type = error::function_parameter_num_error;
		return ret;
	}
	if ((*type)[0] != running::STRING) {
		ret.error = true;
		ret.error_type = error::function_print_parameter_error;
		return ret;
	}
	std::string* print_std = (std::string*)(*parameter)[0];
	int para_loc = 1;
	for (int i = 0; i < (int)print_std->size(); i++) {
		if((*print_std)[i]=='{'){
			i++;
			char next = (*print_std)[i];
			int leng = -1;
			if (next >= '0' && next <= '9') {
				leng = next - '0';
				i++;
				next = (*print_std)[i];
			}
			if (next != '}') {
				ret.error = true;
				ret.error_type = error::function_print_parameter_error;
				return ret;
			}

			if ((int)type->size() <= para_loc) {
				ret.error = true;
				ret.error_type = error::function_print_parameter_error;
				return ret;
			}
			
			void *val = (*parameter)[para_loc];
			running::name_type type_val= (*type)[para_loc];
			std::vector<int>* vec_int ;
			std::vector<double>* vec_double;
			std::vector < std::string >* vec_string;

			switch (type_val) {
			case running::name_type::INT:
				printf("%d", *(int*)val);
				break;
			case running::name_type::FLOAT:

				printf("%f", *(double*)val);
				break;
			case running::name_type::STRING:
				printf("%s", (*(std::string*)val).c_str());
				break;
			case running::name_type::FUNCTION:
				printf("function_type");
				break;
			case running::name_type::ARRAY_INT:
				printf("(");
				vec_int = (std::vector<int>*)val;
				for (int j = 0; j < (int)vec_int->size(); j++) {
					printf("%d", (*vec_int)[j]);
					if (j != (int)vec_int->size() - 1) {
						printf(",");
					}
				}
				printf(")");
				break;
			case running::name_type::ARRAY_FLOAT:
				vec_double = (std::vector<double>*)val;
				printf("(");
				for (int j = 0; j < (int)vec_double->size(); j++) {
					printf("%f", (*vec_double)[j]);
					if (j != (int)vec_double->size() - 1) {
						printf(",");
					}
				}
				printf(")");
				break;
			case running::name_type::ARRAY_STRING:
				vec_string = (std::vector<std::string>*)val;
				printf("(");
				for (int j = 0; j < (int)vec_string->size(); j++) {
					printf("\"%s\"", ( (*vec_string)[j]).c_str() );
					if (j != (int)vec_string->size() - 1) {
						printf(",");
					}
				}
				printf(")");
				break;
			}

			para_loc++;
		}
		else {
			printf("%c", (*print_std)[i]);
		}
	} 

	ret.type = running::name_type::INT;
	ret.value = (void*)(new int(0));
	return ret;
}



phrase::return_value init_name::function_int(phrase::infunction_type* infunction) {
	std::vector<running::name_type>* type = infunction->type;
	std::vector<void*>* parameter = infunction->parameter;
	phrase::return_value ret;

	if (type->size() != 1) {
		ret.error = true;
		ret.error_type = error::function_parameter_num_error;
		return ret;
	}
	int val_int;
	double val_double;
	std::string val_string;
	switch ((*type)[0]) {
	case running::name_type::INT:
		val_int = *(int*)((*parameter)[0]);
		ret.value = (void*)(new int(val_int));
		break;
	case running::name_type::FLOAT:
		val_double = *(double*)((*parameter)[0]);
		ret.value = (void*)(new int((int)val_double));
		break;
	case running::name_type::STRING:
		val_string = *(std::string*)((*parameter)[0]);
		val_double = atoi(val_string.c_str());
		ret.value = (void*)(new int((int)val_double));
		break;
	default:
		ret.error = true;
		ret.error_type = error::function_parameter_num_error;
		return ret;
		break;
	}

	ret.type = running::name_type::INT;
	return ret;
}


phrase::return_value init_name::function_float(phrase::infunction_type* infunction) {
	std::vector<running::name_type>* type = infunction->type;
	std::vector<void*>* parameter = infunction->parameter;
	phrase::return_value ret;

	if (type->size() != 1) {
		ret.error = true;
		ret.error_type = error::function_parameter_num_error;
		return ret;
	}

	int val_int;
	double val_double;
	std::string val_string;
	switch ((*type)[0]) {
	case running::name_type::INT:
		val_int = *(int*)((*parameter)[0]);
		ret.value = (void*)(new double((double)val_int));
		break;
	case running::name_type::FLOAT:
		val_double = *(double*)((*parameter)[0]);
		ret.value = (void*)(new double(val_double));
		break;
	case running::name_type::STRING:
		val_string = *(std::string*)((*parameter)[0]);
		val_double = atof(val_string.c_str());
		ret.value = (void*)(new double(val_double));
		break;
	default:
		ret.error = true;
		ret.error_type = error::function_parameter_num_error;
		return ret;
		break;
	}

	ret.type = running::name_type::FLOAT;
	return ret;
}

phrase::return_value init_name::function_string(phrase::infunction_type* infunction) {
	std::vector<running::name_type>* type = infunction->type;
	std::vector<void*>* parameter = infunction->parameter;
	phrase::return_value ret;

	if (type->size() != 1) {
		ret.error = true;
		ret.error_type = error::function_parameter_num_error;
		return ret;
	}

	int val_int;
	double val_double;
	std::string val_string;
	std::string temp1;
	std::string temp2 = "";
	int zeronum = 0;
	switch ((*type)[0]) {
	case running::name_type::INT:
		val_int = *(int*)((*parameter)[0]);
		ret.value = (void*)(new std::string(std::to_string(val_int)));
		break;	
	case running::name_type::FLOAT:
		val_double = *(double*)((*parameter)[0]);
		temp1 = std::to_string(val_double);
		
		for (int i = temp1.length() - 1; i >= 0; i--) {
			if (temp1[i]=='0') {
				zeronum++;
			}
			else {
				break;
			}
		}
		for (int i = 0; i < (int)temp1.length() - zeronum; i++) {
			temp2 = temp2 + temp1[i];
		}
		ret.value = (void*)(new std::string(temp2));
		break;
	case running::name_type::STRING:
		val_string = *(std::string*)((*parameter)[0]);
		
		ret.value = (void*)(new std::string(val_string));
		break;
	default:
		ret.error = true;
		ret.error_type = error::function_parameter_num_error;
		return ret;
		break;
	}


	ret.type = running::name_type::STRING;
	return ret;
}



phrase::return_value init_name::function_range(phrase::infunction_type* infunction) {
	std::vector<running::name_type>* type = infunction->type;
	std::vector<void*>* parameter = infunction->parameter;
	phrase::return_value ret;

	if (type->size() < 1 || type->size()> 3) {
		ret.error = true;
		ret.error_type = error::function_parameter_num_error;
		return ret;
	}

	int startpos = 0;
	int endpos = 0;
	int stride = 1;

	if (type->size() >= 1) {
		if ((*type)[0] != running::name_type::INT) {
			ret.error = true;
			ret.error_type = error::function_parameter_not_support_error;
			return ret;
		}
		int val = *(int*)((*parameter)[0]);
		endpos = val;
	}

	if (type->size() >= 2) {
		if ((*type)[1] != running::name_type::INT) {
			ret.error = true;
			ret.error_type = error::function_parameter_not_support_error;
			return ret;
		}
		int val = *(int*)((*parameter)[1]);
		startpos = endpos;
		endpos = val;
	}

	if (type->size() >= 3) {
		if ((*type)[2] != running::name_type::INT) {
			ret.error = true;
			ret.error_type = error::function_parameter_not_support_error;
			return ret;
		}
		int val = *(int*)((*parameter)[2]);
		stride = val;
	}
	
	std::vector<int>* vec = new std::vector<int>();
	for (int i = startpos; i < endpos; i += stride) {
		vec->push_back(i);
	}

	ret.value = vec;
	ret.type = running::name_type::ARRAY_INT;
	return ret;
}

