#include<iostream>
#include<vector>
using namespace std;
int postorder[33];
int inorder[33];
vector<vector<int>> levels(33);

void init(int postbg,int postend,int inbg,int inend,int level){
	if(postbg>postend)return;
	int r=postorder[postend];
	int t=0;
	while(inorder[inbg+t]!=r){
		t++;
	}
	levels[level].push_back(r);
	//cout<<r<<"***"<<level<<" "<<postbg<<"¡¡"<<postend<<" "<<inbg<<"¡¡"<<inend<<" "<<t<<endl;
	init(postbg,postbg+t-1,inbg,inbg+t-1,level+1); 
	init(postbg+t,postend-1,inbg+t+1,inend,level+1);
	return;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>postorder[i];
	for(int i=0;i<n;i++)cin>>inorder[i];
	init(0,n-1,0,n-1,0);
	cout<<levels[0][0];
	for(int i=1;i<33;i++){
		for(int l=0;l<levels[i].size();l++){
			cout<<" "<<levels[i][l];
		}
	}
	return 0;
}
