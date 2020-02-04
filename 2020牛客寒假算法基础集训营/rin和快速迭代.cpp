#include<iostream>
#include<cmath>
using namespace std;
int count=0;
void fun(int n){
	count++;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(n%i==0)sum++;
	}
	if(sum>2)fun(sum);
}
 void factors(long long int N){
    count++;
    if(1 == N) return ;
    long long int count2 = 2;// 1 与 N 必是
    long long int sqrt_N = sqrt(N);
    long long int r;
    for(long long int i = 2; i <= sqrt_N; i++){
        if(0 == N % i){
            if(i == sqrt_N){
                r = N / i;
                if(r == i){//比如 4 = 2 * 2；那么2 只能算一个
                    count2++;
                }else{
                    count2 += 2;
                }
            }else{
                count2 += 2;
            }
        }
    }
     if(count2>2)factors(count2);
}
int main(){
	long long int n;
	scanf("%lld",&n);
	factors(n);
	cout<<count;
	return 0;
}
