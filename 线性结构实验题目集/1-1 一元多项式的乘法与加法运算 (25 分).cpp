#include<iostream>
#include<vector>
#include<map> 
using namespace std;
struct num{
	int xishu = 0;
	int zhishu = 0;
};
int main(){
	int a,b;
	cin>>a;
	vector<num>n1(a);
	for(int i=0;i<a;i++){
		int q,p;
		cin>>q>>p;
		n1[i].xishu=q;
		n1[i].zhishu=p;
	}
	cin>>b;
	vector<struct num> n2 (b);
	for(int i=0;i<b;i++){
		int q,p;
		cin>>q>>p;
		n2[i].xishu=q;
		n2[i].zhishu=p;
	}
	int flag=0;
	//输出指数积
	map<int,num>mp1;
	 for(int i=0;i<a;i++){
	 	for(int l=0;l<a;l++){
	 		int q=n1[i].xishu*n2[l].xishu;
	 		int p=n1[i].zhishu+n2[l].zhishu;
	 		if(q!=0){
	 		mp1[p].xishu+=q;
	 		mp1[p].zhishu=p;
		 }
		 }
	 }
	 for(int i=2005;i>-2005;i--){
	 	if(mp1[i].xishu!=0){
	 		if(flag){
				cout<<" ";
				}flag=1;
	 		cout<<mp1[i].xishu<<" "<<mp1[i].zhishu;
		 }
	 }
	 if(flag==0){
	 	cout<<"0 0";
	 }
	 cout<<endl;
	
	map<int,num>mp2;
	for(int i=0;i<a;i++){
		mp2[n1[i].zhishu].xishu=mp2[n1[i].zhishu].xishu+n1[i].xishu;
	}
	for(int i=0;i<b;i++){
		mp2[n2[i].zhishu].xishu+=n2[i].xishu;
	}
	flag=0;
	for(int i=2000;i>-2000;i--){
		
	 	if(mp2[i].xishu!=0){
	 		if(flag){
			cout<<" ";
		}flag=1;
	 		cout<<mp2[i].xishu<<" "<<i;
		 }
	 }
	 if(flag==0){
	 	cout<<"0 0";
	 }
	return 0;
} 
