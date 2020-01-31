#include<iostream>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	int max = 0;
	for(int a=0;a<s.size();a++){
		int ta=1;
		int tb=0;
		for(ta=0;a+ta<s.size()&&a-ta>=0&&s[a+ta]==s[a-ta];ta++);
		for(tb=0;a+tb-1<s.size()&&a-tb>=0&&s[a+tb-1]==s[a-tb];tb++);
		cout << ta<<"****"<<tb<<endl;
		if (2*ta-1>max) max = 2*ta-1;
		if (2*tb>max) max = 2*tb;
	}cout<<max;
	return 0;
}
