#pragma once
#define RUNNINGBASIC 0



namespace running {
	enum name_type {
		INT,
		FLOAT,
		STRING,
		ARRAY_INT,
		ARRAY_FLOAT,
		ARRAY_STRING,
		FUNCTION,
		LIST
	};
	//注：所有的array都是vector类型,list是vector<list_items>类型



	struct function_table {
		lexer* lex_table;   //执行参数表
		int start_position; //起始点位置
		int parameter_num;  //参数个数
		bool non_def_num;   //是否有不确定个数的参数
		std::vector<std::string> *name_list;

		bool insert_function;
		void* function_pointer;
		//phrase::return_value(init_function::* f_max) (phrase::infunction_type* infunction) ;

	};

	struct name_table {
		name_type ntype;
		std::string name;
		int level;     //表示变量所处的层级
		void* pointer;  //指向相关结构体的指针
		bool exist;     //表示是否被删除
		int reftimes;   //表示引用次数
	};
}

