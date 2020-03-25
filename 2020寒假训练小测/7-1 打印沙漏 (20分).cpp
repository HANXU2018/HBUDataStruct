#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n>>s;
	int len = sqrt((n+1)/2);
	int sheng = n - 2*len*len+1;
	for(int i=len;i>1;i--){
		for(int j =0;j<len-i;j++)cout<<" ";
		for(int j=0;j<i*2-1;j++)cout<<s;
		cout<<endl;
	}
	for(int i=1;i<=len;i++){
		for(int j =0;j<len-i;j++)cout<<" ";
		for(int j=0;j<i*2-1;j++)cout<<s;
		cout<<endl;
	}cout<<sheng<<endl;
	return 0;
} 
