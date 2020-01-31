#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool flag=false;
vector<bool>ans;
vector<int>num;
int n,m;
void dp(int i,int sum){
	//cout<<"dp"<<i<<" "<<sum<<endl;
	if(flag==true||i>=num.size()||sum>m)return;
	//ans.push_back(num[i]);
	ans[i]=true;
	sum+=num[i];
	if(sum==m){
		flag=true;
		int flag2=0;
		//cout<<"flag"<<endl;
		for(int i=0;i<n;i++){
			//printf("%s%d",i>0?" ":"",ans[i]);
			if(ans[i]==true){
				printf("%s%d",flag2++ >0?" ":"",num[i]);
			}
		}
		return;
	}else if(sum<m)dp(i+1,sum);
	//ans.pop_back();
	ans[i]=false;
	dp(i+1,sum-num[i]);
}
int main(){
	scanf("%d %d",&n,&m);
	num.resize(n);
	ans.resize(n);
	for(int i=0;i<n;i++)scanf("%d",&num[i]);
	sort(num.begin(),num.end());//sort从小到大 
	dp(0,0);
	if(flag== false)printf("No Solution\n");
	return 0;
} 
