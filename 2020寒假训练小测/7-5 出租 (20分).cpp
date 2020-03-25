#include<iostream>
using namespace std;
int num[10];
int num1[11];
int main(){
	string s;
	cin>>s;
	
	for(int i=0;i<11;i++){
		num[s[i]-'0']=1;
	}
	int count=1;
	for(int i=9;i>=0;i--){
		if(num[i]==1){
			num[i]=count++;
		}
	}
	for(int i=0;i<11;i++){
		num1[i]=num[s[i]-'0'];
	}
	cout<<"int[] arr = new int[]{";
	int flag=0;
	for(int i=9;i>=0;i--){
		if(num[i]!=0){
			if(flag){
				cout<<",";
			}
			cout<<i;	
			flag=1;		
		}
	}
	cout<<"};"<<endl<<"int[] index = new int[]{";
	for(int i=0;i<11;i++){
		if(i==0)cout<<num1[i]-1;
		else cout<<","<<num1[i]-1;
	}
	cout<<"};"<<endl;
	return 0;
}
