#include<iostream>
#include<cmath>
#include<set>
using namespace std;
int main(){
	long long int n;
	cin>>n;
	int count=0;
	set<int>se;
	for(int i=1;i*i<=n;i++)se.insert(i*i);
	for(auto it =se.begin();it!=se.end();it++){
		auto it2=it;
		for(it2;it2!=se.end()&&*it* *it2<=n;it2++){
			//cout<<*it<<" "<<*it2<<endl;
			count++;	
		}
	}cout<<count;
	
	return 0;
} 
