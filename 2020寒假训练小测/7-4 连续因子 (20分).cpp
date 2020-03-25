#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int max=0;
	int maxid=0;
	for(int i=2;i<=12;i++){
		int count=0;
		int t=n;
		int q=i;
		while(t%q==0){
			t=t/q;
			q++;
			count++;
			if(count>max){
				max=count;
				maxid=i;
			}
		}
	}
	cout<<max<<endl;
	for(int i=0;i<max;i++){
		if(i>0)cout<<"*"; 
		cout<<maxid+i;
	}
	return 0;
}
