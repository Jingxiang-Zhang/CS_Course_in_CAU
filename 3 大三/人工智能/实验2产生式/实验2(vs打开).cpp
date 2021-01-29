#include <iostream>
#include <string>
using namespace std;
struct RULES
{
	int count;
	char pre[255];
	char back[255];
	int mark;
};
RULES all_rules[100] = {
	{ 1,"有毛发","哺乳动物",0 },					//所有规则静态数据库
	{ 1,"有奶","哺乳动物",0 },
	{ 1,"有羽毛","鸟",0 },
	{ 2,"会飞&下蛋&","鸟",0 },
	{ 1,"吃肉","食肉动物",0 },
	{ 3,"有锋利的牙齿&有爪&眼睛盯着前方&","食肉动物",0 },
	{ 2,"哺乳动物&有蹄&","有蹄类哺乳动物",0 },
	{ 2,"哺乳动物&反刍&","有偶蹄类哺乳动物",0 },
	{ 4,"哺乳动物&食肉动物&黄褐色&有暗斑&","金钱豹",0 },
	{ 4,"哺乳动物&食肉动物&黄褐色&黑色条纹&","老虎",0 },
	{ 4,"有蹄类哺乳动物&有长脖子&有长腿&有暗斑&","长颈鹿",0 },
	{ 2,"有蹄类哺乳动物&黑条纹&","斑马",0 },
	{ 5,"鸟&不会飞&有长脖子&有长腿&黑白色&","鸵鸟",0 },
	{ 4,"鸟&不会飞&会游泳&黑白色&","企鹅",0 },
	{ 2,"鸟&会飞&","信天翁",0 },
};

/*哺乳动物
食肉动物
黄褐色
黑色条纹*/

int rule_length;					//输入的事实长度
string input_rules[255];				//输入的事实数组


int compare1(RULES *temp_rules)   //当前提条件为1时
{
	for (int i = 1; i <= rule_length; i++) {
		if (input_rules[i] == temp_rules->pre)
		{
			rule_length++;							//事实库的长度加1
			input_rules[rule_length] = temp_rules->back;	//加入事实库
			temp_rules->mark = 1;					//标记规则已使用过
			return 1;
		}
	}
	return 0;
}
int compare2(RULES *temp_rules)				//前提条件不为1
{
	string each_rules[10];
	string temp_rules_pre = temp_rules->pre;
	for (int i = 0; i != 10; ++i)
		each_rules[i] = "";

	for (int i = 0, j = 1; i < int(temp_rules_pre.length()); i++)
	{
		if (temp_rules_pre[i] != '&') 
			each_rules[j] += temp_rules_pre[i];
		else j++;
	}

	int count_all_matching_rules = 0;
	for (int i = 1; i <= temp_rules->count; i++)
		for (int j = 1; j <= rule_length; j++)
			if (input_rules[j] == each_rules[i])
				count_all_matching_rules += 1;

	//如果匹配成功
	if (count_all_matching_rules == temp_rules->count)
	{
		string new_rules = temp_rules->back;
		rule_length++;					//事实库的长度加1
		input_rules[rule_length] = new_rules;			//加入事实库
		temp_rules->mark = 1;					//标记规则已使用过
		return 1;
	}
	return 0;
}
void Result_Output()
{
	string animal_sort[] = { "金钱豹" ,"老虎" ,"长颈鹿","斑马","鸵鸟","企鹅","信天翁" };
	for (int i = 0; i < 7; i++) {
		if (input_rules[rule_length] == animal_sort[i]) {
			cout << "该动物是" << animal_sort[i] << endl;
			return;
		}
	}
	cout << "没有符合的动物，请确认特征，重新输入" << endl;
}

bool find_rule()			//查找规则库中是否还有可使用的规则
{
	for (int i = 0; i < 16; i++)
		if (all_rules[i].mark == 0)
			return true;
	return false;
}
void Idetify_Input()
{
	int before_rule_length = rule_length;
	for (int i = 0; i < 15; i++)
		all_rules[i].mark = 0;
	for (int i = 0; i < 15; i++)
	{
		if (all_rules[i].mark == 0)				//如果该条规则未使用
		{
			if (all_rules[i].count == 1)		//该条规则前提数为1
			{				
				if (compare1(&all_rules[i]))
					cout << "使用规则" << i + 1 << "且加入的新事实为" << all_rules[i].back << endl;
			}
			else if (compare2(&all_rules[i]))
					cout << "使用规则" << i + 1 << "且加入的新事实为" << all_rules[i].back << endl;
		}
		if (before_rule_length != rule_length)
		{
			if (find_rule() == false) {
				cout << "所有的规则都已使用" << endl;
				break;
			}
			i = 0;
			before_rule_length = rule_length;
		}
	}
	Result_Output();
}
bool Judge_input(int *i){
	string str;
	getline(cin, str);
	if (str.length() != 1 || str[0] < 48 || str[0] >= 57) {
		cout << "无效特征数！" << endl;
		return false;
	}
	else *i = str[0] - 48;
	return true;
}
int main()
{
	while (true) {
		int i;
		cout << endl << "进行动物识别请输入1    退出请输入2" << endl;
		if (!Judge_input(&i)) continue;
		if (i == 1)
		{
			cout << "请输入动物的特征数" << endl;
			if (!Judge_input(&rule_length)) continue;

			cout << "请输入动物的特征" << endl;
			for (int i = 1; i <= rule_length; i++)
				cin >> input_rules[i];
			Idetify_Input();
			string s;
			getline(cin, s);
		}
		else if (i == 2) {
			break;
		}
		else {
			cout << "无效数字！" << endl;
		}
	}
	system("pause");
	return 0;
}
