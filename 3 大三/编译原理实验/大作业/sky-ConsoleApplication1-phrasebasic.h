#pragma once


#define PHRASEBASIC 0



namespace phrase {
	enum block_type {
		loop,
		function,
		if_block
	};

	struct block {
		lexer* lex;
		block_type type;
		int block_start_location;
		int running_table_location;
	};

	struct return_value {
		bool hasvalue = true;
		running::name_type type;  //如果有返回值，则找到返回值类型
		void* value;  //表示返回值的指针
		std::string name;

		bool error = false;
		std::string error_type;
	};

	enum bracket_type {
		bracket,
		para
	};

	struct infunction_type {
		std::vector<running::name_type>* type ;
		std::vector<void*>* parameter ;
	};

}
