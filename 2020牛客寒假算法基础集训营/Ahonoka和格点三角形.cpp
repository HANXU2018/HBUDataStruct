#include<iostream>
#define mo 1000000007
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	long long int sum=0;
	sum=(sum+(a-1)*a*(b-2)*2%mo)%mo;
	sum=(sum+(b-1)*b*(a-2)*2%mo)%mo;
	sum=(sum+2*(b-2)*(b-2)*(a-1)%mo)%mo;
	sum=(sum+2*(a-2)*(a-2)*(b-1)%mo)%mo;
	//printf("%d",(a-1)*a*(b-2)*2+(b-1)*b*(a-2)*2+2*(b-2)*(b-2)*(a-1)+2*(a-2)*(a-2)*(b-1));
	printf("%d",sum%mo);
	return 0;
}
