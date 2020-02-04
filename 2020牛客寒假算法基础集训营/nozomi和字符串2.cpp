#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int>zero;
	vector<int>one;
	one.push_back(0);
	zero.push_back(0);
	
	getchar();
	char c;
	for(int i=0;i<n;i++){
		c=getchar();
		if(c=='1')zero.push_back(i);
		else one.push_back(i);
	}
	zero.push_back(n);
	one.push_back(n);
	int max=-1;
	int flaga=1;
	int flagb=1;
	for(int i=1;i+k<one.size();i++){
		flaga=0;
		int a=one[i]-1;
		int b=one[i+k]-1;
		int length = b-a+1;
		if(length>max)max=length;
	}
	for(int i=1;i+k<zero.size();i++){
		flagb=0;
		int a=zero[i]-1;
		if(a<0)a=0;
		int b=zero[i+k]-1;
		int length = b-a+1;
		if(length>max)max=length;
	}if(flaga||flagb)cout<<n;
	else cout<<max;
	return 0;
}
