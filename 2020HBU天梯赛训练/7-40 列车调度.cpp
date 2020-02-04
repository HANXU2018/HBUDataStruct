#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>num(n);
	for(int i=0;i<n;i++)cin>>num[i];
	vector<int>ans;
	ans.push_back(num[0]);
	for(int i=1;i<n;i++){
		int flag=1;
		sort(ans.begin(),ans.end());
		for(int j=0;j<ans.size();j++){
			if(ans[j]>=num[i]){
				//cout<<"&&"<<ans[j]<<"^^"<<num[i]<<"&&"<<endl;
				ans[j]=num[i];
				flag=0;	
				break;
			}
		}if(flag){
			ans.push_back(num[i]);
			//cout<<num[i]<<"****"<<endl;	
		}
	}cout<<ans.size();
	return 0;
} 
