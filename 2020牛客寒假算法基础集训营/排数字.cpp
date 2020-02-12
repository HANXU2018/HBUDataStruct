#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a=0,b=0;
	char c;
	for(int i=0;i<n;i++){
		c=getchar(); 
		if(c=='6'){
			a++;
		}else if(c=='1')b++;
	}a--;
	if(a>0)cout<<(a>b?b:a);
	else cout<<0;
	return 0;
}
