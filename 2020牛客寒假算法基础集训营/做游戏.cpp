#include<iostream>
using namespace std;
int main(){
	long long int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	long long int q = a>e? e:a;
	long long int w = b>f? f:b;
	long long int r = c>d? d:c; 
	cout<<q+w+r;
	return 0;
} 
