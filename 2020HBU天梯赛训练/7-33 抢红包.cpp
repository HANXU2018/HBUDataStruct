#include<iostream>
#include<algorithm>
using namespace std;
struct people{
	int id=0;
	int num=0;
	int sum=0;
};
people pp[10005]; 
bool cmp1(people p1,people p2){
	if(p1.sum!=p2.sum)return p1.sum>p2.sum;	
	else if(p1.num!=p2.num)return p1.num>p2.num;
	else return p1.id<p2.id;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		pp[i].id=i;
		int t;
		cin>>t;
		for(int j=0;j<t;j++){
			int a,b;
			cin>>a>>b;
			pp[a].num++;
			pp[a].sum+=b;
			pp[i].sum-=b;
		}
	}
	sort(pp+1,pp+n+1,cmp1);
	for(int i=1;i<=n;i++)printf("%d %.2f\n",pp[i].id,0.01*pp[i].sum); 
	return 0;
}
