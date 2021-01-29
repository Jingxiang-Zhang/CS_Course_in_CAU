#include <iostream>
#include <list>

using namespace std;
int main(int argc, char** argv) {
	int child_number,m;
	cin>>child_number>>m;
	list<int> child;
	for(int i=1;i<=child_number;i++)
		child.push_back(i);
	list<int>::iterator it=child.end();
	it--;
	while(!child.empty()){
		for(int i=0;i<m-1;i++)
			if(++it==child.end()) it=child.begin();
		list<int>::iterator at=it;
		if(++at==child.end()) at=child.begin();
		cout<<*at<<" ";
		child.erase(at);
	}
	getchar();
	getchar();  
	return 0;
}
