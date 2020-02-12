#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>ans(n,vector<int>(m));
	ans[0][0]=1;
	for(int a=0;a<n;a++){
		string s;
		cin>>s;
		for(int b=0;b<m;b++){
			if(s[b]=='R'){
				if(b+1<m)ans[a][b+1]=(ans[a][b+1]+ans[a][b])%1000000007;
			}
			else if(s[b]=='D'){
				if(a+1<n)ans[a+1][b]=(ans[a+1][b]+ans[a][b])%1000000007;
				
			}else if(s[b]=='B'){
				if(b+1<m)ans[a][b+1]=(ans[a][b+1]+ans[a][b])%1000000007;
				if(a+1<n)ans[a+1][b]=(ans[a+1][b]+ans[a][b])%1000000007;
			}
		}
	}cout<<ans[n-1][m-1];
	return 0;
}
