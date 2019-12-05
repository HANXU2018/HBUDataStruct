#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int max=-1;
	int a,b;
	cin>>a>>b;
	vector<int> v(a);
	for(int i=0;i<a;i++){
		cin>>v[i];
	}
	vector<int> mou(b);
	sort(v.begin(),v.end(),cmp);
	int d=0;
	int flag=0;
//	for(int i=0;i<a;i++){
//		mou[d]+=v[i];
//		if(mou[d]>max){
//			max==mou[d];
//		}
//		if(flag==0){
//			d++;
//			if(d==b){
//				flag=1;
//			}
//		}else{
//			d--;
//			if(d==0){
//				flag=0;
//			}
//		}
//		d=d%b;
//	}
	cout<<max;
	return 0;
}
