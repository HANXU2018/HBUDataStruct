#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	vector<int>v(a);
	vector<int>mou(b);
	for(int i=0;i<a;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	for(int i=0;i<a;i++){
		sort(mou.begin(),mou.end());
		mou[0]+=v[a-i-1];
	}
	sort(mou.begin(),mou.end());
	cout<<mou[b-1];
	return 0;
} 
