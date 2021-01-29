#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
struct number{
	int num;
	bool exist;
};
bool jud(vector<vector<int> > result,int i,int minmin){
//判断是否需要引入外援，num1表示不用外援最小值 
	int minnum=result[i][0];
	int num1=0;
	int j;
	for(j=0;j<result[i].size();j++){
		num1+=result[i][j];
		if(result[i][j]<minnum){	
			minnum=result[i][j];
		}
	}
	int num2=num1+minnum;

	num1+=minnum*(result[i].size()-2);
	num2+=minmin*(result[i].size()+1);


	if(num1>num2) return true;
	else return false;
	 
	
	
}
int main()
{
	int length;
	cin>>length; 
	int *x=new int[length];
	int i,j;
	for (i = 0; i<length; i++){
		cin>>x[i];
	}
	number *numb=new number[length];
	for(i=0;i<length;i++){
		numb[i].num=x[i];
		numb[i].exist=false;
	}
	vector<vector<int> > result;
	while(true){
		bool allexist=true;
		int loc;
		for(i=0;i<length;i++)
			if(numb[i].exist==false){
				allexist=false;
				loc=i;
				break;
			}
		if(allexist) 
			break;
		vector<int> tempresult;
		
		int tempnum=numb[loc].num;
		int currentnum=tempnum;
		do{
			tempresult.push_back(currentnum);
			numb[currentnum-1].exist=true;
			currentnum=numb[currentnum-1].num;
		}
		while(tempnum!=currentnum);
		result.push_back(tempresult);
	}
	
	//到这里将所有的牛进行分组 
	int minmin=10000;
	int *y=new int[result.size()];
	for(i=0;i<result.size();i++){
		int minn=1000000;
		for(j=0;j<result[i].size();j++)
			if(minn>result[i][j])
				minn=result[i][j];
		y[i]=minn;
		if(minmin>minn) minmin=minn;
	}	
	//minmin为全局最小值 
	for(i=0;i<result.size()-1;i++)
		for(j=0;j<result.size()-1-i;j++)
			if(y[j]>y[i]) {
				int temp=y[i];
				y[i]=y[j];
				y[j]=temp;
				vector<int> tempr=result[i];
				result[i]=result[j];
				result[j]=tempr;
			}
	//将组和组之间按照每组最小值的顺序排序 
	int sumweitht=0;
	vector<vector<int> > showdown;//用于记录最后结果表格 

	vector<int> currentresult;
	for(i=0;i<length;i++)
		currentresult.push_back(x[i]);
	
	for(i=0;i<result.size();i++){
		if(result[i].size()==1) continue;
		if(!(i!=0 && jud(result,i,minmin)) )//如果不引入外援 
{
				
		
		int minnum=result[i][0];
		int minloc=0;
		for(j=1;j<result[i].size();j++){
			if(result[i][j]<minnum){
				minnum=result[i][j];
				minloc=j;
			}
		}
		//找到最小值 
		for(j=minloc-1;j>=0;j--){
			sumweitht=sumweitht+minnum+result[i][j];
			int loc1,loc2;
			int k;
			for(k=0;k<length;k++){
				if(currentresult[k]==minnum) 
					loc1=k;
				if(currentresult[k]==result[i][j])
					loc2=k;
			}
			int temp=currentresult[loc1];
			currentresult[loc1]=currentresult[loc2];
			currentresult[loc2]=temp;
			showdown.push_back(currentresult);
		}
		for(j=result[i].size()-1;j>minloc;j--){
			sumweitht=sumweitht+minnum+result[i][j];
			int loc1,loc2;
			int k;
			for(k=0;k<length;k++){
				if(currentresult[k]==minnum) 
					loc1=k;
				if(currentresult[k]==result[i][j])
					loc2=k;
			}
			
			int temp=currentresult[loc1];
			currentresult[loc1]=currentresult[loc2];
			currentresult[loc2]=temp;
			showdown.push_back(currentresult);
		}
}
		else		
{
		
		//引入外援 
		int minnum=result[i][0];
		int minloc=0;
		for(j=1;j<result[i].size();j++){
			if(result[i][j]<minnum){
				minnum=result[i][j];
				minloc=j;
			}
		}
		
		sumweitht=sumweitht+(minmin+minnum)*2;//直接*2表示最后数值 
		int loc1,loc2;
		int k;
		for(k=0;k<length;k++){
			if(currentresult[k]==minnum) 
				loc1=k;
			if(currentresult[k]==minmin)
				loc2=k;
		}
		int temp=currentresult[loc1];
		currentresult[loc1]=currentresult[loc2];
		currentresult[loc2]=temp;
		showdown.push_back(currentresult);
		//现将外援和内部变量进行交换 
		
		for(j=minloc-1;j>=0;j--){
			sumweitht=sumweitht+minmin+result[i][j];//这里都是用外援的数值 
			for(k=0;k<length;k++){
				if(currentresult[k]==minmin) 
					loc1=k;
				if(currentresult[k]==result[i][j])
					loc2=k;
			}
			int temp=currentresult[loc1];
			currentresult[loc1]=currentresult[loc2];
			currentresult[loc2]=temp;
			showdown.push_back(currentresult);
		}
		for(j=result[i].size()-1;j>minloc;j--){
			sumweitht=sumweitht+minmin+result[i][j];
			for(k=0;k<length;k++){
				if(currentresult[k]==minmin) 
					loc1=k;
				if(currentresult[k]==result[i][j])
					loc2=k;
			}
			
			int temp=currentresult[loc1];
			currentresult[loc1]=currentresult[loc2];
			currentresult[loc2]=temp;
			showdown.push_back(currentresult);
		}
		
		for(k=0;k<length;k++){
			if(currentresult[k]==minnum) 
				loc1=k;
			if(currentresult[k]==minmin)
				loc2=k;
		}
		temp=currentresult[loc1];
		currentresult[loc1]=currentresult[loc2];
		currentresult[loc2]=temp;
		showdown.push_back(currentresult);
		//最后换回来 
	
}
	}
	cout<<sumweitht<<endl;
	for(i=0;i<showdown.size();i++){
		for(j=0;j<length;j++)
			cout<<showdown[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

