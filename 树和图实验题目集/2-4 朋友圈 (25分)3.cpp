#include<iostream>
#include<cstring>
#define MAX 100005
using namespace std;
int pre[MAX];
int Find(int x){
	int r= x,t;
	while(r!=pre[r]){
		r=pre[r];
	}while(pre[x]!=r){
		t = pre[x];
		pre[x]=r;
		x=t;
	}return r;
}
int join(int x,int y){
	int a=Find(x),b=Find(y);
	if(a!=b){
		pre[b]=a;
	}
} 
int main(){
	for(int i=0; i<MAX;i++){
		pre[i]=i;
	}
	int n,m;
	cin>>n>>m;
	while(m--){
		int k,r;
		cin>>k>>r;
		while(--k){
			int t;
			cin>>t;
			join(r,t);
		}
	}
	int max=1,p[MAX];
	memset(p,0,sizeof(p));
	int Max=0;
	for(int i=1; i<=n;i++){
		int r = Find(i);
		p[r]++;
		Max= Max>p[r] ? Max:p[r];
	}printf("%d\n",Max);
	return 0;
}
