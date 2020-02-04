#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<int>zero;
	vector<int>one;
	zero.push_back(0);
	one.push_back(1);
	char flag=s[0];
	for(int i=0;i<s.size();i++){
		if(s[i]==flag){
			continue;
		}else{
			if(flag=='1'){
				zero.push_back(i+1);
			}else{
				one.push_back(i+1);
			}
			flag=s[i];
		}
	}if(flag=='1'){
				one.push_back(n);
			}else{
				zero.push_back(n);
	}
	int max=-1;
	for(int i=one.size()-1;i>=k;i--){
		if(one[i]-one[i-k]>=max){
			max=one[i]-one[i-k];
		}
	}for(int i=zero.size()-1;i>=k;i--){
		if(zero[i]-zero[i-k]>=max){
			max=zero[i]-zero[i-k];
		}
	}if(one.size()<=k||zero.size()<=k)cout<<n;
	else cout<<max+1;
	
	
}
