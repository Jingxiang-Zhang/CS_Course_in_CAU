#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std; 
struct TreeNode{
	vector<TreeNode*> child;
	int childNumber;
	bool haveBlankLeft;
	char data;
	TreeNode(){
		childNumber=0;
		haveBlankLeft=false;
	}
};
TreeNode* BuildTree(string tree){
	stack<TreeNode*> Tr;
	TreeNode *root=new TreeNode;
	root->data=tree[1];
	Tr.push(root);
	int loc=2;
	while(!Tr.empty()){
		TreeNode *temp=Tr.top();
		TreeNode *newTree=new TreeNode;
		switch(tree[loc]){
			case ',':
				Tr.pop();
				temp=Tr.top();
			case '(' :    //左括号表示有子树
				newTree->data=tree[loc+1];
				loc=loc+2;
				Tr.push(newTree);
				temp->child.push_back(newTree);
				temp->childNumber++;
				break;
			case ')':
				Tr.pop();
				loc=loc+1;	
		}
	}
	return root;
}
//(A(B(E,F),C,D(G)))
bool Debug(string tree){
	int pos;
	int leng=tree.length();
	int par=0;
	for(pos=0;pos<leng;pos++){
		if(tree[pos]==' '){
			cout<<"不能出现空格！"<<endl;
			return false;
		}
	}
	for(pos=0;pos<leng;pos++){
		if(tree[pos]=='(') par++;
		if(tree[pos]==')') par--;
	}
	if(par!=0){
		cout<<"括号输入有误！"<<endl;
		return false;
	}
	for(pos=0;pos<leng-1;pos++){
		if(tree[pos]=='(' && tree[pos]==','){
			cout<<"括号后不能加入逗号";
			return false;
		}
	}
	bool flag=false;
	for(pos=0;pos<leng;pos++){
		if(tree[pos]==','){
			if(flag==true) {
				cout<<"出现连续两个逗号！"<<endl;
				return false;
			}
			flag=true;
		}
		if(tree[pos]!=',' && tree[pos]!='(' && tree[pos]!=')') flag=false;
	}
	return true;
}
void WalkTree(TreeNode* root){
	if(root==NULL) return ;
	vector<TreeNode*>::iterator it;
	for(it=root->child.begin();it!=root->child.end();it++){
		WalkTree(*it);
	}
	cout<<root->data;
} 
void MidWalkTree(TreeNode* root){
	if(root==NULL) return ;
	vector<TreeNode*>::iterator it;
	it=root->child.begin();
	if(root->haveBlankLeft ==false){
		MidWalkTree(*it);
		it++;
	}
	cout<<root->data;
	if(it==root->child.end()) return ;
	MidWalkTree(*it);
}
void LinkBrother(TreeNode* root){
	vector<TreeNode*>::iterator it,at;
	if(root->childNumber==0){
		root->haveBlankLeft=true;
		return ;
	}
	it=root->child.begin();
	at=it;
	int i;
	for(i=0;i<root->childNumber-1;i++){
		at++;
		(*it)->child.push_back(*at);
		it++;
	}
	it=root->child.begin();
	for(i=0;i<root->childNumber;i++){
		LinkBrother(*it);
		it++;
	}
}
void DeleteSon(TreeNode* root){
	if(root->childNumber==0) return;
	vector<TreeNode*>::iterator it,at;
	it=root->child.begin();
	int i;
	for(i=0;i<root->childNumber;i++){
		DeleteSon(*it);
		if(i!=0)
			root->child.erase(it);
		else
			it++;
	}
}
void TransfortTree(TreeNode* root){
	LinkBrother(root);
    DeleteSon(root);
}
int main(int argc, char** argv) {
	string tree;
	cout<<"请输入一棵数：";
	getline(cin,tree);
	while(Debug(tree)==false){
		cout<<"树的输入有误，请重新输入"<<endl;
		cout<<"请输入一棵数：";
		cin>>tree;
	}
	TreeNode *root=BuildTree(tree);
	cout<<"后序遍历输出该树为：";
	WalkTree(root);
	cout<<endl;
	TransfortTree(root);
	cout<<"中序遍历转化成的二叉树为：";  
	MidWalkTree(root);
	return 0;
}
