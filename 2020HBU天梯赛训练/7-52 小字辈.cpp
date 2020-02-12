#include<iostream>
#include<vector>
#include<set>
using namespace std;
int fa[1000005];
int main(){
	int n;
	cin>>n;
	vector<set<int>>ans(n);
	for(int i=1;i<=n;i++){
		cin>>fa[i];
		if(fa[i]==-1)fa[i]=0;
		ans[fa[i]].insert(i);
	}vector<set<int>>level(1);
	level[0].insert(*ans[0].begin()); 
	while(n>1){
		set<int> t;
		level.push_back(t);
		for(auto it = level[level.size()-2].begin();it!=level[level.size()-2].end();it++){
			for(auto ii =ans[*it].begin();ii!=ans[*it].end();ii++ )
			{	
				level[level.size()-1].insert(*ii);
				//cout<<*ii;
				n--;
			}
		}//cout<<endl;
	}
	cout<<level.size()<<endl;
	int flag=0;
	for(auto it =level[level.size()-1].begin();it!=level[level.size()-1].end();it++){
		if(flag)cout<<" ";
		flag=1;
		printf("%d",*it);
	}
	
	
	return 0;
}
