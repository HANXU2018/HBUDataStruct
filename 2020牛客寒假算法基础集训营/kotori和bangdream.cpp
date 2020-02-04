#include<iostream>
using namespace std;
int main(){
	int n,x,a,b;
	cin>>n>>x>>a>>b;
	printf("%.02f",n*((0.01)*x*a+(1-0.01*x)*b));
	return 0;
}
