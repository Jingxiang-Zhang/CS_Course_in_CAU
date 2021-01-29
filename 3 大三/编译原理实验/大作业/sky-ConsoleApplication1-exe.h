#pragma once
#define EXE 0
#include<string>


class exe {
public:
	exe();
	bool run_single_line(std::string line);
	bool run_file(std::string name);
	bool run_function(std::string name);

	void start_debugging();
	void insert_break_point(int location);
	void del_break_point(int location);

	void show_name_table_temp();
	void change_table();

private:

};


