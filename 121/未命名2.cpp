#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	string s;
	vector<float>v;
	char ch;
	while(cin>>s){
		float sum=0;
		if(s=="Cu"){
			int a,b,c;
			cin>>a>>b>>c;
			sum=a*b*c;
			v.push_back(sum);
		}
		else if(s=="Sp"){
			int a;
			cin>>a;
			sum=3.14*a*a*a*4/3;
			v.push_back(sum);
		}else if(s=="Cy"){
			int a,b;
			cin>>a>>b;
			sum=3.14*a*a*b;
			v.push_back(sum);
		}
	}
	sort(v.begin(),v.end());
	int flag=0;
	for(int i=0;i<v.size();i++){
		if(flag)printf(" ");
		flag=1;
		printf("%.2f",v[v.size()-i-1]);
	}
	
	return 0;
}
