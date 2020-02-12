#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>>bb(10005);
int v[10005][10005];
int aa[10005];
int a[10005];
int n,m;
int check(){
	for(int i=0;i<n;i++){
		if(a[i]>0){
			cout<<"NO"<<endl;
			return 0;
		}
	}cout<<"YES"<<endl;
	return 0;
} 

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
//		v[a][b]=1;
//		v[b][a]=1;
		bb[a].push_back(b);
		bb[b].push_back(a);
		aa[a]++;
		aa[b]++;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		
		for(int l=0;l<n;l++){
			a[l]=aa[l];
		}
		for(int l=0;l<k;l++){
			int t;
			cin>>t;
			a[t]=0;
			for(int j=0;j<bb[t].size();j++){
//				if(v[t][j]==1){
//					a[j]--;
//				}
				a[bb[t][j]]--;
			}
		}
		check();
		
	}
	return 0;
}
