#include<iostream>
#include<vector>
using namespace std;
int main(){
	int a,b,t;
	cin>>a>>b;
	vector<int>num(a);
	for(int i=0;i<a;i++)cin>>num[i];
	for(int i=0;i<b;i++){
		for(int j=1;j<a;j++){
			if(num[j]<num[j-1]){
				t=num[j-1];
				num[j-1]=num[j];
				num[j]=t;
			}
		}
	}for(int i=0;i<a;i++){
		if(i>0){
			cout<<" ";
		} cout<<num[i];
	} 
	return 0;
} 
