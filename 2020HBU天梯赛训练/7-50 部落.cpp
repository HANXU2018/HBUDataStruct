#include<iostream>
#include<set>

using namespace std;
int fa[10005];
int findfa(int x){
	while(fa[x]!=x){
		x=fa[x];
	}return x;
}
set<int>total;
int unionfa(int a,int b){
	total.insert(a);
	total.insert(b);
	int finda=findfa(a),findb=findfa(b);
	if(finda>findb){
		fa[finda]=findb;
	}else fa[findb]=finda;
}
int main(){
	for(int i=0;i<10005;i++)fa[i]=i;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int k,t;
		cin>>k>>t;
		if(k==1)unionfa(t,t);
		for(int j=1;j<k;j++){
			int tt;
			cin>>tt;
			unionfa(t,tt);
		}
	}
	set<int>cnt;
	for(auto it = total.begin();it!=total.end();it++){
		cnt.insert(findfa(*it));
	}printf("%d %d\n",total.size(),cnt.size());
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(findfa(a)==findfa(b))cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
	
	return 0;
}
