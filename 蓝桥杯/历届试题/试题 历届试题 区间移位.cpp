#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int max=0;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(a>10000-b)max+=10000-b;
		else max+=a;
	}
	cout<<max; 
	return 0;
}
