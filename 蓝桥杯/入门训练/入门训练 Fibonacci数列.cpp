#include<iostream>
using namespace std;
int main(){
	long long int n;
	cin>>n;
	int sum=1;
	int a=1;
	int b=1;
	int t=1;
	if(n>2){
		for(int i=3;i<=n;i++){
			t=sum;
			sum=(sum+b)%10007;
			b=t;
		}
		cout<<sum%10007;
	}else{
		cout<<1;
	}
	

	return 0;
}
