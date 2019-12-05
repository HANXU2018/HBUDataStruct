#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s[i]=((s[i]-'0'+3)%10+'0');
		}
	}
	cout<<s;
	return 0;
} 
