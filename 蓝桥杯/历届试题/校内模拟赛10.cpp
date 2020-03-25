#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
bool cmp1(int a,int b){
	return a>b;
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>num(n);
	vector<int>num2(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	copy(num.begin(),num.end(),num2.begin());
	sort(num2.begin(),num2.end(),cmp1);
	map<int,int>mp;
	for(int i=0;i<m;i++){
		mp[num2[i]]=1;
	}
	int flag=1;
	for(int i=0;i<n;i++){
		if(mp[num[i]]==1){
			if(flag){
				cout<<num[i];
				flag=0;
			}else{
				cout<<" "<<num[i];
			}
		}
	}
	return 0;
}
