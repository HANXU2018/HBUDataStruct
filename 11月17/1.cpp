#include<iostream>
#include<vector>
using namespace std;
int isprime(int i){
	for(int a= 2; a*a<=i;a++){
		if(i%a==0){
			return 0;
		}
	}return 1;
}
int main(){
	vector<int>v;
	int n;
	cin>>n;
	int flag=0;
	for(int i=0;i<n;i++){
		int p;
		cin>>p;
		v.push_back(p); 
	} flag=0;
	for(int i=0;i<n;i++){
		if(isprime(v[i])){
				if(flag){
					cout<<" ";
				}flag=1;
				cout<<v[i];
		}
		
	}cout<<endl;
	flag=0;
	for(int i=0;i<n;i++){
		if(v[i]%2==0){
			if(flag){
				cout<<" ";
			}flag=1;
			cout<<v[i];
		}
	}
	return 0;
} 
