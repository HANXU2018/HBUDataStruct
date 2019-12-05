#include<iostream>
#include<cstring>
using namespace std;
const int maxn =300010;
int pre[maxn];
int Find(int x){
	int r = x,t;
	while(pre[r]!=r) r= pre[r];//找到父亲 
	while(pre[x]!=r){
		t=pre[x];//中间的值全换成父亲 
		pre[x]=r;
		x=t;
	}return r;
}
int join(int x,int y){
	int a= Find(x),b=Find(y);
	if(a!=b){
		pre[b]=a;
	}
} 
int main(){
	int n,m,k,t,r;
	for(int i=1;i<maxn;i++) pre[i]=i;
	cin>>n>>m;
	while(m--){
		cin>>k>>r;
		while(--k){
			cin>>t;
			join(r,t);
		}
	}
	int max=1,p[maxn];
	memset(p,0,sizeof(p));
	int Max=0;
	for(int i=1; i<=n;i++){
		int r = Find(i);
		p[r]++;
		Max= Max>p[r] ? Max:p[r];
	}printf("%d\n",Max);
	return 0;
}
