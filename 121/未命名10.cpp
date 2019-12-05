#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,a,b;
	cin>>n>>a>>b;
	vector<vector<int>>v;
	for(int i=0;i<n+1;i++){
		vector<int >vv(n+1,99999);
		v.push_back(vv);
	}
	while(1){
		int na,nb,nn;
		cin>>na>>nb>>nn;
		if(na==-1&&nb==-1&&nn==-1){
			break;
		}
		v[na][nb]=nn;
		v[nb][na]=nn;
	}
	for(int i=1;i<=n;i++){
		if (v[a][i]!=99999){
			for(int l=1;l<=n;l++){
				if(v[a][l]>(v[i][l]+v[a][i])){
					v[a][l]=v[i][l]+v[a][i];
				}
			}
		}
	}
	cout<<v[a][b];
	
	return 0;
}
