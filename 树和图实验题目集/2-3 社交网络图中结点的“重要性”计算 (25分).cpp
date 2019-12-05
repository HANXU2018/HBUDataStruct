#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>v;
	for(int i=0;i<n;i++){
		vector<int>vv(n);
		for(int a=0;a<n;a++)vv[a]=999999;
		vv[i]=0;
		v.push_back(vv);
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v[a-1][b-1]=1;
		v[b-1][a-1]=1;
	}
	for(int a=0;a<n;a++){
		for(int c=0;c<n;c++){
			for(int b=0;b<n;b++){
				if(v[a][b]>v[a][c]+v[c][b]){
					v[a][b]=v[a][c]+v[c][b];
					v[b][a]=v[a][b];
				}
			}
		}
	}
	vector<int>num(n);
	   for(int a=0;a<n;a++){
	   	for(int b=0;b<n;b++)num[a]+=v[a][b];
		}
	int p,s;
	cin>>p;
	for(int i=0;i<p;i++){
		cin>>s;
		printf("Cc(%d)=%.2f\n",s,(n-1)/(1.0*num[s-1]));
	}
	return 0;
}
