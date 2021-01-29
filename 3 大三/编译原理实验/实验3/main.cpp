#include<cstdio> 
#include<cstring> 
#include<iostream> 
using namespace std; 
 
char prog[80], token[8]; 
char ch; 
int syn, p, m = 0, n, sum = 0, kk;    
//p是缓冲区prog的指针，m是token的指针 
//遇到错误，输出结果，kk=1，表示已经找到错误，以后的请不要再次输出错误 
char *rwtab[6] = { 	(char*)"begin",(char*)"if",(char*)"then",
					(char*)"while",(char*)"do",(char*)"end" }; 

void scaner(); 
void factor(); 
void term(); 
void expression(); 
void statement(); 
 
void scaner() {
//cout<<"调用scaner"<<endl;  
	for (n = 0; n < 8; n++) token[n] = NULL;  
	ch = prog[p++];  
	while (ch == ' ') 
		ch = prog[p++];  
	if ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z'))  {   
		m = 0;   
		while ((ch >= 'A'&&ch <= 'Z') || (ch >= 'a'&&ch <= 'z') 
				|| (ch >= '0'&&ch <= '9')) {    
			token[m++] = ch;    
			ch = prog[p++];   
		}   
		token[m++] = '\0';   
		p--;   
		syn = 10;   
		for (n = 0; n < 6; n++)    
			if (strcmp(token, rwtab[n]) == 0){ 
				syn = n + 1;     
				break;    
			}  
	}  
	else  if (ch >= '0'&&ch <= '9') {    
		sum = 0;    
		while (ch >= '0'&&ch <= '9')  {  
			sum = sum * 10 + ch - '0';     
			ch = prog[p++];    
		}    
		p--; 
		syn = 11;   
	}   
	else  switch (ch) {
		case'<':
			m = 0; 
			token[m++] = ch;     
			ch = prog[p++];     
			if (ch == '>') {      
				syn = 21;      
				token[m++] = ch;     
			}     
			else { 
				syn = 20; 
				p--; 
			}     
			break;    
		case'>':
			m = 0; 
			token[m++] = ch;     
			ch = prog[p++];     
			if (ch == '=') {      
				syn = 24;      
				token[m++] = ch;     
			}     
			else {      
				syn = 23;      
				p--;     
			}     
			break; 
   		case':':
		   	m = 0; 
		   	token[m++] = ch;     
		   	ch = prog[p++];     
		   	if (ch == '=') {      
		   		syn = 18;      
			   	token[m++] = ch;   
			}     
			else {      
				syn = 17;      
				p--;     
			}     
			break;    
		case'+':
			syn = 13; 
			token[0] = ch; 
			break;    
		case'-':
			syn = 14; 
			token[0] = ch; 
			break;    
		case'*':
			syn = 15; 
			token[0] = ch; 
			break;    
		case'/':
			syn = 16; 
			token[0] = ch; 
			break;    
		case';':
			syn = 26; 
			token[0] = ch; 
			break;    
		case'(':
			syn = 27; 
			token[0] = ch; 
			break;    
		case')':
			syn = 28; 
			token[0] = ch; 
			break;    
		case'#':
			syn = 0; 
			token[0] = ch; 
			break;    
		default:
			syn = -1;    
	} 
} 


void factor() {
//cout<<"调用factor,syn="<<syn<<endl;  
	if (syn == 10 || syn == 11)   
		scaner();  
	else if (syn == 27)  {   
		scaner();  
		
		expression();
		/*填空1*/      //调用“<表达式>”处理   
		if (syn == 28)    
			scaner();   
		else { 
			cout << "缺')'错误！" << endl; 
			kk = 1; 
		}  
	}  
	else { 
		cout << "表达式错误！" << endl; 
		kk = 1; 
	}  
	return; 
} 
 

void term() {       
	/*填空2*/      //完成 “<因子>{*<因子>|/<因子>}”的功能 
	factor();  
 	while (syn == 15 || syn == 16)  {   
	 	scaner();   
		factor();  
	}  
} 
 
void expression() { 
	// cout<<"调用expression"<<endl;  
	term();  
	//cout<<"返回expression"<<endl; 
 	while (syn == 13 || syn == 14)  {   
	 	scaner();   
		term();  
	}  
	//return; 
} 
 
void statement() {
//cout<<"调用statement,syn="<<syn<<endl;  
	if (syn == 10) {   
		scaner();   
		if (syn == 18) {
			//cout<<"syn=18"<<endl;    
			scaner();    
			expression();   
		}   
		else { 
			cout << "缺:=错误！" << endl; 
			kk = 1; 
		}  
	}  
	else { 
		cout << "error!" << endl; 
		kk = 1; 
	} 
	return; 
} 
 
void yucu() {
	//cout<<"调用yucu"<<endl;  
	//调用的是赋值语句 
	statement();  
	while (syn == 26) { 
		scaner(); 
		statement(); 
		/*填空3 */      //完成 “{；<语句>}”的功能  
	}  
	//return; 
} 
 
void lrparser() {
	//cout<<"调用Irparser"<<endl;  
	if ( syn==1/*填空4 判断是否是 “begin”*/)  {   
		scaner();   
		yucu();   
		if (syn == 6) {    
			scaner();    
			if (syn == 0 && (kk == 0)) 
				cout << "success!" << endl;   
			}   
			else { 
				if (kk != 1) 
					cout << "缺end错误!" << endl; 
				kk = 1; 
			}  
	}  
	else { 
		cout << "缺begin错误！" << endl; 
		kk = 1; 
	} 
 //return; 
} 
 
int main() {  
	cin >> ch;  
	if (ch == '1') strcpy(prog, "begin a:=9; x:=2*3; b:=a+x end#");  
	if (ch == '2') strcpy(prog, "begin a:=9;b:=2*(c+d)/e end#");  
	if (ch == '3') strcpy(prog, "a:=c+d*(1+e);f:=18 end#");  
	if (ch == '4') strcpy(prog, "begin a:=100;b:=a*(1+c/2;end#"); 
 	p = 0;  
	scaner();  
	lrparser(); 
	return 0;
} 
 
 
 
