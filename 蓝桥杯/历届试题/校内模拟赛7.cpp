#include<iostream>
using namespace std;
int num[100]={0};
int main(){
	string s;
	int flag=1;
	int change=0;
	int ff=1;
	cin>>s;
	int a,b,c,d; 
	for(int i=0;i<s.size();i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
			ff=0;
			num[change]=i;
		}else if(ff==0){
			ff=1;
			change++;
		}
	}
	if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u'){
		flag=0;
	}
	//cout<<num[0]<<num[1]<<flag<<endl; 
	if(num[1]==s.size()-1&&flag==1){
		cout<<"yes"<<endl;
	}else cout<<"no"<<endl;
	return 0;
}
