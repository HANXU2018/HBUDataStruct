#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>num(n);
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>num[i];
		sum+=num[i];
	}int sum2=0;
	int id=0;
	int maxsum=0;
	for(int i=0;i<n;i++){
		sum2+=num[i];
		if(abs(sum2-sum)>maxsum){
			id=i;
			maxsum=abs(sum2-sum);
		}
	}
	cout<<id+1;
return 0;
}
