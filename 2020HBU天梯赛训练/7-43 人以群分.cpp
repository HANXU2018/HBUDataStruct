#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>ans(n);
	int sum1=0,sum=0;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		ans[i]=t;
		sum+=t;
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<n/2;i++){
		sum1+=ans[i];
	}
	cout<<"Outgoing #: "<<n-n/2<<endl<<"Introverted #: "<<n/2<<endl<<"Diff = "<<sum-2*sum1;
	return 0;
}
