#include<iostream>
using namespace std;
long long int num[100005];
long long int sum = 0;
int count=0;
int main(){
	int n;
	cin>>n;
	string s;
	while(n-->0){
		cin>>s;
		if(s=="Push"){
			int t;
			cin>>t;
			num[count++]=t;
			sum+=t;
		}else if(s=="PeekMedian"){
			if(count==0)cout<<"Invalid"<<endl;
			else cout<<sum/count<<endl;
		}else if(s=="Pop"){
			if(count==0)cout<<"Invalid"<<endl;
			else {
				sum-=num[--count];
				cout<<num[count]<<endl;	
			}
		}
		
	}
	return 0;
}
