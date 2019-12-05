#include<iostream>
#include<vector>
using namespace std;
int main(){
	int sum=0;
	int n;
	cin>>n;
	vector<int>num(n);
	vector<vector<int>> v;
	for(int i=0;i<n;i++){
		vector<int> vv(n);
		v.push_back(vv); 
	}
	int p=(n-1)*n/2;
	for(int i=0;i<p;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(d==0)v[a-1][b-1]=c;
	}
	int count=n;
	int min=v[0][0];
	int minid=0;
	while(count>0){
		min=99999999;
		for(int i=0;i<n;i++){
			int t=minid;
			if(min>v[t][i]&&num[i]!=1){
				min=v[t][i];
				minid=i;
			}
		}
		sum+=min;
		count--;
		num[minid]=1;
	}
	cout<<sum;	
return 0; 
} 
