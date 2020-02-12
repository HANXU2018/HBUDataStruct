#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
struct Node{
	string name;
	int num,sum;
};
bool cmp1(Node a,Node b){
	if(a.num!=b.num){return a.num>b.num;}
	return a.sum<b.sum;
}
int main(){
	int n;
	cin>>n;
	vector<Node>node(n);
	for(int i=0;i<n;i++){
		string name;
		int k;
		cin>>name>>k;
		set<int>t;
		int tt;
		for(int j=0;j<k;j++){
			cin>>tt;
			t.insert(tt);
		}
		node[i].name=name;
		node[i].num=t.size();
		node[i].sum=k;
	}sort(node.begin(),node.end(),cmp1);
	if(n==0)cout<<"- - -";
	else if(n==1)cout<<node[0].name<<" - -";
	else if(n==2)cout<<node[0].name<<" "<<node[1].name<<" -";
	else cout<<node[0].name<<" "<<node[1].name<<" "<<node[2].name; 
	return 0;
} 
