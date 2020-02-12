#include<iostream>
using namespace std;
int num[100005];
int main(){
	int n;char c;
	cin>>n;
	int count=0;
	c=getchar();
	for(int i=0;i<n;i++){
		c=getchar();
		if(c=='1'){
			num[count++]=i;
		}
	}
	long long int sum=0;
	for(int i=0;i<count;i++){
		sum=(sum+(2*i-count+1)*num[i]%1000000007)%1000000007;
	}cout<<sum%1000000007;
	return 0;
}
