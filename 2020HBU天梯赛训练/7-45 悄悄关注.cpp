#include<iostream>
#include<map>
#include<set>
using namespace std;
int main(){
	set<string>ss;
	map<string,int>mp;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		ss.insert(s);
	}
	int k;
	cin>>k;
	int sum=0;
	for(int i=0;i<k;i++){
		string s;
		int t;
		cin>>s>>t;
		mp[s]=t;
		sum+=t;
	}
	int flag=1;
	for(auto it = mp.begin();it!=mp.end();it++){
		if(it->second*k>sum&&ss.find(it->first)==ss.end()){
			cout<<it->first<<endl;
			flag=0;	
		}
	}if(flag)cout<<"Bing Mei You"<<endl;
	return 0;
}
