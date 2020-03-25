#include<iostream>
#include<vector>
using namespace std;
struct nn{
	int x;
	int y;
};
int num[1005][1005];
int main(){
	vector<nn>vv;
	nn n1;
	int n,m;
	cin>>n>>m;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<s.size();j++){
			if(s[j]=='.')num[i][j]=0;
			else if(s[j]=='g'){
				num[i][j]==1;
				n1.x=i;
				n1.y=j;
				vv.push_back(n1);	
			}
		}
	}
	int k;
	cin>>k;
	for(int i=0;i<vv.size();i++){
		n1=vv[i];
		int x=n1.x;
		int y=n1.y;
		if(x+k<n)num[x+k][y]=1;
		if(x>=k)num[x-k][y]=1;
		if(y+k<m)num[x][y+k]=1;
		if(y>=k)num[x][y-k]=1;
		for(int a=x-k+1;a<x+k;a++){
			if(a<0){
				continue;
			}
			for(int b=y-k+1;b<y+k;b++){
				if(b<0){
					continue;
				}
				num[a][b]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(num[i][j]==1)cout<<'g';
			else cout<<'.';
		}cout<<endl;
	}
	return 0;
}
