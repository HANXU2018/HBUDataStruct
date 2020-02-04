#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int sum=n*(n+1)/2;
	for(int i=1;i<n;i++){
		int t;
		cin>>t;
		sum-=t;
	}cout<<sum;
	return 0;
}
