#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct la{
	int id;
	int count;
};
bool cm1(la l1,la l2){
	if(l1.count==l2.count){
		return l1.id>l2.id;
	}
	return l1.count>l2.count;
} 
int main(){
	vector<la>lable(1000);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int t;
			cin>>t;
			lable[t].id=t;
			lable[t].count++;
		}
	}
	sort(lable.begin(),lable.end(),cm1);
	cout<<lable[0].id<<" "<<lable[0].count<<endl;
	return 0;
}
