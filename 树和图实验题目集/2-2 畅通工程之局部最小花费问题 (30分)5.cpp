#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<vector<int>> v;
	for(int i=0;i<n;i++){
		vector<int>vv(n);
		for(int a=0;a<n;a++)vv[a]=999999;
		vv[i]=0;
		v.push_back(vv);
	}
	vector<int> vis(n);
	vector<int> dis(n);
	for(int i=0;i<n*(n-1)/2;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(d==1){
			v[a-1][b-1]=0;
			v[b-1][a-1]=0;
		}else{
			v[a-1][b-1]=c;
			v[b-1][a-1]=c;
		}
	}
	vis[0]=1;
	int count=1;
	int sum=0;
	for(int i=0;i<n;i++){
		dis[i]=v[0][i];
	}
	while(count<n){
		int min =999999;
		int d=0;
		for(int i=0;i<n;i++){
			if(vis[i]==0&&dis[i]<min){
				min=dis[i];
				d=i;
			}
		}vis[d]=1;
		sum+=min;
		count++;
		for(int i=0;i<n;i++){
			if(vis[i]==0&&dis[i]>v[d][i]){
				dis[i]=v[d][i];
			}
		}
		
	}
	printf("%d",sum);
	return 0;
}
