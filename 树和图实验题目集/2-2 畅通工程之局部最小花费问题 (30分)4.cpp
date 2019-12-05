#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<vector<int>>v;
	for(int i = 0;i < n;i++){
		vector<int> num(n);
		for(int a=0;a<n;a++){
			num[a]=999999;
		}num[i]=0;
		v.push_back(num);
	}
	for(int i = 0;i < n*(n-1)/2;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(d==0){
			v[a-1][b-1]=c;
			v[b-1][a-1]=c;
		}else{
			v[a-1][b-1]=0;
			v[b-1][a-1]=0;
		}
	}
	vector<int> vis(n);
	vis[0]=1;
	vector<int > dis(n);
	for(int i=0;i<n;i++){
		dis[i]=v[0][i];
	}
	int count  = 1;
	int sum=0;
	while(count<n){
		int min=9999999,d=0;
		for(int i=0;i<n;i++){
			if(vis[i]== 0 &&dis[i]<min){
				min = dis[i],d = i;
			}
		}
		vis[d] = 1;
		count++;
		sum+=min;
		for(int i=0 ; i<n;i++){
			if(vis[i]==0&&dis[i]>v[d][i])
			{
				dis[i] = v [d][i];	
			}
		}
		
	}printf("%d",sum);
	
	return 0;
}
