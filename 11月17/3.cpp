#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct stu{
		string name;
		double score;
	};
bool cmp1(stu s1, stu s2){
	return s1.score>s2.score;
}
int main(){
	int k;
	cin>>k;
	vector<double>v(k);
	for(int i = 0;i<k;i++){
		cin>>v[i];
	}
	int n;
	cin>>n;
	vector<stu> st(n);
	for(int i=0;i<n;i++){
		cin>>st[i].name;
		for(int l=0;l<k;l++){
			int t;
			cin>>t;
			st[i].score +=t*v[l];
		}
	}
	sort(st.begin(),st.end(),cmp1);
	double d= n*1.0/10;
	int ll=n/10;
	if(d>n/10){
		ll++;
	}
	for(int i = 0 ;i<ll;i++){
		cout<<st[i].name<<endl; 
	} 
	return 0;
}
