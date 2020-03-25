#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>vv(n);
	vector<int>zuo(n);
	vector<int>you(n);
	int min=10005;
	int max=-1;
	for(int i=0;i<n;i++){
		cin>>vv[i];
		zuo[i]=min;
		if(vv[i]<min){
			min=vv[i];
		}
	}
	int count=0;
	for(int i=n-1;i>=0;i--){
		you[i]=max;
		if(vv[i]>max){
			max=vv[i];
		}
		if(vv[i]>zuo[i]&&vv[i]<you[i]){
			count++;
		}
	}
	cout<<count;
	return 0;
}
