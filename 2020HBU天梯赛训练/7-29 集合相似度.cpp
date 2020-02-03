#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main(){
	int n,a,b;
	scanf("%d",&n);
	vector<unordered_set<int>>ss(n+1);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		int p;
		for(int l=0;l<t;l++){
			scanf("%d",&p);
			ss[i].insert(p);
		}
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		unordered_set<int>t;
		int count=0;
		for(auto it=ss[a].begin();it!=ss[a].end();it++) if(ss[b].count(*it))count++;
		printf("%0.2f%%\n",100.0*count/(ss[a].size()+ss[b].size()-count));
	}
	return 0;
}
