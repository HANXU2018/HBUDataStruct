#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;
bool cmp1(int a,int b){
	return a>b;
}
int main(){
	int n,k,m;
	cin>>n>>k>>m;
	vector<int> ans;
	for(int i=0;i<n;i++){
		int max=-1;
		int min=105;
		int sum=0;
		int t;
		for(int j=0;j<k;j++){
			cin>>t;
			if(t>max)max=t;
			if(t<min)min=t;
			sum+=t;
		}
		sum-=max;
		sum-=min;
		ans.push_back(sum);	
	}sort(ans.begin(),ans.end(),cmp1);
	for(int i=m-1;i>=0;i--){
		printf("%.03f",ans[i]*1.0/(k-2));
		if(i!=0)cout<<" ";
	}
	return 0;
} 
