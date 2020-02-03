#include<iostream>
#include<vector>
using namespace std;
struct Node{
	int add;
	int val;
	int next;
};
Node node[100005];
bool vis[100005];
int main(){
	int add,n;
	vector<Node>v;
	cin>>add>>n;
	for(int i=0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		node[a].add=a;
		node[a].val=b;
		node[a].next=c;
	}int flag=0;
	while(add!=-1){
		if(flag==0){
			printf("%05d %d ",add,node[add].val);
			flag=1;
		}else {
			if(vis[abs(node[add].val)]==false)printf("%05d\n%05d %d ",add,add,node[add].val);
			else{
				v.push_back(node[add]);
			}
		}
		vis[abs(node[add].val)]=true;
		add=node[add].next;
	}
	for(int i=0;i<v.size();i++){
		if(i==0)	printf("-1\n%05d %d ",v[i].add,v[i].val);
		else printf("%05d\n%05d %d ",v[i].add,v[i].add,v[i].val);
	}cout<<-1;
	
	return 0;
} 
