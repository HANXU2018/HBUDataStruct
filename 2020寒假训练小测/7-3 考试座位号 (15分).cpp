#include<iostream>
using namespace std;
struct STU {
	string id;
	int a;
};
STU stu[1005];
int main(){
	int n;
	cin>>n;
	string id;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>id>>a>>b;
		stu[a].a=b;
		stu[a].id=id;
	}
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		cout<<stu[t].id<<" "<<stu[t].a<<endl;
	}
	return 0;
} 
