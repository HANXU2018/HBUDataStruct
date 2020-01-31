#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp1(int a,int b){
	return a>b;	
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>path;
	for(int i=0;i<=m;i++){
		vector<int>pp(n+1);
		path.push_back(pp);
	}
	vector<int>dp(m+1);
	vector<int>num(n+1);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num.begin(),num.end(),cmp1);
	for(int a=0;a<n;a++){
		for(int b=m;b >= num[a];b--){
			//cout<<a<<n<<" "<<b<<num[a]<<" ++++"<<endl;
			if(dp[b]<=dp[b-num[a]]+num[a]){
				path[b][a]=1;
				dp[b] = dp[b-num[a]]+num[a];
			} 
		}
	}
	//cout<<dp[m];
	if(dp[m] != m){
		cout<<"No Solution"<<endl;
	}else{
		int j = m;
		int i = n - 1;
		while (j > 0) {
			if (path[j][i] == 1) {
				if (j != m) cout << " ";
				cout << num[i];
				j -= num[i];
			}
			i--;
		}
	} 
	return 0;
}
