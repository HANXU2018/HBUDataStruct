#include<iostream>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int sum=1;
	for(int i=0;i<a;i++){
		sum*=26;
	}
	sum=sum-b;
	string s;
	for(int i=0;i<a;i++){
		s=(char)(sum%26+'a')+s;
		sum=sum/26;
	}
	cout<<s;
	return 0;
}
