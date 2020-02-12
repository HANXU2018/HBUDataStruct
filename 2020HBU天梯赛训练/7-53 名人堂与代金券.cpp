#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	string name;
	int score;
	int num;
};
bool cmp1(node a,node b){
	if(a.score!=b.score){
		return a.score>b.score;
	}return a.name<b.name;
}
int main(){
	int a,b,c;
	int sum=0;
	cin>>a>>b>>c;
	vector<node>ans(a);
	for(int i=0;i<a;i++){
		string s;
		int t;
		cin>>s>>t;
		ans[i].name=s;
		ans[i].score=t;
		if(t>=b)sum+=50;
		else if(t>=60)sum+=20;
	}cout<<sum<<endl;
	sort(ans.begin(),ans.end(),cmp1);
	ans[0].num=1;
	cout<<ans[0].num<<" "<<ans[0].name<<" "<<ans[0].score<<endl;
	for(int i=1;i<a;i++){
		if(ans[i].score==ans[i-1].score){
			ans[i].num=ans[i-1].num;
		}else{
			ans[i].num=i+1;
		}
		if(ans[i].num<=c){
			cout<<ans[i].num<<" "<<ans[i].name<<" "<<ans[i].score<<endl;
		}else break;
	}
	return 0;
}
