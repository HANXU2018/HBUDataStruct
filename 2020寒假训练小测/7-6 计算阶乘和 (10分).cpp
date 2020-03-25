#include<iostream>
using namespace std;
int jie(int a){
	int sum=1;
	for(int i=1;i<=a;i++){
		sum*=i;
	}
	return sum;
}
int main(){
	int n;
	int sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		sum+=jie(i);
	}
	cout<<sum;
	return 0;
}
