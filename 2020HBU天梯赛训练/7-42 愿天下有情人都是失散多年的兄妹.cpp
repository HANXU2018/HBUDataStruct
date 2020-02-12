#include<iostream>
#include<set>
using namespace std;
int fa[100005];
int mo[100005];
int count=0;
int sex[100005];
set<int>family;
void add(int a,int n){
	if(a!=0){
		family.insert(a);
		count++;
	}
	if(n<3&&a!=0){
		add(fa[a],n+1);
		add(mo[a],n+1);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int id,fid,mid;
		char sexs;
		cin>>id>>sexs>>fid>>mid;
		fa[id]=fid;
		mo[id]=mid;
		sex[id]=sexs;
		sex[fid]='M';
		sex[mid]='F'; 
	}
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(sex[a]==sex[b]){
			cout<<"Never Mind"<<endl;
		}
		else {
			family.clear();
			count = 0;
			add(a,0);
			add(b,0);
			//cout<<count<<" "<<family.size()<<endl;
			if(count==family.size()){
				cout<<"Yes"<<endl;
			}else cout<<"No"<<endl;
		}
	}
	return 0;
}
